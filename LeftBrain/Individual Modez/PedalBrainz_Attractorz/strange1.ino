


/**

STRANGE ATTRACTORS

*/
  //
  //  This Section is the Strange Attractor loop
  //


int scaledXInner;
int scaledYInner;
int scaledZInner;


void strangeAttractor()
{

  // SET MODE HERE
  //Bank = 1;
  //Mode = 8;

  //x = 0.01;
  //y = 0.3;
  //z = 0.7;

  //x = 0.1;
  //y = 2;
  //z = 1;

  //x = 0.5;
  //y = 0.9;
  //z = 0.1;



  //controlsMax();
  //checkButtons();

  //Don't execute the code if not enough time has elapsed
  if (millis() > nextLorenzUpdate) {


    lorenzFunction();
    nextLorenzUpdate = millis() + (printDelay);


    brightenColors();
    //checkButtons();

    //A2 potentiometer controls for amount of randomless from less to more random
    b = map(analogRead(A2), 0, 1024, 20, 50);

    strangeBright();
    //strangeBrightMinDark();
    //checkButtons();

    showLEDS();

    //A0 potentiometer controls for fade speed
    delayA0(fadeSpeed);

    //checkButtons();

    // Slow down the simulation when the value is low

    //strangeSlow();
    //strangeSlow2();
    //checkButtons();

    //plotCycle();
    //checkButtons();

  }

}

void strangeBright() {

  //A1 potentiometer controls for maximum brightness
  maxBrightness = map(analogRead(A1), 0, 1024, 0, maxBrightnessTemp);
  MaxBrightReduction = constrain(maxBrightness, 0, MaxBright);
  pixel.setBrightness(maxBrightness);
  strip.setBrightness(MaxBrightReduction);
  FastLED.setBrightness(MaxBrightReduction);
  inner.setBrightness(maxBrightness);
  showLEDS();

  //Serial.println("maxBrightness : " + String(maxBrightness));
  //Serial.println("MaxBright : " + String(MaxBright));
  //Serial.println("MaxBrightReduction : " + String(MaxBrightReduction));



  //Modes
  /* Set a value for each potentiometer (pin) for colors R,G,B. */

  if (Mode == 1)
  {
    for (int p = 0; p < strip.numPixels(); p++) {   // For each pixel in strip...
      strip.setPixelColor(p, (scaledX / 2), 0, (scaledX / 4));

    }
    pixel.setPixelColor(0, (scaledXInner / 4), 0, (scaledXInner / 8));   //Single Output Scaled X
    inner.setPixelColor(0, (scaledXInner / 4), 0, (scaledXInner / 8));   //Single Output Scaled X
    //pixel.setPixelColor(0, x, 0, 30);   //Single Output Scaled X
    showLEDS();
  }
  if (Mode == 2)
  {
    for (int p = 0; p < strip.numPixels(); p++) {   // For each pixel in strip...
      strip.setPixelColor(p, (scaledX / 2), 0, (scaledZ / 2));

    }
    pixel.setPixelColor(0, (scaledXInner / 4), 0, (scaledZInner / 4));   //Double Output Scaled X & Z
    inner.setPixelColor(0, (scaledXInner / 4), 0, (scaledZInner / 4));   //Double Output Scaled X & Z
    //pixel.setPixelColor(0, x, 0, z+100);   //Double Output Scaled X & Z
    showLEDS();
  }
  if (Mode == 3)
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
  //Serial.println("x: " + String(x) + " y : " + String(y) + " z : " + String(z));

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

  scaledX = map(x, scalings[0][0], scalings[1][0], 0, 255);
  scaledY = map(y, scalings[0][1], scalings[1][1], 0, 255);
  scaledZ = map(z, scalings[0][2], scalings[1][2], 0, 255);

  scaledXInner = map(scaledX, 0, 255, 0, 190);
  scaledYInner = map(scaledY, 0, 255, 0, 190);
  scaledZInner = map(scaledZ, 0, 255, 0, 190);

  //Serial.println("scaledx: " + String(scaledX) + " scaledY : " + String(scaledY) + " scaledz : " + String(scaledZ));
  Serial.println("x: " + String(x) + " y : " + String(y) + " z : " + String(z));

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

    effectiveR = brightness;                          //Red (x) is the master
    effectiveG = (scaledX / scaledY) * effectiveR;    //Proportion must remain unchanged
    effectiveB = (scaledX / scaledZ) * effectiveR;    //Proportion must remain unchanged

    if (effectiveR < 0) effectiveR = 0;   //Results must be greater or equal to 0
    if (effectiveG < 0) effectiveG = 0;   //Results must be greater or equal to 0
    if (effectiveB < 0) effectiveB = 0;   //Results must be greater or equal to 0

/*    Serial.print("Fading  ");
    Serial.print(brightness);
    Serial.print("  ");
    Serial.print(effectiveR);
    Serial.print("  ");
    Serial.print(effectiveG);
    Serial.print("  ");
    Serial.println(effectiveB);
    //delay(3000);*/

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
    maxBrightness = map(analogRead(A1), 0, 1024, 0, maxBrightnessTemp);
    MaxBrightReduction = constrain(maxBrightness, 0, MaxBright);
    pixel.setBrightness(maxBrightness);
    strip.setBrightness(MaxBrightReduction);
    FastLED.setBrightness(MaxBrightReduction);
    inner.setBrightness(maxBrightness);
    showLEDS();
    //Serial.println(maxBrightness);

    //Modes
    /* Set a value for each potentiometer (pin) for colors R,G,B. */

    if (Mode == 1)
    {
      for (int p = 0; p < strip.numPixels(); p++) {   // For each pixel in strip...
        strip.setPixelColor(p, (scaledX / 2), 0, (scaledX / 4));
      }
      pixel.setPixelColor(0, (scaledXInner / 4), 0, (scaledXInner / 8));   //Single Output Scaled X
      inner.setPixelColor(0, (scaledXInner / 4), 0, (scaledXInner / 8));   //Single Output Scaled X
      //pixel.setPixelColor(0, x, 0, 30);   //Single Output Scaled X
      showLEDS();
    }
    if (Mode == 2)
    {
      for (int p = 0; p < strip.numPixels(); p++) {   // For each pixel in strip...
        strip.setPixelColor(p, (scaledX / 2), 0, (scaledZ / 2));

      }
      pixel.setPixelColor(0, (scaledXInner / 4), 0, (scaledZInner / 4));   //Double Output Scaled X & Z
      inner.setPixelColor(0, (scaledXInner / 4), 0, (scaledZInner / 4));   //Double Output Scaled X & Z
      //pixel.setPixelColor(0, x, 0, z+100);   //Double Output Scaled X & Z
      showLEDS();
    }
    if (Mode == 3)
    {
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
      //checkButtons();
      delayA2(darkDelay);

      maxBrightness = map(analogRead(A1), 0, 1024, 0, maxBrightnessTemp);
      MaxBrightReduction = constrain(maxBrightness, 0, MaxBright);
      pixel.setBrightness(maxBrightness);
      strip.setBrightness(MaxBrightReduction);
      FastLED.setBrightness(MaxBrightReduction);
      inner.setBrightness(maxBrightness);
      showLEDS();
      
      //Serial.println("strangeSlow: " + String(darkDelay) + " strangeSlowAmount : " + String(strangeSlowAmount));
      Serial.println("scaledY: " + String(scaledY) + " darkDelay : " + String(darkDelay) + " strangeSlowCount : " + String(strangeSlowCount));
    }
  }
}
