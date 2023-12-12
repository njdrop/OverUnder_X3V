#ifndef ODOMETRY_H
#define ODOMETRY_H

#include "vex.h"
using namespace vex;


class odometry {
        public:
                double getX();
                double getY();
                double getHeading();
        private:
                task odometryTask;
        protected:
                double xPosition;
                double yPosition;
                double heading;
                // similar to private these are members that can be accesed from the child class but not from the object itself

};

#endif