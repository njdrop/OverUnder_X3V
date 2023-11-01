#include "vex.h"
#include "library.h"
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

        static bool firstLoop = true;
        void toggleBool(bool buttonValue, bool &toggleValue) {
                //if the up button is pressed
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

        
}
