#include "vex.h"
using namespace vex;

void doNothingRoute()
{
    // do nothing
}
autonRoute doNothing = {"Do Nothing", 0, 0, 0, doNothingRoute};

void forwardsBackwardsRoute()
{
    Drive.moveDistance(25, 100, 1, true);
    Drive.moveDistance(-25, 100, 1, true);
}
autonRoute forwardsBackwards = {"Forwards Backwards", 0, 0, 0, forwardsBackwardsRoute};

void backwardsForwardsRoute()
{
    Drive.moveDistance(-25, 100, 1, true);
    Drive.moveDistance(25, 100, 1, true);
}
autonRoute backwardsForwards = {"Backwards Forwards", 0, 0, 0, backwardsForwardsRoute};

void nearSideAWPRoute()
{
    dropDown1.open();
    dropDown2.open();
    wait(0.5, sec);
    Drive.turn(-45, 100, 1);
    dropDown1.close();
    dropDown2.close();
    Drive.turn(-43, 100, 1);
    wait(3, sec);
    Drive.moveDistance(41.5, 100, 1.3, true);
    intake_Group.spin(reverse, 12000, vex::voltageUnits::mV);
}
autonRoute nearSideAWP = {"NS AWP SAFE", 0, 0, 0, nearSideAWPRoute};

void nearSideRoute()
{
    Drive.moveDistance(-5, 100, .3);
    dropDown1.open();
    Drive.moveDistance(5, 100, .3);
    Drive.turn(-40, 100, .6);
    dropDown1.close();
    wait(.1, sec);
    Drive.turn(-118, 100, .6);
    // intakeLift.open();
    intake_Group.spin(fwd, 100, pct);
    Drive.moveDistance(50, 80, 1.33);
    Drive.turn(-40, 100, .7);
    // intakeLift.close();
    intake_Group.spin(fwd, -100, pct);
    leftWing.open();
    Drive.moveDistance(23, 100, 1);
    Drive.moveDistance(-10, 100, .7);
    leftWing.close();
    Drive.turn(-100, 100, 1);
    Drive.moveDistance(-50, 100, 1.7);
    Drive.turn(-15, 100, .6);
    Drive.moveDistance(-15, 100, .6);
    Drive.turn(45, 100, .8);
    dropDown1.open();
    Drive.moveDistance(-11, 100, .4);
    dropDown1.close();
    Drive.moveDistance(7, 100, .5);
    Drive.turn(-5, 100, .7);
    Drive.moveDistance(30, 100, 1);
    Drive.turn(-40, 100, .6);
    Drive.moveDistance(22, 100, 1);
    // intakeLift.open();
}
autonRoute nearSide = {"NS Elims", 0, 0, 0, nearSideRoute};

void farSideAWPRoute()
{
    Drive.moveDistance(7, 100, .8);
    dropDown1.open();
    dropDown2.open();
    Drive.moveDistance(13, 100, .8);
    Drive.turn(-45, 100, 1);
    dropDown1.close();
    dropDown2.close();
    wait(3, sec);
    leftWing.open();
    rightWing.open();
    wait(.5, sec);
    Drive.moveDistance(1000, 100, 1);
    Drive.moveDistance(-5, 100, 1);
    leftWing.close();
    rightWing.close();
    wait(1, sec);
    Drive.turn(-200, 100, 1);
    Drive.moveDistance(23, 100, 1.2);
    Drive.turn(-140, 100, 1.2);
    Drive.moveDistance(37, 100, 1.5);
    intake_Group.spin(fwd, -12000, vex::voltageUnits::mV);
}
autonRoute farSideAWP = {"FS AWP SAFE", 0, 0, 0, farSideAWPRoute};

void farSideRoute()
{
    intake_Group.spin(fwd, 100, pct);
    wait(.4, sec);
    Drive.moveDistance(-34, 100, 1);
    Drive.turn(-35, 100, .5);
    //    dropDown1.open();
    Drive.moveDistance(-17, 100, .7);
    //    dropDown1.close();
    Drive.turn(-45, 100, 0.6);
    wait(.4, sec);
    Drive.turn(97, 100, .9);
    leftWing.open();

    intake_Group.spin(fwd, -100, pct);
    wait(.3, sec);
    Drive.moveDistance(1000, 100, .7);
    Drive.moveDistance(-10, 100, .7);

    intake_Group.spin(fwd, 100, pct);
    leftWing.close();
    wait(.3, sec);
    Drive.turn(17, 100, .6);
    Drive.moveDistance(46, 100, 1.4);
    Drive.turn(100, 100, .7);
    Drive.moveDistance(14, 100, .6);
    Drive.turn(180, 100, .7);
    intake_Group.spin(fwd, -100, pct);
    leftWing.open();

    intake_Group.spin(fwd, -100, pct);
    Drive.moveDistance(1000, 100, .8);
    leftWing.close();

    Drive.turn(19, 100, 1.2);
    intake_Group.spin(fwd, 100, pct);
    Drive.moveDistance(20, 100, .9);
    leftWing.open();
    Drive.turn(180, 100, .8);

    Drive.moveDistance(100000, 100, 1);
}
autonRoute farSide = {"FS Elims", 0, 0, 0, farSideRoute};

void sixBallMidRushRoute()
{
    intake_Group.spin(fwd, 100, pct);
    Drive.moveDistance(4, 100, 0.4);
    Drive.moveDistance(-35, 90, 1.2);
    Drive.turn(150, 100, 1.2);
    intake_Group.spin(fwd, -100, pct);
    Drive.moveDistance(16, 100, 0.6);
    dropDown1.open();
    dropDown2.open();
    Drive.moveDistance(12, 100, 0.6);

    Drive.turn(97, 100, 0.2);
    dropDown1.close();
    dropDown2.close();
    Drive.turn(97, 100, 0.4);
    Drive.turn(105, 100, 0.4);
    leftWing.open();
    rightWing.open();

    Drive.moveDistance(1000, 100, 0.5);
    Drive.moveDistance(-23, 100, 0.6);

    rightWing.close();
    leftWing.close();
    Drive.turn(27, 100, 0.6);
    intake_Group.spin(fwd, 100, pct);
    Drive.swing(55, 100, 5, 1.25);
    Drive.turn(100, 100, 0.7);
    Drive.moveDistance(15, 100, 0.6);
    Drive.turn(180, 100, 0.6);
    intake_Group.spin(fwd, -100, pct);

    leftWing.open();
    Drive.moveDistance(1000, 100, 0.8);
    leftWing.close();

    Drive.turn(15, 100, 1.2);
    intake_Group.spin(fwd, 100, pct);
    Drive.moveDistance(30, 100, 0.9);
    leftWing.open();
    Drive.turn(180, 100, 1.1);
    rightWing.open();
    intake_Group.spin(fwd, -100, pct);

    Drive.moveDistance(100000, 100, 0.7);

}
autonRoute sixBallMidRush = {"Six Ball Mid Rush", 0, 0, 0, sixBallMidRushRoute};

void SkillsSetupRoute()
{
    int startTime = vex::timer::system();
    Drive.turn(10, 100, 0.3);
    Drive.moveDistance(-24, 100, 0.6);
    Drive.turn(47, 100, 0.5);
    Drive.moveDistance(-1000, 100, 0.5);
    Drive.turn(45, 100, 0.6);
    Drive.moveDistance(10, 100, 0.45);
    Drive.turn(-60, 100, 0.5);
    Drive.moveDistance(-7, 100, 0.3);
    Drive.turn(-62, 100, 0.4);
    dropDown1.open();
    dropDown2.open();
    printf("%lu   ", vex::timer::system() - startTime);
}

void autonSkillsRoute()
{
    // run the inital setup route for skills
    SkillsSetupRoute(); // 4.45 seconds
    // shoot for 28 seconds
    int startTime = vex::timer::system();
    while (vex::timer::system() - startTime <= 22500)
    {
        shooter_Group.spin(fwd, 10000, vex::voltageUnits::mV);
    }
    shooter_Group.stop(coast);
    dropDown1.close();
    dropDown2.close();
    // spin intake to prevent double possesion
    intake_Group.spin(fwd, -12000, vex::voltageUnits::mV);
    // drive towards long barrier
    Drive.moveDistance(55, 100, 1);
    // turn parrell to long barrier to push triballs
    Drive.turn(-125, 100, 0.75);
    // open wings and run down the long barrier to push all the triballs across and into the alley way
    leftWing.open();
    rightWing.open();
    Drive.moveDistance(67, 100, 1.65);
    leftWing.close();
    rightWing.close();
    // ensure the robot has not gotten turned incedentally
    Drive.turn(-130, 100, 0.1);
    // back off of the short barrier
    Drive.moveDistance(-10, 100, 0.6);
    // sequence to get around the short barrier
    Drive.turn(-185, 100, 0.6);
    Drive.moveDistance(20, 100, 0.5);
    Drive.swing(40, 100, -51, 1.0);
    // run down left alley way
    Drive.turn(-55, 100, 0.2);
    rightWing.open();
    Drive.moveDistance(70, 100, 1.7);
    Drive.turn(-35, 100, 0.4);
    // push tribals into the corner
    Drive.swing(42, 100, 46, 1);
    // push left side of goal
    Drive.moveDistance(1000, 100, 0.5);
    Drive.moveDistance(-8, 100, 0.5);
    rightWing.close();
    Drive.turn(36, 100, 0.2);
    // move around to the front side of the goal
    Drive.turn(132, 100, 0.9);
    Drive.swing(45, 100, 100, 1);
    Drive.turn(-15, 100, 0.95);
    leftWing.open();
    // first push into the front of the goal
    Drive.swing(40, 85, -60, 1);
    Drive.moveDistance(1000, 100, 0.4);
    Drive.turn(-30, 100, 0.15);
    leftWing.close();
    Drive.swing(-30, 100, 0, 0.9);
    // turn to move further right for the second push
    Drive.turn(51, 100, 0.7);
    Drive.moveDistance(10, 100, 0.85);
    // face the front of the goal agian
    Drive.turn(-60, 100, 0.7);
    // second push into the front of the goal
    leftWing.open();
    Drive.swing(60, 100, -5, 1);
    Drive.moveDistance(1000, 100, 0.25);
    Drive.turn(-55, 100, 0.45);
    leftWing.close();
    Drive.moveDistance(-38, 100, 0.9);
    // third push
    Drive.turn(48, 100, 0.65);
    Drive.moveDistance(20, 100, 0.8);
    Drive.turn(-72, 100, 0.95);
    rightWing.open();
    leftWing.open();
    Drive.swing(50, 100, -15, 1);
    Drive.moveDistance(1000, 100, 0.3);
    Drive.moveDistance(-15, 100, 0.3);
    Drive.moveDistance(1000, 100, 0.6);
    Drive.turn(-55, 100, 0.45);
    leftWing.close();
    rightWing.close();
    Drive.moveDistance(-15, 100, 0.9);
    // push right side
    Drive.turn(30, 100, 0.85);
    Drive.moveDistance(40, 100, 0.7);
    Drive.turn(-60, 100, 0.75);
    leftWing.open();
    Drive.swing(25, 100, -134, 1.5);
    Drive.moveDistance(1000, 100, 0.6);
    Drive.moveDistance(-1000, 100, 0.1);
    leftWing.close();
    printf("%lu\n", vex::timer::system() - startTime);
}

void driverSkillsRoute()
{
    SkillsSetupRoute();
}

autonRoute driverSkills = {"Driver Skills", 0, 0, 0, autonSkillsRoute};
autonRoute autonSkills = {"Skills", 0, 0, 0, autonSkillsRoute};