#ifndef VEX_H
#define VEX_H

// libraries
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// vex dependancies
#include "v5.h"
#include "v5_vcs.h"

// X3V Library
#include "Configuration/robotConfig.h"
#include "X3VLibrary/MiniPID.h"
#include "X3VLibrary/library.h"
#include "X3VLibrary/odometry.h"
#include "X3VLibrary/drivetrainControl.h"
#include "X3VLibrary/shooterControl.h"

// usercontrol states
void driveState();
void shootState();
void ptoDriveToCataState();
void ptoCataToDriveState();

// autonomous routes
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