#include "vex.h"
using namespace vex;

//*******************//
// Motor Definitions //
//*******************//
vex::brain Brain;
vex::controller con;
// motors
vex::motor leftMotor1 = motor(PORT1, ratio18_1, true);
vex::motor leftMotor2 = motor(PORT4, ratio18_1, true);
vex::motor leftMotor3 = motor(PORT8, ratio18_1, true);
vex::motor leftMotor4 = motor(PORT7, ratio18_1, false);
vex::motor rightMotor1 = motor(PORT6, ratio18_1, false);
vex::motor rightMotor2 = motor(PORT5, ratio18_1, false);
vex::motor rightMotor3 = motor(PORT10, ratio18_1, false);
vex::motor rightMotor4 = motor(PORT9, ratio18_1, true);
// pneumatics

// sensors
vex::rotation catapultRotationSensor = rotation(PORT12, false);
vex::inertial inertialSensor = inertial(PORT20);
vex::limit autonSelectorSwitch = limit(Brain.ThreeWirePort.A);
// vision
vision::signature GREEN_TRIBALL = vision::signature(1, -4897, -1467, -3182, -5425, -1629, -3527, 1.300, 0);
vision::signature HANGBAR_CAP = vision::signature(2, 1543, 1811, 1677, -3769, -3387, -3578, 8.600, 0);
vex::vision visionSensor = vision(vex::PORT15, 84, GREEN_TRIBALL, HANGBAR_CAP);




//*************************//
// Drive Group Definitions //
//*************************//x
vex::motor_group leftDrive_Group = motor_group(leftMotor1, leftMotor2, leftMotor3, leftMotor4);
vex::motor_group rightDrive_Group = motor_group(rightMotor1, rightMotor2, rightMotor3, rightMotor4);
vex::inertial *driveIntertial = &inertialSensor;
drivetrainObj Drive = drivetrainObj(DRIVE_WHEEL_DIAMETER, DRIVE_GEAR_RATIO);

//***************************//
// Shooter Group Definitions //
//***************************//
vex::motor_group shooter_Group = motor_group();
vex::rotation *shooterRotationSensor = &catapultRotationSensor;
shooterObj Catapult = shooterObj(SHOOTER_LOADED_POSITION, SHOOTER_UNLOADED_POSITION);

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
autonRoute autonRoutesList[] {
	doNothing,
	eliminationOffensiveRisky,
};

int NUMBER_OF_AUTONS = 2;
