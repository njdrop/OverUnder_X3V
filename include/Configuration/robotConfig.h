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
extern vex::motor leftMotor1;
extern vex::motor leftMotor2;
extern vex::motor leftMotor3;
extern vex::motor leftMotor4;
extern vex::motor rightMotor1;
extern vex::motor rightMotor2;
extern vex::motor rightMotor3;
extern vex::motor rightMotor4;
// pneumatics

// sensors
extern vex::inertial inertialSensor;
extern vex::limit autonSelectorSwitch;
// vision
extern vision::signature GREEN_TRIBALL;
extern vision::signature HANGBAR_CAP;
extern vex::vision visionSensor;


//**************************//
// Drive Group Declarations //
//**************************//
extern vex::motor_group leftDrive_Group;
extern vex::motor_group rightDrive_Group;
extern vex::inertial *driveIntertial;
extern drivetrainObj Drive;

//****************************//
// Shooter Group Declarations //
//****************************//
extern vex::motor_group shooter_Group;
extern vex::rotation *shooterRotationSensor;
extern shooterObj Catapult;

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
 * @brief This is the bottom position of the shooter (degrees)
 */
extern double SHOOTER_LOADED_POSITION;

/**
 * @brief This is the top position of the shooter (degrees)
 * This value should in theory be larger than SHOOTER_LOADED_POSITION 
 * otherwise the member function will not work properly
 */
extern double SHOOTER_UNLOADED_POSITION; 

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