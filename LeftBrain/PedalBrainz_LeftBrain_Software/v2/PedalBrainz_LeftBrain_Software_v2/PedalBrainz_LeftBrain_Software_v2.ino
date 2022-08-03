//  Welcome to Pedal Brainz
//
//
//  -Lost Lab


/**

  ARDUINO Libraries in-use
  These must be included in your Arduino Environment using /Sketch/Include Libraries/Manage Libraries... or by importing the Library .zip directly

*/

#define NUMPIXELS 3 // Number of LEDs in strip
#define PINSTRIP 4 // Pin used for the strip (knobs)
#define MAX_POWER 100
#define VOLTS 5

//#include <Adafruit_DotStar.h>
//#include <Adafruit_NeoPixel.h>

#include <FlashAsEEPROM_SAMD.h>
#include <MultiMap.h>

#include <FastLED_NeoPixel.h>
#include <FastLED.h>
// Declare our NeoPixel strip object:
//Adafruit_NeoPixel strip(NUMPIXELS, 4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel inner(1, 3, NEO_GRB + NEO_KHZ800);
//Adafruit_NeoPixel pixel(1, 7); // SEEED XIAO
Adafruit_NeoPixel pixel(1, PIN_NEOPIXEL);

//FastLED_NeoPixel <NUMPIXELS, 4, NEO_GRB + NEO_KHZ800> strip;
//FastLED_NeoPixel <1, 3, NEO_GRB + NEO_KHZ800> inner;
//FastLED_NeoPixel <1, PIN_NEOPIXEL> pixel;

#define NUM_LEDS_INNER 1

//CRGB leds[NUM_LEDS_INNER];
//CRGBArray<NUM_LEDS_INNER> ledsInner;
//FastLED_NeoPixel_Variant inner(ledsInner, NUM_LEDS_INNER);

#define NUM_LEDS 3

//CRGB leds[NUM_LEDS];
CRGBArray <NUM_LEDS> leds;
//FastLED_NeoPixel_Variant strip(leds, NUM_LEDS);
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

  POTENTIOMETER declarations

*/

// Setting the Button Pins
const int buttonPinUp = A9;     // Button Up
const int buttonPinDown =  A10;      // Button Down

bool buttonLongHoldUp;
bool buttonLongHoldDown;

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

float fadeSpeed = 13;
int fullDelay = 0;
int darkDelay = 0;

float fadeAmount = 1;  //Change it to adjust the fading between each step (fading speed)
float fadeAmountA1;
float fadeAmountA2;

int delayAmount = 0;

bool fadeUp;
bool fadeUpA1;
bool fadeUpA2;

float randomAmountA0 = 0;
float randomAmountA1 = 0;
float randomAmountA2 = 0;

int randomSaw = 0;

int delayRandom = random(0, 1000);
int delayValue = 0;
int delayValueA0 = 0;
int delayValueA1 = 0;
int delayValueA2 = 0;

uint16_t  count = 0;

// Sets the value in milleseconds of the slowest fadeSpeed for delayA0
int speedMinimum = 10000;
int speedMaximum = 0;

// Sets the value in milleseconds of the longest duration for delayA1 and delayA2
int durationMaximum = 10000;
//int durationMaximum = 5000;

int timeMultiplier;

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

uint32_t colorBlueDark = 0x0000FF;
uint32_t colorBlueLight = 0x004EFF;
uint32_t colorBlueLightest = 0x5AFFFF;
uint32_t colorBlueTurquoise = 0x00FFFF;
uint32_t colorGreenDark = 0x00FF00;
uint32_t colorGreenLight = 0x38FF00;
uint32_t colorGreenMint = 0x00FF2C;
uint32_t colorGreenPea = 0x64FF00;
uint32_t colorRedDark = 0xFF0000;
uint32_t colorRedLight = 0xFF0020;
uint32_t colorRedPurple = 0xFF00FF;


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

/**

  MEMORY Declarations

*/

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
  int savedMultiplier;
} savedData;



// Create a "savedData" variable and call it "dataz"
  savedData dataz;

// Check signature at address 0
int startup;
int startupBank;
int startupMode;
int startupMaxBright;
int startupMultiplier;
int MultiplierTemp;

int multiplierIndicatorValue;

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
float la = 10.0;
float lb = 28.0;
float lc = 8.0 / 3.0;

float lx = 0;
float ly = 0;
float lz = 0;

float ldx = 0;
float ldy = 0;
float ldz = 0;

//Coordinates for other attractorz
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
float scaledXInner;
float scaledYInner;
float scaledZInner;
float scaledInnerCombined;


//Constants for the lorenz function, KEEP UNCHANGED
float a = 10.0;
float b = 28.0;
float c = 8.0 / 3.0;
float d;
float e;
float f;
float g;

float timestep;

//Variables for lorenz function
float dx = 0;
float dy = 0;
float dz = 0;

//Variables for timing
float dt = 0.01;  //Time between interval (seconds) default: 10ms (0.01s) you can change it but the code become unstable
unsigned long nextAttractorzUpdate = 0;
int printDelay = 10; //Time between each serial print (default: 50ms)


float scalings[2][3] {
  {0, 0, 0}, //minX, minY, minZ
  {0, 0, 0} //maxX, maxY, maxZ
};

bool already = false; // the variable is used to restart only after two consecutive max values

float maxValue, minValue;

  float mapfloat(float b, float in_min, float in_max, float out_min, float out_max)
  {
    return (b - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  }

 void (* resetFunc)(void)=0; // declare reset function @ address 0 

int strangeRandom;
int strangeSlowAmount;
int strangeSlowCount;

bool firstAttractorzType;
int attractorzIndicatorValue = 0;
int attractorzLEDType = 0;

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
int scaledValTemp;
boolean waitDelay = true;

float randomAmount;
const int randomDensity = 8;
int randomCore[randomDensity];
int randomNumbers[loopLength];


/**

  RAINBOWZ2 Declarations

*/

int randomOnce = 0;
boolean increaseValue = true;
int modulateSpeed = 0;
int modulateConstrain;

static uint16_t xx;
static uint16_t yy;
static uint16_t zz;

int randomBright0 = 50;
int randomBright1 = 90;
int randomBright2 = 155;
int randomBright3 = 255;

int MaxBrightReductionQuad;
int MaxBrightReductionQuad0;
int MaxBrightReductionQuad1;
int MaxBrightReductionQuad2;
int MaxBrightReductionQuad3;

int InnerBrightReductionQuad;
int InnerBrightReductionQuad0;
int InnerBrightReductionQuad1;
int InnerBrightReductionQuad2;
int InnerBrightReductionQuad3;

int sawzDirection;

/* rainbow2 */
uint32_t colorone = 0xFF007F;
uint32_t colortwo = 0x6200FF;
uint32_t colorthree = 0xBEFF00;
uint32_t colorfour = 0x00FF34;
uint32_t colorfive = 0x0400FF;
uint32_t colorsix = 0x2600CA;


/**

  GAME Declarations

*/

// A counter to record the number of button presses made by the player
int numButtonPresses;

const int STATE_START_GAME        = 0;  // Initial state
const int STATE_PICK_RND_SEQUENCE = 1;  // Pick a random sequence of LEDs
const int STATE_SHOW_RND_SEQUENCE = 2;  // Show the randomly selected sequence of LED flashes
const int STATE_READ_PLAYER_GUESS = 3;  // Read the player's guess
const int STATE_VERIFY_GUESS      = 4;  // Check the guess against the random sequence
const int STATE_GUESS_CORRECT     = 5;  // Player guessed correctly
const int STATE_GUESS_INCORRECT   = 6;  // Player guessed incorrectly

// The current state the game is in
int currentState;
int nextState;

// The difficulty level (1..MAX_DIFFICULTY_LEVEL)
// (Do not set to zero!)
int difficultyLevel;


/**

  LIGHT LOOPZ Declarations

*/

bool pressedTapzUp = false;
bool pressedTapzDown = false;
boolean empty = false;
unsigned long startMillis;


/**

  BRIGHTNESS Declarations

*/

float brightness = 0;
int brightnessScaled;
int maxBrightness = 190; //Pixel Max Bright
int maxBrightnessTemp = 190; //Pixel Max Bright


// Average LEDS for getting the values of the Knob LEDs and using them

int avgLight;
int avgLight0;
int avgLight1;
int avgLight2;
int avgLightInner;
float innerValue;
float innerValueRed;
float innerValueBlue;
float innerValueGreen;

/**

  PALETTE Declarations

*/

CRGBPalette16 currentPalette;
TBlendType    currentBlending;

#define DITHER = 1;
#define FRAMES_PER_SECOND 60

int STEPS = 30;// STEPS set dynamically once we've started up



bool initialBank;
float startIndex = 0;



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
  //strip.begin(); LEDS.addLeds<LED_TYPE,LED_PIN,COLOR_ORDER>(leds,NUM_LEDS);
  strip.begin(FastLED.addLeds<WS2812B, PINSTRIP, GRB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip));
  //inner.begin(FastLED.addLeds<WS2812B, 3, GRB>(ledsInner, NUM_LEDS_INNER).setCorrection(TypicalLEDStrip));
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

  clicked = false;
  initialBank = false;
  
  // Set a Startup Mode
  // Default:
  // Bank = 1;
  // Mode = 0;

  Bank = 1;
  Mode = 0;

  timeMultiplier = 1;

  speedMinimum = 10000;
  durationMaximum = 10000;

  setTimeMultiplier();

  buttonLongHoldUp = false;
  buttonLongHoldDown = false;

  // This catches at the end of the Routines() and writeStartupDataz()
  routinesStartup = true;

  // Game Setups
  difficultyLevel = 1;
  currentState = STATE_START_GAME;
  nextState = currentState;
  numButtonPresses = 0;

  // Recorderz Setup
  //empty=true;
  initial = true;

  setRandoms();
  plotterPrint = false; // This prints to the Serial.Plotter and when set to True can slow down some Modez. Set to False to remove Serial Plotting of Values
  startMillis = millis();  //initial start time
}

/**

  Loop

*/


void loop() {
 
  // This is the function that handles startup and Mode switching
  
  checkResetDefault();
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
