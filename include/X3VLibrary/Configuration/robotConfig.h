#ifndef ROBOTCONFIG_H
#define ROBOTCONFIG_H

using namespace vex;

extern vex::brain Brain;
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
extern vex::rotation catapultRotationSensor;
extern vex::inertial inertialSensor;
extern vex::pneumatics intakeSolenoid;
extern vex::pneumatics blockerSolenoid;

/**
 * @brief defines the possible states the robot can be in
 * 
 */
enum possibleState {
        driveState,
        ptoCataToDriveState,
        ptoDriveToCataState,
        shootState
};

/**
 * @brief controls the state machine for usercontrol
 * @see main.cpp
 */
extern possibleState state;

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


/**
 * @brief the value (pct) at which the line sensor should read that the pto gear has engaged with the drivetrain
 */
extern double lineSensorEdgeValue;

extern const char * autoNames[11];

#endif