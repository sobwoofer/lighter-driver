
#include <Arduino.h>
#include <gpio_setup.h>
#include <ArduinoJson.h>

#include <fireplace_driver.h>
#include <captive_portal.h>

void setup() {
  //Serial.begin(115200);
  gpio_setup();
  setupFireplaceDriver();
  setupCaptivePortal();

}

void loop() {
  loopCaptivePortal();  
  processLighting();
}