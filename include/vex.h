#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "v5.h"
#include "v5_vcs.h"


#include "X3VLibrary/MiniPID.h"
#include "X3VLibrary/drivetrainControl.h"
#include "X3VLibrary/library.h"
#include "X3VLibrary/Configuration/robotConfig.h"

void drive();
void shoot();
void ptoDriveToCata();
void autoPTODriveToCata();
void ptoCataToDrive();
extern void autoPTOCataToDrive();
extern bool stateSwitchButtonReleased;


