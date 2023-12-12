#ifndef ODOMETRY_H
#define ODOMETRY_H

#include "vex.h"
using namespace vex;

/**
 * @file odometry.h
 * @brief Contains the definition of the odometry class and related functions for tracking the position of an object relative to the field.
 */


/**
 * @brief Class for calculating the global X, Y and Heading values of an object relative to a position on the field
 */
class odometry {
        public:
                /**
                 * @brief gets the X position of the object relative to a point on the field
                 * @return double
                 */
                double getX();

                /**
                 * @brief gets the Y position of the object relative to a point on the field
                 * @return double
                 */
                double getY();

                /**
                 * @brief gets the heading of the object
                 * @return double
                 */
                double getHeading();

                /**
                 * @brief manualy set the X value of the object relative to (0,0) on the field
                 */
                void setX(double newX);

                /**
                 * @brief manualy set the Y value of the object relative to (0,0) on the field
                 */
                void setY(double newY);

                /**
                 * @brief manualy set the heading of the object
                 */
                void setHeading(double newHeading);

                /**
                 * @brief manualy set the X, Y, and Heading value of the object relative to (0,0) on the field
                 */
                void setPosition(double newX, double newY, double newHeading);

                /**
                 * @brief enables the task to track the position of the object
                 */
                void startTracking();

                /**
                 * @brief pauses the task to track the position of the object
                 */
                void pauseTracking();

                /**
                 * @brief resumes the task to track the position of the object
                 */
                void resumeTracking();

                /**
                 * @brief stops the task to track the position of the object
                 */
                void stopTracking();

        private:

                /**
                 * @brief calculates the new X value of the object relative to (0,0) on the field
                 * @return double representing the new X value of the robot
                 */
                double findNewX();

                /**
                 * @brief calculates the new Y value of the object relative to (0,0) on the field
                 * @return double representing the new Y value of the robot
                 */
                double findNewY();

                /**
                 * @brief calculates the new heading value of the object
                 * @return double representing the new heading value of the robot
                 */
                double findNewHeading();

                /**
                 * @brief Static function for task constructor
                 * @param instance Pointer to the instance of the odometry
                 */
                static int findNewPositionStatic (void* instance);
        
                /**
                 * @brief Member function for the odometry task
                 * @param Unused parameter
                 */
                int findNewPositionFunction (void*);

                /**
                 * @brief Task for tracking the position of the object
                 */
                vex::task odometryTask;

        protected:
                /**
                 * @brief the current X value of the object
                 */
                double xPosition;

                /**
                 * @brief the current Y value of the object
                 */
                double yPosition;

                /**
                 * @brief the current heading value of the object
                 */
                double heading;
};

#endif