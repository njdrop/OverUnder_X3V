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


void pre_auton(void)
{
    inertialSensor.calibrate();
}

void autonomous(void)
{
    // wait(2000, msec);
    // Drive.state=1;
    // while (Drive.state == 1)
    // {
    //     wait(10, msec);
    // }
    // Drive.turn(90, 100, 5, Drive.PTO_DriveEngaged);
    // Drive.moveDistance(30, 100, 5, Drive.PTO_DriveEngaged);
    Drive.stopAutoStateMachineTask();
    PTOSolenoid.open();

    while(vex::timer::system() <= 20000)
    {
        leftMotor3.spin(fwd, -12000, vex::voltageUnits::mV);
        leftMotor4.spin(fwd, -12000, vex::voltageUnits::mV);
        rightMotor3.spin(fwd, -12000, vex::voltageUnits::mV);
        rightMotor4.spin(fwd, -12000, vex::voltageUnits::mV);
        printf("%f\t", catapultRotationSensor.position(deg));
        printf("%f\t", leftMotor3.torque(vex::torqueUnits::Nm));
        printf("%f\t", leftMotor4.torque(vex::torqueUnits::Nm));
        printf("%f\t", rightMotor3.torque(vex::torqueUnits::Nm));
        printf("%f\n", rightMotor4.torque(vex::torqueUnits::Nm));
        wait(10, msec);
    }
}

void usercontrol(void) 
{
    Drive.stopAutoStateMachineTask();
    // initalizes boolean objects for the intake lift
    toggleBoolObject intakeToggle(false);
    // initalizes boolean objects for the wings
    toggleBoolObject wingsToggle(false);
    // initalizes boolean objects for the blocker
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

        double leftStickY = con.Axis3.value() * 100; 
        // runs the 2 left side drive motors at right stick value
        Drive.runLeftSide(nearbyint(leftStickY));

        double rightStickY = con.Axis2.value() * 100; 
        // runs the 2 right side drive motors at right stick value
        Drive.runRightSide(nearbyint(rightStickY));
  
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