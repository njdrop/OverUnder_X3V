#ifndef VEX_H
#define VEX_H

// libraries
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <array>
#include <stack>
#include <map>
#include <queue>

// vex dependancies
#include "v5.h"
#include "v5_vcs.h"

// X3V Library
#include "X3VLibrary/library.h"
#include "X3VLibrary/MiniPID.h"
#include "X3VLibrary/drivetrain.h"
#include "Configuration/robotConfig.h"


// autonomous routes
extern	autonRoute	doNothing;
extern  autonRoute      forwardsBackwards;
extern  autonRoute      backwardsForwards;
extern  autonRoute      nearSideSafeAWP;
extern  autonRoute      nearSideRushLeftAWP;
extern  autonRoute      nearSideRushRightAWP;
extern  autonRoute      nearSideElims;
extern  autonRoute      farSideSafeAWP;
extern  autonRoute      farSideRushLeftAWP;
extern  autonRoute      farSideRushRightAWP;
extern  autonRoute      farSideElims;
extern  autonRoute      autonSkills;
extern  autonRoute      driverSkills;

#endif