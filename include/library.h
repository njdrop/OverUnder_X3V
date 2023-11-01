#ifndef LIBRARY_H
#define LIBRARY_H

using namespace vex;

namespace lib {
        /**
         * @brief Send an input to two motors with one command as a voltage command. Also rounds the input to the nearest integer to stop the motors from bugging out
         * 
         * @param motor1 one of the motors the input will be sent to
         * @param motor2 the other motor the input will be sent to
         * @param input mV to be sent to both motors (min: -12000, max:+12000)
         */
        void sendInputToMotors(vex::motor motor1, vex::motor motor2, double input);

        /**
         * @brief If bool is true open a solinoid, otherwise close it
         * 
         * @param solenoid the solenoid that should be controlled
         * @param toggleValue the bool that should be used to evaluate if it should be toggled 
         */
        void toggleSolenoid(vex::pneumatics solenoid, bool toggleValue);

        /**
         * @brief If a button is pressed then it will toggle a boolean variable. If this function is run multiple time,
         * the bool will only be toggle in the first loop until the button is released again
         * 
         * @param button the solenoid that should be controlled
         * @param toggleValue the bool that should be used to evaluate if it should be toggled 
         */
        void toggleBool(bool buttonValue, bool &toggleValue);
}

#endif
