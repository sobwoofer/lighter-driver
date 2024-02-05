#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

#define SOUND_FIRE  0
#define SOUND_FOREST  1
#define SOUND_SEA  2
#define SOUND_CITY  3

int volume = 0;
int soundType = SOUND_FIRE;

SoftwareSerial mySoftwareSerial(PIN_MP3_RX, PIN_MP3_TX); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

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

int getVolume()
{
    return analogRead(VOLUME)/34;
}

void playSound()
{
    myDFPlayer.stop();
    myDFPlayer.disableLoop();
    myDFPlayer.volume(getVolume());
    switch (soundType)
    {
    case SOUND_FIRE:
      myDFPlayer.play(1);
      break;
    case SOUND_FOREST:
      myDFPlayer.play(2);
      break;
    case SOUND_SEA:
      myDFPlayer.play(3);
      break;
    case SOUND_CITY:
      myDFPlayer.play(4);
      break;
    
    default:
     myDFPlayer.play(1);
    }
    myDFPlayer.enableLoop();
}

void selectSoundType(int newSoundType) {
  soundType = newSoundType;
  playSound();
}

void stopSound()
{
    myDFPlayer.stop();
}

void playerLoop()
{
      if (volume != getVolume()) {
        volume = getVolume();
        myDFPlayer.volume(volume);
    }
}