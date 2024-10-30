#include "SoftwareSerial.h"
#include "DFPlayer.h" //playerV2


#define SOUND_FIRE  1
#define SOUND_BIRDS  3
#define SOUND_SEA  5
#define SOUND_RAIN  7
#define SOUND_CRICKETS  9
#define SOUND_JUNGLE  6
#define SOUND_CHIKENS  13
#define SOUND_TRAIN  15 
#define SOUND_FROGS  17

int volume = 0;
int soundType = SOUND_FIRE;

unsigned long previousMillisReplay = 0;        // Зберігає останній час, коли ми оновили таймер
const long intervalReplay = 1200000; // Інтервал для перезапуску TODO 20 min

SoftwareSerial mySoftwareSerial(PIN_MP3_RX, PIN_MP3_TX); // RX, TX
DFPlayer myDFPlayer; // playerV2

int getVolume()
{
    return analogRead(VOLUME)/34;
}

void playSound()
{

    //playerV2
    myDFPlayer.stop();
    myDFPlayer.setVolume(getVolume());

    myDFPlayer.playTrack(soundType);
    myDFPlayer.repeatCurrentTrack(true);

}

void setupPlayer() 
{
  soundType = param(PARAM_SOUND_TYPE).toInt();
  // Serial.println("Sound type: ");
  // Serial.println(soundType);
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);

  // Start communication with DFPlayer Mini playerV2
  myDFPlayer.begin(mySoftwareSerial); //playerV2

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
        myDFPlayer.setVolume(volume); // playerV2
    }
}