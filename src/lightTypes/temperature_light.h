
#define TEMPERATURE_1 Tungsten100W
#define TEMPERATURE_2 OvercastSky
// How many seconds to show each temperature before switching
#define DISPLAYTIME 20
// How many seconds to show black between switches
#define BLACKTIME   3

void setupTemperatureLight() {
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalSMD5050 );
}

void temperatureLightLoop()
{
  // draw a generic, no-name rainbow
  static uint8_t starthue = 0;
  fill_rainbow( leds, NUM_LEDS, --starthue, 20);

  // Choose which 'color temperature' profile to enable.
  uint8_t secs = (millis() / 1000) % (DISPLAYTIME * 2);
  if( secs < DISPLAYTIME) {
    FastLED.setTemperature( TEMPERATURE_1 ); // first temperature
    // leds[0] = TEMPERATURE_1; // show indicator pixel
  } else {
    FastLED.setTemperature( TEMPERATURE_2 ); // second temperature
    // leds[0] = TEMPERATURE_2; // show indicator pixel
  }

  // Black out the LEDs for a few secnds between color changes
  // to let the eyes and brains adjust
//   if( (secs % DISPLAYTIME) < BLACKTIME) {
//     memset8( leds, 0, NUM_LEDS * sizeof(CRGB));
//   }
  
  FastLED.show();
  FastLED.delay(8);
}