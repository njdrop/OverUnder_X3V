#ifndef VEX_H
#define VEX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "v5.h"
#include "v5_vcs.h"

#include "X3VLibrary/MiniPID.h"
#include "X3VLibrary/library.h"
#include "Configuration/robotConfig.h"
#include "X3VLibrary/drivetrainControl.h"
#include "X3VLibrary/shooterControl.h"

void driveState();
void shootState();
void ptoDriveToCataState();
void ptoCataToDriveState();
void autoPTODriveToCata();
void autoPTOCataToDrive();

extern bool stateSwitchButtonReleased;

void	doNothingRoute();
void	skills1Route();
void	skills2Route();
void	skills3Route();
void	soloAutonomousWinPointRoute();
void	qualificationOffensiveRoute();
void	qualificationOffensiveRiskyRoute();
void	qualificationDefensiveRoute();
void	qualificationDefensiveRiskyRoute();
void	eliminationOffensiveRoute();
void	eliminationOffensiveRiskyRoute();
void	eliminationDefensiveRoute();
void	eliminationDefensiveRiskyRoute();
extern	autonRoute	doNothing;
extern	autonRoute	skills1;
extern	autonRoute	skills2;
extern	autonRoute	skills3;
extern	autonRoute	soloAutonomousWinPoint;
extern	autonRoute	qualificationOffensive;
extern	autonRoute	qualificationOffensiveRisky;
extern	autonRoute	qualificationDefensive;
extern	autonRoute	qualificationDefensiveRisky;
extern	autonRoute	eliminationOffensive;
extern	autonRoute	eliminationOffensiveRisky;
extern	autonRoute	eliminationDefensive;
extern	autonRoute	eliminationDefensiveRisky;

#endif