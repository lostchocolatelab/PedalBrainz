// Lumenati Alien Garden https://learn.sparkfun.com/tutorials/lumenati-alien-garden-/upload-the-code


void alienGardenz() { 

  maxBrightnessAdjust();
  checkButtons();

  fadeSpeed = map(analogRead(A0), 0, 1024, 300, 0);
  darkDelay = map(analogRead(A2), 0, 1024, 0, 300); 
  delayA2(darkDelay);

  // set the length for delays and initial brightness for each flower
  uint8_t x;
  uint16_t wait = 50;
  uint8_t flower1 = 75;
  uint8_t flower2 = 255;
  uint8_t flower3 = 75;


    //To bring them to life, I'm dimming and brightening the LEDs to make them "pulse"
    //a little bit. Flower1 will get progressively brighter, while Flower2 gets dimmer.
    while (flower1 < 255)
      {
        flower1++;
        flower2--;
        leds[0].setHSV( 192, 255 , flower1 );
        leds[1].setHSV( 96, 255 , flower1 );
        leds[2].setHSV( 192, 255 , flower1 );
        FastLED.show();
        averageLEDS();
        delayA0(fadeSpeed);
      }


    //Once flower1 is at max brightness, they'll reverse, and flower1 will grow dimmer
    //while flower2 grows brighter.
     while (flower1 > 75)
      {
        flower1--;
        flower2++;
        leds[0].setHSV( 192, 255 , flower1 );
        leds[1].setHSV( 96, 255 , flower1 );
        leds[2].setHSV( 192, 255 , flower1 );
        FastLED.show();
        averageLEDS();
        delayA0(fadeSpeed);
      }


  FastLED.show();
  averageLEDS();
  //delayA0(fadeSpeed);

}


void alienz1() { 


  int x = 1;

  for (int i = 0; i > -1; i = i + x)  //This fades the brightness in and out using maths
  {


    MaxBrightReduction = constrain(i, 0, MaxBright);

    //scalePixelBrightness(i);
    scalePixelRed(i);

    //A1 potentiometer controls for maximum brightness
    //maxBrightness = map(analogRead(A1), 0, 1024, 0, maxBrightnessTemp);
    MaxBrightReduction = constrain(maxBrightness, 0, MaxBright);
    pixel.setBrightness(maxBrightness);
    strip.setBrightness(MaxBrightReduction);
    FastLED.setBrightness(MaxBrightReduction);
    inner.setBrightness(maxBrightness);

    //for (int p = 0; p < strip.numPixels(); p++) {     // For each pixel in strip...
    for (int i = 0; i < NUM_LEDS; i++) {     // For each pixel in strip...
      //strip.setPixelColor(p, (i/5), 0, i);
      //strip.setPixelColor(p, (redValue), 0, redValue);
      leds[i] = CRGB(redValue, 0, redValue);
    }

    pixel.setPixelColor(0, redValue, 0, redValue);
    inner.setPixelColor(0, redValue, 0, redValue);

    showLEDS();
    FastLED.show();

    if (i == 255)                       //If the fade has reached it's peak keep the LED lit and then fade out
  {
    x = -1;
  }
}

}

void alienz2() { 

fadeAmount = 255;

 for(int i = 0; i < NUM_LEDS; i++ )
   {
   leds[i].setRGB(0,255,250);  // Set Color HERE!!!
   leds[i].fadeLightBy(brightness);
  }
  FastLED.show();
  brightness = brightness + fadeAmount;
  // reverse the direction of the fading at the ends of the fade: 
  if(brightness == 0 || brightness == 255)
  {
    fadeAmount = -fadeAmount ; 
  }    
  delay(0);  // This delay sets speed of the f

}