#ifndef INERTIALGROUP_H
#define INERTIALGROUP_H

#include "vex.h"
using namespace vex;

class inertialGroup 
{
    public:
        inertialGroup (vex::inertial main, vex::inertial secondary);
        double getHeading ();
        double getRotation ();
};

#endif