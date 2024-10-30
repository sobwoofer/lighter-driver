#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>

const byte DNS_PORT = 53;
const String SSID = "LUCERNA";
IPAddress apIP(172, 217, 28, 1);
DNSServer dnsServer;
ESP8266WebServer webServer(80);


void redFire()
{
    Serial.println("red fire");
    selectColor(COLOR_RED);
    webServer.send(200, "text/html", "OK");
}

void greenFire()
{
    Serial.println("green fire");
    selectColor(COLOR_GREEN);
    webServer.send(200, "text/html", "OK");
}

void blueFire()
{
    Serial.println("blue fire");
    selectColor(COLOR_BLUE);
    webServer.send(200, "text/html", "OK");
}

void yellowFire()
{
    Serial.println("yellow fire");
    selectColor(COLOR_YELLOW);
    webServer.send(200, "text/html", "OK");
}

void brightHigh()
{
    Serial.println("bright high");
    selectBrightness(BRIGHTNESS_HIGH);
    webServer.send(200, "text/html", "OK");
}

void brightMedium()
{
    Serial.println("bright medium");
    selectBrightness(BRIGHTNESS_MEDIUM);
    webServer.send(200, "text/html", "OK");
}

void brightLow()
{
    Serial.println("bright low");
    selectBrightness(BRIGHTNESS_LOW);
    webServer.send(200, "text/html", "OK");
}

void lightSpeedLow()
{
    Serial.println("light speed low");
    selectLightSpeed(LIGHT_SPEED_LOW);
    webServer.send(200, "text/html", "OK");
}

void lightSpeedMedium()
{
    Serial.println("light speed medium");
    selectLightSpeed(LIGHT_SPEED_MEDIUM);
    webServer.send(200, "text/html", "OK");
}

void lightSpeedHigh()
{
    Serial.println("light speed high");
    selectLightSpeed(LIGHT_SPEED_HIGH);
    webServer.send(200, "text/html", "OK");
}

void lightTypeFire()
{
    Serial.println("type fire");
    selectLightType(LIGHT_TYPE_FIRE);
    webServer.send(200, "text/html", "OK");
}

void lightTypeOcean()
{
    Serial.println("type ocean");
    selectLightType(LIGHT_TYPE_OCEAN);
    webServer.send(200, "text/html", "OK");
}

void lightTypeStrips()
{
    Serial.println("type strips");
    selectLightType(LIGHT_TYPE_STRIPS);
    webServer.send(200, "text/html", "OK");
}

void lightTypeTemperature()
{
    Serial.println("type temperature");
    selectLightType(LIGHT_TYPE_TEMPERATURE);
    webServer.send(200, "text/html", "OK");
}

void soundTypeFire()
{
    Serial.println("sound fire");
    selectSoundType(SOUND_FIRE);
    webServer.send(200, "text/html", "OK");
}

void soundTypeBirds()
{
    Serial.println("sound birds");
    selectSoundType(SOUND_BIRDS);
    webServer.send(200, "text/html", "OK");
}

void soundTypeSea()
{
    Serial.println("sound sea");
    selectSoundType(SOUND_SEA);
    webServer.send(200, "text/html", "OK");
}

void soundTypeRain()
{
    Serial.println("sound rain");
    selectSoundType(SOUND_RAIN);
    webServer.send(200, "text/html", "OK");
}

void soundTypeCrickets()
{
    Serial.println("sound crickets");
    selectSoundType(SOUND_CRICKETS);
    webServer.send(200, "text/html", "OK");
}

void soundTypeJungle()
{
    Serial.println("sound jungle");
    selectSoundType(SOUND_JUNGLE);
    webServer.send(200, "text/html", "OK");
}

void soundTypeChikens()
{
    Serial.println("sound chikens");
    selectSoundType(SOUND_CHIKENS);
    webServer.send(200, "text/html", "OK");
}

void soundTypeTrain()
{
    Serial.println("sound train");
    selectSoundType(SOUND_TRAIN);
    webServer.send(200, "text/html", "OK");
}

void soundTypeFrogs()
{
    Serial.println("sound frogs");
    selectSoundType(SOUND_FROGS);
    webServer.send(200, "text/html", "OK");
}

void handleLangEn()
{
    Serial.println("language EN");
    write_param(PARAM_LANG, String("en"));
    save_flag = true;
    save_param();
    webServer.send(200, "text/html", "OK");
}

void handleLangUk()
{
    Serial.println("language UK");
    write_param(PARAM_LANG, String("uk"));
    save_flag = true;
    save_param();
    webServer.send(200, "text/html", "OK");
}


void setupCaptivePortal() {
    WiFi.mode(WIFI_AP);
     WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
     WiFi.softAP(SSID);

    // if DNSServer is started with "*" for domain name, it will reply with
     // provided IP to all DNS request
     dnsServer.start(DNS_PORT, "*", apIP);
     //add style
    //  webServer.on("/style.css", handleCss);

    //  SPIFFS.begin(); // Запуск файлової системи

    // Налаштовуємо обробку запиту на файл JSON
    webServer.on("/lang.json", HTTP_GET, []() {
        File file = SPIFFS.open("/lang.json", "r");
        if (file) {
            webServer.streamFile(file, "application/json");
            file.close();
        } else {
            webServer.send(404, "text/plain", "File not found");
        }
    });

    // Обробка запиту для style.css
    webServer.on("/style.css", HTTP_GET, []() {
        File file = SPIFFS.open("/style.css", "r");
        if (file) {
        webServer.streamFile(file, "text/css");
        file.close();
        } else {
        webServer.send(404, "text/plain", "File not found");
        }
    });

    // Обробка запиту для main.js
    webServer.on("/main.js", HTTP_GET, []() {
        File file = SPIFFS.open("/main.js", "r");
        if (file) {
        webServer.streamFile(file, "text/javascript");
        file.close();
        } else {
        webServer.send(404, "text/plain", "File not found");
        }
    });
    
    webServer.on("/red", redFire);
    webServer.on("/green", greenFire);
    webServer.on("/blue", blueFire);
    webServer.on("/yellow", yellowFire);

     webServer.on("/bright_low", brightLow);
     webServer.on("/bright_medium", brightMedium);
     webServer.on("/bright_high", brightHigh);

    webServer.on("/speed_low", lightSpeedLow);
     webServer.on("/speed_medium", lightSpeedMedium);
     webServer.on("/speed_high", lightSpeedHigh);

     webServer.on("/light_fire", lightTypeFire);
     webServer.on("/light_ocean", lightTypeOcean);
     webServer.on("/light_strips", lightTypeStrips);
     webServer.on("/light_temperature", lightTypeTemperature);

     webServer.on("/sound_fire", soundTypeFire);
     webServer.on("/sound_birds", soundTypeBirds);
     webServer.on("/sound_sea", soundTypeSea);
     webServer.on("/sound_rain", soundTypeRain);

     webServer.on("/sound_crickets", soundTypeCrickets);
     webServer.on("/sound_jungle", soundTypeJungle);
     webServer.on("/sound_chikens", soundTypeChikens);
     webServer.on("/sound_train", soundTypeTrain);
     webServer.on("/sound_frogs", soundTypeFrogs);

     webServer.on("/lang_en", handleLangEn);
     webServer.on("/lang_uk", handleLangUk);

     // replay to all requests with same HTML
     webServer.onNotFound([]() {
            File file = SPIFFS.open("/index.html", "r");
            if (file) {
                // Читаємо файл у змінну
                String htmlContent = file.readString();
                file.close();

                // Заміна місця для мови у HTML
                htmlContent.replace("{LANG}", param(PARAM_LANG));  
                // Відправляємо HTML-контент клієнту
                webServer.send(200, "text/html", htmlContent);

                // webServer.streamFile(file, "text/html");
                // file.close();
            } else {
                webServer.send(404, "text/plain", "File not found");
            }
        });
  webServer.begin();
}

void loopCaptivePortal() {
    dnsServer.processNextRequest();
    webServer.handleClient();
}