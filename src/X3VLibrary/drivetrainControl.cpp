#include "vex.h"
using namespace vex;

/**
 * @brief sets the left side motors to spin at a voltage
 * 
 * @param voltage the voltage applied to the motors (messured in mV)
 * @param withPTO true => runs all four motors false => runs just the two direct motors (defult is set to false)
 */
void runLeftSide(double voltage, bool withPTO = false) 
{
        leftMotor1.spin(fwd, nearbyint(voltage), vex::voltageUnits::mV);
        leftMotor2.spin(fwd, nearbyint(voltage), vex::voltageUnits::mV);
        if (withPTO) 
        {
                leftMotor3.spin(fwd, nearbyint(voltage), vex::voltageUnits::mV);
                leftMotor4.spin(fwd, nearbyint(voltage), vex::voltageUnits::mV);
        }
}

/**
 * @brief sets the right side motors to spin at a voltage
 * 
 * @param voltage the voltage applied to the motors (messured in mV)
 * @param withPTO true => runs all four motors false => runs just the two direct motors (defult is set to false)
 */
void runRightSide(double voltage, bool withPTO = false) 
{
        rightMotor1.spin(fwd, nearbyint(voltage), vex::voltageUnits::mV);
        rightMotor2.spin(fwd, nearbyint(voltage), vex::voltageUnits::mV);
        if (withPTO) 
        {
                rightMotor3.spin(fwd, nearbyint(voltage), vex::voltageUnits::mV);
                rightMotor4.spin(fwd, nearbyint(voltage), vex::voltageUnits::mV);
        }
}


