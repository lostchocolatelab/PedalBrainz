#define UPDATES_PER_SECOND 100

// This example shows several ways to set up and use 'palettes' of colors
// with FastLED.
//
// These compact palettes provide an easy way to re-colorize your
// animation on the fly, quickly, easily, and with low overhead.
//
// USING palettes is MUCH simpler in practice than in theory, so first just
// run this sketch, and watch the pretty lights as you then read through
// the code.  Although this sketch has eight (or more) different color schemes,
// the entire sketch compiles down to about 6.5K on AVR.
//
// FastLED provides a few pre-configured color palettes, and makes it
// extremely easy to make up your own color schemes with palettes.
//
// Some notes on the more abstract 'theory and practice' of
// FastLED compact palettes are at the bottom of this file.



CRGBPalette16 currentPalette;
TBlendType    currentBlending;

//extern CRGBPalette16 myRedWhiteBluePalette;
extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;


// Gradient palette "cw5_032_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/cw/5/tn/cw5-032.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 8 bytes of program space. Orange to Yellow

DEFINE_GRADIENT_PALETTE( cw5_032_gp ) {
    0, 255, 51,  1,
  255, 255,141,  0};

// Gradient palette "cw5_020_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/cw/5/tn/cw5-020.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 8 bytes of program space. Pink to Purple

DEFINE_GRADIENT_PALETTE( cw5_020_gp ) {
    0,  61, 13, 24,
  255,   5,  1, 40};

// Gradient palette "cw5_068_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/cw/5/tn/cw5-068.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 8 bytes of program space. Orange to Red

DEFINE_GRADIENT_PALETTE( cw5_068_gp ) {
    0, 203, 21,  1,
  255,  83,  1,  2};

// Gradient palette "cw5_055_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/cw/5/tn/cw5-055.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 8 bytes of program space. Peach to Salmon

DEFINE_GRADIENT_PALETTE( cw5_055_gp ) {
    0, 255,141,  7,
  255, 169, 28, 10};

  // Gradient palette "cw2_033_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/cw/2/tn/cw2-033.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 12 bytes of program space. Blue to Yellow

DEFINE_GRADIENT_PALETTE( cw2_033_gp ) {
    0,  20, 54, 45,
  127,  74,178, 23,
  255, 224,244, 17};

// Gradient palette "cw2_087_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/cw/2/tn/cw2-087.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 12 bytes of program space. Blue to Blue

DEFINE_GRADIENT_PALETTE( cw2_087_gp ) {
    0,   1, 17, 39,
  127,   5, 41, 65,
  255,  33, 66, 88};

  // Gradient palette "cw2_041_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/cw/2/tn/cw2-041.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 12 bytes of program space. GreenBlue to Purple

DEFINE_GRADIENT_PALETTE( cw2_041_gp ) {
    0,   1, 16,  1,
  127,   2,  6, 41,
  255,  28, 22, 59};

// Gradient palette "cw2_042_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/cw/2/tn/cw2-042.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 12 bytes of program space. Dark to Light Purple

DEFINE_GRADIENT_PALETTE( cw2_042_gp ) {
    0,   4,  8,  6,
  127,  20, 23, 59,
  255,  61, 69,109};

  // Gradient palette "October_Sky_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/colo/sugar/tn/October_Sky.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 40 bytes of program space.

DEFINE_GRADIENT_PALETTE( October_Sky_gp ) {
    0,  42,  7, 11,
  142,  42,  7, 11,
  142, 121, 11, 14,
  170, 121, 11, 14,
  170, 192, 25, 11,
  198, 192, 25, 11,
  198, 232, 66,  5,
  226, 232, 66,  5,
  226, 227,122,  9,
  255, 227,122,  9};

// Gradient palette "cyan_to_dark_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/colo/evad/tn/cyan_to_dark.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 40 bytes of program space.

DEFINE_GRADIENT_PALETTE( cyan_to_dark_gp ) {
    0,   0,255,255,
   51,   0,255,255,
   51,   0,187,180,
  102,   0,187,180,
  102,   0,135,123,
  153,   0,135,123,
  153,   0, 92, 80,
  204,   0, 92, 80,
  204,   0, 57, 47,
  255,   0, 57, 47};

  // Gradient palette "Ocean_Bottom_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/colo/katiekat013/tn/Ocean_Bottom.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 40 bytes of program space.

DEFINE_GRADIENT_PALETTE( Ocean_Bottom_gp ) {
    0,  13, 14,  8,
   51,  13, 14,  8,
   51,  42, 38, 25,
  102,  42, 38, 25,
  102,  23, 52, 45,
  153,  23, 52, 45,
  153,  22, 81, 80,
  204,  22, 81, 80,
  204,  15,118,132,
  255,  15,118,132};




void palette1()
{
    //ChangePalettePeriodically();
    currentPalette = cyan_to_dark_gp;
    currentBlending = LINEARBLEND;
    
    static uint8_t startIndex = 0;
    startIndex = startIndex + 1; /* motion speed */
    
    FillLEDsFromPaletteColors( startIndex);
    
    //FastLED.show();
    //FastLED.delay(300 / UPDATES_PER_SECOND);
    fadeSpeed = 300;
    delayA0(fadeSpeed);
    Serial.println("palette : ");
}

void FillLEDsFromPaletteColors( uint8_t colorIndex)
{
    uint8_t brightness = 255;
    //for(int i = 0; i < NUM_LEDS; i++) { 
    //for(int i = NUM_LEDS-1; i >= 0; i--) {
    for( int i = 0; i < NUM_LEDS; ++i) {
        leds[0] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        leds[1] = ColorFromPalette( currentPalette, colorIndex+10, brightness, currentBlending);
        leds[2] = ColorFromPalette( currentPalette, colorIndex+20, brightness, currentBlending);
        //colorIndex = colorIndex + 3;
    	//FastLED.delay(100 / UPDATES_PER_SECOND);
    	FastLED.show();
    	//showLEDS();
    	//Serial.println("colorIndex : " + String(colorIndex));
    }
    //colorIndex += 3;
    //FastLED.delay(1000 / UPDATES_PER_SECOND);
}


// There are several different palettes of colors demonstrated here.
//
// FastLED provides several 'preset' palettes: RainbowColors_p, RainbowStripeColors_p,
// OceanColors_p, CloudColors_p, LavaColors_p, ForestColors_p, and PartyColors_p.
//
// Additionally, you can manually define your own color palettes, or you can write
// code that creates color palettes on the fly.  All are shown here.

void ChangePalettePeriodically()
{
    uint8_t secondHand = (millis() / 1000) % 60;
    static uint8_t lastSecond = 99;
    
    if( lastSecond != secondHand) {
        lastSecond = secondHand;
        if( secondHand ==  0)  { currentPalette = RainbowColors_p;         currentBlending = LINEARBLEND; }
        if( secondHand == 10)  { currentPalette = RainbowStripeColors_p;   currentBlending = NOBLEND;  }
        if( secondHand == 15)  { currentPalette = RainbowStripeColors_p;   currentBlending = LINEARBLEND; }
        if( secondHand == 20)  { SetupPurpleAndGreenPalette();             currentBlending = LINEARBLEND; }
        if( secondHand == 25)  { SetupTotallyRandomPalette();              currentBlending = LINEARBLEND; }
        if( secondHand == 30)  { SetupBlackAndWhiteStripedPalette();       currentBlending = NOBLEND; }
        if( secondHand == 35)  { SetupBlackAndWhiteStripedPalette();       currentBlending = LINEARBLEND; }
        if( secondHand == 40)  { currentPalette = CloudColors_p;           currentBlending = LINEARBLEND; }
        if( secondHand == 45)  { currentPalette = PartyColors_p;           currentBlending = LINEARBLEND; }
        if( secondHand == 50)  { currentPalette = myRedWhiteBluePalette_p; currentBlending = NOBLEND;  }
        if( secondHand == 55)  { currentPalette = myRedWhiteBluePalette_p; currentBlending = LINEARBLEND; }
    }
}



// This function fills the palette with totally random colors.
void SetupTotallyRandomPalette()
{
    for( int i = 0; i < 16; ++i) {
        currentPalette[i] = CHSV( random8(), 255, random8());
    }
}

// This function sets up a palette of black and white stripes,
// using code.  Since the palette is effectively an array of
// sixteen CRGB colors, the various fill_* functions can be used
// to set them up.
void SetupBlackAndWhiteStripedPalette()
{
    // 'black out' all 16 palette entries...
    fill_solid( currentPalette, 16, CRGB::Black);
    // and set every fourth one to white.
    currentPalette[0] = CRGB::White;
    currentPalette[4] = CRGB::White;
    currentPalette[8] = CRGB::White;
    currentPalette[12] = CRGB::White;
    
}

// This function sets up a palette of purple and green stripes.
void SetupPurpleAndGreenPalette()
{
    CRGB purple = CHSV( HUE_PURPLE, 255, 255);
    CRGB green  = CHSV( HUE_GREEN, 255, 255);
    CRGB black  = CRGB::Black;
    
    currentPalette = CRGBPalette16(
                                   green,  green,  black,  black,
                                   purple, purple, black,  black,
                                   green,  green,  black,  black,
                                   purple, purple, black,  black );
}


// This example shows how to set up a static color palette
// which is stored in PROGMEM (flash), which is almost always more
// plentiful than RAM.  A static PROGMEM palette like this
// takes up 64 bytes of flash.
const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM =
{
    CRGB::Red,
    CRGB::Gray, // 'white' is too bright compared to red and blue
    CRGB::Blue,
    CRGB::Black,
    
    CRGB::Red,
    CRGB::Gray,
    CRGB::Blue,
    CRGB::Black,
    
    CRGB::Red,
    CRGB::Red,
    CRGB::Gray,
    CRGB::Gray,
    CRGB::Blue,
    CRGB::Blue,
    CRGB::Black,
    CRGB::Black
};



// Additional notes on FastLED compact palettes:
//
// Normally, in computer graphics, the palette (or "color lookup table")
// has 256 entries, each containing a specific 24-bit RGB color.  You can then
// index into the color palette using a simple 8-bit (one byte) value.
// A 256-entry color palette takes up 768 bytes of RAM, which on Arduino
// is quite possibly "too many" bytes.
//
// FastLED does offer traditional 256-element palettes, for setups that
// can afford the 768-byte cost in RAM.
//
// However, FastLED also offers a compact alternative.  FastLED offers
// palettes that store 16 distinct entries, but can be accessed AS IF
// they actually have 256 entries; this is accomplished by interpolating
// between the 16 explicit entries to create fifteen intermediate palette
// entries between each pair.
//
// So for example, if you set the first two explicit entries of a compact 
// palette to Green (0,255,0) and Blue (0,0,255), and then retrieved 
// the first sixteen entries from the virtual palette (of 256), you'd get
// Green, followed by a smooth gradient from green-to-blue, and then Blue.