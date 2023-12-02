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

    //  tracks the first loop that the button has been held
    bool firstButtonPress = true;
    while (true)
    {
        if (Brain.Screen.pressing())
        {
            // ensure autonSelect is only incremented once per button press
            if (firstButtonPress)
            {
                // increment the value wrapping at 10
                autonSelect = (autonSelect + 1) % NUMBER_OF_AUTONS;
                // record that the first loop has now happened
                firstButtonPress = false;
            }
            // on all other loops while the button is pressed nothing will happen
        }
        else
        {
            // once released, a new button press can increment the autonSelect
            firstButtonPress = true;
        }
        
        con.Screen.smartPrint(autonNames[autonSelect]);
        wait(100, msec);
    }
}

void autonomous(void)
{
    // run the selected auton route from the list of all routes
    autonRoutes[autonSelect]();
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
        leftDriveEngaged = (leftPTO_Sensor.value(pct) > LINE_SENOR_EDGE_VALUE);
        rightDriveEngaged = (rightPTO_Sensor.value(pct) > LINE_SENOR_EDGE_VALUE);

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

int main()
{
    Competition.autonomous(autonomous);
    Competition.drivercontrol(usercontrol);

    pre_auton();

    while (true)
    {
        wait(100, msec);
    }
}