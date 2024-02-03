#include "vex.h"

void default_constants(){
  chassis.set_drive_constants(10, 1.5, 0, 10, 0);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .3, .03, 3, 15);
  chassis.set_swing_constants(12, .4, .01, 4, 15);
  chassis.set_drive_exit_conditions(1.5, 300, 1500);
  chassis.set_turn_exit_conditions(1, 300, 3000);
  chassis.set_swing_exit_conditions(1, 300, 3000);

  inertialSensor.calibrate();
  wait(2, seconds);
}

void odom_constants(){
  default_constants();
  chassis.drive_max_voltage = 8;
  chassis.drive_settle_error = 3;
}

void drive_test(){
  
  // Calibrate inertial sensor
  //inertialSensor.calibrate();
  //wait(2, seconds);
  //spit out preload
  //wait to let other robot get out of the way
  //wait(2, seconds);
  //get close right triball and close center triball and shoot them over into the alley
  intake.setVelocity(100, percent);
  intake.spin(reverse);
  wait(0.3, seconds);
  intake.spin(forward);
  flyTop.setVelocity(200, rpm);
  flyTop.spin(forward);
  flyBottom.setVelocity(280, rpm);
  flyBottom.spin(forward);
  chassis.turn_to_angle(-90);
  chassis.drive_distance(20);
  chassis.turn_to_angle(0);
  chassis.drive_distance(15);
  chassis.turn_to_angle(-105);
  chassis.drive_distance(15);
  wait(0.2, seconds);
  chassis.drive_distance(-5);
  chassis.turn_to_angle(-93);
  flyTop.setVelocity(240, rpm);
  flyBottom.setVelocity(320, rpm);
  chassis.drive_distance(13);
  wait(0.2, seconds);
  chassis.drive_distance(-5);
  //push any over the bar that didn't make it
  wings.set(true);
  wait(0.3, seconds);
  chassis.drive_distance(-25);
  //wait(0.3, seconds);
  wings.set(false);
  chassis.drive_distance(10);
  chassis.turn_to_angle(180);
  wings.set(true);
  chassis.drive_distance(-12);
  //get the middle right and middle middle triballs and shoot them over the bar into the alley
  chassis.drive_distance(5);
  wings.set(false);
  chassis.right_swing_to_angle(-80);
  chassis.drive_distance(10);
  //wait(0.2, seconds);
  chassis.drive_distance(-5);
  //wait(0.2, seconds);
  chassis.drive_distance(15);
  //wait(0.2, seconds);
  chassis.drive_distance(-5);
  //wait(0.2, seconds);
  //get alliance triball from match load zone
  chassis.right_swing_to_angle(-45);
  chassis.turn_to_angle(135);
  //get rid of any triballs in the way
  flyTop.setVelocity(70, percent);
  flyBottom.setVelocity(80, percent);
  flyTop.setBrake(brake);
  flyBottom.setBrake(brake);
  //wait(0.3, seconds);
  chassis.drive_distance(42);
  flyTop.stop();
  flyBottom.stop();
  wait(0.7, seconds);
  flyTop.setVelocity(10, percent);
  flyTop.spin(reverse);
  flyBottom.setVelocity(5, percent);
  flyBottom.spin(reverse);
  chassis.drive_distance(18);
  wait(0.5, seconds);
  //score alliance triball in goal
  chassis.drive_distance(-5);
  chassis.turn_to_angle(255);
  chassis.drive_distance(6);
  intake.spin(reverse);
  //wait(0.3, seconds);
  chassis.drive_distance(-6);
  chassis.turn_to_angle(45);
  chassis.drive_distance(-10);
  chassis.right_swing_to_angle(90);
  //double score to make sure we have it in the goal
  //chassis.drive_distance(-10);
  //.drive_distance(10);
  chassis.drive_distance(-15);
  chassis.drive_distance(8);
  chassis.turn_to_angle(0);
  //plow all the triballs under the bar to far side of the field
  chassis.drive_distance(-10);
  chassis.left_swing_to_angle(40);
  chassis.drive_distance(12);
  chassis.turn_to_angle(235);
  chassis.drive_distance(-8);
  chassis.turn_to_angle(180);
  chassis.drive_distance(-42);




  




  
  //THIS AUTON IS FOR THE FIELD SET UP WRONG!!! DO NOT USE!!!!
  
  /*
  // Calibrate inertial sensor
  inertialSensor.calibrate();
  wait(2, seconds);
  //spit out preload
  //wait to let other robot get out of the way
  //wait(2, seconds);
  intake.setVelocity(100, percent);
  intake.spin(reverse);
  wait(0.5, seconds);
  //get left middle triball
  intake.spin(forward);
  flyTop.setVelocity(10, percent);
  flyTop.spin(reverse);
  flyBottom.setVelocity(5, percent);
  flyBottom.spin(reverse);
  chassis.turn_to_angle(-90);
  chassis.drive_distance(35);
  chassis.turn_to_angle(-52);
  chassis.drive_distance(6.5);
  //shove two over the bar with wings
  chassis.drive_distance(-2);
  chassis.turn_to_angle(-150);
  wings.set(true);
  chassis.drive_distance(-13);
  chassis.right_swing_to_angle(-90);
  chassis.drive_distance(-15);
  //outtake ball in intake over the bar
  chassis.drive_distance(12);
  wings.set(false);
  chassis.turn_to_angle(75);
  intake.spin(reverse);
  //chassis.drive_distance(3);
  wait(0.3, seconds);
  //grab middle middle triball
  chassis.turn_to_angle(-60);
  intake.spin(forward);
  chassis.drive_distance(15);
  //score triball in intake over the short barrier bar
  chassis.turn_to_angle(75);
  chassis.drive_distance(12);
  intake.spin(reverse);
  wait(0.5, seconds);
  chassis.set_drive_constants(10, 1.5, 0, 10, 0);
  chassis.drive_distance(-12);
  //use wings to get both triballs over the bar
  chassis.turn_to_angle(0);
  wings.set(true);
  chassis.turn_to_angle(-90);
  wait(0.3, seconds);
  chassis.drive_distance(-22);
  chassis.drive_distance(5);
  wings.set(false);
  //get triball in match load zone
  chassis.turn_to_angle(180);
  intake.spin(forward);
  chassis.drive_distance(13);
  chassis.turn_to_angle(135);
  intake.spin(forward);
  //get rid of any triballs in the way
  flyTop.setVelocity(70, percent);
  flyBottom.setVelocity(80, percent);
  flyTop.setBrake(brake);
  flyBottom.setBrake(brake);
  wait(0.5, seconds);
  chassis.drive_distance(20);
  flyTop.stop();
  flyBottom.stop();
  wait(0.5, seconds);
  flyTop.setVelocity(10, percent);
  flyTop.spin(reverse);
  flyBottom.setVelocity(5, percent);
  flyBottom.spin(reverse);
  chassis.drive_distance(12);
  wait(0.7, seconds);
  //score alliance triball in goal
  chassis.drive_distance(-5);
  chassis.turn_to_angle(255);
  chassis.drive_distance(6);
  intake.spin(reverse);
  wait(0.3, seconds);
  chassis.drive_distance(-6);
  chassis.turn_to_angle(45);
  chassis.drive_distance(-8);
  chassis.right_swing_to_angle(90);
  //double score to make sure we have it in the goal
  //chassis.drive_distance(-10);
  //chassis.drive_distance(10);
  chassis.drive_distance(-15);
  chassis.drive_distance(8);
  chassis.turn_to_angle(0);
  //plow all the triballs under the bar to far side of the field
  chassis.drive_distance(-15);
  chassis.left_swing_to_angle(40);
  chassis.drive_distance(12);
  chassis.turn_to_angle(235);
  chassis.drive_distance(-8);
  chassis.turn_to_angle(180);
  chassis.drive_distance(-95);*/
}

void turn_test(){
  // Calibrate inertial sensor
  inertialSensor.calibrate();
  wait(2, seconds);
  chassis.turn_to_angle(5);
  chassis.turn_to_angle(30);
  chassis.turn_to_angle(90);
  chassis.turn_to_angle(225);
  chassis.turn_to_angle(0);
}

void swing_test(){
  // Calibrate inertial sensor
  inertialSensor.calibrate();
  wait(2, seconds);
  chassis.right_swing_to_angle(45);
  chassis.left_swing_to_angle(90);
  chassis.left_swing_to_angle(45);
  chassis.right_swing_to_angle(0);
  chassis.right_swing_to_angle(90);
  chassis.left_swing_to_angle(0);

}

void full_test(){

  flyTop.setVelocity(70, percent);
  flyBottom.setVelocity(80, percent);
  flyBottom.spin(forward);
  flyTop.spin(forward);
  intake.setVelocity(100, percent);
  intake.spin(forward);

  while(1){
  
  chassis.drive_distance(-7);
  wait(0.7, seconds);
  chassis.drive_distance(8);
  wait(0.5, seconds);

  }


  
  


  /*chassis.drive_distance(24);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(-36);
  chassis.right_swing_to_angle(-90);
  chassis.drive_distance(24);
  chassis.turn_to_angle(0);*/
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