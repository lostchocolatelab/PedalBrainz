
//  Rainbow Quadz
//  Cycles through 6 colors. The Brightness of each color is modulated 4 times. Default brightness set in declarations.
//  Modez 1 - Uses randomBright01-04 Declared in General Declarations
//  Modez 2 - Randomize Brightness values for the 4 values once at startup
//  Modez 3 - Randomize Brightness values for the 4 values after each cycle
//
//  Set Color -> Set 4 Brightness Values w/ Delay (A1) -> Delay before setting next Color (A0)
//  
//  A0 = Duration of 4th brightness after brightness changes for a single color
//  A1 = Delay of each Brightness Value (4) for a Single Color
//  A2 = Duration of Darkness after full Color Cycle (or betwixt each color if darkDelayBetwixtColors is enabled)

int randomBright01 = 20;
int randomBright02 = 60;
int randomBright03 = 110;
int randomBright04 = 170;

int randomOnce = 0;

/**

  Brightness Blink 6

*/

void RainbowQuad(){

    if (Mode == 1) {
      randomBright01 = 20;
      randomBright02 = 60;
      randomBright03 = 110;
      randomBright04 = 170;

      
      MaxBrightReductionQuad1 = map(randomBright01, 0, 255, 0, MaxBright);
      MaxBrightReductionQuad2 = map(randomBright02, 0, 255, 0, MaxBright);
      MaxBrightReductionQuad3 = map(randomBright03, 0, 255, 0, MaxBright);
      MaxBrightReductionQuad4 = map(randomBright04, 0, 255, 0, MaxBright);
    }
    else if (Mode == 2) {
      randomOnce = 0;
      setRandomBrightsOnce();
      
      MaxBrightReductionQuad1 = map(randomBright01, 0, 255, 0, MaxBright);
      MaxBrightReductionQuad2 = map(randomBright02, 0, 255, 0, MaxBright);
      MaxBrightReductionQuad3 = map(randomBright03, 0, 255, 0, MaxBright);
      MaxBrightReductionQuad4 = map(randomBright04, 0, 255, 0, MaxBright);
    }
    else if (Mode == 3) {
      // Un-comment 'setRandomBrights' in Loop to randomize Brightness values for the 4 values after each cycle
      setRandomBrights();
      
      MaxBrightReductionQuad1 = map(randomBright01, 0, 255, 0, MaxBright);
      MaxBrightReductionQuad2 = map(randomBright02, 0, 255, 0, MaxBright);
      MaxBrightReductionQuad3 = map(randomBright03, 0, 255, 0, MaxBright);
      MaxBrightReductionQuad4 = map(randomBright04, 0, 255, 0, MaxBright);
    }
    else;

    
      Serial.println("Static Bright 1 " + String(randomBright01));
      Serial.println("Static Bright 2 " + String(randomBright02));
      Serial.println("Static Bright 3 " + String(randomBright03));
      Serial.println("Static Bright 4 " + String(randomBright04));
      Serial.println("--------");
      Serial.println("MaxBrightReductionQuad 1 " + String(MaxBrightReductionQuad1));
      Serial.println("MaxBrightReductionQuad 2 " + String(MaxBrightReductionQuad2));
      Serial.println("MaxBrightReductionQuad 3 " + String(MaxBrightReductionQuad3));
      Serial.println("MaxBrightReductionQuad 4 " + String(MaxBrightReductionQuad4));
      Serial.println("--------");
    
    // Set the color
    pixel.setPixelColor(0, colorone); 
    pixel.show(); 

    inner.setPixelColor(0, colorone); 
    inner.show(); 

    for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
         strip.setPixelColor(p, colorone);
      }
    strip.show(); 
      
    // Do the brightness changes 4 times
    quadBrightness();  
    // Delay the change to the next color by the amount of A0
    delayA0(fadeSpeed);
    // Add an amount of darness by the amount of A2
    darkDelayBetwixtColors();
    
    pixel.setPixelColor(0, colortwo); 
    pixel.show();
    inner.setPixelColor(0, colortwo); 
    inner.show();
    for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
         strip.setPixelColor(p, colortwo);
      }
    strip.show(); 
    quadBrightness();  
    delayA0(fadeSpeed);
    darkDelayBetwixtColors();
    
    pixel.setPixelColor(0, colorthree); 
    pixel.show();  
    inner.setPixelColor(0, colorthree); 
    inner.show();  
    for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
         strip.setPixelColor(p, colorthree);
      }
    strip.show(); 
    quadBrightness();  
    delayA0(fadeSpeed);
    darkDelayBetwixtColors();
    
    pixel.setPixelColor(0, colorfour); 
    pixel.show();
    inner.setPixelColor(0, colorfour); 
    inner.show();
    for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
         strip.setPixelColor(p, colorfour);
      }
    strip.show();   
    quadBrightness();  
    delayA0(fadeSpeed);
    darkDelayBetwixtColors();
    
    pixel.setPixelColor(0, colorfive); 
    pixel.show();
    inner.setPixelColor(0, colorfive); 
    inner.show();
    for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
         strip.setPixelColor(p, colorfive);
      }
    strip.show(); 
    quadBrightness();  
    delayA0(fadeSpeed);
    darkDelayBetwixtColors();
    
    pixel.setPixelColor(0, colorsix); 
    pixel.show(); 
    inner.setPixelColor(0, colorsix); 
    inner.show();  
    for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
         strip.setPixelColor(p, colorsix);
      }
    strip.show(); 
    quadBrightness();  
    delayA0(fadeSpeed);
    

    // Make the pixel dark
    
    strip.setBrightness(0);
    strip.show(); 
    for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
         strip.setPixelColor(p, 0,0,0);
    }
    pixel.setPixelColor(0, 0,0,0); 
    pixel.setBrightness(0);
    pixel.show();
    
    inner.setPixelColor(0, 0,0,0); 
    inner.setBrightness(0);
    inner.show();
       

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
  inner.setBrightness(randomBright01);
  inner.show(); 
  strip.setBrightness(MaxBrightReductionQuad1);
  strip.show(); 
  // Delay the change to the next brightness by the amount of A1
  delayA1(fullDelay);

 
  //Serial.println("Full Delay 1: " + String(fullDelay));

  // Set the brightness
  pixel.setBrightness(randomBright02);
  pixel.show();
  inner.setBrightness(randomBright02);
  inner.show();
  strip.setBrightness(MaxBrightReductionQuad2);
  strip.show(); 
  // Delay the change to the next brightness by the amount of A1
  delayA1(fullDelay);


    
  //Serial.println("Full Delay 2: " + String(fullDelay));

  // Set the brightness
  pixel.setBrightness(randomBright03);
  pixel.show(); 
  inner.setBrightness(randomBright03);
  inner.show(); 
  strip.setBrightness(MaxBrightReductionQuad3);
  strip.show(); 
  // Delay the change to the next brightness by the amount of A1
  delayA1(fullDelay);
  

  
  //Serial.println("Full Delay 3: " + String(fullDelay));

  // Set the brightness
  pixel.setBrightness(randomBright04);
  pixel.show(); 
  inner.setBrightness(randomBright04);
  inner.show(); 
  strip.setBrightness(MaxBrightReductionQuad4);
  strip.show(); 
  // Delay the change to the next brightness by the amount of A1
  delayA1(fullDelay);
  
  if (Mode == 3) {
      // Un-comment 'setRandomBrights' in Loop to randomize Brightness values for the 4 values after each cycle
      setRandomBrights();
    }
  else;
  
  //Serial.println("Full Delay 4: " + String(fullDelay));

}

void setRandomBrights() {

      randomBright01  = random(10, 255);
      randomBright02  = random(10, 255);
      randomBright03  = random(10, 255);
      randomBright04  = random(10, 255);

 
}

void setRandomBrightsOnce() {
  if (randomOnce == 0) {
    
      randomBright01  = random(10, 255);
      randomBright02  = random(10, 255);
      randomBright03  = random(10, 255);
      randomBright04  = random(10, 255);

      randomOnce = 1;
     
  }

  
}

void darkDelayBetwixtColors(){
  
    // Make the pixel dark 
    /*strip.setBrightness(0);
    for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
         strip.setPixelColor(p, 0,0,0);
    }
    strip.show(); 
    
    pixel.setPixelColor(0, 0,0,0); 
    pixel.setBrightness(0);
    pixel.show();  
    
    inner.setPixelColor(0, 0,0,0); 
    inner.setBrightness(0);
    inner.show();*/   

    // Delay by the amount of A2 - Remove the following comment to turn the led off between each color 
    delayA2(darkDelay);

}
