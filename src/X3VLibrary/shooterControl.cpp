#include "vex.h"
using namespace vex;

shooterObj::shooterObj (double loaded_position, double unloaded_position) 
{    
        timeout = 5;
        LOADED_POSITION = loaded_position;
        UNLOADED_POSITION = unloaded_position;
};

int shooterObj::shooterDrawFunction (void*) 
{
        while (true)
        {
                if ((*shooterRotationSensor).velocity(rpm) > 0) 
                {
                        shooter_Group.stop(vex::brakeType::brake);
                }
                else if ((*shooterRotationSensor).position(deg) >= 1)
                {

                }
                wait(10, msec);
        }
        return 0;
}

int shooterObj::shooterDrawFunctionStatic(void* instance) {
        return static_cast<shooterObj*>(instance)->shooterDrawFunction(nullptr);
}

void shooterObj::startAutoDrawTask() {
        shooterDrawTask = vex::task(shooterDrawFunctionStatic, this);
}

void shooterObj::stopAutoDrawTask ()
{
        shooterDrawTask.stop();
}

void shooterObj::manualDraw (bool aSync)
{

}

void shooterObj::shoot (bool aSync)
{
        
}

double shooterObj::position () {
        double maximumAngle = LOADED_POSITION - UNLOADED_POSITION;
        double currentAngle = (*shooterRotationSensor).position(deg) - UNLOADED_POSITION;
        double percentAngle = currentAngle / maximumAngle;
        return percentAngle;
}

double shooterObj::velocity (vex::velocityUnits units) {
        return (*shooterRotationSensor).velocity(units);
}

bool shooterObj::getIsLoaded () {
        return isLoaded;
}

shooterObj Catapult = shooterObj(SHOOTER_LOADED_POSITION, SHOOTER_UNLOADED_POSITION);
