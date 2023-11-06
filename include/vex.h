#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "v5.h"
#include "v5_vcs.h"


#include "MiniPID.h"
#include "X3VLibrary/driveControl.h"
#include "X3VLibrary/library.h"
#include "X3VLibrary/robotConfig.h"

extern int state;
extern bool leftDriveEngaged;
extern bool rightDriveEngaged;
void drive();
void shoot();
void ptoDriveToCata();
void ptoCataToDrive();

