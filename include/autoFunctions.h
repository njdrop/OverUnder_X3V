#ifndef AUTOFUNCTIONS_H
#define AUTOFUNCTIONS_H

using namespace vex;

void runAllMotors (double speed);

void stopAllMotors (vex::brakeType bType);


void driveStraight (double dist, double speed, double timeout);


#endif
