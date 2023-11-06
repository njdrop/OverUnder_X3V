#include "vex.h"
using namespace vex;


namespace lib {
        
        void sendInputToMotors (vex::motor motor1, vex::motor motor2, double input) 
        {
                /*
                calls both motors with voltage control
                when using voltage control, decimals make the motor twitch and heat up...
                so we round th input to the nearest ineger
                (it is on a scale of -12000 to 12000 so this does not cause noticable granularity)
                */
                motor1.spin(fwd, nearbyint(input), vex::voltageUnits::mV);
                motor2.spin(fwd, nearbyint(input), vex::voltageUnits::mV);
        }

        void toggleSolenoid(vex::pneumatics solenoid, bool toggleValue) 
        {
                //if the toggleValue is true
                if (toggleValue) {
                        //then open the solenoid
                        solenoid.open();
                } 
                else 
                {
                        //otherwise close the solenoid
                        solenoid.close();
                }
        }
}


/**
 * @brief Construct a new toggle Boolean object
 * 
 * @param initialValue the value the boolean will be set to initaly
 */
toggleBoolObject::toggleBoolObject(bool initialValue) {
        firstLoop = true;
        toggleValue = initialValue;
}

/**
 * @brief Set the Boolean objects value manually
 * 
 * @param value the value the boolean will be manually set to
 */
void toggleBoolObject::setValue(bool value) {
        toggleValue = value;
}

 /**
 * @brief changes the boolean object's value based on input from the controller
 * on the first loop in which the button value is true the objects's value will toggle
 * subsequent loops will not change the value until the button value becomes false again
 * 
 * @param buttonValue weather the button is being pressed. Used to determine if the boolean object should be toggled 
 */
void toggleBoolObject::changeValueFromInput(bool buttonValue) {
        
        if (buttonValue) {
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

/**
 * @brief Get the Value of the boolean object
 * 
 * @return true 
 * @return false 
 */
bool toggleBoolObject::getValue() {
        return toggleValue;
}
