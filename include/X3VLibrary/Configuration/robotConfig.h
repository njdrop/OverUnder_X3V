#ifndef ROBOTCONFIG_H
#define ROBOTCONFIG_H

#include "vex.h"
using namespace vex;

//********************//
// Motor Declarations //
//********************//
extern vex::brain Brain;
extern vex::controller con;
extern vex::motor leftMotor1;
extern vex::motor leftMotor2;
extern vex::motor leftMotor3;
extern vex::motor leftMotor4;
extern vex::motor rightMotor1;
extern vex::motor rightMotor2;
extern vex::motor rightMotor3;
extern vex::motor rightMotor4;
extern vex::pneumatics wingsSolenoid;
extern vex::pneumatics PTOSolenoid;
extern vex::line leftPTO_Sensor;
extern vex::line rightPTO_Sensor;
extern vex::rotation catapultRotationSensor;
extern vex::inertial inertialSensor;
extern vex::pneumatics intakeSolenoid;
extern vex::pneumatics blockerSolenoid;


//**************************//
// Drive Group Declarations //
//**************************//
extern vex::motor_group leftDrive_Group;
extern vex::motor_group rightDrive_Group;
extern vex::motor_group leftPTO_Group;
extern vex::motor_group rightPTO_Group;

//****************************//
// Shooter Group Declarations //
//****************************//
extern vex::motor_group shooter_Group;

//****************************//
// Intake Group Declarations  //
//****************************//
extern vex::motor_group intake_Group;


//******************************//
// Robot Parameter Declarations //
//******************************//
/**
 * @brief The diameter of the wheels on the drivetrain
 */
extern double DRIVE_WHEEL_DIAMETER;

/**
 * @brief the gear ratio of the drivetrain
 * This is calculated by taking the number of teeth on the powered gear divided by the number of teeth on the gears attatched to the wheels
 * GR = # teeth on powered gear / # teeth on drive gear
 */
extern double DRIVE_GEAR_RATIO;

/**
 * @brief the value (pct) at which the line sensor should read that the pto gear has engaged with the drivetrain
 */
extern double LINE_SENOR_EDGE_VALUE;

/**
 * @brief BRADON ADD COMMENT HERE
 * 
 */
extern double CATA_LOADED_POSITION;

/**
 * @brief Enum representing possible states for the robot.
 *
 * This enumeration defines the various states that the system can be in. Each state
 * represents a specific operational mode.
 *
 * The possible states are:
 *   - #drive: The system is in the regular drive state.
 *   - #ptoCataToDrive: The system is transitioning from power take-off (PTO) to drive state.
 *   - #ptoDriveToCata: The system is transitioning from drive to power take-off (PTO) state.
 *   - #shoot: The system is in the shoot state.
 */
enum class state
{
    drive,
    ptoCataToDrive,
    ptoDriveToCata,
    shoot
};

/**
 * @brief controls the state machine for usercontrol
 */
extern state currentState;

/**
 * @brief defines if the left pto motors are engaged with the drive or the catapult
 *
 * @return true => the left pto motors control the drive
 * @return false => the left pto motors control the catapult
 */
extern bool leftDriveEngaged;

/**
 * @brief defines if the right pto motors are engaged with the drive or the catapult
 *
 * @return true => the right pto motors control the drive
 * @return false => the right pto motors control the catapult
 */
extern bool rightDriveEngaged;

//***************************//
// Auton Routes Declarations //
//***************************//
/**
 * @brief an string array with the names of all the atonomous routes
 */
extern const char *autoNames[];

/**
 * @brief an array with the declaration of all the autonomous routes
 */
extern void (*autonRoutes[])();


#endif