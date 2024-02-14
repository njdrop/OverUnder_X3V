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
bool usercontrolRunning = false;
void pre_auton(void)
{
	// calibrate the inertial sensor
	driveInertial.calibrate();
	//  tracks the first loop that the button has been held
	bool firstButtonPress = true;
	while (!Brain.Screen.pressing() && !usercontrolRunning)
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
		con.Screen.clearScreen();
		con.Screen.setCursor(1,1);
		con.Screen.print(autonRoutesList[autonSelect].name);
		Brain.Screen.clearScreen();
		Brain.Screen.printAt(69, 69, autonRoutesList[autonSelect].name);
		wait(100, msec);
	}
}

void autonomous ()
{
	autonRoutesList[autonSelect].routeFunction();
}

void usercontrol(void)
{
	int startTime = vex::timer::system();
	if (autonRoutesList[autonSelect].name == driverSkills.name) {
		driverSkills.routeFunction();
	}
	usercontrolRunning = true;
	toggleBoolObject frontWingsToggle(frontLeftWing.value() && frontRightWing.value());
	toggleBoolObject backWingsToggle(backWings.value());
	toggleBoolObject liftToggle(lift.value());
	toggleBoolObject intakeLiftToggle(intakeLift.value());
	while (!(autonRoutesList[autonSelect].name == driverSkills.name) || (vex::timer::system() - startTime) <= 60000.0)
	{
		con.Screen.clearScreen();
		con.Screen.setCursor(1,1);
		con.Screen.print((vex::timer::system() - startTime) / 1000);
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
			shooter_Group.spin(fwd, 8000, vex::voltageUnits::mV);
		}
		else if (con.ButtonDown.pressing())
		{
			shooter_Group.spin(fwd, 12000, vex::voltageUnits::mV);
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

		
		frontLeftWing.set(frontWingsToggle.getValue());
		frontRightWing.set(frontWingsToggle.getValue());
		backWings.set(backWingsToggle.getValue());
		intakeLift.set(intakeLiftToggle.getValue());
		lift.set(liftToggle.getValue());

		wait(10, msec);
	}
	Drive.stopLeftSide(coast);
	Drive.stopRightSide(coast);
	intake_Group.stop();
	shooter_Group.stop();
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