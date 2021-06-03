/*
 * This is a Randomly cycling waveform based on Strange Attractors math (Lorentz Function) 
 * and can be configured for one, two, or three waveforms to drive the individual RGB values of the DotStar.
 * 
 * DK:
 * A0 - Randomness Amount (Less = Sine-like)
 * A1 - Maximum Brightness
 * A2 - Rate (Less = Slower)
 * 
 * Original Sketch by:
 * Timothy Franceschi
 * 21/04/2021
 * https://www.fiverr.com/timofran
 */

#include <Adafruit_DotStar.h>

#define INTERNAL_DS_DATA 3 //Change according to your project
#define INTERNAL_DS_CLK  4 //Change according to your project

/* Set the DtoStar as "pixel". */
Adafruit_DotStar pixel = Adafruit_DotStar(1, INTERNAL_DS_DATA, INTERNAL_DS_CLK, DOTSTAR_BGR);

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
                      {0,0,0},  //minX, minY, minZ
                      {0,0,0}   //maxX, maxY, maxZ 
                     };

int brightness = 0;
int fadeAmount = 1;  //Change it to adjust the fading between each step (fading speed)
int maxBrightness = 255;
int delayAmount = 0;

//#define SIMULATION  //Comment this line to normal run

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); //Increased to reduce cicle duration

  //Execute this code only if in simulation mode
  #ifdef SIMULATION
    while(!Serial) {
      //Wait for serial to connect

      analogWrite(13, brightness);
      analogWrite(11, brightness);
      analogWrite(9, brightness);

      // change the brightness for next time through the loop:
      brightness = brightness + fadeAmount;
    
      // reverse the direction of the fading at the ends of the fade:
      if (brightness <= 0 || brightness >= 255) {
        fadeAmount = -fadeAmount;
      }
      // wait for 30 milliseconds to see the dimming effect
      //delay(30);
      
    }
    Serial.println(F("Type anything to start..."));
    while(!Serial.available()) {
      //Wait for a key to be pressed before to proceed

      //analogWrite(13, brightness);
      //analogWrite(11, brightness);
      //analogWrite(9, brightness);

      // change the brightness for next time through the loop:
      brightness = brightness + fadeAmount;
    
      // reverse the direction of the fading at the ends of the fade:
      if (brightness <= 0 || brightness >= 255) {
        fadeAmount = -fadeAmount;
      }
      // wait for 30 milliseconds to see the dimming effect
      //delay(30);
      
    }
    
  #endif

  #ifdef SIMULATION
    //I set a defined x, y and z if I'm simulating
    x = 0.01;
    y = 0.3;
    z = 0.7;

  #else
    /*
     * If I'm not simulating, I set x,y and z from the potentiometers' readings
     * 
     * Values are scaled 0-1 before the be OK. I don't know if it is necessary but it works
     * We could try to remove this function
     * 
     * If potentiometer is full, then the corresponding variable is deactivated (= 0)
     * 
     */
    //x = map(analogRead(A0),0,1024,0,1);
    //y = map(analogRead(A1),0,1024,0,1);
    //z = map(analogRead(A2),0,1024,0,1);
    

    x = 0.01;
    y = 0.3;
    z = 0.7;

    //x = random(0.01, 0.05);
    //y = 0.3;
    //z = random(0.6, 0.9);

    //if(analogRead(A0) > 1020) x = 0;
    //if(analogRead(A1) > 1020) y = 0;
    //if(analogRead(A2) > 1020) z = 0;
    
  #endif

  pixel.begin();
  pixel.setPixelColor(0, 255, 0, 255);
  pixel.setBrightness(255);
  
}

void loop() {
  
  //I do not execute the code if it is not elapsed enough time
  if(millis() > nextLorenzUpdate){
    
    lorenzFunction();
    nextLorenzUpdate = millis() + (printDelay);

    brightenColors();

    b = map(analogRead(A0), 0, 1024, 20, 35);
    //Serial.println(" A0:  " + String(analogRead(A0)) + " b:  " + String(b));

    printDelay = map(analogRead(A0), 0, 1024, 10, 15);

    //fadeAmount = map(analogRead(A2), 0, 1024, 1, 10);
    //Serial.println(" A2:  " + String(analogRead(A2)) + " fadeAmount:  " + String(fadeAmount));

    maxBrightness = map(analogRead(A1), 0, 1024, 0, 255);
    pixel.setBrightness(maxBrightness);

    delayAmount = map(analogRead(A2), 0, 1024, 0, 300);
    //Serial.println(" A2:  " + String(analogRead(A2)) + " a:  " + String(a));

    /* Set a value for each potentiometer (pin) for colors R,G,B. */
    //pixel.setPixelColor(0, scaledX, 0, 0); //Single Output
    pixel.setPixelColor(0, scaledX, 0, scaledZ); //Double Output
    //pixel.setPixelColor(0, effectiveR, effectiveG, effectiveB); //Triple Output

    pixel.show();                         //Show current configuration
    delay(delayAmount);
     /*
     * I print all variables in a way that can be visualized on the Serial Plotter
     * 
     * Note I used the F() for text. This helps reducing the memory usage
     * 
     */
    Serial.print(F("x:  "));
    Serial.print(scaledX);
    //Serial.print(F("  |  "));
    //Serial.println(effectiveR);
    Serial.print(F("y:  "));
    Serial.print(scaledY);
    //Serial.print(F("  |  "));
    //Serial.println(effectiveG);
    Serial.print(F("z:  "));
    Serial.print(scaledZ);
    //Serial.print(F("  |  "));
    //Serial.println(effectiveB);

    //Serial.println("x:  " + String(x) + " y:  " + String(y) + " z:  " + String(z));
    //Serial.println("A0:  " + String(analogRead(A0)) + " A1:  " + String(analogRead(A1)) + " A2:  " + String(analogRead(A2)));
    

    //If simulating I also print the free SRAM memory portion
    #ifdef SIMULATION
      //Serial.print(F("freeMemory: "));
      //Serial.println((int)freeMemory);
    #endif

    Serial.print("\n"); //Comment this line to not have a space between cicles

    /*analogWrite(13, effectiveR);
    analogWrite(11, effectiveG);
    analogWrite(9, effectiveB);*/
    
  }
  
}

void updateScaling(byte rowA, byte cellA, byte rowB, byte cellB, float checkValue) {

  if(checkValue < scalings[rowA][cellA]){ //If the variable is higher than the current max scale value, then update the max scale value
    scalings[rowA][cellA] = checkValue;
  }

  if(checkValue > scalings[rowB][cellB]){ //If the variable is lower than the current min scale value, then update the min scale value
    scalings[rowB][cellB] = checkValue;
  }
  
}

void lorenzFunction() {

  /*
   * This function performs the calculations for the Lorenz equation
   * 
   * I removed the for cicle and I perform a single calculation to extend the code working time
   * 
   * I divided each equation in two steps:
   * Before I calculation and sum to the old value in the same step, now I divided it
   * 
   */

  dx = (a * (y - x)) * dt;
  dy = (x * (b - z) - y) * dt;
  dz = ((x * y) - (c * z)) * dt;

  x += dx;
  y += dy;
  z += dz;

  /*
   * I don't know exactly what range of values can the lorenz return
   * 
   * So I created a function to adjust the scalings if a value is outside the range
   * 
   */
  
  updateScaling(0,0,1,0,x);
  updateScaling(0,1,1,1,y);
  updateScaling(0,2,1,2,z);

  //Values are scaled to 0-255 to adapt to the analogWrite function

  scaledX = map(x, scalings[0][0], scalings[1][0], 0, 255);
  scaledY = map(y, scalings[0][1], scalings[1][1], 0, 255);
  scaledZ = map(z, scalings[0][2], scalings[1][2], 0, 255);
  
}

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

void brightenColors() {

  /*
   * Brightness is managed as follows:
   *    When brightness should be maximum:
   *      Nothing appens to not affect the colors
   *     
   *    When brightness should be minimum:
   *      Variables are decreased to obtain minimum brightness without affecting the color
   */

  if(fadeAmount < 0) {
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

  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  
}
