#include "vex.h"
using namespace vex;

namespace lib
{
    double angularDistanceToLinearDistance(double angularDistance, double diameter)
    {
        return (angularDistance * 3.14159 / 180) * (diameter / 2);
    }

    double angularDistanceToLinearDistance(double angularDistance, double diameter, double gearRatio)
    {
        double angularDitstanceinRadians = angularDistance * 3.14159 / 180 * gearRatio;
        return angularDitstanceinRadians * diameter / 2;
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

void vex::brain::lcd::smartPrint(const char *displayText)   
{
    clearScreen();
    setCursor(1,1);
    print(displayText);
}

void vex::brain::lcd::smartPrint(char displayText)   
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
