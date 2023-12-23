#include "vex.h"
using namespace vex;

//*******************//
// Motor Definitions //
//*******************//
vex::brain Brain;
vex::controller con;
// motors
vex::motor leftMotor1 (PORT1, ratio6_1, true);
vex::motor leftMotor2 (PORT2, ratio6_1, true);
vex::motor leftMotor3 (PORT3, ratio6_1, true);
vex::motor rightMotor1 (PORT8, ratio6_1, false);
vex::motor rightMotor2 (PORT9, ratio6_1, false);
vex::motor rightMotor3 (PORT10, ratio6_1, false);
vex::motor slapper1 (PORT19, ratio18_1, false);
vex::motor slapper2 (PORT20, ratio18_1, false);
// pneumatics
vex::pneumatics lift (Brain.ThreeWirePort.B);
vex::pneumatics leftWing (Brain.ThreeWirePort.B);
vex::pneumatics rightWing (Brain.ThreeWirePort.C);
// sensors
vex::inertial inertialSensor (PORT11);
vex::rotation catapultRotationSensor (PORT21, false);
vex::limit autonSelectorSwitch (Brain.ThreeWirePort.A);
// vision
// vision::signature TRIBALL (1, -6037, -4939, -5488, -4991, -3223, -4106, 4.200, 0);
// vex::vision visionSensor (vex::PORT6, 84, TRIBALL);




//*************************//
// Drive Group Definitions //
//*************************//
vex::motor_group leftDrive_Group = motor_group(leftMotor1, leftMotor2, leftMotor3);
vex::motor_group rightDrive_Group = motor_group(rightMotor1, rightMotor2, rightMotor3);
vex::inertial *driveIntertial = &inertialSensor;
drivetrainObj Drive (DRIVE_WHEEL_DIAMETER, DRIVE_GEAR_RATIO);

//***************************//
// Shooter Group Definitions //
//***************************//
vex::motor_group shooter_Group = motor_group(slapper1, slapper2);
vex::rotation *shooterRotationSensor = &catapultRotationSensor;
shooterObj Catapult (SHOOTER_LOADED_POSITION, SHOOTER_UNLOADED_POSITION);

//***************************//
// Intake Group Definitions  //
//***************************//
vex::motor_group intake_Group = motor_group();


//*****************************//
// Robot Parameter Definitions //
//*****************************//
// drivetrain
double DRIVE_WHEEL_DIAMETER = 2.75;
double DRIVE_GEAR_RATIO = 3/4;
// shooter
double SHOOTER_LOADED_POSITION = 0;
double SHOOTER_UNLOADED_POSITION = 0;
// other
double MAX_MOTOR_VOLTAGE = 12000;


//**************************//
// Auton Routes Definitions //
//**************************//
autonRoute autonRoutesList[] 
{
	eliminationOffensiveRisky,
	doNothing,
};

int NUMBER_OF_AUTONS = 2;
