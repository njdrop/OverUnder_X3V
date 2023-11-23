#ifndef LIBRARY_H
#define LIBRARY_H

using namespace vex;

namespace lib
{

    void sendInputToMotors(vex::motor motor1, vex::motor motor2, double input);
    void toggleSolenoid(vex::pneumatics solenoid, bool toggleValue);
    double angularDistanceToLinearDistance(double angularDistance, double diameter);
}

class toggleBoolObject
{
public:
    toggleBoolObject(bool);
    void setValue(bool);
    void changeValueFromInput(bool);
    bool getValue();

private:
    void init();
    bool firstLoop;
    bool toggleValue;
};

#endif
