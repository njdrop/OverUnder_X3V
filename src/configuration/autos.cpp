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
    backWings.open();
    Drive.turn(-45, 100, 1);
    Drive.turn(-35, 100, 1);
    backWings.close();
    wait(6, sec);
    Drive.moveDistance(40, 100, 1.3, true);
    intakeLift.open();
    intake_Group.spin(reverse, 12000, vex::voltageUnits::mV);
}
autonRoute nearSideAWP = {"NS AWP SAFE", 0, 0, 0, nearSideAWPRoute};

void nearSideRoute()
{
    double startTime = vex::timer::system();
    Drive.moveDistance(-5,100,.3);
    backWings.open();
    Drive.moveDistance(5,100,.3);
    Drive.turn(-40, 100, .6);
    backWings.close();
    wait(.1,sec);
    Drive.turn(-118,100,.6);
    intakeLift.open();
    intake_Group.spin(fwd,100,pct);
    Drive.moveDistance(50,80,1.33);
    Drive.turn(-40,100,.7);
    intakeLift.close();
    intake_Group.spin(fwd,-100,pct);
    frontWings.open();
    Drive.moveDistance(23,100,1);
    Drive.moveDistance(-10,100,.7);
    frontWings.close();
    Drive.turn(-100,100,1);
    Drive.moveDistance(-50,100,1.7);
    Drive.turn(-15,100,.6);
    Drive.moveDistance(-15,100,.6);
    Drive.turn(45,100,.8);
    backWings.open();
    Drive.moveDistance(-11,100,.4);
    backWings.close();
    Drive.moveDistance(7,100,.5);
    Drive.turn(-5,100,.7);
    Drive.moveDistance(30,100,1);
    Drive.turn(-40,100,.6);
    Drive.moveDistance(25,100,1);
    intakeLift.open();
    printf("%f\n", vex::timer::system()- startTime);
}
autonRoute nearSide = {"NS Elims", 0, 0, 0, nearSideRoute};

void skills1Route()
{
    backWings.open();
    while (true)
    {
        shooter_Group.spin(fwd, 7000, vex::voltageUnits::mV);
    }
}
autonRoute skills1 = {"Skills", 0, 0, 0, skills1Route};
