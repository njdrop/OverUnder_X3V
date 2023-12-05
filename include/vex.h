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
void ptoCataToDrive();

void autoPTODriveToCata();
extern void autoPTOCataToDrive();

extern bool stateSwitchButtonReleased;

void doNothing();
void skills1();
void skills2();
void skills3();
void soloAutonomousWinPoint();
void qualificationOffensive();
void qualificationOffensiveRisky();
void qualificationDefensive();
void qualificationDefensiveRisky();
void eliminationOffensive();
void eliminationOffensiveRisky();
void eliminationDefensive();
void eliminationDefensiveRisky();


