#include "vex.h"
using namespace vex;

//*******************//
// Robot Definitions //
//*******************//
vex::brain Brain;
vex::controller con;
// motors
vex::motor leftMotor1 (PORT20, ratio6_1, true);
vex::motor leftMotor2 (PORT19, ratio6_1, true);
vex::motor leftMotor3 (PORT18, ratio6_1, true);
vex::motor rightMotor1 (PORT11, ratio6_1, false);
vex::motor rightMotor2 (PORT12, ratio6_1, false);
vex::motor rightMotor3 (PORT13, ratio6_1, false);
vex::motor intake (PORT16, ratio18_1, true);
vex::motor kicker1 (PORT14, ratio18_1, true);
vex::motor kicker2 (PORT17, ratio18_1, false);
// pneumatics
vex::pneumatics rightDropDown (Brain.ThreeWirePort.H);
vex::pneumatics leftDropDown (Brain.ThreeWirePort.E);
vex::pneumatics rightWing (Brain.ThreeWirePort.G);
vex::pneumatics leftWing (Brain.ThreeWirePort.F);

// sensors
vex::inertial inertialSensorMain (PORT10);
vex::inertial inertialSensorBackup (PORT1);
vex::pot autonSelector (Brain.ThreeWirePort.B);

//*****************************//
// Robot Parameter Definitions //
//*****************************//
double DRIVE_WHEEL_DIAMETER = 2.75;
double DRIVE_GEAR_RATIO = 1.0;
double MAX_MOTOR_VOLTAGE = 12000;

//*************************//
// Drive Group Definitions //
//*************************//
vex::motor_group leftDrive_Group = motor_group(leftMotor1, leftMotor2, leftMotor3);
vex::motor_group rightDrive_Group = motor_group(rightMotor1, rightMotor2, rightMotor3);
drivetrainObj Drive (DRIVE_WHEEL_DIAMETER, DRIVE_GEAR_RATIO);

//***************************//
// Shooter Group Definitions //
//***************************//
vex::motor_group shooter_Group = motor_group(kicker1, kicker2);

//***************************//
// Intake Group Definitions  //
//***************************//
vex::motor_group intake_Group = motor_group(intake);

//**************************//
// Auton Routes Definitions //
//**************************//
autonRoute autonRoutesList[] 
{
	doNothing,
	nearSideSafeAWP,
	nearSideRushLeftAWP,
	nearSideRushRightAWP,
	nearSideElims,
	farSideSafeAWP,
	farSideRushLeftAWP,
	farSideRushRightAWP,
	farSideElims,
};

int NUMBER_OF_AUTONS = 9;
