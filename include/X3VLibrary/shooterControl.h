#ifndef SHOOTERCONTROL_H
#define SHOOTERCONTROL_H

#include "vex.h"
using namespace vex;


class shooterObj {
    public:
        /**
         * @brief Construct a new shooter Obj object
         */
        shooterObj(double loaded_position, double unloaded_position);

        /**
         * @brief maximum amount of time the shooter will spend trying to complete a function
         */
        double timeout;

        /**
         * @brief enables the task to automatically draw the shooter back
         */
        void startAutoDrawTask();

        /**
         * @brief disables the task to automatically draw the shooter back
         */
        void stopAutoDrawTask();

        /**
         * @brief draws the shooter to is back most position one time
         * 
         * @param aSync when true, the function will happen asyncronously rather than waiting for completion
         */
        void manualDraw(bool aSync = false);
        
        /**
         * @brief fires the shooter 
         * 
         * @param aSync when true, the function will happen asyncronously rather than waiting for completion
         */
        void shoot(bool aSync = true);

        /**
         * @brief returns the current possition of the shooter
         * 
         * @returns the percentage between the loaded and unloaded position (loaded = 1 - Unloaded = 0)
         */
        double position ();

        /**
         * @brief returns the current velocity of the shooter
         */
        double velocity (vex::velocityUnits units);

        /**
         * @brief return the value of isLoaded
         */
        bool getIsLoaded();

    private:
        /**
         * @brief static cast function to use the member function as static function 
         */
        static int shooterDrawFunctionStatic(void* instance);

        /**
         * @brief function that automaticly draws the shooter into the loaded position
         * @return the function will not reach the return
         */
        int shooterDrawFunction(void*);

        /**
         * @brief this is the task that the shooterDrawFunction runs inside of
         */
        vex::task shooterDrawTask;

        /**
         * @brief the loaded position of the shooter in degrees
         */
        double LOADED_POSITION;

        /**
         * @brief the unloaded position of the shooter in degrees
         */
        double UNLOADED_POSITION;

        /**
         * @brief a boolean value that represent is the shooter is in a loaded state
         * 
         */
        bool isLoaded;
};

#endif