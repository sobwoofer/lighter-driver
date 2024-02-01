#include <ESP8266mDNS.h>
#ifdef ESP8266
void onSTAConnected(WiFiEventStationModeConnected ipInfo)
{
    Serial.printf("Connected to %s\r\n", ipInfo.ssid.c_str());
}

void onSTAGotIP(WiFiEventStationModeGotIP ipInfo)
{
    Serial.printf("Got IP: %s\r\n", ipInfo.ip.toString().c_str());
    Serial.printf("Connected: %s\r\n", WiFi.status() == WL_CONNECTED ? "yes" : "no");
    get_ip = true;
    led_mode = 1;
    ip_addres = WiFi.localIP().toString();
}

void onSTADisconnected(WiFiEventStationModeDisconnected event_info)
{
    Serial.printf("Disconnected from SSID: %s\n", event_info.ssid.c_str());
    Serial.printf("Reason: %d\n", event_info.reason);
}
#else
void WiFiEvent(WiFiEvent_t event, system_event_info_t info)
{
    switch (event)
    {
    case SYSTEM_EVENT_STA_START:
        Serial.println(F("Station Mode Started"));
        break;
    case SYSTEM_EVENT_STA_GOT_IP:
        Serial.println("Connected to :" + String(WiFi.SSID()));
        Serial.print("Got IP: ");
        Serial.println(WiFi.localIP());
        get_ip = true;
        led_mode = 1;
        break;
    case SYSTEM_EVENT_STA_DISCONNECTED:
        Serial.println(F("Disconnected from station, attempting reconnection"));
        WiFi.reconnect();
        break;
    default:
        break;
    }
}
#endif

void wifi_connect()
{
    int wifi_mode = param(F("wifi_mode")).toInt();
    switch (wifi_mode)
    {
        case 1:
        {
            WiFi.mode(WIFI_OFF);
            WiFi.mode(WIFI_AP);
            //wifi_station_set_hostname("feeder.local");
            WiFi.softAP("PetFeeder");

            Serial.println(WiFi.softAPIP());
            WiFi.setAutoConnect(true);
            //WiFi.setHostname("feeder-server.pp.ua"); //TODO test it

            
            //MDNS.begin("feeder.local", WiFi.softAPIP());
            //wifi_station_set_hostname("feeder.local");
            //MDNS.addService("http", "tcp", 80); //TODO https

            Serial.println(WiFi.getHostname());
            Serial.println(F("Start Wi-Fi AP mode!"));
            break;
        }
        case 2:
        {
#ifdef ESP8266
            static WiFiEventHandler e1, e2, e3;
            e1 = WiFi.onStationModeGotIP(onSTAGotIP);
            e2 = WiFi.onStationModeDisconnected(onSTADisconnected);
            e3 = WiFi.onStationModeConnected(onSTAConnected);
#else
            WiFi.onEvent(WiFiEvent);
#endif
            WiFi.mode(WIFI_OFF);
            WiFi.mode(WIFI_STA);
            WiFi.begin(param(F("ssid")).c_str(), param(F("pass")).c_str());
            Serial.println(F("Connecting STA"));
            led_mode = 3;
            
            while (WiFi.status() != WL_CONNECTED && millis() - timing_wifi_connect < 10000)//Try to connect to wifi 10 sec
            {
                delay(1);
                gpio_handle();
            }
            if (WiFi.status() == WL_CONNECTED) {
                Serial.println();
                WiFi.scanNetworks(true);
                wifiMode = 2;
            }
            
            break;
        }
    }
}

void wifi_scan()
{
    int n = WiFi.scanComplete();
    page_content += F("<div class=\"list-group\" id=\"list-tab\" role=\"tablist\">");
    if (n == WIFI_SCAN_FAILED)
        WiFi.scanNetworks(true);
    else if (n)
    {
        for (int i = 0; i < n; ++i)
        {
            //page_content += F("<tr><th scope=\"row\">");
            //page_content += String(i + 1);
            page_content += F("<a href='javascript:selssid(\"");
            page_content += WiFi.SSID(i);
            page_content += F("\")' class=\"list-group-item list-group-item-action\">");
            page_content += WiFi.SSID(i);
            page_content += F("</a>");
            //page_content += String(WiFi.channel(i));
            //page_content += F("</td><td>");
            //page_content += String(WiFi.RSSI(i));
            //page_content += F("</td></tr>");
        }
        WiFi.scanDelete();
        if (WiFi.scanComplete() == WIFI_SCAN_FAILED)
        {
            WiFi.scanNetworks(true);
        }
    }
    page_content += F("</div><input type=\"button\" value=\"Search Wi-Fi\" onclick=\"page_update(");
    page_content += current_page;
    page_content += F(");\" class=\"btn btn-outline-dark btn-lg btn-block mt-3\"><br>");
}

String ipToString(IPAddress ip)
{
    String s = "";
    for (int i = 0; i < 4; i++)
        s += i ? "." + String(ip[i]) : String(ip[i]);
    return s;
}

bool ap_sta_con = false;

void wifi_con()
{
    if (ap_sta_con)
        return;
    ap_sta_con = true;
    save_param();
    WiFi.mode(WIFI_AP_STA);
    WiFi.begin(param(F("ssid")).c_str(), param(F("pass")).c_str());
    Serial.println(F("Connecting STA"));
}

void statrt_handle()
{
    if (!get_ip)
        return;
    if (restart_timer + restart_interval > millis())
        return;
    save_flag = true;
    save_param();
    ESP.restart();
}
