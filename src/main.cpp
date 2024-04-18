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

// integer used to choose the correct auton route from the array
int autonSelect = 0;
// booling to turn off preauton once drive control starts

bool usercontrolRunning = false;
int usercontrolStartTime = 0;
void pre_auton(void)
{
	// calibrate the inertial sensor
	driveInertial.calibrate();
	//  tracks the first loop that the button has been held
	while (true)
	{	
		autonSelect = int(floor(autonSelector.angle(deg) / (255.0 / NUMBER_OF_AUTONS)));
		// prints the name of the selected auton on the controller
		con.Screen.clearLine(1);
		con.Screen.setCursor(1, 1);
		con.Screen.print((vex::timer::system() - usercontrolStartTime) / 1000);
		con.Screen.setCursor(1, 20);
		con.Screen.print(int((leftMotor1.temperature(fahrenheit) + leftMotor2.temperature(fahrenheit) + leftMotor3.temperature(fahrenheit)) / 3));

		con.Screen.clearLine(2);
		con.Screen.setCursor(2,1);
		con.Screen.print(autonRoutesList[autonSelect].name);
		con.Screen.setCursor(2, 20);
		con.Screen.print(int((rightMotor1.temperature(fahrenheit) + rightMotor2.temperature(fahrenheit) + rightMotor3.temperature(fahrenheit)) / 3));

		con.Screen.clearLine(3);
		con.Screen.setCursor(3,20);
		con.Screen.print(int(Brain.Battery.capacity(pct)));
		
		// prints the name of the selected auton on the brain
		Brain.Screen.clearScreen();
		Brain.Screen.printAt(10, 30, autonRoutesList[autonSelect].name);
		wait(200, msec);
	}
	con.Screen.clearScreen();
	Brain.Screen.clearScreen();
}

void autonomous ()
{
	int startTime = vex::timer::system();
	// run the route function of the auton selected from the array
	autonRoutesList[autonSelect].routeFunction();
	printf("%lu\n", vex::timer::system() - startTime);
}


void usercontrol(void)
{
	usercontrolRunning = true;
	
	// initalize objects to control the wings and pto
	toggleBoolObject rightDropDownToggle (rightDropDown.value());
	toggleBoolObject leftDropDownToggle (leftDropDown.value());
	toggleBoolObject ptoToggle (false);
	toggleBoolObject hangReleaseToggle (false);

	usercontrolStartTime = vex::timer::system();
	if (autonRoutesList[autonSelect].name == autonSkills.name) 
	{
		// if driver skills was the selected auton first run the driveskill route if one exists
		driverSkills.routeFunction();
	}


	// if driverskills is selected automaticly terminate uercontrol after 60 seconds, otherwise this will never exit
	while (!(autonRoutesList[autonSelect].name == autonSkills.name) || (vex::timer::system() - usercontrolStartTime) <= 60000)
	{
		// records the value of the left stick
		double leftStickY = con.Axis3.value() * 100;
		// records the value of the right stick
		double rightStickY = con.Axis2.value() * 100;
		// runs the 2 left side drive motors at right stick value
		Drive.runLeftSide(nearbyint(leftStickY));
		// runs the 2 right side drive motors at right stick value
		Drive.runRightSide(nearbyint(rightStickY));		

		// intake controls
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

		// // kicker controls
		// if (con.ButtonRight.pressing())
		// {
		// 	shooter_Group.spin(fwd, 10000, vex::voltageUnits::mV);
		// }
		// else
		// {
		// 	shooter_Group.stop(coast);
		// }

		// button to release the hang mechanism
		

		

		// check controller input to toggle values for wings and pto
		rightDropDownToggle.changeValueFromInput(con.ButtonY.pressing());
		leftDropDownToggle.changeValueFromInput(con.ButtonRight.pressing());
		ptoToggle.changeValueFromInput(con.ButtonX.pressing());
		hangReleaseToggle.changeValueFromInput(con.ButtonUp.pressing());

		// set all pnematics to their desired states
		rightDropDown.set(rightDropDownToggle.getValue());
		leftDropDown.set(leftDropDownToggle.getValue());
		rightWing.set(con.ButtonR2.pressing());
		leftWing.set(con.ButtonL2.pressing());
		pto.set(ptoToggle.getValue());
		hangRelease.set(hangReleaseToggle.getValue());

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