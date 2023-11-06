#ifndef DRIVECONTROL_H
#define DRIVECONTROL_H

using namespace vex;

class drive {
        public:
                void runLeftSide(double voltage, bool withPTO = false);
                void runRightSide(double voltage, bool withPTO = false);
                void driveForward(double distance, double maxSpeed, )

};

#endif
