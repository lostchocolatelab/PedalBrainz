//  Mode 7 | Rainbow Squarez
//  A0 = Cycle Speed
//  A1 = Brightness
//  A2 =  Duration of Darkness after full Color Cycle
//
//  Mode 8 | Rainbow Squarez Ramping
//  A0 = Cycle Speed
//  A1 = Amount of Randomness
//  A2 =  Duration of Darkness after full Color Cycle
//
//  Mode 9 | Rainbow Squarez Random
//  A0 = Cycle Speed
//  A1 = Amount of Randomness
//  A2 =  Duration of Darkness after full Color Cycle

void brightnessA1(){
    
    checkButtons();

    //valueA1 = map(analogRead(A1), 0, 1024, 0, 20);
    //pixel.setBrightness(valueA1);  
    //inner.setBrightness(valueA1);  
    
    //brightness = map(analogRead(A1), 0, 1024, 0, 255);
    //MaxBrightReduction = map(brightness, 0, 255, 0, MaxBright);
    //FastLED.setBrightness(MaxBrightReduction); 
 
    //A1 potentiometer controls for maximum brightness
    maxBrightness = map(analogRead(A1), 0, 1024, 0, maxBrightnessTemp);
    MaxBrightReduction = constrain(maxBrightness, 0, MaxBright);
    pixel.setBrightness(maxBrightness);
    strip.setBrightness(MaxBrightReduction);
    FastLED.setBrightness(MaxBrightReduction);
    inner.setBrightness(maxBrightness);
    showLEDS();

    Serial.println("maxBrightnessTemp " + String(maxBrightnessTemp));
    Serial.println("MaxBright " + String(MaxBright));
    Serial.println("maxBrightness " + String(maxBrightness));
    Serial.println("MaxBrightnessReduction " + String(MaxBrightReduction));
    
}

void RainbowSquarez(){

    //Serial.println("RainbowSquarez " + String(fadeSpeed));
    
    checkButtons();

    ModulateControl();

    // Set the color
    for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                  strip.setPixelColor(p, colorRed);
    }
    pixel.setPixelColor(0, colorRed); 
    inner.setPixelColor(0, colorRed);
    brightnessA1(); 
    showLEDS();
  
    // Delay the change to the next color by the amount of A0
    delayA0(fadeSpeed);
    // Add an amount of darness by the amount of A2
    //darkDelayBetwixtColors();

    ModulateControl();

    for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                  strip.setPixelColor(p, colorOrange);
    }
    pixel.setPixelColor(0, colorOrange); 
    inner.setPixelColor(0, colorOrange); 
    brightnessA1();
    showLEDS();
    
    delayA0(fadeSpeed);
    //darkDelayBetwixtColors();

    ModulateControl();

    for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                  strip.setPixelColor(p, colorYellow);
    }
    pixel.setPixelColor(0, colorYellow); 
    inner.setPixelColor(0, colorYellow); 
    brightnessA1();
    showLEDS();
    
    delayA0(fadeSpeed);
    //darkDelayBetwixtColors();

    ModulateControl();

    for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                  strip.setPixelColor(p, colorGreen);
    }
    pixel.setPixelColor(0, colorGreen); 
    inner.setPixelColor(0, colorGreen); 
    brightnessA1();
    showLEDS();
    
    delayA0(fadeSpeed);
    //darkDelayBetwixtColors();

    ModulateControl();

    for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                  strip.setPixelColor(p, colorBlue);
    }
    pixel.setPixelColor(0, colorBlue); 
    inner.setPixelColor(0, colorBlue); 
    brightnessA1();
    showLEDS();
    
    delayA0(fadeSpeed);
    //darkDelayBetwixtColors();
    
    ModulateControl();

    for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                  strip.setPixelColor(p, colorPurple);
    }
    pixel.setPixelColor(0, colorPurple); 
    inner.setPixelColor(0, colorPurple); 
    brightnessA1();
    showLEDS(); 
    
    delayA0(fadeSpeed);
    //darkDelayBetwixtColors();

    ModulateControl();

    for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                  strip.setPixelColor(p, colorBlue);
    }
    pixel.setPixelColor(0, colorBlue); 
    inner.setPixelColor(0, colorBlue); 
    brightnessA1();
    showLEDS();
  
    delayA0(fadeSpeed);
    //darkDelayBetwixtColors();
    
    ModulateControl();

    for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                  strip.setPixelColor(p, colorGreen);
    }
    pixel.setPixelColor(0, colorGreen); 
    inner.setPixelColor(0, colorGreen); 
    brightnessA1();
    showLEDS();

    delayA0(fadeSpeed);

    ModulateControl();

    for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                  strip.setPixelColor(p, colorYellow);
    }
    pixel.setPixelColor(0, colorYellow); 
    inner.setPixelColor(0, colorYellow); 
    brightnessA1();
    showLEDS();
    
    delayA0(fadeSpeed);
    //darkDelayBetwixtColors();

    ModulateControl();

    for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                  strip.setPixelColor(p, colorOrange);
    }
    pixel.setPixelColor(0, colorOrange); 
    inner.setPixelColor(0, colorOrange);
    brightnessA1();
    showLEDS(); 
    
    delayA0(fadeSpeed);
    //darkDelayBetwixtColors();

    darkDelay = map(analogRead(A2), 0, 1024, 0, durationMaximum);
    Serial.println("darkDelay " + String(darkDelay));

    if (darkDelay > 30) {
      // Make the pixel dark

      //FastLED.setBrightness(0);
      strip.show(); 
      for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
           strip.setPixelColor(p, 0,0,0);
           strip.setBrightness(0);
      }
      pixel.setPixelColor(0, 0,0,0); 
      pixel.setBrightness(0);
      inner.setPixelColor(0, 0,0,0); 
      inner.setBrightness(0);
      showLEDS();
      

    // Delay by the amount of A2
    delayA2(darkDelay);
    //Serial.println("darkDelay " + String(darkDelay));

    }
    
    //darkDelayBetwixtColors();
    
 
  //pixel.show(); 
  

}



void changeValue() {
     
     checkButtons();

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

      checkButtons();

      if (modulateSpeed < 1){
        increaseValue = true;
        
      }
      if (modulateSpeed > 2000){
        increaseValue = false;

     }
  
}

void ModulateControl() {

      checkButtons();

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
