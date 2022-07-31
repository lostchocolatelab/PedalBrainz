

void showLEDS(){

  //FastLED.show();
  strip.show();
  pixel.show();
  inner.show();
  
}

void maxBrightnessSet(){

  MaxBrightReduction = constrain(maxBrightness, 0, MaxBright);
  pixel.setBrightness(maxBrightness);
  strip.setBrightness(MaxBrightReduction);
  inner.setBrightness(maxBrightness);
  FastLED.setBrightness(MaxBrightReduction);
  showLEDS();

  //Serial.println("maxBrightness : " + String(maxBrightness));
  //Serial.println("MaxBright : " + String(MaxBright));
  //Serial.println("MaxBrightReduction : " + String(MaxBrightReduction));
}

void maxBrightnessAdjust()
{
  //A1 potentiometer controls for maximum brightness
  maxBrightness = map(analogRead(A1), 0, 1024, 0, maxBrightnessTemp);
  MaxBrightReduction = constrain(maxBrightness, 0, MaxBright);
  pixel.setBrightness(maxBrightness);
  strip.setBrightness(MaxBrightReduction);
  inner.setBrightness(maxBrightness);
  FastLED.setBrightness(MaxBrightReduction);

  //Serial.println("maxBrightness : " + String(maxBrightness));
  //Serial.println("MaxBright : " + String(MaxBright));
  //Serial.println("MaxBrightReduction : " + String(MaxBrightReduction));
}

void darkLEDS() 
{

    checkButtons();

    // Make the pixel dark

    strip.setBrightness(0);
    FastLED.setBrightness(0);
    pixel.setBrightness(0);
    inner.setBrightness(0);

    for (int p = 0; p < strip.numPixels(); p++) {       // For each pixel in strip...
        strip.setPixelColor(p, 0, 0, 0);
    }
    pixel.setPixelColor(0, 0, 0, 0);
    inner.setPixelColor(0, 0, 0, 0);
    showLEDS();

    //delayA2(darkDelay);
    //Serial.println("dark dark dark dark dark dark dark dark ");

}

void darkLEDSDelay() 
{

    checkButtons();

    //darkDelay = map(analogRead(A2), 0, 1024, 0, durationMaximum);
    //Serial.println("darkDelay " + String(darkDelay));

    if (darkDelay > 5) {

      // Make the pixel dark

        strip.setBrightness(0);
        FastLED.setBrightness(0);
        pixel.setBrightness(0);
        inner.setBrightness(0);

        for (int p = 0; p < strip.numPixels(); p++) {       // For each pixel in strip...
            strip.setPixelColor(p, 0, 0, 0);
        }
        pixel.setPixelColor(0, 0, 0, 0);
        inner.setPixelColor(0, 0, 0, 0);
        showLEDS();

    }
    

    delayA2(darkDelay);
    //Serial.println("dark dark dark dark dark dark dark dark ");

}

void averageLEDS(){

  avgLight0 = leds[0].getAverageLight();
  avgLight1 = leds[1].getAverageLight();
  avgLight2 = leds[2].getAverageLight();
  avgLight = avgLight0+avgLight1+avgLight2;
  avgLightInner = map(avgLight, 0, 255, 0, 190);

  //avgLight = avgLight1;

  //Serial.println("Average : " + String(avgLight));

  scalePixelInner(avgLightInner);
  pixel.setPixelColor(0, innerValue,0,0); 
  inner.setPixelColor(0, innerValue,0,0);  

  showLEDS();
}

void averageLEDSBrightness(){

  avgLight0 = leds[0].getAverageLight();
  avgLight1 = leds[1].getAverageLight();
  avgLight2 = leds[2].getAverageLight();
  avgLight = avgLight0+avgLight1+avgLight2;

  mapScaledBright(avgLight);

  avgLightInner = mapfloat(scaledBright, 0, 190, 0, 190);

  scalePixelInner(avgLightInner);

  //Serial.println("Average : " + String(avgLight));
  pixel.setBrightness(avgLightInner);
  inner.setBrightness(avgLightInner);

  
  pixel.setPixelColor(0, innerValue,0,0); 
  inner.setPixelColor(0, innerValue,0,0);  

  showLEDS();
}

void averageLEDSBrightnessPalette(){

  mapScaledBrightPalette(startIndex);

  avgLightInner = mapfloat(scaledBright, 0, 190.0, -5, 600.0);

  scalePixelInner(avgLightInner);
  
  //Serial.println("Average : " + String(avgLight));
  pixel.setBrightness(avgLightInner);
  inner.setBrightness(avgLightInner);

  
  pixel.setPixelColor(0, innerValue,0,0); 
  inner.setPixelColor(0, innerValue,0,0);  

  //showLEDS();
}



void averageLEDSPlot(){

  avgLight0 = leds[0].getAverageLight();
  avgLight1 = leds[1].getAverageLight();
  avgLight2 = leds[2].getAverageLight();
  avgLight = avgLight0+avgLight1+avgLight2;

  mapScaledBright(avgLight);

  avgLightInner = mapfloat(scaledBright, 0, 190, 0, 190);

  scalePixelInner(avgLightInner);
}

void pixelScaling()
{
  
  // updateScaling(0, 0, 1, 0, x);
  // updateScaling(0, 1, 1, 1, y);
  // updateScaling(0, 2, 1, 2, z);

  // //Values are scaled to 0-255 to adapt to the analogWrite function

  // scaledX = mapfloat(x, scalings[0][0], scalings[1][0], 0, 255);
  // scaledY = mapfloat(y, scalings[0][1], scalings[1][1], 0, 255);
  // scaledZ = mapfloat(z, scalings[0][2], scalings[1][2], 0, 255);

  // scaledX = x;
  // scaledY = y;
  // scaledZ = z;

  // scaledX = mapfloat(x, -10, 10, 0, 255);
  // scaledY = mapfloat(y, -10, 10, 0, 255);
  // scaledZ = mapfloat(z, -10, 10, 0, 255);

  // scaledXInner = scaledX;
  // scaledYInner = scaledY;
  // scaledZInner = scaledZ;    

  attractorzIndicatorValue = mapfloat(analogRead(A2), 0, 1024, 0, 300);

  if (attractorzLEDType == 1)
  {
    // scaledXInner = mapfloat(scaledX, 0, 255, -50, 230);
    // scaledYInner = mapfloat(scaledY, 0, 255, -50, 230);
    // scaledZInner = mapfloat(scaledZ, 0, 255, -50, 230);  
    scaledXInner = mapfloat(scaledX, 0, 255, 0, 190);
    scaledYInner = mapfloat(scaledY, 0, 255, 0, 190);
    scaledZInner = mapfloat(scaledZ, 0, 255, 0, 190); 
    // scaledXInner = scaledX;
    // scaledYInner = scaledY;
    // scaledZInner = scaledZ;   
    scaledInnerCombined = (scaledXInner+scaledYInner+scaledZInner)/3; 
    scaledInnerCombined = constrain(scaledInnerCombined, 0, scaledInnerCombined);
  }  
  else if (attractorzLEDType == 2)
  {
    // scaledXInner = mapfloat(scaledX, 0, 255, -30, 220);
    // scaledYInner = mapfloat(scaledY, 0, 255, -30, 220);
    // scaledZInner = mapfloat(scaledZ, 0, 255, -30, 220); 
    scaledXInner = mapfloat(scaledX, 0, 255, 0, 190);
    scaledYInner = mapfloat(scaledY, 0, 255, 0, 190);
    scaledZInner = mapfloat(scaledZ, 0, 255, 0, 190); 
    // scaledXInner = scaledX;
    // scaledYInner = scaledY;
    // scaledZInner = scaledZ;  
    scaledInnerCombined = (scaledXInner+scaledYInner)/2;  
    scaledInnerCombined = constrain(scaledInnerCombined, 0, scaledInnerCombined);
  }
  else if (attractorzLEDType == 3)
  {
    // scaledXInner = mapfloat(scaledX, 0, 255, -10, 200);
    // scaledYInner = mapfloat(scaledY, 0, 255, -10, 200);
    // scaledZInner = mapfloat(scaledZ, 0, 255, -10, 200);
    scaledXInner = mapfloat(scaledX, 0, 255, 0, 190);
    scaledYInner = mapfloat(scaledY, 0, 255, 0, 190);
    scaledZInner = mapfloat(scaledZ, 0, 255, 0, 190); 
    // scaledXInner = scaledX;
    // scaledYInner = scaledY;
    // scaledZInner = scaledZ;  
    scaledInnerCombined = scaledXInner;  
    scaledInnerCombined = constrain(scaledInnerCombined, 0, scaledInnerCombined);
  } 
  else; 

}

void mapScaledBrightPalette (int val){

      //controlAmount = map(analogRead(A0), 0, 1024, 0, 100);
      //valueLog = log(analogRead(A0)+1)/log(1024)*255;
      //Serial.println("Mode 1 valueLog: " + String(valueLog));
      //fadeSpeed = map(valueLog, 0, 255, (speedMinimum), (40/2)); // Logarithmic Potentiometer Value
      //fadeSpeed = map(valueLog, 0, 255, (speedMinimum/2), (40/2)); // Logarithmic Potentiometer Value

      // This makes the potentiometer slower to change when reducting from full and gives better control fidelity at higher speeds
      // This is a map of values for the potentiometer. note: the in array should have increasing values
      int in[]  = {0, 25,51,76,102,127,153,178,204,229,255};
      // This is a map of values for potentiometer curve type.
      int out[] = {5, 7, 9,  11,  15,  20,  32,  48,  70,  100,  255 };  // 11
      //int out[] = {10, 55, 90,  100,  110,  120,  130,  140,  150,  160,  255 };  // 11
      // This maps the potentiometer scale.
      controlAmount  = val;
      // This is a multimap that assigns values from the [in] array (potentiometer) to values from the [out] array (curve)
      x = multiMap(controlAmount, in, out, 11);
      // This maps the values for the Modez.
      scaledBright = mapfloat(x, 0, 255.0, 0, 255.0);
      //scaledBright = constrain(x, 0.0, 255.0);

      //int redValue = 236;
      //int blueValue = 73;
      //int greenValue = 107;
      
}

void mapScaledBright (int val){

      //controlAmount = map(analogRead(A0), 0, 1024, 0, 100);
      //valueLog = log(analogRead(A0)+1)/log(1024)*255;
      //Serial.println("Mode 1 valueLog: " + String(valueLog));
      //fadeSpeed = map(valueLog, 0, 255, (speedMinimum), (40/2)); // Logarithmic Potentiometer Value
      //fadeSpeed = map(valueLog, 0, 255, (speedMinimum/2), (40/2)); // Logarithmic Potentiometer Value

      // This makes the potentiometer slower to change when reducting from full and gives better control fidelity at higher speeds
      // This is a map of values for the potentiometer. note: the in array should have increasing values
      int in[]  = {0, 25,51,76,102,127,153,178,204,229,255};
      // This is a map of values for potentiometer curve type.
      //int out[] = {0, 5, 10,  15,  20,  25,  30,  35,  50,  80,  255 };  // 11
      int out[] = {0, 5, 10,  15,  20,  25,  30,  35,  50,  80,  255 };  // 11
      // This maps the potentiometer scale.
      controlAmount  = val;
      // This is a multimap that assigns values from the [in] array (potentiometer) to values from the [out] array (curve)
      x = multiMap(controlAmount, in, out, 11);
      // This maps the values for the Modez.
      scaledBright = mapfloat(x, 0, 255.0, 0, 255.0);
      //scaledBright = constrain(x, 0.0, 255.0);

      //int redValue = 236;
      //int blueValue = 73;
      //int greenValue = 107;
      
}