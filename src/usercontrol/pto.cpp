#include "vex.h"
using namespace vex;

void ptoDriveToCata()
{
    // makes pto begin to switch
    PTOSolenoid.open();
    if (!leftDriveEngaged && !rightDriveEngaged)
    {
        // if both gears have disengaged with the drive then we are good so switch to the shooting state
        currentState = state::shoot;
    }

    // fail safe button
    // to be used if the robot does not have pneumatic pressure
    // or can't get the pto to swtich for some other reason
    if (con.ButtonDown.pressing())
    {
        // fail safe if driv
        currentState = state::drive;
    }

    // if left side is still engaed with the drive
    if (leftDriveEngaged)
    {
        // then spin the left motors to get them to disengage
        leftPTO_Group.spin(fwd, 12000, vex::voltageUnits::mV);
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
        rightPTO_Group.spin(fwd, 12000, vex::voltageUnits::mV);
    }
    else
    {
        // otherwise just wait untill the state swtiches
        rightPTO_Group.stop(coast);
    }
}

void ptoCataToDrive()
{
    // makes pto begin to switch
    PTOSolenoid.close();
    if (leftDriveEngaged && rightDriveEngaged)
    {
        // if both gears have engaged with the drive then we are good so switch to the drive state
        currentState = state::drive;
    }

    // fail safe button
    // to be used if the robot does not have pneumatic pressure
    // or can't get the pto to swtich for some other reason
    if (con.ButtonDown.pressing())
    {
        currentState = state::shoot;
    }

    // if left side is still disengaed with the drive
    if (!leftDriveEngaged)
    {
        // then spin the left motors to get them to engage
        leftPTO_Group.spin(fwd, 12000, vex::voltageUnits::mV);
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
        rightPTO_Group.spin(fwd, 12000, vex::voltageUnits::mV);
    }
    else
    {
        // otherwise just wait untill the state swtiches
        rightPTO_Group.stop(coast);
    }
}