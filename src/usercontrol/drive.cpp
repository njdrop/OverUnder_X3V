#include "vex.h"
#include "library.h"
using namespace vex;



void drive() {
        
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
        if (con.ButtonR2.pressing()) {
                // switch to pto state
                state = 1;
        }

        // gets value of the y axis on the left stick of the controller
        double leftStickY = con.Axis3.value();
        // runs the 2 left side pto motors at left stick value
        leftMotor3.spin(fwd, nearbyint(leftStickY), vex::voltageUnits::mV);
        leftMotor4.spin(fwd, nearbyint(leftStickY), vex::voltageUnits::mV);

        // gets value of the y axis on the right stick of the controller
        double rightStickY = con.Axis2.value(); 
        // runs the 2 right side pto motors at right stick value
        rightMotor3.spin(fwd, nearbyint(rightStickY), vex::voltageUnits::mV);
        rightMotor4.spin(fwd, nearbyint(rightStickY), vex::voltageUnits::mV);

}