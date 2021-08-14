
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
uint32_t CurrentColor = Sketch2Pink;

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

boolean Blink1 = true;
boolean plotterPrint = true;

long WaitTime = 200;

int Mode = 0;

/**

  Rainbowz Declarations

*/

unsigned short pixelnumber = 0;

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
int printDelay = 50; //Time between each serial print (default: 50ms)


float scalings[2][3] {
  {0, 0, 0}, //minX, minY, minZ
  {0, 0, 0} //maxX, maxY, maxZ
};

int brightness = 0;
int fadeAmount = 1;  //Change it to adjust the fading between each step (fading speed)
int maxBrightness = 190;
int delayAmount = 0;
int strangeRandom;
int strangeSlowAmount;
int strangeSlowDelay;
int strangeSlowCount;

/**

  POTENTIOMETER declarations

*/


int pot_val;

//variables to hold R, G, B  values
double xx = 0.01;
double yy = 0.01;
double zz = 0.01;

//constants
double aa = 10.00;
double bb = 28.00;
double cc = 8.00 / 3.00;



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

  Setup

*/

void setup() {
  Serial.begin(115200);
  /* Start the DotStar LED */
  pixel.begin();
  pixel.setBrightness(maxBrightness);
  pixel.setPixelColor(0, redValue, blueValue, greenValue);
  pixel.show();

  // Set a Startup Mode
  Mode = 1;

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

  // Strange Attractor 1
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

      x = 0.01;
      y = 0.3;
      z = 0.7;

      strangeSlowCount = 0;

      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
    else
    {
      if (WaitForModeChange)
      {

        //Call the main routine and loop the thing
        strangeAttractor ();
      }
      // Wait for the Mode Change
      modeChangeWait();
    }
  }

  // Strange Attractor 2
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

      x = 0.1;
      y = 2;
      z = 1;

      strangeSlowCount = 0;

      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
    else
    {
      if (WaitForModeChange)
      {

        //Call the main routine and loop the thing
        strangeAttractor ();
      }
      // Wait for the Mode Change
      modeChangeWait();
    }
  }

  // Strange Attractor 3
  if (Mode == 3)
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

      x = 0.5;
      y = 0.9;
      z = 0.1;

      strangeSlowCount = 0;

      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
    else
    {
      if (WaitForModeChange)
      {

        // Call the main routine and loop the thing
        strangeAttractor ();
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

      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
    else
    {
      if (WaitForModeChange)
      {

        //Call the main routine and loop the thing
        speedyAttractorz();
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
        speedyAttractorz();
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
        speedyAttractorz();

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


      }
      // Wait for the Mode Change
      modeChangeWait();
    }
  }

  // Strange Attractor 1
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

      x = 0.01;
      y = 0.3;
      z = 0.7;

      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
    else
    {
      if (WaitForModeChange)
      {

        //Call the main routine and loop the thing
        strangeAttractor ();
      }
      // Wait for the Mode Change
      modeChangeWait();
    }
  }

  // Strange Attractor 2
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

      x = 0.1;
      y = 2;
      z = 1;

      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
    else
    {
      if (WaitForModeChange)
      {

        //Call the main routine and loop the thing
        strangeAttractor ();
      }
      // Wait for the Mode Change
      modeChangeWait();
    }
  }

  // Strange Attractor 3
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

      x = 0.5;
      y = 0.9;
      z = 0.1;

      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
    else
    {
      if (WaitForModeChange)
      {

        // Call the main routine and loop the thing
        strangeAttractor ();
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
      valueLog = log(analogRead(A0) + 1) / log(1024) * 255;
      //Serial.println("Mode 1 valueLog: " + String(valueLog));
      fadeSpeed = map(valueLog, 0, 255, (speedMinimum / 2), (40 / 2)); // Logarithmic Potentiometer Value

      //fadeSpeed = map(analogRead(A0), 0, 1024, (speedMinimum/10), 0);
      maxBrightness = map(analogRead(A1), 0, 1024, 0, 190);
      pixel.setBrightness(maxBrightness);
    }
    // Potentiometer Top Right | A0 - Map the value of the Potentiometer to a Variable
    else if (Mode == 2) {
      valueLog = log(analogRead(A0) + 1) / log(1024) * 255;
      //Serial.println("Mode 1 valueLog: " + String(valueLog));
      fadeSpeed = map(valueLog, 0, 255, (speedMinimum / 2), (40 / 2)); // Logarithmic Potentiometer Value
      //fadeSpeed = map(analogRead(A0), 0, 1024, (speedMinimum/10), 0);
      maxBrightness = map(analogRead(A1), 0, 1024, 0, 190);
      pixel.setBrightness(maxBrightness);
    }

    else if (Mode == 3) {
      valueLog = log(analogRead(A0) + 1) / log(1024) * 255;
      //Serial.println("Mode 1 valueLog: " + String(valueLog));
      fadeSpeed = map(valueLog, 0, 255, (speedMinimum / 2), (40 / 2)); // Logarithmic Potentiometer Value
      //fadeSpeed = map(analogRead(A0), 0, 1024, (speedMinimum/10), 0);
      maxBrightness = map(analogRead(A1), 0, 1024, 0, 190);
      pixel.setBrightness(maxBrightness);
    }
    else if (Mode == 4) {
      valueLog = log(analogRead(A0) + 1) / log(1024) * 255;
      //Serial.println("Mode 1 valueLog: " + String(valueLog));
      fadeSpeed = map(valueLog, 0, 255, (speedMinimum / 2), (40 / 2)); // Logarithmic Potentiometer Value
      //fadeSpeed = map(analogRead(A0), 0, 1024, durationMaximum, 0);
      maxBrightness = map(analogRead(A1), 0, 1024, 0, 190);
      pixel.setBrightness(maxBrightness);
    }
    else if (Mode == 5) {
      valueLog = log(analogRead(A0) + 1) / log(1024) * 255;
      //Serial.println("Mode 1 valueLog: " + String(valueLog));
      fadeSpeed = map(valueLog, 0, 255, (speedMinimum / 2), (40 / 2)); // Logarithmic Potentiometer Value
      //fadeSpeed = map(analogRead(A0), 0, 1024, durationMaximum, 0);
      maxBrightness = map(analogRead(A1), 0, 1024, 0, 190);
      pixel.setBrightness(maxBrightness);
    }
    else if (Mode == 6) {
      valueLog = log(analogRead(A0) + 1) / log(1024) * 255;
      //Serial.println("Mode 1 valueLog: " + String(valueLog));
      fadeSpeed = map(valueLog, 0, 255, (speedMinimum / 2), (40 / 2)); // Logarithmic Potentiometer Value
      //fadeSpeed = map(analogRead(A0), 0, 1024, durationMaximum, 0);
      maxBrightness = map(analogRead(A1), 0, 1024, 0, 190);
      pixel.setBrightness(maxBrightness);
    }
    else {
      fadeSpeed = 7;
      //Serial.println("Else fadeSpeeed: " + String(fadeSpeed));
    }

    //Make this number smaller to fade faster
    if (Mode == 1)
    {
      delay(0);
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
      maxBrightness = map(analogRead(A1), 0, 1024, 0, 190);
      pixel.setBrightness(maxBrightness);
    }
    // Potentiometer Top Left | A1 - Map the value of the potentiometer to a variable and Update the Variable(s)
    else if (Mode == 2) {
      maxBrightness = map(analogRead(A1), 0, 1024, 0, 190);
      pixel.setBrightness(maxBrightness);
    }
    else if (Mode == 3) {
      maxBrightness = map(analogRead(A1), 0, 1024, 0, 190);
      pixel.setBrightness(maxBrightness);
    }
    else if (Mode == 4) {
      maxBrightness = map(analogRead(A1), 0, 1024, 0, 190);
      pixel.setBrightness(maxBrightness);
    }
    else if (Mode == 5) {
      maxBrightness = map(analogRead(A1), 0, 1024, 0, 190);
      pixel.setBrightness(maxBrightness);
    }
    else if (Mode == 6) {
      maxBrightness = map(analogRead(A1), 0, 1024, 0, 190);
      pixel.setBrightness(maxBrightness);
    }
    else if (Mode == 7) {

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

    if (Mode ==  1) {
      maxBrightness = map(analogRead(A1), 0, 1024, 0, 190);
      pixel.setBrightness(maxBrightness);
    }
    //Potentiometer Bottom Right | A2 - Map the value of the potentiometer to a variable and Update the Variable(s)
    else if (Mode == 2) {
      maxBrightness = map(analogRead(A1), 0, 1024, 0, 190);
      pixel.setBrightness(maxBrightness);
    }
    else if (Mode == 3) {
      maxBrightness = map(analogRead(A1), 0, 1024, 0, 190);
      pixel.setBrightness(maxBrightness);
    }
    else if (Mode == 4) {
      maxBrightness = map(analogRead(A1), 0, 1024, 0, 190);
      pixel.setBrightness(maxBrightness);
    }
    else if (Mode == 5) {
      maxBrightness = map(analogRead(A1), 0, 1024, 0, 190);
      pixel.setBrightness(maxBrightness);
    }
    else if (Mode == 6) {
      maxBrightness = map(analogRead(A1), 0, 1024, 0, 190);
      pixel.setBrightness(maxBrightness);
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


  //Fade in from the beginning of the Rainbow cycle (Red)
  for (int x = 0; x < 255; x++)
  {
    if ((analogRead(A0) <= ValueZeroAdjustment) && (analogRead(A1) <= ValueZeroAdjustment) && (analogRead(A2) <= ValueZeroAdjustment)) {
      x = 0;
      Serial.println("I Broke");
      break;
    }

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
        pixel.setPixelColor(0, 36, 0, 255);
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
        Mode = Mode + 1;
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
      if (Blink1 = true)
      {
        valueA1 = map(analogRead(A1), 0, 1024, 0, 20);
        pixel.setPixelColor(0, valueA1, (valueA1 / 5), 0); // Blink 1
        pixel.setBrightness(valueA1);
        pixel.show();
      }
      if (Blink1 = false)
      {
        valueA2 = map(analogRead(A2), 0, 1024, 0, 255);
        pixel.setPixelColor(0, (valueA2 / 6), valueA2, valueA2); // Blink 2
        pixel.setBrightness(valueA2);
        pixel.show();
      }
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

  STRANGE ATTRACTORS

*/
//
//  This Section is the Strange Attractor loop
//

void strangeAttractor()
{

  //controlsMax();
  //scaledY = 100;

  //Don't execute the code if not enough time has elapsed
  if (millis() > nextLorenzUpdate) {

    lorenzFunction();
    nextLorenzUpdate = millis() + (printDelay);

    brightenColors();

    printDelay = map(analogRead(A0), 0, 1024, 10, 15);

    //A0 potentiometer controls for fade speed
    //delayAmount = map(analogRead(A0), 0, 1024, (speedMinimum/10), 0);

    //A2 potentiometer controls for amount of randomless from less to more random
    b = map(analogRead(A2), 0, 1024, 20, 50);

    strangeBright();
    //strangeBrightMinDark();

    maxBrightness = map(analogRead(A1), 0, 1024, 0, 190);
    pixel.setBrightness(maxBrightness);

    pixel.show();
    //delay(delayAmount);
    delayA0(fadeSpeed);

    // Slow down the simulation when the value is low

    strangeSlow();

    //Serial.println("darkDelay: " + String(darkDelay) + " scaledY : " + String(scaledY));

    plotCycle();

  }

}

void strangeBright() {

  //A1 potentiometer controls for maximum brightness
  maxBrightness = map(analogRead(A1), 0, 1024, 0, 190);
  pixel.setBrightness(maxBrightness);
  //Serial.println(maxBrightness);

  //Modes
  /* Set a value for each potentiometer (pin) for colors R,G,B. */

  if (Mode == 1)
  {
    pixel.setPixelColor(0, (scaledX / 4), 0, (scaledX / 8)); //Single Output Scaled X
    //pixel.setPixelColor(0, x, 0, 30); //Single Output Scaled X
  }
  if (Mode == 2)
  {
    pixel.setPixelColor(0, (scaledX / 4), 0, (scaledZ / 4)); //Double Output Scaled X & Z
    //pixel.setPixelColor(0, x, 0, z+100); //Double Output Scaled X & Z
  }
  if (Mode == 3)
  {
    pixel.setPixelColor(0, (scaledX / 2), (scaledY / 6), (scaledZ / 2)); //Triple Output Scaled XYZ
  }

}


void strangeBrightMinDark() {

  if ((scaledY >= 0) && (scaledY <= 50)) {
    pixel.setBrightness(maxBrightness - 255);
    pixel.setPixelColor(0, 0, 0, 0);
  }
  else if ((scaledY >= 51) && (scaledY <= 255))
  {
    //A1 potentiometer controls for maximum brightness
    maxBrightness = map(analogRead(A1), 0, 1024, 0, 190);
    pixel.setBrightness(maxBrightness);
    //Serial.println(maxBrightness);

    //Modes
    /* Set a value for each potentiometer (pin) for colors R,G,B. */

    if (Mode == 1)
    {
      pixel.setPixelColor(0, (scaledX / 4), 0, (scaledX / 8)); //Single Output Scaled X
      //pixel.setPixelColor(0, x, 0, 30); //Single Output Scaled X
    }
    if (Mode == 2)
    {
      pixel.setPixelColor(0, (scaledX / 4), 0, (scaledZ / 4)); //Double Output Scaled X & Z
      //pixel.setPixelColor(0, x, 0, z+100); //Double Output Scaled X & Z
    }
    if (Mode == 3)
    {
      pixel.setPixelColor(0, (scaledX / 2), (scaledY / 6), (scaledZ / 2)); //Triple Output Scaled XYZ
    }
  }

}

void strangeSlow() {


  if ((strangeSlowCount >= 0) && (strangeSlowCount <= 20)) {
    strangeSlowCount = strangeSlowCount + 1;
  }
  else {
    // Slow down the simulation when the value is low
    if ((scaledY >= 0) && (scaledY <= 50)) {
      valueA0 = map(analogRead(A0), 0, 1024, 1000, 0);
      strangeRandom = random(20, 200);
      strangeSlowAmount = (strangeRandom + valueA0);
      darkDelay = strangeSlowAmount;
      //darkDelay = strangeSlowAmount;
      delayA2(darkDelay);

      maxBrightness = map(analogRead(A1), 0, 1024, 0, 190);
      pixel.setBrightness(maxBrightness);
      //Serial.println("strangeSlow: " + String(darkDelay) + " strangeSlowAmount : " + String(strangeSlowAmount));
      Serial.println("scaledY: " + String(scaledY) + " darkDelay : " + String(darkDelay) + " strangeSlowCount : " + String(strangeSlowCount));

    }
  }
}



/**

  STRANGE ATTRACTORS Lorentz

  This Section is the Strange Attractor maths and stuff called by the strangeAttractor() function

     This function performs the calculations for the Lorenz equation

*/

void lorenzFunction() {

  // I divided each equation in two steps:
  // Before I calculation and sum to the old value in the same step, now I divided it

  dx = (a * (y - x)) * dt;
  dy = (x * (b - z) - y) * dt;
  dz = ((x * y) - (c * z)) * dt;

  x += dx;
  y += dy;
  z += dz;

  /*
     I don't know exactly what range of values can the lorenz return

     So I created a function to adjust the scalings if a value is outside the range

  */

  updateScaling(0, 0, 1, 0, x);
  updateScaling(0, 1, 1, 1, y);
  updateScaling(0, 2, 1, 2, z);

  //Values are scaled to 0-255 to adapt to the analogWrite function

  scaledX = map(x, scalings[0][0], scalings[1][0], 0, 190);
  scaledY = map(y, scalings[0][1], scalings[1][1], 0, 190);
  scaledZ = map(z, scalings[0][2], scalings[1][2], 0, 190);

}



/**

  Strange Attractors - Brighten Colors

       Brightness is managed as follows:
        When brightness should be maximum:
          Nothing happens to not affect the colors

*/

void brightenColors() {

  // When brightness should be minimum:
  // Variables are decreased to obtain minimum brightness without affecting the color

  if (fadeAmount < 0) {
    //Brightness is decreasing
    //Results are decreased to match with the wanted brightness

    effectiveR = brightness;                        //Red (x) is the master
    effectiveG = (scaledX / scaledY) * effectiveR;  //Proportion must remain unchanged
    effectiveB = (scaledX / scaledZ) * effectiveR;  //Proportion must remain unchanged

    if (effectiveR < 0) effectiveR = 0; //Results must be greater or equal to 0
    if (effectiveG < 0) effectiveG = 0; //Results must be greater or equal to 0
    if (effectiveB < 0) effectiveB = 0; //Results must be greater or equal to 0

    /*Serial.print("Fading  ");
      Serial.print(brightness);
      Serial.print("  ");
      Serial.print(effectiveR);
      Serial.print("  ");
      Serial.print(effectiveG);
      Serial.print("  ");
      Serial.println(effectiveB);
      delay(3000);*/

  } else {
    //Brightness is increasing
    //Results remains unchanged

    effectiveR = scaledX;
    effectiveG = scaledY;
    effectiveB = scaledZ;

  }

  brightness += fadeAmount;

  if (brightness <= 0 || brightness >= 190) {
    fadeAmount = -fadeAmount;
  }

}

/**

  Lorentz Speedy

*/

void speedyAttractorz() {
  valueA1 = map(analogRead(A1), 0, 1024, 0, 255);
  pixel.setBrightness(valueA1); //set brightness

  valueA2 = map(analogRead(A2), 0, 1024, 0, 5);

  double dt = 1081 / 100000.00; //calculate the time def. acording to potentiometer map value
  //double dt = pot_val / 999000.00; //calculate the time def. acording to potentiometer map value

  //Serial.print(pot_val); //print it on serial monitor
  Serial.print(dt); Serial.print(","); //print it on serial monitor

  //chaotic system (lorentz) math calculations
  double dx = (aa * (yy - xx)) * dt;
  double dy = (xx * (bb - zz) - y) * dt;
  double dz = (xx * yy - cc * zz) * dt;

  //summing each result with previos result
  xx = xx + dx;
  yy = yy + dy;
  zz = zz + dz;

  //print on serial monitor
  Serial.print(scale_val(xx)); Serial.print(",");
  Serial.print(scale_val(yy)); Serial.print(",");
  Serial.print(scale_val(zz)); Serial.print(",");
  Serial.println();

  //pixel.setPixelColor(0, scale_val(x), scale_val(y), scale_val(z)); //set R, G, B values to dot star
  if (Mode == 4) {
    pixel.setPixelColor(0, scale_val(xx), 0, 0); //set R, G, B values to dot star
  }
  if (Mode == 5) {
    pixel.setPixelColor(0, scale_val(xx), 0, scale_val(zz)); //set R, G, B values to dot star
  }
  if (Mode == 6) {
    pixel.setPixelColor(0, scale_val(xx), scale_val(yy), scale_val(zz)); //set R, G, B values to dot star
  }
  pixel.show(); //display the dot star
  strangeSlowSpeedy();
  delayA0(fadeSpeed);
}

//function to convert number from -20 - 70 to -20 - 255 range
int scale_val(int val) {
  if (val < -20) val = -20;
  if (val > 70) val = 70;
  return map(val, -20, 70, -20, 255);
}

void strangeSlowSpeedy() {

  valueA2 = map(analogRead(A2), 0, 1024, 0, 1000);
  valueA1 = map(analogRead(A1), 0, 1024, 0, 255);
  pixel.setBrightness(valueA1); //set brightness

  // Slow down the simulation when the value is low
  if ((scale_val(xx) >= -1) && (scale_val(xx) <= 1)) {
    strangeRandom = random(20, 200);
    strangeSlowAmount = (strangeRandom + (delayAmount * 2));
    darkDelay = strangeSlowAmount + valueA2;
    delayA2(darkDelay);
    //Serial.println("slowSpeedy: " + String(scale_val(xx)) + " strangeSlowDelay : " + String(strangeSlowDelay));

  }


  //Serial.println("Count if Waiting = False: " + String(count));
}

/**

  Serial Printing and Plotting

  This Section includes different ways to print and plot the variable to the Arduino Serial Monitor and Serial Plotter

*/

void plotCycle()
{

  //Serial.println(" A0 = " + String(analogRead(A0)) + " A1 = " + String(analogRead(A1)) + " A2 = " + String(analogRead(A2)));

  if (plotterPrint == true) {

    ///*
    if (Mode == 1)
    {
      //Print some things
      Serial.print("Min:0,Max:200"); //Un-comment this for a smooth line
      Serial.print(","); //Un-comment this for a smooth line

      //printStrangeScaled(); // This one is nice
      //printStrangeScaled2();
      //printStrangeScaled3(); // This one is nice
      //printStrangeScaledSingle();

      //printStrangeEffective();

      //Serial.print("Min:0,Max:100");
      printStrangeXYZ(); // This one is the coolest

    }

    // If the Mode is 2-5, run print for fades
    if ((Mode >= 1) && (Mode <= 3))
    {
      //Print some things
      Serial.print("Min:0,Max:200"); //Un-comment this for a smooth line
      Serial.print(","); //Un-comment this for a smooth line

      //printStrangeScaled(); // This one is nice
      //printStrangeScaled2();
      //printStrangeScaled3(); // This one is nice
      //printStrangeScaledSingle();

      //printStrangeEffective();

      //Serial.print("Min:0,Max:100");
      printStrangeXYZ(); // This one is the coolest
    }

    if ((Mode >= 6) && (Mode <= 7))
      //if (6 <= Mode)
    {

    }
    if ((Mode >= 8) && (Mode <= 10))
      //if (6 <= Mode)
    {
      //Print some things
      Serial.print("Min:0,Max:200"); //Un-comment this for a smooth line
      Serial.print(","); //Un-comment this for a smooth line

      //printStrangeScaled(); // This one is nice
      //printStrangeScaled2();
      //printStrangeScaled3(); // This one is nice
      //printStrangeScaledSingle();

      //printStrangeEffective();

      //Serial.print("Min:0,Max:100");
      printStrangeXYZ(); // This one is the coolest
    }
    else;
  }
  //*/
}

void printStrangeXYZ()
{
  Serial.println("x:  " + String(x + 100) + " y:  " + String(y + 100) + " z:  " + String(z + 100));
  Serial.print("\n"); //Comment this line to not have a space between cicles
  //Serial.println("A0:  " + String(analogRead(A0)) + " A1:  " + String(analogRead(A1)) + " A2:  " + String(analogRead(A2)));
}


void printStrangeScaled()
{
  Serial.println(String(scaledX));
  Serial.println(String(scaledY));
  Serial.println(String(scaledZ));
}

void printStrangeScaled2()
{
  Serial.println("x:  " + String(scaledX) + " y:  " + String(scaledY) + " z:  " + String(scaledZ));
  Serial.print("\n"); //Comment this line to not have a space between cicles
}

void printStrangeScaled3()
{
  Serial.println(String(scaledX));
  Serial.print("\n"); //Comment this line to not have a space between cicles
  Serial.println(String(scaledY));
  Serial.print("\n"); //Comment this line to not have a space between cicles
  Serial.println(String(scaledZ));
  Serial.print("\n"); //Comment this line to not have a space between cicles
}

void printStrangeScaledSingle()
{
  //Serial.print(F("x:  "));
  //Serial.println(String(scaledX));
  //Serial.print(F("y:  "));
  //Serial.println(String(scaledY));
  Serial.print(F("z:  "));
  Serial.println(String(scaledZ));
  //Serial.print("\n"); //Comment this line to not have a space between cicles
}

void printStrangeEffective()
{
  Serial.print(F("  |  "));
  Serial.println(effectiveR);
  Serial.print(F("  |  "));
  Serial.println(effectiveG);
  Serial.print(F("  |  "));
  Serial.println(effectiveB);
  Serial.print("\n"); //Comment this line to not have a space between cicles
}


/**

  STRANGE ATTRACTORS Functions

  This Section is the Strange Attractor maths and stuff called by the strangeAttractor() function

*/

void updateScaling(byte rowA, byte cellA, byte rowB, byte cellB, float checkValue) {

  if (checkValue < scalings[rowA][cellA]) { //If the variable is higher than the current max scale value, then update the max scale value
    scalings[rowA][cellA] = checkValue;
  }

  if (checkValue > scalings[rowB][cellB]) { //If the variable is lower than the current min scale value, then update the min scale value
    scalings[rowB][cellB] = checkValue;
  }

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
    Programmer : Ranga Marasinghe
    Date       : 2021-April-22
    https://www.fiverr.com/ranga_niroshan

  Fading
    Programmer : Guljanjua
    Date       : 2021-April-21
    https://www.fiverr.com/guljanjua

    Rainbow Mode
    https://www.instructables.com/How-to-Make-Proper-Rainbow-and-Random-Colors-With-/

  Strange Attractorz Lorentz
    Programmer : Timothy Franceschi
    Date       : 2021-April-21
    https://www.fiverr.com/timofran

  Alpha and Beta Brainz Testers
    Ancient Radiations
    Forrest Hopkins
    LEEMS Industries
    Aotokumo
    Andy Pitcher
    Mask Audio Electronics
    Aaron Meagher - Discrete Circuitry

  Special Thanks
    Rarebuzzer
    Mask Audio Electronics
    El Garatge
    Obscura MFG
    Lightning Wave
    Collector//Emitter Discord Community






*/
