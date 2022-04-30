//  Abstracted Strange Attractorz Modez
//
//
//  -Lost Lab


/**

  ARDUINO Libraries in-use
  These must be included in your Arduino Environment using /Sketch/Include Libraries/Manage Libraries... or by importing the Library .zip directly

*/

//#include <Adafruit_DotStar.h>
#include <FlashAsEEPROM_SAMD.h>
#include <MultiMap.h>
#include <Adafruit_NeoPixel.h>
#include <FastLED_NeoPixel.h>
#include <FastLED.h>

#define NUMPIXELS 3 // Number of LEDs in strip
#define PINSTRIP 4 // Pin used for the strip (knobs)
#define MAX_POWER 100
#define VOLTS 5

// Declare our NeoPixel strip object:
//Adafruit_NeoPixel strip(NUMPIXELS, 4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel inner(1, 3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixel(1, PIN_NEOPIXEL);

//FastLED_NeoPixel <NUMPIXELS, 4, NEO_GRB + NEO_KHZ800> strip;
//FastLED_NeoPixel <1, 3, NEO_GRB + NEO_KHZ800> inner;
//FastLED_NeoPixel <1, PIN_NEOPIXEL> pixel;

#define NUM_LEDS_INNER 1
#define NUM_LEDS 3

CRGBArray <NUM_LEDS> leds;
FastLED_NeoPixel_Variant strip(leds, NUM_LEDS);



/**

  Adafruit_DotStar Library declaration
  Set the on-board DotStar as "pixel".

*/

//Adafruit_DotStar pixel = Adafruit_DotStar(1, INTERNAL_DS_DATA, INTERNAL_DS_CLK, DOTSTAR_BGR);

/**

  POTENTIOMETER declarations

*/

int valueA0 = 135;
int valueA1 = 0;
int valueA2 = 0;

/**

  BUTTON declarations

*/

// Setting the Button Pins
const int buttonPinUp = A9;     // Button Up
const int buttonPinDown =  A10;      // Button Down

/**

  General declarations
  Some colors, some randoms, some brightness

*/

// Set a default variable for the red, blue, and green (RGB) value of the on-board Dot Star
// Pink! Potentiometer A0: 236 Potentiometer A1: 73 Potentiometer A2: 107

int head  = 0, tail = -10; // Index of first 'on' and 'off' pixels

int redValue = 236;
int blueValue = 73;
int greenValue = 107;

int fadeValueScaled;
int scaledBright;

int fadeSpeed = 13;
int fullDelay = 0;
int darkDelay = 0;

int randomAmountA0 = 0;
int randomAmountA1 = 0;
int randomAmountA2 = 0;

int delayRandom = random(0, 1000);
int delayValue = 0;
int delayValueA0 = 0;
int delayValueA1 = 0;
int delayValueA2 = 0;

// Sets the value in milleseconds of the slowest fadeSpeed for delayA0
int speedMinimum = 10000;
int speedMaximum = 0;

// Sets the value in milleseconds of the longest duration for delayA1 and delayA2
int durationMaximum = 10000;

int valueLog;
int controlAmount;

unsigned long myTime;
int LEDBrightness; // Used to get brightness in plotter

/**

  SQUAREZ Declarations

*/

boolean Blink1 = true;

/**

  NAVIGATION Declarations

*/

bool clicked = false;

bool nothingBroken = true;
bool breakdelayA0 = false;
bool breakdelayA1 = false;
bool breakdelayA2 = false;

long WaitTime = 200;

int Mode = 1;
int Bank = 1;
int MaxBright = 255; // Strip Max Bright
int MaxBrightTemp = 190;
int MaxBrightReduction;
int MaxBrightRainbow;

boolean plotterPrint = true;

/**

  STRANGE ATTRACTORZ Declarations

*/

//Coordinates for the lorenz function
float w = 0;
float x = 0;
float y = 0;
float z = 0;
float scaledX = 0;
float scaledY = 0;
float scaledZ = 0;
float effectiveR = 0;
float effectiveG = 0;
float effectiveB = 0;

//Constants for the lorenz function, KEEP UNCHANGED
float a = 10.0;
float b = 28.0;
float c = 8.0 / 3.0;

//Variables for lorenz function
float dx = 0;
float dy = 0;
float dz = 0;

//Variables for timing
float dt = 0.01;  //Time between interval (seconds) default: 10ms (0.01s) you can change it but the code become unstable
unsigned long nextLorenzUpdate = 0;
int printDelay = 10; //Time between each serial print (default: 50ms)


float scalings[2][3] {
  {0, 0, 0}, //minX, minY, minZ
  {0, 0, 0} //maxX, maxY, maxZ
};

int brightness = 0;
int brightnessScaled;
float fadeAmount = 1;  //Change it to adjust the fading between each step (fading speed)
int maxBrightness = 190; //Pixel Max Bright
int maxBrightnessTemp = 190; //Pixel Max Bright
int delayAmount = 0;
int strangeRandom;
int strangeSlowAmount;
int strangeSlowCount;

float randomAmount;

// Rainbowz2

int randomOnce = 0;
boolean increaseValue = true;
int modulateSpeed = 0;
int modulateConstrain;

unsigned long startMillis;

// Average LEDS for getting the values of the Knob LEDs and using them

int avgLight;
int avgLight0;
int avgLight1;
int avgLight2;
int avgLightInner;




/**

  Setup

*/

void setup() {
  Serial.begin(115200);

  // Setup the buttons
  pinMode(buttonPinUp, INPUT_PULLUP);
  pinMode(buttonPinDown, INPUT_PULLUP);
  
  /* Start the DotStar LED */
  pixel.begin();
  strip.begin(FastLED.addLeds<WS2812B, PINSTRIP, GRB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip));
  inner.begin();

  //FastLED.setMaxPowerInVoltsAndMilliamps( VOLTS, MAX_POWER);
  //FastLED.setMaxRefreshRate(10000);
  //FastLED.setDither(BINARY_DITHER);
  
  pixel.setBrightness(maxBrightness);
  strip.setBrightness(maxBrightness);
  inner.setBrightness(maxBrightness);
  
  strip.setPixelColor(0, redValue, blueValue, greenValue);
  strip.setPixelColor(1, redValue, blueValue, greenValue);
  strip.setPixelColor(2, redValue, blueValue, greenValue);
  strip.setPixelColor(3, redValue, blueValue, greenValue);
  pixel.setPixelColor(0, redValue, blueValue, greenValue);
  inner.setPixelColor(0, redValue, blueValue, greenValue);
  
  strip.show();
  pixel.show();
  inner.show();

  x = 0.01;
  y = 0.3;
  z = 0.7;

  //x = 0.1;
  //y = 2;
  //z = 1;

  //x = 0.5;
  //y = 0.9;
  //z = 0.1;

  // Set a Startup Mode
  Bank = 1;
  Mode = 2;
  MaxBright = 255;

  //setRandoms();
  plotterPrint = false; // This prints to the Serial.Plotter and when set to True can slow down some Modez. Set to False to remove Serial Plotting of Values
  startMillis = millis();  //initial start time
}

/**

  Loop

*/


void loop() {
 
  // This is the function that handles startup and Mode switching
  
  //Routines();
  
  //Explicit Functions and Modes can be set here, instead of the Routines
  strangeAttractor();

  // plotCycle writes values to the Serial Monitor for plotting/
  // This is sprinkled throughout the code in-order to update the values on the Serial Plotter
  
  //plotCycle();
  //checkButtons();

  // Some memory Print
  //Serial.print(F("freeMemory: "));
  //Serial.println((int)freeMemory);

}

/**

  Some Global Functions


*/

void showLEDS(){

  //FastLED.show();
  strip.show();
  pixel.show();
  inner.show();
  
}

void maxBrightnessSet(){

  MaxBrightReduction = constrain(maxBrightness, 0, MaxBright);
  pixel.setBrightness(maxBrightness);
  strip.setBrightness(MaxBrightReduction);
  inner.setBrightness(maxBrightness);
  FastLED.setBrightness(MaxBrightReduction);
  showLEDS();
}

void maxBrightnessAdjust()
{
  //A1 potentiometer controls for maximum brightness
  maxBrightness = map(analogRead(A1), 0, 1024, 0, maxBrightnessTemp);
  MaxBrightReduction = constrain(maxBrightness, 0, MaxBright);
  pixel.setBrightness(maxBrightness);
  strip.setBrightness(MaxBrightReduction);
  inner.setBrightness(maxBrightness);
  FastLED.setBrightness(MaxBrightReduction);

  //Serial.println("maxBrightness : " + String(maxBrightness));
  //Serial.println("MaxBright : " + String(MaxBright));
  //Serial.println("MaxBrightReduction : " + String(MaxBrightReduction));
}

void averageLEDS(){

  avgLight0 = leds[0].getAverageLight();
  avgLight1 = leds[1].getAverageLight();
  avgLight2 = leds[2].getAverageLight();
  avgLight = avgLight0+avgLight1+avgLight2;
  avgLightInner = map(avgLight, 0, 255, 0, 190);
  //avgLight = avgLight1;

  //Serial.println("Average : " + String(avgLight));

  pixel.setPixelColor(0, avgLightInner,avgLightInner,avgLightInner); 
  inner.setPixelColor(0, avgLightInner,avgLightInner,avgLightInner);  

  showLEDS();
}

void averageLEDSBrightness(){

  avgLight0 = leds[0].getAverageLight();
  avgLight1 = leds[1].getAverageLight();
  avgLight2 = leds[2].getAverageLight();
  avgLight = avgLight0+avgLight1+avgLight2;

  mapScaledBright(avgLight);

  avgLightInner = map(scaledBright, 0, 255, 0, 190);

  //Serial.println("Average : " + String(avgLight));
  pixel.setBrightness(avgLightInner);
  inner.setBrightness(avgLightInner);

  pixel.setPixelColor(0, avgLightInner,avgLightInner,avgLightInner); 
  inner.setPixelColor(0, avgLightInner,avgLightInner,avgLightInner);  

  showLEDS();
}


void mapScaledBright (int val){

      //controlAmount = map(analogRead(A0), 0, 1024, 0, 100);
      //valueLog = log(analogRead(A0)+1)/log(1024)*255;
      //Serial.println("Mode 1 valueLog: " + String(valueLog));
      //fadeSpeed = map(valueLog, 0, 255, (speedMinimum), (40/2)); // Logarithmic Potentiometer Value
      //fadeSpeed = map(valueLog, 0, 255, (speedMinimum/2), (40/2)); // Logarithmic Potentiometer Value

      // This makes the potentiometer slower to change when reducting from full and gives better control fidelity at higher speeds
      // This is a map of values for the potentiometer. note: the in array should have increasing values
      int in[]  = {0, 25,51,76,102,127,153,178,204,229,255};
      // This is a map of values for potentiometer curve type.
      int out[] = {0, 5, 10,  15,  20,  25,  30,  35,  50,  80,  190 };  // 11
      // This maps the potentiometer scale.
      controlAmount  = val;
      // This is a multimap that assigns values from the [in] array (potentiometer) to values from the [out] array (curve)
      x = multiMap(controlAmount, in, out, 11);
      // This maps the values for the Modez.
      scaledBright = map(x, 0, 255, 0, 255);

      //int redValue = 236;
      //int blueValue = 73;
      //int greenValue = 107;
      
}

/**

  ATTRIBUTION


  Routine & ValueHigh/ Low
  * Programmer : Ranga Marasinghe
  * Date       : 2021-April-22
  * https://www.fiverr.com/ranga_niroshan

  Initial Fading
  * Programmer : Guljanjua
  * Date       : 2021-April-21
  * https://www.fiverr.com/guljanjua

  * Rainbow Mode
  * https://www.instructables.com/How-to-Make-Proper-Rainbow-and-Random-Colors-With-/

  Strange Attractorz Lorentz
  * Programmer : Timothy Franceschi
  * Date       : 2021-April-21
  * https://www.fiverr.com/timofran

  Mountainz (Snack Master)
  * Programmer : Yann Seznec
  * Date       : 2021-May
  * https://www.yannseznec.com/

  Alpha and Beta Brainz Testers
  * Ancient Radiations
  * Forrest Hopkins
  * LEEMS Industries
  * Aotokumo
  * Andy Pitcher
  * Mask Audio Electronics
  * Aaron Meagher - Discrete Circuitry

  Special Thanks
  * Rarebuzzer
  * Mask Audio Electronics
  * El Garatge
  * Obscura MFG
  * Lightning Wave
  * Collector//Emitter Discord Community
  * 

*/
