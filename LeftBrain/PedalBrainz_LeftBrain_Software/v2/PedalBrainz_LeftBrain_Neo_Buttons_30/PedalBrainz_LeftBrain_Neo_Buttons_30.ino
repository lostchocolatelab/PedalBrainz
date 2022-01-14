//  Welcome to Pedal Brainz
//
//  Mode Change
//  All potentiometers to zero fully counter clockwise (left) for 1 second then rotate potentiometer A2 clockwise (right) from zero for Mode Change.
//
//  Mode Save
//  The last Mode used will be saved as the Startup Mode.
//
//  Mode 1 | Squarez 
//  A0 = Speed between 2 Blinks
//  A1 = Blink 1 Color Value (Brightness)
//  A2 = Blink 2 Color Value (Brightness)
//
//  Mode 2 | Trainglez 
//  A0 = Fade speed of LED
//  A1 = Duration when LED is fully on (It's Lit)
//  A2 = Duration when LED is fully off (It's Dark)
//
//  Mode 3 | Trainglez Random
//  A0 = Amount of Random Time Added to A1, A2
//  A1 = Duration when LED is fully on (It's Lit)
//  A2 = Duration when LED is fully off (It's Dark)
//
//  Mode 4 | Rainbowz
//  A0 = Rainbow Cycle Speed
//  A1 = Maximum Brightness
//  A2 = Duration when LED is fully off (It's Dark)
//
//  Mode 5 | Rainbowz Random
//  A0 = Rainbow Cycle Speed
//  A1 = Randomized Maximum Brightness
//  A2 = Duration when LED is fully off (It's Dark)
//
//  Mode 6 | Mountainz Random Repeat
//  A0 = Cycle Speed
//  A1 = Amount of Randomness
//  A2 = Chance of Snack
//
//  Mode 7 | Mountainz Random Random
//  A0 = Cycle Speed
//  A1 = Amount of Randomness
//  A2 = Chance of Snack
//
//  Mode 8 | Strange Attractorz Single
//  A0 = Cycle Speed
//  A1 = Maximum Brightness
//  A2 = Amount of Randomness
//
//  Mode 9 | Strange Attractorz Double
//  A0 = Cycle Speed
//  A1 = Maximum Brightness
//  A2 = Amount of Randomness
//
//  Mode 10 | Strange Attractorz Triple
//  A0 = Cycle Speed
//  A1 = Maximum Brightness
//  A2 = Amount of Randomness
//
//
//  -Lost Lab


/**

  ARDUINO Libraries in-use
  These must be included in your Arduino Environment using /Sketch/Include Libraries/Manage Libraries... or by importing the Library .zip directly

*/

#include <Adafruit_DotStar.h>
#include <FlashAsEEPROM_SAMD.h>
#include "MultiMap.h"

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define NUMPIXELS 3 // Number of LEDs in strip

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(NUMPIXELS, 4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel inner(1, 3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixel(1, PIN_NEOPIXEL);


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

  POTENTIOMETER declarations

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

int      head  = 0, tail = -10; // Index of first 'on' and 'off' pixels

int redValue = 236;
int blueValue = 73;
int greenValue = 107;

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

  ROUTINES Declarations

*/

// Some Colors
uint32_t Sketch2Blue = 0x0000FF;
uint32_t Sketch2Red = 0xFF0000;
uint32_t Sketch2Green = 0x00FF00;
uint32_t Sketch2Yellow = 0xFFFF00;
uint32_t Sketch2Pink = 0xFF69B4;
uint32_t Sketch2Orange = 0xFF8000;

/* rainbow1 */
uint32_t colorRed = 0xFF0000;
uint32_t colorOrange = 0xFF6600;
uint32_t colorYellow = 0xFFFF00;
uint32_t colorGreen = 0x00FF00;
uint32_t colorBlue = 0x0000FF;
uint32_t colorPurple = 0x660CCF;
uint32_t colorPink = 0xFF69B4;

/* rainbow2 */
uint32_t colorone= 0xFF007F;
uint32_t colortwo= 0x6200FF;
uint32_t colorthree= 0xBEFF00;
uint32_t colorfour= 0x00FF34;
uint32_t colorfive= 0x0400FF;
uint32_t colorsix= 0x2600CA;


uint32_t CurrentColor = Sketch2Pink;




int rainbowBright = 255;
int rainbowBrightReducation;

/**

  NAVIGATION Declarations

*/

boolean ValueZeroReached = false;
boolean ValueHighReached = false;
int ValueHighlight = 0;
long ValueHighlightTime;
long ValueZeroTime, ValueHighTime;
int ValueZeroAdjustment = 20;

boolean waitingFlag = false;
boolean WaitForModeChange = true;
boolean routinesStartup = true;

int FlashDelay;
int ModeFlashDelay = 100;
boolean initial = true;

bool clicked = false;

bool nothingBroken = true;
bool breakdelayA0 = false;
bool breakdelayA1 = false;
bool breakdelayA2 = false;

long WaitTime = 200;


const int STARTUP_DATA = 0xBEEFDEED;
uint16_t storedAddress = 0;
    
// Create a structure that is big enough to contain a Bank
// and a Mode. The "valid" variable is set to "true" once
// the structure is filled with actual data for the first time.
typedef struct
{
  int savedBank;
  int savedMode;
  int savedMaxBright;
} savedData;



// Create a "savedData" variable and call it "dataz"
  savedData dataz;

// Check signature at address 0
int startup;
int startupBank;
int startupMode;
int startupMaxBright;

int Mode = 1;
int Bank = 1;
int MaxBright = 255; // Strip Max Bright
int MaxBrightTemp = 190;
int MaxBrightReduction;
int MaxBrightReductionQuad1;
int MaxBrightReductionQuad2;
int MaxBrightReductionQuad3;
int MaxBrightReductionQuad4;
int MaxBrightRainbow;

boolean plotterPrint = true;

/**

  STRANGE ATTRACTORZ Declarations

*/

//Coordinates for the lorenz function
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
int fadeAmount = 1;  //Change it to adjust the fading between each step (fading speed)
int maxBrightness = 190; //Pixel Max Bright
int maxBrightnessTemp = 190; //Pixel Max Bright
int delayAmount = 0;
int strangeRandom;
int strangeSlowAmount;
int strangeSlowCount;

/**

  Mountain Snack Mode declarations

*/

// easily adjustable parameters

int color = 0; // change between 0, 1, 2 to set the color of the pixel (currently not used)
float minLength = 1000; // minimum length, shortest cycle time in milliseconds
float maxLength = 100096; // this plus minLength is the longest the loop can be, in milliseconds
bool reRandom = false; // whether or not the random numbers are reset on each loop
int maximumScale = 90;

// other variables that probably shouldn't be poked at without some thought

unsigned long milli;
int lastMillis;
const int loopLength = 2048; // size of the arrays that i'm using
float currentLoc;
int currentStep;
int currentVal;
int newCalibrate1;
int newValue1;
float targetSpeed; // length of the cycle as calculated by valueA0
float speedControl;

// Snack

bool snackEat = false;
float snackChance;
int snackMilli;
long snackRandom;
int snackInterval; // length of time between each potential snack, currently relative to targetSpeed
int snackLength; // rough length of the snack, also relative to targetSpeed
int snackLengthRandom; // a random number between -50 and 50 added to snackLength to give some variation on the length of the snack
int delaySnackLength; // the addition of snackLength & snackLengthRandom

int sumArray[loopLength];
int scaledVal;
boolean waitDelay = true;

float randomAmount;
const int randomDensity = 8;
int randomCore[randomDensity];
int randomNumbers[loopLength];


// Rainbowz2

boolean increaseValue = true;
int modulateSpeed = 0;
int modulateConstrain;




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
  strip.begin();
  inner.begin();
  
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

  clicked = false;

  
  // Set a Startup Mode
  Bank = 1;
  Mode = 0;

  routinesStartup = true;
  readStartupBank();
  

  
  setRandoms();
  plotterPrint = false; // This prints to the Serial.Plotter and when set to True can slow down some Modez. Set to False to remove Serial Plotting of Values
  
}

/**

  Loop

*/


void loop() {
 
  // This is the function that handles startup and Mode switching
  
  Routines();

  

  //Explicit Functions and Modes can be set here, instead of the Routines
  //mountainSnack();

  // plotCycle writes values to the Serial Monitor for plotting/
  // This is sprinkled throughout the code in-order to update the values on the Serial Plotter
  
  plotCycle();
  checkButtons();

  // Some memory Print
  //Serial.print(F("freeMemory: "));
  //Serial.println((int)freeMemory);


}

/**

  Reading and Writing to FLASH/ EEPROM Memory

  This Section reads the startupMode value and uses it for the Mode after startup and writes the startupMode value for the current Mode

*/



/**

  ATTRIBUTION


  Routine & ValueHigh/ Low
  * Programmer : Ranga Marasinghe
  * Date       : 2021-April-22
  * https://www.fiverr.com/ranga_niroshan

  Fading
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
