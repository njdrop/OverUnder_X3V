#include "vex.h"

using namespace vex;

void ptoDriveToCata () {
        // makes pto begin to switch
        PTOSolenoid.open();
        if (!leftDriveEngaged && !rightDriveEngaged) 
        {
                // if both gears have disengaged with the drive then we are good so switch to the shooting state
                state = shootState;
        }

        if (con.ButtonDown.pressing()) {
                // fail safe if driv
                state = driveState;
        }

        // if left side is still engaed with the drive
        if (leftDriveEngaged) 
        {
                //then spin the left motors to get them to disengage
                leftMotor3.spin(fwd, 12000, vex::voltageUnits::mV);
                leftMotor4.spin(fwd, 12000, vex::voltageUnits::mV);  
        }
        else
        {
                // otherwise just wait untill the state swtiches
                leftMotor3.stop(coast);
                leftMotor4.stop(coast);
        }

        // if right side is still engaed with the drive
        if (rightDriveEngaged) 
        {
                //then spin the right motors to get them to disengage
                rightMotor3.spin(fwd, 12000, vex::voltageUnits::mV);
                rightMotor4.spin(fwd, 12000, vex::voltageUnits::mV);  
        }
        else
        {
                // otherwise just wait untill the state swtiches
                rightMotor3.stop(coast);
                rightMotor4.stop(coast);
        }
}



void ptoCataToDrive () {
// makes pto begin to switch
        PTOSolenoid.close();
        if (leftDriveEngaged && rightDriveEngaged) 
        {
                // if both gears have engaged with the drive then we are good so switch to the drive state
                state = driveState;
        }

        if (con.ButtonDown.pressing()) {
                state = shootState;
        }

        // if left side is still disengaed with the drive
        if (!leftDriveEngaged) 
        {
                //then spin the left motors to get them to engage
                leftMotor3.spin(fwd, 12000, vex::voltageUnits::mV);
                leftMotor4.spin(fwd, 12000, vex::voltageUnits::mV);  
        }
        else
        {
                // otherwise just wait untill the state swtiches
                leftMotor3.stop(coast);
                leftMotor4.stop(coast);
        }

        // if right side is still disengaed with the drive
        if (!rightDriveEngaged) 
        {
                //then spin the right motors to get them to engage
                rightMotor3.spin(fwd, 12000, vex::voltageUnits::mV);
                rightMotor4.spin(fwd, 12000, vex::voltageUnits::mV);  
        }
        else
        {
                // otherwise just wait untill the state swtiches
                rightMotor3.stop(coast);
                rightMotor4.stop(coast);
        }
}