#include "vex.h"
using namespace vex;


void doNothingRoute()
{
    // do nothing
    Drive.turn(90, 100, 10);
}
autonRoute doNothing = {"Do Nothing", 0, 0, 0, doNothingRoute};

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

