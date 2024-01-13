#include "vex.h"
using namespace vex;

//*******************//
// Robot Definitions //
//*******************//
vex::brain Brain;
vex::controller con;
// motors
vex::motor leftMotor1 (PORT1, ratio6_1, true);//1
vex::motor leftMotor2 (PORT2, ratio6_1, true);//2
vex::motor leftMotor3 (PORT3, ratio6_1, true);//3
vex::motor rightMotor1 (PORT8, ratio6_1, false);//8
vex::motor rightMotor2 (PORT9, ratio6_1, false);//9
vex::motor rightMotor3 (PORT10, ratio6_1, false);//10
vex::motor intake (PORT16, ratio18_1, true);//16
vex::motor kicker1 (PORT18, ratio18_1, true);//18
vex::motor kicker2 (PORT19, ratio18_1, true);//19
// pneumatics
vex::pneumatics intakeLift (Brain.ThreeWirePort.A);
vex::pneumatics lift (Brain.ThreeWirePort.B);
vex::pneumatics frontWings (Brain.ThreeWirePort.D);
vex::pneumatics backWings (Brain.ThreeWirePort.C);
// sensors
vex::inertial inertialSensorMain (PORT4);//4
vex::inertial inertialSensorBackup (PORT7);//7
vex::limit autonSelectorSwitch (Brain.ThreeWirePort.H);
// vision
// vision::signature TRIBALL (1, -6037, -4939, -5488, -4991, -3223, -4106, 4.200, 0);
// vex::vision visionSensor (vex::PORT6, 84, TRIBALL);

//*************************//
// Drive Group Definitions //
//*************************//
vex::motor_group leftDrive_Group = motor_group(leftMotor1, leftMotor2, leftMotor3);
vex::motor_group rightDrive_Group = motor_group(rightMotor1, rightMotor2, rightMotor3);
InertialGroup driveInertial (inertialSensorMain, inertialSensorBackup);
drivetrainObj Drive (DRIVE_WHEEL_DIAMETER, DRIVE_GEAR_RATIO);

//***************************//
// Shooter Group Definitions //
//***************************//
vex::motor_group shooter_Group = motor_group(kicker1, kicker2);


//***************************//
// Intake Group Definitions  //
//***************************//
vex::motor_group intake_Group = motor_group(intake);


//*****************************//
// Robot Parameter Definitions //
//*****************************//
double DRIVE_WHEEL_DIAMETER = 2.75;
double DRIVE_GEAR_RATIO = 3/4;
double MAX_MOTOR_VOLTAGE = 12000;


//**************************//
// Auton Routes Definitions //
//**************************//
autonRoute autonRoutesList[] 
{
	// farSideAWP,
	doNothing,
	forwardsBackwards,
	backwardsForwards,
};

int NUMBER_OF_AUTONS = 4;
