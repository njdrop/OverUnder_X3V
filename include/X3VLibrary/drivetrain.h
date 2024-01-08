#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include "vex.h"
using namespace vex;

/**
 * @file drivetrain.h
 * @brief Contains the definition of the drivetrainObj class and related functions for controlling the robot's drivetrain.
 */

/**
 * @brief Class representing the drivetrain of the robot.
 */
class drivetrainObj
{
    public:
        /**
         * @brief Constructor for drivetrainObj.
         * @param wheelDiam The diameter of the wheels.
         * @param gR The gear ratio of the drivetrain.
         */
        drivetrainObj(double wheelDiam, double gR, vex::inertial inertialMain, vex::inertial inertialBackup);

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
         * @brief Get the Inertial heading using either the main or backup sensor depending on availability
         * @return double 
         */
        double getInertialHeading(vex::rotationUnits units);

        /**
         * @brief Get the Inertial rotation using either the main or backup sensor depending on availability
         * @return double 
         */
        double getInertialRotation(vex::rotationUnits units);

        /**
         * @brief manualy set the X value of the object relative to (0,0) on the field
         */
        void setX(double newX);

        /**
         * @brief manualy set the Y value of the object relative to (0,0) on the field
         */
        void setY(double newY);

        /**
         * @brief manualy set the X and Y value of the object relative to (0,0) on the field
         */
        void setPosition(double newX, double newY);

        /**
         * @brief calibrate the inertial sensors
         */
        void calibrate();

        /**
         * @brief Runs the left side of the drivetrain.
         * @param voltage The voltage to apply.
         */
        void runLeftSide(double voltage);

        /**
         * @brief Runs the right side of the drivetrain.
         * @param voltage The voltage to apply.
         */
        void runRightSide(double voltage);

        /**
         * @brief Stops the left side of the drivetrain.
         * @param brakeType The type of brake to apply.
         */
        void stopLeftSide(vex::brakeType brakeType = brake);

         /**
         * @brief Stops the right side of the drivetrain.
         * @param brakeType The type of brake to apply.
         */
        void stopRightSide(vex::brakeType brakeType = brake);

        /**
         * @brief Sets the brake type for the drivetrain.
         * @param brakeType The type of brake to set.
         */
        void setBrakeType(vex::brakeType brakeType);

        /**
         * @brief Moves the robot a specified distance.
         * @param distance The distance to move. (inches)
         * @param maxSpeed The maximum speed to use. (pct 0-100)
         * @param timeout The maximum time to allow for the movement. (seconds)
         * @param correctHeading Indicates whether to correct the heading during movement.
         */
        void moveDistance(double distance, double maxSpeed, double timeout, bool correctHeading = false);

        /**
         * @brief Turns the robot to a specified angle.
         * @param targetAngle The target angle to turn to. (degrees clockwise)
         * @param maxSpeed The maximum speed to use. (pct 0-100)
         * @param timeout The maximum time to allow for the turn. (seconds)
         */
        void turn(double targetAngle, double maxSpeed, double timeout);

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
         * @brief pointer to the main inertial sensor 
         */
        vex::inertial *inertialMain;

        /**
         * @brief pointer to the backup inertial sensor 
         */
        vex::inertial *inertialBackup;

        /**
         * @brief Gets the average encoder value of the left drive.
         * @return The encoder value.
         */
        double getLeftDriveEncoderValue();

        /**
         * @brief Gets the average encoder value of the right drive.
         * @return The encoder value.
         */
        double getRightDriveEncoderValue();

        /**
         * @brief Gets the average encoder value of the whole drive.
         * @return The encoder value.
         */
        double getDriveEncoderValue();

        /**
         * @brief Static function for task constructor
         * @param instance Pointer to the instance of the odometry
         */
        static int findNewPositionStatic(void *instance);

        /**
         * @brief Member function for the odometry task
         * @param Unused parameter
         */
        int updatePositionFunction(void *);

        /**
         * @brief Task for tracking the position of the object
         */
        vex::task odometryTask;
        
        /**
         * @brief memeber variable that stores the diameter of the wheels in inches
         */
        double wheelDiameter;

        /**
         * @brief member variable that stores the gear ratio of the drivetrain as a ratio
         * 
         */
        double gearRatio;

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
