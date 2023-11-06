#ifndef DRIVECONTROL_H
#define DRIVECONTROL_H

using namespace vex;

class drive {
        public:
                void runLeftSide(double voltage, bool withPTO = false);
                void runRightSide(double voltage, bool withPTO = false);
                void stopLeftSide(vex::brakeType brakeType = brake, bool withPTO = false);
                void stopRightSide(vex::brakeType brakeType = brake, bool withPTO = false);
                void driveDistance(double distance, double maxSpeed, double timeout, bool withPTO = false);
                void driveTurn(double targetAngle, double maxSpeed, double timeout, bool withPTO = false);
        private:
                double getLeftDriveEncoderValue(bool withPTO = false);
                double getRightDriveEncoderValue(bool withPTO = false);
                double getDriveEncoderValue(bool withPTO = false);
};

#endif
