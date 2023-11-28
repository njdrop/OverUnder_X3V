#include "vex.h"
using namespace vex;

namespace lib
{
    
    void sendInputToMotors(vex::motor motor1, vex::motor motor2, double input)
    {
        /*
        * calls both motors with voltage control
        * when using voltage control, decimals make the motor twitch and heat up...
        * so we round th input to the nearest ineger
        * (it is on a scale of -12000 to 12000 so this does not cause noticable granularity)
        */
        motor1.spin(fwd, nearbyint(input), vex::voltageUnits::mV);
        motor2.spin(fwd, nearbyint(input), vex::voltageUnits::mV);
    }

    void toggleSolenoid(vex::pneumatics solenoid, bool toggleValue)
    {
        // if the toggleValue is true
        if (toggleValue)
        {
            // then open the solenoid
            solenoid.open();
        }
        else
        {
            // otherwise close the solenoid
            solenoid.close();
        }
    }

    double angularDistanceToLinearDistance(double angularDistance, double diameter)
    {
        return (angularDistance * 3.14159 / 180) * (diameter / 2);
    }

    double angularDistanceToLinearDistance(double angularDistance, double diameter, double gearRatio)
    {
        double radius = diameter / 2;
        double angularDitstanceinRadians = angularDistance * 3.14159 / 180;
        double angularDIstanceofOutput = angularDitstanceinRadians * gearRatio;
        double linearDistance = angularDIstanceofOutput * radius;
        return linearDistance;
    }
}


void vex::controller::lcd::smartPrint(const char *displayText)   
{
    clearScreen();
    setCursor(1,1);
    print(displayText);
}

void vex::controller::lcd::smartPrint(char displayText)   
{
    clearScreen();
    setCursor(1,1);
    print(displayText);
}

toggleBoolObject::toggleBoolObject(bool initialValue)
{
    firstLoop = true;
    toggleValue = initialValue;
}

void toggleBoolObject::setValue(bool value)
{
    toggleValue = value;
}

void toggleBoolObject::changeValueFromInput(bool buttonValue)
{

    if (buttonValue)
    {
        if (firstLoop)
        {
            firstLoop = false;
            toggleValue = !toggleValue;
        }
    }
    else
    {
        firstLoop = true;
    }
}

bool toggleBoolObject::getValue()
{
    return toggleValue;
}
