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
    Drive.turn(-43, 100, 1);
    dropDown1.close();
    dropDown2.close();
    wait(3, sec);
    Drive.moveDistance(41.5, 100, 1.3, true);
    // intakeLift.open();
    intake_Group.spin(reverse, 12000, vex::voltageUnits::mV);
}
autonRoute nearSideAWP = {"NS AWP SAFE", 0, 0, 0, nearSideAWPRoute};

void nearSideRoute()
{
    Drive.moveDistance(-5,100,.3);
    dropDown1.open();
    Drive.moveDistance(5,100,.3);
    Drive.turn(-40, 100, .6);
    dropDown1.close();
    wait(.1,sec);
    Drive.turn(-118,100,.6);
    // intakeLift.open();
    intake_Group.spin(fwd,100,pct);
    Drive.moveDistance(50,80,1.33);
    Drive.turn(-40,100,.7);
    // intakeLift.close();
    intake_Group.spin(fwd,-100,pct);
    leftWing.open();
    Drive.moveDistance(23,100,1);
    Drive.moveDistance(-10,100,.7);
    leftWing.close();
    Drive.turn(-100,100,1);
    Drive.moveDistance(-50,100,1.7);
    Drive.turn(-15,100,.6);
    Drive.moveDistance(-15,100,.6);
    Drive.turn(45,100,.8);
    dropDown1.open();
    Drive.moveDistance(-11,100,.4);
    dropDown1.close();
    Drive.moveDistance(7,100,.5);
    Drive.turn(-5,100,.7);
    Drive.moveDistance(30,100,1);
    Drive.turn(-40,100,.6);
    Drive.moveDistance(22,100,1);
    // intakeLift.open();
}
autonRoute nearSide = {"NS Elims", 0, 0, 0, nearSideRoute};

void farSideAWPRoute()
{
   Drive.moveDistance(7,100,.8);
   dropDown1.open();
   dropDown2.open();
   Drive.moveDistance(13,100,.8);
   Drive.turn(-45,100,1);
   dropDown1.close();
   dropDown2.close();
   wait(3,sec);
   leftWing.open();
   rightWing.open();
   wait(.5,sec);
   Drive.moveDistance(1000,100,1);
   Drive.moveDistance(-5,100,1);
   leftWing.close();
   rightWing.close();
   wait(1,sec);
   Drive.turn(-200,100,1);
   Drive.moveDistance(23,100,1.2);
   Drive.turn(-140,100,1.2);
   Drive.moveDistance(37,100,1.5);
   intake_Group.spin(fwd, -12000, vex::voltageUnits::mV);
}
autonRoute farSideAWP = {"FS AWP SAFE", 0, 0, 0, farSideAWPRoute};

void farSideRoute()
{
   intake_Group.spin(fwd,100,pct);
//    intakeLift.open();
   wait(.4,sec);
   Drive.moveDistance(-34,100,1);
   Drive.turn(-35,100,.5);
   dropDown1.open();
   Drive.moveDistance(-17,100,.7);
   dropDown1.close();
   Drive.turn(-45, 100, 0.6);
   wait(.4,sec);
   Drive.turn(97,100,.9);
   leftWing.open();
//    intakeLift.close();
   intake_Group.spin(fwd,-100,pct);
   wait(.3,sec);
   Drive.moveDistance(1000,100,.7);
   Drive.moveDistance(-10,100,.7);
//    intakeLift.open();
   intake_Group.spin(fwd,100,pct);
   leftWing.close();
   wait(.3,sec);
   Drive.turn(17,100,.6);
   Drive.moveDistance(46,100,1.4);
   Drive.turn(100,100,.7);
   Drive.moveDistance(14,100,.6);
   Drive.turn(180,100,.7);
   intake_Group.spin(fwd,-100,pct);
   leftWing.open();
//    intakeLift.close();
   intake_Group.spin(fwd,-100,pct);
   Drive.moveDistance(1000,100,.8);
   leftWing.close();
//    intakeLift.open();
   Drive.turn(19,100,1.2 );
   intake_Group.spin(fwd,100,pct);
   Drive.moveDistance(20,100,.9);
   leftWing.open();
   Drive.turn(180,100,.8);
//    intakeLift.close();
   Drive.moveDistance(100000,100,1);
}

autonRoute farSide = {"FS Elims", 0, 0, 0, farSideRoute};

void driverSkillsRoute()
{
    Drive.moveDistance(-20, 100, 0.6, true);
    Drive.turn(45, 100, 0.5);
    Drive.moveDistance(-1000, 100, 0.4, true);
    Drive.moveDistance(10, 100, 0.4, true);
    Drive.turn(-50, 100, 0.5);
    Drive.moveDistance(-1000, 100, 0.3, true);
    Drive.turn(-65, 100, 0.5);
    dropDown1.open();
    wait(100, msec);
}
autonRoute driverSkills = {"Driver Skills", 0, 0, 0, driverSkillsRoute};


void autonSkillsRoute()
{
    int startTime = vex::timer::system();
    driverSkillsRoute();
    while (vex::timer::system() - startTime <= 35000)
    {
        shooter_Group.spin(fwd, 7000, vex::voltageUnits::mV);
    }
    shooter_Group.stop(coast);
    dropDown1.close();
    wait(200, msec);
    Drive.turn(0, 100, 0.45);
    Drive.moveDistance(25, 100, 0.85, true);
    Drive.turn(-45, 100, 0.45);
    Drive.moveDistance(90, 100, 2.5, true);
    Drive.turn(-90, 100, 0.45);
    Drive.moveDistance(1000, 100, 1, false);
    Drive.moveDistance(-10, 100, 0.5, false);
    Drive.turn(-120, 100, 0.3);
    Drive.moveDistance(1000, 100, 0.75, true);
    Drive.moveDistance(-20, 100, 0.7, true);
    Drive.turn(-185, 100, 0.9);
    Drive.moveDistance(45, 100, 1, true);
    Drive.turn(-235, 100, 0.8);
    dropDown1.open();
    Drive.moveDistance(-1000, 100, 1, true);
    dropDown1.close();
    Drive.moveDistance(20, 100, 1, true);
    Drive.turn(-165, 100, 0.5);
    Drive.moveDistance(15, 100, 0.6, true);
    Drive.turn(-235, 100, 0.5);
    dropDown1.open();
    Drive.moveDistance(-1000, 100, 1, true);
    Drive.moveDistance(10, 100, 0.2, true);
    dropDown1.close();
}
autonRoute autonSkills = {"Skills", 0, 0, 0, autonSkillsRoute};