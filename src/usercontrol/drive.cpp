#include "vex.h"
#include "library.h"
using namespace vex;

void drive() {
        
        //if switch state button pressed
        if (con.ButtonR2.pressing()) {
                //switch to pto state
                state = 1;
        }

        //gets value of the y axis on the left stick of the controller
        double leftStickY = con.Axis3.value();
        //runs all four left side motors at left stick value
        leftMotor1.spin(fwd, nearbyint(leftStickY), vex::voltageUnits::mV);
        leftMotor2.spin(fwd, nearbyint(leftStickY), vex::voltageUnits::mV);
        leftMotor3.spin(fwd, nearbyint(leftStickY), vex::voltageUnits::mV);
        leftMotor4.spin(fwd, nearbyint(leftStickY), vex::voltageUnits::mV);

        //gets value of the y axis on the right stick of the controller
        double rightStickY = con.Axis2.value(); 
        //runs all four right side motors at right stick value
        rightMotor1.spin(fwd, nearbyint(rightStickY), vex::voltageUnits::mV);
        rightMotor2.spin(fwd, nearbyint(rightStickY), vex::voltageUnits::mV);
        rightMotor3.spin(fwd, nearbyint(rightStickY), vex::voltageUnits::mV);
        rightMotor4.spin(fwd, nearbyint(rightStickY), vex::voltageUnits::mV);










}