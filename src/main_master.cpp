/*
    Voici le programme pour la carte master qui va envoyer des caractères à l'aide du protocole SPI à la carte slave 
    qui va contrôler le bras

    Programme basique sur Arduino UNO
  Compilé sur Visual Studio Code v1.95.2
  Avec l'IDE PlatformIO v3.3.3
  
  Constituants :
  -  Bras mécanique Braccio
  -  Adruino UNO avec shield associé

  Version 1 : 05/12/2024

  -  Benoit BOREK
  -  Mathis BENOIT
  -   Alban de Farcy de Pontfarcy
*/

#include <Arduino.h>
#include <Braccio.h>
#include <SPI.h>
#include <Servo.h>

#define MISO 12
#define MOSI 11
#define SCK 13
#define CS 10

void setup(){
    SPI.begin(); // Initialisation en tant qu'esclave
  SPI.setClockDivider(SPI_CLOCK_DIV8); // Réglage de la vitesse du SPI
  pinMode(CS, INPUT);           // CS comme entrée
  pinMode(MISO, INPUT);         //MISO en tant qu'input (Master Input Slave Output)
  pinMode(MOSI, OUTPUT);        //MOSI en tant qu'output (Master Output Slave Input)
  

  SPI.attachInterrupt(); // Activer les interruptions SPI
  Serial.begin(9600);
}

void loop(){

}