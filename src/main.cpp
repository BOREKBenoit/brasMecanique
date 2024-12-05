/* 
  Bras Mécanique en SPI
  
  Programme basique sur Arduino UNO
  IDE Visual Studio Code 1.95.2
  
  Constituants :
  -  Bras mécanique Braccio
  -  Adruino UNO avec shield associé

  Version 1 : 05/12/2024

  Benoit BOREK
  Mathis BENOIT
  Alban de Farcy de Pontfarcy
  */
 
#include <Braccio.h>
#include <Servo.h>


Servo base;
Servo shoulder;
Servo elbow;
Servo wrist_rot;
Servo wrist_ver;
Servo gripper;

int time = 5;

void setup() {

  Serial.begin(9600);

Braccio.begin();
Serial.println("Start");
}




void loop() {

      Braccio.ServoMovement(time, 90, 90, 180, 180, 90, 10);

      Braccio.ServoMovement(time, 90, 90, 180, 180, 90, 10);
      delay(50000);

      
      
      







  

  
 
  


}
