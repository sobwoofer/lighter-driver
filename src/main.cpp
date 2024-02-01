#include <Arduino.h>
#include <ArduinoJson.h>
//#define RELEASE // Раскоментировать перед выпуском релиза. Это отключит вывод в серийный порт!
//TODO need to remove some delay() functions to program will faster, added vars with calculator ms insted
#define LED 16    // D0 led pin
#define BUTTON 0 // D3 button pin
#define LIGHT 2 //D4 

#define ACTION 13 //D7 action input
#define LED_PIN 5 //D1 led lamp
#define PIN_MP3_TX 12 //TX D6 Player TX Connects to module's RX 
#define PIN_MP3_RX 14 //RX D5 Connects to module's TX 

#define VOLUME 0 // A0 button pin


//#define LED_PIN 12 //D6 
//#define LED_PIN 15 //D8 led lamp
//#define SERVO_MIXER 4 //D2 motor2  //make with one pin motor
//#define HOLE_START 12 //D6 
//#define HOLE_END 14 //D5


//#define SPEAKER 13 //D7 ACTION
//#define MOTOR_1 14 //D5 motor1
//#define SERVO_MIXER 4 //D2 motor2  //make with one pin motor

//#define HOLE_END 14 //D5

unsigned long timing_wifi_connect;
unsigned long timing_mqtt_connect;
unsigned long timing_action_detection;

//#include <clock.h>
#include "html.h"
#include "mqtt.h"
#include "lighterDriver.h"



void setup() {
    timing_wifi_connect = millis();
    timing_action_detection = millis();
    framework();
    setupDriver(); //Setup drivers of actions
    Serial.println("driver set up");

}

void loop() {
  framework_handle();
  //TODO do mills instead delay https://arduinomaster.ru/program/arduino-delay-millis/
  String wifi_mode = param(F("wifi_mode"));
   Serial.print("wifi_mode: ");
    Serial.println(param(F("wifi_mode")));
    
  // if (wifi_mode == "2") { // if wifi client is connected
  //   if (!mqtt_client.connected()) { //TODO do process feedeng while try to connect
  //     // mqtt_setup();
  //   } else {
  //     mqtt_client.loop();
  //   }
  // } else {
  //   //AP router
  //   led_mode = 0;
  // }


  

  if (button_state) {       //Если нажали на кнопку //TODO make one portion when press button
    //makeOnePortion();
    // publish("make_portion", 1);
    //mqtt_client.publish("feeder/server", "portion");
  }
// loopLamp();
  processLighting();
  

}

