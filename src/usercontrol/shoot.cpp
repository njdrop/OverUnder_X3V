#include "vex.h"
#include "library.h"
using namespace vex;

void shoot() {
        //is switch state button pressed
        if (con.ButtonR2.pressing()) {
                //switch to pto state
                state = 2;
        }
}