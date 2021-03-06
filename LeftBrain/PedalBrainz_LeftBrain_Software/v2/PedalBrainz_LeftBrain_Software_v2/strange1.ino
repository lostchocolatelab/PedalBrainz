/**

  STRANGE ATTRACTORS 1

  Attractorz Maths implemented in code by Timothy Franceschi

*/


  //
  //  This Section is the Strange Attractor loop
  //

void strangeAttractor()
{

  //controlsMax();
  checkButtons();

  //Don't execute the code if not enough time has elapsed
  if (millis() > nextAttractorzUpdate) {


    lorenzFunction();
    nextAttractorzUpdate = millis() + (printDelay);

    brightenColors();
    checkButtons();

    //A2 potentiometer controls for amount of randomless from less to more random
    b = map(analogRead(A2), 0, 1024, 20, 50);

    strangeBright();
    //strangeBrightMinDark();
    checkButtons();

    showLEDS();

    //A0 potentiometer controls for fade speed
    delayA0(fadeSpeed);

    checkButtons();

    // Slow down the simulation when the value is low

    //strangeSlow();
    strangeSlow2();
    checkButtons();

    plotCycle();
    checkButtons();

  }

}


void strangeBright() {

  //A1 potentiometer controls for maximum brightness
  maxBrightnessAdjust();

  showLEDS();

  //Serial.println("maxBrightness : " + String(maxBrightness));
  //Serial.println("MaxBright : " + String(MaxBright));
  //Serial.println("MaxBrightReduction : " + String(MaxBrightReduction));



  //Modes
  /* Set a value for each potentiometer (pin) for colors R,G,B. */

  if (Mode == 8)
  {
    for (int p = 0; p < strip.numPixels(); p++) {   // For each pixel in strip...
      strip.setPixelColor(p, (scaledX / 2), 0, (scaledX / 4));

    }
    pixel.setPixelColor(0, (scaledXInner / 4), 0, (scaledXInner / 8));   //Single Output Scaled X
    inner.setPixelColor(0, (scaledXInner / 4), 0, (scaledXInner / 8));   //Single Output Scaled X
    //pixel.setPixelColor(0, x, 0, 30);   //Single Output Scaled X
    showLEDS();
  }
  if (Mode == 9)
  {
    for (int p = 0; p < strip.numPixels(); p++) {   // For each pixel in strip...
      strip.setPixelColor(p, (scaledX / 2), 0, (scaledZ / 2));

    }
    pixel.setPixelColor(0, (scaledXInner / 4), 0, (scaledZInner / 4));   //Double Output Scaled X & Z
    inner.setPixelColor(0, (scaledXInner / 4), 0, (scaledZInner / 4));   //Double Output Scaled X & Z
    //pixel.setPixelColor(0, x, 0, z+100);   //Double Output Scaled X & Z
    showLEDS();
  }
  if (Mode == 10)
  {
    for (int p = 0; p < strip.numPixels(); p++) {   // For each pixel in strip...
      strip.setPixelColor(p, (scaledX), (scaledY / 3), (scaledZ));

    }
    pixel.setPixelColor(0, (scaledXInner / 2), (scaledYInner / 6), (scaledZInner / 2));   //Triple Output Scaled XYZ
    inner.setPixelColor(0, (scaledXInner / 2), (scaledYInner / 6), (scaledZInner / 2));   //Triple Output Scaled XYZ
    showLEDS();
  }
  
  // Print some stuff
  //Serial.println("scaledx: " + String(scaledX) + " scaledY : " + String(scaledY) + " scaledz : " + String(scaledZ));
  
  if (plotterPrint == true)
  {
    Serial.println("," + String(scaledX) + "," + String(scaledY) + "," + String(scaledZ));
  }
  else;

}


void strangeBrightMinDark() {

  if ((scaledY >= 0) && (scaledY <= 50)) {
    
    pixel.setBrightness(maxBrightness - 255);
    strip.setBrightness(maxBrightness);
    FastLED.setBrightness(maxBrightness);
    inner.setBrightness(maxBrightness - 255);

    for (int p = 0; p < strip.numPixels(); p++) {   // For each pixel in strip...
      strip.setPixelColor(p, 0, 0, 0);

    }
    pixel.setPixelColor(0, 0, 0, 0);
    inner.setPixelColor(1, 0, 0, 0);
    showLEDS();
  }
  else if ((scaledY >= 51) && (scaledY <= 255))
  {
    //A1 potentiometer controls for maximum brightness
    maxBrightnessAdjust();
    showLEDS();
    //Serial.println(maxBrightness);

    //Modes
    /* Set a value for each potentiometer (pin) for colors R,G,B. */

    if (Mode == 8)
    {
      maxBrightnessAdjust();

      for (int p = 0; p < strip.numPixels(); p++) {   // For each pixel in strip...
        strip.setPixelColor(p, (scaledX / 2), 0, (scaledX / 4));
      }
      pixel.setPixelColor(0, (scaledXInner / 4), 0, (scaledXInner / 8));   //Single Output Scaled X
      inner.setPixelColor(0, (scaledXInner / 4), 0, (scaledXInner / 8));   //Single Output Scaled X
      //pixel.setPixelColor(0, x, 0, 30);   //Single Output Scaled X
      showLEDS();
    }
    if (Mode == 9)
    {
      maxBrightnessAdjust();

      for (int p = 0; p < strip.numPixels(); p++) {   // For each pixel in strip...
        strip.setPixelColor(p, (scaledX / 2), 0, (scaledZ / 2));

      }
      pixel.setPixelColor(0, (scaledXInner / 4), 0, (scaledZInner / 4));   //Double Output Scaled X & Z
      inner.setPixelColor(0, (scaledXInner / 4), 0, (scaledZInner / 4));   //Double Output Scaled X & Z
      //pixel.setPixelColor(0, x, 0, z+100);   //Double Output Scaled X & Z
      showLEDS();
    }
    if (Mode == 10)
    {
      maxBrightnessAdjust();

      for (int p = 0; p < strip.numPixels(); p++) {   // For each pixel in strip...
        strip.setPixelColor(p, (scaledX), (scaledY / 3), (scaledZ));

      }
      pixel.setPixelColor(0, (scaledXInner / 2), (scaledYInner / 6), (scaledZInner / 2));   //Triple Output Scaled XYZ
      inner.setPixelColor(0, (scaledXInner / 2), (scaledYInner / 6), (scaledZInner / 2));   //Triple Output Scaled XYZ
      showLEDS();
    }
  }
}

/**

STRANGE ATTRACTORS Slow down

These functions slow down the simulation when values are low (effectivly keeping the LED dark longer)

*/

void strangeSlow() {

  // Slow down the simulation when the value is low
  if ((scaledY >= 0) && (scaledY <= 50)) {

    strangeRandom = random(20, 200);
    strangeSlowAmount = (strangeRandom + (delayAmount * 2));
    //slowDelay = strangeSlowAmount;
    //delaySomething(slowDelay);
  }


    //Serial.println("Count if Waiting = False: " + String(count));
}


void strangeSlow2() {

  maxBrightnessAdjust();

  if ((strangeSlowCount >= 0) && (strangeSlowCount <= 10)) {
       strangeSlowCount = strangeSlowCount + 1;
  }
  else 
  {
    // Slow down the simulation when the value is low
  if ((scaledY >= 0) && (scaledY <= 5)) {
      valueA0 = map(analogRead(A0), 0, 1024, 1000, 0);
      strangeRandom = random(20, 200);
      strangeSlowAmount = (strangeRandom + valueA0);
      darkDelay = strangeSlowAmount;
    
      checkButtons();
      delayA2(darkDelay);

      maxBrightnessAdjust();
      showLEDS();
      
      //Serial.println("strangeSlow: " + String(darkDelay) + " strangeSlowAmount : " + String(strangeSlowAmount));
      //Serial.println("scaledY: " + String(scaledY) + " darkDelay : " + String(darkDelay) + " strangeSlowCount : " + String(strangeSlowCount));
    
    }
  }
}

void strangeSlow3() {

  checkButtons();
  pixelScaling();
  attractorzIndicator();

  if ((strangeSlowCount >= 0) && (strangeSlowCount <= 20)) {
    strangeSlowCount = strangeSlowCount + 1;
  }
  else {
    // Slow down the simulation when the value is low
    if ((scaledInnerCombined >= 0) && (scaledInnerCombined <= 50))  {
      valueA0 = map(analogRead(A0), 0, 1024, 1000, 0);
      strangeRandom = random(20, 200);
      strangeSlowAmount = (strangeRandom + valueA0);
      darkDelay = strangeSlowAmount;
      //darkDelay = strangeSlowAmount;
      checkButtons();
      delayA2(darkDelay);

      maxBrightnessAdjust();
      showLEDS();
      
      //Serial.println("strangeSlow: " + String(darkDelay) + " strangeSlowAmount : " + String(strangeSlowAmount));
      //Serial.println(", " + String(darkDelay) + " , " + String(strangeSlowAmount));
      //Serial.println("scaledY: " + String(scaledY) + " darkDelay : " + String(darkDelay) + " strangeSlowCount : " + String(strangeSlowCount));
    
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

  dx = (la * (ly - lx)) * dt;
  dy = (lx * (lb - lz) - ly) * dt;
  dz = ((lx * ly) - (lc * lz)) * dt;

  lx += dx;
  ly += dy;
  lz += dz;

  /*
  I don't know exactly what range of values can the lorenz return

  So I created a function to adjust the scalings if a value is outside the range

  */

  updateScaling(0, 0, 1, 0, lx);
  updateScaling(0, 1, 1, 1, ly);
  updateScaling(0, 2, 1, 2, lz);

  //Values are scaled to 0-255 to adapt to the analogWrite function

  scaledX = mapfloat(lx, scalings[0][0], scalings[1][0], 0, 255);
  scaledY = mapfloat(ly, scalings[0][1], scalings[1][1], 0, 255);
  scaledZ = mapfloat(lz, scalings[0][2], scalings[1][2], 0, 255);

  scaledXInner = mapfloat(scaledX, 0, 255, 0, 190);
  scaledYInner = mapfloat(scaledY, 0, 255, 0, 190);
  scaledZInner = mapfloat(scaledZ, 0, 255, 0, 190);
}

/**

Strange Attractors - Brighten Colors

Brightness is managed as follows:
When brightness should be maximum:
Nothing happens to not affect the colors

*/

void brightenColors() {

  maxBrightnessAdjust();

  // When brightness should be minimum:
  // Variables are decreased to obtain minimum brightness without affecting the color

  if (fadeAmount < 0) {
    //Brightness is decreasing
    //Results are decreased to match with the wanted brightness

    effectiveR = brightness;                          //Red (x) is the master
    effectiveG = (scaledX / scaledY) * effectiveR;    //Proportion must remain unchanged
    effectiveB = (scaledX / scaledZ) * effectiveR;    //Proportion must remain unchanged

    if (effectiveR < 0) effectiveR = 0;   //Results must be greater or equal to 0
    if (effectiveG < 0) effectiveG = 0;   //Results must be greater or equal to 0
    if (effectiveB < 0) effectiveB = 0;   //Results must be greater or equal to 0

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

/**

STRANGE ATTRACTORS Functions

This Section is the Strange Attractor maths and stuff called by the strangeAttractor() function

*/

void updateScaling(byte rowA, byte cellA, byte rowB, byte cellB, float checkValue) {

  if (checkValue < scalings[rowA][cellA]) {   //If the variable is higher than the current max scale value, then update the max scale value
    scalings[rowA][cellA] = checkValue;
  }

  if (checkValue > scalings[rowB][cellB]) {   //If the variable is lower than the current min scale value, then update the min scale value
    scalings[rowB][cellB] = checkValue;
  }

    // Serial.print(",");
    // Serial.print(checkValue);
    // Serial.print(",");
    // Serial.print(scalings[rowA][cellA]);
    // Serial.print(",");
    // Serial.println(scalings[rowB][cellB]);  

}

void zeroVariables()
{
//Constants for the lorenz function, KEEP UNCHANGED
// a = 0;
// b = 0;
// c = 0;
// d = 0;
// e = 0;
// f = 0;
// g = 0;

// w = 0;
// x = 0;
// y = 0;
// z = 0;
// scaledX = 0;
// scaledY = 0;
// scaledZ = 0;
// effectiveR = 0;
// effectiveG = 0;
// effectiveB = 0;

//Variables for lorenz function
// dx = 0;
// dy = 0;
// dz = 0;

}

void strangeDelayReset()
{
  strangeRandom = 0;
  strangeSlowAmount = 0;
  delayAmount = 0;
  fadeSpeed = 0;
  darkDelay = 0;
  fullDelay = 0;
}
