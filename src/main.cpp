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
	Brain.Screen.smartPrint("CALIBRATED LAKSJFLSKEJFL:KSDJFLKSDJFLKSDJFLKSDJ");
	Drive.startAutoStateMachineTask();
	Drive.driveState = autonRoutesList[autonSelect].initalState;
}


void autonomous(void)
{
	// run the selected auton route
	autonRoutesList[autonSelect].routeFunction();
}

void usercontrol(void)
{
	// ensures the auton program will not interfere with the state machine
	Drive.stopAutoStateMachineTask();
	// contructs boolean objects for the intake lift
	toggleBoolObject intakeToggle(intakeSolenoid.value());
	// contructs boolean objects for the wings
	toggleBoolObject wingsToggle(wingsSolenoid.value());
	// contructs boolean objects for the blocker
	toggleBoolObject blockerToggle(blockerSolenoid.value());

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
		double leftStickY = abs(con.Axis3.value()) / con.Axis3.value() * pow(con.Axis3.value(), 2) / 1.27;
		// records the value of the right stick
		double rightStickX = abs(con.Axis1.value()) / con.Axis1.value() * pow(con.Axis1.value(), 2) / 1.27;

		// runs the 2 left side drive motors at right stick value
		Drive.runLeftSide(nearbyint(leftStickY + rightStickX), Drive.PTO_DriveEngaged);
		// runs the 2 right side drive motors at right stick value
		Drive.runRightSide(nearbyint(leftStickY - rightStickX), Drive.PTO_DriveEngaged);

		double leftpow1 = leftMotor1.power(watt);
		double leftpow2 = leftMotor2.power(watt);
		double leftpow3 = leftMotor3.power(watt);
		double leftpow4 = leftMotor4.power(watt);
		double rightpow1 = rightMotor1.power(watt);
		double rightpow2 = rightMotor2.power(watt);
		double rightpow3 = rightMotor3.power(watt);
		double rightpow4 = rightMotor4.power(watt);
		
		// char rightmotorspow1[1000];
		// char rightmotorspow2[1000];
		// char rightmotorspow3[1000];
		// char rightmotorspow4[1000];
		// sprintf(rightmotorspow1, "%1.1111f", rightpow1);
		// sprintf(rightmotorspow2, "%1.1111f", rightpow2);
		// sprintf(rightmotorspow3, "%1.1111f", rightpow3);
		// sprintf(rightmotorspow4, "%1.1111f", rightpow4);

		printf("%f ", leftpow1);
		printf("%f ", leftpow2);
		printf("%f ", leftpow3);
		printf("%f ", leftpow4);
		printf("%f ", rightpow1);
		printf("%f ", rightpow2);
		printf("%f ", rightpow3);
		printf("%f\n", rightpow4);

		wait(20, msec);
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