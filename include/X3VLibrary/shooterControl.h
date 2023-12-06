#ifndef SHOOTERCONTROL_H
#define SHOOTERCONTROL_H

#include "vex.h"
using namespace vex;



/*

int driveStateMachineTask();

class driveControl
{
public:
    driveControl(double wheelDiam, double gR);
    void runLeftSide(double voltage, bool withPTO = false);
    void runRightSide(double voltage, bool withPTO = false);
    void stopLeftSide(vex::brakeType brakeType = brake, bool withPTO = false);
    void stopRightSide(vex::brakeType brakeType = brake, bool withPTO = false);
    void moveDistance(double distance, double maxSpeed, double timeout, bool withPTO = false, bool correctHeading = false);
    void turn(double targetAngle, double maxSpeed, double timeout, bool withPTO = false);
    void setBrakeType(vex::brakeType brakeType);
    void startAutoStateMachineTask();
    void stopAutoStateMachineTask();
    bool PTO_DriveEngaged;
    state driveState;
    vex::task driveTask;

        private:
    double getLeftDriveEncoderValue(bool withPTO = false);
    double getRightDriveEncoderValue(bool withPTO = false);
    double getDriveEncoderValue(bool withPTO = false);
    double wheelDiameter;
    double gearRatio;
};

extern driveControl Drive;
*/

class shooter {

};

#endif