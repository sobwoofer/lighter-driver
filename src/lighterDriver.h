#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include "fireLight.h"

//Таймер для millis()
uint32_t timer = 0;

SoftwareSerial mySoftwareSerial(PIN_MP3_RX, PIN_MP3_TX); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

int lighterStatus = 0; // переменная для угла поворота микро серво


void setupPlayer() 
{
  // Start communication with DFPlayer Mini
  if (myDFPlayer.begin(mySoftwareSerial)) {
   Serial.println("Player OK");
    
    // Play the first MP3 file on the SD card
  } else {
    Serial.println("Connecting to DFPlayer Mini failed!");
  }

}

//init pins for motors
void setupDriver()
{
   // Init serial port for DFPlayer Mini
  mySoftwareSerial.begin(9600);
  setupPlayer();

  setupLamp();

  pinMode(ACTION, INPUT);
  //pinMode(SPEAKER, OUTPUT);
  pinMode(LIGHT, OUTPUT);

  //TODO setup RTC time driver
  Serial.print(__DATE__);
  Serial.println(__TIME__);

  Serial.print("setup driver done");
}



void turnOnLight() {
      digitalWrite(LIGHT, HIGH);

      myDFPlayer.volume(20);
      myDFPlayer.play(002);
      delay(1500);
      //myDFPlayer.stop();
      myDFPlayer.play(001);
}

void turnOffLight() {

  digitalWrite(LIGHT, LOW);
  lampOff();
   myDFPlayer.stop();
}

void processLighting() {


    if (digitalRead(ACTION) == HIGH && millis() - timing_action_detection > 2000) {
          lighterStatus = !lighterStatus;

          if (lighterStatus) {
              turnOnLight();
          } else {
              turnOffLight();
          }
          Serial.println("lighter status detected");
          timing_action_detection = millis();
    } else {
      //Serial.println("lighter status not detected");
    }

  if (lighterStatus) {
    loopLamp();
  }

}


