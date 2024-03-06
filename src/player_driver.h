#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

#define SOUND_FIRE  0
#define SOUND_FOREST  1
#define SOUND_SEA  2
#define SOUND_RAIN  3
#define SOUND_CRICKETS  4
#define SOUND_JUNGLE  5
#define SOUND_CHIKENS  6

int volume = 0;
int soundType = SOUND_FIRE;

unsigned long previousMillisReplay = 0;        // Зберігає останній час, коли ми оновили таймер
const long intervalReplay = 1200000; // Інтервал для перезапуску TODO 20 min

SoftwareSerial mySoftwareSerial(PIN_MP3_RX, PIN_MP3_TX); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

int getVolume()
{
    return analogRead(VOLUME)/34;
}

void playSound()
{
    myDFPlayer.stop();
    myDFPlayer.volume(getVolume());
    switch (soundType)
    {
    case SOUND_FIRE:
      myDFPlayer.play(1);//TODO 1,2,3
      myDFPlayer.loop(1);
      break;
    case SOUND_FOREST:
      myDFPlayer.play(2);
      myDFPlayer.loop(2);
      break;
    case SOUND_SEA:
      myDFPlayer.play(3);
      myDFPlayer.loop(3);
      break;
    case SOUND_RAIN:
      myDFPlayer.play(4);
      myDFPlayer.loop(4);
      break;
    
    default:
     myDFPlayer.play(1);
     myDFPlayer.loop(1);
    }
    myDFPlayer.enableLoop();
    
}

void setupPlayer() 
{
  soundType = param(PARAM_SOUND_TYPE).toInt();
  // Serial.println("Sound type: ");
  // Serial.println(soundType);
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);
  // Start communication with DFPlayer Mini
  if (myDFPlayer.begin(mySoftwareSerial)) {
   Serial.println("Player OK");
    
  } else {
    Serial.println("Connecting to DFPlayer Mini failed!");
    ESP.restart();
  }

  playSound();
}

void selectSoundType(int newSoundType) {
  soundType = newSoundType;
  write_param(PARAM_SOUND_TYPE, String(soundType));
  save_flag = true;
  save_param();
  playSound();
}

void stopSound()
{
    myDFPlayer.stop();
}

void playOneInWhile()
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillisReplay >= intervalReplay) {
    // Збережіть поточний час
    previousMillisReplay = currentMillis;

    // play again
    playSound();
  }
   
}

void playerLoop()
{
  playOneInWhile();
      if (volume != getVolume()) {
        volume = getVolume();
        myDFPlayer.volume(volume);
    }
}