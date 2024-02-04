#include "vex.h"
using namespace vex;

void doNothingRoute()
{
    // do nothing
}
autonRoute doNothing = {"Do Nothing", 0, 0, 0, doNothingRoute};

void forwardsBackwardsRoute()
{
    Drive.moveDistance(25, 100, 1);
    Drive.moveDistance(-25, 100, 1);
}
autonRoute forwardsBackwards = {"Forwards Backwards", 0, 0, 0, forwardsBackwardsRoute};

void backwardsForwardsRoute()
{
    Drive.moveDistance(-25, 100, 1);
    Drive.moveDistance(25, 100, 1);
}
autonRoute backwardsForwards = {"Backwards Forwards", 0, 0, 0, backwardsForwardsRoute};

void nearSideAWPRoute()
{
    backWings.open();
    Drive.turn(-45, 100, 1);
    Drive.turn(-35, 100, 1);
    backWings.close();
    wait(6, sec);
    Drive.moveDistance(33, 100, 1.3);
    intakeLift.open();
    intake_Group.spin(reverse, 12000, vex::voltageUnits::mV);
}
autonRoute nearSideAWP = {"NS AWP SAFE", 0, 0, 0, nearSideAWPRoute};

void nearSideRoute()
{
    Drive.moveDistance(-5, 100, .3);
    backWings.open();
    Drive.moveDistance(5, 100, .3);
    Drive.turn(-40, 100, .6);
    backWings.close();
    wait(.1, sec);
    Drive.turn(-118, 100, .6);
    intakeLift.open();
    intake_Group.spin(fwd, 100, pct);
    Drive.moveDistance(50, 80, 1.33);
    Drive.turn(-40, 100, .7);
    intakeLift.close();
    intake_Group.spin(fwd, -100, pct);
    frontWings.open();
    Drive.moveDistance(23, 100, 1);
    Drive.moveDistance(-10, 100, .7);
    frontWings.close();
    Drive.turn(-100, 100, 1);
    Drive.moveDistance(-50, 100, 1.7);
    Drive.turn(-15, 100, .6);
    Drive.moveDistance(-15, 100, .6);
    Drive.turn(45, 100, .8);
    backWings.open();
    Drive.moveDistance(-11, 100, .4);
    backWings.close();
    Drive.moveDistance(7, 100, .5);
    Drive.turn(-5, 100, .7);
    Drive.moveDistance(30, 100, 1);
    Drive.turn(-40, 100, .6);
    Drive.moveDistance(22, 100, 1);
    intakeLift.open();
}
autonRoute nearSide = {"NS Elims", 0, 0, 0, nearSideRoute};

void farSideAWPRoute()
{
    Drive.moveDistance(7, 100, .8);
    backWings.open();
    Drive.moveDistance(13, 100, .8);
    Drive.turn(-45, 100, 1);
    backWings.close();
    wait(3, sec);
    frontWings.open();
    wait(.5, sec);
    Drive.moveDistance(1000, 100, 1);
    Drive.moveDistance(-5, 100, 1);
    frontWings.close();
    wait(1, sec);
    Drive.turn(-200, 100, 1);
    Drive.moveDistance(23, 100, 1.2);
    Drive.turn(-140, 100, 1.2);
    Drive.moveDistance(33, 100, 1.5);
    intakeLift.open();
}
autonRoute farSideAWP = {"FS AWP SAFE", 0, 0, 0, farSideAWPRoute};

void farSideRoute()
{
    intake_Group.spin(fwd, 100, pct);
    intakeLift.open();
    wait(.4, sec);
    Drive.moveDistance(-34, 100, 1);
    Drive.turn(-35, 100, .5);
    backWings.open();
    Drive.moveDistance(-17, 100, .7);
    backWings.close();
    Drive.turn(-45, 100, 0.6);
    wait(.4, sec);
    Drive.turn(97, 100, .9);
    frontWings.open();
    intakeLift.close();
    intake_Group.spin(fwd, -100, pct);
    wait(.3, sec);
    Drive.moveDistance(1000, 100, .7);
    Drive.moveDistance(-10, 100, .7);
    intakeLift.open();
    intake_Group.spin(fwd, 100, pct);
    frontWings.close();
    wait(.3, sec);
    Drive.turn(17, 100, .6);
    Drive.moveDistance(46, 100, 1.4);
    Drive.turn(100, 100, .7);
    Drive.moveDistance(14, 100, .6);
    Drive.turn(180, 100, .7);
    intake_Group.spin(fwd, -100, pct);
    frontWings.open();
    intakeLift.close();
    intake_Group.spin(fwd, -100, pct);
    Drive.moveDistance(1000, 100, .8);
    frontWings.close();
    intakeLift.open();
    Drive.turn(19, 100, 1.2);
    intake_Group.spin(fwd, 100, pct);
    Drive.moveDistance(20, 100, .9);
    frontWings.open();
    Drive.turn(180, 100, .8);
    intakeLift.close();
    Drive.moveDistance(100000, 100, 1);
}
autonRoute farSide = {"FS Elims", 0, 0, 0, farSideRoute};

void SkillsSetupRoute()
{
    int startTime = vex::timer::system();
    Drive.turn(20, 100, 0.4);
    Drive.moveDistance(-24, 100, 0.6);
    Drive.turn(47, 100, 0.5);
    Drive.moveDistance(-50, 100, 0.6);
    Drive.turn(35, 100, 0.45);
    Drive.moveDistance(10, 100, 0.4);
    Drive.turn(-50, 100, 0.5);
    Drive.moveDistance(-50, 100, 0.3);
    Drive.turn(-61, 100, 0.6);
    backWings.open();
    wait(100, msec);
    printf("%lu   ", vex::timer::system() - startTime);
}

void autonSkillsRoute()
{
    int startTime = vex::timer::system();
    SkillsSetupRoute();
    while (vex::timer::system() - startTime <= 35000)
    {
        shooter_Group.spin(fwd, 7000, vex::voltageUnits::mV);
    }
    shooter_Group.stop(coast);
    backWings.close();
    wait(200, msec);
    Drive.turn(0, 100, 0.45);
    Drive.moveDistance(23, 100, 0.85);
    Drive.turn(-43, 100, 0.5);
    Drive.moveDistance(75, 100, 2.5);
    Drive.moveDistance(10, 50, 1);
    Drive.turn(-90, 100, 0.45);
    Drive.moveDistance(24, 100, 1, false);
    Drive.turn(-135, 100, 1);
    Drive.moveDistance(18, 100, 1);
    Drive.moveDistance(-10, 100, 0.5);
    Drive.moveDistance(18, 100, 1);
    Drive.moveDistance(-10, 100, 0.5);
    Drive.turn(-215, 100, .5);
    Drive.moveDistance(44, 100, 3);
    Drive.turn(-135, 100, .5);
    frontWings.open();
    Drive.turn(-110, 80, 1);
    Drive.moveDistance(14, 100, .5);
    Drive.turn(-45, 80, 1);
    Drive.moveDistance(30, 100, 2);
    Drive.moveDistance(-5, 100, .5);
    frontWings.close();
    Drive.turn(-90, 100, .5);
    Drive.moveDistance(-20, 100, 2);
    Drive.turn(-135, 100, 1);
    frontWings.open();
    Drive.moveDistance(24, 80, 3);
    Drive.turn(-45, 80, 1);
    Drive.moveDistance(24, 100, 2);
    printf("%lu\n", vex::timer::system());
}

void Skills2Route()
{
    // forwards (-44)
    // run the inital setup route for skills
    SkillsSetupRoute(); // 4.45 seconds
    // shoot for 28 seconds
    int startTime = vex::timer::system();
    while (vex::timer::system() - startTime <= 28000) //28000
    {
        shooter_Group.spin(fwd, 8000, vex::voltageUnits::mV);
    }

    shooter_Group.stop(coast);
    backWings.close();
    // drive towards long barrier
    Drive.moveDistance(55, 100, 1);
    // turn parrell to long barrier to push triballs
    Drive.turn(-134, 100, 0.66);
    // open wings and run down the long barrier to push all the triballs across and into the alley way
    frontWings.open();
    Drive.moveDistance(67, 100, 1.5);
    frontWings.close();
    // ensure the robot has not gotten turned incedentally
    Drive.turn(-134, 100, 0.1);
    // back off of the short barrier
    Drive.moveDistance(-10, 100, 0.6);
    // sequence to get around the short barrier
    Drive.turn(-185, 100, 0.504);
    Drive.moveDistance(40, 100, 1);
    Drive.turn(-89, 100, 0.7);
    Drive.moveDistance(8, 100, 0.6);
    Drive.turn(-50.5, 100, 0.45);
    // run down left alley way
    Drive.moveDistance(83, 100, 1.9);
    // turn into the corner of the goal
    Drive.turn(-1, 100, 0.6);
    // push tribals into the corner
    Drive.moveDistance(31, 100, 1);
    // turn to face the left side of the goal
    Drive.turn(46, 100, 0.5);
    // double push
    Drive.moveDistance(1000, 100, 0.6);
    Drive.moveDistance(-3, 100, 0.5);
    // move around to the front side of the goal
    Drive.turn(136, 100, 0.7);
    Drive.moveDistance(40, 100, 1);
    Drive.turn(51, 100, 0.7);
    Drive.moveDistance(20, 100, 0.9);
    // face the front of the goal
    Drive.turn(-44, 100, 0.7);
    // first push into the front of the goal
    frontWings.open();
    wait(100, msec);
    Drive.moveDistance(1000, 100, 0.9);
    frontWings.close();
    Drive.moveDistance(-30, 100, 0.9);
    // turn to move further right for the second push
    Drive.turn(51, 100, 0.8);
    Drive.moveDistance(22, 100, 0.85);
    // face the front of the goal agian
    Drive.turn(-59, 100, 0.65);
    // second push into the front of the goal
    frontWings.open();
    wait(100, msec);
    Drive.moveDistance(1000, 100, 0.8, false);
    frontWings.close();
    Drive.moveDistance(-30, 100, 0.9);
    // turn and move towards the right corner
    Drive.turn(6, 100, 0.7);
    Drive.moveDistance(60, 100, 1.2);
    // face the right side of the goal
    Drive.turn(-116, 100, 1);
    // double push into the right side of the goal
    Drive.moveDistance(1000, 100, 0.85);
    Drive.moveDistance(-100, 100, 0.1);
    printf("%lu\n", vex::timer::system() - startTime);

}


autonRoute driverSkills = {"Driver Skills", 0, 0, 0, SkillsSetupRoute};
autonRoute autonSkills = {"Skills", 0, 0, 0, Skills2Route};