/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       2024noahdropsey                                           */
/*    Created:      10/24/2023, 2:43:16 PM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
using namespace vex;
competition Competition;

/////////////////////////////////////////////////////////////////////////////
vex::brain  Brain;
vex::controller con;
vex::motor  leftMotor1 = motor(PORT1, ratio18_1, true);
vex::motor  leftMotor2 = motor(PORT4, ratio18_1, true);
vex::motor  leftMotor3 = motor(PORT8, ratio18_1, true);
vex::motor  leftMotor4 = motor(PORT7, ratio18_1, false);
vex::motor  rightMotor1 = motor(PORT6, ratio18_1, false);
vex::motor  rightMotor2 = motor(PORT5, ratio18_1, false);
vex::motor  rightMotor3 = motor(PORT10, ratio18_1, false);
vex::motor  rightMotor4 = motor(PORT9, ratio18_1, true);
vex::pneumatics wingsSolenoid = pneumatics(Brain.ThreeWirePort.H);
vex::pneumatics PTOSolenoid = pneumatics(Brain.ThreeWirePort.A);
vex::line leftPTO = line(Brain.ThreeWirePort.B);
vex::line rightPTO = line(Brain.ThreeWirePort.C);
vex::rotation cataRot = rotation(PORT20, false);
vex::inertial Inert = inertial(PORT19);
////////////////////  Const Values (DO NOT CHANGE)    ///////////////////////
bool f1 = true;
////////////////////////  Tuning Values   ///////////////////////////////////
double lineSensorEdgeValue = 0.5;
////////////////////////   State Values    //////////////////////////////////
int state = 0;
bool leftDriveEngaged = false;
bool rightDriveEngaged = false;
/////////////////////////////////////////////////////////////////////////////

void pre_auton(void)
{

}

void autonomous(void)
{

}

void usercontrol(void) 

{
    while (true) {
        // define states of sensors
        // each loop determine if the line sensor dectects a light level greater than the edge case 
        // indecates weather pto gear is engaged or disengaged from the drivetrain
        leftDriveEngaged = (leftPTO.value(pct) > lineSensorEdgeValue); 
        rightDriveEngaged = (rightPTO.value(pct) > lineSensorEdgeValue);

        switch (state) 
        {
            case 0:
                drive(); //run drive state code (see "drive.cpp")
                break;
            case 1:
                //ptoToShoot State
                break;
            case 2:
                //ptoToDrive State
                break;
            case 3:
                //shoot State
                break;
            default:
                printf("%d\n", 404); //if we reach this point, then no we did not
                break;
        } //end of switch (state)
    } //end of while (true)
} //end of void usercontrol (void)

int main() {

  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  while (true) {
    wait(100, msec);
  }
} //end of int main {