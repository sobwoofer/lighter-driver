#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h" //playerV1


#define SOUND_FIRE  1
#define SOUND_BIRDS  2
#define SOUND_SEA  3
#define SOUND_RAIN  4
#define SOUND_CRICKETS  5
#define SOUND_JUNGLE  6
#define SOUND_CHIKENS  7
#define SOUND_TRAIN  8
#define SOUND_FROGS  9

int volume = 0;
int soundType = SOUND_FIRE;

unsigned long previousMillisReplay = 0;        // Зберігає останній час, коли ми оновили таймер
const long intervalReplay = 1200000; // Інтервал для перезапуску TODO 20 min

SoftwareSerial mySoftwareSerial(PIN_MP3_RX, PIN_MP3_TX); // RX, TX
DFRobotDFPlayerMini myDFPlayer; // playerV1

int getVolume()
{
    return analogRead(VOLUME)/34;
}

void playSound()
{
    // playerV1
    myDFPlayer.stop();
    myDFPlayer.volume(getVolume());
    myDFPlayer.enableLoop();

    myDFPlayer.play(soundType);
    myDFPlayer.loop(soundType);

    
}

void setupPlayer() 
{
  soundType = param(PARAM_SOUND_TYPE).toInt();
  // Serial.println("Sound type: ");
  // Serial.println(soundType);
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);

  // Start communication with DFPlayer Mini playerV1
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
        myDFPlayer.volume(volume); // playerV1
    }
}