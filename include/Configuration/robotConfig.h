#ifndef ROBOTCONFIG_H
#define ROBOTCONFIG_H

#include "vex.h"
using namespace vex;

//********************//
// Robot Declarations //
//********************//
extern vex::brain Brain;
extern vex::controller con;
// motors

// pneumatics
extern vex::pneumatics lift;
extern vex::pneumatics frontWings;
extern vex::pneumatics backWings;
// sensors
extern vex::inertial inertialSensorMain;
extern vex::inertial inertialSensorBackup;
extern vex::limit autonSelectorSwitch;
// vision


//**************************//
// Drive Group Declarations //
//**************************//
extern vex::motor_group leftDrive_Group;
extern vex::motor_group rightDrive_Group;
extern drivetrainObj Drive;

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
 * @brief this is the maximum voltage the motor can be run at in mV's
 * In theroy this value could be 12700 but to protect the motors and increase their lifespan we are using 12000
 */
extern double MAX_MOTOR_VOLTAGE;

//***************************//
// Auton Routes Declarations //
//***************************//
/**
 * @brief a structure for the autonomous selector
 */
typedef struct 
{ 
	const char *name;
    double setUpX;
    double setUpY;
    double setUpHeading;
	void (*routeFunction)();
} autonRoute;

/**
 * @brief an array of routes for the auton selector to cycle through and run
 */
extern autonRoute autonRoutesList[];

/**
 * @brief this is the number of autons that are used in the auton selector
 */
extern int NUMBER_OF_AUTONS;

#endif