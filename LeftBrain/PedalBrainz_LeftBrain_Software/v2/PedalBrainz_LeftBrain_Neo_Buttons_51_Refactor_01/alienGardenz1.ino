// Lumenati Alien Garden https://learn.sparkfun.com/tutorials/lumenati-alien-garden-/upload-the-code


void alienGardenz() { 

  maxBrightnessAdjust();

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
        leds[3].setHSV( 96, 255 , flower1 );
        leds[4].setHSV( 192, 255 , flower2 );
        leds[5].setHSV( 96, 255 , flower2 );
        leds[6].setHSV( 192, 255 , flower2 );
        leds[7].setHSV( 96, 255 , flower2 );
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
        leds[3].setHSV( 96, 255 , flower1 );
        leds[4].setHSV( 192, 255 , flower2 );
        leds[5].setHSV( 96, 255 , flower2 );
        leds[6].setHSV( 192, 255 , flower2 );
        leds[7].setHSV( 96, 255 , flower2 );
        FastLED.show();
        averageLEDS();
        delayA0(fadeSpeed);
      }


  FastLED.show();
  averageLEDS();
  delayA0(fadeSpeed);

}
