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
drivetrainObj::drivetrainObj(double wheelDiam, double gR)
{
    wheelDiameter = wheelDiam;
    gearRatio = gR;
    PTO_DriveEngaged = (driveState == state::drive);
    driveState = INITIAL_STATE;
    driveTask = vex::task();
}

//**********************************
// Configuration functions
//**********************************

void drivetrainObj::startAutoStateMachineTask()
{
    driveTask = vex::task(driveStateMachineFunction);
}
void drivetrainObj::stopAutoStateMachineTask()
{
    driveTask.stop();
}

/**
 * @brief state machine task that handels the state operations during autonomous
 *
 * @param drive
 * @return int
 */
int driveStateMachineFunction()
{
    while (true)
    {
        // define states of sensors
        // each loop determine if the line sensor dectects a light level greater than the edge case
        // indecates weather pto gear is engaged or disengaged from the drivetrain
        leftDriveEngaged = (leftPTO_Sensor.value(pct) > LINE_SENOR_EDGE_VALUE);
        rightDriveEngaged = (rightPTO_Sensor.value(pct) > LINE_SENOR_EDGE_VALUE);

        switch (Drive.driveState)
        {
        case state::drive:
            break;
        case state::ptoDriveToCata:
            // makes pto begin to switch
            PTOSolenoid.open();
            if (!leftDriveEngaged && !rightDriveEngaged)
            {
                // if both gears have disengaged with the drive then we are good so switch to the shooting state
                Drive.driveState = state::shoot;
            }
            
            // if left side is still engaed with the drive
            if (leftDriveEngaged)
            {
                // then spin the left motors to get them to disengage
                leftPTO_Group.spin(fwd, MAX_MOTOR_VOLTAGE, vex::voltageUnits::mV);
            }
            else
            {
                // otherwise just wait untill the state swtiches
                leftPTO_Group.stop(coast);
            }

            // if right side is still engaed with the drive
            if (rightDriveEngaged)
            {
                // then spin the right motors to get them to disengage
                rightPTO_Group.spin(fwd, MAX_MOTOR_VOLTAGE, vex::voltageUnits::mV);
            }
            else
            {
                // otherwise just wait untill the state swtiches
                rightPTO_Group.stop(coast);
            }
            break;
        case state::ptoCataToDrive:
            // makes pto begin to switch
            PTOSolenoid.close();
            if (leftDriveEngaged && rightDriveEngaged)
            {
                // if both gears have engaged with the drive then we are good so switch to the drive state
                Drive.driveState = state::drive;
            }

            // if left side is still disengaed with the drive
            if (!leftDriveEngaged)
            {
                // then spin the left motors to get them to engage
                leftPTO_Group.spin(fwd, MAX_MOTOR_VOLTAGE, vex::voltageUnits::mV);
            }
            else
            {
                // otherwise just wait untill the state swtiches
                leftPTO_Group.stop(coast);
            }

            // if right side is still disengaed with the drive
            if (!rightDriveEngaged)
            {
                // then spin the right motors to get them to engage
                rightPTO_Group.spin(fwd, MAX_MOTOR_VOLTAGE, vex::voltageUnits::mV);
            }
            else
            {
                // otherwise just wait untill the state swtiches
                rightPTO_Group.stop(coast);
            }
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
void drivetrainObj::runLeftSide(double voltage, bool withPTO)
{
    leftDrive_Group.spin(fwd, nearbyint(voltage), vex::voltageUnits::mV);
    if (withPTO)
    {
        leftPTO_Group.spin(fwd, nearbyint(voltage), vex::voltageUnits::mV);
    }
}

/**
 * @brief sets the right side motors to spin at a voltage
 *
 * @param voltage the voltage applied to the motors (messured in mV)
 * @param withPTO true => runs all four motors false => runs just the two direct motors (defult is set to false)
 */
void drivetrainObj::runRightSide(double voltage, bool withPTO)
{
    rightDrive_Group.spin(fwd, nearbyint(voltage), vex::voltageUnits::mV);
    if (withPTO)
    {
        rightPTO_Group.spin(fwd, nearbyint(voltage), vex::voltageUnits::mV);
    }
}

/**
 * @brief sets all motors on the left side to stop
 *
 * @param brakeType the brakeType applied
 * @param withPTO true => runs all four motors false => runs just the two direct motors (defult is set to false)
 */
void drivetrainObj::stopLeftSide(vex::brakeType brakeType, bool withPTO)
{
    leftDrive_Group.stop(brakeType);
    if (withPTO)
    {
        leftPTO_Group.stop(brakeType);
    }
}

/**
 * @brief sets all motors on the right side to stop
 *
 * @param brakeType the brakeType applied
 * @param withPTO true => runs all four motors false => runs just the two direct motors (defult is set to false)
 */
void drivetrainObj::stopRightSide(vex::brakeType brakeType, bool withPTO)
{
    rightDrive_Group.stop(brakeType);
    if (withPTO)
    {
        rightPTO_Group.stop(brakeType);
    }
}

void drivetrainObj::setBrakeType(vex::brakeType brakeType)
{
    leftDrive_Group.setStopping(brakeType);
    leftPTO_Group.setStopping(brakeType);
    rightDrive_Group.setStopping(brakeType);
    rightPTO_Group.setStopping(brakeType);
}

/**
 * @brief runs the drivetrain to run a set distance
 *
 * @param distance distance to travel (inches)
 * @param maxSpeed max speed to run the motors (pct) (min:0 max:100)
 * @param timeout time to completion (second)
 * @param debug prints debug info to the terminal (default: false)
 */
void drivetrainObj::moveDistance(double targetDistance, double maxSpeed, double timeout, bool withPTO, bool correctHeading)
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
void drivetrainObj::turn(double targetAngle, double maxSpeed, double timeout, bool withPTO)
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
drivetrainObj Drive(DRIVE_WHEEL_DIAMETER, DRIVE_GEAR_RATIO);