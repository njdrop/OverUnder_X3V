/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       2024noahdropsey                                           */
/*    Created:      10/24/2023, 2:43:16 PM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
//hi
#include "vex.h"
#include "MiniPID.cpp"
using namespace vex;
competition Competition;
//hi
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
  vex::rotation cataRot = rotation(PORT20, false);
  vex::inertial Inert = inertial(PORT19);
/////////////////////////////////////////////////////////////////////////////
  bool calibrated = false;
  bool driveEngaged = true;
  double cataLoadedPosition = 345;
  double cataUnloadedPosition = 280;
  double cataSpeedPct = 0.6;
  bool f1 = true;
/////////////////////////////////////////////////////////////////////////////

void calibrate() 
{
  if (!calibrated) 
  {
    Inert.calibrate();
    wait(2500, msec);
    calibrated = true;
    if (driveEngaged) 
    {
      //if pto is set to be engaged to drive then set pto solenoid to switch to drive
      PTOSolenoid.open();
    } 
    else 
    {    
      //otherwise set the solenoid to switch to catapult and intake
      PTOSolenoid.close();
    }
  }
}


void pre_auton(void)
{
  calibrate();
}

void autonomous(void)
{
  calibrate();
  PTOSolenoid.open();
  leftMotor1.spin(reverse, 12000, vex::voltageUnits::mV);
  leftMotor2.spin(reverse, 12000, vex::voltageUnits::mV);
  leftMotor3.spin(reverse, 12000, vex::voltageUnits::mV);
  leftMotor4.spin(reverse, 12000, vex::voltageUnits::mV);
  rightMotor1.spin(reverse, 12000, vex::voltageUnits::mV);
  rightMotor2.spin(reverse, 12000, vex::voltageUnits::mV);
  rightMotor3.spin(reverse, 12000, vex::voltageUnits::mV);
  rightMotor4.spin(reverse, 12000, vex::voltageUnits::mV);
  wait(2000, msec);
  leftMotor1.spin(fwd, 12000, vex::voltageUnits::mV);
  leftMotor2.spin(fwd, 12000, vex::voltageUnits::mV);
  leftMotor3.spin(fwd, 12000, vex::voltageUnits::mV);
  leftMotor4.spin(fwd, 12000, vex::voltageUnits::mV);
  rightMotor1.spin(fwd, 12000, vex::voltageUnits::mV);
  rightMotor2.spin(fwd, 12000, vex::voltageUnits::mV);
  rightMotor3.spin(fwd, 12000, vex::voltageUnits::mV);
  rightMotor4.spin(fwd, 12000, vex::voltageUnits::mV);
  wait(1000, msec);
  leftMotor1.stop();
  leftMotor2.stop();
  leftMotor3.stop();
  leftMotor4.stop();
  rightMotor1.stop();
  rightMotor2.stop();
  rightMotor3.stop();
  rightMotor4.stop();
}


void usercontrol(void) {
  
  calibrate();
  // if the inertial is not callibrated then do so
  while (true) 
  {
    if (driveEngaged) 
    {
      //if pto is set to be engaged to drive then set pto solenoid to switch to drive
      PTOSolenoid.open();
    } 
    else 
    {    
      //otherwise set the solenoid to switch to catapult and intake
      PTOSolenoid.close();
    }
    
    if (con.ButtonL2.pressing()) 
    {
      wingsSolenoid.open();
    }
    else
    {
      wingsSolenoid.close();
    }

    //get values for left and right joysticks
    double leftStick = con.Axis3.value();
    double rightStick = con.Axis2.value();
    //always spin direct drive motors at joy stick value speed
    leftMotor1.spin(fwd, leftStick * 120, vex::voltageUnits::mV);
    leftMotor2.spin(fwd, leftStick * 120, vex::voltageUnits::mV);
    rightMotor1.spin(fwd, rightStick * 120, vex::voltageUnits::mV);
    rightMotor2.spin(fwd, rightStick * 120, vex::voltageUnits::mV);


    //if toggle button is pressed then...
    if (con.ButtonA.pressing()) 
    {
      if (f1)
      {
        //if this is the first loop that the button is pressed 
        //then record variable to mark that it is no longer the first loop
        //this ensure the toogle is only fliped once for each time the button is pressed 
        //even if the button is held down
        f1 = false;
        //swith pto from engaged to not egaged or visa versa
        driveEngaged = !driveEngaged;
      }
    } else {
      //when toggle button is release record that it can be the first loop again
      f1 = true;
    }

    //if any of the intake or catapult related buttons are pressed 
    //the pto will switch to disengage from the drivetrain if it isn't already
    if (con.ButtonR1.pressing() || con.ButtonR2.pressing() || con.ButtonL1.pressing()) 
    {
      driveEngaged = false;
    }


    if (driveEngaged) 
    {
      //if pto is engaged to drive then spin pto motor at joy stick speeds
      leftMotor3.spin(fwd, nearbyint(leftStick * 120), vex::voltageUnits::mV);
      leftMotor4.spin(fwd, nearbyint(leftStick * 120), vex::voltageUnits::mV);
      rightMotor3.spin(fwd, nearbyint(rightStick * 120), vex::voltageUnits::mV);
      rightMotor4.spin(fwd, nearbyint(rightStick * 120), vex::voltageUnits::mV);
    }
    else
    {
      //if pto is engaged with intake cata then...
      if (con.ButtonR1.pressing()) 
      {
        //if intake button pressed then spin intake
        leftMotor3.spin(fwd, 12000, vex::voltageUnits::mV);
        leftMotor4.spin(fwd, 12000, vex::voltageUnits::mV);
        rightMotor3.spin(fwd, 12000, vex::voltageUnits::mV);
        rightMotor4.spin(fwd, 12000, vex::voltageUnits::mV);
      }
      else if (con.ButtonR2.pressing()) 
      {
        if (cataRot.velocity(rpm) < 0) 
        {
          //if cata is currently firing
          //cata stop
          leftMotor3.stop(coast);
          leftMotor4.stop(coast);
          rightMotor3.stop(coast);
          rightMotor4.stop(coast);
        }
        else
        {
          //if intake reverse button pressed then spin intake reverse
          leftMotor3.spin(reverse, 3000, vex::voltageUnits::mV);
          leftMotor4.spin(reverse, 3000, vex::voltageUnits::mV);
          rightMotor3.spin(reverse, 3000, vex::voltageUnits::mV);
          rightMotor4.spin(reverse, 3000, vex::voltageUnits::mV); 
        }
      } 
      else
      {
        //if niether intake button is being pressed then begin catapult sequence
        if (cataRot.velocity(rpm) < 0) 
        {
          //if cata is currently firing
          //cata stop
          leftMotor3.stop(coast);
          leftMotor4.stop(coast);
          rightMotor3.stop(coast);
          rightMotor4.stop(coast);
        } 
        else if (cataRot.position(deg) < cataLoadedPosition) 
        {
          //if cata is not firing and cata is not loaded
          //cata spin (pull back)
          leftMotor3.spin(reverse, 12000*cataSpeedPct, vex::voltageUnits::mV);
          leftMotor4.spin(reverse, 12000*cataSpeedPct, vex::voltageUnits::mV);
          rightMotor3.spin(reverse, 12000*cataSpeedPct, vex::voltageUnits::mV);
          rightMotor4.spin(reverse, 12000*cataSpeedPct, vex::voltageUnits::mV); 
        } 
        else
        {
          //if cata is not firing and is loaded then...
          if (con.ButtonL1.pressing()) 
          {
            //if pressing launch button then spin cata to launch
            leftMotor3.spin(reverse, 12000*cataSpeedPct, vex::voltageUnits::mV);
            leftMotor4.spin(reverse, 12000*cataSpeedPct, vex::voltageUnits::mV);
            rightMotor3.spin(reverse, 12000*cataSpeedPct, vex::voltageUnits::mV);
            rightMotor4.spin(reverse, 12000*cataSpeedPct, vex::voltageUnits::mV); 
          }
          else
          {
            //if not pressing launch button then stop the cata and continue to wait for the button to be pressed
            leftMotor3.stop(coast);
            leftMotor4.stop(coast);
            rightMotor3.stop(coast);
            rightMotor4.stop(coast);
          }
        }
      } 
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
}
