#include "vex.h"
using namespace vex;

void soloAutonomousWinPoint () 
{

}

void qualificationOffensive () 
{
        intakeSolenoid.open();
        // Drive.driveState = 0;
        // Drive.startAutoStateMachineTask();
        // back up
        Drive.moveDistance(-10, 100, 2, true, true);
        // open wings
        wingsSolenoid.open();
        // push matchload out
        Drive.moveDistance(10, 100, 2, true, true);
        // close wings
        wingsSolenoid.close();
        // back up
        Drive.moveDistance(-34, 100, 2, true, true);
        // turn back towards goal
        Drive.turn(45, 100, 2, true);
        // push preload into goal
        Drive.moveDistance(-12, 100, 2, true, true);
        // drive away from goal
        Drive.moveDistance(10, 100, 2, true, true);
        // point front towards long barrier
        Drive.turn(-45, 100, 2, true);
        // drive towards long barrier
        Drive.moveDistance(48, 100, 2, true, true);
        // // point front towards triball barrier
        // Drive.turn(-101.3, 100, 2, true);
        // // pto to catapult
        // Drive.driveState = 1;
        // wait(3000, msec);
        // // start intake
        // leftMotor3.spin(fwd, 12000, vex::voltageUnits::mV);
        // leftMotor4.spin(fwd, 12000, vex::voltageUnits::mV);
        // rightMotor3.spin(fwd, 12000, vex::voltageUnits::mV);
        // rightMotor4.spin(fwd, 12000, vex::voltageUnits::mV);
        // // move towards triball
        // Drive.moveDistance(43.25, 100, 2, false, true);
        // // stop the intake
        // leftMotor3.stop(hold);
        // leftMotor4.stop(hold);
        // rightMotor3.stop(hold);
        // rightMotor4.stop(hold);
        // // switch pto back to drive
        // Drive.driveState = 2;
        // wait(3000, msec);
        // // back up
        // Drive.moveDistance(-10, 100, 2, true, true);
        // // turn towards goal
        // Drive.turn(-225, 100, 2, true);
        // // open wings
        // wingsSolenoid.open();
        // // lift intake
        // intakeSolenoid.open();
        // // push both triballs in
        // Drive.moveDistance(40, 100, 2, true, true);
        // // back up
        // Drive.moveDistance(-10, 100, 2, true, true);
        // turn towards hang bar
        Drive.turn(0, 100, 2, true);
        // open blocker
        blockerSolenoid.open();
        // // drive to hang bar
        // Drive.moveDistance(34, 100, 2, true, true);
        // push blocker into hang bar
        Drive.turn(-20, 100, 2, true);

}

void qualificationOffensiveRisky () 
{
        intakeSolenoid.open();
        Drive.driveState = 0;
        Drive.startAutoStateMachineTask();
        // back up
        Drive.moveDistance(-10, 100, 2, true, true);
        // open wings
        wingsSolenoid.open();
        // push matchload out
        Drive.moveDistance(10, 100, 2, true, true);
        // close wings
        wingsSolenoid.open();
        // back up
        Drive.moveDistance(-34, 100, 2, true, true);
        // turn back towards goal
        Drive.turn(45, 100, 2, true);
        // push preload into goal
        Drive.moveDistance(-12, 100, 2, true, true);
        // drive away from goal
        Drive.moveDistance(10, 100, 2, true, true);
        // point front towards long barrier
        Drive.turn(-45, 100, 2, true);
        // drive towards long barrier
        Drive.moveDistance(36, 100, 2, true, true);
        // point front towards triball barrier
        Drive.turn(-101.3, 100, 2, true);
        // pto to catapult
        Drive.driveState = 1;
        wait(3000, msec);
        // start intake
        leftMotor3.spin(fwd, 12000, vex::voltageUnits::mV);
        leftMotor4.spin(fwd, 12000, vex::voltageUnits::mV);
        rightMotor3.spin(fwd, 12000, vex::voltageUnits::mV);
        rightMotor4.spin(fwd, 12000, vex::voltageUnits::mV);
        // move towards triball
        Drive.moveDistance(43.25, 100, 2, false, true);
        // stop the intake
        leftMotor3.stop(hold);
        leftMotor4.stop(hold);
        rightMotor3.stop(hold);
        rightMotor4.stop(hold);
        // switch pto back to drive
        Drive.driveState = 2;
        wait(3000, msec);
        // back up
        Drive.moveDistance(-10, 100, 2, true, true);
        // turn towards goal
        Drive.turn(-225, 100, 2, true);
        // open wings
        wingsSolenoid.open();
        // lift intake
        intakeSolenoid.open();
        // push both triballs in
        Drive.moveDistance(40, 100, 2, true, true);
        // back up
        Drive.moveDistance(-10, 100, 2, true, true);
        // turn towards hang bar
        Drive.turn(0, 100, 2, true);
        // open blocker
        blockerSolenoid.open();
        // drive to hang bar
        Drive.moveDistance(34, 100, 2, true, true);
        // push blocker into hang bar
        Drive.turn(-20, 100, 2, true);
}

void qualificationDefensive () 
{
        intakeSolenoid.open();
        // back up
        Drive.moveDistance(-10, 100, 1, true, true);
        // open wings
        wingsSolenoid.open();
        // push matchload out
        Drive.moveDistance(10, 100, 1, true, true);
        // close wings
        wingsSolenoid.close();
        // back up
        Drive.moveDistance(-22, 100, 1, true, true);
        // turn back towards goal
        Drive.turn(45, 100, 1, true);
        // push preload into goal
        Drive.moveDistance(-8, 100, 1, true, true);
        // drive away from goal
        Drive.moveDistance(8, 100, 1, true, true);
        // point backend towards long barrier
        Drive.turn(125, 100, 1, true);
        // drive towards long barrier
        Drive.moveDistance(-52, 100, 1, true, true);
        // open blocker
        blockerSolenoid.open();
        // push blocker into goal
        Drive.turn(0, 100, 1, true);
}

void qualificationDefensiveRisky () 
{
        
}