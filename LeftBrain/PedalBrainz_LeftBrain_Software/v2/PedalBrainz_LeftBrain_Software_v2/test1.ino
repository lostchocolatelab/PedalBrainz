/**

    These are utility modes

*/

void testColorPotentiometer() {

  //Start the Brightness of the on-board DotStar LED
  pixel.setBrightness(255);
  inner.setBrightness(255);
  strip.setBrightness(255);

  /* Read the value for each potentiometer (pin) and set as R, G, B continuously while looping*/

  //Potentiometer Top Left | A1 - Map the value of the potentiometer from 0-1024 to 0-256 to the variable redValue
  redValue = map(analogRead(A1), 0, 1024, 0, 256);
  //Serial.println("potentiometerA1: " + String(redValue));   //This will print the value of the A1 Potentiometer

  //Potentiometer Top Right | A0 - Map the value of the potentiometer from 0-1024 to 0-256 to the variable greenValue
  blueValue = map(analogRead(A0), 0, 1024, 0, 256);
  //Serial.println("potentiometerA0: " + String(greenValue));   //This will print the value of the A0 Potentiometer

  //Potentiometer Bottom Right | A2 - Map the value of the potentiometer from 0-1024 to 0-256 to the variable blueValue
  greenValue = map(analogRead(A2), 0, 1024, 0, 256);
  //Serial.println("potentiometerA2: " + String(blueValue));   //This will print the value of the A2 Potentiometer

  if (2 >= redValue)
  {
    redValue = 0;
  }
  if (1 >= greenValue)
  {
    greenValue = 0;
  }
  if (1 >= blueValue)
  {
    blueValue = 0;
  }

  // Declare the LED "number" (0) and set a value for each potentiometer (pin) for colors R,G,B
  //pixel.setPixelColor(0, (redValue), (greenValue), (blueValue));
  //strip.setPixelColor(0,0,0,0);

  strip.setPixelColor(0, redValue, blueValue, greenValue);
  strip.setPixelColor(1, redValue, blueValue, greenValue);
  strip.setPixelColor(2, redValue, blueValue, greenValue);
  //strip.setPixelColor(3, redValue, blueValue, greenValue);

  pixel.setPixelColor(0, redValue, blueValue, greenValue);
  inner.setPixelColor(0, redValue, blueValue, greenValue);

  inner.show();
  strip.show();
  pixel.show();

  checkButtons();

  //This will print the value of all thee Potentiometers in the Serial Monitor and Serial Plotter
  Serial.println("Potentiometer A1: RED " + String(redValue) + " Potentiometer A2: GREEN " + String(blueValue) + " Potentiometer A0: BLUE " + String(greenValue));
}

void testBrightPotentiometer() {



  //Potentiometer Top Left | A1 - Map the value of the potentiometer from 0-1024 to 0-256 to the variable redValue
  //MaxBrightTemp = map(analogRead(A1), 0, 1024, 0, 256);
  //Serial.println("potentiometerA1: " + String(redValue));   //This will print the value of the A1 Potentiometer

  //Potentiometer Top Right | A0 - Map the value of the potentiometer from 0-1024 to 0-256 to the variable greenValue
  //MaxBrightTemp = map(analogRead(A0), 0, 1024, 0, 256);
  //Serial.println("potentiometerA0: " + String(greenValue));   //This will print the value of the A0 Potentiometer

  //Potentiometer Bottom Right | A2 - Map the value of the potentiometer from 0-1024 to 0-256 to the variable blueValue
  MaxBrightTemp = map(analogRead(A0), 0, 1024, 0, 256);
  //Serial.println("MaxBrightTemp: " + String(MaxBrightTemp));   //This will print the value of MaxBrightTemp

  //Start the Brightness of the on-board DotStar LED
  pixel.setBrightness(0);
  inner.setBrightness(0);
  strip.setBrightness(MaxBrightTemp);

  //Potentiometer Top Left | A1 - Map the value of the potentiometer from 0-1024 to 0-256 to the variable redValue
  redValue = map(analogRead(A0), 0, 1024, 0, 256);
  //Serial.println("potentiometerA1: " + String(redValue));   //This will print the value of the A1 Potentiometer
  greenValue = redValue;
  blueValue = redValue;

  // Declare the LED "number" (0) and set a value for each potentiometer (pin) for colors R,G,B
  //pixel.setPixelColor(0, (redValue), (greenValue), (blueValue));
  //strip.setPixelColor(0,0,0,0);

  strip.setPixelColor(0, 0, 0, 0);
  strip.setPixelColor(1, redValue, blueValue, greenValue);
  strip.setPixelColor(2, 0, 0, 0);
  //strip.setPixelColor(3, redValue, blueValue, greenValue);

  pixel.setPixelColor(0, 0, 0, 0);
  inner.setPixelColor(0, 0, 0, 0);

  inner.show();
  strip.show();
  pixel.show();

  checkButtons();

  //This will print the value of all thee Potentiometers in the Serial Monitor and Serial Plotter
  //Serial.println("Potentiometer A1: RED " + String(redValue)  + " Potentiometer A2: BLUE " + String(blueValue)+ " Potentiometer A0: GREEN " + String(greenValue));
}

void testCurve()
{
  innerValue = 115;
  greenValue = 0;
  blueValue = 130;


  //plotCycle();

  // Set x and start fading
  int x = 1;

  // valueA1 = map(analogRead(A1), 0, 1024, 0, 190);
  // Serial.println("Fade Max: " + String(valueA1));

  for (int i = 0; i > -1; i = i + x)  //This fades the brightness in and out using maths
  {

    MaxBrightReduction = constrain(i, 0, MaxBright);

    //scalePixelBrightness(i);
    scalePixelInner(i);

    //A1 potentiometer controls for maximum brightness
    //maxBrightness = map(analogRead(A1), 0, 1024, 0, maxBrightnessTemp);
    MaxBrightReduction = constrain(maxBrightness, 0, MaxBright);
    strip.setBrightness(MaxBrightReduction);
    FastLED.setBrightness(MaxBrightReduction);
    pixel.setBrightness(maxBrightness);
    inner.setBrightness(maxBrightness);

    //for (int p = 0; p < strip.numPixels(); p++) {     // For each pixel in strip...
    // for (int i = 0; i < NUM_LEDS; i++) {     // For each pixel in strip...
    //   //strip.setPixelColor(p, (i/5), 0, i);
    //   //strip.setPixelColor(p, (redValue), 0, redValue);
    //   leds[i] = CRGB(innerValue, innerValue, innerValue);
    // }

    pixel.setPixelColor(0, 0, 0, innerValue);
    inner.setPixelColor(0, 0, 0, innerValue);

    showLEDS();
    FastLED.show();

    //plotCycle();
    checkButtons();

  if (i == 140)                       //If the fade has reached it's peak keep the LED lit and then fade out
  {


    //Mode changes to the delay time when LED is full color value for potentiometer A1
    //Use the value of A1 to keep the LED fully lit by the amount of A1 (delay) and then start fading out

    delayA1(500);
    //Serial.println("Delay when LED fully lit (ms): " + String(fullDelay));

    //plotCycle();
    checkButtons();

    x = -1;      // switch direction at peak

    //Experiment in-progress
    //pixel.setPixelColor(0, redValue+i, greenValue, blueValue-i);
  }

  //Mode changes to the delay time of the fade speed for potentiometer A0
  //Use the value of A0 to control the rate of fade in/out using a delay

  delayA0(fadeSpeed);
  //FastLED.delay(fadeSpeed);
  //Serial.println("Rate of Fade in/ Fade out: " + String(fadeSpeed));

  //plotCycle();
  checkButtons();

  }

  //Serial.println("Rate of Fade in/ Fade out: " + String(valueA0));

  //Mode changes to the delay time of the fade speed for potentiometer A2
  //Use the value of A2 to keep the LED fully dark (delay) between fade in/fade out

  delayA2(500);
  //Serial.println("Delay when LED fully dark (ms): " + String(darkDelay));

  //plotCycle();
  checkButtons();

  //randomAmount = random(0, delayValueA0);
  
  //Serial.println("Rate of Fade in/ Fade out: " + String(fadeSpeed) + " ||| Delay when LED fully lit (ms): " + String(fullDelay) + " ||| Delay when LED fully dark (ms): " + String(darkDelay));
  //plotCycle();
  checkButtons();

}