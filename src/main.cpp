/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       2024noahdropsey                                           */
/*    Created:      10/24/2023, 2:43:16 PM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
#include "library.h"
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
vex::pneumatics intakeSolenoid = pneumatics(Brain.ThreeWirePort.D);
vex::pneumatics blockerSolenoid = pneumatics(Brain.ThreeWirePort.E);
vex::line leftPTO = line(Brain.ThreeWirePort.B);
vex::line rightPTO = line(Brain.ThreeWirePort.C);
// vex::rotation cataRot = rotation(PORT20, false);
vex::inertial Inert = inertial(PORT19);


////////////////////  Const Values (DO NOT CHANGE)    ///////////////////////
bool f1 = true;
bool f2 = true;
bool f3 = true;
////////////////////////  Tuning Values   ///////////////////////////////////
double lineSensorEdgeValue = 57; // the percent at which the line sensor should read the the pto gear has engaged with the drivetrain
////////////////////////   State Values    //////////////////////////////////
int state = 0; // state control => changes what configuration the bot is in depending on the state
bool leftDriveEngaged = true; // a boolean value that determines weather the light sensor reads that the pto gear is moved to engae with the left side of the drivetrain
bool rightDriveEngaged = true; // a boolean value that determines weather the light sensor reads that the pto gear is moved to engae with the right side of the drivetrain
/////////////////////////////////////////////////////////////////////////////

void pre_auton(void)
{
}

void autonomous(void)
{

}

void usercontrol(void) 
{
    // initalizes boolean objects for the intake lift
    toggleBoolObject intakeToggle(false);
    // initalizes boolean objects for the wings
    toggleBoolObject wingsToggle(false);
    // initalizes boolean objects for the blocker
    toggleBoolObject blockerToggle(false);

    while (true) 
    {
        printf("%f\n", leftMotor3.power(vex::powerUnits::watt));
        // define states of sensors
        // each loop determine if the line sensor dectects a light level greater than the edge case 
        // indecates weather pto gear is engaged or disengaged from the drivetrain
        leftDriveEngaged = (leftPTO.value(pct) > lineSensorEdgeValue); 
        rightDriveEngaged = (rightPTO.value(pct) > lineSensorEdgeValue);


        //////////////////////////// Universal Controls ////////////////////////////
        
        // toggles wings using button Up (see library.cpp for explaination)
        wingsToggle.changeValueFromInput(con.ButtonUp.pressing());
        lib::toggleSolenoid(wingsSolenoid, wingsToggle.getValue());
        
        // toggles blocker using button B (see library.cpp for explaination)
        blockerToggle.changeValueFromInput(con.ButtonB.pressing());
        lib::toggleSolenoid(blockerSolenoid, blockerToggle.getValue());

        // toggles intake lift using button X (see library.cpp for explaination)
        intakeToggle.changeValueFromInput(con.ButtonX.pressing());
        lib::toggleSolenoid(intakeSolenoid, intakeToggle.getValue());

        double leftStickY = con.Axis3.value() * 100; 
        // runs the 2 left side drive motors at right stick value
        leftMotor1.spin(fwd, nearbyint(leftStickY), vex::voltageUnits::mV);
        leftMotor2.spin(fwd, nearbyint(leftStickY), vex::voltageUnits::mV);

        double rightStickY = con.Axis2.value() * 100; 
        // runs the 2 right side drive motors at right stick value
        rightMotor1.spin(fwd, nearbyint(rightStickY), vex::voltageUnits::mV);
        rightMotor2.spin(fwd, nearbyint(rightStickY), vex::voltageUnits::mV);
  
        //////////////////////////// State Control ////////////////////////////
        switch (state) 
        {
            case 0:
                drive(); // run drive state code (see "drive.cpp")
                break;
            case 1:
                con.rumble("-");
                ptoDriveToCata(); // ptoToShoot State
                break;
            case 2:
                con.rumble(".");
                ptoCataToDrive(); // ptoToDrive State
                break;
            case 3:
                shoot(); // shoot State
                break;
            default:
                printf("%d\n", 404); // if we reach this point, then no we did not
                break;
        } // end of switch (state)
    } // end of while (true)
} // end of void usercontrol (void)

int main() {

  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  while (true) {
    wait(100, msec);
  }
} // end of int main {