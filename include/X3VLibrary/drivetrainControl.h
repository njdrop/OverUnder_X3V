#ifndef DRIVECONTROL_H
#define DRIVECONTROL_H

#include "vex.h"
using namespace vex;

int driveStateMachineFunction();

class drivetrainObj
{
public:
    drivetrainObj(double wheelDiam, double gR);
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

    /**
     * @brief this controls the state of the drive (you must have run startAutoStateMachineTask() for this to work)
     * 
     * Possible Values to Assign
     * state::drive
     * state::ptoDrivetoCata
     * state::ptoCatatoDrive
     * state::shoot
     */
    state driveState;
    

private:
    double getLeftDriveEncoderValue(bool withPTO = false);
    double getRightDriveEncoderValue(bool withPTO = false);
    double getDriveEncoderValue(bool withPTO = false);
    double wheelDiameter;
    double gearRatio;
    vex::task driveTask;

};

/**
 * @brief This is the drivetrain for the current robot
 */
extern drivetrainObj Drive;

#endif
