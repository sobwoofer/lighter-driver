// CONNECTIONS:
// DS1302 DAT/IO --> 4
// DS1302 CLK/SCLK --> 0
// DS1302 RST/CE --> 2
// DS1302 VCC --> 3.3v - 5v
// DS1302 GND --> GND

#include <ThreeWire.h>  
#include <RtcDS1302.h>

ThreeWire myWire(CLOCK_DAT, CLOCK_CLK, CLOCK_RST); // IO, SCLK, CE
RtcDS1302<ThreeWire> Rtc(myWire);

#define countof(a) (sizeof(a) / sizeof(a[0]))

bool isTime(const RtcDateTime& dt, const char* time)
{
    char datestring[20];

    snprintf_P(datestring, 
            countof(datestring),
            PSTR("%02u:%02u:%02u"),
            dt.Hour(),dt.Minute(),dt.Second());


    return strcmp(datestring, time) == 0; // if 0 that time are equal and return true
}

void printDateTime(const RtcDateTime& dt)
{
    char datestring[20];

    snprintf_P(datestring, 
            countof(datestring),
            PSTR("%02u/%02u/%04u %02u:%02u:%02u"),
            dt.Month(),
            dt.Day(),
            dt.Year(),
            dt.Hour(),
            dt.Minute(),
            dt.Second() );
    Serial.print(datestring);
}

void setupClock()
{
    Rtc.Begin();
    //RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
    //Rtc.SetDateTime(compiled);
    printDateTime(Rtc.GetDateTime());
}

// sample input: date = "Dec 06 2009", time = "12:34:56"
void setTime(const char* date, const char* time) {
    
    printDateTime(Rtc.GetDateTime());

    RtcDateTime compiled = RtcDateTime(date, time);
    printDateTime(compiled);

    Serial.println();

    if (!Rtc.IsDateTimeValid()) 
    {
        // Common Causes:
        //    1) first time you ran and the device wasn't running yet
        //    2) the battery on the device is low or even missing

        Serial.println("RTC lost confidence in the DateTime!");
        Rtc.SetDateTime(compiled);
    }

    if (Rtc.GetIsWriteProtected())
    {
        Serial.println("RTC was write protected, enabling writing now");
        Rtc.SetIsWriteProtected(false);
    }

    if (!Rtc.GetIsRunning())
    {
        Serial.println("RTC was not actively running, starting now");
        Rtc.SetIsRunning(true);
    }

    RtcDateTime now = Rtc.GetDateTime();
    if (now < compiled) 
    {
        Serial.println("RTC is older than compile time!  (Updating DateTime)");
        Rtc.SetDateTime(compiled);
    }
    else if (now > compiled) 
    {
        Serial.println("RTC is newer than compile time. (this is expected)");
    }
    else if (now == compiled) 
    {
        Serial.println("RTC is the same as compile time! (not expected but all is fine)");
    }
}


