// GLOBAL VARIABLES --------------------------------------------------------

// This bizarre construct isn't Arduino code in the conventional sense.
// It exploits features of GCC's preprocessor to generate a PROGMEM
// table (in flash memory) holding an 8-bit unsigned sine wave (0-255).
const int _SBASE_ = __COUNTER__ + 1; // Index of 1st __COUNTER__ ref below
#define _S1_ (sin((__COUNTER__ - _SBASE_) / 128.0 * M_PI) + 1.0) * 127.5 + 0.5,
#define _S2_ _S1_ _S1_ _S1_ _S1_ _S1_ _S1_ _S1_ _S1_ // Expands to 8 items
#define _S3_ _S2_ _S2_ _S2_ _S2_ _S2_ _S2_ _S2_ _S2_ // Expands to 64 items
const uint8_t PROGMEM sineTable[] = { _S3_ _S3_ _S3_ _S3_ }; // 256 items

// Similar to above, but for an 8-bit gamma-correction table.
#define _GAMMA_ 2.6
const int _GBASE_ = __COUNTER__ + 1; // Index of 1st __COUNTER__ ref below
#define _G1_ pow((__COUNTER__ - _GBASE_) / 255.0, _GAMMA_) * 255.0 + 0.5,
#define _G2_ _G1_ _G1_ _G1_ _G1_ _G1_ _G1_ _G1_ _G1_ // Expands to 8 items
#define _G3_ _G2_ _G2_ _G2_ _G2_ _G2_ _G2_ _G2_ _G2_ // Expands to 64 items
const uint8_t PROGMEM gammaTable[] = { _G3_ _G3_ _G3_ _G3_ }; // 256 items

// These are used in estimating (very approximately) the current draw of
// the board and NeoPixels.  BASECURRENT is the MINIMUM current (in mA)
// used by the entire system (microcontroller board plus NeoPixels) --
// keep in mind that even when "off," NeoPixels use a tiny amount of
// current (a bit under 1 milliamp each).  LEDCURRENT is the maximum
// additional current PER PRIMARY COLOR of ONE NeoPixel -- total current
// for an RGB NeoPixel could be up to 3X this.  The '3535' NeoPixels on
// Circuit Playground are smaller and use less current than the more
// common '5050' type used in NeoPixel strips and shapes.
#define BASECURRENT 10
#define LEDCURRENT  18 // Try using 18 for '5050' NeoPixels
uint16_t  count = 0;    // Frame count, results displayed every 256 frames
//uint32_t sum   = 0;    // Cumulative current, for calculating average
//uint8_t *pixelPtr;     // -> NeoPixel color data

// HSV (hue-saturation-value) to RGB function used for the next two modes.
uint32_t hsv2rgb(int32_t h, uint8_t s, uint8_t v, boolean gc=false) {
  uint8_t n, r, g, b;

  // Hue circle = 0 to 1530 (NOT 1536!)
  h %= 1530;           // -1529 to +1529
  if(h < 0) h += 1530; //     0 to +1529
  n  = h % 255;        // Angle within sextant; 0 to 254 (NOT 255!)
  switch(h / 255) {    // Sextant number; 0 to 5
   case 0 : r = 255    ; g =   n    ; b =   0    ; break; // R to Y
   case 1 : r = 254 - n; g = 255    ; b =   0    ; break; // Y to G
   case 2 : r =   0    ; g = 255    ; b =   n    ; break; // G to C
   case 3 : r =   0    ; g = 254 - n; b = 255    ; break; // C to B
   case 4 : r =   n    ; g =   0    ; b = 255    ; break; // B to M
   default: r = 255    ; g =   0    ; b = 254 - n; break; // M to R
  }

  uint32_t v1 =   1 + v; // 1 to 256; allows >>8 instead of /255 - BRIGHTNESS
  uint16_t s1 =   1 + s; // 1 to 256; same reason - BRIGHTNESS
  uint8_t  s2 = 255 - s; // 255 to 0 - COLOR SHIFT

     if (Bank == 2){
          if (Mode == 1){
    
                
                v1 = map(analogRead(A1), 0, 1024, 0, 255);
                s2 = map(analogRead(A2), 0, 1024, 0, 255);
                //strip.setBrightness(MaxBrightReduction);
                
         }
         else;
      }
      else;

  
     

  r = ((((r * s1) >> 8) + s2) * v1) >> 8;
  g = ((((g * s1) >> 8) + s2) * v1) >> 8;
  b = ((((b * s1) >> 8) + s2) * v1) >> 8;
  if(gc) { // Gamma correct?
    r = pgm_read_byte(&gammaTable[r]);
    g = pgm_read_byte(&gammaTable[g]);
    b = pgm_read_byte(&gammaTable[b]);
  }
  return ((uint32_t)r << 16) | ((uint16_t)g << 8) | b;
  
}

void rainbowNew(){

  
  mode_colorwheel_gamma();
  
 }

// Rotating color wheel, using 'raw' RGB values (no gamma correction).
// Average current use is about 1/2 of the max-all-white case.
void mode_colorwheel() {
  valueA0  = map(analogRead(A0), 0, 1024, 1, 7);
  uint32_t t = millis()*valueA0;
  //uint32_t t = millis();
  for(uint8_t i=0; i<10; i++) {
    uint8_t j = i + (i > 4);
    strip.setPixelColor(i,
      hsv2rgb(t + j * 1530 / 12, 255, 255, false));
    pixel.setPixelColor(i,
      hsv2rgb(t + j * 1530 / 12, 255, 255, false));
    inner.setPixelColor(i,
      hsv2rgb(t + j * 1530 / 12, 255, 255, false));  
    //delayA0(fadeSpeed);
    //count = count+1; 
  }
  //count = count+1;
  
}

void mode_colorwheel_intro() {
  
  valueA0  = 10;
  uint32_t t = millis();
  //uint32_t t = millis();
  for(uint8_t i=0; i<30; i++) {
    uint8_t j = i + (i > 4);
    
    for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
      strip.setPixelColor(i,
      hsv2rgb(t + j * 1530 / 12, 255, 255, false));
    }
    pixel.setPixelColor(i,
      hsv2rgb(t + j * 1530 / 12, 255, 255, false));
    inner.setPixelColor(i,
      hsv2rgb(t + j * 1530 / 12, 255, 255, false));  
    //delayA0(fadeSpeed);
    //count = count+1; 
  
  showLEDS();
  //Serial.println("I did this thing");
  }
  //count = count+1;
  
}
// Color wheel using gamma-corrected values.  Current use is slightly less
// than the 'raw' case, but not tremendously so, as only 1/3 of pixels at
// any time are in transition cases (else 100% on or off).
void mode_colorwheel_gamma() {
  
  valueA0  = map(analogRead(A0), 0, 1024, 1, 7);
  uint32_t t = millis()*valueA0;
  //uint32_t t = millis();
  for(uint8_t i=0; i<10; i++) {
    uint8_t j = i + (i > 4);
    strip.setPixelColor(i,
      hsv2rgb(t + j * 1530 / 12, 255, 255, true));
    pixel.setPixelColor(i,
      hsv2rgb(t + j * 1530 / 12, 255, 255, true));
    inner.setPixelColor(i,
      hsv2rgb(t + j * 1530 / 12, 255, 255, true));  
    //delayA0(fadeSpeed);   
  }
  //count = count+1;
  showLEDS();

   
}
