#include "vex.h"
using namespace vex;

/**
 * @brief returns the average value of the motor encoders on the left side of the drive
 * 
 * @param withPTO weather to include the pto motors in the average
 * @return double average motor encoder value (deg)
 */
double drive::getLeftDriveEncoderValue(bool withPTO) {
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
double drive::getRightDriveEncoderValue(bool withPTO) {
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
double drive::getDriveEncoderValue(bool withPTO) {
        return (getLeftDriveEncoderValue(withPTO)+getRightDriveEncoderValue(withPTO))/2;
}

/**
 * @brief sets the left side motors to spin at a voltage
 * 
 * @param voltage the voltage applied to the motors (messured in mV)
 * @param withPTO true => runs all four motors false => runs just the two direct motors (defult is set to false)
 */
void drive::runLeftSide(double voltage, bool withPTO) 
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
void drive::runRightSide(double voltage, bool withPTO) 
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
void drive::stopLeftSide(vex::brakeType brakeType, bool withPTO) 
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
void drive::stopRightSide(vex::brakeType brakeType, bool withPTO) 
{
        rightMotor1.stop(brakeType);
        rightMotor2.stop(brakeType);
        if (withPTO) 
        {
                rightMotor3.stop(brakeType);
                rightMotor4.stop(brakeType);
        }
}

/**
 * @brief runs the drivetrain to run a set distance
 * 
 * @param distance distance to travel (inches)
 * @param maxSpeed max speed to run the motors (mV) (min:0 max:12000)
 * @param timeout time to completion (milliseconds)
 */
void drive::driveDistance(double targetDistance, double maxSpeed, double timeout, bool withPTO)
{
        MiniPID distanceControl(2000, 5, 1200);
        distanceControl.setOutputLimits(-maxSpeed, maxSpeed);
        double startPos = getDriveEncoderValue();
        double startTime = vex::timer::system();
        while (vex::timer::system() - startTime <= timeout)
        {
                double actualDistance = lib::angularDistanceToLinearDistance(getDriveEncoderValue() - startPos);
                double speed = distanceControl.getOutput(actualDistance, targetDistance);
                runLeftSide(speed, withPTO);
                runRightSide(speed, withPTO);
                wait(20, msec);
        }
        stopLeftSide(vex::brakeType::coast, withPTO);
        stopRightSide(vex::brakeType::coast, withPTO);
}

/**
 * @brief runs the drivetrain to turn to a set angle
 * 
 * @param angle angle to turn to (this is an absolut value based on the inertial sensors gyro unit) (degrees)
 * @param maxSpeed max speed to run the motors (mV) (min:-12000 max:12000)
 * @param timeout time to completion (milliseconds) 
 */
void drive::driveTurn(double targetAngle, double maxSpeed, double timeout, bool withPTO)
{
        MiniPID angleControl(2000, 5, 1200);
        angleControl.setOutputLimits(-maxSpeed, maxSpeed);
        double startRotation = inertialSensor.rotation(deg);
        double startTime = vex::timer::system();
        while (vex::timer::system() - startTime <= timeout)
        {
                double speed = angleControl.getOutput(inertialSensor.rotation(deg) - startRotation, targetAngle);
                runLeftSide(-speed, withPTO);
                runRightSide(speed, withPTO);
                wait(20, msec);
        }
        stopLeftSide(vex::brakeType::coast, withPTO);
        stopRightSide(vex::brakeType::coast, withPTO);
}