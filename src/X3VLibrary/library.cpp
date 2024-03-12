#include "vex.h"
using namespace vex;

double angularDistanceToLinearDistance(double angularDistance, double diameter, double gearRatio)
{
    return angularDistance * M_PI / 180.0 * gearRatio * (diameter / 2.0);
}

double clamp(double value, double min, double max) 
{
    // if the value is within the desire interval just return the value
    if (min <= value && value <= max)
    {
        return value;
    }
    
    // if the value is less than the min then just return the min
    if (value < min)
    {
        return min;
    }

    // if the value excedes the maximimum then return the max
    if (value > max)
    {
        return max;
    }
    return -1;
}
double clamp(double value, double min); 
double clamp(double value, double max);

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
