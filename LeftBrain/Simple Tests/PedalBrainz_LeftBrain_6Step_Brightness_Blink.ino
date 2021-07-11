//
//  Pedal Brainz - Rainbow Brightness Modulation
//
//  Cycles through 6 colors. The Brightness of each color is modulated 4 times. Default brightness set in declarations.
//  Un-comment 'setRandomBrights' in Setup to randomize Brightness values for the 4 values once at startup
//  Un-comment 'setRandomBrights' in Loop to randomize Brightness values for the 4 values after each cycle
//
//  Set Color -> Set 4 Brightness Values w/ Delay (A1) -> Delay before setting next Color (A0)
//  
//  A0 = Delay of each Brightness Value (4) for a Single Color
//  A1 = Duration of 4th brightness after brightness changes for a single color
//  A2 = Duration of Darkness after full Color Cycle (or betwixt each color if darkDelayBetwixtColors is enabled)
//

#include <Adafruit_DotStar.h>

/* Set the DotStar as "pixel". */
Adafruit_DotStar pixel = Adafruit_DotStar(1, INTERNAL_DS_DATA, INTERNAL_DS_CLK, DOTSTAR_BGR);

/**

  POTENTIOMETER declarations

*/

int valueA0 = 0;
int valueA1 = 0;
int valueA2 = 0;

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

int LEDBrightness;

// Some Colors
uint32_t colorRed = 0xFF0000;
uint32_t colorOrange = 0xFF6600;
uint32_t colorYellow = 0xFFFF00;
uint32_t colorGreen = 0x00FF00;
uint32_t colorBlue = 0x0000FF;
uint32_t colorPurple = 0x660CCF;
uint32_t colorPink = 0xFF69B4;

// Sets the value in milleseconds of the slowest fadeSpeed for delayA0
int speedMinimum = 5000;

// Sets the value in milleseconds of the longest duration for delayA1 and delayA2
int durationMaximum = 10000;

int valueLog;

int randomBright01 = 20;
int randomBright02 = 60;
int randomBright03 = 110;
int randomBright04 = 170;



void setup() {
    Serial.begin(57600);
    /* Start the DotStar LED */
    pixel.begin();
    //pixel.setBrightness(155);

    // Un-comment 'setRandomBrights' in Setup to randomize Brightness values for the 4 values once at startup
    //setRandomBrights();


}

void loop() {

    // Un-comment 'setRandomBrights' in Loop to randomize Brightness values for the 4 values after each cycle
    //setRandomBrights();
    
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
    
    pixel.setPixelColor(0, colorOrange); 
    pixel.show();
    quadBrightness();  
    delayA1(fullDelay);
    darkDelayBetwixtColors();
    pixel.setPixelColor(0, colorYellow); 
    pixel.show();  
    quadBrightness();  
    delayA1(fullDelay);
    darkDelayBetwixtColors();
    pixel.setPixelColor(0, colorGreen); 
    pixel.show();  
    quadBrightness();  
    delayA1(fullDelay);
    darkDelayBetwixtColors();
    pixel.setPixelColor(0, colorBlue); 
    pixel.show();
    quadBrightness();  
    delayA1(fullDelay);
    darkDelayBetwixtColors();
    pixel.setPixelColor(0, colorPurple); 
    pixel.show();  
    quadBrightness();  
    delayA1(fullDelay);
    

    // Make the pixel dark
    pixel.setBrightness(0);
    pixel.show();    

    // Delay by the amount of A2
    delayA2(darkDelay);
    
    //darkDelayBetwixtColors();
    
 
  //pixel.show(); 
  
}


void delayA0(int count)
{

  int delayCountA0 = fadeSpeed;

  plotCycle();

  for (int count = 0; count <= delayCountA0; count++) 
  {
    delayCountA0 = fadeSpeed;

    plotCycle();


    // Potentiometer Top Right | A0 - Map the value of the Potentiometer to a Variable

      valueLog = log(analogRead(A0)+1)/log(1024)*255;
      //Serial.println("Mode 1 valueLog: " + String(valueLog));
      fadeSpeed = map(valueLog, 0, 255, (speedMinimum/2), (40/2)); // Logarithmic Potentiometer Value
      //fadeSpeed = map(analogRead(A0), 0, 1024, durationMaximum, 0);
      
      //Serial.println("Mode 1 fadeSpeeed: " + String(fadeSpeed));

      //valueA1 = map(analogRead(A1), 0, 1024, 0, 90);
      //valueA2 = map(analogRead(A2), 0, 1024, 0, 90);
   
      delay(1);
    
  }
}

/**

  A1 Delay - Full Delay

*/


void delayA1(int count)
{

  int delayCountA1 = fullDelay;


  for (int count = 0; count <= delayCountA1; count++) 
  {

    delayCountA1 = fullDelay;

    plotCycle();
      fullDelay = map(analogRead(A1), 0, 1024, 100, speedMinimum); // Linear Potentiometer Value
      //Serial.println("Mode 1 fullDelay: " + String(fullDelay));
   
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

  for (int count = 0; count <= delayCountA2; count++) 
  {

    delayCountA2 = darkDelay;
    //Serial.println("delayA2 delayCountA2: " + String(delayCountA2));
    
    plotCycle();

      darkDelay = map(analogRead(A2), 0, 1024, 0, durationMaximum);
      //Serial.println("Mode 1 darkDelay: " + String(darkDelay));
    
    delay(1);
    //controlsMax();
    //Serial.println("Count if Waiting = False: " + String(count));
  }
}

void quadBrightness()
{
  // Set the brightness
  pixel.setBrightness(randomBright01);
  pixel.show(); 
  // Delay the change to the next brightness by the amount of A1
  delayA0(fadeSpeed);
  
  //Serial.println("Full Delay 1: " + String(fullDelay));

  // Set the brightness
  pixel.setBrightness(randomBright02);
  pixel.show(); 
  // Delay the change to the next brightness by the amount of A1
  delayA0(fadeSpeed);
  
  //Serial.println("Full Delay 2: " + String(fullDelay));

  // Set the brightness
  pixel.setBrightness(randomBright03);
  pixel.show(); 
  // Delay the change to the next brightness by the amount of A1
  delayA0(fadeSpeed);
  
  //Serial.println("Full Delay 3: " + String(fullDelay));

  // Set the brightness
  pixel.setBrightness(randomBright04);
  pixel.show(); 
  // Delay the change to the next brightness by the amount of A1
  delayA0(fadeSpeed);
  
  //Serial.println("Full Delay 4: " + String(fullDelay));


  
}

void setRandomBrights() {

randomBright01  = random(10, 255);
randomBright02  = random(10, 255);
randomBright03  = random(10, 255);
randomBright04  = random(10, 255);
  
}

void darkDelayBetwixtColors(){
  
    // Make the pixel dark 
    pixel.setBrightness(0);
    pixel.show();    

    // Delay by the amount of A2 - Remove the following comment to turn the led off between each color 
    delayA2(darkDelay);

}
  
void plotCycle()
{
    //Serial.println(fadeSpeed);
    //Serial.println("Full Delay 4: " + String(fullDelay));
}
