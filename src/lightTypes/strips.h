#define NUM_STRIPS 3

CRGB stripColor;

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
// For mirroring strips, all the "special" stuff happens just in setup.  We
// just addLeds multiple times, once for each strip
void setupStripsLight() {
  // tell FastLED there's 60 NEOPIXEL leds on pin 2, starting at index 0 in the led array
  FastLED.addLeds<CHIPSET,LED_PIN,COLOR_ORDER>(leds, 0, NUM_LEDS);
}



void stripsLoop() {
  setStripsColor();
  static int pixelPosition = 0; // Поточна позиція бігаючого пікселя
  static bool goingForward = true; // Напрямок руху пікселя

  // Згасання всіх світлодіодів для створення ефекту "хвоста"
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i].fadeToBlackBy(50);
  }

  // Встановлюємо колір для поточного пікселя
  leds[pixelPosition] = stripColor; // Ви можете змінити на будь-який колір

  // Оновлюємо позицію пікселя
  if (goingForward) {
    if (pixelPosition < NUM_LEDS - 1) {
      pixelPosition++;
    } else {
      goingForward = false; // Змінити напрямок
    }
  } else {
    if (pixelPosition > 0) {
      pixelPosition--;
    } else {
      goingForward = true; // Змінити напрямок
    }
  }

  // Показуємо оновлені світлодіоди
  FastLED.show();
  delay(100); // Керуємо швидкістю анімації
}