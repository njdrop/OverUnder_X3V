#include "vex.h"
using namespace vex;

//**********************//
// constructor function //
//**********************//

drivetrainObj::drivetrainObj(double wheelDiam, double gR)
{
    wheelDiameter = wheelDiam;
    gearRatio = gR;
    xPosition = 0;
    yPosition = 0;
    heading = 0;
}

//****************//
// public members //
//****************//

double drivetrainObj::getX()
{
    return xPosition;
}

double drivetrainObj::getY()
{
    return yPosition;
}

double drivetrainObj::getHeading()
{
    return heading;
}

void drivetrainObj::setX(double newX) 
{
    xPosition = newX;
}

void drivetrainObj::setY(double newY)
{
    yPosition = newY;
}

void drivetrainObj::setPosition(double newX, double newY)
{
    setX(newX);
    setY(newY);
}

void drivetrainObj::calibrate()
{
    setPosition(0, 0);
}

void drivetrainObj::runLeftSide(double voltage)
{
    leftDrive_Group.spin(fwd, nearbyint(voltage), vex::voltageUnits::mV);
}

void drivetrainObj::runRightSide(double voltage)
{
    rightDrive_Group.spin(fwd, nearbyint(voltage), vex::voltageUnits::mV);
}

void drivetrainObj::stopLeftSide(vex::brakeType brakeType)
{
    leftDrive_Group.stop(brakeType);
}

void drivetrainObj::stopRightSide(vex::brakeType brakeType)
{
    rightDrive_Group.stop(brakeType);
}

void drivetrainObj::setBrakeType(vex::brakeType brakeType)
{
    leftDrive_Group.setStopping(brakeType);
    rightDrive_Group.setStopping(brakeType);
}

void drivetrainObj::moveDistance(double targetDistance, double maxSpeed, double timeout, bool correctHeading)
{
    MiniPID distanceControl(1100, 5, 5000);
    MiniPID headingControl(400, 0, 1200);
    distanceControl.setOutputLimits(-120 * maxSpeed, 120 * maxSpeed);
    headingControl.setOutputLimits(-120 * maxSpeed, 120 * maxSpeed);
    double startPos = getDriveEncoderValue();
    double startAngle = driveInertial.getRotation();
    double startTime = vex::timer::system();
    double correctionFactor, speed, actualAngle, actualDistance, encoderDistance;
    while (vex::timer::system() - startTime <= timeout * 1000)
    {   
        encoderDistance = getDriveEncoderValue() - startPos;
        actualDistance = angularDistanceToLinearDistance(encoderDistance, wheelDiameter, gearRatio);
        actualAngle = driveInertial.getRotation();
        speed = distanceControl.getOutput(actualDistance, targetDistance);
        correctionFactor = headingControl.getOutput(actualAngle, startAngle);
        
        if (correctHeading)
        {
            runLeftSide(speed + correctionFactor);
            runRightSide(speed - correctionFactor);
        }
        else
        {
            runLeftSide(speed);
            runRightSide(speed);
        }
        wait(20, msec);
    }
    stopLeftSide(vex::brakeType::coast);
    stopRightSide(vex::brakeType::coast);
}

void drivetrainObj::turn(double targetAngle, double maxSpeed, double timeout)
{
    MiniPID angleControl(350, 15, 1500);
    angleControl.setOutputLimits(-120 * maxSpeed, 120 * maxSpeed);
    angleControl.setMaxIOutput(0);
    double startTime = vex::timer::system();
    while (vex::timer::system() - startTime <= timeout * 1000)
    {
        double actualAngle = driveInertial.getRotation();
        double speed = angleControl.getOutput(actualAngle, targetAngle);
        if (fabs(targetAngle-actualAngle) < 5) 
        {
            angleControl.setMaxIOutput(2000);
        }
        runLeftSide(speed);
        runRightSide(-speed);

        wait(10, msec);
    }
    stopLeftSide(vex::brakeType::coast);
    stopRightSide(vex::brakeType::coast);
}

void drivetrainObj::startTracking()
{
    // Start a task for tracking the position
    // The task is assigned the static member function shooterDrawFunctionStatic
    // with the current instance of the shooterObj class (this) as an argument.
    odometryTask = vex::task(findNewPositionStatic, this);
}

void drivetrainObj::pauseTracking()
{
    // suspends the task
    odometryTask.suspend();
}

void drivetrainObj::resumeTracking()
{
    // resumes the task
    odometryTask.resume();
}

void drivetrainObj::stopTracking()
{
    odometryTask.stop();
}

//*****************//
// private members //
//*****************//

double drivetrainObj::getLeftDriveEncoderValue()
{
    return leftDrive_Group.position(deg);
}

double drivetrainObj::getRightDriveEncoderValue()
{
    return rightDrive_Group.position(deg);
}

double drivetrainObj::getDriveEncoderValue()
{
    return (getLeftDriveEncoderValue() + getRightDriveEncoderValue()) / 2;
}

int drivetrainObj::updatePositionFunction(void*) {
    // Continuous loop for monitoring and controlling the shooter.
    double previousRelativeX = 0;
    double previousRelativeY = angularDistanceToLinearDistance(getDriveEncoderValue(), wheelDiameter, gearRatio);
    while (true)
    {
        // calculate relative robot movement
        double relativeMovementX = 0 - previousRelativeX;
        double relativeMovementY = angularDistanceToLinearDistance(getDriveEncoderValue(), wheelDiameter, gearRatio) - previousRelativeY;
        double headingInRad = heading * 3.1416 / 180;
        xPosition += sin(headingInRad) * relativeMovementY + cos(headingInRad) * relativeMovementX;
        yPosition += cos(headingInRad) * relativeMovementY - sin(headingInRad) * relativeMovementX;
        heading = driveInertial.getRotation();

        // update previous values for reference
        previousRelativeX = 0;
        previousRelativeY = angularDistanceToLinearDistance(getDriveEncoderValue(), wheelDiameter, gearRatio);
        wait(10, msec);
    }
    // The function will never return as it's in an infinite loop.
    return 0;
}

int drivetrainObj::findNewPositionStatic(void* instance) {
    // Execute the non-static member function shooterDrawFunction on the specified instance of the shooterObj class
    // This is achieved by casting the instance pointer back to a shooterObj*, then calling the shooterDrawFunction with a nullptr argument.
    return static_cast<drivetrainObj*>(instance)->updatePositionFunction(nullptr);
}