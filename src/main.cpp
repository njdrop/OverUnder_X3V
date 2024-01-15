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
	Drive.calibrate();
	driveInertial.calibrate();

	//  tracks the first loop that the button has been held
	bool firstButtonPress = true;
	while (!Brain.Screen.pressing() && !Competition.isDriverControl())
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
}




void usercontrol(void)
{
	con.Screen.clearScreen();
	toggleBoolObject frontWingsToggle(false);
	toggleBoolObject backWingsToggle(false);
	toggleBoolObject liftToggle(lift.value());
	toggleBoolObject intakeLiftToggle(intakeLift.value());
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
		
		frontWingsToggle.changeValueFromInput(con.ButtonX.pressing());
		backWingsToggle.changeValueFromInput(con.ButtonB.pressing());
		liftToggle.changeValueFromInput(con.ButtonUp.pressing());
		
		if (con.ButtonUp.pressing())
		{
			intakeLiftToggle.setValue(true);
		}

		if(con.ButtonR2.pressing())
		{
			intakeLiftToggle.setValue(false);
			backWingsToggle.setValue(false);
		}

		if (con.ButtonL2.pressing())
		{
			shooter_Group.spin(fwd, 12000, vex::voltageUnits::mV);
		}
		else if (false)
		{
			shooter_Group.spin(fwd, 8000, vex::voltageUnits::mV);
		}
		else
		{
			shooter_Group.stop(coast);
		}


		if (con.ButtonR1.pressing())
		{
			intakeLiftToggle.setValue(true);
			intake_Group.spin(fwd, 12000, vex::voltageUnits::mV);
		}
		else if (con.ButtonL1.pressing())
		{
			intakeLiftToggle.setValue(true);
			intake_Group.spin(fwd, -12000, vex::voltageUnits::mV);
		}
		else
		{
			intake_Group.stop(coast);
		}

		
		frontWings.set(frontWingsToggle.getValue());
		backWings.set(backWingsToggle.getValue());
		intakeLift.set(intakeLiftToggle.getValue());
		lift.set(liftToggle.getValue());

		wait(10, msec);
	}
}

int main()
{
	Competition.autonomous(autonRoutesList[autonSelect].routeFunction);
	Competition.drivercontrol(usercontrol);

	pre_auton();
	while (true)
	{
		wait(100, msec);
	}
}