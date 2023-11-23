/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Noah Dropsey                                              */
/*    Created:      10/24/2023, 2:43:16 PM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
using namespace vex;
competition Competition;

int autonSelect = 0;
void pre_auton(void)
{
    // calibrate the inertial sensor
    inertialSensor.calibrate();
    bool firstButtonPress = true;
    while (true) 
    {
        if (Brain.Screen.pressing())
        {
            // ensure autonSelect is only incremented once per button press
            if(firstButtonPress)
            {
                // record the the first loop has now happened
                firstButtonPress = false;
                if(autonSelect == 10) //3
                {
                    // if autonSelect has reached the end then cycle it
                    autonSelect = 0;
                }
                else
                {
                    // increment autonSelect
                    autonSelect++;
                }
            }
        }
        else
        {
            // record the the button has been released so that a new button press is allowed to increment the autonSelect
            firstButtonPress = true;
        }

        con.Screen.clearScreen();
        con.Screen.setCursor(1, 1);
        con.Screen.print(autonSelect);
        con.Screen.print(" - ");
        con.Screen.print(autoNames[autonSelect]);
        wait(100, msec);
    }
}

void autonomous(void)
{
    // autonomous selector
    switch (autonSelect)
    {
        case 0:
            // do nothing
            break;
        case 1:
            // skills
            autonSkills2();
            break;
        case 2:
            // Qualification Offensive
            qualificationOffensive();
            break;
        case 3:
            // Qualification Offensive Risky
            qualificationOffensiveRisky();
            break;
        case 4:
            // Qualification Defensive
            qualificationDefensive();
            break;
        case 5:
            // Qualification Defensive Risky
            qualificationDefensiveRisky();
            break;
        case 6:
            // Elimination Offensive
            eliminationOffensive();
            break;
        case 7:
            // Elimination Defensive
            eliminationOffensiveRisky();
            break;
        case 8:
            // Elimination Offensive Risky
            eliminationDefensive();
            break;
        case 9:
            // Elimination Defensive Risky
            eliminationDefensiveRisky();
            break;
         case 10:
            // Solo Autonomous Win Point            
            soloAutonomousWinPoint();
            break;
        default:
            break;
    }
}



void usercontrol(void) 
{
   // ensures the auton program will not interfere with the state machine
    Drive.stopAutoStateMachineTask();
    // contructs boolean objects for the intake lift
    toggleBoolObject intakeToggle(false);
    // contructs boolean objects for the wings
    toggleBoolObject wingsToggle(false);
    // contructs boolean objects for the blocker
    toggleBoolObject blockerToggle(false);

    while (true) 
    {
        // define states of sensors
        // each loop determine if the line sensor dectects a light level greater than the edge case 
        // indecates weather pto gear is engaged or disengaged from the drivetrain
        leftDriveEngaged = (leftPTO.value(pct) > lineSensorEdgeValue); 
        rightDriveEngaged = (rightPTO.value(pct) > lineSensorEdgeValue);

        //////////////////////////// Universal Controls ////////////////////////////
        
        // toggles wings using button Up (see library.cpp for explaination)
        wingsToggle.changeValueFromInput(con.ButtonL2.pressing());
        lib::toggleSolenoid(wingsSolenoid, wingsToggle.getValue());
        
        // toggles blocker using button B (see library.cpp for explaination)
        blockerToggle.changeValueFromInput(con.ButtonB.pressing());
        lib::toggleSolenoid(blockerSolenoid, blockerToggle.getValue());

        // toggles intake lift using button X (see library.cpp for explaination)
        intakeToggle.changeValueFromInput(con.ButtonX.pressing());
        lib::toggleSolenoid(intakeSolenoid, intakeToggle.getValue());

        // records the value of the left stick
        double leftStickY = con.Axis3.value() * 100; 
        // runs the 2 left side drive motors at right stick value
        Drive.runLeftSide(nearbyint(leftStickY));

        // records the value of the right stick
        double rightStickY = con.Axis2.value() * 100; 
        // runs the 2 right side drive motors at right stick value
        Drive.runRightSide(nearbyint(rightStickY));
  
        //////////////////////////// State Control ////////////////////////////
        switch (currentState) 
        {
            case state::drive:
                drive();
                break;
            case state::ptoDriveToCata:
                con.rumble("-");
                ptoDriveToCata();
                break;
            case state::ptoCataToDrive:
                con.rumble(".");
                ptoCataToDrive();
                break;
            case state::shoot:
                shoot();
                break;
            default:
                printf("%d\n", 404); // if we reach this point, then no we did not
                break;
        }
    }
}

int main() {

  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  while (true) {
    wait(100, msec);
  }
} // end of int main {