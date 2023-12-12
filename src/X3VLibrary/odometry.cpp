#include "vex.h"
using namespace vex;

//****************//
// public members //
//****************//
double odometry::getX()
{
        return xPosition;
}

double odometry::getY()
{
        return yPosition;
}

double odometry::getHeading()
{
        return heading;
}

void odometry::setX(double newX)
{
        xPosition = newX;
}

void odometry::setY(double newY)
{
        yPosition = newY;
}

void odometry::setHeading(double newHeading)
{
        heading = newHeading;
}

void odometry::setPosition(double newX, double newY, double newHeading)
{
        setX(newX);
        setY(newY);
        setHeading(newHeading);
}

void odometry::startTracking()
{
        // Start a task for tracking the position
        // The task is assigned the static member function shooterDrawFunctionStatic
        // with the current instance of the shooterObj class (this) as an argument.
        odometryTask = vex::task(findNewPositionStatic, this);
}

void odometry::pauseTracking()
{
        // suspends the task
        odometryTask.suspend();
}

void odometry::resumeTracking()
{
        // resumes the task
        odometryTask.resume();
}

void odometry::stopTracking()
{
        odometryTask.stop();
}

//*****************//
// private members //
//*****************//

double odometry::findNewX(double deltaRelativeX, double deltaRelativeY, double heading)
{       
        double deltaGlobalX = cos(heading) * deltaRelativeY + sin(heading) * deltaRelativeX;
        return xPosition += deltaGlobalX;
}

double odometry::findNewY(double deltaRelativeX, double deltaRelativeY, double heading)
{
        return 0;
}

double odometry::findNewHeading()
{
        return 0;
}

int odometry::findNewPositionFunction(void*) {
        // Continuous loop for monitoring and controlling the shooter.
        while (true)
        {
		xPosition += findNewX(0,0,0);
                yPosition += findNewY(0,0,0);
                heading += findNewHeading();
                wait(10, msec);
        }
        // The function will never return as it's in an infinite loop.
        return 0;
}

int odometry::findNewPositionStatic(void* instance) {
        // Execute the non-static member function shooterDrawFunction on the specified instance of the shooterObj class
        // This is achieved by casting the instance pointer back to a shooterObj*, then calling the shooterDrawFunction with a nullptr argument.
        return static_cast<odometry*>(instance)->findNewPositionFunction(nullptr);
}



//*******************//
// protected members //
//*******************//
