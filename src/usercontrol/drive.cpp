#include "vex.h"
using namespace vex;

void drive()
{

    /*
     * When in drive state controls should be as follow:
     * Left Joystick         => controls all motors on the left side of the drivetrain
     * Right Joystick        => controls all motors on the right side of the drivetrain
     * ButtonR1              => unassigned
     * ButtonR2              => toggles the pto and switches to the next state
     * ButtonL1              => unassigned
     * ButtonL2              => unassigned
     * ButtonUp              => Toggles the wings open or close
     * ButtonX               => Toggles lifting the intake up or down
     * ButtonB               => Toggles the blocker up or down
     */

    // if switch state button pressed
    if (con.ButtonR2.pressing())
    {
        if (stateSwitchButtonReleased)
        {
            stateSwitchButtonReleased = false;
            // switch to pto state
            currentState = state::ptoDriveToCata;
        }
    }
    else
    {
        stateSwitchButtonReleased = true;
    }

    // gets value of the y axis on the left stick of the controller
    double leftStickY = con.Axis3.value() * 100;
    // runs the 2 left side pto motors at left stick value
    leftPTO_Group.spin(fwd, nearbyint(leftStickY), vex::voltageUnits::mV);
    // gets value of the y axis on the right stick of the controller
    double rightStickY = con.Axis2.value() * 100;
    // runs the 2 right side pto motors at right stick value
    rightPTO_Group.spin(fwd, nearbyint(rightStickY), vex::voltageUnits::mV);

    leftPTO_Group.setStopping(coast);
    rightPTO_Group.setStopping(coast);
}