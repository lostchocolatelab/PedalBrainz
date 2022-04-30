//
//  "Pacifica"
//  Gentle, blue-green ocean waves.
//  December 2019, Mark Kriegsman and Mary Corey March.
//  For Dan.
//

//#define FASTLED_ALLOW_INTERRUPTS 0
//#include <FastLED.h>
//FASTLED_USING_NAMESPACE

uint8_t hue1 = map(analogRead(A2), 0, 1024, 0, 190);
uint8_t hue2 = map(analogRead(A2), 0, 1024, 0, 30);  


void testFast() {
   // Move a single white led 
   for(int whiteLed = 0; whiteLed < NUM_LEDS; whiteLed = whiteLed + 1) {
      // Turn our current led on to white, then show the leds
      leds[whiteLed] = CRGB::White;

      // Show the leds (only one of which is set to white, from above)
      FastLED.show();

      // Wait a little bit
     delay(100);

      // Turn our current led back to black for the next loop around
      leds[whiteLed] = CRGB::Black;
   }
}


void oceanz()
{
    EVERY_N_MILLISECONDS( 5) 
    {
        pacifica_loop();
        //FastLED.show();
        //pixel.show();
        //inner.show();
        showLEDS();


    }

    
    checkSpeed();
    plotCycle();
    checkButtons();
}

//////////////////////////////////////////////////////////////////////////
//
// The code for this animation is more complicated than other examples, and 
// while it is "ready to run", and documented in general, it is probably not 
// the best starting point for learning.  Nevertheless, it does illustrate some
// useful techniques.
//
//////////////////////////////////////////////////////////////////////////
//
// In this animation, there are four "layers" of waves of light.  
//
// Each layer moves independently, and each is scaled separately.
//
// All four wave layers are added together on top of each other, and then 
// another filter is applied that adds "whitecaps" of brightness where the 
// waves line up with each other more.  Finally, another pass is taken
// over the led array to 'deepen' (dim) the blues and greens.
//
// The speed and scale and motion each layer varies slowly within independent 
// hand-chosen ranges, which is why the code has a lot of low-speed 'beatsin8' functions
// with a lot of oddly specific numeric ranges.
//
// These three custom blue-green color palettes were inspired by the colors found in
// the waters off the southern coast of California, https://goo.gl/maps/QQgd97jjHesHZVxQ7
//

CRGBPalette16 pacifica_palette_1 = 
    { 0x000507, 0x000409, 0x00030B, 0x00030D, 0x000210, 0x000212, 0x000114, 0x000117, 
      0x000019, 0x00001C, 0x000026, 0x000031, 0x00003B, 0x000046, 0x14554B, 0x28AA50 };
CRGBPalette16 pacifica_palette_2 = 
    { 0x000507, 0x000409, 0x00030B, 0x00030D, 0x000210, 0x000212, 0x000114, 0x000117, 
      0x000019, 0x00001C, 0x000026, 0x000031, 0x00003B, 0x000046, 0x0C5F52, 0x19BE5F };
CRGBPalette16 pacifica_palette_3 = 
    { 0x000208, 0x00030E, 0x000514, 0x00061A, 0x000820, 0x000927, 0x000B2D, 0x000C33, 
      0x000E39, 0x001040, 0x001450, 0x001860, 0x001C70, 0x002080, 0x1040BF, 0x2060FF };  

/*
 * 
CRGBPalette16 pacifica_palette_1 = 
    { 0,  66,  1, 34,
  127, 249,175,226,
  252,  14,  1,  8,
  255,  14,  1,  8 };
CRGBPalette16 pacifica_palette_2 = 
    { 0, 227,101,  3,
  117, 194, 18, 19,
  255,  92,  8,192,
  255,  92,  8,192 };
CRGBPalette16 pacifica_palette_3 = 
    { 0, 242,  5,122,
   58, 239,164,207,
  101, 242,  5,122,
  101, 242,  5,122 };

CRGBPalette16 pacifica_palette_1 = 
    { 0x000507, 0x000409, 0x00030B, 0x00030D, 0x000210, 0x000212, 0x000114, 0x000117, 
      0x000019, 0x00001C, 0x000026, 0x000031, 0x00003B, 0x000046, 0x14554B, 0x28AA50 };
CRGBPalette16 pacifica_palette_2 = 
    { 0x000507, 0x000409, 0x00030B, 0x00030D, 0x000210, 0x000212, 0x000114, 0x000117, 
      0x000019, 0x00001C, 0x000026, 0x000031, 0x00003B, 0x000046, 0x0C5F52, 0x19BE5F };
CRGBPalette16 pacifica_palette_3 = 
    { 0x000208, 0x00030E, 0x000514, 0x00061A, 0x000820, 0x000927, 0x000B2D, 0x000C33, 
      0x000E39, 0x001040, 0x001450, 0x001860, 0x001C70, 0x002080, 0x1040BF, 0x2060FF };    

*/
void checkSpeed(){

    controlAmount  = map(analogRead(A0), 0, 1024, 90, 0);
    averageLEDS();
      
    hue1 = map(analogRead(A2), 0, 1024, 0, 150);
    hue2 = map(analogRead(A2), 0, 1024, 0, 20); 

    //showLEDS(); 
}

void pacifica_loop()
{
    maxBrightnessAdjust();      
      
  // Increment the four "color index start" counters, one for each wave layer.
  // Each is incremented at a different speed, and the speeds vary over time.
  static uint16_t sCIStart1, sCIStart2, sCIStart3, sCIStart4;
  static uint32_t sLastms = 0;
  uint32_t ms = GET_MILLIS();
  uint32_t deltams = ms - sLastms;
  sLastms = ms;

  checkSpeed();

  uint16_t beatsin1 = beatsin16(3, 179, 269);
  uint16_t beatsin2 = beatsin16(4, 179, 269);
  uint16_t speedfactor1 = 400+beatsin1/controlAmount;
  uint16_t speedfactor2 = 400+beatsin2/controlAmount;
  uint32_t deltams1 = (deltams * speedfactor1) / 256;
  uint32_t deltams2 = (deltams * speedfactor2) / 256;
  uint32_t deltams21 = (deltams1 + deltams2) / 2;
  sCIStart1 += (deltams1 * beatsin88(1011,10,13));
  sCIStart2 -= (deltams21 * beatsin88(777,8,11));
  sCIStart3 -= (deltams1 * beatsin88(501,5,7));
  sCIStart4 -= (deltams2 * beatsin88(257,4,6));

  Serial.println("Speedfactor1 : " + String(speedfactor1));
  Serial.println("Speedfactor2 : " + String(speedfactor2));
  Serial.println("deltams1 : " + String(deltams1));
  Serial.println("deltams2 : " + String(deltams2));
  Serial.println("Control Amount : " + String(controlAmount));

  // Clear out the LED array to a dim background blue-green
  //fill_solid( leds, NUM_LEDS, CRGB( 2, 6, 10));
  fill_solid( leds, NUM_LEDS, CRGB( 2+hue2, 6, 10));  //Pinkaliscous
  //Serial.println("Oceanz | Fill Solid");
  

  // Render each of four layers, with different scales and speeds, that vary over time
  pacifica_one_layer( pacifica_palette_1, sCIStart1, beatsin16( 3, 11 * 256, 14 * 256), beatsin8( 10, 70, 130), 0-beat16( 301) );
  pacifica_one_layer( pacifica_palette_2, sCIStart2, beatsin16( 4,  6 * 256,  9 * 256), beatsin8( 17, 40,  80), beat16( 401) );
  pacifica_one_layer( pacifica_palette_3, sCIStart3, 6 * 256, beatsin8( 9, 10,38), 0-beat16(503));
  pacifica_one_layer( pacifica_palette_3, sCIStart4, 5 * 256, beatsin8( 8, 10,28), beat16(601));

  // Add brighter 'whitecaps' where the waves lines up more
  pacifica_add_whitecaps();

  // Deepen the blues and greens a bit
  pacifica_deepen_colors();
}

// Add one layer of waves into the led array
void pacifica_one_layer( CRGBPalette16& p, uint16_t cistart, uint16_t wavescale, uint8_t bri, uint16_t ioff)
{
            
    uint16_t ci = cistart;
    uint16_t waveangle = ioff;
    uint16_t wavescale_half = (wavescale / 2) + 20;
    
    for( uint16_t i = 0; i < NUM_LEDS; i++) {
        waveangle += 250;
        uint16_t s16 = sin16( waveangle ) + 32768;
        uint16_t cs = scale16( s16 , wavescale_half ) + wavescale_half;
        ci += cs;
        uint16_t sindex16 = sin16( ci) + 32768;
        uint8_t sindex8 = scale16( sindex16, 240);
        CRGB c = ColorFromPalette( p, sindex8, bri, LINEARBLEND);
        leds[i] += c;

        maxBrightnessAdjust(); 

        checkSpeed();
        plotCycle();
        checkButtons();

    }
    //showLEDS();
}

// Add extra 'white' to areas where the four layers of light have lined up brightly
void pacifica_add_whitecaps()
{
      
  //Serial.println("Oceanz | Whitecaps");
  uint8_t basethreshold = beatsin8( 9, 55, 65);
  uint8_t wave = beat8( 7 );

  //Serial.println("Oceanz | basethreshold " + String(basethreshold));
  
  for( uint16_t i = 0; i < NUM_LEDS; i++) {
    uint8_t threshold = scale8( sin8( wave), 20) + basethreshold;
    wave += 7;
    uint8_t l = leds[i].getAverageLight();
    if( l > threshold) {
      uint8_t overage = l - threshold;
      uint8_t overage2 = qadd8( overage, overage);
      leds[i] += CRGB( overage, overage2, qadd8( overage2, overage2));
      //Serial.println("Oceanz | ColorFromPalette " + String(overage));
      
    //A1 potentiometer controls for maximum brightness
    maxBrightness = map(analogRead(A1), 0, 1024, 0, maxBrightnessTemp);
    MaxBrightReduction = constrain(maxBrightness, 0, MaxBright);
    pixel.setBrightness(maxBrightness);
    FastLED.setBrightness(MaxBrightReduction);
    inner.setBrightness(maxBrightness);
    //Serial.println("maxBrightness : " + String(maxBrightness));
    //Serial.println("MaxBright : " + String(MaxBright));
    //Serial.println("MaxBrightReduction : " + String(MaxBrightReduction));
    
        checkSpeed();
        plotCycle();
        checkButtons();
    }
  }
}

// Deepen the blues and greens
void pacifica_deepen_colors()
{
                 
  //Serial.println("Oceanz | Deepen");
  for( uint16_t i = 0; i < NUM_LEDS; i++) {

    hue1 = map(analogRead(A2), 0, 1024, 0, 190);
    
    //leds[i].blue = scale8( leds[i].blue,  145); 
    //leds[i].green= scale8( leds[i].green, 200); 
    leds[i].blue = scale8( leds[i].blue,  145-hue1); 
    leds[i].green= scale8( leds[i].green, 200-hue1); 
    leds[i] |= CRGB( 2, 5, 7);
    

    //A1 potentiometer controls for maximum brightness
    maxBrightness = map(analogRead(A1), 0, 1024, 0, maxBrightnessTemp);
    MaxBrightReduction = constrain(maxBrightness, 0, MaxBright);
    pixel.setBrightness(maxBrightness);
    FastLED.setBrightness(MaxBrightReduction);
    inner.setBrightness(maxBrightness);
    //Serial.println("maxBrightness : " + String(maxBrightness));
    //Serial.println("MaxBright : " + String(MaxBright));
    //Serial.println("MaxBrightReduction : " + String(MaxBrightReduction));
    
        checkSpeed();
        plotCycle();
        checkButtons();
  }
}
