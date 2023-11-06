#include "vex.h"
using namespace vex;

int firstLoop = 0;
double cataTopPosition = 297;
double cataLoadedPostition = 225;
int cataIsFiring = 0;
int cataFireNumberOfLoops = 2;
double prevCataPos = 0;
void shoot() {

        printf("%f\n", catapultRotationSensor.position(deg));

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
        if (con.ButtonR2.pressing()) 
        {
                // switch to pto state
                state = 2;
        }

        if (con.ButtonR1.pressing())
        {       
                // sets the pto motors to run the intake
                lib::sendInputToMotors(leftMotor3, leftMotor4, 12000);
                lib::sendInputToMotors(rightMotor3, rightMotor4, 12000);
        }
        else if (con.ButtonUp.pressing())
        {
                // sets the pto motors to run the extake
                lib::sendInputToMotors(leftMotor3, leftMotor4, -12000);
                lib::sendInputToMotors(rightMotor3, rightMotor4, -12000);
        } 
        else if (con.ButtonL1.pressing()) 
        {
                if (catapultRotationSensor.velocity(rpm) >0) 
                {
                        leftMotor3.stop(brake);
                        leftMotor4.stop(brake);
                        rightMotor3.stop(brake);
                        rightMotor4.stop(brake);
                }
                else
                {
                        // sets the pto motors to run the extake
                        lib::sendInputToMotors(leftMotor3, leftMotor4, -10000);
                        lib::sendInputToMotors(rightMotor3, rightMotor4, -10000);
                }
        }
        else
        {
                  if (catapultRotationSensor.velocity(rpm) >0) 
                {
                        leftMotor3.stop(brake);
                        leftMotor4.stop(brake);
                        rightMotor3.stop(brake);
                        rightMotor4.stop(brake);
                }
                else if (!con.ButtonRight.pressing() && (catapultRotationSensor.position(deg) >= cataLoadedPostition)) 
                {
                        // sets the pto motors to run the extake
                        lib::sendInputToMotors(leftMotor3, leftMotor4, -12000);
                        lib::sendInputToMotors(rightMotor3, rightMotor4, -12000);
                }
                else 
                {
                        leftMotor3.stop(coast);
                        leftMotor4.stop(coast);
                        rightMotor3.stop(coast);
                        rightMotor4.stop(coast);
                }
        }
}