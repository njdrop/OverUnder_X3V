#include "vex.h"
using namespace vex;


void doNothingRoute()
{
    // do nothing
    Drive.moveDistance(10, 100, 15, true);
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

void farSideAWPRoute()
{
    backWings.open();
    wait(500,msec);
    Drive.moveDistance(-1, 100, 1, true);//-15
    backWings.close();
    Drive.turn(45, 100, 1);
    Drive.moveDistance(-1, 100, 1, true);//-25
    Drive.turn(-10, 100, 1);
    Drive.moveDistance(1, 100, 2, true);
    Drive.turn(-45, 100, 1);
    Drive.moveDistance(1, 100, 2, true);
}
autonRoute farSideAWP = {"FS AWP SAFE", 0, 0, 0, farSideAWPRoute};

void skills1Route()
{
   
}
autonRoute skills1 = {"Skills", 0, 0, 0, skills1Route};

void soloAutonomousWinPointRoute()
{
   
}
autonRoute soloAutonomousWinPoint = {"Solo AWP", 0, 0, 0, soloAutonomousWinPointRoute};

void qualificationOffensiveRoute()
{
    
}
autonRoute qualificationOffensive = {"Q - Offensive", 0, 0, 0, qualificationOffensiveRoute};

void qualificationOffensiveRiskyRoute()
{
   
}
autonRoute qualificationOffensiveRisky = {"RISKY Q - Offensive", 0, 0, 0, qualificationOffensiveRiskyRoute};

void qualificationDefensiveRoute()
{
   
}
autonRoute qualificationDefensive = {"Q - Defensive", 0, 0, 0, qualificationDefensiveRoute};

void qualificationDefensiveRiskyRoute()
{

}
autonRoute qualificationDefensiveRisky = {"RISKY Q - Defensive", 0, 0, 0, qualificationDefensiveRiskyRoute};

void eliminationOffensiveRoute()
{
   
}
autonRoute eliminationOffensive = {"E - Offensive", 0, 0, 0, eliminationOffensiveRoute};

void eliminationOffensiveRiskyRoute()
{
  
}
autonRoute eliminationOffensiveRisky = {"RISKY E - Offensive", 0, 0, 0, eliminationOffensiveRiskyRoute};

void eliminationDefensiveRoute()
{

}
autonRoute eliminationDefensive = {"E - Defensive", 0, 0, 0, eliminationDefensiveRoute};

void eliminationDefensiveRiskyRoute()
{

}
autonRoute eliminationDefensiveRisky = {"RISKY E - Defensive", 0, 0, 0, eliminationDefensiveRiskyRoute};

