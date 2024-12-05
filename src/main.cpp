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
  Alban DeFarcy
  */
 
#include <Braccio.h>
#include <Servo.h>
#include <SPI.h>

Servo base;
Servo shoulder;
Servo elbow;
Servo wrist_rot;
Servo wrist_ver;
Servo gripper;

int objects = 2; // Cette variable va servir pour dire au robot dans qu'elle position il devra placer l'objet
volatile byte receivedData;

void setup() {
  SPI.begin(); // Initialisation en tant qu'esclave
  SPI.setClockDivider(SPI_CLOCK_DIV8); // Réglage de la vitesse du SPI
  pinMode(10, INPUT); // SS comme entrée
  SPI.attachInterrupt(); // Activer les interruptions SPI
  Serial.begin(9600);


Braccio.begin();
Serial.println("Start");
}

ISR(SPI_STC_vect) { // Interruption lorsqu'une donnée est reçue
  receivedData = SPDR; // SPDR contient les données reçues
}

void loop() {
 if (receivedData) {
    Serial.print("Reçu : ");
    Serial.println((char)receivedData);
       if((char)receivedData == 'H'){
      Braccio.ServoMovement(30, 90, 90, 180, 180, 90, 10);

    }

    receivedData = 0; // Réinitialiser après affichage

 
  }

//Placement du robot en position de capture
//Braccio.ServoMovement(30, 90, 90, 180, 180, 90, 10);


delay(5000);



  

  
 
  


}
