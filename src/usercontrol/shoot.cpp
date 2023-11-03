#include "vex.h"
#include "library.h"
using namespace vex;

int firstLoop = 0;
double cataTopPosition = 50;
double cataLoadedPostition = 140;
int cataIsFiring = 0;
int cataFireNumberOfLoops = 5;

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
        else if (cataIsFiring >= cataFireNumberOfLoops)
        {
                if (cataRot.position(deg) <= cataTopPosition)
                {
                        // if the cata has reached the top position then it is reset anc we can start over
                        cataIsFiring = 0;
                } else {
                        // otherwise the cata has started to fire then 
                        leftMotor3.stop(brake);
                        leftMotor4.stop(brake);
                        rightMotor3.stop(brake);
                        rightMotor4.stop(brake);
                }
        } 
        else if (cataIsFiring >= 1) 
        {
                //if the cata is not firing but firing has begun then ensure the cata continues to spin to get it to fire
                lib::sendInputToMotors(leftMotor3, leftMotor4, -12000);
                lib::sendInputToMotors(rightMotor3, rightMotor4, -12000);
                // add one to counter to make sure the cata motor spins for some number of loops
                cataIsFiring +=1;
        }
        else if (cataRot.position(deg) >= cataLoadedPostition) 
        {
                // if the cata has not been loaded and is not in the process of being 
                // fired then run the motors untill the cata reaches the loaded position
                lib::sendInputToMotors(leftMotor3, leftMotor4, -12000);
                lib::sendInputToMotors(rightMotor3, rightMotor4, -12000);
        }
        else if (con.ButtonL2.pressing())
        {       // if the fire button is pressed run the motors
                lib::sendInputToMotors(leftMotor3, leftMotor4, -12000);
                lib::sendInputToMotors(rightMotor3, rightMotor4, -12000);
                // and set cata to begin the fireing sequence
                cataIsFiring = 1;
        }
}