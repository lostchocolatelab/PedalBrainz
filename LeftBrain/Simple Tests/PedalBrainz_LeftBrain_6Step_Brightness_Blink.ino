
#include <Adafruit_DotStar.h>

/* Set the DtoStar as "pixel". */
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



void setup() {
    Serial.begin(57600);
    /* Start the DotStar LED */
    pixel.begin();
    //pixel.setBrightness(155);
}

void loop() {

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
    delayA0(fadeSpeed);
    pixel.setPixelColor(0, colorYellow); 
    pixel.show();  
    quadBrightness();  
    delayA0(fadeSpeed);
    pixel.setPixelColor(0, colorGreen); 
    pixel.show();  
    quadBrightness();  
    delayA0(fadeSpeed);
    pixel.setPixelColor(0, colorBlue); 
    pixel.show();
    quadBrightness();  
    delayA0(fadeSpeed);
    pixel.setPixelColor(0, colorPurple); 
    pixel.show();  
    quadBrightness();  
    delayA0(fadeSpeed);

    // Make the pixel dark
    pixel.setBrightness(0);
    pixel.show();    

    // Delay by the amount of A2
    delayA2(darkDelay);

    
 
  //pixel.show(); 
  Serial.println(fadeSpeed);
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

      //valueLog = log(analogRead(A0)+1)/log(1024)*255;
      //Serial.println("Mode 1 valueLog: " + String(valueLog));
      //fadeSpeed = map(valueLog, 0, 255, (speedMinimum/2), (40/2)); // Logarithmic Potentiometer Value
      fadeSpeed = map(analogRead(A0), 0, 1024, speedMinimum, 100); // Linear Potentiometer Value
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
      fullDelay = map(analogRead(A1), 0, 1024, 0, durationMaximum);
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
  pixel.setBrightness(20);
  pixel.show(); 
  // Delay the change to the next brightness by the amount of A1
  delayA1(fullDelay);
  Serial.println("Full Delay 1: " + String(fullDelay));

  // Set the brightness
  pixel.setBrightness(60);
  pixel.show(); 
  // Delay the change to the next brightness by the amount of A1
  delayA1(fullDelay);
  Serial.println("Full Delay 2: " + String(fullDelay));

  // Set the brightness
  pixel.setBrightness(100);
  pixel.show(); 
  // Delay the change to the next brightness by the amount of A1
  delayA1(fullDelay);
  
  Serial.println("Full Delay 3: " + String(fullDelay));

  // Set the brightness
  pixel.setBrightness(170);
  pixel.show(); 
  // Delay the change to the next brightness by the amount of A1
  delayA1(fullDelay);
  
  Serial.println("Full Delay 4: " + String(fullDelay));
}

void plotCycle()
{
  
}
