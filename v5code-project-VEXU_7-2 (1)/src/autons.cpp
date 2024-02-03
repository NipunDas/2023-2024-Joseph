#include "vex.h"

void default_constants(){
  chassis.set_drive_constants(10, 1.5, 0, 10, 0);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .4, .03, 3, 15);
  chassis.set_swing_constants(12, .35, .002, 2, 15);
  chassis.set_drive_exit_conditions(1.5, 300, 2000);
  chassis.set_turn_exit_conditions(1, 300, 3000);
  chassis.set_swing_exit_conditions(1, 300, 3000);
}

void odom_constants(){
  default_constants();
  chassis.drive_max_voltage = 8;
  chassis.drive_settle_error = 3;
}

void drive_test(){
  // Calibrate inertial sensor
  inertialSensor.calibrate();
  wait(2, seconds);
  //get alliance triball from match load zone
  intake.setVelocity(100, percent);
  intake.spin(reverse);
  wait(0.2, seconds);
  intake.spin(forward);
  wait(0.5, seconds);
  chassis.drive_distance(-45);
  chassis.left_swing_to_angle(315);
  wings.set(true);
  wait(0.3, seconds);
  chassis.drive_distance(-8);
  wings.set(false);
  wait(0.3, seconds);
  chassis.drive_distance(-5);
  //score alliance triball and the one that starts under the bar, then scores the one in the intake
  chassis.left_swing_to_angle(270);
  chassis.drive_distance(-12);
  chassis.drive_distance(8);
  chassis.turn_to_angle(0);
  chassis.turn_to_angle(90);
  chassis.drive_distance(12);
  //zero against the wall
  chassis.drive_distance(-10);
  chassis.turn_to_angle(0);
  chassis.drive_distance(-7);
  intake.spin(reverse);
  wait(0.5, seconds);
  intake.spin(forward);
  //grab the right middle triball, drop it next to the goal to score later
  chassis.drive_distance(20);
  chassis.turn_to_angle(25);
  chassis.drive_distance(25);
  chassis.drive_distance(-10);
  //spit out triball outside goal to score later
  intake.stop();
  chassis.turn_to_angle(145);
  chassis.drive_distance(13);
  intake.spin(reverse);
  wait(0.5, seconds);
  chassis.drive_distance(-13);
  //pick up middle middle triball, and score two with wings
  chassis.turn_to_angle(55);
  intake.spin(forward);
  chassis.drive_distance(23);
  chassis.drive_distance(-1);
  chassis.turn_to_angle(0);
  wings.set(true);
  wait(0.3, seconds);
  chassis.drive_distance(-25);
  chassis.drive_distance(10);
  wings.set(false);
  //score triball in intake
  chassis.turn_to_angle(180);
  chassis.drive_distance(18);
  //touch the bar
  chassis.set_drive_constants(5, 1.5, 0, 10, 0);
  chassis.drive_distance(-35);
  intake.spin(reverse);
  wait(0.3, seconds);
  intake.stop();
  chassis.drive_distance(2);
  chassis.turn_to_angle(-80);
  chassis.drive_distance(35);
  chassis.drive_distance(-4);
  chassis.turn_to_angle(-76);
  //chassis.turn_to_angle(-45);
  //chassis.drive_distance(35);


  /*chassis.drive_distance(6);
  chassis.drive_distance(12);
  chassis.drive_distance(18);
  chassis.drive_distance(-36);*/
}

void turn_test(){
  chassis.turn_to_angle(5);
  chassis.turn_to_angle(30);
  chassis.turn_to_angle(90);
  chassis.turn_to_angle(225);
  chassis.turn_to_angle(0);
}

void swing_test(){
  inertialSensor.calibrate();
  wait(2, seconds);
  chassis.right_swing_to_angle(45);
  chassis.left_swing_to_angle(90);
  chassis.left_swing_to_angle(45);
  chassis.right_swing_to_angle(0);


}

void full_test(){
  chassis.drive_distance(24);
}

void odom_test(){
  chassis.set_coordinates(0, 0, 0);
  while(1){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(0,50, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(0,70, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(0,90, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(0,110, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(0,130, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    task::sleep(20);
  }
}

void tank_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.turn_to_point(24, 24);
  chassis.drive_to_point(24,24);
  chassis.drive_to_point(0,0);
  chassis.turn_to_angle(0);
}

void holonomic_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.holonomic_drive_to_point(0, 18, 90);
  chassis.holonomic_drive_to_point(18, 0, 180);
  chassis.holonomic_drive_to_point(0, 18, 270);
  chassis.holonomic_drive_to_point(0, 0, 0);
}