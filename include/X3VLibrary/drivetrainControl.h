#ifndef DRIVECONTROL_H
#define DRIVECONTROL_H

using namespace vex;

class driveControl {
        public:
                driveControl(double wheelDiam);
                void runLeftSide(double voltage, bool withPTO = false);
                void runRightSide(double voltage, bool withPTO = false);
                void stopLeftSide(vex::brakeType brakeType = brake, bool withPTO = false);
                void stopRightSide(vex::brakeType brakeType = brake, bool withPTO = false);
                void moveDistance(double distance, double maxSpeed, double timeout, bool withPTO = false);
                void turn(double targetAngle, double maxSpeed, double timeout, bool withPTO = false);
        private:
                double getLeftDriveEncoderValue(bool withPTO = false);
                double getRightDriveEncoderValue(bool withPTO = false);
                double getDriveEncoderValue(bool withPTO = false);
                double wheelDiameter;
};

extern driveControl Drive;

#endif
