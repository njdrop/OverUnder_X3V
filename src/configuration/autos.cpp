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
    Drive.turn(-40, 100, 1.2);
    Drive.turn(-35, 100, 1.2);
    backWings.close();
    wait(6, sec);
    intakeLift.open();
    Drive.moveDistance(35, 100, 1.8);
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
    frontLeftWing.open();
    frontRightWing.open();
    Drive.moveDistance(23, 100, 1);
    Drive.moveDistance(-10, 100, .7);
    frontLeftWing.close();
    frontRightWing.close();
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
    int starttime = vex::timer::system();
    Drive.moveDistance(7, 50, 1);
    backWings.open();
    Drive.moveDistance(13, 50, 1);
    Drive.turn(-45, 100, 1);
    backWings.close();
    wait(0.5, sec);
    Drive.turn(-30, 100, 1);
    frontRightWing.open();
    wait(0.5, sec);
    Drive.moveDistance(1000, 100, 1, false);
    Drive.turn(-30, 100, 0.5);
    Drive.moveDistance(-6, 100, 0.8);
    frontRightWing.close();
    wait(1, sec);
    Drive.turn(-200, 100, 1);
    Drive.moveDistance(24, 100, 1.2);
    Drive.turn(-135, 100, 1.2);
    intakeLift.open();
    intake_Group.spin(reverse, 12000, vex::voltageUnits::mV);
    Drive.moveDistance(33, 100, 1.5);
    printf("%lu\n", vex::timer::system() - starttime);
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
    frontLeftWing.open();
    frontRightWing.open();
    intakeLift.close();
    intake_Group.spin(fwd, -100, pct);
    wait(.3, sec);
    Drive.moveDistance(1000, 100, .7);
    Drive.moveDistance(-10, 100, .7);
    intakeLift.open();
    intake_Group.spin(fwd, 100, pct);
    frontLeftWing.close();
    frontRightWing.close();
    wait(.3, sec);
    Drive.turn(17, 100, .6);
    Drive.moveDistance(46, 100, 1.4);
    Drive.turn(100, 100, .7);
    Drive.moveDistance(14, 100, .6);
    Drive.turn(180, 100, .7);
    intake_Group.spin(fwd, -100, pct);
    frontLeftWing.open();
    frontRightWing.open();
    intakeLift.close();
    intake_Group.spin(fwd, -100, pct);
    Drive.moveDistance(1000, 100, .8);
    frontLeftWing.close();
    frontRightWing.close();
    intakeLift.open();
    Drive.turn(19, 100, 1.2);
    intake_Group.spin(fwd, 100, pct);
    Drive.moveDistance(20, 100, .9);
    frontLeftWing.open();
    frontRightWing.open();
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
    Drive.moveDistance(-100, 100, 0.25);
    Drive.turn(45, 100, 0.6);
    Drive.moveDistance(11, 100, 0.45);
    Drive.turn(-60, 100, 0.5);
    Drive.moveDistance(-50, 100, 0.3);
    Drive.turn(-67 , 100, 0.6);
    backWings.open();
    printf("%lu   ", vex::timer::system() - startTime);
}

void Skills2Route()
{
    // run the inital setup route for skills
    SkillsSetupRoute(); // 4.45 seconds
    // shoot for 28 seconds
    int startTime = vex::timer::system();
    while (vex::timer::system() - startTime <= 25250) //25500
    {
        shooter_Group.spin(fwd, 8700, vex::voltageUnits::mV);
    }

    shooter_Group.stop(coast);
    backWings.close();
    // drive towards long barrier
    Drive.moveDistance(55, 100, 1);
    // turn parrell to long barrier to push triballs
    Drive.turn(-133, 100, 0.7);
    // open wings and run down the long barrier to push all the triballs across and into the alley way
    frontLeftWing.open();
    frontRightWing.open();
    Drive.moveDistance(67, 100, 1.65);
    frontLeftWing.close();
    frontRightWing.close();
    // ensure the robot has not gotten turned incedentally
    Drive.turn(-134, 100, 0.1);
    // back off of the short barrier
    Drive.moveDistance(-10, 100, 0.6);
    // sequence to get around the short barrier
    Drive.turn(-185, 100, 0.6);
    Drive.moveDistance(16, 100, 0.5);
    Drive.swing(18, 100, -51, 1.2);
    // run down left alley way
    Drive.turn(-55, 100, 0.3);
    Drive.moveDistance(70, 100, 1.7);
    frontRightWing.open();
    Drive.turn(-35, 100, 0.4);
            // push tribals into the corner
            Drive.swing(26, 100, 46, 1); // 30
            // push left side of goal
            Drive.moveDistance(1000, 100, 0.5);
            Drive.moveDistance(-1000, 100, 0.3);
            Drive.moveDistance(1000, 100, 0.5);
            Drive.moveDistance(-8, 100, 0.5);
            frontRightWing.close();
            Drive.turn(36, 100, 0.5);
            // move around to the front side of the goal
            Drive.turn(132, 100, 0.9);
            Drive.moveDistance(42, 100, 1);
            Drive.turn(100, 100, 0.45);
            frontRightWing.open();
            Drive.turn(51, 100, 0.65);
            Drive.moveDistance(24, 100, 0.9);
            frontRightWing.close();
            // face the front of the goal
            Drive.turn(144, 100, 0.7);
                    // first push into the front of the goal
                    backWings.open();
                    wait(100, msec);
                    Drive.moveDistance(-1000, 100, 0.75);
                    Drive.turn(144, 100, 0.25);
                    backWings.close();
                    Drive.moveDistance(30, 100, 0.9);
                    // turn to move further right for the second push
                    Drive.turn(51, 100, 0.7);
                    // frontRightWing.open();
                    Drive.moveDistance(27, 100, 0.85);
                    // frontRightWing.close();
                    // face the front of the goal agian
                    Drive.turn(125, 100, 0.7);
                    // second push into the front of the goal
                    backWings.open();
                    wait(100, msec);
                    Drive.swing(-50, 100, 165, 0.95);
                    Drive.turn(125, 100, 0.45);
                    backWings.close();
                    Drive.moveDistance(23, 100, 0.9);
                                // push right side
                                Drive.turn(48, 100, 0.65);
                                frontRightWing.open();
                                Drive.moveDistance(25, 100, 0.8);
                                Drive.turn(-39, 100, 0.75);
                                Drive.moveDistance(15, 100, 0.65);
                                frontRightWing.close();
                                Drive.turn(0, 100, 0.55);
                                Drive.moveDistance(25, 100, 0.8);
                                Drive.turn(-87, 100, 0.8);
                                frontLeftWing.open();
                                Drive.swing(24, 100, -132, 1);
                                Drive.moveDistance(1000, 100, 0.6);
                                Drive.moveDistance(-1000, 100, 0.1);
    printf("%lu\n", vex::timer::system() - startTime);
}

void driverSkillsRoute() 
{
    // run the inital setup route for skills
    SkillsSetupRoute(); // 4.45 seconds
    // shoot for 28 seconds
    int startTime = vex::timer::system();
    while (vex::timer::system() - startTime <= 25500) //25500
    {
        shooter_Group.spin(fwd, 8800, vex::voltageUnits::mV);
    }

    shooter_Group.stop(coast);
    backWings.close();
    // drive towards long barrier
    Drive.moveDistance(55, 100, 1);
    // turn parrell to long barrier to push triballs
    Drive.turn(-133, 100, 0.7);
    // open wings and run down the long barrier to push all the triballs across and into the alley way
    frontLeftWing.open();
    frontRightWing.open();
    Drive.moveDistance(67, 100, 1.65);
    frontLeftWing.close();
    frontRightWing.close();
    // ensure the robot has not gotten turned incedentally
    Drive.turn(-134, 100, 0.1);
    // back off of the short barrier
    Drive.moveDistance(-10, 100, 0.6);
    // sequence to get around the short barrier
    Drive.turn(-185, 100, 0.6);
    Drive.moveDistance(16, 100, 0.5);
    Drive.swing(18, 100, -51, 1.2);
    // run down left alley way
    Drive.turn(-55, 100, 0.3);
    Drive.moveDistance(70, 100, 1.7);
    frontRightWing.open();
    Drive.turn(-35, 100, 0.4);
            // push tribals into the corner
            Drive.swing(26, 100, 46, 1); // 30
            // push left side of goal
            Drive.moveDistance(1000, 100, 0.5);
}

autonRoute driverSkills = {"Driver Skills", 0, 0, 0, driverSkillsRoute};
autonRoute autonSkills = {"Skills", 0, 0, 0, Skills2Route};