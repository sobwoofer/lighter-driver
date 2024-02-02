#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include "fireLight.h"


//Таймер для millis()
uint32_t timer = 0;

SoftwareSerial mySoftwareSerial(PIN_MP3_RX, PIN_MP3_TX); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

int lighterStatus = 0; // light status on off
int volume = 0;




void setupPlayer() 
{
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);
  // Start communication with DFPlayer Mini
  if (myDFPlayer.begin(mySoftwareSerial)) {
   Serial.println("Player OK");
    
  } else {
    Serial.println("Connecting to DFPlayer Mini failed!");
    ESP.restart();
  }
}

//init pins for motors
void setupFireplaceDriver()
{  
  setupPlayer();
  setupLamp();

  Serial.print("setup driver done");
}

int getVolume()
{
  return analogRead(VOLUME)/34;
}

void turnOnLight() {
    
      //play start fire sound
      myDFPlayer.volume(getVolume());
      myDFPlayer.play(2);
      myDFPlayer.enableLoop();
      //show start fire
      // Fire2012WithPalette();
      // FastLED.show();

      // delay(800);
      // myDFPlayer.stop();
      //play long fire sound
      
}

void turnOffLight() {

  // digitalWrite(LIGHT, LOW);
  lampOff();
   myDFPlayer.stop();
}

void processLighting() {

  if (volume != getVolume()) {
    volume = getVolume();
    myDFPlayer.volume(volume);
  }

// Serial.print("action is: ");
//   Serial.println(digitalRead(ACTION));

  if (!lighterStatus && digitalRead(ACTION) == LOW) {
    lighterStatus = 1;
    turnOnLight();
  }

  if (lighterStatus && digitalRead(ACTION) == HIGH) {
    lighterStatus = 0;
    turnOffLight();
  }


  if (lighterStatus) {
    loopLamp();
     Serial.println("loopLamp");
  }

}


