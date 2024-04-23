#include "vex.h"
using namespace vex;

// final
void doNothingRoute()
{
    // do nothing
}
autonRoute doNothing = {"Do Nothing", 0, 0, 0, doNothingRoute};

// final
void forwardsBackwardsRoute()
{
    // drive forwards 25 inches
    Drive.moveDistance(25, 100, 1, true);
    // drive backwards 25 inches
    Drive.moveDistance(-25, 100, 1, true);
}
autonRoute forwardsBackwards = {"Forwards Backwards", 0, 0, 0, forwardsBackwardsRoute};

// final
void backwardsForwardsRoute()
{
    // same thing as forwardsBackwardsRoute() but in reverse
    Drive.moveDistance(-25, 100, 1, true);
    Drive.moveDistance(25, 100, 1, true);
}
autonRoute backwardsForwards = {"Backwards Forwards", 0, 0, 0, backwardsForwardsRoute};

// final
void nearSideAWPRoute()
{
    // open the back wing to get the match load triball out
    rightDropDown.open();
    // make sure the backwing has time to fully open
    wait(500, msec);
    // turn to the left to flick the triball out of the matchloader
    Drive.turn(-45, 100, 1);
    // put the dropdowns back up
    rightDropDown.close();
    // turn down the alleyway to face the hang bar
    wait(1000, msec);
    rightWing.open();
    wait(1000, msec);
    rightWing.close();
    wait(1000, msec);

    Drive.turn(-30, 100, 1);
    // wait to allow the matchload triball to roll infront of the robot to get an extra triball acrossed
    
    // drive throught the alleyway and touch bar with the ziptie on the intake
    intake_Group.spin(fwd, -12000, vex::voltageUnits::mV);
    Drive.moveDistance(40.5, 25, 5);
    Drive.turn(-45, 100, 0.5);
    // spin the intake out to push the triball that starts under the hang bar across
    intake_Group.spin(fwd, 12000, vex::voltageUnits::mV);
    wait(600, msec);
    intake_Group.spin(fwd, -12000, vex::voltageUnits::mV);
}
autonRoute nearSideSafeAWP = {"NS AWP SAFE", 0, 0, 0, nearSideAWPRoute};

void nearSideRushLeftAWPRoute()
{
    inertialSensorMain.setRotation(-80, deg);
    intake_Group.spin(fwd, 12000, vex::voltageUnits::mV);
    Drive.moveDistance(47, 100, 1.2);
    Drive.moveDistance(-49, 100, 1.3);
    intake_Group.spin(fwd, -12000, vex::voltageUnits::mV);
    leftWing.open();
    Drive.turn(20, 70, 1);
    leftWing.close();
    Drive.moveDistance(-25, 100, 1);
    intake_Group.spin(fwd, 0, vex::voltageUnits::mV);
    Drive.turn(90, 100, 0.8);
    Drive.moveDistance(-11, 50, 0.6);
    intake_Group.spin(fwd, -12000, vex::voltageUnits::mV);
    Drive.moveDistance(15, 75, 1);
    Drive.turn(50, 100, 0.8);
    Drive.moveDistance(17, 75, 1);
    rightDropDown.open();
    wait(200, msec);
    Drive.turn(-50, 100, 1);
    wait(200, msec);
    Drive.turn(5, 100, 1);
    rightDropDown.close();
    Drive.moveDistance(38.5, 80, 2);
    intake_Group.spin(fwd, 12000, vex::voltageUnits::mV);
    wait(50, msec);
    intake_Group.spin(fwd, -12000, vex::voltageUnits::mV);
    wait(200, msec);
    intake_Group.spin(fwd, 12000, vex::voltageUnits::mV);
    wait(50, msec);
    intake_Group.spin(fwd, -12000, vex::voltageUnits::mV);
    wait(200, msec);
    intake_Group.spin(fwd, 0, vex::voltageUnits::mV);
}
autonRoute nearSideRushLeftAWP = {"NS Rush Left AWP", 0, 0, 0, nearSideRushLeftAWPRoute};

void nearSideRushRightAWPRoute()
{
    inertialSensorMain.setRotation(-58, deg);
    intake_Group.spin(fwd, 12000, vex::voltageUnits::mV);
    Drive.moveDistance(54, 100, 1.6);
    Drive.moveDistance(-56, 80, 1.6);
    intake_Group.spin(fwd, -12000, vex::voltageUnits::mV);
    leftWing.open();
    Drive.turn(20, 70, 1);
    leftWing.close();
    Drive.moveDistance(-20, 100, 1);
    intake_Group.spin(fwd, 0, vex::voltageUnits::mV);
    Drive.turn(90, 100, 0.8);
    Drive.moveDistance(-8, 50, 0.8);
    intake_Group.spin(fwd, -12000, vex::voltageUnits::mV);
    Drive.moveDistance(12, 75, 1);
    Drive.turn(50, 100, 0.8);
    Drive.moveDistance(13, 75, 1);
    rightDropDown.open();
    wait(200, msec);
    Drive.turn(-30, 100, 1);
    Drive.turn(10, 100, 1);
    rightDropDown.close();
    Drive.moveDistance(39, 80, 2);
    intake_Group.spin(fwd, 12000, vex::voltageUnits::mV);
    wait(50, msec);
    leftWing.open();
    intake_Group.spin(fwd, -12000, vex::voltageUnits::mV);
    wait(200, msec);
    intake_Group.spin(fwd, 12000, vex::voltageUnits::mV);
    wait(50, msec);
    leftWing.close();
    intake_Group.spin(fwd, -12000, vex::voltageUnits::mV);
    wait(200, msec);
    intake_Group.spin(fwd, 0, vex::voltageUnits::mV);
}
autonRoute nearSideRushRightAWP = {"NS Rush Right AWP", 0, 0, 0, nearSideRushRightAWPRoute};

void nearSideRoute()
{
    inertialSensorMain.setRotation(-65, deg);
    intake_Group.spin(fwd, 12000, vex::voltageUnits::mV);
    Drive.moveDistance(53, 100, 1.6);
    Drive.moveDistance(-55, 80, 1.6);
    intake_Group.spin(fwd, -12000, vex::voltageUnits::mV);
    leftWing.open();
    Drive.turn(20, 70, 1);
    leftWing.close();
    Drive.moveDistance(-25, 100, 1);
    intake_Group.spin(fwd, 0, vex::voltageUnits::mV);
    Drive.turn(90, 100, 0.8);
    Drive.moveDistance(-8, 50, 0.6);
    intake_Group.spin(fwd, -12000, vex::voltageUnits::mV);
    Drive.moveDistance(16, 75, 1);
    Drive.turn(50, 100, 0.8);
    Drive.moveDistance(15, 75, 1);
    rightDropDown.open();
    wait(200, msec);
    Drive.turn(-30, 100, 1);
    Drive.turn(10, 100, 1);
    rightDropDown.close();
    Drive.moveDistance(38, 80, 1.4); 
    Drive.turn(0, 100, 0.4);  
    Drive.moveDistance(-42, 100, 1);
    Drive.turn(45, 100, 0.4);
    rightDropDown.open();
}
autonRoute nearSideElims = {"NS Barrier Elims", 0, 0, 0, nearSideRoute};

void farSideAWPRoute()
{
    Drive.moveDistance(7, 100, .8);
    rightDropDown.open();
    Drive.moveDistance(13, 100, .8);
    Drive.turn(-45, 100, 1);
    rightDropDown.close();
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
autonRoute farSideSafeAWP = {"FS AWP SAFE", 0, 0, 0, farSideAWPRoute};

void farSideRushLeftAWPRoute()
{
    inertialSensorMain.setRotation(65, deg);
    intake_Group.spin(fwd, 12000, vex::voltageUnits::mV);
    Drive.moveDistance(55, 100, 1.5);
    Drive.moveDistance(-50, 80, 1.1);
    intake_Group.spin(fwd, -12000, vex::voltageUnits::mV);
    Drive.turn(135, 70, 0.7);
    Drive.moveDistance(-13, 100, 0.7);
    intake_Group.spin(fwd, 12000, vex::voltageUnits::mV);
    Drive.turn(10, 100, 0.7);
    Drive.moveDistance(25, 100, 0.7);
    Drive.moveDistance(-24, 100, 0.8);
    Drive.turn(180, 100, 1);
    intake_Group.spin(fwd, -12000, vex::voltageUnits::mV);
    Drive.moveDistance(19, 100, 0.8);
    Drive.turn(145, 100, 0.8);
    rightDropDown.open();
    wait(200, msec);
    Drive.moveDistance(9, 100, 0.7);
    Drive.turn(70, 100, 0.8);
    rightDropDown.close();
    Drive.turn(110, 100, 0.6);
    rightWing.open();
    Drive.moveDistance(100, 100, 0.6);
    Drive.moveDistance(-25, 100, 0.7);
    rightWing.close();
    Drive.turn(-10, 100, 0.8);
    intake_Group.spin(fwd, 12000, vex::voltageUnits::mV);
    Drive.moveDistance(45, 100, 1.3);

}
autonRoute farSideRushLeftAWP = {"FS Rush Left AWP", 0, 0, 0, farSideRushLeftAWPRoute};

void farSideRushRightAWPRoute()
{

}
autonRoute farSideRushRightAWP = {"FS Rush Right AWP", 0, 0, 0, farSideRushRightAWPRoute};

void farSideRoute()
{
    inertialSensorMain.setRotation(-12, deg);
    intake_Group.spin(fwd, 12000, vex::voltageUnits::mV);
    Drive.moveDistance(52, 80, 1.4);
    Drive.moveDistance(-59, 80, 1.3);
    intake_Group.spin(fwd, -12000, vex::voltageUnits::mV);
    Drive.turn(90, 100, 0.7);
    Drive.moveDistance(-10, 100, 0.5);
    Drive.turn(-90, 100, 0.8);
    intake_Group.spin(fwd, 12000, vex::voltageUnits::mV);
    Drive.moveDistance(22, 100, 0.65);
    // inertialSensorMain.setRotation(-90, deg);
    Drive.moveDistance(-22, 100, 0.6);
    Drive.turn(80, 100, 0.65);
    intake_Group.spin(fwd, -12000, vex::voltageUnits::mV);
    Drive.moveDistance(16, 100, 0.7);
    Drive.turn(45, 100, 0.6);
    Drive.moveDistance(13, 100, 0.6);
    rightDropDown.open();
    wait(200, msec);
    Drive.turn(-10, 100, 0.4);
    rightDropDown.close();
    // Drive.swing(-10, 100, 30, 0.7);
    Drive.moveDistance(-10, 100, 0.12);
    Drive.turn(10, 100, 0.12);
    Drive.moveDistance(1000, 100, 0.7, false);
    Drive.moveDistance(-15, 100, 0.6);
    Drive.turn(-70, 100, 0.75);
    intake_Group.spin(fwd, 12000, vex::voltageUnits::mV);
    Drive.moveDistance(50, 100, 1.2);
    Drive.swing(-35, 100, 70, 0.9);
    intake_Group.spin(fwd, -12000, vex::voltageUnits::mV);
    rightWing.open();
    Drive.swing(35, 100, 0, 0.7);
    Drive.moveDistance(1000, 100, 0.4, false);
    rightWing.close();
    Drive.moveDistance(-1000, 100, 0.4, false);
}
autonRoute farSideElims = {"FS Elims", 0, 0, 0, farSideRoute};

void SkillsSetupRoute()
{
    Drive.turn(10, 100, 0.3);
    Drive.moveDistance(-20, 100, 0.7);
    Drive.turn(47, 100, 0.65);
    Drive.moveDistance(-10000, 100, 0.4);
    Drive.turn(45, 100, 0.3);
    Drive.moveDistance(10, 100, 0.7);
    Drive.turn(-63, 100, 0.6);
    Drive.moveDistance(-5, 100, 0.5);
    Drive.turn(-63, 100, 0.8);    
    rightDropDown.open();
}

void autonSkillsRoute()
{
    // run the inital setup route for skills
    SkillsSetupRoute(); // 4.45 seconds
    // shoot for 21 seconds
    shooter_Group.spin(fwd, 10000, vex::voltageUnits::mV);
    wait(22, sec);
    shooter_Group.stop(coast);
    rightDropDown.close();
    // spin intake to prevent double possesion
    intake_Group.spin(fwd, 12000, vex::voltageUnits::mV);
    // drive towards long barrier
    Drive.swing(55, 100, 0, 1); 
    Drive.turn(-20, 100, 0.4);
    intake_Group.spin(fwd, 12000, vex::voltageUnits::mV);
    rightWing.close();
    Drive.moveDistance(-12, 100, 0.7); //~-.25
    // turn parrell to long barrier to push triballs
    Drive.turn(-127, 100, 0.85);
    intake_Group.spin(fwd, -12000, vex::voltageUnits::mV);
    // open wings and run down the long barrier to push all the triballs across and into the alley way
    leftWing.open();
    rightWing.open();
    Drive.moveDistance(75, 100, 1.65); //~-.15
    leftWing.close();
    // sequence to get around the short barrier
    Drive.turn(-240, 70, 0.8);
    Drive.turn(-200, 100, 0.4);
    rightWing.close();
    intake_Group.spin(fwd, 0, vex::voltageUnits::mV);
    Drive.swing(42, 100, -240, 1);
    leftWing.open();
    Drive.turn(-120, 100, 0.8);
    intake_Group.spin(fwd, -12000, vex::voltageUnits::mV);
    leftWing.close();
    rightWing.open();
    Drive.swing(40, 100, -48, 0.9);
    Drive.turn(-60, 100, 0.4);
    // run down left alley way
    rightWing.open();
    Drive.moveDistance(50, 100, 1.6);
    Drive.turn(-35, 100, 0.4);
    // push tribals into the corner
    Drive.swing(47, 100, 46, 1);
    // push left side of goal
    Drive.moveDistance(1000, 100, 0.5);
    Drive.moveDistance(-14, 100, 0.6);
    // move around to the front side of the goal
                                                                Drive.turn(118, 100, 0.8);
    Drive.moveDistance(35, 100, 0.9);
    Drive.turn(10, 70, 0.9);
    rightWing.close();
    // first push into the front of the goal
    Drive.swing(35, 70, -60, 1.2);
    Drive.turn(40, 100, .5);
    Drive.swing(-20, 100, 80, 1.2);
    rightWing.open();
    leftWing.open();
    Drive.swing(30, 70, -45, 1.2);
    rightWing.close();
    Drive.moveDistance(1000, 100, 0.8);
    Drive.turn(0, 100, .4);
    Drive.swing(-20, 100, 70, 1.2);
    rightWing.open();
    Drive.swing(30, 70, -45, 1.2);
    rightWing.close();
    Drive.moveDistance(1000, 100, 0.8);
    // Drive.swing(-20, 100, 50, 0.8);
    // rightWing.open();
    // Drive.swing(45, 100, -35, 1);
    // Drive.moveDistance(10, 100, .8);
    // Drive.turn(-135, 100, .8)
    // Drive.moveDistance(1000, 100, 0.8);
    // Drive.moveDistance(-5, 100, .5);
   


    Drive.moveDistance(-8, 100, 0.5);
    // push right side
    Drive.turn(30, 100, 0.85);
    Drive.moveDistance(60, 100, 1);
    Drive.turn(-60, 100, 0.7);
    leftWing.open();
    Drive.swing(50, 100, -134, 1);
    Drive.moveDistance(1000, 100, 0.5);
    Drive.moveDistance(-1000, 100, 0.2);
    Drive.moveDistance(1000, 100, 0.7);
    Drive.moveDistance(-1000, 100, 0.2);
    leftWing.close();
}

void driverSkillsRoute()
{
    SkillsSetupRoute();
}

autonRoute driverSkills = {"Driver Skills", 0, 0, 0, driverSkillsRoute};
autonRoute autonSkills = {"Skills", 0, 0, 0, autonSkillsRoute};



