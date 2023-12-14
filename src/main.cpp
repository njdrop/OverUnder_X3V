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
	while (!Brain.Screen.pressing())
	{
		if (autonSelectorSwitch.pressing())
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
		
		// prints the name of the selected auton on the controller
		con.Screen.smartPrint(autonRoutesList[autonSelect].name);
		Brain.Screen.smartPrint(autonRoutesList[autonSelect].name);
		wait(100, msec);
	}
	// calibrate the drivetrain
	(*driveIntertial).calibrate();
	wait(3000, msec);
	Brain.Screen.smartPrint("CALIBRATED");

	// set position
	Drive.setPosition(0, 0);

	// start tracking
	Drive.startTracking();

}


void autonomous(void)
{
	// run the selected auton route
	autonRoutesList[autonSelect].routeFunction();
}

void usercontrol(void)
{
	Drive.startTracking();
	while (true)
	{
		// records the value of the left stick
		double leftStickY = con.Axis3.value() * 100;
		// records the value of the right stick
		double rightStickY = con.Axis2.value() * 100;

		// runs the 2 left side drive motors at right stick value
		Drive.runLeftSide(nearbyint(leftStickY));
		// runs the 2 right side drive motors at right stick value
		Drive.runRightSide(nearbyint(rightStickY));
		
		if (con.ButtonB.pressing())
		{
			printf("%lu ", vex::timer::system());
			printf("%f ", Drive.getX());
			printf("%f ", Drive.getY());
			printf("%f\n", Drive.getHeading());
		}
		
		wait(10, msec);
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