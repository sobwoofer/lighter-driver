#define NUM_STRIPS 3

CRGB stripColor;

// For mirroring strips, all the "special" stuff happens just in setup.  We
// just addLeds multiple times, once for each strip
void setupStripsLight() {
  // tell FastLED there's 60 NEOPIXEL leds on pin 2, starting at index 0 in the led array
  FastLED.addLeds<CHIPSET,LED_PIN,COLOR_ORDER>(leds, 0, NUM_LEDS);

}

void setStripsColor() {
if (colorType == COLOR_RED) {
    stripColor = CRGB::Red;
  }

  if (colorType == COLOR_GREEN) {
   stripColor = CRGB::Green;
  }

  if (colorType == COLOR_BLUE) {
    stripColor = CRGB::Blue;
  }

  if (colorType == COLOR_YELLOW) {
    stripColor = CRGB::Yellow;
  }
}

void stripsLoop() {
    setStripsColor();
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = stripColor;
    FastLED.show();
    leds[i] = CRGB::Black;
    if (NUM_LEDS-1 != i) {
        delay(100);
    }
  }

  for(int i = NUM_LEDS-1; i > 0; i--) {
    leds[i] = stripColor;
    FastLED.show();
    leds[i] = CRGB::Black;
    delay(100);
  }
}
