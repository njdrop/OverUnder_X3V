#include "vex.h"
using namespace vex;


void doNothingRoute()
{
    // do nothing
}
autonRoute doNothing = {"Do Nothing", 0, 0, 0, doNothingRoute};

void skills1Route()
{
    // set robot in match load configuration
    int cycle = 1;
    while (true)
    {
        // wait for the matchloads to be loaded
        wait(2900, msec);
        // drive under the hang bar
        Drive.turn(-10, 100, 0.25);
        Drive.moveDistance(50, 100, 1.65, true);
        Drive.turn(-15, 100, 0.25);
        Drive.moveDistance(20, 90, 0.75, true);
        // turn to the goal
        Drive.turn(-50, 100, 0.3);
        // push the triballs near the goal
        Drive.moveDistance(25, 100, 0.65, true);
        Drive.turn(-100, 100, 0.65);
        Drive.turn(-50, 100, 0.75);
        // go towards the far wall
        Drive.moveDistance(-10, 100, 0.65, true);
        // turn towards the far wall
        Drive.turn(-20, 100, 0.4);
        // go towards the far wall
        Drive.moveDistance(10, 100, 0.5, true);
        // turn back end to the goal
        Drive.turn(95, 100, 0.85);
        // push triablls ino the goal
        Drive.moveDistance(-40, 100, 0.75, true);
        if (cycle == 4)
        {
            Drive.moveDistance(25, 100, 0.5, true);
            Drive.turn(105, 100, 0.2);
            Drive.moveDistance(-40, 100, 0.75, true);
        }
        else
        {
            // insure robot has not tunred while pushing
            Drive.turn(95, 100, 0.2);
            // drive back to algin with alley way
            Drive.moveDistance(32, 80, 1, true);
            // turn back side towards alley way
            Drive.turn(-22, 100, 0.85);
            // drive to the matchload bar progessivly slowing down
            Drive.moveDistance(-65, 100, 1.65, true);
            Drive.turn(0, 100, 0.4);
            Drive.moveDistance(-17, 80, 0.6, true);
            // set robot to be ready for matchl loadding
        }
        // track the number of cycle
        cycle++;
    }
}
autonRoute skills1 = {"Skills", 0, 0, 0, skills1Route};

void skills2Route()
{
    // set robot in match load configuration
    int counter = 0;
    while (true)
    {
        // wait for the matchloads to be loaded
        wait(2900 + 1000 * counter, msec);
        // drive under the hang bar
        Drive.turn(-10, 100, 0.5);
        Drive.moveDistance(25, 100, 0.75, true);
        Drive.turn(-23, 100, 0.5);
        Drive.moveDistance(45, 90, 1.75, true);

        // turn to the goal
        Drive.turn(-55, 100, 0.5);
        // push the triballs near the goal
        Drive.moveDistance(30, 100, 0.75, true);
        Drive.turn(-80, 100, 0.75);
        // back up away from triballs
        Drive.moveDistance(-7, 100, 0.5, true);

        Drive.turn(90, 100, 1);
        // push triablls ino the goal
        Drive.moveDistance(-40, 100, 0.75, true);
        // ensure drive has not turned
        Drive.turn(90, 100, 0.25);

        // back off of the goal
        Drive.moveDistance(15, 100, 0.5, true);
        // turn towards the far wall
        Drive.turn(125, 100, 0.5);
        // go towards the far wall
        Drive.moveDistance(-10, 100, 0.75, true);

        // turn more towards the corner of the goal this time
        Drive.turn(90, 100, 0.5);
        // push a second time
        Drive.moveDistance(-40, 100, 0.75, true);

        if (counter == 2)
        {
            // back it up
            Drive.moveDistance(10, 100, .5, true);
            // yolo
            Drive.moveDistance(-10, 100, .5, true);
        }
        else
        {
            // insure robot has not tunred while pushing
            Drive.turn(95, 100, 0.25);

            // drive back to algin with alley way
            Drive.moveDistance(30, 75, 1.25, true);
            // turn back side towards alley way
            Drive.turn(-23, 100, 1);

            // drive to the matchload bar
            Drive.moveDistance(-68, 80, 2, true);
            Drive.turn(0, 100, 0.4);
            Drive.moveDistance(-12, 80, 0.75, true);

            // set robot to be ready for matchl loadding
            counter++;
        }
    }
}
autonRoute skills2 = {"Skills", 0, 0, 0, skills2Route};

void skills3Route() 
{
    for (int i = 0; i < 44; i++) 
    {
        while(true) 
        {
            wait(10, msec);
        }
        wait(125, msec);
    }

}
autonRoute skills3 = {"Skills", 0, 0, 0, skills3Route};

void soloAutonomousWinPointRoute()
{
   
}
autonRoute soloAutonomousWinPoint = {"Solo AWP", 0, 0, 0, soloAutonomousWinPointRoute};

void qualificationOffensiveRoute()
{
    // back up
    Drive.moveDistance(-10, 100, 0.75, true);
    // push matchload out
    Drive.moveDistance(10, 100, 0.75, true);
    // back up
    Drive.moveDistance(-23, 100, 1, true);
    // turn back towards goal
    Drive.turn(45, 100, 0.75);
    // push preload into goal
    Drive.moveDistance(-20, 100, 0.75, true);
    // drive away from goal
    Drive.moveDistance(10, 100, 0.75, true);
    // // point front towards long barrier
    // Drive.turn(63, 100, 1);
    // wait(500, msec);


    // // move towards triball
    // Drive.moveDistance(48, 100, 1.45, false);
    // // stop the intake
    // leftMotor3.stop(hold);
    // leftMotor4.stop(hold);
    // rightMotor3.stop(hold);
    // rightMotor4.stop(hold);
    // // back up
    // Drive.moveDistance(-2, 100, 0.1, false);
    // // turn to the goal
    // Drive.turn(200, 100, 1);
    // // move towards goal to score triball
    // Drive.moveDistance(100, 100, 1.75, false);
    // Drive.moveDistance(-15, 100, 1, false);


    // turn towards bar
    Drive.turn(130, 100, 2);
    // drive to bar
    Drive.moveDistance(60, 100, 2, true);
    // turn into bar
    Drive.turn(180, 100, 2);
}
autonRoute qualificationOffensive = {"Q - Offensive", 0, 0, 0, qualificationOffensiveRoute};

void qualificationOffensiveRiskyRoute()
{
    // back up
    Drive.moveDistance(-10, 100, 2, true);
    // push matchload out
    Drive.moveDistance(10, 100, 2, true);
    // back up
    Drive.moveDistance(-20, 100, 1.5, true);
    // turn back towards goal
    Drive.turn(45, 100, 2);
    // push preload into goal
    Drive.moveDistance(-12, 100, 2, true);
    // drive away from goal
    Drive.moveDistance(10, 100, 2, true);
    // point front towards long barrier
    Drive.turn(-45, 100, 2);
    // drive towards long barrier
    Drive.moveDistance(36, 100, 2, true);
    // point front towards triball barrier
    Drive.turn(-101.3, 100, 2);
    // pto to catapult

    wait(3000, msec);
    // start intake


    // move towards triball
    Drive.moveDistance(43.25, 100, 2, false);
    // stop the intake

    // switch pto back to drive

    wait(3000, msec);
    // back up
    Drive.moveDistance(-10, 100, 2, true);
    // turn towards goal
    Drive.turn(-225, 100, 2);
    // lift intake
    // push both triballs in
    Drive.moveDistance(40, 100, 2, true);
    // back up
    Drive.moveDistance(-10, 100, 2, true);
    // turn towards hang bar
    Drive.turn(0, 100, 2);
    // drive to hang bar
    Drive.moveDistance(34, 100, 2, true);
    // push blocker into hang bar
    Drive.turn(-20, 100, 2);
}
autonRoute qualificationOffensiveRisky = {"RISKY Q - Offensive", 0, 0, 0, qualificationOffensiveRiskyRoute};

void qualificationDefensiveRoute()
{
    // lower intake
    // back up
    Drive.moveDistance(-10, 100, 2, true);
    // push matchload out
    Drive.moveDistance(10, 100, 2, true);
    // back up
    Drive.moveDistance(-20, 100, 1.5, true);
    // turn back towards goal
    Drive.turn(45, 100, 1);
    // push preload into goal
    Drive.moveDistance(-6, 100, 1, true);
    // drive away from goal
    Drive.moveDistance(8, 100, 1, true);
    // point backend towards long barrier
    Drive.turn(125, 100, 1);
    // drive towards long barrier
    Drive.moveDistance(-52, 100, 2, true);
    // push blocker into goal
    Drive.turn(180, 100, 1);
    wait(500, msec);
    Drive.moveDistance(-4, 100, 1, true);
    Drive.turn(173, 100, 1);
}
autonRoute qualificationDefensive = {"Q - Defensive", 0, 0, 0, qualificationDefensiveRoute};

void qualificationDefensiveRiskyRoute()
{
    qualificationDefensiveRoute();
}
autonRoute qualificationDefensiveRisky = {"RISKY Q - Defensive", 0, 0, 0, qualificationDefensiveRiskyRoute};

void eliminationOffensiveRoute()
{
    // pto to catapult
    // start intake


    // drive forward
    Drive.moveDistance(20, 100, 1.3, false);
    // stop intake


    // drive backward
    Drive.moveDistance(-23, 100, 2.5, true);
    //Turn
    Drive.turn(135, 100, 0);
    // Knock out match load
    Drive.moveDistance(16, 100, 2.5, true);
    Drive.turn(110, 100, 0);
    Drive.moveDistance(18, 100, 2, true);
    Drive.moveDistance(-10, 100, 2, true);
    Drive.moveDistance(16, 100, 2, true);
    Drive.moveDistance(-10, 100, 2, true);
    Drive.turn(180, 100, 1);
    Drive.moveDistance(-40, 4, true);
}
autonRoute eliminationOffensive = {"E - Offensive", 0, 0, 0, eliminationOffensiveRoute};

void eliminationOffensiveRiskyRoute()
{
    int startTime = vex::timer::system();
    // set intial rotation and hits the allience triball with the wings
    Drive.turn(0, 100, 0.45);
    // drive towards uncontested triball
    Drive.moveDistance(30, 100, 0.85, true);
    Drive.turn(-20, 100, 0.35);
    Drive.moveDistance(25, 100, 0.70, true);
    // turn to goal
    Drive.turn(105, 100, 1);
    wait(150, msec);
    // push uncontested and contested triball into goal
    Drive.moveDistance(40, 100, 1, true);
    // back up
    Drive.moveDistance(-10, 100, 0.25, true);
    // turn to other contested triabll
    Drive.turn(-30, 100, 0.9);
    // drive into contested triball
    Drive.moveDistance(20, 100, 0.8, true);
    // turn to goal
    Drive.turn(-210, 100, 1.15);
    // push last contested triball into goal
    Drive.moveDistance(30, 100, 1, true);
    // back up
    Drive.moveDistance(-10, 100, 0.25, true);
    // turn to right wall
    Drive.turn(-315, 100, 1);
    // drive backwards towards left wall
    Drive.moveDistance(-80, 100, 1.25, true);
    // turn to match load triball
    Drive.turn(-265, 100, 1);
    // push out match load triball
    Drive.moveDistance(20, 100, 0.75, true);
    // turn towards goal
    Drive.turn(-310, 100, 0.75);
    // push triballs into goal
    Drive.moveDistance(20, 100, 0.82, true);
    // backup
    Drive.moveDistance(-5, 100, 0.25, true);
    int currenttime = vex::timer::system();
    printf("%i\n", currenttime - startTime);
}
autonRoute eliminationOffensiveRisky = {"RISKY E - Offensive", 0, 0, 0, eliminationOffensiveRiskyRoute};

void eliminationDefensiveRoute()
{
    qualificationDefensiveRoute();
}
autonRoute eliminationDefensive = {"E - Defensive", 0, 0, 0, eliminationDefensiveRoute};

void eliminationDefensiveRiskyRoute()
{
    qualificationDefensiveRiskyRoute();
}
autonRoute eliminationDefensiveRisky = {"RISKY E - Defensive", 0, 0, 0, eliminationDefensiveRiskyRoute};

