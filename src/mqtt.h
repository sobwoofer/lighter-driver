#include <PubSubClient.h>

//Enter your mqtt server configurations
char* subscribeTopic = "lighter/"; //Password
char* deviceId = "6"; //Password 4779040221497
const char* mqttServer = "mesquiteskull658.cloud.shiftr.io";    //Enter Your mqttServer address
const int mqttPort = 1883;       //Port number
const char* mqttUser = "mesquiteskull658"; //User
const char* mqttPassword = "1nfmHhq7dqekivIm"; //Password

WiFiClient espClient;
PubSubClient mqtt_client(espClient);

void mqtt_setup() {

  if (WiFi.status() != WL_CONNECTED) {
      if (millis() - timing_wifi_connect > 1000) {
        Serial.println("WiFi is disconnected");        
        timing_wifi_connect = millis();
      }
      led_mode = 3; //connecting to wifi
      return;
  } else {
    led_mode = 1; //connected
  }

  Serial.print("Connected to WiFi :");
  Serial.println(WiFi.SSID());


  if (!mqtt_client.connected() && millis() - timing_mqtt_connect > 1000) {
    mqtt_client.setServer(mqttServer, mqttPort);
    Serial.println("Connecting to MQTT...");

    if (mqtt_client.connect("ESP8266", mqttUser, mqttPassword )) {
        Serial.println("connected");
        //char topic[20];
        //snprintf_P(topic, countof(topic), PSTR("%02u/%02u"), subscribeTopic, deviceId);
        mqtt_client.subscribe(strcat(subscribeTopic, deviceId)); //topic = feeder/12
    } else {
      Serial.print("failed with state ");
      Serial.println(mqtt_client.state());  //If you get state 5: mismatch in configuration
      timing_mqtt_connect = millis();
    }
  }
 
}

void publish(const char* command, int status, const char* data = "")
{
  //create json
  DynamicJsonBuffer jsonBuffer;
    JsonObject& root = jsonBuffer.createObject();
    root["type"] = command;
    root["feeder_id"] = deviceId;
    root["status"] = status;
    root["data"] = data;

    char message[100];
    root.printTo((char*)message, root.measureLength() + 1);
    
  mqtt_client.publish("lighter/server", message); //TODO encode json
}