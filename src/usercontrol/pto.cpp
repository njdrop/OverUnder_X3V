#include "vex.h"
using namespace vex;

void ptoDriveToCataState()
{
    // makes pto begin to switch
    PTOSolenoid.open();
    if (!leftDriveEngaged && !rightDriveEngaged)
    {
        // if both gears have disengaged with the drive then we are good so switch to the shooting state
        Drive.driveState = state::shoot;
    }

    // fail safe button
    // to be used if the robot does not have pneumatic pressure
    // or can't get the pto to swtich for some other reason
    if (con.ButtonDown.pressing())
    {
        // fail safe if driv
        Drive.driveState = state::drive;
    }

    // if left side is still engaed with the drive
    if (leftDriveEngaged)
    {
        // then spin the left motors to get them to disengage
        leftPTO_Group.spin(fwd, MAX_MOTOR_VOLTAGE, vex::voltageUnits::mV);
    }
    else
    {
        // otherwise just wait untill the state swtiches
        leftPTO_Group.stop(coast);
    }

    // if right side is still engaed with the drive
    if (rightDriveEngaged)
    {
        // then spin the right motors to get them to disengage
        rightPTO_Group.spin(fwd, MAX_MOTOR_VOLTAGE, vex::voltageUnits::mV);
    }
    else
    {
        // otherwise just wait untill the state swtiches
        rightPTO_Group.stop(coast);
    }
}

void ptoCataToDriveState()
{
    // makes pto begin to switch
    PTOSolenoid.close();
    if (leftDriveEngaged && rightDriveEngaged)
    {
        // if both gears have engaged with the drive then we are good so switch to the drive state
        Drive.driveState = state::drive;
    }

    // fail safe button
    // to be used if the robot does not have pneumatic pressure
    // or can't get the pto to swtich for some other reason
    if (con.ButtonDown.pressing())
    {
        Drive.driveState = state::shoot;
    }

    // if left side is still disengaed with the drive
    if (!leftDriveEngaged)
    {
        // then spin the left motors to get them to engage
        leftPTO_Group.spin(fwd, MAX_MOTOR_VOLTAGE, vex::voltageUnits::mV);
    }
    else
    {
        // otherwise just wait untill the state swtiches
        leftPTO_Group.stop(coast);
    }

    // if right side is still disengaed with the drive
    if (!rightDriveEngaged)
    {
        // then spin the right motors to get them to engage
        rightPTO_Group.spin(fwd, MAX_MOTOR_VOLTAGE, vex::voltageUnits::mV);
    }
    else
    {
        // otherwise just wait untill the state swtiches
        rightPTO_Group.stop(coast);
    }
}