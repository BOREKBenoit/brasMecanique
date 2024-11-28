
/*
  simpleMovements.ino

 This  sketch simpleMovements shows how they move each servo motor of Braccio

 Created on 18 Nov 2015
 by Andrea Martino

 This example is in the public domain.
 */

#include <Braccio.h>
#include <Servo.h>

Servo base;
Servo shoulder;
Servo elbow;
Servo wrist_rot;
Servo wrist_ver;
Servo gripper;

void setup() {
  //Initialization functions and set up the initial position for Braccio
  //All the servo motors will be positioned in the "safety" position:
  //Base (M1):90 degrees
  //Shoulder (M2): 45 degrees
  //Elbow (M3): 180 degrees
  //Wrist vertical (M4): 180 degrees
  //Wrist rotation (M5): 90 degrees
  //gripper (M6): 10 degrees
  Braccio.begin();
}

void loop() {
  // Placement du bras en position de capturer un objet
  Braccio.ServoMovement(30,          180,  45, 180, 180, 90, 10);
  Braccio.ServoMovement(30,          180,  95, 180, 180, 90, 10);
  delay(1000);

  // Capture de l'objet
  Braccio.ServoMovement(30,          180,  95, 180, 180, 90, 73);
  Braccio.ServoMovement(30,          180,  30, 180, 180, 90, 73);

  //Rotation du bras pour deposer l'objet ailleurs
  Braccio.ServoMovement(30,          90,  30, 180, 180, 90, 73);
  Braccio.ServoMovement(30,          90,  95, 180, 180, 90, 73);

  //Depot de l'objet
  Braccio.ServoMovement(30,          90,  95, 180, 180, 90, 10);
  
  delay(5000);
  
 
  


}
