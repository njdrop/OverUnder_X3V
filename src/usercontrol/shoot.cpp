#include "vex.h"
using namespace vex;

void shootState()
{

    // When in shoot state controls should be as follow:
    // Left Joystick         => control 2 drive motors on the left side of the drivetrain
    // Right Joystick        => control 2 drive motors on the right side of the drivetrain
    // ButtonR1              => intake
    // ButtonR2              => toggle the pto and switches to the next state
    // ButtonL1              => fires the catapult
    // ButtonL2              => toggle the wings open or close
    // ButtonUp              => extake
    // ButtonX               => toggle lifting the intake up or down
    // ButtonB               => toggle the blocker up or down

    // is switch state button pressed
    if (con.ButtonR2.pressing())
    {
        if (stateSwitchButtonReleased)
        {
            stateSwitchButtonReleased = false;
            // switch to pto state
            Drive.driveState = state::ptoCataToDrive;
        }
    }
    else
    {
        stateSwitchButtonReleased = true;
    }

    if (con.ButtonR1.pressing())
    {
        // sets the pto motors to run the intake
        leftPTO_Group.spin(fwd, MAX_MOTOR_VOLTAGE, vex::voltageUnits::mV);
        rightPTO_Group.spin(fwd, MAX_MOTOR_VOLTAGE, vex::voltageUnits::mV);
    }
    else if (con.ButtonUp.pressing())
    {
        // sets the pto motors to run the extake
        leftPTO_Group.spin(fwd, -MAX_MOTOR_VOLTAGE, vex::voltageUnits::mV);
        rightPTO_Group.spin(fwd, -MAX_MOTOR_VOLTAGE, vex::voltageUnits::mV);
    }
    else if (con.ButtonL1.pressing())
    {
        if (catapultRotationSensor.velocity(rpm) > 0)
        {
            leftPTO_Group.stop(brake);
            rightPTO_Group.stop(brake);
        }
        else
        {
            // sets the pto motors to run the extake
            leftPTO_Group.spin(fwd, -MAX_MOTOR_VOLTAGE, vex::voltageUnits::mV);
            rightPTO_Group.spin(fwd, -MAX_MOTOR_VOLTAGE, vex::voltageUnits::mV);
        }
    }
    else
    {
        if (catapultRotationSensor.velocity(rpm) > 0)
        {
            leftPTO_Group.stop(brake);
            rightPTO_Group.stop(brake);
        }
        else if (!con.ButtonRight.pressing() && (catapultRotationSensor.position(deg) >= SHOOTER_LOADED_POSITION))
        {
            // sets the pto motors to run the extake
            leftPTO_Group.spin(fwd, -MAX_MOTOR_VOLTAGE, vex::voltageUnits::mV);
            rightPTO_Group.spin(fwd, -MAX_MOTOR_VOLTAGE, vex::voltageUnits::mV);
        }
        else
        {
            leftPTO_Group.stop(coast);
            rightPTO_Group.stop(coast);
        }
    }
}