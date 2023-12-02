#include "vex.h"
using namespace vex;

void doNothing()
{
    // do nothing
}

void skills1()
{
    // set robot in match load configuration
    blockerSolenoid.open();
    intakeSolenoid.open();
    wingsSolenoid.open();
    int cycle = 1;
    while (true)
    {
        // wait for the matchloads to be loaded
        wait(2900, msec);
        // close the blocker so we fit under the bar
        blockerSolenoid.close();
        // drive under the hang bar
        Drive.turn(-10, 100, 0.25, true);
        Drive.moveDistance(50, 100, 1.65, true, true);
        Drive.turn(-15, 100, 0.25, true);
        Drive.moveDistance(20, 90, 0.75, true, true);
        // turn to the goal
        Drive.turn(-50, 100, 0.3, true);
        // push the triballs near the goal
        Drive.moveDistance(25, 100, 0.65, true, true);
        // use the wings to kick a few of them that are stuck on the wall closer to the goal
        Drive.turn(-100, 100, 0.65, true);
        Drive.turn(-50, 100, 0.75, true);
        wingsSolenoid.close();
        // go towards the far wall
        Drive.moveDistance(-10, 100, 0.65, true, true);
        // turn towards the far wall
        Drive.turn(-20, 100, 0.4, true);
        // go towards the far wall
        Drive.moveDistance(10, 100, 0.5, true, true);
        // turn back end to the goal
        Drive.turn(95, 100, 0.85, true);
        // push triablls ino the goal
        Drive.moveDistance(-40, 100, 0.75, true, true);
        if (cycle == 4)
        {
            Drive.moveDistance(25, 100, 0.5, true, true);
            Drive.turn(105, 100, 0.2, true);
            Drive.moveDistance(-40, 100, 0.75, true, true);
        }
        else
        {
            // insure robot has not tunred while pushing
            Drive.turn(95, 100, 0.2, true);
            // drive back to algin with alley way
            Drive.moveDistance(32, 80, 1, true, false);
            // turn back side towards alley way
            Drive.turn(-22, 100, 0.85, true);
            // drive to the matchload bar progessivly slowing down
            Drive.moveDistance(-65, 100, 1.65, true, false);
            Drive.turn(0, 100, 0.4, true);
            Drive.moveDistance(-17, 80, 0.6, true, false);
            // set robot to be ready for matchl loadding
            blockerSolenoid.open();
            wingsSolenoid.open();
        }
        // track the number of cycle
        cycle++;
    }
}

void skills2()
{
    // set robot in match load configuration
    blockerSolenoid.open();
    intakeSolenoid.open();
    wingsSolenoid.open();
    int counter = 0;
    while (true)
    {
        // wait for the matchloads to be loaded
        wait(2900 + 1000 * counter, msec);
        // close the blocker so we fit under the bar
        blockerSolenoid.close();
        // drive under the hang bar
        Drive.turn(-10, 100, 0.5, true);
        Drive.moveDistance(25, 100, 0.75, true, true);
        Drive.turn(-23, 100, 0.5, true);
        Drive.moveDistance(45, 90, 1.75, true, true);

        // turn to the goal
        Drive.turn(-55, 100, 0.5, true);
        // push the triballs near the goal
        Drive.moveDistance(30, 100, 0.75, true, true);
        // use the wings to kick a few of them that are stuck on the wall closer to the goal
        Drive.turn(-80, 100, 0.75, true);
        wingsSolenoid.close();
        // back up away from triballs
        Drive.moveDistance(-7, 100, 0.5, true, true);

        // turn back end closer to the outer corner of the goal
        Drive.turn(90, 100, 1, true);
        // push triablls ino the goal
        Drive.moveDistance(-40, 100, 0.75, true, false);
        // ensure drive has not turned
        Drive.turn(90, 100, 0.25, true);

        // back off of the goal
        Drive.moveDistance(15, 100, 0.5, true, true);
        // turn towards the far wall
        Drive.turn(125, 100, 0.5, true);
        // go towards the far wall
        Drive.moveDistance(-10, 100, 0.75, true, true);

        // turn more towards the corner of the goal this time
        Drive.turn(90, 100, 0.5, true);
        // push a second time
        Drive.moveDistance(-40, 100, 0.75, true, false);

        if (counter == 2)
        {
            // back it up
            Drive.moveDistance(10, 100, .5, true, true);
            // yolo
            Drive.moveDistance(-10, 100, .5, true, true);
        }
        else
        {
            // insure robot has not tunred while pushing
            Drive.turn(95, 100, 0.25, true);

            // drive back to algin with alley way
            Drive.moveDistance(30, 75, 1.25, true, true);
            // turn back side towards alley way
            Drive.turn(-23, 100, 1, true);

            // drive to the matchload bar
            Drive.moveDistance(-68, 80, 2, true, true);
            Drive.turn(0, 100, 0.4, true);
            Drive.moveDistance(-12, 80, 0.75, true, true);

            // set robot to be ready for matchl loadding
            blockerSolenoid.open();
            wingsSolenoid.open();
            counter++;
        }
    }
}

void soloAutonomousWinPoint()
{
   
}

void qualificationOffensive()
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
    leftPTO_Group.spin(fwd, MAX_MOTOR_VOLTAGE, vex::voltageUnits::mV);
    rightPTO_Group.spin(fwd, MAX_MOTOR_VOLTAGE, vex::voltageUnits::mV);
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

void qualificationOffensiveRisky()
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
    Drive.driveState = state::ptoDriveToCata;
    wait(3000, msec);
    // start intake
    leftPTO_Group.spin(fwd, MAX_MOTOR_VOLTAGE, vex::voltageUnits::mV);
    rightPTO_Group.spin(fwd, MAX_MOTOR_VOLTAGE, vex::voltageUnits::mV);
    // move towards triball
    Drive.moveDistance(43.25, 100, 2, false, true);
    // stop the intake
    leftMotor3.stop(hold);
    leftMotor4.stop(hold);
    rightMotor3.stop(hold);
    rightMotor4.stop(hold);
    // switch pto back to drive
    Drive.driveState = state::ptoCataToDrive;
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

void qualificationDefensive()
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
    wait(500, msec);
    Drive.moveDistance(-4, 100, 1, true, true);
    Drive.turn(173, 100, 1, true);
}

void qualificationDefensiveRisky()
{
    qualificationDefensive();
}

void eliminationOffensive()
{
    intakeSolenoid.open();
    blockerSolenoid.open();
    // pto to catapult
    PTOSolenoid.open();
    // start intake
    leftPTO_Group.spin(fwd, 12000, vex::voltageUnits::mV);
    rightPTO_Group.spin(fwd, 12000, vex::voltageUnits::mV);
    // drive forward
    Drive.moveDistance(20, 100, 1.3, false, true);
    // stop intake
    leftPTO_Group.stop();
    rightPTO_Group.stop(); 
    PTOSolenoid.close();
    // drive backward
    Drive.moveDistance(-23, 100, 2.5, true, true);
    //Turn
    Drive.turn(135, 100, 2);
    wingsSolenoid.open();
    // Knock out match load
    Drive.moveDistance(16, 100, 2.5, true, true);
    Drive.turn(110, 100, 1);
    wingsSolenoid.close();
    intakeSolenoid.close();
    Drive.moveDistance(18, 100, 2, true, false);
    Drive.moveDistance(-10, 100, 2, true, false);
    Drive.moveDistance(16, 100, 2, true, false);
    Drive.moveDistance(-10, 100, 2, true, false);
    Drive.turn(180, 100, 1, true);
    Drive.moveDistance(-40, 4, true, true);


}

void eliminationOffensiveRisky()
{
    qualificationOffensive();
}

void eliminationDefensive()
{
    qualificationDefensive();
}

void eliminationDefensiveRisky()
{
    qualificationDefensiveRisky();
}