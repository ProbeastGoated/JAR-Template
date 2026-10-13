#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen.
brain  Brain;

//The motor constructor takes motors as (port, ratio, reversed), so for example
//motor LeftFront = motor(PORT1, ratio6_1, false);
controller Controller1;
// My controls
/*motor FrontLeft = motor(PORT12, ratio6_1, true);
motor FrontRight = motor(PORT19, ratio6_1, false);
motor BackLeft = motor(PORT3, ratio6_1, true);
motor BackRight = motor(PORT11, ratio6_1, false);
*/
motor FrontLeft = motor(PORT1, ratio6_1, true);
motor FrontRight = motor(PORT12, ratio6_1, false);
motor BackLeft = motor(PORT2, ratio6_1, true);
motor BackRight = motor(PORT11, ratio6_1, false);

motor intake_11 = motor(PORT3, ratio6_1, false);

motor cascade_1 = motor(PORT5, ratio18_1, true);
motor cascade_2 = motor(PORT9, ratio18_1, false);

motor claw_wrist = motor(PORT20, ratio36_1, false);
motor claw_intake = motor(PORT13, ratio18_1, false);

motor toggle_mech = motor(PORT14, ratio18_1, false);

inertial Inertial = inertial(PORT7);
//Add your devices below, and don't forget to do the same in robot-config.h:


void vexcodeInit( void ) {
  // nothing to initialize
}