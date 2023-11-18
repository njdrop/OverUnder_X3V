#include "vex.h"
using namespace vex;

void soloAutonomousWinPoint () 
{

}

void qualificationOffensive () 
{
        intakeSolenoid.open();
        // back up
        Drive.moveDistance(-10, 100, 0.75, true, true);
        // open wings
        wingsSolenoid.open();
        // push matchload out
        Drive.moveDistance(10, 100, 0.75, true, true);
        // close wings
        wingsSolenoid.close();
        // back up
        Drive.moveDistance(-23, 100, 1, true, true);
        // turn back towards goal
        Drive.turn(-45, 100, 0.75, true);
        // push preload into goal
        Drive.moveDistance(-20, 100, 0.75, true, true);
        // drive away from goal
        Drive.moveDistance(10, 100, 0.75, true, true);
        // point front towards long barrier
        Drive.turn(63, 100, 1, true);
        PTOSolenoid.open();
        wait(500, msec);
        leftMotor3.spin(fwd, 12000, vex::voltageUnits::mV);
        leftMotor4.spin(fwd, 12000, vex::voltageUnits::mV);
        rightMotor3.spin(fwd, 12000, vex::voltageUnits::mV);
        rightMotor4.spin(fwd, 12000, vex::voltageUnits::mV);
        // move towards triball
        Drive.moveDistance(48, 100, 1.45, false, true);
        // stop the intake
        leftMotor3.stop(hold);
        leftMotor4.stop(hold);
        rightMotor3.stop(hold);
        rightMotor4.stop(hold);
        // back up
        Drive.moveDistance(-2, 100, 0.1, false, true);
        // turn to the goal
        Drive.turn(200, 100, 1, false);
        intakeSolenoid.close();
        wingsSolenoid.open();
        // move towards goal to score triball
        Drive.moveDistance(100, 100, 1.75, false, true);
        Drive.moveDistance(-15, 100, 1, false, true);

}

void qualificationOffensiveRisky () 
{
        intakeSolenoid.open();
        // back up
        Drive.moveDistance(-10, 100, 2, true, true);
        // open wings
        wingsSolenoid.open();
        // push matchload out
        Drive.moveDistance(10, 100, 2, true, true);
        // close wings
        wingsSolenoid.close();
        // back up
        Drive.moveDistance(-20, 100, 1.5, true, true);
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
        // lower intake
        intakeSolenoid.open();
        // back up
        Drive.moveDistance(-10, 100, 2, true, true);
        // open wings
        wingsSolenoid.open();
        // push matchload out
        Drive.moveDistance(10, 100, 2, true, true);
        // close wings
        wingsSolenoid.close();
        // back up
        Drive.moveDistance(-20, 100, 1.5, true, true);
        // turn back towards goal
        Drive.turn(45, 100, 1, true);
        // push preload into goal
        Drive.moveDistance(-6, 100, 1, true, true);
        // drive away from goal
        Drive.moveDistance(8, 100, 1, true, true);
        // point backend towards long barrier
        Drive.turn(125, 100, 1, true);
        // drive towards long barrier
        Drive.moveDistance(-52, 100, 2, true, true);
        // push blocker into goal
        Drive.turn(180, 100, 1, true);
        // open blocker
        blockerSolenoid.open();
        wait(500,msec);
        Drive.moveDistance(-4, 100, 1, true, true);
        Drive.turn(173, 100, 1, true);
}

void qualificationDefensiveRisky () 
{
        
}