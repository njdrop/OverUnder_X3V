#include "vex.h"
using namespace vex;

//*******************//
// Motor Definitions //
//*******************//
vex::brain Brain;
vex::controller con;
vex::motor leftMotor1 = motor(PORT1, ratio18_1, true);
vex::motor leftMotor2 = motor(PORT4, ratio18_1, true);
vex::motor leftMotor3 = motor(PORT8, ratio18_1, true);
vex::motor leftMotor4 = motor(PORT7, ratio18_1, false);
vex::motor rightMotor1 = motor(PORT6, ratio18_1, false);
vex::motor rightMotor2 = motor(PORT5, ratio18_1, false);
vex::motor rightMotor3 = motor(PORT10, ratio18_1, false);
vex::motor rightMotor4 = motor(PORT9, ratio18_1, true);
vex::pneumatics wingsSolenoid = pneumatics(Brain.ThreeWirePort.H);
vex::pneumatics PTOSolenoid = pneumatics(Brain.ThreeWirePort.F);
vex::pneumatics intakeSolenoid = pneumatics(Brain.ThreeWirePort.D);
vex::pneumatics blockerSolenoid = pneumatics(Brain.ThreeWirePort.E);
vex::line leftPTO_Sensor = line(Brain.ThreeWirePort.B);
vex::line rightPTO_Sensor = line(Brain.ThreeWirePort.C);
vex::rotation catapultRotationSensor = rotation(PORT12, false);
vex::inertial inertialSensor = inertial(PORT20);
vex::limit autonSelectorSwitch = limit(Brain.ThreeWirePort.A);

//*************************//
// Drive Group Definitions //
//*************************//x
vex::motor_group leftDrive_Group = motor_group(leftMotor1, leftMotor2);
vex::motor_group rightDrive_Group = motor_group(rightMotor1, rightMotor2);
vex::motor_group leftPTO_Group = motor_group(leftMotor3, leftMotor4);
vex::motor_group rightPTO_Group = motor_group(rightMotor3, rightMotor4);
vex::inertial *driveIntertial = &inertialSensor;

//***************************//
// Shooter Group Definitions //
//***************************//
vex::motor_group shooter_Group = motor_group(leftMotor3,leftMotor4, rightMotor3, rightMotor4);
vex::rotation *shooterRotationSensor = &catapultRotationSensor;

//***************************//
// Intake Group Definitions  //
//***************************//
vex::motor_group intake_Group = motor_group(leftMotor3,leftMotor4, rightMotor3, rightMotor4);


//*****************************//
// Robot Parameter Definitions //
//*****************************//
// drivetrain
double DRIVE_WHEEL_DIAMETER = 2.75;
double DRIVE_GEAR_RATIO = 3/4;
double LINE_SENOR_EDGE_VALUE = 57;
state INITIAL_STATE = state::drive;
// shooter
double SHOOTER_LOADED_POSITION = 233;
double SHOOTER_UNLOADED_POSITION = 291;
// other
double MAX_MOTOR_VOLTAGE = 12000;


bool leftDriveEngaged = true;
bool rightDriveEngaged = true;
bool stateSwitchButtonReleased = true;

//**************************//
// Auton Routes Definitions //
//**************************//
autonRoute autonRoutesList[] {
	eliminationOffensiveRisky,
	doNothing,
	skills3,
	soloAutonomousWinPoint,
	qualificationOffensive,
	qualificationDefensive,
	eliminationOffensive,	
};

int NUMBER_OF_AUTONS = 7;
