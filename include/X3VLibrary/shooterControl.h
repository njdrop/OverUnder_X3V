#ifndef SHOOTERCONTROL_H
#define SHOOTERCONTROL_H

#include "vex.h"
using namespace vex;


class shooterObj {
    public:
        /**
         * @brief Construct a new shooter Obj object
         */
        shooterObj (double loaded_position, double unloaded_position);

        /**
         * @brief maximum amount of time the shooter will spend trying to complete a function
         */
        double timeout;

        /**
         * @brief enables the task to automatically draw the shooter back
         */
        void startAutoDrawTask ();

        /**
         * @brief disables the task to automatically draw the shooter back
         */
        void stopAutoDrawTask ();

        /**
         * @brief draws the shooter to is back most position one time
         * 
         * @param aSync when true, the function will happen asyncronously rather than waiting for completion
         */
        void manualDraw (bool aSync);
        void manualDraw ();

        /**
         * @brief fires the shooter 
         * 
         * @param aSync when true, the function will happen asyncronously rather than waiting for completion
         */
        void shoot (bool aSync);
        void shoot ();

        /**
         * @brief returns the current possition of the shooter in percent of total range
         * 
         * @returns the percentage between the loaded and unloaded position (loaded = 1 - Unloaded = 0)
         */
        double position (vex::percentUnits units);

        /**
         * @brief returns the current possition of the shooter in degree
         */
        double position (vex::rotationUnits units);

        /**
         * @brief returns the current velocity of the shooter
         */
        double velocity (vex::velocityUnits units);

        /**
         * @brief returns true if the shooter position is past the loaded position
         */
        bool isLoaded ();
        
        /**
         * @brief returns true if the shooters velocity is not 0
         */
        bool isMoving ();

    private:
        /**
         * @brief Task for automatically drawing the shooter back
         */
        vex::task shooterDrawTask;

        /**
         * @brief Static function for task constructor
         * @param instance Pointer to the instance of the shooterObj
         * @return Result of calling shooterDrawFunction
         */
        static int shooterDrawFunctionStatic (void* instance);
    
        /**
         * @brief Member function for the shooter task
         * @param Unused parameter
         * @return Result of the shooter task
         */
        int shooterDrawFunction (void*);
        
        /**
         * @brief Loaded position of the shooter
         */
        double LOADED_POSITION;
        
        /**
         * @brief Unloaded position of the shooter
         */
        double UNLOADED_POSITION;
};

extern shooterObj Catapult;

#endif