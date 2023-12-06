#include "vex.h"
using namespace vex;

shooterObj::shooterObj (double loaded_position, double unloaded_position) 
{    
        timeout = 5;
        LOADED_POSITION = loaded_position;
        UNLOADED_POSITION = unloaded_position;
};

void shooterObj::startAutoDrawTask ()
{
        shooterDrawTask = task(shooterDrawFunction);
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
