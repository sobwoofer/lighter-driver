#include <FastLED.h>

#define COLOR_ORDER GRB
#define CHIPSET     TM1829 //or WS2812 or TM1829
#define NUM_LEDS    10

#define BRIGHTNESS_HIGH  220
#define BRIGHTNESS_MEDIUM  110
#define BRIGHTNESS_LOW  30

#define COLOR_RED  0
#define COLOR_GREEN  1
#define COLOR_BLUE  2
#define COLOR_YELLOW  3

#define LIGHT_TYPE_FIRE  0
#define LIGHT_TYPE_TEMPERATURE  1
#define LIGHT_TYPE_STRIPS  2
#define LIGHT_TYPE_OCEAN  3

#define LIGHT_SPEED_LOW  1
#define LIGHT_SPEED_MEDIUM  2
#define LIGHT_SPEED_HIGH  3

bool gReverseDirection = false;

CRGB leds[NUM_LEDS];
CRGBPalette16 gPal;
TBlendType    currentBlending;

int colorType = COLOR_RED;
int lightType = LIGHT_TYPE_FIRE;
int brightnessType = BRIGHTNESS_HIGH;
int lightSpeed = LIGHT_SPEED_MEDIUM;

#include "lightTypes/fire_light.h"
#include "lightTypes/temperature_light.h"
//#include "lightTypes/color_pallete.h"
//#include "lightTypes/cylon.h"
#include "lightTypes/strips.h"
//#include "lightTypes/pacifica.h" // wifi not connect
#include "lightTypes/ocean_light.h"

void lampOff()
{
    FastLED.clearData();
    for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB::Black;
    }
    FastLED.show();
}

void selectBrightness(int newBrightness) {
  brightnessType = newBrightness;
  write_param(PARAM_BRIGHTNES_TYPE, String(brightnessType));
  save_flag = true;
  save_param();
  FastLED.setBrightness( brightnessType);
}

void selectLightSpeed(int newLightSpeed) {
  lightSpeed = newLightSpeed;
  write_param(PARAM_LIGHT_SPEED, String(lightSpeed));
  save_flag = true;
  save_param();
}

void selectColor(int newColor) {
  colorType = newColor;
  write_param(PARAM_COLOR_TYPE, String(colorType));
  save_flag = true;
  save_param();
}

void selectLightType(int newLightType) {
  lightType = newLightType;
  write_param(PARAM_LIGHT_TYPE, String(lightType));
  save_flag = true;
  save_param();
}

//init pins for motors
void setupLightDriver()
{  
  lightType = param(PARAM_LIGHT_TYPE).toInt();
  colorType = param(PARAM_COLOR_TYPE).toInt();
  lightSpeed = param(PARAM_LIGHT_SPEED).toInt();
  if (!param(PARAM_BRIGHTNES_TYPE).toInt()) {
    brightnessType = BRIGHTNESS_MEDIUM;
  } else {
    brightnessType = param(PARAM_BRIGHTNES_TYPE).toInt();   
  }
  
  FastLED.setBrightness( brightnessType);
  // setupColorPallete();
  // setupCylon();
  // setupPacifica();
  switch (lightType) {
    case LIGHT_TYPE_FIRE:
      setupFireLight();
      break;
    case LIGHT_TYPE_OCEAN:
      setupOceanLight();
      break;
    case LIGHT_TYPE_STRIPS:
      setupStripsLight();
      break;
    case LIGHT_TYPE_TEMPERATURE:
      setupTemperatureLight();
      break;
    default:
      setupFireLight();
      break;
  }
  

  lampOff();
  Serial.print("setup driver done");
}



void lightLoop()
{
    switch (lightType) {
    case LIGHT_TYPE_FIRE:
      fireLightLoop();
      break;
    case LIGHT_TYPE_OCEAN:
      oceanLoop();
      break;
    case LIGHT_TYPE_STRIPS:
      stripsLoop();
      break;
    case LIGHT_TYPE_TEMPERATURE:
      temperatureLightLoop();
      break;
    default:
      fireLightLoop();
      break;
  }

  // colorPalleteLoop();
  // cylonLoop();
  // pacificaLoop();
}
