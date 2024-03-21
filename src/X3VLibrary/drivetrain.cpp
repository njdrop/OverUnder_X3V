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
    // initalize objects for PID control
    MiniPID distanceControl(1600, 5, 3000);
    MiniPID headingControl(300, 3, 1200);
    // configure pid controls
    distanceControl.setOutputLimits(-120 * maxSpeed, 120 * maxSpeed);
    headingControl.setOutputLimits(-120 * maxSpeed, 120 * maxSpeed);

    // track inital values to use for calculating total change
    double startPos = getDriveEncoderValue();
    double startAngle = inertialSensorMain.rotation(deg);
    double startTime = vex::timer::system();

    // condition exits loops after some amount of time has passed
    while (vex::timer::system() - startTime <= timeout * 1000)
    {
        // calculate the total distance the encoder has traveled in degrees
        double encoderDistance = getDriveEncoderValue() - startPos;
        // converts the encoder distance to inches traveled
        double travelDistance = angularDistanceToLinearDistance(encoderDistance, wheelDiameter, gearRatio);
        // stores the current heading of the robot
        double actualAngle = inertialSensorMain.rotation(deg);
        // gets ouptput from pid controller for travel speed
        double output = distanceControl.getOutput(travelDistance, targetDistance);
        // gets output from pid controller for turning speed
        double correctionFactor = headingControl.getOutput(actualAngle, startAngle);

        if (correctHeading)
        {
            runLeftSide(output + correctionFactor);
            runRightSide(output - correctionFactor);
        }
        else
        {
            runLeftSide(output);
            runRightSide(output);
        }
        wait(20, msec);
    }
    stopLeftSide(vex::brakeType::coast);
    stopRightSide(vex::brakeType::coast);
}

void drivetrainObj::moveDistance(double targetDistance, double maxSpeed, double timeout)
{
    moveDistance(targetDistance, maxSpeed, timeout, true);
}

void drivetrainObj::swing(double targetDistance, double maxSpeed, double targetAngle, double timeout)
{
    // initalize objects for PID control
    MiniPID distanceControl(1100, 5, 5000);
    MiniPID headingControl(300, 2, 1200);
    // configure pid controls
    distanceControl.setOutputLimits(-120 * maxSpeed, 120 * maxSpeed);
    headingControl.setOutputLimits(-120 * maxSpeed, 120 * maxSpeed);

    // track inital values to use for calculating total change
    double startPos = getDriveEncoderValue();
    double startAngle = inertialSensorMain.rotation(deg);
    double startTime = vex::timer::system();
    double currTargetAngle = inertialSensorMain.rotation(deg);

    // condition exits loops after some amount of time has passed
    while (vex::timer::system() - startTime <= timeout * 1000)
    {
        // calculate the total distance the encoder has traveled in degrees
        double encoderDistance = getDriveEncoderValue() - startPos;
        // converts the encoder distance to inches traveled
        double travelDistance = angularDistanceToLinearDistance(encoderDistance, wheelDiameter, gearRatio);
        // stores the current heading of the robot
        double actualAngle = inertialSensorMain.rotation(deg);
        // cacluates the percent of distance driven to target distance
        double fracComplete = travelDistance / targetDistance;
        // sets current target angle to that percentage between the start agnle and the final target angle
        currTargetAngle = (targetAngle - startAngle) * fracComplete + startAngle;
        // gets ouptput from pid controller for travel speed
        double output = distanceControl.getOutput(travelDistance, targetDistance);
        // gets output from pid controller for turning speed
        double correctionFactor = headingControl.getOutput(actualAngle, currTargetAngle);

        // sends command to run motors at desired speeds
        runLeftSide(output + correctionFactor);
        runRightSide(output - correctionFactor);
        wait(20, msec);
    }
    stopLeftSide(vex::brakeType::coast);
    stopRightSide(vex::brakeType::coast);
}

void drivetrainObj::turn(double targetAngle, double maxSpeed, double timeout)
{
    // initalize object for PID control
    MiniPID angleControl(400, 20, 3000);
    // configure PID controller
    angleControl.setOutputLimits(-120 * maxSpeed, 120 * maxSpeed);
    angleControl.setMaxIOutput(0);
    // store the inital time
    double startTime = vex::timer::system();

    // condition exits loops after some amount of time has passed
    while (vex::timer::system() - startTime <= timeout * 1000)
    {
        // stores the robots current heading
        double actualAngle = inertialSensorMain.rotation(deg);
        // gets output from PID controller for desired turn spped
        double output = angleControl.getOutput(actualAngle, targetAngle);

        // only introduce the integral portion of the PID if the robot is within 5 degrees of the target
        // this helps to prevent overshoot and integral windup
        if (fabs(targetAngle - actualAngle) < 5)
        {
            angleControl.setMaxIOutput(8000);
        }
        // set the motors to the desired speed
        runLeftSide(output);
        runRightSide(-output);
        wait(10, msec);
    }
    stopLeftSide(vex::brakeType::coast);
    stopRightSide(vex::brakeType::coast);
    printf("%f\n", targetAngle - inertialSensorMain.rotation(deg));
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

int drivetrainObj::updatePositionFunction(void *)
{
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
        heading = inertialSensorMain.rotation(deg);

        // update previous values for reference
        previousRelativeX = 0;
        previousRelativeY = angularDistanceToLinearDistance(getDriveEncoderValue(), wheelDiameter, gearRatio);
        wait(10, msec);
    }
    // The function will never return as it's in an infinite loop.
    return 0;
}

int drivetrainObj::findNewPositionStatic(void *instance)
{
    // Execute the non-static member function shooterDrawFunction on the specified instance of the shooterObj class
    // This is achieved by casting the instance pointer back to a shooterObj*, then calling the shooterDrawFunction with a nullptr argument.
    return static_cast<drivetrainObj *>(instance)->updatePositionFunction(nullptr);
}