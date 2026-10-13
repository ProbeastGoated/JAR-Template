using namespace vex;

extern brain Brain;

//To set up a motor called LeftFront here, you'd use
//extern motor LeftFront;
extern controller Controller1;

extern motor FrontLeft;
extern motor BackLeft;
extern motor FrontRight;
extern motor BackRight;

extern motor intake_11;

extern motor cascade_1;
extern motor cascade_2;

extern motor claw_wrist;
extern motor claw_intake;

extern motor toggle_mech;
//Add your devices below, and don't forget to do the same in robot-config.cpp:
extern inertial Inertial;


void  vexcodeInit( void );