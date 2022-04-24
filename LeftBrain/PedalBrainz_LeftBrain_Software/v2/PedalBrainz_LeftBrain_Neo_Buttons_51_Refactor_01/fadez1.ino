void Fadez_01 () {

  plotCycle();

  if (Mode == 2)
  {
    redValue = 115;
    greenValue = 0;
    blueValue = 130;
  }
  else if (Mode == 3)     // pixel.setPixelColor(0, 36, 0, 255);
  {
    redValue = 36;
    greenValue = 0;
    blueValue = 255;

    valueA0 = map(analogRead(A0), 0, 1024, 100, 0);
    delayValueA0 = map(analogRead(A0), 0, 1024, -200, 40);
    randomAmountA0 = random(0, delayValueA0);
    fadeSpeed = valueA0 + randomAmountA0;
    //Serial.println("randomAmountA0: " + String(fadeSpeed));
    //Serial.println("Fade Speed: " + String(fadeSpeed));
  }
  else
  {
    fadeSpeed = 0;
    fullDelay = 0;
    darkDelay = 0;
    randomAmount = 0;
  }

  // Set x and start fading
  int x = 1;

  
  for (int i = 0; i > -1; i = i + x)  //This fades the brightness in and out using maths
  {

    MaxBrightReduction = constrain(i, 0, MaxBright);

    //scalePixelBrightness(i);
    scalePixelRed(i);

    //A1 potentiometer controls for maximum brightness
    //maxBrightness = map(analogRead(A1), 0, 1024, 0, maxBrightnessTemp);
    MaxBrightReduction = constrain(maxBrightness, 0, MaxBright);
    pixel.setBrightness(maxBrightness);
    strip.setBrightness(MaxBrightReduction);
    FastLED.setBrightness(MaxBrightReduction);
    inner.setBrightness(maxBrightness);

    //for (int p = 0; p < strip.numPixels(); p++) {     // For each pixel in strip...
    for (int i = 0; i < NUM_LEDS; i++) {     // For each pixel in strip...
      //strip.setPixelColor(p, (i/5), 0, i);
      //strip.setPixelColor(p, (redValue), 0, redValue);
      leds[i] = CRGB(redValue, 0, redValue);
    }

    pixel.setPixelColor(0, redValue, 0, redValue);
    inner.setPixelColor(0, redValue, 0, redValue);

    showLEDS();
    FastLED.show();

    plotCycle();
    checkButtons();

    if (clicked == true) {

        //Serial.println("I Broke Fadez Mode " + String(Mode) + " because button was clicked");
        breakdelayA0 = true;
        breakdelayA1 = true;
        breakdelayA2 = true;
        clicked = false;
        break;
        i = 1;
        x = 1;
        fadeSpeed = 0;
        fullDelay = 0;
        darkDelay = 0;
        randomAmount = 0;
    }
    else {

    };

    if (breakdelayA0 == true)
    {
      //Serial.println("Fadez - I Broke delayA0 Because A0 was true");
      breakdelayA0 = false;
      break;
    }
    if (breakdelayA1 == true)
    {
      //Serial.println("Fadez - I Broke delayA1 Because A0 was true");
      breakdelayA1 = false;
      break;
    }
    if (breakdelayA2 == true)
    {
      //Serial.println("Fadez - I Broke delayA2 Because A0 was true");
      breakdelayA2 = false;
      break;
    }
    else {
  };

  if (i == 255)                       //If the fade has reached it's peak keep the LED lit and then fade out
  {


    //Mode changes to the delay time when LED is full color value for potentiometer A1
    //Use the value of A1 to keep the LED fully lit by the amount of A1 (delay) and then start fading out

    delayA1(fullDelay);
    Serial.println("Delay when LED fully lit (ms): " + String(fullDelay));

    plotCycle();
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

  plotCycle();
  checkButtons();

  }

  //Serial.println("Rate of Fade in/ Fade out: " + String(valueA0));

  //Mode changes to the delay time of the fade speed for potentiometer A2
  //Use the value of A2 to keep the LED fully dark (delay) between fade in/fade out

  delayA2(darkDelay);
  Serial.println("Delay when LED fully dark (ms): " + String(darkDelay));

  plotCycle();
  checkButtons();

  randomAmount = random(0, delayValueA0);
  
  //Serial.println("Rate of Fade in/ Fade out: " + String(fadeSpeed) + " ||| Delay when LED fully lit (ms): " + String(fullDelay) + " ||| Delay when LED fully dark (ms): " + String(darkDelay));
  plotCycle();
  checkButtons();

}


void fadez2()
{

  MaxBrightReduction = constrain(fadeAmount, 0, MaxBright);

  //A1 potentiometer controls for maximum brightness
  //maxBrightness = map(analogRead(A1), 0, 1024, 0, maxBrightnessTemp);
  MaxBrightReduction = constrain(maxBrightness, 0, MaxBright);
  pixel.setBrightness(maxBrightness);
  strip.setBrightness(MaxBrightReduction);
  FastLED.setBrightness(MaxBrightReduction);
  inner.setBrightness(maxBrightness);

  if (fadeAmount >= 255)      
  {

    
    fadeUp = false;
    fadeAmount = 255;

  }
  else if (fadeAmount <= 0)
  {

    //delay(1000);
    fadeUp = true;
    fadeAmount = 0;

  }
  else;


  if (fadeUp == true)
  {
        fadeAmount = fadeAmount + 0.5;
        fadeAmount = fadeAmount+valueA0;

        Serial.println("FADE UP || fadeAmount = " + String(fadeAmount) + " A0 = " + String(valueA0) + " fadeUp = " + String(fadeUp));

  }
  else if (fadeUp == false)
  {
        fadeAmount = fadeAmount - 0.5;
        fadeAmount = fadeAmount-valueA0;

        Serial.println("FADE DOWN || fadeAmount = " + String(fadeAmount) + " A0 = " + String(valueA0) + " fadeDown = " + String(fadeUp));

  }
  else;

    //scalePixelBrightness(i);
    scalePixelRed(fadeAmount);

    valueA0 = map(analogRead(A0), 0, 1024, 1, 30);
    fadeAmount = constrain(fadeAmount, 0, 255);
    //FastLED.setBrightness(fadeAmount);

    for (int i = 0; i < NUM_LEDS; i++) {     // For each pixel in strip...
      //strip.setPixelColor(p, (i/5), 0, i);
      //strip.setPixelColor(p, (redValue), 0, redValue);
      leds[i] = CRGB(redValue, 0, redValue);
    }

    pixel.setPixelColor(0, redValue, 0, redValue);
    inner.setPixelColor(0, redValue, 0, redValue);

    showLEDS();
    FastLED.show();
       
}