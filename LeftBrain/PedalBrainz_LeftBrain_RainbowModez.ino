
//  Welcome to Pedal Brainz
//
//  Mode Change
//  All potentiometers to zero fully counter clockwise (left) for 1 second then rotate potentiometer A2 clockwise (right) from zero for Mode Change.
//
//  Mode Save
//  The last Mode used will be saved as the Startup Mode.
//
//
//  Mode 1 | Rainbowz
//  A0 = Rainbow Cycle Speed
//  A1 = Maximum Brightness
//  A2 = Duration when LED is fully off (It's Dark)
//
//  Mode 2 | Rainbowz Random
//  A0 = Rainbow Cycle Speed
//  A1 = Randomized Maximum Brightness
//  A2 = Duration when LED is fully off (It's Dark)
//
//  Modez 3,4,5 | Rainbowz Cycle
//  Cycles through 6 colors. The Brightness of each color is modulated 4 times. Default brightness set in declarations.
//  Modez 3 - Uses randomBright01-04 Declared in General Declarations
//  Modez 4 - Randomize Brightness values for the 4 values once at startup
//  Modez 5 - Randomize Brightness values for the 4 values after each cycle
//
//  Set Color -> Set 4 Brightness Values w/ Delay (A1) -> Delay before setting next Color (A0)
//  
//  A0 = Duration of 4th brightness after brightness changes for a single color
//  A1 = Delay of each Brightness Value (4) for a Single Color
//  A2 = Duration of Darkness after full Color Cycle (or betwixt each color if darkDelayBetwixtColors is enabled)
//
//  Mode 6 | Mountainz Rainbow Random Repeat
//  A0 = Cycle Speed
//  A1 = Amount of Randomness
//  A2 = Chance of Snack
//
//  Mode 7 | Mountainz Rainbow Random Random
//  A0 = Cycle Speed
//  A1 = Amount of Randomness
//  A2 = Chance of Snack
//
//  Mode 8 | Rainbow Squarez
//  A0 = Cycle Speed
//  A1 = Amount of Randomness
//  A2 = Chance of Snack 
//
//  Mode 9 | Rainbow Squarez Random
//  A0 = Cycle Speed
//  A1 = Amount of Randomness
//  A2 = Chance of Snack
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

/**

  Adafruit_DotStar Library declaration
  Set the on-board DotStar as "pixel".

*/

Adafruit_DotStar pixel = Adafruit_DotStar(1, INTERNAL_DS_DATA, INTERNAL_DS_CLK, DOTSTAR_BGR);

/**

  POTENTIOMETER declarations

*/

int valueA0 = 135;
int valueA1 = 0;
int valueA2 = 0;

/**

  FlashAsEEPROM_SAMD Library declarations
  FLASH MEMORY/ EEPROM for reading and writing the startup mode

*/

uint16_t address = 0;
int number;
int startupMode = 1;



/**

  General declarations
  Some colors, some randoms, some brightness

*/

// Set a default variable for the red, blue, and green (RGB) value of the on-board Dot Star
// Pink! Potentiometer A0: 236 Potentiometer A1: 73 Potentiometer A2: 107

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
int speedMinimum = 5000;

// Sets the value in milleseconds of the longest duration for delayA1 and delayA2
int durationMaximum = 10000;

int valueLog;

unsigned long myTime;
int LEDBrightness;

// Some Colors
uint32_t colorRed = 0xFF0000;
uint32_t colorOrange = 0xFF6600;
uint32_t colorYellow = 0xFFFF00;
uint32_t colorGreen = 0x00FF00;
uint32_t colorBlue = 0x0000FF;
uint32_t colorPurple = 0x660CCF;
uint32_t colorPink = 0xFF69B4;
uint32_t Sketch2Blue = 0x0000FF;
uint32_t Sketch2Red = 0xFF0000;
uint32_t Sketch2Green = 0x00FF00;
uint32_t Sketch2Yellow = 0xFFFF00;
uint32_t Sketch2Pink = 0xFF69B4;
uint32_t Sketch2Orange = 0xFF8000;
uint32_t CurrentColor = Sketch2Pink;

int randomBright01 = 20;
int randomBright02 = 60;
int randomBright03 = 110;
int randomBright04 = 170;

int randomOnce = 0;


/**

  ROUTINES Declarations

*/


int FlashDelay;
int Brightnesslevel;
int rainbowBright = 255;

boolean waitingFlag = false;
boolean WaitForModeChange = true;

boolean ValueZeroReached = false;
boolean ValueHighReached = false;
int ValueHighlight = 0;
long ValueHighlightTime;
long ValueZeroTime, ValueHighTime;
int ValueZeroAdjustment = 20;

int ModeFlashDelay = 100;
boolean initial = true;

boolean plotterPrint = true;

long WaitTime = 200;

int Mode = 0;

int currentVal;
float randomAmount;
int controlAmount;
int x;

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

int newCalibrate1;
int newValue1;
float targetSpeed; // length of the cycle as calculated by valueA0
float speedControl;
bool snackEat = false;
float snackChance;
int snackMilli;
long snackRandom;
int snackInterval; // length of time between each potential snack, currently relative to targetSpeed
int snackLength; // rough length of the snack, also relative to targetSpeed
int snackLengthRandom; // a random number between -50 and 50 added to snackLength to give some variation on the length of the snack
int delaySnackLength; // the addition of snackLength & snackLengthRandom
int scaledVal;

const int randomDensity = 8;

int randomCore[randomDensity];
int randomNumbers[loopLength];

int sumArray[loopLength];

int strangeRandom;
int strangeSlowAmount;
int delayAmount = 0;


/**

  Rainbowz Declarations

*/

unsigned short pixelnumber = 0;
int maxBrightness = 190;
boolean increaseValue = true;
int modulateSpeed = 0;
int modulateConstrain;


/**

  Rainbow Mode - Arrays of numbers

*/

const uint8_t lights[360] = {
  0,   0,   0,   0,   0,   1,   1,   2,
  2,   3,   4,   5,   6,   7,   8,   9,
  11,  12,  13,  15,  17,  18,  20,  22,
  24,  26,  28,  30,  32,  35,  37,  39,
  42,  44,  47,  49,  52,  55,  58,  60,
  63,  66,  69,  72,  75,  78,  81,  85,
  88,  91,  94,  97, 101, 104, 107, 111,
  114, 117, 121, 124, 127, 131, 134, 137,
  141, 144, 147, 150, 154, 157, 160, 163,
  167, 170, 173, 176, 179, 182, 185, 188,
  191, 194, 197, 200, 202, 205, 208, 210,
  213, 215, 217, 220, 222, 224, 226, 229,
  231, 232, 234, 236, 238, 239, 241, 242,
  244, 245, 246, 248, 249, 250, 251, 251,
  252, 253, 253, 254, 254, 255, 255, 255,
  255, 255, 255, 255, 254, 254, 253, 253,
  252, 251, 251, 250, 249, 248, 246, 245,
  244, 242, 241, 239, 238, 236, 234, 232,
  231, 229, 226, 224, 222, 220, 217, 215,
  213, 210, 208, 205, 202, 200, 197, 194,
  191, 188, 185, 182, 179, 176, 173, 170,
  167, 163, 160, 157, 154, 150, 147, 144,
  141, 137, 134, 131, 127, 124, 121, 117,
  114, 111, 107, 104, 101,  97,  94,  91,
  88,  85,  81,  78,  75,  72,  69,  66,
  63,  60,  58,  55,  52,  49,  47,  44,
  42,  39,  37,  35,  32,  30,  28,  26,
  24,  22,  20,  18,  17,  15,  13,  12,
  11,   9,   8,   7,   6,   5,   4,   3,
  2,   2,   1,   1,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0
};

const uint8_t HSVlights[61] =
{ 0, 4, 8, 13, 17, 21, 25, 30, 34, 38, 42, 47, 51, 55, 59, 64, 68, 72, 76,
  81, 85, 89, 93, 98, 102, 106, 110, 115, 119, 123, 127, 132, 136, 140, 144,
  149, 153, 157, 161, 166, 170, 174, 178, 183, 187, 191, 195, 200, 204, 208,
  212, 217, 221, 225, 229, 234, 238, 242, 246, 251, 255
};

const uint8_t HSVpower[121] =
{ 0, 2, 4, 6, 8, 11, 13, 15, 17, 19, 21, 23, 25, 28, 30, 32, 34, 36, 38, 40,
  42, 45, 47, 49, 51, 53, 55, 57, 59, 62, 64, 66, 68, 70, 72, 74, 76, 79, 81,
  83, 85, 87, 89, 91, 93, 96, 98, 100, 102, 104, 106, 108, 110, 113, 115, 117,
  119, 121, 123, 125, 127, 130, 132, 134, 136, 138, 140, 142, 144, 147, 149,
  151, 153, 155, 157, 159, 161, 164, 166, 168, 170, 172, 174, 176, 178, 181,
  183, 185, 187, 189, 191, 193, 195, 198, 200, 202, 204, 206, 208, 210, 212,
  215, 217, 219, 221, 223, 225, 227, 229, 232, 234, 236, 238, 240, 242, 244,
  246, 249, 251, 253, 255
};

/**

  Mountain Snack Mode Arrays of Numbers

*/


PROGMEM const int sine2048[] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9,
  9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15, 15, 16,
  16, 16, 16, 16, 17, 17, 17, 17, 17, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 20, 20, 20, 20, 20, 21, 21, 21, 21, 21, 22, 22, 22, 22, 23, 23, 23, 23, 23, 24, 24,
  24, 24, 25, 25, 25, 25, 26, 26, 26, 26, 27, 27, 27, 27, 27, 28, 28, 28, 28, 29, 29, 29, 29, 30, 30, 30, 30, 31, 31, 31, 31, 32, 32, 32, 33, 33, 33, 33, 34, 34,
  34, 34, 35, 35, 35, 35, 36, 36, 36, 37, 37, 37, 37, 38, 38, 38, 38, 39, 39, 39, 40, 40, 40, 40, 41, 41, 41, 42, 42, 42, 42, 43, 43, 43, 44, 44, 44, 45, 45, 45,
  45, 46, 46, 46, 47, 47, 47, 48, 48, 48, 48, 49, 49, 49, 50, 50, 50, 51, 51, 51, 52, 52, 52, 52, 53, 53, 53, 54, 54, 54, 55, 55, 55, 56, 56, 56, 57, 57, 57, 58,
  58, 58, 59, 59, 59, 60, 60, 60, 61, 61, 61, 62, 62, 62, 63, 63, 63, 64, 64, 64, 65, 65, 65, 66, 66, 66, 67, 67, 67, 68, 68, 68, 69, 69, 69, 70, 70, 71, 71, 71,
  72, 72, 72, 73, 73, 73, 74, 74, 74, 75, 75, 75, 76, 76, 77, 77, 77, 78, 78, 78, 79, 79, 79, 80, 80, 81, 81, 81, 82, 82, 82, 83, 83, 83, 84, 84, 85, 85, 85, 86,
  86, 86, 87, 87, 88, 88, 88, 89, 89, 89, 90, 90, 90, 91, 91, 92, 92, 92, 93, 93, 93, 94, 94, 95, 95, 95, 96, 96, 97, 97, 97, 98, 98, 98, 99, 99, 100, 100, 100, 101,
  101, 101, 102, 102, 103, 103, 103, 104, 104, 105, 105, 105, 106, 106, 106, 107, 107, 108, 108, 108, 109, 109, 110, 110, 110, 111, 111, 112, 112, 112, 113, 113, 113, 114, 114, 115, 115, 115, 116, 116,
  117, 117, 117, 118, 118, 119, 119, 119, 120, 120, 120, 121, 121, 122, 122, 122, 123, 123, 124, 124, 124, 125, 125, 126, 126, 126, 127, 127, 128, 128, 128, 128, 129, 129, 129, 130, 130, 131, 131, 131, 132, 132, 133, 133, 133, 134, 134, 135, 135,
  135, 136, 136, 136, 137, 137, 138, 138, 138, 139, 139, 140, 140, 140, 141, 141, 142, 142, 142, 143, 143, 143, 144, 144, 145, 145, 145, 146, 146, 147, 147, 147, 148, 148, 149, 149, 149, 150, 150, 150,
  151, 151, 152, 152, 152, 153, 153, 154, 154, 154, 155, 155, 155, 156, 156, 157, 157, 157, 158, 158, 158, 159, 159, 160, 160, 160, 161, 161, 162, 162, 162, 163, 163, 163, 164, 164, 165, 165, 165, 166,
  166, 166, 167, 167, 167, 168, 168, 169, 169, 169, 170, 170, 170, 171, 171, 172, 172, 172, 173, 173, 173, 174, 174, 174, 175, 175, 176, 176, 176, 177, 177, 177, 178, 178, 178, 179, 179, 180, 180, 180,
  181, 181, 181, 182, 182, 182, 183, 183, 183, 184, 184, 184, 185, 185, 186, 186, 186, 187, 187, 187, 188, 188, 188, 189, 189, 189, 190, 190, 190, 191, 191, 191, 192, 192, 192, 193, 193, 193, 194, 194,
  194, 195, 195, 195, 196, 196, 196, 197, 197, 197, 198, 198, 198, 199, 199, 199, 200, 200, 200, 201, 201, 201, 202, 202, 202, 203, 203, 203, 203, 204, 204, 204, 205, 205, 205, 206, 206, 206, 207, 207,
  207, 207, 208, 208, 208, 209, 209, 209, 210, 210, 210, 210, 211, 211, 211, 212, 212, 212, 213, 213, 213, 213, 214, 214, 214, 215, 215, 215, 215, 216, 216, 216, 217, 217, 217, 217, 218, 218, 218, 218,
  219, 219, 219, 220, 220, 220, 220, 221, 221, 221, 221, 222, 222, 222, 222, 223, 223, 223, 224, 224, 224, 224, 225, 225, 225, 225, 226, 226, 226, 226, 227, 227, 227, 227, 228, 228, 228, 228, 228, 229,
  229, 229, 229, 230, 230, 230, 230, 231, 231, 231, 231, 232, 232, 232, 232, 232, 233, 233, 233, 233, 234, 234, 234, 234, 234, 235, 235, 235, 235, 235, 236, 236, 236, 236, 236, 237, 237, 237, 237, 237,
  238, 238, 238, 238, 238, 239, 239, 239, 239, 239, 240, 240, 240, 240, 240, 240, 241, 241, 241, 241, 241, 242, 242, 242, 242, 242, 242, 243, 243, 243, 243, 243, 243, 244, 244, 244, 244, 244, 244, 245,
  245, 245, 245, 245, 245, 245, 246, 246, 246, 246, 246, 246, 246, 247, 247, 247, 247, 247, 247, 247, 248, 248, 248, 248, 248, 248, 248, 248, 249, 249, 249, 249, 249, 249, 249, 249, 250, 250, 250, 250,
  250, 250, 250, 250, 250, 250, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253,
  253, 253, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
  255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
  255, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 252, 252, 252,
  252, 252, 252, 252, 252, 252, 252, 252, 252, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 249, 249, 249, 249, 249, 249, 249, 249, 248, 248, 248,
  248, 248, 248, 248, 248, 247, 247, 247, 247, 247, 247, 247, 246, 246, 246, 246, 246, 246, 246, 245, 245, 245, 245, 245, 245, 245, 244, 244, 244, 244, 244, 244, 243, 243, 243, 243, 243, 243, 242, 242,
  242, 242, 242, 242, 241, 241, 241, 241, 241, 240, 240, 240, 240, 240, 240, 239, 239, 239, 239, 239, 238, 238, 238, 238, 238, 237, 237, 237, 237, 237, 236, 236, 236, 236, 236, 235, 235, 235, 235, 235,
  234, 234, 234, 234, 234, 233, 233, 233, 233, 232, 232, 232, 232, 232, 231, 231, 231, 231, 230, 230, 230, 230, 229, 229, 229, 229, 228, 228, 228, 228, 228, 227, 227, 227, 227, 226, 226, 226, 226, 225,
  225, 225, 225, 224, 224, 224, 224, 223, 223, 223, 222, 222, 222, 222, 221, 221, 221, 221, 220, 220, 220, 220, 219, 219, 219, 218, 218, 218, 218, 217, 217, 217, 217, 216, 216, 216, 215, 215, 215, 215,
  214, 214, 214, 213, 213, 213, 213, 212, 212, 212, 211, 211, 211, 210, 210, 210, 210, 209, 209, 209, 208, 208, 208, 207, 207, 207, 207, 206, 206, 206, 205, 205, 205, 204, 204, 204, 203, 203, 203, 203,
  202, 202, 202, 201, 201, 201, 200, 200, 200, 199, 199, 199, 198, 198, 198, 197, 197, 197, 196, 196, 196, 195, 195, 195, 194, 194, 194, 193, 193, 193, 192, 192, 192, 191, 191, 191, 190, 190, 190, 189,
  189, 189, 188, 188, 188, 187, 187, 187, 186, 186, 186, 185, 185, 184, 184, 184, 183, 183, 183, 182, 182, 182, 181, 181, 181, 180, 180, 180, 179, 179, 178, 178, 178, 177, 177, 177, 176, 176, 176, 175,
  175, 174, 174, 174, 173, 173, 173, 172, 172, 172, 171, 171, 170, 170, 170, 169, 169, 169, 168, 168, 167, 167, 167, 166, 166, 166, 165, 165, 165, 164, 164, 163, 163, 163, 162, 162, 162, 161, 161, 160,
  160, 160, 159, 159, 158, 158, 158, 157, 157, 157, 156, 156, 155, 155, 155, 154, 154, 154, 153, 153, 152, 152, 152, 151, 151, 150, 150, 150, 149, 149, 149, 148, 148, 147, 147, 147, 146, 146, 145, 145,
  145, 144, 144, 143, 143, 143, 142, 142, 142, 141, 141, 140, 140, 140, 139, 139, 138, 138, 138, 137, 137, 136, 136, 136, 135, 135, 135, 134, 134, 133, 133, 133, 132, 132, 131, 131, 131, 130, 130, 129,
  129, 129, 128, 128, 128, 127, 127, 126, 126, 126, 125, 125, 124, 124, 124, 123, 123, 122, 122, 122, 121, 121, 120, 120, 120, 119, 119, 119, 118, 118, 117, 117, 117, 116, 116, 115, 115, 115, 114, 114,
  113, 113, 113, 112, 112, 112, 111, 111, 110, 110, 110, 109, 109, 108, 108, 108, 107, 107, 106, 106, 106, 105, 105, 105, 104, 104, 103, 103, 103, 102, 102, 101, 101, 101, 100, 100, 100, 99, 99, 98,
  98, 98, 97, 97, 97, 96, 96, 95, 95, 95, 94, 94, 93, 93, 93, 92, 92, 92, 91, 91, 90, 90, 90, 89, 89, 89, 88, 88, 88, 87, 87, 86, 86, 86, 85, 85, 85, 84, 84, 83,
  83, 83, 82, 82, 82, 81, 81, 81, 80, 80, 79, 79, 79, 78, 78, 78, 77, 77, 77, 76, 76, 75, 75, 75, 74, 74, 74, 73, 73, 73, 72, 72, 72, 71, 71, 71, 70, 70, 69, 69,
  69, 68, 68, 68, 67, 67, 67, 66, 66, 66, 65, 65, 65, 64, 64, 64, 63, 63, 63, 62, 62, 62, 61, 61, 61, 60, 60, 60, 59, 59, 59, 58, 58, 58, 57, 57, 57, 56, 56, 56,
  55, 55, 55, 54, 54, 54, 53, 53, 53, 52, 52, 52, 52, 51, 51, 51, 50, 50, 50, 49, 49, 49, 48, 48, 48, 48, 47, 47, 47, 46, 46, 46, 45, 45, 45, 45, 44, 44, 44, 43,
  43, 43, 42, 42, 42, 42, 41, 41, 41, 40, 40, 40, 40, 39, 39, 39, 38, 38, 38, 38, 37, 37, 37, 37, 36, 36, 36, 35, 35, 35, 35, 34, 34, 34, 34, 33, 33, 33, 33, 32,
  32, 32, 31, 31, 31, 31, 30, 30, 30, 30, 29, 29, 29, 29, 28, 28, 28, 28, 27, 27, 27, 27, 27, 26, 26, 26, 26, 25, 25, 25, 25, 24, 24, 24, 24, 23, 23, 23, 23, 23,
  22, 22, 22, 22, 21, 21, 21, 21, 21, 20, 20, 20, 20, 20, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 17, 17, 17, 17, 17, 16, 16, 16, 16, 16, 15, 15, 15, 15, 15, 15,
  14, 14, 14, 14, 14, 13, 13, 13, 13, 13, 13, 12, 12, 12, 12, 12, 12, 11, 11, 11, 11, 11, 11, 10, 10, 10, 10, 10, 10, 10, 9, 9, 9, 9, 9, 9, 9, 8, 8, 8,
  8, 8, 8, 8, 7, 7, 7, 7, 7, 7, 7, 7, 6, 6, 6, 6, 6, 6, 6, 6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};


/**

  Setup

*/

void setup() {
  Serial.begin(115200);
  /* Start the DotStar LED */
  pixel.begin();
  pixel.setBrightness(maxBrightness);
  pixel.setPixelColor(0, redValue, blueValue, greenValue);
  pixel.show();
  
  setRandoms();
  
  // Set a Startup Mode
  Mode = 8;

  fadeSpeed = 0;
  
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

  // Some memory Print
  //Serial.print(F("freeMemory: "));
  //Serial.println((int)freeMemory);


}


/**

  Routines

  This is where the Mode switching and waiting happens within the loop.

*/


void Routines()
{

  // Pring the Mode value currently initialized
  //Serial.println("Mode : "+ String(Mode));

  plotCycle();

  //This is the initial startup mode (Mode = 0)
  //Things are about to start kicking in...

  if (Mode == 0)
  {
    // On first power cycle, do this thing so that folks know things are getting ready
    
    // Fade in from the beginning of the Rainbow cycle (starts with the color Red) using some default values
    // This "for loop" adds to "x" which is set to zero (0) until it reaches 255 (Max Brightness)
    for (int x = 0; x < 255; x++)
    {
      //Setting a default rate for the rainbow cycling during startup
      valueA0 = 2;
      valueA2 = 255;

      // Increase the value of the Red value (x) causing a fade in;
      // "pixel" = what we defined the "Adafruit_DotStar" at the start of this Sketch
      // setPixelColor - how to set the pixel color
      // pixelnumber - defined as zero (0) above
      // 0, 0, 0 - These are the R(ed), G(reen), B(lue), values of the pixel from 0-255
      // x is currently being used as a variable to increment/ decrement the fade

      pixel.setPixelColor(pixelnumber, x, 0, 0);

      // A delay amount between each increase in colorvalue
      // Currently using the default for A0 set above
      delay(valueA0 / 2);
      pixel.show();
    }

    //Run the Rainbow cycle
    for (int k = 0; k < 360; k++)
    {

      // Rainbow Mode was adapted from an example online (See attribution at the end)
      // Several types of rainbow cycling were included and kept
      // Uncomment one of the mode (or modes?) to use for Rainbow Mode

      // trueHSV(0, k);
      powerHSV(0, k);
      // sineLED(0, k);
      pixel.show();

      // Set the rate of the rainbow cycling during initialization
      valueA0 = 2;
      delay(valueA0);

      // Set the maximum brightness of the pixel during initialization
      valueA2 = 255;
      pixel.setBrightness(valueA2);

    }


    // Fade out from the end of the Rainbow (lol) cycle (ends with the color Red)
    for (int x = 255; x >= 0; x--)
    {
      // Setting a default rate for the rainbow cycling during startup
      valueA0 = 2;
      valueA2 = 255;

      // Reduces the value of the Red (x) value causing a fade out
      pixel.setPixelColor(pixelnumber, x, 0, 0);

      // A delay amount between each increase in colorvalue
      // Currently using the default for A0 set above
      delay(valueA0 / 2);
      pixel.show();
    }

    // Add a delay (ms) at the end of the rainbow cycle using potantiometer A2 while the LED is dark
    valueA1 = 0;
    //delay(valueA1);

    //Serial.println("Rate of Rainbow cycling: " + String(valueA0)  + " ||| Delay between Rainbow cycles (ms): " + String(valueA1) + " ||| Maximum Brightness value: " + String(valueA2));
    //delay(400);

    /**

      Read & Set Startup Mode

    */

    // Read the values of Startup Mode
    readStartupMode();
    Serial.println("I Read startupMode - " + String(startupMode));

    // Set the Mode to the value of startupMode
    Mode = startupMode;
    Serial.println("Mode set to startupMode - " + String(Mode));

    // If the Mode is 1 or less, set the Mode to 1
    // If there's nothing saved start Modes from the beginning
    if (1 >= Mode)
    {
      Mode = 1;
      Serial.println("Mode was equal to or less than - " + String(Mode));
    }

    // If the Mode is 2 or more, set the Mode to startupMode
    // If a mode has been saved, set the saved startupMode as the Mode
    else if (2 <= Mode)
    {
      Mode = startupMode;
      Serial.println("Mode was greater than one - " + String(Mode));
    }

  }

  /**

    Modez

  */

 //Rainbow 01
  if (Mode == 1)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      modeFlash();

      //Do the last thing and WaitForModeChange

      pixel.setBrightness(100);
      pixel.setPixelColor(0, 36, 200, 10);
      pixel.show();

      writeStartupMode();

      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
    else
    {
      if (WaitForModeChange)
      {

        //Call the main routine and loop the thing
        RainbowMode ();
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }

  //Rainbow 02
  if (Mode == 2)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      modeFlash();

      //Do the last thing and WaitForModeChange

      pixel.setBrightness(100);
      pixel.setPixelColor(0, 36, 200, 10);
      pixel.show();

      writeStartupMode();

      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
    else
    {
      if (WaitForModeChange)
      {

        //Call the main routine and loop the thing
        RainbowMode ();
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }


  // 
  if (Mode == 3)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      modeFlash();

      //Do the last thing and WaitForModeChange

      pixel.setBrightness(255);
      pixel.setPixelColor(0, 0, 255, 60);
      //31,255,60
      pixel.show();

      writeStartupMode();

      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
    else
    {
      if (WaitForModeChange)
      {

        // Call the main routine and loop the thing
        brightnessBlink6();
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }

  //
  if (Mode == 4)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      modeFlash();

      //Do the last thing and WaitForModeChange

      pixel.setBrightness(100);
      pixel.setPixelColor(0, 36, 200, 10);
      pixel.show();

      writeStartupMode();

      randomOnce = 0;

      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
    else
    {
      if (WaitForModeChange)
      {

        //Call the main routine and loop the thing
        brightnessBlink6();
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }

  //
  if (Mode == 5)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      modeFlash();

      //Do the last thing and WaitForModeChange

      pixel.setBrightness(100);
      pixel.setPixelColor(0, 36, 200, 10);
      pixel.show();

      writeStartupMode();

      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
    else
    {
      if (WaitForModeChange)
      {

        //Call the main routine and loop the thing
        brightnessBlink6();
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }

  // 
  if (Mode == 6)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      modeFlash();

      // Do the last thing and WaitForModeChange

      pixel.setBrightness(100);
      pixel.setPixelColor(0, 36, 200, 10);
      pixel.show();

      writeStartupMode();

      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
     else
    {
      if (WaitForModeChange)
      {

        //Call the main routine and loop the thing
        mountainSnack();
        reRandom = false;
        
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }

 // 
  if (Mode == 7)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      modeFlash();

      //Do the last thing and WaitForModeChange

      pixel.setBrightness(100);
      pixel.setPixelColor(0, 36, 200, 10);
      pixel.show();

      writeStartupMode();    

      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
     else
    {
      if (WaitForModeChange)
      {

        //Call the main routine and loop the thing
        mountainSnack();
        reRandom = true;
        
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }

  // 
  if (Mode == 8)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      modeFlash();

      //Do the last thing and WaitForModeChange

      pixel.setBrightness(100);
      pixel.setPixelColor(0, 36, 200, 10);
      pixel.show();

      writeStartupMode();

      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
    else
    {
      if (WaitForModeChange)
      {

        //Call the main routine and loop the thing
       RainbowSquarez();
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }

  // 
  if (Mode == 9)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      modeFlash();

      //Do the last thing and WaitForModeChange

      pixel.setBrightness(100);
      pixel.setPixelColor(0, 36, 200, 10);
      pixel.show();

      writeStartupMode();

      increaseValue = true;
      //fadeSpeed = 10;
      
      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
     else
    {
      if (WaitForModeChange)
      {

        //Call the main routine and loop the thing
        //Serial.println("INIT fadeSpeed: " + String(fadeSpeed));
        RainbowSquarez();
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }

  //
  if (Mode == 10)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      modeFlash();

      //Do the last thing and WaitForModeChange

      pixel.setBrightness(100);
      pixel.setPixelColor(0, 36, 200, 10);
      pixel.show();

      writeStartupMode();

      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
     else
    {
      if (WaitForModeChange)
      {

        // Call the main routine and loop the thing

      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }

}




/**

  A0 Delay - Fade Speed

*/


void delayA0(int count)
{

  int delayCountA0 = fadeSpeed;

  plotCycle();

  for (int count = 0; count <= delayCountA0; count++) {

    delayCountA0 = fadeSpeed;

    plotCycle();

    if ((analogRead(A0) <= ValueZeroAdjustment) && (analogRead(A1) <= ValueZeroAdjustment) && (analogRead(A2) <= ValueZeroAdjustment)) {
      count = 0;
      Serial.println("I Broke");
      break;
    }

    // Potentiometer Top Right | A0 - Map the value of the Potentiometer to a Variable
    if (Mode == 1) {
      //fadeSpeed = map(analogRead(A0), 0, 1024, (speedMinimum/10), -1);
      //Serial.println("Mode 4 fadeSpeeed: " + String(fadeSpeed));

      // This makes the potentiometer slower to change when reducting from full and gives better control fidelity at higher speeds
      // This is a map of values for the potentiometer. note: the in array should have increasing values
      int in[]  = {0, 25.5,51,76.5,102,127.5,153,178.5,204,229.5,255};
      // This is a map of values for potentiometer curve type.
      int out[] = { 2300,2298,2296,2295,2292,2200,2100,2000,1800,1300,0 };  // 11
      // This maps the potentiometer scale.
      controlAmount  = map(analogRead(A0), 0, 1024, 255, 0);
      // This is a multimap that assigns values from the [in] array (potentiometer) to values from the [out] array (curve)
      x = multiMap(controlAmount, in, out, 11);
      // This maps the values for the Modez.
      fadeSpeed = map(x, 0, 2300, speedMinimum/10, -1);

      //Serial.println("Mode 1 controlAmount: " + String(controlAmount));
      //Serial.println("Mode 1 fadeSpeeed: " + String(fadeSpeed));

    }
    // Potentiometer Top Right | A0 - Map the value of the Potentiometer to a Variable
    else if (Mode == 2) {
      //fadeSpeed = map(analogRead(A0), 0, 1024, (speedMinimum/10), -1);
      //Serial.println("Mode 5 fadeSpeeed: " + String(fadeSpeed));

      // This makes the potentiometer slower to change when reducting from full and gives better control fidelity at higher speeds
      // This is a map of values for the potentiometer. note: the in array should have increasing values
      int in[]  = {0, 25.5,51,76.5,102,127.5,153,178.5,204,229.5,255};
      // This is a map of values for potentiometer curve type.
      int out[] = { 2300,2298,2296,2295,2292,2200,2100,2000,1800,1300,0 };  // 11
      // This maps the potentiometer scale.
      controlAmount  = map(analogRead(A0), 0, 1024, 255, 0);
      // This is a multimap that assigns values from the [in] array (potentiometer) to values from the [out] array (curve)
      x = multiMap(controlAmount, in, out, 11);
      // This maps the values for the Modez.
      fadeSpeed = map(x, 0, 2300, speedMinimum/10, -1);

      //Serial.println("Mode 2 controlAmount: " + String(controlAmount));
      //Serial.println("Mode 2 fadeSpeeed: " + String(fadeSpeed));      
    }
    
    else if (Mode == 3) {
      //valueLog = log(analogRead(A0)+1)/log(1024)*255;
      //Serial.println("Mode 1 valueLog: " + String(valueLog));
      //fadeSpeed = map(valueLog, 0, 255, (speedMinimum/2), (40/2)); // Logarithmic Potentiometer Value
      //fadeSpeed = map(analogRead(A0), 0, 1024, durationMaximum, 0);

      // This makes the potentiometer slower to change when reducting from full and gives better control fidelity at higher speeds
      // This is a map of values for the potentiometer. note: the in array should have increasing values
      int in[]  = {0, 25.5,51,76.5,102,127.5,153,178.5,204,229.5,255};
      // This is a map of values for potentiometer curve type.
      int out[] = { 2300,2298,2296,2295,2292,2200,2100,2000,1800,1300,0 };  // 11
      // This maps the potentiometer scale.
      controlAmount  = map(analogRead(A0), 0, 1024, 255, 0);
      // This is a multimap that assigns values from the [in] array (potentiometer) to values from the [out] array (curve)
      x = multiMap(controlAmount, in, out, 11);
      // This maps the values for the Modez.
      fadeSpeed = map(x, 0, 2300, speedMinimum, 10);
      

      //Serial.println("Mode 3 controlAmount: " + String(controlAmount));
      Serial.println("Mode 3 fadeSpeeed: " + String(fadeSpeed));    
    }
    else if (Mode == 4) {
      //valueLog = log(analogRead(A0)+1)/log(1024)*255;
      //Serial.println("Mode 1 valueLog: " + String(valueLog));
      //fadeSpeed = map(valueLog, 0, 255, (speedMinimum/2), (40/2)); // Logarithmic Potentiometer Value
      //fadeSpeed = map(analogRead(A0), 0, 1024, durationMaximum, 0);

      // This makes the potentiometer slower to change when reducting from full and gives better control fidelity at higher speeds
      // This is a map of values for the potentiometer. note: the in array should have increasing values
      int in[]  = {0, 25.5,51,76.5,102,127.5,153,178.5,204,229.5,255};
      // This is a map of values for potentiometer curve type.
      int out[] = { 2300,2298,2296,2295,2292,2200,2100,2000,1800,1300,0 };  // 11
      // This maps the potentiometer scale.
      controlAmount  = map(analogRead(A0), 0, 1024, 255, 0);
      // This is a multimap that assigns values from the [in] array (potentiometer) to values from the [out] array (curve)
      x = multiMap(controlAmount, in, out, 11);
      // This maps the values for the Modez.
      fadeSpeed = map(x, 0, 2300, speedMinimum, 10);
      

      //Serial.println("Mode 3 controlAmount: " + String(controlAmount));
      Serial.println("Mode 3 fadeSpeeed: " + String(fadeSpeed)); 

    }
    else if (Mode == 5) {
      //valueLog = log(analogRead(A0)+1)/log(1024)*255;
      //Serial.println("Mode 1 valueLog: " + String(valueLog));
      //fadeSpeed = map(valueLog, 0, 255, (speedMinimum/2), (40/2)); // Logarithmic Potentiometer Value
      //fadeSpeed = map(analogRead(A0), 0, 1024, durationMaximum, 0);

      // This makes the potentiometer slower to change when reducting from full and gives better control fidelity at higher speeds
      // This is a map of values for the potentiometer. note: the in array should have increasing values
      int in[]  = {0, 25.5,51,76.5,102,127.5,153,178.5,204,229.5,255};
      // This is a map of values for potentiometer curve type.
      int out[] = { 2300,2298,2296,2295,2292,2200,2100,2000,1800,1300,0 };  // 11
      // This maps the potentiometer scale.
      controlAmount  = map(analogRead(A0), 0, 1024, 255, 0);
      // This is a multimap that assigns values from the [in] array (potentiometer) to values from the [out] array (curve)
      x = multiMap(controlAmount, in, out, 11);
      // This maps the values for the Modez.
      fadeSpeed = map(x, 0, 2300, speedMinimum, 10);
      

      //Serial.println("Mode 3 controlAmount: " + String(controlAmount));
      Serial.println("Mode 3 fadeSpeeed: " + String(fadeSpeed)); 

    }
    else if (Mode == 8) {
      valueLog = log(analogRead(A0)+1)/log(1024)*255;
      //Serial.println("Mode 1 valueLog: " + String(valueLog));
      fadeSpeed = map(valueLog, 0, 255, (speedMinimum/2), 30); // Logarithmic Potentiometer Value
      //fadeSpeed = map(analogRead(A0), 0, 1024, durationMaximum, 0);

      Serial.println("delayA0 Mode 8 - fadeSpeeed: " + String(fadeSpeed));

    }    
    else if (Mode == 9) {
      //valueA0 = map(analogRead(A0), 0, 1024, 2000, 0);
      valueA0 = log(analogRead(A0)+1)/log(1024)*255;
      modulateConstrain = modulateSpeed + (valueA0-200);
      fadeSpeed = constrain(modulateConstrain, 0, 3000);
      //fadeSpeed = map(analogRead(A0), 0, 1024, durationMaximum, 0);
      //ModulateControl();
      //fadeSpeed = fadeSpeed;
      
      //Serial.println("delayA0 fadeSpeeed: " + String(fadeSpeed));
    }   
    else {
      fadeSpeed = 7;
      //Serial.println("Else fadeSpeeed: " + String(fadeSpeed));
    }

        //Make this number smaller to fade faster
    if (Mode == 3)
    {
      delay(1);
    }
    else
    {
      delay(.5);
    }
    
    //controlsMax();
    //Serial.println("Count if Waiting = False: " + String(count));
  }
}



/**

  A1 Delay - Full Delay

*/


void delayA1(int count)
{

  int delayCountA1 = fullDelay;

  for (int count = 0; count <= delayCountA1; count++) {

    delayCountA1 = fullDelay;

    plotCycle();

    if ((analogRead(A0) <= ValueZeroAdjustment) && (analogRead(A1) <= ValueZeroAdjustment) && (analogRead(A2) <= ValueZeroAdjustment)) {
      count = 0;
      Serial.println("I Broke");
      break;
    }

    if (Mode ==  1) {
    fullDelay = 100;
    }
    // Potentiometer Top Left | A1 - Map the value of the potentiometer to a variable and Update the Variable(s)
    if (Mode == 2) {

      fullDelay = 100;
    }
    else if (Mode == 3) {
      //fullDelay = map(analogRead(A1), 0, 1024, speedMinimum, 100); // Linear Potentiometer Value
      //Serial.println("Mode 1 fullDelay: " + String(fullDelay));

      // This makes the potentiometer slower to change when reducting from full and gives better control fidelity at higher speeds
      // This is a map of values for the potentiometer. note: the in array should have increasing values
      int in[]  = {0, 25.5,51,76.5,102,127.5,153,178.5,204,229.5,255};
      // This is a map of values for potentiometer curve type.
      int out[] = { 2300,2298,2296,2295,2292,2200,2100,2000,1800,1300,0 };  // 11
      // This maps the potentiometer scale.
      controlAmount  = map(analogRead(A1), 0, 1024, 255, 0);
      // This is a multimap that assigns values from the [in] array (potentiometer) to values from the [out] array (curve)
      x = multiMap(controlAmount, in, out, 11);
      // This maps the values for the Modez.
      fullDelay = map(x, 0, 2300, speedMinimum, 10);
      

      //Serial.println("Mode 3 controlAmount: " + String(controlAmount));
      //Serial.println("Mode 3 fadeSpeeed: " + String(fadeSpeed));
      
    }
    else if (Mode == 4) {
      fullDelay = map(analogRead(A1), 0, 1024, speedMinimum, 100); // Linear Potentiometer Value
      //Serial.println("Mode 1 fullDelay: " + String(fullDelay));
      
      // This makes the potentiometer slower to change when reducting from full and gives better control fidelity at higher speeds
      // This is a map of values for the potentiometer. note: the in array should have increasing values
      int in[]  = {0, 25.5,51,76.5,102,127.5,153,178.5,204,229.5,255};
      // This is a map of values for potentiometer curve type.
      int out[] = { 2300,2298,2296,2295,2292,2200,2100,2000,1800,1300,0 };  // 11
      // This maps the potentiometer scale.
      controlAmount  = map(analogRead(A1), 0, 1024, 255, 0);
      // This is a multimap that assigns values from the [in] array (potentiometer) to values from the [out] array (curve)
      x = multiMap(controlAmount, in, out, 11);
      // This maps the values for the Modez.
      fullDelay = map(x, 0, 2300, speedMinimum, 10);
      
    }
    else if (Mode == 5) {
      //fullDelay = map(analogRead(A1), 0, 1024, speedMinimum, 100); // Linear Potentiometer Value
      //Serial.println("Mode 1 fullDelay: " + String(fullDelay));
      
      // This makes the potentiometer slower to change when reducting from full and gives better control fidelity at higher speeds
      // This is a map of values for the potentiometer. note: the in array should have increasing values
      int in[]  = {0, 25.5,51,76.5,102,127.5,153,178.5,204,229.5,255};
      // This is a map of values for potentiometer curve type.
      int out[] = { 2300,2298,2296,2295,2292,2200,2100,2000,1800,1300,0 };  // 11
      // This maps the potentiometer scale.
      controlAmount  = map(analogRead(A1), 0, 1024, 255, 0);
      // This is a multimap that assigns values from the [in] array (potentiometer) to values from the [out] array (curve)
      x = multiMap(controlAmount, in, out, 11);
      // This maps the values for the Modez.
      fullDelay = map(x, 0, 2300, speedMinimum, 10);
    }
    else {
      fullDelay = 100;
      //Serial.println("Else fullDelay: " + String(fullDelay));
    }

    delay(1);
    //controlsMax();
    //Serial.println("Count if Waiting = False: " + String(count));
  }
}

/**

  A2 Delay - Dark Delay

*/


void delayA2(int count)
{

  int delayCountA2 = darkDelay;


  for (int count = 0; count <= delayCountA2; count++) {

    delayCountA2 = darkDelay;
    //Serial.println("delayA2 delayCountA2: " + String(delayCountA2));
    
    plotCycle();

    if ((analogRead(A0) <= ValueZeroAdjustment) && (analogRead(A1) <= ValueZeroAdjustment) && (analogRead(A2) <= ValueZeroAdjustment)) {
      count = 0;
      Serial.println("I Broke");
      break;
    }
    
   if (Mode == 1) {

      valueA2 = map(analogRead(A2), 0, 1024, 0, durationMaximum);
      darkDelay =  valueA2;
      //Serial.println("Mode 4 darkDelay: " + String(fullDelay));
    }
    else if (Mode == 2) {

      valueA2 = map(analogRead(A2), 0, 1024, 0, durationMaximum);
      darkDelay =  valueA2;
      //Serial.println("Mode 4 darkDelay: " + String(fullDelay));
    }
    else if (Mode == 3) {

      darkDelay = map(analogRead(A2), 0, 1024, 0, durationMaximum);
      //Serial.println("Mode 1 darkDelay: " + String(darkDelay));
    }
    else if (Mode == 4) {

      darkDelay = map(analogRead(A2), 0, 1024, 0, durationMaximum);
      //Serial.println("Mode 1 darkDelay: " + String(darkDelay));
    }    
    else if (Mode == 5) {

      darkDelay = map(analogRead(A2), 0, 1024, 0, durationMaximum);
      //Serial.println("Mode 1 darkDelay: " + String(darkDelay));
    }  
    else if (Mode == 8) {

      darkDelay = map(analogRead(A2), 0, 1024, 0, durationMaximum);
      //Serial.println("Mode 1 darkDelay: " + String(darkDelay));
    } 
    else if (Mode == 9) {

      darkDelay = map(analogRead(A2), 0, 1024, 0, durationMaximum);
      //Serial.println("Mode 1 darkDelay: " + String(darkDelay));
    }                  
    else {
      darkDelay = 100;
      //Serial.println("Else darkDelay: " + String(darkDelay));
    }

    delay(1);
    //controlsMax();
    //Serial.println("Count if Waiting = False: " + String(count));
  }
}



/**

  Rainbow mode Setups

*/

void setRGBpoint(int pixelnumber, uint8_t redValue, uint8_t greenValue, uint8_t blueValue)
{
  pixel.setPixelColor(pixelnumber, redValue, 0, 0);
  pixel.setPixelColor(pixelnumber, 0, greenValue, 0);
  pixel.setPixelColor(pixelnumber, 0, 0, blueValue);

  //Serial.println(redValue);
  //Serial.println(greenValue);
  //Serial.println(blueValue);
}

// the real HSV rainbow
void trueHSV(int pixelnumber, int angle)
{
  byte red, green, blue;

  if (angle < 60) {
    redValue = 255;
    greenValue = HSVlights[angle];
    blueValue = 0;
  } else if (angle < 120) {
    redValue = HSVlights[120 - angle];
    greenValue = 255;
    blueValue = 0;
  } else if (angle < 180) {
    redValue = 0, greenValue = 255;
    blueValue = HSVlights[angle - 120];
  } else if (angle < 240) {
    redValue = 0, greenValue = HSVlights[240 - angle];
    blueValue = 255;
  } else if (angle < 300) {
    redValue = HSVlights[angle - 240], greenValue = 0;
    blueValue = 255;
  } else
  {
    redValue = 255, greenValue = 0;
    blueValue = HSVlights[360 - angle];
  }
  setRGBpoint(pixelnumber, redValue, greenValue, blueValue);
  pixel.setPixelColor(pixelnumber, redValue, greenValue, blueValue);

}

// the 'power-conscious' HSV rainbow
void powerHSV(int pixelnumber, int angle)
{
  byte redValue, greenValue, blueValue;
  if (angle < 120) {
    redValue = HSVpower[120 - angle];
    greenValue = HSVpower[angle];
    blueValue = 0;
  } else if (angle < 240) {
    redValue = 0;
    greenValue = HSVpower[240 - angle];
    blueValue = HSVpower[angle - 120];
  } else
  {
    redValue = HSVpower[angle - 240];
    greenValue = 0;
    blueValue = HSVpower[360 - angle];
  }
  setRGBpoint(pixelnumber, redValue, greenValue, blueValue);
  pixel.setPixelColor(pixelnumber, redValue, greenValue, blueValue);
  //pixel.show();
}

// sine wave rainbow
void sineLED(int pixelnumber, int angle)
{
  setRGBpoint(pixelnumber, lights[(angle + 120) % 360], lights[angle],  lights[(angle + 240) % 360]);
  pixel.setPixelColor(pixelnumber, lights[(angle + 120) % 360], lights[angle],  lights[(angle + 240) % 360]);

}

void RainbowMode () {

  if (Mode == 2) {

    //Randomize the maximum brightness of the LED using potantiometer A2
    rainbowBright = valueA1 - randomAmount;
    pixel.setBrightness(rainbowBright);
    //Serial.println("Mode 5 randomAmount: " + String(randomAmount));
    //Serial.println("Mode 5 rainbowBright: " + String(rainbowBright));
  }
  else;

  //Fade in from the beginning of the Rainbow cycle (Red)
  for (int x = 0; x < 255; x++)
  {
    if ((analogRead(A0) <= ValueZeroAdjustment) && (analogRead(A1) <= ValueZeroAdjustment) && (analogRead(A2) <= ValueZeroAdjustment)) {
      x = 0;
      Serial.println("I Broke");
      break;
    }

    if (Mode == 1) {

      //Change the maximum brightness of the LED using potantiometer A1
      rainbowBright = map(analogRead(A1), 0, 1024, 0, 100);
      pixel.setBrightness(rainbowBright);
      //Serial.println("Mode 4 rainbowBright: " + String(rainbowBright));
    }
    if (Mode == 2) {

      //Change the maximum brightness of the LED using potantiometer A1

      valueA1 = map(analogRead(A1), 0, 1024, 0, 255);
      randomAmount = random(0, 255);
      //Serial.println("Mode 5 randomAmount: " + String(randomAmount));
      //Serial.println("Mode 5 rainbowBright: " + String(rainbowBright));
    }
    else;

    plotCycle();

    //Change the rate of the rainbow cycling using potantiometer A0
    //Increase the value of the R value causing a fade in;
    pixel.setPixelColor(pixelnumber, x, 0, 0);



    //A delay amount between each increase in value mapped to A0 and divided
    delayA0(fadeSpeed / 100);
    pixel.show();
  }

  //Run the Rainbow cycle (Red)
  for (int k = 0; k < 360; k++)
  {

    // uncomment the mode (or modes) you need below.

    //trueHSV(0, k);

    powerHSV(0, k);

    //sineLED(0, k);

    pixel.show();

    if ((analogRead(A0) <= ValueZeroAdjustment) && (analogRead(A1) <= ValueZeroAdjustment) && (analogRead(A2) <= ValueZeroAdjustment)) {
      k = 0;
      Serial.println("I Broke");
      break;
    }

    //Change the rate of the rainbow cycling using potantiometer A0
    fadeSpeed = map(analogRead(A0), 0, 1024, 80, -1);
    //Serial.println("Mode 5 fadeSpeeed: " + String(fadeSpeed));


    delayA0(fadeSpeed);


    if (Mode == 1) {
      //Change the maximum brightness of the LED using potantiometer A1
      rainbowBright = map(analogRead(A1), 0, 1024, 0, 100);
      pixel.setBrightness(rainbowBright);
      //Serial.println("Mode 4 rainbowBright: " + String(rainbowBright));
    }
    else;

    //plotCycle();

  }


  //Fade out from the end of the Rainbow (lol) cycle (Red)
  for (int x = 255; x >= 0; x--)
  {
    if ((analogRead(A0) <= ValueZeroAdjustment) && (analogRead(A1) <= ValueZeroAdjustment) && (analogRead(A2) <= ValueZeroAdjustment)) {
      x = 0;
      Serial.println("I Broke");
      break;
    }

    if (Mode == 1) {
      //Change the maximum brightness of the LED using potantiometer A1
      rainbowBright = map(analogRead(A1), 0, 1024, 0, 100);
      pixel.setBrightness(rainbowBright);
      //Serial.println("Mode 4 rainbowBright: " + String(rainbowBright));
    }
    else;

    //Change the rate of the rainbow cycling using potantiometer A0
    //Reduces the value of the R value causing a fade out;
    pixel.setPixelColor(pixelnumber, x, 0, 0);

    //A delay amount between each reduction in value mapped to A0 and divided
    delayA0(fadeSpeed / 100);
    pixel.show();

    plotCycle();
  }

  //Add a delay (ms) at the end of the rainbow cycle using potantiometer A2 while the LED is dark
  //valueA1 = map(analogRead(A1), 0, 1024, 0, 30);
  delayA2(darkDelay);

  plotCycle();

  //Serial.println("Rate of Rainbow cycling: " + String(valueA0)  + " ||| Delay between Rainbow cycles (ms): " + String(valueA1) + " ||| Maximum Brightness value: " + String(valueA2));

}

/**

  Brightness Blink 6

*/

void brightnessBlink6(){

    if (Mode == 4) {
      setRandomBrightsOnce();
    }
    else if (Mode == 5) {
      // Un-comment 'setRandomBrights' in Loop to randomize Brightness values for the 4 values after each cycle
      setRandomBrights();
    }

    
    Serial.println(randomBright01);
    Serial.println(randomBright02);
    Serial.println(randomBright03);
    Serial.println(randomBright04);
    
    // Set the color
    pixel.setPixelColor(0, colorRed); 
    pixel.show(); 
    // Do the brightness changes 4 times
    quadBrightness();  
    // Delay the change to the next color by the amount of A0
    delayA0(fadeSpeed);
    // Add an amount of darness by the amount of A2
    darkDelayBetwixtColors();
    
    pixel.setPixelColor(0, colorOrange); 
    pixel.show();
    quadBrightness();  
    delayA0(fadeSpeed);
    darkDelayBetwixtColors();
    
    pixel.setPixelColor(0, colorYellow); 
    pixel.show();  
    quadBrightness();  
    delayA0(fadeSpeed);
    darkDelayBetwixtColors();
    pixel.setPixelColor(0, colorGreen); 
    pixel.show();  
    quadBrightness();  
    delayA0(fadeSpeed);
    darkDelayBetwixtColors();
    pixel.setPixelColor(0, colorBlue); 
    pixel.show();
    quadBrightness();  
    delayA0(fadeSpeed);
    darkDelayBetwixtColors();
    pixel.setPixelColor(0, colorPurple); 
    pixel.show();  
    quadBrightness();  
    delayA0(fadeSpeed);
    

    // Make the pixel dark
    pixel.setBrightness(0);
    pixel.show();    

    // Delay by the amount of A2
    delayA2(darkDelay);
    
    //darkDelayBetwixtColors();
    
 
  //pixel.show(); 
  

}

void quadBrightness()
{
  // Set the brightness
  pixel.setBrightness(randomBright01);
  pixel.show(); 
  // Delay the change to the next brightness by the amount of A1
  delayA1(fullDelay);
  
  //Serial.println("Full Delay 1: " + String(fullDelay));

  // Set the brightness
  pixel.setBrightness(randomBright02);
  pixel.show(); 
  // Delay the change to the next brightness by the amount of A1
  delayA1(fullDelay);
  
  //Serial.println("Full Delay 2: " + String(fullDelay));

  // Set the brightness
  pixel.setBrightness(randomBright03);
  pixel.show(); 
  // Delay the change to the next brightness by the amount of A1
  delayA1(fullDelay);
  
  //Serial.println("Full Delay 3: " + String(fullDelay));

  // Set the brightness
  pixel.setBrightness(randomBright04);
  pixel.show(); 
  // Delay the change to the next brightness by the amount of A1
  delayA1(fullDelay);
  
  //Serial.println("Full Delay 4: " + String(fullDelay));


  
}

void setRandomBrights() {

      randomBright01  = random(10, 255);
      randomBright02  = random(10, 255);
      randomBright03  = random(10, 255);
      randomBright04  = random(10, 255);

      Serial.println("Random Bright 1 " + String(randomBright01));
      Serial.println("Random Bright 2 " + String(randomBright02));
      Serial.println("Random Bright 3 " + String(randomBright03));
      Serial.println("Random Bright 4 " + String(randomBright04));
  
}

void setRandomBrightsOnce() {
  if (randomOnce == 0) {
    
      randomBright01  = random(10, 255);
      randomBright02  = random(10, 255);
      randomBright03  = random(10, 255);
      randomBright04  = random(10, 255);

      randomOnce = 1;
      Serial.println("Random Bright 1 " + String(randomBright01));
      Serial.println("Random Bright 2 " + String(randomBright02));
      Serial.println("Random Bright 3 " + String(randomBright03));
      Serial.println("Random Bright 4 " + String(randomBright04));
  }

  
}

void darkDelayBetwixtColors(){
  
    // Make the pixel dark 
    pixel.setBrightness(0);
    pixel.show();    

    // Delay by the amount of A2 - Remove the following comment to turn the led off between each color 
    delayA2(darkDelay);

}

void brightnessA1(){
    valueA1 = map(analogRead(A1), 0, 1024, 0, 20);
    pixel.setBrightness(valueA1);  
}

void RainbowSquarez(){

    //Serial.println("RainbowSquarez " + String(fadeSpeed));
    
    ModulateControl();
    // Set the color
    pixel.setPixelColor(0, colorRed); 
    pixel.show(); 
    brightnessA1();
 
    // Delay the change to the next color by the amount of A0
    delayA0(fadeSpeed);
    // Add an amount of darness by the amount of A2
    //darkDelayBetwixtColors();

    ModulateControl();
    pixel.setPixelColor(0, colorOrange); 
    pixel.show();
    brightnessA1();
    delayA0(fadeSpeed);
    //darkDelayBetwixtColors();

    ModulateControl();
    pixel.setPixelColor(0, colorYellow); 
    pixel.show();  
    brightnessA1();
    delayA0(fadeSpeed);
    //darkDelayBetwixtColors();

    ModulateControl();
    pixel.setPixelColor(0, colorGreen); 
    pixel.show();  
    delayA0(fadeSpeed);
    //darkDelayBetwixtColors();

    ModulateControl();
    pixel.setPixelColor(0, colorBlue); 
    pixel.show();
    brightnessA1();
    delayA0(fadeSpeed);
    //darkDelayBetwixtColors();
    
    ModulateControl();
    pixel.setPixelColor(0, colorPurple); 
    pixel.show();
    brightnessA1();
    delayA0(fadeSpeed);
    //darkDelayBetwixtColors();

    ModulateControl();
    pixel.setPixelColor(0, colorBlue); 
    pixel.show();
    brightnessA1();
    delayA0(fadeSpeed);
    //darkDelayBetwixtColors();
    
    ModulateControl();
    pixel.setPixelColor(0, colorGreen); 
    pixel.show();  
    delayA0(fadeSpeed);

    ModulateControl();
    pixel.setPixelColor(0, colorYellow); 
    pixel.show();  
    brightnessA1();
    delayA0(fadeSpeed);
    //darkDelayBetwixtColors();

    ModulateControl();
    pixel.setPixelColor(0, colorOrange); 
    pixel.show();
    brightnessA1();
    delayA0(fadeSpeed);
    //darkDelayBetwixtColors();

    darkDelay = map(analogRead(A2), 0, 1024, 0, durationMaximum);
    Serial.println("darkDelay " + String(darkDelay));

    if (darkDelay > 20) {
      // Make the pixel dark

    pixel.setBrightness(0);
    pixel.show();    

    // Delay by the amount of A2
    delayA2(darkDelay);
    //Serial.println("darkDelay " + String(darkDelay));

    }
    
    //darkDelayBetwixtColors();
    
 
  //pixel.show(); 
  

}



void changeValue() {
     
      if (increaseValue == true) {
        if ((modulateSpeed >= 1) && (modulateSpeed <= 100)){
           modulateSpeed = modulateSpeed+1;
           Serial.println("Increasing Modulation Least ");
        }
        else if ((modulateSpeed >= 101) && (modulateSpeed <= 200)){
           modulateSpeed = modulateSpeed+5;
           Serial.println("Increasing Modulation Leser ");
        }
        else if ((modulateSpeed >= 201) && (modulateSpeed <= 600)){
           modulateSpeed = modulateSpeed+10;
           Serial.println("Increasing Modulation Less ");
        }
        else {
          modulateSpeed = modulateSpeed+40;
        }
        
      }

      if (increaseValue == false) {
        if ((modulateSpeed >= 1) && (modulateSpeed <= 100)){
           modulateSpeed = modulateSpeed-1;
           Serial.println("Decreasing Modulation Least ");
        }
        else if ((modulateSpeed >= 101) && (modulateSpeed <= 200)){
           modulateSpeed = modulateSpeed-5;
           Serial.println("Decreasing Modulation Lesser ");
        }
        else if ((modulateSpeed >= 201) && (modulateSpeed <= 600)){
           modulateSpeed = modulateSpeed-10;
           Serial.println("Decreasing Modulation Less ");
        }
        else {
          modulateSpeed = modulateSpeed-40;
        }
      }
}

void valueRangeLimits() {

      if (modulateSpeed < 1){
        increaseValue = true;
        
      }
      if (modulateSpeed > 2000){
        increaseValue = false;

     }
  
}

void ModulateControl() {

      Serial.println("Increase " + String(increaseValue));
      Serial.println("Increase false - fadeSpeed: " + String(fadeSpeed));
      Serial.println("Increase false - modulateSpeed: " + String(modulateSpeed));
        
       //Serial.println("Mode 1 valueLog: " + String(valueLog));
      //fadeSpeed = map(valueLog, 0, 255, (speedMinimum/2), (40/2)); // Logarithmic Potentiometer Value
      //fadeSpeed = map(analogRead(A0), 0, 1024, durationMaximum, 0);
      //fadeSpeed = fadeSpeed;
      
      valueRangeLimits();
      changeValue();
      
      
 /** fadeSpeed = 1;
  
  // Fade In
  for (int x = 0; x < 255; x++)
  {
    if ((analogRead(A0) <= ValueZeroAdjustment) && (analogRead(A1) <= ValueZeroAdjustment) && (analogRead(A2) <= ValueZeroAdjustment)) {
      x = 0;
      Serial.println("I Broke");
      break;
    }

    plotCycle();

    fadeSpeed = fadeSpeed+1;
    Serial.println("Modulate|| fadeSpeeed: " + String(fadeSpeed));


    //A delay amount between each increase in value mapped to A0 and divided
    delayA0(fadeSpeed);
    pixel.show();
  }

  //Fade out 
  for (int x = 255; x >= 0; x--)
  {
    if ((analogRead(A0) <= ValueZeroAdjustment) && (analogRead(A1) <= ValueZeroAdjustment) && (analogRead(A2) <= ValueZeroAdjustment)) {
      x = 0;
      Serial.println("I Broke");
      break;
    }

    fadeSpeed = fadeSpeed-1;
    Serial.println("Modulate||| fadeSpeeed: " + String(fadeSpeed));

    //A delay amount between each reduction in value mapped to A0 and divided
    delayA0(fadeSpeed);
    pixel.show();

    plotCycle();
  }

  //Add a delay (ms) at the end of the rainbow cycle using potantiometer A2 while the LED is dark
  //valueA1 = map(analogRead(A1), 0, 1024, 0, 30);
  //delayA2(darkDelay);

  plotCycle();

  //Serial.println("Rate of Rainbow cycling: " + String(valueA0)  + " ||| Delay between Rainbow cycles (ms): " + String(valueA1) + " ||| Maximum Brightness value: " + String(valueA2));

*/



}


/**

  Mountain Snack Mode Functions

  This Section is the Mountain Snack Mode and stuff called by the mountainSnack() function
  
*/

void setRandoms() {

  for (int j = 0; j < randomDensity; j++) {
    randomCore[j] = (random(512) - 256); // fill a random array of size=randomDensity
    //   Serial.println(randomCore[j]);
    for (int i = 0; i < (loopLength / randomDensity); i++) {
      randomNumbers[i + ((loopLength / randomDensity)*j)] = randomCore[j]; // apply those randomDensity values evenly and sequentially into an array of 2048 values
    }
  }

}

void mountainSnack() {

  
  newValue1 = map(analogRead(A0), 0, 1024, 255, 0); // Control the Speed
  
  if (abs(newValue1 - newCalibrate1) > 1) { // this further smooths the knob, at the expense of some accuracy. probably worth it.
    valueA0 = newValue1;
    newCalibrate1 = newValue1;
    //Serial.println("newValue1 :" + String(newValue1));
    //Serial.println("newCalibrate :" + String(newCalibrate1));
  }

  valueA2 = analogRead(A2); // Increases Chance for Snack
  valueA1 = analogRead(A1); // Amount of Randomness to the Cycle
  
  speedControl = float(valueA0) / 256; // speed control bit shifted and then goes from 0-1
  randomAmount = float(valueA1) / 2048; // random depth from 0-0.5
  snackChance = valueA2; // chance of snack from 0-1024

  // calculate the random array that will be sent to LED by multiplying the random number array by a factor from 0 to 1 (for now, maybe these values should be adjusted)
  for (int i = 0; i < loopLength; i++) {
    int randomDepth = int(randomNumbers[i] * randomAmount);

    // sum1024[i] = int(sine1024[i]+((random1024[i]-128)*randomMultiplier));
    sumArray[i] = constrain(sine2048[i] + randomDepth, 0, 255);
  };




  // Set pulse rate
  valueA0 = newValue1;
  targetSpeed = (maxLength * speedControl) + minLength; // set number of milliseconds the loop will last by multiplying the longest possible length by a fraction calculated by the knob
  //Serial.println("targetspeed :" + String(targetSpeed));
  milli = millis() - lastMillis;
  if (milli > targetSpeed) {
    milli = 0;
    lastMillis = millis();
    if (reRandom) {
      setRandoms(); // the resets the random numbers on each loop.
    };
  }

  // use targetSpeed and lengths to read the array of values and determine LED brightness
 // currentLoc = (milli * ((maxLength + minLength) / targetSpeed)) / 2; // fix this so that lengths other than 1000-4096 can be selected
   currentLoc = (milli * ((maxLength + minLength) / targetSpeed)) / ((maxLength + minLength)/loopLength);
  currentVal = sumArray[int(currentLoc)];




  // every so often decide whether to stop for a snack, current 3 times per cycle

  snackInterval = int(targetSpeed / 3.2);
  if ((millis() - snackMilli) > snackInterval) {
    snackMilli = millis();
    snackRandom = random(1024); // this is where randomness range could be set, currently it is 0-100%, should maybe max out at 50%?

    //   Serial.println(snackRandom);
  }


  // if you've decided to have your snack
  if (snackRandom < snackChance) {
    
    snackLength = map(analogRead(A0), 0, 1024, 0, 1000); // Control the amount of Random Snack
    //snackLength = int(targetSpeed/3);
    lastMillis += snackLength;
    snackRandom = 1024;
    //snackLengthRandom = random(100)-50;
    snackLengthRandom = random(snackLength+1000)-(snackLength+50);
    delaySnackLength = snackLength+snackLengthRandom;
    //Serial.println("SNACK TIME");
    //Serial.println(snackLength+snackLengthRandom);
    //delay(snackLength+snackLengthRandom);
    //Serial.println("snackLength :" + String(delaySnackLength));
    
    delaySnack(delaySnackLength);

    plotCycle();

  }


  if (Mode == 6){
    
      color = 3;
  }
  if (Mode == 7){
    
      color = 3;
  }

// yann's simple system for setitng single pixel color with variable brightness

scaledVal = map(currentVal, 0, 255, 0, maximumScale);
  //Serial.println(scaledVal);
  if (color == 0) {
    pixel.setBrightness(scaledVal);
    pixel.setPixelColor(0, 255, 0, 255);
  }

  if (color == 1) {
     pixel.setBrightness(scaledVal);
    pixel.setPixelColor(0, 0, 255, 255);
  }

  if (color == 2) {
     pixel.setBrightness(scaledVal);
    pixel.setPixelColor(0, 0, 0, 255);
  }

  // damian's wacky system for setitng triple pixel color with variable brightness

  
  if (color == 3) {
    if ((currentVal >= 0) && (currentVal <= 40)) {
      pixel.setBrightness(scaledVal);
      pixel.setPixelColor(0, colorRed); 
    }
    if ((currentVal >= 41) && (currentVal <= 80)) {
      pixel.setBrightness(scaledVal);
      pixel.setPixelColor(0, colorOrange); 
    }
    if ((currentVal >= 81) && (currentVal <= 120)) {
      pixel.setBrightness(scaledVal);
      pixel.setPixelColor(0, colorYellow); 
    }
    if ((currentVal >= 121) && (currentVal <= 160)) {
      pixel.setBrightness(scaledVal);
      pixel.setPixelColor(0, colorGreen); 
    }
    if ((currentVal >= 161) && (currentVal <= 200)) {
      pixel.setBrightness(scaledVal);
      pixel.setPixelColor(0, colorBlue); 
    }
    if ((currentVal >= 201) && (currentVal <= 240)) {
      pixel.setBrightness(scaledVal);
      pixel.setPixelColor(0, colorPurple); 
    }
    if ((currentVal >= 241) && (currentVal <= 260)) {
      pixel.setBrightness(scaledVal);
      pixel.setPixelColor(0, colorPink); 
    }
  }
  pixel.show();


    // Slow down the simulation when the value is low
    if ((scaledVal >= 0) && (scaledVal <= 10)) {
      strangeRandom = random(20, 200);
      strangeSlowAmount = (strangeRandom+(delayAmount*3));
      delay(strangeSlowAmount);
      //Serial.println("StrangeSlow: " + String(strangeSlowAmount));
      //Serial.println("ScaledVal: " + String(scaledVal));
      //Serial.println("CurrentVal: " + String(currentVal));
  }

 

  plotCycle();

  

  // pixel.setPixelColor(pixel number, R, G, B);
  // pixel.setPixelColor(0, 64, 0, 0); pixel.show(); delay(1000); //red brightness value 0-255
}

void delaySnack(int count)
{
  
  int delaySnackLength = snackLength+snackLengthRandom;
  int delaySnacking = delaySnackLength;

  for (int count = 0; count <= delaySnacking; count++) {

    delaySnacking = delaySnackLength;
    //Serial.println("delaySnacking delaySnackLength: " + String(delaySnacking));
    
    plotCycle();

    if ((analogRead(A0) <= ValueZeroAdjustment) && (analogRead(A1) <= ValueZeroAdjustment) && (analogRead(A2) <= ValueZeroAdjustment)) {
      count = 0;
      Serial.println("I Broke");
      break;
    }
    
    delay(1);
    //controlsMax();
    //Serial.println("Count if Waiting = False: " + String(count));
  }
}




/**

  Mode Change

*/
//
//  This Section is waiting for all potentiometers to be fully counter-clockwise for a duration 
//  and then will start flashing a pattern of light in preparation for advancing Modez
//  If A2 is above zero (turned clockwise) mode will advance in Routines 
//  If A0 or A1 is above zero (turned clockwise) current Mode will resume with Mode Color
//


void modeFlash() {
  
   // Flash Pink 3 Times bacause Pink is pretty cool
   for (int i = 0; i < 3; i++)
      {
        pixel.setBrightness(70);
        pixel.setPixelColor(0, Sketch2Pink); // Pink
        pixel.show();
        delay(ModeFlashDelay);
        pixel.setPixelColor(0, 0x000000); // Blank
        pixel.show();
        delay(ModeFlashDelay);
      }
 }

void modeChangeWait() {
  
    
     // If all pins are fully counter-clockwise (zero) get ready to routine (Mode) change and set WaitForModeChange to False
     if ((analogRead(A0) <= ValueZeroAdjustment) && (analogRead(A1) <= ValueZeroAdjustment) && (analogRead(A2) <= ValueZeroAdjustment) && (WaitForModeChange))
        {
          WaitForModeChange = false;
          //Serial.println(" WaitForModeChange = False");
          delay(200);
        }

    //If WaitForModeChange is False because all of the potentiometers are fully counter-clockwise and a variable duration of time has elapsed, start blinking.
    if (!WaitForModeChange)
    {
        pixel.setBrightness(70);
        pixel.setPixelColor(0, Sketch2Green);
        pixel.show();
        delay(100);
        pixel.setPixelColor(0, 0x000000); // Blank
        pixel.show();
        delay(300);
        Serial.println("Blinking and getting ready to Advance Modez");

      // If pin A0 or A1 moves from fully counter-clockwise (zero) go back to waiting for the routine (Mode) change
      if ((analogRead(A0) > ValueZeroAdjustment) or (analogRead(A1) > ValueZeroAdjustment) && (!WaitForModeChange))
      {
        
        if (Mode == 1)
        {
    
        }
        if (Mode == 2)
        {
          pixel.setPixelColor(0, 36, 0, 255); 
        }
        if (Mode == 3)
        {
          pixel.setPixelColor(0, 0, 200, 30);    
        }
        if (Mode == 4)
        {
          pixel.setPixelColor(0, Sketch2Red);
        }
        if (Mode == 5)
        {
          pixel.setPixelColor(0, Sketch2Red);
        }
        else;
            
        pixel.show();
        waitingFlag = true;
        WaitForModeChange = true;
        //Serial.println(" WaitForModeChange = False & WaitingFlag = True");
        Serial.println("Peaced-Out on Advancing the Mode");
      }
      
      // If pin A2 moves from fully counter-clockwise (zero) then advance the Mode
      if ((analogRead(A2) > ValueZeroAdjustment) && (!WaitForModeChange))
      {
        if (9 >= Mode)
        {
          Mode = Mode+1;
          //Serial.println("Mode Change = " + String(Mode));
        }
        else if (Mode == 10)
        {
          Mode = 1;
          //Serial.println("Mode Change = " + String(Mode));
        }
                
        waitingFlag = false;
        WaitForModeChange = false;
        //Serial.println(" WaitForModeChange = False & WaitingFlag = False");
        Serial.println("Totally advancing Modez Now");
      }
      
    }   
      
      
  
}


/**

  Write Startup Mode to Memory

*/
//
//  This Section is waiting for all potentiometers to be fully clockwise for a duration defined as "ValueHighlightTime"
//  and then will start flashing a pattern of light in preparation for wiritng the startup mode to the Flash/ EEPROM Memory
//  If A2 is beloww zero (turned counter-clockwise) then the current Mode will be written as the Startup Mode to Memory
//  If A0 or A1 is rotated below fully clockwise (turned counter-clockwise) current Mode will resume with Mode Color
//
//


void controlsMax()
{

  // If all the potentiometer are fully clockwise, set "ValueHighReached" to "True" and get ready to blink.
  //
  if ((analogRead(A0) > 1022) && (analogRead(A1) > 1022) && (analogRead(A2) > 1022) && (!ValueHighReached))
  {
    ValueHighTime = millis();
    ValueHighlightTime = millis();
    ValueHighReached = true;
    Serial.println("Getting Ready to Save the Current Mode as the Startup Mode");

  }

//
  // When A0 or A1 becomes less than fully Clockwise, resume the current Mode without writing the Startup Mode
  // then set the pixel color to the right color depending on the current Mode
  //
  if (((analogRead(A0) < 1023) or (analogRead(A1) < 1023)) && (ValueHighReached))
  {
    ValueHighTime = 0;
    ValueHighReached = false;

    if (Mode == 1)
    {
    
    }
    if (Mode == 2)
    {
      pixel.setPixelColor(0, 36, 0, 255); 
    }
    if (Mode == 3)
    {
      pixel.setPixelColor(0, 0, 200, 30);    
    }
    if (Mode == 4)
    {
      pixel.setPixelColor(0, Sketch2Red);
    }
    if (Mode == 5)
    {
      pixel.setPixelColor(0, Sketch2Red);
    }
    else;

    pixel.show();
    Serial.println("Peaced-Out on Saving the Startup Mode");
  }


  
  //
  // When A2 potentiometer becomes less than fully Clockwise, write the startup mode to the Flash/ EEPROM Memory
  // then set the pixel color to the right color depending on the Mode
  //
  if ((analogRead(A2) < 1023) && (ValueHighReached))
  {
    ValueHighTime = 0;
    ValueHighReached = false;

    // Write the startupMode to EEPROM Flash Memory
    writeStartupMode();

    modeFlash();
    pixel.setPixelColor(0, Sketch2Red);
    pixel.show();
    delay(1000);
    modeFlash();

    if (Mode == 1)
    {
      
    }
    if (Mode == 2)
    {
      pixel.setPixelColor(0, 36, 0, 255); 
    }
    if (Mode == 3)
    {
      pixel.setPixelColor(0, 0, 200, 30);    
    }
    if (Mode == 4)
    {
      pixel.setPixelColor(0, Sketch2Red);
    }
    if (Mode == 5)
    {
      pixel.setPixelColor(0, Sketch2Red);
    }
    else;

    pixel.show();
    Serial.println("Startup Mode written to Flash Memory");
  }

  //If "ValueHighReached" = True and the duration in milleseconds defined for "WaitTime" has been reached, start blinking a pattern and get ready to save the startup mode.
  if (((ValueHighTime + WaitTime) < millis()) && (ValueHighReached))
  {

    //If all the potentiometer are fully clockwise and a variable duration of time has elapsed, start blinking.
    if ((ValueHighlightTime + 300) < millis())
    {

      if (ValueHighlight == 0)
      {
        ValueHighlightTime = millis();
        ValueHighlight = 1;
        pixel.setBrightness(155);
        //pixel.setPixelColor(0, 255,64,98);
        pixel.setPixelColor(0, Sketch2Yellow);
        pixel.show();
        delay(100);
        pixel.setPixelColor(0, 0x000000); // Blank
        pixel.show();
        delay(300);
        Serial.println("Blinking and getting ready to Save Startup Mode");
      }
      else
      {
        ValueHighlightTime = millis();
        ValueHighlight = 0;
        Serial.println("I'm ready to write the startup mode");
      }

    }
  }
}


/**

  Serial Printing and Plotting

  This Section includes different ways to print and plot the variable to the Arduino Serial Monitor and Serial Plotter

*/

void plotCycle()
{

//Serial.println(" A0 = " + String(analogRead(A0)) + " A1 = " + String(analogRead(A1)) + " A2 = " + String(analogRead(A2)));

if (plotterPrint == true){
          
  ///*
  if (Mode == 1)
{
  Serial.println("Min:0,Max:100"); //Un-comment this for a smooth line
  //Serial.println(","); //Un-comment this for a smooth line
  Serial.println(currentVal);
  //Serial.println(valueA1);
  //Serial.println(valueA2);
  
}

  // If the Mode is 2-5, run print for fades
   if ((Mode >= 2) && (Mode <= 5))
  {
    //Serial.println("Min:0,Max:255");
    Serial.println("Min:0,Max:255"); //Un-comment this for a smooth line
    //Serial.print(","); //Un-comment this for a smooth line

    LEDBrightness = pixel.getBrightness();
    Serial.println(LEDBrightness);
    //LEDBrightness = redValue + blueValue + greenValue;
  }

  if ((Mode >= 6) && (Mode <= 7))
    //if (6 <= Mode)
  {
    //Serial.print("Min:0,Max:300"); //Un-comment this for a smooth line
    //Serial.print(","); //Un-comment this for a smooth line
    Serial.println(currentVal);
    //Serial.print(","); //Un-comment this for a smooth line
  }
  if ((Mode >= 8) && (Mode <= 10))
    //if (6 <= Mode)
  {
    //Print some things
    Serial.print("Min:0,Max:200"); //Un-comment this for a smooth line
    Serial.print(","); //Un-comment this for a smooth line


  }
  else;
} 
  //*/
}




/**

  Memory Reporting Tools

  This Section is used for memory reporting
  
*/

#ifdef __arm__
// should use uinstd.h to define sbrk but Due causes a conflict
extern "C" char* sbrk(int incr);
#else  // __ARM__
extern char *__brkval;
#endif  // __arm__

int freeMemory() {
  char top;
#ifdef __arm__
  return &top - reinterpret_cast<char*>(sbrk(0));
#elif defined(CORE_TEENSY) || (ARDUINO > 103 && ARDUINO != 151)
  return &top - __brkval;
#else  // __arm__
  return __brkval ? &top - __brkval : &top - __malloc_heap_start;
#endif  // __arm__
}

/**

  Reading and Writing to FLASH/ EEPROM Memory

  This Section reads the startupMode value and uses it for the Mode after startup and writes the startupMode value for the current Mode

*/

void writeStartupMode()
{
  // Set the current Mode as the startupMode
  startupMode = Mode;
  Serial.println("Setting Mode as startupMode: Mode = " + String(Mode) + " | startupMode = " + String(startupMode));


  // Save into emulated-EEPROM the current Mode number for the next run of the sketch
  EEPROM.put(address, (int) (startupMode));
  Serial.println("Writing startupMode = " + String(startupMode));

  if (!EEPROM.getCommitASAP())
  {
    Serial.println("CommitASAP not set. Need commit()");
    EEPROM.commit();
  }
  Serial.println("Done writing to emulated EEPROM.");
}

void readStartupMode()
{

  // Read the content of emulated-EEPROM startupMode variable
  EEPROM.get(address, startupMode);
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
