
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

int randomBright01 = 50;
int randomBright02 = 90;
int randomBright03 = 155;
int randomBright04 = 255;

int MaxBrightReductionQuad1;
int MaxBrightReductionQuad2;
int MaxBrightReductionQuad3;
int MaxBrightReductionQuad4;

int InnerBrightReductionQuad1;
int InnerBrightReductionQuad2;
int InnerBrightReductionQuad3;
int InnerBrightReductionQuad4;

int randomOnce = 0;

/* rainbow2 */
uint32_t colorone= 0xFF007F;
uint32_t colortwo= 0x6200FF;
uint32_t colorthree= 0xBEFF00;
uint32_t colorfour= 0x00FF34;
uint32_t colorfive= 0x0400FF;
uint32_t colorsix= 0x2600CA;

/**

  Brightness Blink 6

*/

void RainbowQuad(){


            //maxBrightness = map(analogRead(A1), 0, 1024, 0, maxBrightnessTemp);
            
            MaxBrightReduction = constrain(maxBrightness, 0, MaxBright);
            pixel.setBrightness(maxBrightness);
            strip.setBrightness(MaxBrightReduction);
            FastLED.setBrightness(MaxBrightReduction);
            inner.setBrightness(maxBrightness);
            showLEDS();

            Serial.println("maxBrightness : " + String(maxBrightness));
            Serial.println("MaxBright : " + String(MaxBright));
            Serial.println("MaxBrightReduction : " + String(MaxBrightReduction));

            
    if (Mode == 1) {
      randomBright01 = 50;
      randomBright02 = 90;
      randomBright03 = 155;
      randomBright04 = 255;

      InnerBrightReductionQuad1 = map(randomBright01, 0, 255, 0, 190);
      InnerBrightReductionQuad2 = map(randomBright02, 0, 255, 0, 190);
      InnerBrightReductionQuad3 = map(randomBright03, 0, 255, 0, 190);
      InnerBrightReductionQuad4 = map(randomBright04, 0, 255, 0, 190);

      MaxBrightReductionQuad1 = map(randomBright01, 0, 255, 0, MaxBright);
      MaxBrightReductionQuad2 = map(randomBright02, 0, 255, 0, MaxBright);
      MaxBrightReductionQuad3 = map(randomBright03, 0, 255, 0, MaxBright);
      MaxBrightReductionQuad4 = map(randomBright04, 0, 255, 0, MaxBright);
    }
    else if (Mode == 2) {
      randomOnce = 0;
      setRandomBrightsOnce();

      InnerBrightReductionQuad1 = map(randomBright01, 0, 255, 0, 190);
      InnerBrightReductionQuad2 = map(randomBright02, 0, 255, 0, 190);
      InnerBrightReductionQuad3 = map(randomBright03, 0, 255, 0, 190);
      InnerBrightReductionQuad4 = map(randomBright04, 0, 255, 0, 190);
      
      MaxBrightReductionQuad1 = map(randomBright01, 0, 255, 0, MaxBright);
      MaxBrightReductionQuad2 = map(randomBright02, 0, 255, 0, MaxBright);
      MaxBrightReductionQuad3 = map(randomBright03, 0, 255, 0, MaxBright);
      MaxBrightReductionQuad4 = map(randomBright04, 0, 255, 0, MaxBright);
    }
    else if (Mode == 3) {
      // Un-comment 'setRandomBrights' in Loop to randomize Brightness values for the 4 values after each cycle
      setRandomBrights();

      InnerBrightReductionQuad1 = map(randomBright01, 0, 255, 0, 190);
      InnerBrightReductionQuad2 = map(randomBright02, 0, 255, 0, 190);
      InnerBrightReductionQuad3 = map(randomBright03, 0, 255, 0, 190);
      InnerBrightReductionQuad4 = map(randomBright04, 0, 255, 0, 190);
      
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
      Serial.println("InnerBrightReductionQuad 1 " + String(InnerBrightReductionQuad1));
      Serial.println("InnerBrightReductionQuad 2 " + String(InnerBrightReductionQuad2));
      Serial.println("InnerBrightReductionQuad 3 " + String(InnerBrightReductionQuad3));
      Serial.println("InnerBrightReductionQuad 4 " + String(InnerBrightReductionQuad4));
      Serial.println("--------");
      Serial.println("MaxBrightReductionQuad 1 " + String(MaxBrightReductionQuad1));
      Serial.println("MaxBrightReductionQuad 2 " + String(MaxBrightReductionQuad2));
      Serial.println("MaxBrightReductionQuad 3 " + String(MaxBrightReductionQuad3));
      Serial.println("MaxBrightReductionQuad 4 " + String(MaxBrightReductionQuad4));
      Serial.println("--------");
    
    // Set the color
     
    for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
         strip.setPixelColor(p, colorone);
      }
    pixel.setPixelColor(0, colorone); 
    inner.setPixelColor(0, colorone);
    showLEDS(); 
    Serial.println("colorone");
      
    // Do the brightness changes 4 times
    quadBrightness(); 
    showLEDS();  
    // Delay the change to the next color by the amount of A0
    delayA0(fadeSpeed);
    // Add an amount of darness by the amount of A2
    darkDelayBetwixtColors();
    
    pixel.setPixelColor(0, colortwo); 
    inner.setPixelColor(0, colortwo); 
    for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
         strip.setPixelColor(p, colortwo);
      }
    showLEDS();
    Serial.println("colortwo");

    quadBrightness(); 
    showLEDS(); 
    delayA0(fadeSpeed);
    darkDelayBetwixtColors();
    
    pixel.setPixelColor(0, colorthree); 
    inner.setPixelColor(0, colorthree); 
    for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
         strip.setPixelColor(p, colorthree);
         
    }
    showLEDS();
    Serial.println("colorthree");
    
    quadBrightness();  
    showLEDS(); 
    delayA0(fadeSpeed);
    darkDelayBetwixtColors();
    
    pixel.setPixelColor(0, colorfour); 
    inner.setPixelColor(0, colorfour); 
    for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
         strip.setPixelColor(p, colorfour);
      }
    showLEDS();
    Serial.println("colorfour");
      
    quadBrightness(); 
    showLEDS();  
    delayA0(fadeSpeed);
    darkDelayBetwixtColors();
    
    pixel.setPixelColor(0, colorfive); 
    inner.setPixelColor(0, colorfive); 
    for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
         strip.setPixelColor(p, colorfive);
      }
    showLEDS();
    Serial.println("colorfive");
    
    quadBrightness(); 
    showLEDS();  
    delayA0(fadeSpeed);
    darkDelayBetwixtColors();
    
    pixel.setPixelColor(0, colorsix); 
    inner.setPixelColor(0, colorsix); 
    for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
         strip.setPixelColor(p, colorsix);
      }
    showLEDS();
    Serial.println("colorsix");
    
    quadBrightness(); 
    showLEDS();  
    delayA0(fadeSpeed);

    
    
    // Delay by the amount of A2
    // delayA2(darkDelay);
    
    //darkDelayBetwixtColors();

    darkLEDSDelay();

}

void quadBrightness()
{
  // Set the brightness
  pixel.setBrightness(InnerBrightReductionQuad1);
  inner.setBrightness(InnerBrightReductionQuad1);
  //strip.setBrightness(randomBright01);
  //FastLED.setBrightness(randomBright01);
  strip.setBrightness(MaxBrightReductionQuad1);
  FastLED.setBrightness(MaxBrightReductionQuad1);
  showLEDS(); 
  // Delay the change to the next brightness by the amount of A1
  delayA1(fullDelay);

  //Serial.println("Full Delay 1: " + String(fullDelay));

  // Set the brightness
  pixel.setBrightness(InnerBrightReductionQuad2);
  inner.setBrightness(InnerBrightReductionQuad2);
  //strip.setBrightness(randomBright02);
  //FastLED.setBrightness(randomBright02);
  strip.setBrightness(MaxBrightReductionQuad2);
  FastLED.setBrightness(MaxBrightReductionQuad2);
  showLEDS(); 
  // Delay the change to the next brightness by the amount of A1
  delayA1(fullDelay);


    
  //Serial.println("Full Delay 2: " + String(fullDelay));

  // Set the brightness
  pixel.setBrightness(InnerBrightReductionQuad3);
  inner.setBrightness(InnerBrightReductionQuad3);
  //strip.setBrightness(randomBright03);
  //FastLED.setBrightness(randomBright03);
  strip.setBrightness(MaxBrightReductionQuad3);
  FastLED.setBrightness(MaxBrightReductionQuad3);
  showLEDS(); 
  // Delay the change to the next brightness by the amount of A1
  delayA1(fullDelay);
  

  
  //Serial.println("Full Delay 3: " + String(fullDelay));

  // Set the brightness
  pixel.setBrightness(InnerBrightReductionQuad4);
  inner.setBrightness(InnerBrightReductionQuad4);
  //strip.setBrightness(randomBright04);
  //FastLED.setBrightness(randomBright04);
  strip.setBrightness(MaxBrightReductionQuad4);
  FastLED.setBrightness(MaxBrightReductionQuad4);
  showLEDS(); 
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

void darkLEDS(){
    
    // Make the pixel dark
    
    strip.setBrightness(0);
    FastLED.setBrightness(0);
    pixel.setBrightness(0);
    inner.setBrightness(0);

    for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
         strip.setPixelColor(p, 0,0,0);
    }
    pixel.setPixelColor(0, 0,0,0); 
    inner.setPixelColor(0, 0,0,0); 
    showLEDS(); 

    //delayA2(darkDelay);
    Serial.println("dark");
    
}

void darkLEDSDelay(){
    
    darkDelay = map(analogRead(A2), 0, 1024, 0, durationMaximum);
    Serial.println("darkDelay " + String(darkDelay));

    if (darkDelay > 30) {
      
        // Make the pixel dark
        
        strip.setBrightness(0);
        FastLED.setBrightness(0);
        pixel.setBrightness(0);
        inner.setBrightness(0);
    
        for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
             strip.setPixelColor(p, 0,0,0);
        }
        pixel.setPixelColor(0, 0,0,0); 
        inner.setPixelColor(0, 0,0,0); 
        showLEDS(); 

    }  
      
    delayA2(darkDelay);
    Serial.println("dark");
    
}


void darkDelayBetwixtColors(){
  
    // Make the pixel dark 
    /*FastLED.setBrightness(0);
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
    //delayA2(darkDelay);

}
