#include "vex.h"

/**
 * Resets the constants for auton movement.
 * Modify these to change the default behavior of functions like
 * drive_distance(). For explanations of the difference between
 * drive, heading, turning, and swinging, as well as the PID and
 * exit conditions, check the docs.
 */

void default_constants(){
  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
  chassis.set_drive_constants(10, 1.5, 0, 10, 0);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .4, .03, 3, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);

  // Each exit condition set is in the form of (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1.5, 300, 5000);
  chassis.set_turn_exit_conditions(1, 300, 3000);
  chassis.set_swing_exit_conditions(1, 300, 3000);
}

void simple_auto(){
  chassis.set_drive_constants(6, 5, 0, 1, 0);
  claw_intake.setVelocity(100,rpm);
  claw_wrist.setVelocity(20,rpm);
  claw_wrist.spinToPosition(90, degrees, false);
  chassis.drive_distance(25);
  claw_intake.spinFor(180, degrees, true);
  /*chassis.turn_to_angle(50); //don't know yet
  claw_wrist.spinToPosition(45, degrees, false);
  chassis.drive_distance(10); //don't know yet
  chassis.turn_to_angle(0); //don't know yet
  claw_intake.spinFor(-180, degrees, true);
  chassis.drive_distance(-10); //don't know yet
  chassis.turn_to_angle(0); //don't know yet
*/ 

}

void skills_auto()
{
  claw_wrist.setPosition(0,degrees);
  claw_intake.setVelocity(200,rpm);
  claw_wrist.setVelocity(20,rpm);
  cascade_1.setVelocity(200, rpm);
  cascade_2.setVelocity(200, rpm);
  chassis.set_drive_constants(8, 1.5, 0, 10, 0);
  chassis.set_drive_exit_conditions(1, 6, 2000);
  claw_wrist.spinToPosition(110, degrees, false);
  chassis.drive_distance(50);
  claw_intake.spinFor(180, degrees, true);
  claw_wrist.spinToPosition(150, degrees, false);
  wait(.5, seconds);
  chassis.drive_distance(-10);
  chassis.turn_to_angle(180, 8);
  claw_wrist.spinToPosition(75, degrees, false);
  chassis.drive_distance(30);
  chassis.turn_to_angle(168, 8);
  chassis.drive_distance(19);
  claw_intake.spinFor(forward, 400, degrees, false);
  wait(2, seconds);
  chassis.set_drive_constants(5, 1.5, 0, 10, 0);
  chassis.drive_distance(-3);
  chassis.turn_to_angle(180, 3);
  chassis.drive_distance(-50);
  chassis.set_turn_constants(3, 1.5, 0, 10, 0);
  chassis.turn_to_angle(50, 6);
  claw_wrist.spinToPosition(110, degrees, false);
  cascade_1.setTimeout(2,seconds);
  cascade_2.setTimeout(2,seconds);
  cascade_1.spinFor(forward,1900, degrees, false);
  cascade_2.spinFor(forward,1900, degrees, true);
  chassis.set_drive_constants(5, 1.5, 0, 10, 0);
  chassis.drive_distance(50);
  wait(3,seconds);
  claw_intake.setVelocity(100,rpm);
  claw_intake.spinFor(360, degrees, true);
  claw_wrist.setPosition(220,degrees);
  chassis.drive_distance(-5);
  // new code by JG
  /*
  chassis.turn_to_angle(38,6);
  cascade_1.spinFor(reverse,2000,degrees,false);
  cascade_2.spinFor(reverse,2000,degrees,false);
  chassis.drive_distance(-100);
  chassis.turn_to_angle(180,3);
  claw_wrist.spinToPosition(60,degrees,true);
  chassis.drive_distance(20);
  claw_intake.spinFor(forward,3000,degrees,false);
  wait(2,seconds);
  chassis.set_drive_constants(3, 1.5, 0, 10, 0);
  chassis.drive_distance(-3);
  chassis.turn_to_angle(180, 3);
  chassis.drive_distance(-20);
  chassis.turn_to_angle(38, 6);
  claw_wrist.spinToPosition(110, degrees, false);
  cascade_1.setTimeout(2,seconds);
  cascade_2.setTimeout(2,seconds);
  cascade_1.spinFor(forward,2800, degrees, false);
  cascade_2.spinFor(forward,2800, degrees, true);
  chassis.set_drive_constants(5, 1.5, 0, 10, 0);
  chassis.drive_distance(50);
  wait(3,seconds);
  claw_intake.spinFor(360, degrees, true);
  /*chassis.drive_distance(-60);
  chassis.turn_to_angle(-38, 6);
  */
  /*chassis.drive_distance(20);
  chassis.turn_to_angle(180, 3);
  chassis.drive_distance(3);
  chassis.set_drive_constants(3, 1.5, 0, 10, 0);
  */
  

  /*chassis.set_drive_constants(2, 1.5, 0, 10, 0);
  chassis.drive_distance(-40);
  chassis.set_drive_constants(5, 2, 0, 5, 0);
  chassis.set_drive_exit_conditions(1, 6, 3500);
  chassis.turn_to_angle(10, 5);
  chassis.drive_distance(5);
  chassis.turn_to_angle(30, 5);
  claw_wrist.spinToPosition(110, degrees, false);
  cascade_1.spinFor(forward,2000, degrees, false);
  cascade_2.spinFor(forward,2000, degrees, false);
  chassis.drive_distance(60);
*/
  /*cascade_1.spinFor(180, degrees, false);
  cascade_2.spinFor(180, degrees, true);
  cascade_1.spinFor(-180, degrees, false);
  cascade_2.spinFor(-180, degrees, true);*/
}

/**
 * Sets constants to be more effective for odom movements.
 * For functions like drive_to_point(), it's often better to have
 * a slower max_voltage and greater settle_error than you would otherwise.
 */

void odom_constants(){
  default_constants();
  chassis.heading_max_voltage = 10;
  chassis.drive_max_voltage = 8;
  chassis.drive_settle_error = 3;
  chassis.boomerang_lead = .5;
  chassis.drive_min_voltage = 0;
}

/**
 * The expected behavior is to return to the start position.
 */

void drive_test(){
  chassis.drive_distance(6);
  chassis.drive_distance(12);
  chassis.drive_distance(18);
  chassis.drive_distance(-36);
}

/**
 * The expected behavior is to return to the start angle, after making a complete turn.
 */

void turn_test(){
  chassis.turn_to_angle(5);
  chassis.turn_to_angle(30);
  chassis.turn_to_angle(90);
  chassis.turn_to_angle(225);
  chassis.turn_to_angle(0);
}

/**
 * Should swing in a fun S shape.
 */

void swing_test(){
  chassis.left_swing_to_angle(90);
  chassis.right_swing_to_angle(0);
}

/**
 * A little of this, a little of that; it should end roughly where it started.
 */

void full_test(){
  chassis.drive_distance(24);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(-36);
  chassis.right_swing_to_angle(-90);
  chassis.drive_distance(24);
  chassis.turn_to_angle(0);
}

/**
 * Doesn't drive the robot, but just prints coordinates to the Brain screen 
 * so you can check if they are accurate to life. Push the robot around and
 * see if the coordinates increase like you'd expect.
 */

void odom_test(){
  chassis.set_coordinates(0, 0, 0);
  while(1){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(5,20, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(5,40, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(5,60, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(5,80, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(5,100, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    vex::this_thread::sleep_for(20);
  }
}

/**
 * Should end in the same place it began, but the second movement
 * will be curved while the first is straight.
 */

void tank_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.turn_to_point(24, 24);
  chassis.drive_to_point(24,24);
  chassis.drive_to_point(0,0);
  chassis.turn_to_angle(0);
}

/**
 * Drives in a square while making a full turn in the process. Should
 * end where it started.
 */

void holonomic_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.holonomic_drive_to_pose(0, 18, 90);
  chassis.holonomic_drive_to_pose(18, 0, 180);
  chassis.holonomic_drive_to_pose(0, 18, 270);
  chassis.holonomic_drive_to_pose(0, 0, 0);
}