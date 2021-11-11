#include <Arduino.h>
#include <ArduinoJson.h>
//#define RELEASE // Раскоментировать перед выпуском релиза. Это отключит вывод в серийный порт!
//TODO need to remove some delay() functions to program will faster, added vars with calculator ms insted
#define LED 16    // D0 led pin
#define BUTTON 0 // D3 button pin
#define ACTION 13 //D7 action input
#define LED_PIN 5 //D1 led lamp

//#define LED_PIN 12 //D6 
//#define LED_PIN 15 //D8 led lamp
//#define SERVO_MIXER 4 //D2 motor2  //make with one pin motor
//#define HOLE_START 12 //D6 
//#define HOLE_END 14 //D5

#define LIGHT 2 //D4 
#define PIN_MP3_TX 1 //TX Player TX Connects to module's RX 
#define PIN_MP3_RX 3 //RX Connects to module's TX 

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


void MQTTcallback(char* topic, byte* payload, unsigned int length) {
 
    Serial.print("Message arrived in topic: ");
    Serial.println(topic);
    Serial.print("Message:");

    String message;

    for (int i = 0; i < length; i++) {
      message = message + (char)payload[i];  //Conver *byte to String
    }
  
    Serial.print(message);

    DynamicJsonBuffer jsonBuffer;
    JsonObject& requestRoot = jsonBuffer.parseObject(message);

    String messageType = requestRoot["type"];


    //Set schedule config in flash memory
    if (messageType == "set_schedule") {
      Serial.println("set schedule action");
      write_param("schedule", requestRoot["data"]);
      save_flag = true;
      save_param();
      publish("set_schedule", 1);
    }

    //Set time in real-time clock
    if (messageType == "set_time") {
      Serial.println("set time action");
      //setTime(requestRoot["data"]["date"], requestRoot["data"]["time"]);
      publish("set_time", 1);
    }

    //Make one portion
    if (messageType == "make_portion") {
      Serial.println("make 1 portion");
      //makeOnePortion();
      publish("make_portion", 1);
    }

    //Send message to server that feeder online
    if (messageType == "health_check") {
      Serial.println("health check");
      publish("health_check", 1);
      //TODO send http request to server
    }
      
 
    Serial.println("-----------------------");
}

void setup() {
    timing_wifi_connect = millis();
    timing_mqtt_connect = millis();
    timing_action_detection = millis();
    framework();
    mqtt_setup();
    mqtt_client.setCallback(MQTTcallback);
    setupDriver(); //Setup drivers of actions
    //setupClock(); //Setup driver of clock
    Serial.println("driver set up");
}

void loop() {
  framework_handle();
  //TODO do mills instead delay https://arduinomaster.ru/program/arduino-delay-millis/
  String wifi_mode = param(F("wifi_mode"));
  if (wifi_mode == "2") { // if wifi client is connected
    if (!mqtt_client.connected()) { //TODO do process feedeng while try to connect
      mqtt_setup();
    } else {
      mqtt_client.loop();
    }
  } else {
    //AP router
    led_mode = 0;
  }

  

  if (button_state) {       //Если нажали на кнопку //TODO make one portion when press button
    //makeOnePortion();
    publish("make_portion", 1);
    //mqtt_client.publish("feeder/server", "portion");
  }

  processLighting();
  

}

