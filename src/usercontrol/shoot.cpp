#include "vex.h"
#include "library.h"
using namespace vex;

int firstLoop = 0;

void shoot() {

         
        // When in shoot state controls should be as follow:
        // Left Joystick         => controls 2 drive motors on the left side of the drivetrain
        // Right Joystick        => controls 2 drive motors on the right side of the drivetrain
        // ButtonR1              => Intake
        // ButtonR2              => toggles the pto and switches to the next state
        // ButtonL1              => extake
        // ButtonL2              => fires the catapult
        // ButtonUp              => Toggles the wings open or close
        // ButtonX               => Toggles lifting the intake up or down
        // ButtonB               => Toggles the blocker up or down
        


        //is switch state button pressed
        if (con.ButtonR2.pressing()) {
                // switch to pto state
                state = 2;
        }

        if (con.ButtonR1.pressing())
        {       
                // sets the pto motors to run the intake
                lib::sendInputToMotors(leftMotor3, leftMotor4, 12000);
                lib::sendInputToMotors(rightMotor3, rightMotor4, 12000);
        }
        else if (con.ButtonL1.pressing())
        {
                // sets the pto motors to run the extake
                lib::sendInputToMotors(leftMotor3, leftMotor4, -12000);
                lib::sendInputToMotors(rightMotor3, rightMotor4, -12000);
        }
        else if (con.ButtonL2.pressing())
        {
                // run the catapult to fire unless the cata resistance drops then stop to wait for the cata to reach the top
                if (firstLoop <= 5) {
                        //if the is the first loop since L2 has been pressed then run the motors
                        //otherwise L2 must be release to reset the first loop
                        firstLoop += 1;
                        lib::sendInputToMotors(leftMotor3, leftMotor4, -12000);
                        lib::sendInputToMotors(rightMotor3, rightMotor4, -12000);
                }
                else  
                {
                        if (leftMotor3.current(vex::currentUnits::amp) <= 10)
                        {
                                leftMotor3.stop(brake);
                                leftMotor4.stop(brake);
                                rightMotor3.stop(brake);
                                rightMotor4.stop(brake);
                        }
                }
        }
        else
        {
                //if none of the conditions are true then reset first loop and stop the motors
                firstLoop = 0;
                leftMotor3.stop(brake);
                leftMotor4.stop(brake);
                rightMotor3.stop(brake);
                rightMotor4.stop(brake);
        }


}