#ifndef DRIVECONTROL_H
#define DRIVECONTROL_H

#include "vex.h"
using namespace vex;

/**
 * @file driveControl.h
 * @brief Contains the definition of the drivetrainObj class and related functions for controlling the robot's drivetrain.
 */


/**
 * @brief Function that defines the drive state machine.
 * @return Integer representing the current state of the drive.
 */
int driveStateMachineFunction();


/**
 * @brief Class representing the drivetrain of the robot.
 */
class drivetrainObj: public odometry
{
    public:
        /**
         * @brief Constructor for drivetrainObj.
         * @param wheelDiam The diameter of the wheels.
         * @param gR The gear ratio of the drivetrain.
         */
        drivetrainObj(double wheelDiam, double gR);

        /**
         * @brief Runs the left side of the drivetrain.
         * @param voltage The voltage to apply.
         * @param withPTO Indicates whether PTO (Power Take-Off) is engaged.
         */
        void runLeftSide(double voltage, bool withPTO = false);

        /**
         * @brief Runs the right side of the drivetrain.
         * @param voltage The voltage to apply.
         * @param withPTO Indicates whether PTO (Power Take-Off) is engaged.
         */
        void runRightSide(double voltage, bool withPTO = false);


        /**
         * @brief Stops the left side of the drivetrain.
         * @param brakeType The type of brake to apply.
         * @param withPTO Indicates whether PTO is engaged.
         */
        void stopLeftSide(vex::brakeType brakeType = brake, bool withPTO = false);

         /**
         * @brief Stops the right side of the drivetrain.
         * @param brakeType The type of brake to apply.
         * @param withPTO Indicates whether PTO is engaged.
         */
        void stopRightSide(vex::brakeType brakeType = brake, bool withPTO = false);

        /**
         * @brief Moves the robot a specified distance.
         * @param distance The distance to move. (inches)
         * @param maxSpeed The maximum speed to use. (pct 0-100)
         * @param timeout The maximum time to allow for the movement. (seconds)
         * @param withPTO Indicates whether PTO is engaged.
         * @param correctHeading Indicates whether to correct the heading during movement.
         */
        void moveDistance(double distance, double maxSpeed, double timeout, bool withPTO = false, bool correctHeading = false);

        /**
         * @brief Turns the robot to a specified angle.
         * @param targetAngle The target angle to turn to. (degrees clockwise)
         * @param maxSpeed The maximum speed to use. (pct 0-100)
         * @param timeout The maximum time to allow for the turn. (seconds)
         * @param withPTO Indicates whether PTO is engaged.
         */
        void turn(double targetAngle, double maxSpeed, double timeout, bool withPTO = false);

        /**
         * @brief Sets the brake type for the drivetrain.
         * @param brakeType The type of brake to set.
         */
        void setBrakeType(vex::brakeType brakeType);

        /**
         * @brief Starts the drivetrain state machine task.
         */
        void startAutoStateMachineTask();

        /**
         * @brief Stops the drivetrain state machine task.
         */
        void stopAutoStateMachineTask();

        /**
         * @brief Gets the current state of PTO drive engagement.
         */
        bool PTO_DriveEngaged;

        /**
         * @brief Controls the state of the drive.
         * You must have called startAutoStateMachineTask() for this to work.
         * Possible Values to Assign:
         * - state::drive
         * - state::ptoDrivetoCata
         * - state::ptoCatatoDrive
         * - state::shoot
         */
        state driveState;
        

    private:
        /**
         * @brief Gets the average encoder value of the left drive.
         * @param withPTO Indicates whether PTO is engaged.
         * @return The encoder value.
         */
        double getLeftDriveEncoderValue(bool withPTO = false);

        /**
         * @brief Gets the average encoder value of the right drive.
         * @param withPTO Indicates whether PTO is engaged.
         * @return The encoder value.
         */
        double getRightDriveEncoderValue(bool withPTO = false);


        double getDriveEncoderValue(bool withPTO = false);

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
         * @brief Task responsible for managing the drivetrain state machine.
         */
        vex::task driveTask;
};

/**
 * @brief Global instance of drivetrainObj representing the drivetrain for the current robot.
 */
extern drivetrainObj Drive;

#endif
