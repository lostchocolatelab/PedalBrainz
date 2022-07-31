// change these to match your hardware setup
// https://codebender.cc/sketch:102327#FastLed%20Breath.ino
//#define LED_PIN 6                          // hardware SPI pin SCK
//#define NUM_LEDS 2
//#define COLOR_ORDER RGB
//#define LED_TYPE WS2811
//#define MIN_BRIGHTNESS 8                   // watch the power!
//#define MAX_BRIGHTNESS 128                   // watch the power!
 
//struct CRGB leds[NUM_LEDS];
 
/*void setup()
{
    LEDS.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
    FastLED.setBrightness(MAX_BRIGHTNESS);
    FastLED.clear();
    fill_solid(leds, NUM_LEDS, CRGB::White);
}*/
 
void breather1() {

  for (int p = 0; p < strip.numPixels(); p++) {       // For each pixel in strip...
      strip.setPixelColor(p, 100, 2, 20);
    }
    pixel.setPixelColor(0, 36, 0, 12);
    inner.setPixelColor(0, 36, 0, 100);

    maxBrightnessAdjust();
    checkButtons();

    fadeSpeed = map(analogRead(A0), 0, 1024, 0, 5000);
    darkDelay = map(analogRead(A2), 0, 1024, 0, 100); 
  
 //float breath = (exp(sin(millis()/2000.0*PI)) - 0.36787944)*108.0;
 float breath = (exp(sin(millis()/fadeSpeed*PI)) - 0.36787944)*darkDelay;
 breath = map(breath, 0, 255, 0, maxBrightness);
 FastLED.setBrightness(breath);

 averageLEDS();
 FastLED.show(); 
  
}