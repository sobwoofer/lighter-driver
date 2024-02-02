#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>

const byte DNS_PORT = 53;
const String SSID = "FIREPLACE";
IPAddress apIP(172, 217, 28, 1);
DNSServer dnsServer;
ESP8266WebServer webServer(80);

String responseHTML = ""
                      "<!DOCTYPE html><html lang='en'><head>"
                      "<meta name='viewport' content='width=device-width'>"
                      "<title>Welcome to FirePlace</title></head><body>"
                      "<h1>Welcome to FirePlace</h1>"
                      " <a href='/red'>red</a> <a href='/green'>green</a> <a href='/blue'>blue</a>"
                      "</body></html>";

void redFire()
{
    Serial.println("red fire");
    color1 = CRGB::Black;
    color2 = CRGB::Red;
    color3 = CRGB::Yellow;
    setupLamp();
    webServer.send(200, "text/html", responseHTML);
}

void greenFire()
{
    Serial.println("green fire");
    color1 = CRGB::Black;
    color2 = CRGB::Green;
    color3 = CRGB::GreenYellow;
    setupLamp();
    webServer.send(200, "text/html", responseHTML);
}

void blueFire()
{
    Serial.println("blue fire");
    color1 = CRGB::Black;
    color2 = CRGB::Blue;
    color3 = CRGB::BlueViolet;
    setupLamp();
    webServer.send(200, "text/html", responseHTML);
}

void setupCaptivePortal() {
    WiFi.mode(WIFI_AP);
     WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
     WiFi.softAP(SSID);

    // if DNSServer is started with "*" for domain name, it will reply with
     // provided IP to all DNS request
     dnsServer.start(DNS_PORT, "*", apIP);
    
    webServer.on("/red", redFire);
    webServer.on("/green", greenFire);
    webServer.on("/blue", blueFire);
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