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

// libraries
// #include <stdarg.h>


// X3V Library
#include "X3VLibrary/drivetrain.h"
#include "X3VLibrary/inertialGroup.h"
#include "X3VLibrary/MiniPID.h"
#include "X3VLibrary/library.h"
#include "Configuration/robotConfig.h"




// autonomous routes
extern	autonRoute	doNothing;
extern	autonRoute	skills1;
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