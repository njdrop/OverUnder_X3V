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
int minRot = 0;
int maxRot = 240;
bool usercontrolRunning = false;
void pre_auton(void)
{
	// calibrate the inertial sensor
	driveInertial.calibrate();
	//  tracks the first loop that the button has been held
	while (!Brain.Screen.pressing() && !usercontrolRunning)
	{	
		// prints the name of the selected auton on the controller
		autonSelect = int(floor(autonSelector.angle(deg) / (250.0 / NUMBER_OF_AUTONS)));
		con.Screen.clearScreen();
		con.Screen.setCursor(1,1);
		con.Screen.print(autonRoutesList[autonSelect].name);
		Brain.Screen.clearScreen();
		Brain.Screen.printAt(69, 69, autonRoutesList[autonSelect].name);
		wait(50, msec);
	}
	con.Screen.clearScreen();
	Brain.Screen.clearScreen();
}

void autonomous ()
{
	// Drive.moveDistance(50, 100, 15);
	autonRoutesList[autonSelect].routeFunction();
}


void usercontrol(void)
{
	int startTime = vex::timer::system();
	if (autonRoutesList[autonSelect].name == driverSkills.name) {
		driverSkills.routeFunction();
	}
	usercontrolRunning = true;

	toggleBoolObject dropDownToggle (dropDown1.value());
	toggleBoolObject ptoToggle (false);
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

		if (con.ButtonR1.pressing())
		{
			intake_Group.spin(fwd, 12000, vex::voltageUnits::mV);
		}
		else if (con.ButtonL1.pressing())
		{
			intake_Group.spin(fwd, -12000, vex::voltageUnits::mV);
		}
		else
		{
			intake_Group.stop(coast);
		}

		if (con.ButtonDown.pressing())
		{
			shooter_Group.spin(fwd, 12000, vex::voltageUnits::mV);
		}
		else
		{
			shooter_Group.stop(coast);
		}

		dropDownToggle.changeValueFromInput(con.ButtonB.pressing());
		ptoToggle.changeValueFromInput(con.ButtonUp.pressing() && con.ButtonY.pressing());

		dropDown1.set(dropDownToggle.getValue());
		dropDown2.set(dropDownToggle.getValue());
		rightWing.set(con.ButtonR2.pressing());
		leftWing.set(con.ButtonL2.pressing());
		pto.set(ptoToggle.getValue());

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