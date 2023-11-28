#include "vex.h"
using namespace vex;

//**********************************
// Constructor function
//**********************************

/**
 * @brief Constructs a new drivetrain object
 *
 * @param wheelDiam diameter of wheels on the drive
 */
driveControl::driveControl(double wheelDiam, double gR)
{
    wheelDiameter = wheelDiam;
    gearRatio = gR;
    PTO_DriveEngaged = (currentState == driveState);
    driveState = currentState;
    driveTask = vex::task();
}

//**********************************
// Configuration functions
//**********************************

void driveControl::startAutoStateMachineTask()
{
    driveTask = vex::task(driveStateMachineTask);
}
void driveControl::stopAutoStateMachineTask()
{
    driveTask.stop();
}

/**
 * @brief returns the average value of the motor encoders on the left side of the drive
 *
 * @param withPTO weather to include the pto motors in the average
 * @return double average motor encoder value (deg)
 */
double driveControl::getLeftDriveEncoderValue(bool withPTO)
{
    double total = 0;
    total += leftMotor1.position(deg);
    total += leftMotor2.position(deg);
    if (withPTO)
    {
        total += leftMotor3.position(deg);
        total += leftMotor4.position(deg);
        return total / 4;
    }
    else
    {
        return total / 2;
    }
}

/**
 * @brief returns the average value of the motor encoders on the right side of the drive
 *
 * @param withPTO weather to include the pto motors in the average
 * @return double average motor encoder value (deg)
 */
double driveControl::getRightDriveEncoderValue(bool withPTO)
{
    double total = 0;
    total += rightMotor1.position(deg);
    total += rightMotor2.position(deg);
    if (withPTO)
    {
        total += rightMotor3.position(deg);
        total += rightMotor4.position(deg);
        return total / 4;
    }
    else
    {
        return total / 2;
    }
}

/**
 * @brief returns the average value of the motor encoders of the drive
 *
 * @param withPTO weather to include the pto motors in the average
 * @return double average motor encoder value (deg)
 */
double driveControl::getDriveEncoderValue(bool withPTO)
{
    return (getLeftDriveEncoderValue(withPTO) + getRightDriveEncoderValue(withPTO)) / 2;
}

/**
 * @brief state machine task that handels the state operations during autonomous
 *
 * @param drive
 * @return int
 */
int driveStateMachineTask()
{
    while (true)
    {
        // define states of sensors
        // each loop determine if the line sensor dectects a light level greater than the edge case
        // indecates weather pto gear is engaged or disengaged from the drivetrain
        leftDriveEngaged = (leftPTO.value(pct) > LINE_SENOR_EDGE_VALUE);
        rightDriveEngaged = (rightPTO.value(pct) > LINE_SENOR_EDGE_VALUE);

        switch (Drive.driveState)
        {
        case state::drive:
            break;
        case state::ptoDriveToCata:
            break;
        case state::ptoCataToDrive:
            break;
        case state::shoot:
            break;
        } // end of switch (state)
        wait(10, msec);
    }
    return 1;
}

/**
 * @brief sets the left side motors to spin at a voltage
 *
 * @param voltage the voltage applied to the motors (messured in mV)
 * @param withPTO true => runs all four motors false => runs just the two direct motors (defult is set to false)
 */
void driveControl::runLeftSide(double voltage, bool withPTO)
{
    leftMotor1.spin(fwd, nearbyint(voltage), vex::voltageUnits::mV);
    leftMotor2.spin(fwd, nearbyint(voltage), vex::voltageUnits::mV);
    if (withPTO)
    {
        leftMotor3.spin(fwd, nearbyint(voltage), vex::voltageUnits::mV);
        leftMotor4.spin(fwd, nearbyint(voltage), vex::voltageUnits::mV);
    }
}

/**
 * @brief sets the right side motors to spin at a voltage
 *
 * @param voltage the voltage applied to the motors (messured in mV)
 * @param withPTO true => runs all four motors false => runs just the two direct motors (defult is set to false)
 */
void driveControl::runRightSide(double voltage, bool withPTO)
{
    rightMotor1.spin(fwd, nearbyint(voltage), vex::voltageUnits::mV);
    rightMotor2.spin(fwd, nearbyint(voltage), vex::voltageUnits::mV);
    if (withPTO)
    {
        rightMotor3.spin(fwd, nearbyint(voltage), vex::voltageUnits::mV);
        rightMotor4.spin(fwd, nearbyint(voltage), vex::voltageUnits::mV);
    }
}

/**
 * @brief sets all motors on the left side to stop
 *
 * @param brakeType the brakeType applied
 * @param withPTO true => runs all four motors false => runs just the two direct motors (defult is set to false)
 */
void driveControl::stopLeftSide(vex::brakeType brakeType, bool withPTO)
{
    leftMotor1.stop(brakeType);
    leftMotor2.stop(brakeType);
    if (withPTO)
    {
        leftMotor3.stop(brakeType);
        leftMotor4.stop(brakeType);
    }
}

/**
 * @brief sets all motors on the right side to stop
 *
 * @param brakeType the brakeType applied
 * @param withPTO true => runs all four motors false => runs just the two direct motors (defult is set to false)
 */
void driveControl::stopRightSide(vex::brakeType brakeType, bool withPTO)
{
    rightMotor1.stop(brakeType);
    rightMotor2.stop(brakeType);
    if (withPTO)
    {
        rightMotor3.stop(brakeType);
        rightMotor4.stop(brakeType);
    }
}

void driveControl::setBrakeType(vex::brakeType brakeType)
{
    leftMotor1.setBrake(brakeType);
    leftMotor2.setBrake(brakeType);
    leftMotor3.setBrake(brakeType);
    leftMotor4.setBrake(brakeType);
    rightMotor1.setBrake(brakeType);
    rightMotor2.setBrake(brakeType);
    rightMotor3.setBrake(brakeType);
    rightMotor4.setBrake(brakeType);
}

/**
 * @brief runs the drivetrain to run a set distance
 *
 * @param distance distance to travel (inches)
 * @param maxSpeed max speed to run the motors (pct) (min:0 max:100)
 * @param timeout time to completion (second)
 * @param debug prints debug info to the terminal (default: false)
 */
void driveControl::moveDistance(double targetDistance, double maxSpeed, double timeout, bool withPTO, bool correctHeading)
{
    MiniPID distanceControl(2000, 5, 1200);
    MiniPID headingControl(800, 0, 2500);
    distanceControl.setOutputLimits(-120 * maxSpeed, 120 * maxSpeed);
    headingControl.setOutputLimits(-120 * maxSpeed, 120 * maxSpeed);
    double startPos = getDriveEncoderValue(withPTO);
    double startAngle = inertialSensor.rotation(deg);
    double startTime = vex::timer::system();
    while (vex::timer::system() - startTime <= timeout * 1000)
    {
        double actualDistance = lib::angularDistanceToLinearDistance((getDriveEncoderValue(withPTO) - startPos), wheelDiameter, gearRatio);
        double actualAngle = inertialSensor.rotation(deg);
        double speed = distanceControl.getOutput(actualDistance, targetDistance);
        double correctionFactor = 0.5 * headingControl.getOutput(actualAngle, startAngle);
        if (correctHeading)
        {
            runLeftSide(speed + correctionFactor, withPTO);
            runRightSide(speed - correctionFactor, withPTO);
        }
        else
        {
            runLeftSide(speed, withPTO);
            runRightSide(speed, withPTO);
        }
        wait(20, msec);
    }
    stopLeftSide(vex::brakeType::coast, withPTO);
    stopRightSide(vex::brakeType::coast, withPTO);
}

/**
 * @brief runs the drivetrain to turn to a set angle
 *
 * @param angle angle to turn to (this is an absolut value based on the inertial sensor's gyro unit) (degrees)
 * @param maxSpeed max speed to run the motors (pct) (min: 0 max: 100)
 * @param timeout time to completion (seconds)
 */
void driveControl::turn(double targetAngle, double maxSpeed, double timeout, bool withPTO)
{
    MiniPID angleControl(800, 0, 2500);
    angleControl.setOutputLimits(-120 * maxSpeed, 120 * maxSpeed);
    double startTime = vex::timer::system();
    while (vex::timer::system() - startTime <= timeout * 1000)
    {
        double actualAngle = inertialSensor.rotation(deg);
        double speed = angleControl.getOutput(actualAngle, targetAngle);
        runLeftSide(speed, withPTO);
        runRightSide(-speed, withPTO);
        wait(20, msec);
    }
    stopLeftSide(vex::brakeType::coast, withPTO);
    stopRightSide(vex::brakeType::coast, withPTO);
}

/**
 * @brief definition of drivetrain
 */

driveControl Drive(DRIVE_WHEEL_DIAMETER, DRIVE_GEAR_RATIO);