#include "vex.h"
using namespace vex;

shooterObj::shooterObj (double loaded_position, double unloaded_position) 
{    
        timeout = 5;
        LOADED_POSITION = loaded_position;
        UNLOADED_POSITION = unloaded_position;
};

int shooterObj::shooterDrawFunction(void*)
{
        // Continuous loop for monitoring and controlling the shooter.
        while (true)
        {
		// Check if the shooter is currently firing (velocity greater than 0).
		if (velocity(rpm) > 0) 
		{
			// If the shooter is moving, stop it using brake mode.
			shooter_Group.stop(vex::brakeType::brake);
		}
		// Check if the shooter is at or below the loaded position.
		else if (position(pct) <= 0)
		{
			// If the shooter is at or below the loaded position, stop it using brake mode.
			shooter_Group.stop(vex::brakeType::brake);
		}
		// If none of the above conditions are met, reverse the shooter motors to draw the shooter back
		else
		{
			shooter_Group.spin(fwd, -MAX_MOTOR_VOLTAGE, vex::voltageUnits::mV);
		}
		// Wait for a short duration (10 milliseconds) before the next iteration.
		wait(10, msec);
        }
        // The function will never return as it's in an infinite loop.
        return 0;
}


int shooterObj::shooterDrawFunctionStatic(void* instance)
{
        // Execute the non-static member function shooterDrawFunction on the specified instance of the shooterObj class
        // This is achieved by casting the instance pointer back to a shooterObj*, then calling the shooterDrawFunction with a nullptr argument.
        return static_cast<shooterObj*>(instance)->shooterDrawFunction(nullptr);
}


void shooterObj::startAutoDrawTask()
{
        // Start a VEX task for automatically drawing the shooter back.
        // The task is assigned the static member function shooterDrawFunctionStatic
        // with the current instance of the shooterObj class (this) as an argument.
        shooterDrawTask = vex::task(shooterDrawFunctionStatic, this);
}

void shooterObj::stopAutoDrawTask()
{
        // Stop the task responsible for automatically drawing the shooter back.
        shooterDrawTask.stop();
}

void shooterObj::manualDraw()
{
	int startTime = vex::timer::system();
	// Loop until the shooter is drawn back past the loaded position or the timeout is reached
	while (!isLoaded() && vex::timer::system() - startTime < 1000 * timeout) {
		// Check if the shooter is currently moving (velocity greater than 0).
		if (velocity(rpm) > 0) {
			// If the shooter is moving, stop it using brake mode.
			shooter_Group.stop(vex::brakeType::brake);
		} else {
			// If the shooter is not moving, reverse the shooter motors
			// to draw the shooter back using a predefined maximum motor voltage.
			shooter_Group.spin(fwd, -MAX_MOTOR_VOLTAGE, vex::voltageUnits::mV);
		}
		// Wait for a short duration (10 milliseconds) before the next iteration.
		wait(10, msec);
	}
	// Stop the shooter motors once drawing is completed or the timeout is reached.
	shooter_Group.stop(vex::brakeType::brake);
}

void shooterObj::manualDraw(bool aSync)
{
	if (aSync) {

	}
	else
	{
		manualDraw();
	}
}


void shooterObj::shoot (bool aSync)
{
	if (aSync) {
		// Add code for asynchronous manual draw if needed later
	}
	else
	{
		shoot();
	}
}

void shooterObj::shoot ()
{
	// ensures the draw task is not running while the shooter is firing
	shooterDrawTask.suspend();
	
	int startTime = vex::timer::system();
	// Loop until the shooter has reached the top position and is not moving or the timeout is reached
	while (isLoaded() && velocity(rpm) <= 0 && vex::timer::system() - startTime < 1000 * timeout) {
		// Check if the shooter is currently moving (velocity greater than 0).
		if (velocity(rpm) > 0) {
			// If the shooter is moving, stop it using brake mode.
			shooter_Group.stop(vex::brakeType::brake);
		} else {
			// If the shooter is not moving, reverse the shooter motors
			// to draw the shooter back using a predefined maximum motor voltage.
			shooter_Group.spin(fwd, -MAX_MOTOR_VOLTAGE, vex::voltageUnits::mV);
		}
		// Wait for a short duration (10 milliseconds) before the next iteration.
		wait(10, msec);
	}
	// Stop the shooter motors once drawing is completed or the timeout is reached.
	shooter_Group.stop(vex::brakeType::brake);
	// resumes the draw task if it was running
	shooterDrawTask.resume();
}

double shooterObj::position (vex::percentUnits units) {
        // find the range of the shooter
        double maximumAngle = UNLOADED_POSITION - LOADED_POSITION;
        // find the relative position of the shooter within in the range
        double currentAngle = (*shooterRotationSensor).position(deg) - LOADED_POSITION;
        // find the percentage of the shooter's relative postition to the total range
        double percentAngle = currentAngle / maximumAngle;
        // return the value
        return percentAngle;
}

double shooterObj::position (vex::rotationUnits units) {
        return (*shooterRotationSensor).position(units);
}

double shooterObj::velocity (vex::velocityUnits units) {
        return (*shooterRotationSensor).velocity(units);
}

bool shooterObj::isLoaded () {
        return position(pct) <= 0;
}

bool shooterObj::isMoving () {
        return velocity(rpm) != 0;
}