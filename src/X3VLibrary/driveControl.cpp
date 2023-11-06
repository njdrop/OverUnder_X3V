#include "vex.h"
using namespace vex;

void runAllMotors (double speed) 
{
                leftMotor1.spin(fwd, nearbyint(speed), vex::voltageUnits::mV);
                rightMotor1.spin(fwd, nearbyint(speed), vex::voltageUnits::mV);
                leftMotor2.spin(fwd, nearbyint(speed), vex::voltageUnits::mV);
                rightMotor2.spin(fwd, nearbyint(speed), vex::voltageUnits::mV);
                leftMotor3.spin(fwd, nearbyint(speed), vex::voltageUnits::mV);
                rightMotor3.spin(fwd, nearbyint(speed), vex::voltageUnits::mV);
                leftMotor4.spin(fwd, nearbyint(speed), vex::voltageUnits::mV);
                rightMotor4.spin(fwd, nearbyint(speed), vex::voltageUnits::mV);     
}

void stopAllMotors (vex::brakeType bType) 
{
                leftMotor1.stop(bType);
                rightMotor1.stop(bType);
                leftMotor2.stop(bType);
                rightMotor2.stop(bType);
                leftMotor3.stop(bType);
                rightMotor3.stop(bType);
                leftMotor4.stop(bType);
                rightMotor4.stop(bType);     
}


void driveStraight (double dist, double maxSpeed, double timeout) {
        double startPos = leftMotor1.position(deg);
        int startTime = vex::timer::system();
        MiniPID distanceControl = MiniPID(2000, 50, 1800);
        distanceControl.setOutputLimits(-120 * maxSpeed, 120 * maxSpeed);
        
        while ((vex::timer::system() - startTime) <= timeout*1000) 
        {
                double speed = distanceControl.getOutput(((leftMotor1.position(deg) - startPos)*3.1416/180*2.75), dist);
                printf("%f\n", ((leftMotor1.position(deg) - startPos)*3.1416/180*2.75) - dist);
                runAllMotors(speed);
                wait(20, msec);
        }
        stopAllMotors(brake);
}


