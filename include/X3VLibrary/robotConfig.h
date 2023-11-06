#ifndef ROBOTCONFIG_H
#define ROBOTCONFIG_H

using namespace vex;

extern vex::controller con;
extern vex::motor  leftMotor1;
extern vex::motor  leftMotor2;
extern vex::motor  leftMotor3;
extern vex::motor  leftMotor4;
extern vex::motor  rightMotor1;
extern vex::motor  rightMotor2;
extern vex::motor  rightMotor3;
extern vex::motor  rightMotor4;
extern vex::pneumatics wingsSolenoid;
extern vex::pneumatics PTOSolenoid;
extern vex::line leftPTO;
extern vex::line rightPTO;
extern vex::rotation cataRot;
extern vex::inertial Inert;
extern vex::pneumatics intakeSolenoid;
extern vex::pneumatics blockerSolenoid;

#endif