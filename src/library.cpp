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



toggleBoolObject::toggleBoolObject(bool initialValue) {
        firstLoop = true;
        toggleValue = initialValue;
}

void toggleBoolObject::setValue(bool value) {
        toggleValue = value;
}

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

bool toggleBoolObject::getValue() {
        return toggleValue;
}
