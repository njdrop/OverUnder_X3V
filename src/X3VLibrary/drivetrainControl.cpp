#include "vex.h"
using namespace vex;


//**********************************
//Constructor function
//**********************************

/**
 * @brief Constructs a new drivetrain object
 * 
 * @param wheelDiam diameter of wheels on the drive
 */
driveControl::driveControl(double wheelDiam) 
{
        wheelDiameter = wheelDiam;
        PTO_DriveEngaged = (state == 0); 
        driveState = state;
        driveTask = vex::task();
}

//**********************************
//Configuration functions
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
double driveControl::getLeftDriveEncoderValue(bool withPTO) {
        double total = 0;
        total += leftMotor1.position(deg);
        total += leftMotor2.position(deg);
        if (withPTO) 
        {
                total += leftMotor3.position(deg);
                total += leftMotor4.position(deg);
                return total/4;
        }       
        else
        {
                return total/2;
        }
}
  
/**
 * @brief returns the average value of the motor encoders on the right side of the drive
 * 
 * @param withPTO weather to include the pto motors in the average
 * @return double average motor encoder value (deg)
 */
double driveControl::getRightDriveEncoderValue(bool withPTO) {
        double total = 0;
        total += rightMotor1.position(deg);
        total += rightMotor2.position(deg);
        if (withPTO) 
        {
                total += rightMotor3.position(deg);
                total += rightMotor4.position(deg);
                return total/4;
        }       
        else
        {
                return total/2;
        }
}

/**
 * @brief returns the average value of the motor encoders of the drive
 * 
 * @param withPTO weather to include the pto motors in the average
 * @return double average motor encoder value (deg)
 */
double driveControl::getDriveEncoderValue(bool withPTO) {
        return (getLeftDriveEncoderValue(withPTO)+getRightDriveEncoderValue(withPTO))/2;
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
                leftDriveEngaged = (leftPTO.value(pct) > lineSensorEdgeValue); 
                rightDriveEngaged = (rightPTO.value(pct) > lineSensorEdgeValue);

                switch (Drive.driveState) 
                {
                        case 0:
                                PTOSolenoid.close();
                                Drive.PTO_DriveEngaged = true;
                                break;    
                        case 1:
                                PTOSolenoid.open();
                                if (!leftDriveEngaged && !rightDriveEngaged) 
                                {
                                        // if both gears have disengaged with the drive then we are good so switch to the shooting state
                                        Drive.driveState = 3;
                                }
                                // if left side is still engaed with the drive
                                if (leftDriveEngaged) 
                                {
                                        //then spin the left motors to get them to disengage
                                        leftMotor3.spin(fwd, 12000, vex::voltageUnits::mV);
                                        leftMotor4.spin(fwd, 12000, vex::voltageUnits::mV);  
                                }
                                else
                                {
                                        // otherwise just wait untill the state swtiches
                                        leftMotor3.stop(coast);
                                        leftMotor4.stop(coast);
                                }

                                // if right side is still engaed with the drive
                                if (rightDriveEngaged) 
                                {
                                        //then spin the right motors to get them to disengage
                                        rightMotor3.spin(fwd, 12000, vex::voltageUnits::mV);
                                        rightMotor4.spin(fwd, 12000, vex::voltageUnits::mV);  
                                }
                                else
                                {
                                        // otherwise just wait untill the state swtiches
                                        rightMotor3.stop(coast);
                                        rightMotor4.stop(coast);
                                }
                                break;
                        case 2:
                                PTOSolenoid.close();
                                if (leftDriveEngaged && rightDriveEngaged) 
                                {
                                        // if both gears have engaged with the drive then we are good so switch to the drive state
                                        Drive.driveState = 0;
                                }

                                // if left side is still disengaed with the drive
                                if (!leftDriveEngaged) 
                                {
                                        //then spin the left motors to get them to engage
                                        leftMotor3.spin(fwd, 12000, vex::voltageUnits::mV);
                                        leftMotor4.spin(fwd, 12000, vex::voltageUnits::mV);  
                                }
                                else
                                {
                                        // otherwise just wait untill the state swtiches
                                        leftMotor3.stop(coast);
                                        leftMotor4.stop(coast);
                                }

                                // if right side is still disengaed with the drive
                                if (!rightDriveEngaged) 
                                {
                                        //then spin the right motors to get them to engage
                                        rightMotor3.spin(fwd, 12000, vex::voltageUnits::mV);
                                        rightMotor4.spin(fwd, 12000, vex::voltageUnits::mV);  
                                }
                                else
                                {
                                        // otherwise just wait untill the state swtiches
                                        rightMotor3.stop(coast);
                                        rightMotor4.stop(coast);
                                }
                                break;

                        case 3:
                                PTOSolenoid.open();
                                Drive.PTO_DriveEngaged = false; 
                                break;   
                              
                        default:
                                printf("%d\n", 404); // if we reach this point, then no we did not
                                break;
                } // end of switch (state)
                wait(10,msec);
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
                double actualDistance = lib::angularDistanceToLinearDistance((getDriveEncoderValue(withPTO) - startPos), wheelDiameter);
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
driveControl Drive(2.75);