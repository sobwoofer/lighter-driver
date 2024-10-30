void pacifica_loop();
void pacifica_deepen_colors();
void pacifica_add_whitecaps();
void pacifica_one_layer(CRGBPalette16& p, uint16_t cistart, uint16_t wavescale, uint8_t bri, uint16_t ioff);

// Визначення кастомних палітр
CRGBPalette16 bluePalette = CRGBPalette16(CRGB::Aqua, CRGB::Blue, CRGB::DarkBlue, CRGB::Violet);
CRGBPalette16 greenPalette = CRGBPalette16(CRGB::YellowGreen, CRGB::Green, CRGB::DarkGreen, CRGB::SeaGreen);
CRGBPalette16 redPalette = CRGBPalette16(CRGB::DarkRed, CRGB::Red, CRGB::Orange, CRGB::Red);
CRGBPalette16 yellowPalette = CRGBPalette16(CRGB::Yellow, CRGB::LightYellow, CRGB::Yellow, CRGB::GreenYellow);


void setupOceanLight() {
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
}

void oceanLoop() {
  pacifica_loop();
  FastLED.show();
  
  switch (lightSpeed)
  {
  case LIGHT_SPEED_LOW:
    FastLED.delay(1000 / 50);
    break;
  case LIGHT_SPEED_MEDIUM:
    FastLED.delay(1000 / 120);
    break;
  case LIGHT_SPEED_HIGH:
    FastLED.delay(1000 / 320);
    break;
  
  default:
    break;
  }
}

void pacifica_loop() {
  CRGBPalette16 currentPalette;
  switch (colorType) {
    case COLOR_BLUE:
      currentPalette = bluePalette;
      break;
    case COLOR_GREEN:
      currentPalette = greenPalette;
      break;
    case COLOR_RED:
      currentPalette = redPalette;
      break;
    case COLOR_YELLOW:
      currentPalette = yellowPalette;
      break;
    default:
      currentPalette = bluePalette;
      break;
  }

  static uint16_t sCIStart = 0, sCIEnd = 0;
  sCIStart += 1;
  sCIEnd += 3;
  uint16_t ciStart = sCIStart, ciEnd = sCIEnd;

  pacifica_deepen_colors();
  pacifica_add_whitecaps();

  uint16_t speed = 20; // Швидкість "хвиль"
  pacifica_one_layer(currentPalette, ciStart, speed, 240, 0);

  ciStart += 275; ciEnd += 275;
  pacifica_one_layer(currentPalette, ciStart, speed, 240, 0);

  ciStart += 275; ciEnd += 275;
  pacifica_one_layer(currentPalette, ciStart, speed, 240, 0);
}

void pacifica_deepen_colors() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i].blue = scale8(leds[i].blue,  145); 
    leds[i].green= scale8(leds[i].green, 200); 
    leds[i] |= CRGB( 2, 5, 7);
  }
}

void pacifica_add_whitecaps() {
  uint8_t basethreshold = 30;
  uint8_t wave = beat8(7);
  
  for (int i = 0; i < NUM_LEDS; i++) {
    uint8_t threshold = scale8(sin8(wave), 20) + basethreshold;
    wave += 7;
    uint8_t l = leds[i].getAverageLight();
    if (l > threshold) {
      uint8_t overage = l - threshold;
      uint8_t overage2 = qadd8(overage, overage);
      leds[i] |= CRGB(overage, overage2, qadd8(overage2, overage2));
    }
  }
}

void pacifica_one_layer(CRGBPalette16& p, uint16_t cistart, uint16_t wavescale, uint8_t bri, uint16_t ioff) {
  uint16_t ci = cistart, waveangle = ioff, wavescale_half = (wavescale / 2);
  
  for (int i = 0; i < NUM_LEDS; i++) {
    waveangle += 250;
    uint16_t s16 = sin16(waveangle) + wavescale_half;
    uint8_t cs = scale16by8(s16, 240);
    leds[i] = ColorFromPalette(p, ci + cs, bri);
    ci += 3;
  }
}