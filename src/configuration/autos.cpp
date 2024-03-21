#include "vex.h"
using namespace vex;

void doNothingRoute()
{
    // do nothing
}
autonRoute doNothing = {"Do Nothing", 0, 0, 0, doNothingRoute};

void forwardsBackwardsRoute()
{
    // drive forwards 25 inches
    Drive.moveDistance(25, 100, 1, true);
    // drive backwards 25 inches
    Drive.moveDistance(-25, 100, 1, true);
}
autonRoute forwardsBackwards = {"Forwards Backwards", 0, 0, 0, forwardsBackwardsRoute};

void backwardsForwardsRoute()
{
    // same thing as forwardsBackwardsRoute() but in reverse
    Drive.moveDistance(-25, 100, 1, true);
    Drive.moveDistance(25, 100, 1, true);
}
autonRoute backwardsForwards = {"Backwards Forwards", 0, 0, 0, backwardsForwardsRoute};

void nearSideAWPRoute()
{
    // open the back wing to get the match load triball out
    dropDown.open();
    // make sure the backwing has time to fully open
    wait(0.5, sec);
    // turn to the left to flick the triball out of the matchloader
    Drive.turn(-45, 100, 1);
    // put the dropdowns back up
    dropDown.close();
    // turn down the alleyway to face the hang bar
    Drive.turn(-43, 100, 1);
    // wait to allow the matchload triball to roll infront of the robot to get an extra triball acrossed
    wait(3, sec);
    // drive throught the alleyway and touch bar with the ziptie on the intake
    Drive.moveDistance(41.5, 100, 1.3, true);
    // spin the intake out to push the triball that starts under the hang bar across
    intake_Group.spin(reverse, 12000, vex::voltageUnits::mV);
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
    dropDown.open();
    wait(200, msec);
    Drive.turn(-50, 100, 1);
    wait(200, msec);
    Drive.turn(5, 100, 1);
    dropDown.close();
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
    inertialSensorMain.setRotation(-65, deg);
    intake_Group.spin(fwd, 12000, vex::voltageUnits::mV);
    Drive.moveDistance(53, 100, 1.4);
    Drive.moveDistance(-55, 100, 1.2);
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
    dropDown.open();
    Drive.turn(-50, 100, 1);
    wait(200, msec);
    Drive.turn(5, 100, 1);
    dropDown.close();
    Drive.moveDistance(38, 80, 2);
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
autonRoute nearSideRushRightAWP = {"NS Rush Right AWP", 0, 0, 0, nearSideRushRightAWPRoute};

void nearSideRoute()
{
    inertialSensorMain.setRotation(-65, deg);
    intake_Group.spin(fwd, 12000, vex::voltageUnits::mV);
    Drive.moveDistance(53, 100, 1.4);
    Drive.moveDistance(-55, 100, 1.2);
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
    dropDown.open();
    Drive.turn(-50, 100, 1);
    wait(200, msec);
    Drive.turn(5, 100, 1);
    dropDown.close();
    Drive.moveDistance(38, 80, 1.2);
    Drive.moveDistance(-38, 100, 1.2);
    Drive.turn(45, 100, 0.8);
    Drive.moveDistance(-8, 100, 0.8);
    dropDown.open();
}
autonRoute nearSideElims = {"NS Barrier Elims", 0, 0, 0, nearSideRoute};

void farSideAWPRoute()
{
    Drive.moveDistance(7, 100, .8);
    dropDown.open();
    Drive.moveDistance(13, 100, .8);
    Drive.turn(-45, 100, 1);
    dropDown.close();
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
    Drive.moveDistance(53, 100, 1.4);
    Drive.moveDistance(-32, 100, 0.8);
    Drive.turn(70, 100, 0.6);
    Drive.moveDistance(-25, 100, 0.8);
    rightWing.open();
    wait(100, msec);
    intake_Group.spin(fwd, -12000, vex::voltageUnits::mV);
    Drive.turn(140, 70, 1);
    rightWing.close();
    
    // Drive.turn(160, 100, 0.75);
    // Drive.moveDistance(19, 100, 0.8);
    // dropDown.open();
    // Drive.turn(70, 100, 0.8);
    // dropDown.close();
    // wait(200, msec);
    // Drive.turn(-45, 100, 0.8);
    // Drive.moveDistance(-10, 100, 0.8);
    // Drive.turn(-90, 100, 0.8);
    // dropDown.open();
    // Drive.moveDistance(-100, 100, 0.8);
    // dropDown.close();
    // Drive.turn(-45, 100, 0.8);
    // Drive.moveDistance(30, 100, 0.8);
    // Drive.turn(7, 100, 0.75);
    // intake_Group.spin(fwd, 12000, vex::voltageUnits::mV);
    // Drive.moveDistance(33, 100, 1.4);
}
autonRoute farSideRushLeftAWP = {"FS Rush Left AWP", 0, 0, 0, farSideRushLeftAWPRoute};

void farSideRushRightAWPRoute()
{
    
}
autonRoute farSideRushRightAWP = {"FS Rush Right AWP", 0, 0, 0, farSideRushRightAWPRoute};

void farSideRoute()
{
    // grab hang bar triball and drive back to matchload bar
    intake_Group.spin(fwd, 100, pct);
    Drive.moveDistance(4, 100, 0.4);
    Drive.moveDistance(-37, 85, 1.2);
    // turn and knock triball out of matchloader
    Drive.turn(140, 100, 1.2);
    intake_Group.spin(fwd, -100, pct);
    Drive.moveDistance(19, 100, 0.6);
    dropDown.open();
    Drive.moveDistance(12, 100, 0.6);
    Drive.turn(80, 100, 0.6);
    dropDown.close();

    // turn and push all triballs into the goal
    Drive.turn(120, 100, 0.4);
    leftWing.open();
    Drive.swing(1000, 100, 90, 0.6);
    Drive.moveDistance(-20, 100, 0.5);
    leftWing.close();

    // turn and grab free triball on barrier
    Drive.turn(33, 100, 0.6);
    intake_Group.spin(fwd, 100, pct);
    Drive.swing(55, 100, 5, 1.25);
    Drive.turn(105, 100, 0.7);
    Drive.moveDistance(12, 100, 0.6);
    Drive.turn(180, 100, 0.6);
    intake_Group.spin(fwd, -100, pct);

    leftWing.open();
    Drive.moveDistance(1000, 100, 0.8);
    leftWing.close();

    Drive.turn(15, 100, 1.2);
    intake_Group.spin(fwd, 100, pct);
    Drive.moveDistance(30, 100, 0.9);
    Drive.turn(180, 100, 1.2);
    leftWing.open();
    rightWing.open();
    intake_Group.spin(fwd, -100, pct);
    Drive.moveDistance(100000, 100, 0.7);
    leftWing.close();
    rightWing.close();
    Drive.moveDistance(-10000, 100, 0.05);
    intake_Group.stop(coast);
}
autonRoute farSideElims = {"FS Elims", 0, 0, 0, farSideRoute};

void SkillsSetupRoute()
{
<<<<<<< HEAD
=======
    int startTime = vex::timer::system();
>>>>>>> parent of 6139a29 (tuning pids after car drop off doing zombies)
    Drive.turn(10, 100, 0.3);
    Drive.moveDistance(-22, 100, 0.75);
    Drive.turn(47, 100, 0.5);
    Drive.moveDistance(-10000, 100, 0.7);
    Drive.turn(45, 100, 0.6);
    Drive.moveDistance(10, 100, 0.45);
    Drive.turn(-60, 100, 0.5);
    Drive.moveDistance(-7, 100, 0.3);
    Drive.turn(-63, 100, 0.4);
    dropDown.open();
}

void SkillsSetupRoute2()
{
<<<<<<< HEAD
=======
    int startTime = vex::timer::system();
>>>>>>> parent of 6139a29 (tuning pids after car drop off doing zombies)
    Drive.turn(20, 100, 0.5);
    Drive.moveDistance(-14, 100, 0.75);
    Drive.turn(-63, 100, 0.5);
    Drive.moveDistance(-5, 100, .5);
    dropDown.open();
}


void autonSkillsRoute()
{
    // run the inital setup route for skills
    SkillsSetupRoute2(); // 4.45 seconds
    wait(1000, sec);
    // shoot for 28 seconds
    int startTime = vex::timer::system();
    shooter_Group.spin(fwd, 10000, vex::voltageUnits::mV);
    // wait(22.25, sec);
    shooter_Group.stop(coast);
    dropDown.close();
    Drive.turn(-66, 100, 0.5);
    // spin intake to prevent double possesion
    intake_Group.spin(fwd, 12000, vex::voltageUnits::mV);
    // drive towards long barrier
    rightWing.open();
    Drive.swing(62, 100, -35, 1);
    rightWing.close();
    Drive.moveDistance(-15, 100, 0.7);
    // turn parrell to long barrier to push triballs
    Drive.turn(-127, 100, 0.85);
    intake_Group.spin(fwd, -12000, vex::voltageUnits::mV);
    // open wings and run down the long barrier to push all the triballs across and into the alley way
    leftWing.open();
    rightWing.open();
    Drive.moveDistance(75, 100, 1.65);
    leftWing.close();
    rightWing.close();
    // ensure the robot has not gotten turned incedentally
    Drive.turn(-130, 100, 0.1);
    // back off of the short barrier
    Drive.moveDistance(-15, 100, 0.6);
    // sequence to get around the short barrier
    Drive.turn(-200, 100, 0.6);
    Drive.moveDistance(25, 100, 0.5);
    Drive.swing(25, 100, -58, 1);
    // run down left alley way
    Drive.turn(-60, 100, 0.2);
    rightWing.open();
    Drive.moveDistance(70, 100, 1.7);
    Drive.turn(-35, 100, 0.4);
    // push tribals into the corner
    Drive.swing(47, 100, 46, 1);
    // push left side of goal
    Drive.moveDistance(1000, 100, 0.5);
    Drive.moveDistance(-8, 100, 0.5);
    rightWing.close();
    Drive.turn(36, 100, 0.2);
    // move around to the front side of the goal
    Drive.turn(135, 100, 0.9);
    Drive.swing(45, 100, 100, 1);
    Drive.turn(-15, 100, 0.95);
    leftWing.open();
    // first push into the front of the goal
    Drive.swing(40, 85, -60, 1);
    Drive.moveDistance(1000, 100, 0.4);
    Drive.turn(-0, 100, 0.3); 
    leftWing.close();
    Drive.swing(-30, 100, 51, 1);
    // turn to move further right for the second push
    Drive.moveDistance(27, 100, 0.85);
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
    Drive.moveDistance(35, 100, 0.8);
    Drive.turn(-95, 100, 0.95);
    rightWing.open();
    leftWing.open();
    Drive.swing(50, 100, -10, 1);
    Drive.moveDistance(1000, 100, 0.3);
    Drive.moveDistance(-15, 100, 0.4);
    leftWing.close();
    rightWing.close();
    Drive.turn(-55, 100, 0.45);
    Drive.moveDistance(-10, 100, 0.7);
    // push right side
    Drive.turn(30, 100, 0.85);
    Drive.moveDistance(45, 100, 0.7);
    Drive.turn(-60, 100, 0.75);
    leftWing.open();
    Drive.swing(40, 100, -134, 1.2);
    Drive.moveDistance(1000, 100, 0.6);
    Drive.moveDistance(-1000, 100, 0.1);
    leftWing.close();
    printf("%lu\n", vex::timer::system() - startTime);
}

void driverSkillsRoute()
{
    SkillsSetupRoute();
}

autonRoute driverSkills = {"Driver Skills", 0, 0, 0, driverSkillsRoute};
autonRoute autonSkills = {"Skills", 0, 0, 0, autonSkillsRoute};



