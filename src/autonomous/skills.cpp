#include "vex.h"
using namespace vex;

void autonSkills1 () {
        // set robot in match load configuration
        blockerSolenoid.open();
        intakeSolenoid.open();
        wingsSolenoid.open();
        int cycle = 1;
        while (true) 
        {
                // wait for the matchloads to be loaded
                wait(3000, msec);
                // close the blocker so we fit under the bar
                blockerSolenoid.close();
                // drive under the hang bar
                Drive.turn(-10, 100, 0.25, true, false);
                Drive.moveDistance(50, 100, 1.65, true, false);
                Drive.turn(-15, 100, 0.25, true, false);
                Drive.moveDistance(20, 90, 0.75, true, false);
                // turn to the goal
                Drive.turn(-50, 100, 0.3, true, false);
                // push the triballs near the goal
                Drive.moveDistance(25, 100, 0.65, true, false);
                // use the wings to kick a few of them that are stuck on the wall closer to the goal
                Drive.turn(-100, 100, 0.65, true, false);
                Drive.turn(-50, 100, 0.75, true, false);
                wingsSolenoid.close();
                // go towards the far wall
                Drive.moveDistance(-10, 100, 0.65, true, false);
                // turn towards the far wall
                Drive.turn(-20, 100, 0.4, true, false);
                // go towards the far wall
                Drive.moveDistance(10, 100, 0.5, true, false);
                // turn back end to the goal
                Drive.turn(95, 100, 0.85, true, false);
                // push triablls ino the goal
                Drive.moveDistance(-40, 100, 0.75, true, false);
                if (cycle == 4) 
                {
                        Drive.moveDistance(25, 100, 0.5, true, false);
                        Drive.turn(105, 100, 0.2, true, false);
                        Drive.moveDistance(-40, 100, 0.75, true, false);
                }
                else
                {
                        // insure robot has not tunred while pushing
                        Drive.turn(95, 100, 0.2, true, false);
                        // drive back to algin with alley way
                        Drive.moveDistance(32, 80, 1, true, false);
                        // turn back side towards alley way
                        Drive.turn(-22, 100, 0.85, true, false);
                        //drive to the matchload bar progessivly slowing down
                        Drive.moveDistance(-65, 100, 1.65, true, false);
                        Drive.turn(0, 100, 0.4, true, false);
                        Drive.moveDistance(-17, 80, 0.6, true, false);
                        // set robot to be ready for matchl loadding
                        blockerSolenoid.open();
                        wingsSolenoid.open();
                }
                //track the number of cycle
                cycle ++;
        }
}