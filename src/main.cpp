/* 
  Bras Mécanique en SPI - Danse
  
  Programme basique sur Arduino UNO
  IDE Visual Studio Code 1.95.2
  
  Constituants :
  -  Bras mécanique Braccio
  -  Adruino UNO avec shield associé

  Version 2 : 05/12/2024

  - Benoit BOREK
  - Mathis BENOIT
  - Alban de Farcy de Pontfarcy
  - Noam Sanoussi
*/
#include <Braccio.h>
#include <Servo.h>

Servo base;
Servo shoulder;
Servo elbow;
Servo wrist_rot;
Servo wrist_ver;
Servo gripper;

int time = 10; // Temps pour chaque mouvement (plus bas = plus rapide)

void setup() {
  Serial.begin(9600);
  Braccio.begin(); // Initialisation du bras
  Serial.println("Danse du Braccio commence !");
}

void loop() {
  // Mouvement 1 : Bras en position neutre
  Braccio.ServoMovement(time, 90, 90, 90, 90, 90, 10);
  delay(500);

  // Mouvement 2 : Rotation de la base
  Braccio.ServoMovement(time, 45, 90, 90, 90, 90, 10);
  delay(500);
  Braccio.ServoMovement(time, 135, 90, 90, 90, 90, 10);
  delay(500);
  Braccio.ServoMovement(time, 90, 90, 90, 90, 90, 10);
  delay(500);

  // Mouvement 3 : Épaule haut-bas
  Braccio.ServoMovement(time, 90, 45, 90, 90, 90, 10);
  delay(500);
  Braccio.ServoMovement(time, 90, 135, 90, 90, 90, 10);
  delay(500);
  Braccio.ServoMovement(time, 90, 90, 90, 90, 90, 10);
  delay(500);

  // Mouvement 4 : Coude plié-déplié
  Braccio.ServoMovement(time, 90, 90, 45, 90, 90, 10);
  delay(500);
  Braccio.ServoMovement(time, 90, 90, 135, 90, 90, 10);
  delay(500);
  Braccio.ServoMovement(time, 90, 90, 90, 90, 90, 10);
  delay(500);

  // Mouvement 5 : Rotation et inclinaison du poignet
  Braccio.ServoMovement(time, 90, 90, 90, 45, 45, 10);
  delay(500);
  Braccio.ServoMovement(time, 90, 90, 90, 135, 135, 10);
  delay(500);
  Braccio.ServoMovement(time, 90, 90, 90, 90, 90, 10);
  delay(500);

  // Mouvement 6 : Ouverture et fermeture de la pince
  Braccio.ServoMovement(time, 90, 90, 90, 90, 90, 0);
  delay(500);
  Braccio.ServoMovement(time, 90, 90, 90, 90, 90, 10);
  delay(500);

  // Pause avant de recommencer
  delay(1000);
}
