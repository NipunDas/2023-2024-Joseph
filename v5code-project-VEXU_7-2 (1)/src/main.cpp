#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration ****SMALL BOT****:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// intake               motor         20              
// L1                   motor         6               
// L2                   motor         7               
// L3                   motor         8               
// R1                   motor         16              
// R2                   motor         17              
// R3                   motor         18              
// inertialSensor       inertial      19              
// climber              digital_out   A               
// wings                digital_out   B               
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;
competition Competition;

/*---------------------------------------------------------------------------*/
/*                             VEXcode Config                                */
/*                                                                           */
/*  Before you do anything else, start by configuring your motors and        */
/*  sensors using the V5 port icon in the top right of the screen. Doing     */
/*  so will update robot-config.cpp and robot-config.h automatically, so     */
/*  you don't have to. Ensure that your motors are reversed properly. For    */
/*  the drive, spinning all motors forward should drive the robot forward.   */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                             JAR-Template Config                           */
/*                                                                           */
/*  Where all the magic happens. Follow the instructions below to input      */
/*  all the physical constants and values for your robot. You should         */
/*  already have configured your robot manually with the sidebar configurer. */
/*---------------------------------------------------------------------------*/

Drive chassis(

//Specify your drive setup below. There are seven options:
//ZERO_TRACKER_NO_ODOM, ZERO_TRACKER_ODOM, TANK_ONE_ENCODER, TANK_ONE_ROTATION, TANK_TWO_ENCODER, TANK_TWO_ROTATION, HOLONOMIC_TWO_ENCODER, and HOLONOMIC_TWO_ROTATION
//For example, if you are not using odometry, put ZERO_TRACKER_NO_ODOM below:
ZERO_TRACKER_ODOM,

//Add the names of your Drive motors into the motor groups below, separated by commas, i.e. motor_group(Motor1,Motor2,Motor3).
//You will input whatever motor names you chose when you configured your robot using the sidebar configurer, they don't have to be "Motor1" and "Motor2".

//Left Motors:
motor_group(L1,L2,L3),

//Right Motors:
motor_group(R1,R2,R3),

//Specify the PORT NUMBER of your inertial sensor, in PORT format (i.e. "PORT1", not simply "1"):
PORT19,

//Input your wheel diameter. (4" omnis are actually closer to 4.125"):
3.25,

//External ratio, must be in decimal, in the format of input teeth/output teeth.
//If your motor has an 84-tooth gear and your wheel has a 60-tooth gear, this value will be 1.4.
//If the motor drives the wheel directly, this value is 1:
0.6,

//Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
//For most cases 360 will do fine here, but this scale factor can be very helpful when precision is necessary.
360,

/*---------------------------------------------------------------------------*/
/*                                  PAUSE!                                   */
/*                                                                           */
/*  The rest of the drive constructor is for robots using POSITION TRACKING. */
/*  If you are not using position tracking, leave the rest of the values as  */
/*  they are.                                                                */
/*---------------------------------------------------------------------------*/

//If you are using ZERO_TRACKER_ODOM, you ONLY need to adjust the FORWARD TRACKER CENTER DISTANCE.

//FOR HOLONOMIC DRIVES ONLY: Input your drive motors by position. This is only necessary for holonomic drives, otherwise this section can be left alone.
//LF:      //RF:    
PORT1,     -PORT2,

//LB:      //RB: 
PORT3,     -PORT4,

//If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the chassis).
//If this is a rotation sensor, enter it in "PORT1" format, inputting the port below.
//If this is an encoder, enter the port as an integer. Triport A will be a "1", Triport B will be a "2", etc.
3,

//Input the Forward Tracker diameter (reverse it to make the direction switch):
2.75,

//Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
//For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
//This distance is in inches:
-2,

//Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
1,

//Sideways tracker diameter (reverse to make the direction switch):
-2.75,

//Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
5.5

);

int current_auton_selection = 6;
bool auto_started = false;

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  default_constants();

  while(auto_started == false){            //Changing the names below will only change their names on the
    Brain.Screen.clearScreen();            //brain screen for auton selection.
    switch(current_auton_selection){       //Tap the brain screen to cycle through autons.
      case 0:
        Brain.Screen.printAt(50, 50, "AWP");
        break;
      case 1:
        Brain.Screen.printAt(50, 50, "AWP");
        break;
      case 2:
        Brain.Screen.printAt(50, 50, "Turn Test");
        break;
      case 3:
        Brain.Screen.printAt(50, 50, "Swing Test");
        break;
      case 4:
        Brain.Screen.printAt(50, 50, "Prog Skills");
        break;
      case 5:
        Brain.Screen.printAt(50, 50, "Odom Test");
        break;
      case 6:
        Brain.Screen.printAt(50, 50, "Tank Odom Test");
        break;
      case 7:
        Brain.Screen.printAt(50, 50, "Holonomic Odom Test");
        break;
    }
    if(Brain.Screen.pressing()){
      while(Brain.Screen.pressing()) {}
      current_auton_selection ++;
    } else if (current_auton_selection == 8){
      current_auton_selection = 1;
    }
    task::sleep(10);
  }
}

void autonomous(void) {
  auto_started = true;
  switch(current_auton_selection){  
    case 0:
      drive_test(); //This is the default auton, if you don't select from the brain.
      break;        //Change these to be your own auton functions in order to use the auton selector.
    case 1:         //Tap the screen to cycle through autons.
      drive_test();
      break;
    case 2:
      turn_test();
      break;
    case 3:
      swing_test();
      break;
    case 4:
      full_test();
      break;
    case 5:
      odom_test();
      break;
    case 6:
      tank_odom_test();
      break;
    case 7:
      holonomic_odom_test();
      break;
 }
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

bool status = false;
bool climberState = false;
void toggleWings() {
  status = !status;
  wings.set(status);
}

void toggleClimber() {
  climberState = !climberState;
  climber.set(climberState);
}

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    //Replace this line with chassis.control_tank(); for tank drive 
    //or chassis.control_holonomic(); for holo drive.
    /*
    if (Controller1.ButtonR1.pressing()) 
    {
      wings.set(false);
    }
    if (Controller1.ButtonR2.pressing()) 
    {
      wings.set(true);
    }
    if (Controller1.ButtonX.pressing()) 
    {
      climber.set(true);
    }
    if (Controller1.ButtonB.pressing()) 
    {
      climber.set(false);
    }*/
    
    //chassis.control_arcade();

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

void updateDrivetrainVelocity()
{
  int leftVelocity = (Controller1.Axis3.position() + (Controller1.Axis1.position()/1.5)) * 120;
  int rightVelocity = (Controller1.Axis3.position() - (Controller1.Axis1.position()/1.5)) * 120;

  motor_group(L1,L2,L3).spin(vex::forward, leftVelocity, vex::voltageUnits::mV);
  motor_group(R1,R2,R3).spin(vex::forward, rightVelocity, vex::voltageUnits::mV);
}

void onevent_Controller1ButtonL1_pressed_0() {
  intake.setVelocity(100.0, percent);
  intake.spin(forward);
}

// "when Controller1 ButtonL2 pressed" hat block
void onevent_Controller1ButtonL2_pressed_0() {
  intake.setVelocity(100.0, percent);
  intake.spin(reverse);
}

// "when Controller1 ButtonL2 released" hat block
void onevent_Controller1ButtonL2_released_0() {
  intake.setVelocity(20.0, percent);
  intake.spin(forward);
}

// "when Controller1 ButtonY pressed" hat block
void onevent_Controller1ButtonY_pressed_0() {
  intake.stop();
}

// "when Controller1 ButtonA pressed" hat block
void onevent_Controller1ButtonA_pressed_0() {
  intake.setVelocity(50.0, percent);
  intake.spin(forward);
}


int main() {
  // register event handlers
  Controller1.ButtonR1.pressed(toggleWings);
  Controller1.ButtonX.pressed(toggleClimber);
  Controller1.ButtonL1.pressed(onevent_Controller1ButtonL1_pressed_0);
  Controller1.ButtonL2.pressed(onevent_Controller1ButtonL2_pressed_0);
  Controller1.ButtonL2.released(onevent_Controller1ButtonL2_released_0);
  Controller1.ButtonY.pressed(onevent_Controller1ButtonY_pressed_0);
  Controller1.ButtonA.pressed(onevent_Controller1ButtonA_pressed_0);
  Controller1.Axis1.changed(updateDrivetrainVelocity);
  Controller1.Axis3.changed(updateDrivetrainVelocity);


  /*}
//
// Main will set up the competition functions and callbacks.
//
int main() {*/
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  //Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
