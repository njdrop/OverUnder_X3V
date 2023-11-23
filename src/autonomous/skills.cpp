#include "vex.h"
using namespace vex;

void autonSkills1()
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

void autonSkills2()
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