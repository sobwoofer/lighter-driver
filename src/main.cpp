
#include <Arduino.h>
#include <gpio_setup.h>
#include <ArduinoJson.h>

#include <led_driver.h>
#include <player_driver.h>
#include <captive_portal.h>

int mainSwitcher = 0;

void setup() {
  Serial.begin(115200);
  gpio_setup();
  setupLightDriver();
  setupPlayer();
  setupCaptivePortal();

}

void loop() {
  loopCaptivePortal();  
  // processLighting();

  //if swittch on start playing and lighting
  if (!mainSwitcher && digitalRead(ACTION) == LOW) {
    mainSwitcher = 1;
    playSound();
  }

 //if swittch off stop playing and lighting
  if (mainSwitcher && digitalRead(ACTION) == HIGH) {
    mainSwitcher = 0;
    stopSound();
    lampOff();
  }

// Serial.println("loop main switcher: ");
// Serial.print(mainSwitcher);
  if (mainSwitcher) {
    lightLoop();
    playerLoop();
     Serial.println("loopLamp");
  }
}