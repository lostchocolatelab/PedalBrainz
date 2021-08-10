
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
//  
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

/**

  Rainbowz Declarations

*/

unsigned short pixelnumber = 0;
int maxBrightness = 190;
int currentVal;
float randomAmount;


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
  //Mode = 1;
  
  plotterPrint = true; // This prints to the Serial.Plotter and when set to True can slow down some Modez. Set to False to remove Serial Plotting of Values

  
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
      fadeSpeed = map(analogRead(A0), 0, 1024, (speedMinimum/10), -1);
      //Serial.println("Mode 4 fadeSpeeed: " + String(fadeSpeed));

    }
    // Potentiometer Top Right | A0 - Map the value of the Potentiometer to a Variable
    else if (Mode == 2) {
      fadeSpeed = map(analogRead(A0), 0, 1024, (speedMinimum/10), -1);
      //Serial.println("Mode 5 fadeSpeeed: " + String(fadeSpeed));
    }
    
    else if (Mode == 3) {
      valueLog = log(analogRead(A0)+1)/log(1024)*255;
      //Serial.println("Mode 1 valueLog: " + String(valueLog));
      fadeSpeed = map(valueLog, 0, 255, (speedMinimum/2), (40/2)); // Logarithmic Potentiometer Value
      //fadeSpeed = map(analogRead(A0), 0, 1024, durationMaximum, 0);
    }
    else if (Mode == 4) {
      valueLog = log(analogRead(A0)+1)/log(1024)*255;
      //Serial.println("Mode 1 valueLog: " + String(valueLog));
      fadeSpeed = map(valueLog, 0, 255, (speedMinimum/2), (40/2)); // Logarithmic Potentiometer Value
      //fadeSpeed = map(analogRead(A0), 0, 1024, durationMaximum, 0);

    }
    else if (Mode == 5) {
      valueLog = log(analogRead(A0)+1)/log(1024)*255;
      //Serial.println("Mode 1 valueLog: " + String(valueLog));
      fadeSpeed = map(valueLog, 0, 255, (speedMinimum/2), (40/2)); // Logarithmic Potentiometer Value
      //fadeSpeed = map(analogRead(A0), 0, 1024, durationMaximum, 0);

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
      fullDelay = map(analogRead(A1), 0, 1024, speedMinimum, 100); // Linear Potentiometer Value
      //Serial.println("Mode 1 fullDelay: " + String(fullDelay));
    }
    else if (Mode == 4) {
      fullDelay = map(analogRead(A1), 0, 1024, speedMinimum, 100); // Linear Potentiometer Value
      //Serial.println("Mode 1 fullDelay: " + String(fullDelay));
    }
    else if (Mode == 5) {
      fullDelay = map(analogRead(A1), 0, 1024, speedMinimum, 100); // Linear Potentiometer Value
      //Serial.println("Mode 1 fullDelay: " + String(fullDelay));
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
        if (4 >= Mode)
        {
          Mode = Mode+1;
          //Serial.println("Mode Change = " + String(Mode));
        }
        else if (Mode == 5)
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
