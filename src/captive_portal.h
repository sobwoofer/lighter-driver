#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <html.h>

const byte DNS_PORT = 53;
const String SSID = "FIREPLACE";
IPAddress apIP(172, 217, 28, 1);
DNSServer dnsServer;
ESP8266WebServer webServer(80);


void redFire()
{
    Serial.println("red fire");
    selectColor(COLOR_RED);
    webServer.send(200, "text/html", responseHTML);
}

void greenFire()
{
    Serial.println("green fire");
    selectColor(COLOR_GREEN);
    webServer.send(200, "text/html", responseHTML);
}

void blueFire()
{
    Serial.println("blue fire");
    selectColor(COLOR_BLUE);
    webServer.send(200, "text/html", responseHTML);
}

void yellowFire()
{
    Serial.println("yellow fire");
    selectColor(COLOR_YELLOW);
    webServer.send(200, "text/html", responseHTML);
}

void brightHigh()
{
    Serial.println("bright high");
    selectBrightness(BRIGHTNESS_HIGH);
    webServer.send(200, "text/html", responseHTML);
}

void brightMedium()
{
    Serial.println("bright medium");
    selectBrightness(BRIGHTNESS_MEDIUM);
    webServer.send(200, "text/html", responseHTML);
}

void brightLow()
{
    Serial.println("bright low");
    selectBrightness(BRIGHTNESS_LOW);
    webServer.send(200, "text/html", responseHTML);
}

void lightTypeFire()
{
    Serial.println("type fire");
    selectLightType(LIGHT_TYPE_FIRE);
    webServer.send(200, "text/html", responseHTML);
}

void lightTypeOcean()
{
    Serial.println("type ocean");
    selectLightType(LIGHT_TYPE_OCEAN);
    webServer.send(200, "text/html", responseHTML);
}

void lightTypeStrips()
{
    Serial.println("type strips");
    selectLightType(LIGHT_TYPE_STRIPS);
    webServer.send(200, "text/html", responseHTML);
}

void lightTypeTemperature()
{
    Serial.println("type temperature");
    selectLightType(LIGHT_TYPE_TEMPERATURE);
    webServer.send(200, "text/html", responseHTML);
}

void soundTypeFire()
{
    Serial.println("sound fire");
    selectSoundType(SOUND_FIRE);
    webServer.send(200, "text/html", responseHTML);
}

void soundTypeForest()
{
    Serial.println("sound forest");
    selectSoundType(SOUND_FOREST);
    webServer.send(200, "text/html", responseHTML);
}

void soundTypeSea()
{
    Serial.println("sound sea");
    selectSoundType(SOUND_SEA);
    webServer.send(200, "text/html", responseHTML);
}

void soundTypeRain()
{
    Serial.println("sound rain");
    selectSoundType(SOUND_RAIN);
    webServer.send(200, "text/html", responseHTML);
}


// void handleCss() {
//     File file = SPIFFS.open("/style.css", "r");
//     webServer.streamFile(file, "text/css");
//     file.close();
// }

void setupCaptivePortal() {
    WiFi.mode(WIFI_AP);
     WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
     WiFi.softAP(SSID);

    // if DNSServer is started with "*" for domain name, it will reply with
     // provided IP to all DNS request
     dnsServer.start(DNS_PORT, "*", apIP);
     //add style
    //  webServer.on("/style.css", handleCss);
    
    webServer.on("/red", redFire);
    webServer.on("/green", greenFire);
    webServer.on("/blue", blueFire);
    webServer.on("/yellow", yellowFire);

     webServer.on("/bright_low", brightLow);
     webServer.on("/bright_medium", brightMedium);
     webServer.on("/bright_high", brightHigh);

     webServer.on("/light_fire", lightTypeFire);
     webServer.on("/light_ocean", lightTypeOcean);
     webServer.on("/light_strips", lightTypeStrips);
     webServer.on("/light_temperature", lightTypeTemperature);

     webServer.on("/sound_fire", soundTypeFire);
     webServer.on("/sound_forest", soundTypeForest);
     webServer.on("/sound_sea", soundTypeSea);
     webServer.on("/sound_rain", soundTypeRain);

     // replay to all requests with same HTML
     webServer.onNotFound([]() {
            webServer.send(200, "text/html", responseHTML);
        });
  webServer.begin();
}

void loopCaptivePortal() {
    dnsServer.processNextRequest();
    webServer.handleClient();
}