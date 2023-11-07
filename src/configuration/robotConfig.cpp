#include "vex.h"
using namespace vex;

vex::brain  Brain;
vex::controller con;
vex::motor  leftMotor1 = motor(PORT1, ratio18_1, true);
vex::motor  leftMotor2 = motor(PORT4, ratio18_1, true);
vex::motor  leftMotor3 = motor(PORT8, ratio18_1, true);
vex::motor  leftMotor4 = motor(PORT7, ratio18_1, false);
vex::motor  rightMotor1 = motor(PORT6, ratio18_1, false);
vex::motor  rightMotor2 = motor(PORT5, ratio18_1, false);
vex::motor  rightMotor3 = motor(PORT10, ratio18_1, false);
vex::motor  rightMotor4 = motor(PORT9, ratio18_1, true);
vex::pneumatics wingsSolenoid = pneumatics(Brain.ThreeWirePort.H);
vex::pneumatics PTOSolenoid = pneumatics(Brain.ThreeWirePort.F);
vex::pneumatics intakeSolenoid = pneumatics(Brain.ThreeWirePort.D);
vex::pneumatics blockerSolenoid = pneumatics(Brain.ThreeWirePort.E);
vex::line leftPTO = line(Brain.ThreeWirePort.B);
vex::line rightPTO = line(Brain.ThreeWirePort.C);
vex::rotation catapultRotationSensor = rotation(PORT12, false);
vex::inertial inertialSensor = inertial(PORT20);

double wheelDiameter = 2.75;

int state = 0;
bool leftDriveEngaged = true;
bool rightDriveEngaged = true;
double lineSensorEdgeValue = 57;
bool stateSwitchButtonReleased = true;