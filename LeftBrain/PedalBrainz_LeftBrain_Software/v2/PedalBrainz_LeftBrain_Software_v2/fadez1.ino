void scalePixelFade (int val){

      //controlAmount = map(analogRead(A0), 0, 1024, 0, 100);
      //valueLog = log(analogRead(A0)+1)/log(1024)*255;
      //Serial.println("Mode 1 valueLog: " + String(valueLog));
      //fadeSpeed = map(valueLog, 0, 255, (speedMinimum), (40/2)); // Logarithmic Potentiometer Value
      //fadeSpeed = map(valueLog, 0, 255, (speedMinimum/2), (40/2)); // Logarithmic Potentiometer Value

      // This makes the potentiometer slower to change when reducting from full and gives better control fidelity at higher speeds
      // This is a map of values for the potentiometer. note: the in array should have increasing values
      int in[]  = {0, 25,51,76,102,127,153,178,204,229,255};
      // This is a map of values for potentiometer curve type.
      int out[] = {0, 5, 10,  15,  20,  25,  30,  35,  50,  80,  190 };  // 11
      // This maps the potentiometer scale.
      controlAmount  = val;
      // This is a multimap that assigns values from the [in] array (potentiometer) to values from the [out] array (curve)
      x = multiMap(controlAmount, in, out, 11);
      // This maps the values for the Modez.
      fadeValueScaled = map(x, 0, 255, 0, 255);

      //int redValue = 236;
      //int blueValue = 73;
      //int greenValue = 107;
      
}

  ////////////////////
  ////////////////////        Original fadez
  ////////////////////


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

////////////////////
////////////////////        Boolean Fadez
////////////////////

void fadez2()
{

  // Do a bunch of brightness stuff

  MaxBrightReduction = constrain(fadeAmount, 0, MaxBright);

  //A1 potentiometer controls for maximum brightness
  //maxBrightness = map(analogRead(A1), 0, 1024, 0, maxBrightnessTemp);
  maxBrightnessSet();

  //  Get ready to start the fade
  //  If the fadeAmount is over 255 (maximum) then fade down

  if (fadeAmount >= 255)      
  {

    //  Delay by an amount (A1) when the fade amount is 255 (max)
    //  Keeps the LED full brightness at peak

    delayA1(fullDelay);
    //Serial.println("Delay when LED fully lit (ms): " + String(fullDelay));

    plotCycle();
    checkButtons();

    //  If 

    if (Mode == 1)
    {
      fadeAmount = 0;
      setDark();
    }
    else
    {
      fadeUp = false;
      fadeAmount = 255;
    }

    

  }
  else if (fadeAmount <= 0)
  {

    delayA2(darkDelay);
    //Serial.println("Delay when LED fully dark (ms): " + String(darkDelay));

    plotCycle();
    checkButtons();

    fadeUp = true;
    fadeAmount = 0;

  }
  else;


  if (fadeUp == true)
  {
        fadeAmount = fadeAmount + 0.5;
        fadeAmount = fadeAmount+valueA0;

        //Serial.println("FADE UP || fadeAmount = " + String(fadeAmount) + " A0 = " + String(valueA0) + " fadeUp = " + String(fadeUp));

  }
  else if (fadeUp == false)
  {
        fadeAmount = fadeAmount - 0.5;
        fadeAmount = fadeAmount-valueA0;

        //Serial.println("FADE DOWN || fadeAmount = " + String(fadeAmount) + " A0 = " + String(valueA0) + " fadeDown = " + String(fadeUp));

  }
  else;

    valueA0 = map(analogRead(A0), 0, 1024, 0.5, 17.5);
    fadeAmount = constrain(fadeAmount, 0.0, 255.0);
    //FastLED.setBrightness(fadeAmount);

    //scalePixelBrightness(i);
    scalePixelRed(fadeAmount);

    for (int i = 0; i < NUM_LEDS; i++) {     // For each pixel in strip...
    //strip.setPixelColor(p, (i/5), 0, i);
    //strip.setPixelColor(p, (redValue), 0, redValue);
    leds[i] = CRGB(redValue, 0, redValue);
    }

    pixel.setPixelColor(0, redValue, 0, redValue);
    inner.setPixelColor(0, redValue, 0, redValue);

    delayA0(fadeSpeed);
    //FastLED.delay(fadeSpeed);
    //Serial.println("Rate of Fade in/ Fade out: " + String(fadeSpeed));

    plotCycle();
    checkButtons();

    showLEDS();
    FastLED.show();
       
}

void trianglez1()
{

  MaxBrightReduction = constrain(fadeAmount, 0, MaxBright);

  //A1 potentiometer controls for maximum brightness
  //maxBrightness = map(analogRead(A1), 0, 1024, 0, maxBrightnessTemp);
  maxBrightnessSet();

  //  Get ready to start the fade
  //  If the fadeAmount is equal or over 255 (maximum) then fade down

  if (fadeAmount >= 255)      
  {

    //  Delay by an amount (A1) when the fade amount is 255 (max)
    //  Keeps the LED full brightness

    delayA1(fullDelay);
    //Serial.println("Delay when LED fully lit (ms): " + String(fullDelay));

    plotCycle();
    checkButtons();

    fadeUp = false;
    fadeAmount = 255;

  }

  //  If the fadeAmount is equal or less than 0 (minimum) then fade up

  else if (fadeAmount <= 0)
  {

    //  Delay by an amount (A2) when the fade amount is 0 (min)
    //  Keeps the LED dark 

    delayA2(darkDelay);
    //Serial.println("Delay when LED fully dark (ms): " + String(darkDelay));

    plotCycle();
    checkButtons();

    // Set the fadeUp to true, set the fadeAmount to zero and start the cycle over

    fadeUp = true;
    fadeAmount = 0;

  }
  else;


  //  If fading up calculate how fast the fadeAmount counts up

  if (fadeUp == true)
  {
        fadeAmount = fadeAmount + 0.5;
        fadeAmount = fadeAmount+valueA0;

        //Serial.println("FADE UP || fadeAmount = " + String(fadeAmount) + " A0 = " + String(valueA0) + " fadeUp = " + String(fadeUp));

  }

  //  If fading down calculate how fast the fadeAmount counts down

  else if (fadeUp == false)
  {
        fadeAmount = fadeAmount - 0.5;
        fadeAmount = fadeAmount-valueA0;

        //Serial.println("FADE DOWN || fadeAmount = " + String(fadeAmount) + " A0 = " + String(valueA0) + " fadeDown = " + String(fadeUp));

  }
  else;

    //  Update the fadeAmount, rate of the cycle

    valueA0 = map(analogRead(A0), 0, 1024, 0.5, 17.5);
    fadeAmount = constrain(fadeAmount, 0.0, 255.0);
    //FastLED.setBrightness(fadeAmount);

    //  Scale the color of the LEDs

    //scalePixelBrightness(i);
    scalePixelRed(fadeAmount);

    for (int i = 0; i < NUM_LEDS; i++) {     // For each pixel in strip...
    //strip.setPixelColor(p, (i/5), 0, i);
    //strip.setPixelColor(p, (redValue), 0, redValue);
    leds[i] = CRGB(redValue, 0, redValue);
    }

    pixel.setPixelColor(0, redValue, 0, redValue);
    inner.setPixelColor(0, redValue, 0, redValue);

    //  Slow down the fade by an amount from A0

    delayA0(fadeSpeed);
    //FastLED.delay(fadeSpeed);
    //Serial.println("Rate of Fade in/ Fade out: " + String(fadeSpeed));

    plotCycle();
    checkButtons();

    showLEDS();
    FastLED.show();
       
}

void sawzUp1()
{

  MaxBrightReduction = constrain(fadeAmount, 0, MaxBright);

  //A1 potentiometer controls for maximum brightness
  //maxBrightness = map(analogRead(A1), 0, 1024, 0, maxBrightnessTemp);
  maxBrightnessSet();

  if (fadeAmount >= 255)      
  {

    delayA1(fullDelay);
    //Serial.println("Delay when LED fully lit (ms): " + String(fullDelay));

    plotCycle();
    checkButtons();

    fadeAmount = 0;
    setDark();

  }
  else if (fadeAmount <= 0)
  {

    delayA2(darkDelay);
    //Serial.println("Delay when LED fully dark (ms): " + String(darkDelay));

    plotCycle();
    checkButtons();

    fadeUp = true;
    fadeAmount = 0;

  }
  else;


  if (fadeUp == true)
  {
        fadeAmount = fadeAmount + 0.5;
        fadeAmount = fadeAmount+valueA0;

        //Serial.println("FADE UP || fadeAmount = " + String(fadeAmount) + " A0 = " + String(valueA0) + " fadeUp = " + String(fadeUp));

  }
  else if (fadeUp == false)
  {
        fadeAmount = fadeAmount - 0.5;
        fadeAmount = fadeAmount-valueA0;

        //Serial.println("FADE DOWN || fadeAmount = " + String(fadeAmount) + " A0 = " + String(valueA0) + " fadeDown = " + String(fadeUp));

  }
  else;

    valueA0 = map(analogRead(A0), 0, 1024, 0.5, 17.5);
    fadeAmount = constrain(fadeAmount, 0.0, 255.0);
    //FastLED.setBrightness(fadeAmount);

    //scalePixelBrightness(i);
    scalePixelRed(fadeAmount);

    for (int i = 0; i < NUM_LEDS; i++) {     // For each pixel in strip...
    //strip.setPixelColor(p, (i/5), 0, i);
    //strip.setPixelColor(p, (redValue), 0, redValue);
    leds[i] = CRGB(redValue, 0, redValue);
    }

    pixel.setPixelColor(0, redValue, 0, redValue);
    inner.setPixelColor(0, redValue, 0, redValue);

    delayA0(fadeSpeed);
    //FastLED.delay(fadeSpeed);
    //Serial.println("Rate of Fade in/ Fade out: " + String(fadeSpeed));

    plotCycle();
    checkButtons();

    showLEDS();
    FastLED.show();
       
}


void setDark()
{
    valueA0 = map(analogRead(A0), 0, 1024, 0.5, 17.5);
    fadeAmount = constrain(fadeAmount, 0.0, 255.0);
    //FastLED.setBrightness(fadeAmount);

    //scalePixelBrightness(i);
    scalePixelRed(fadeAmount);

    for (int i = 0; i < NUM_LEDS; i++) {     // For each pixel in strip...
    //strip.setPixelColor(p, (i/5), 0, i);
    //strip.setPixelColor(p, (redValue), 0, redValue);
    leds[i] = CRGB(0, 0, 0);
    }

    pixel.setPixelColor(0, 0, 0, 0);
    inner.setPixelColor(0, 0, 0, 0);

    delayA0(fadeSpeed);
    //FastLED.delay(fadeSpeed);
    //Serial.println("Rate of Fade in/ Fade out: " + String(fadeSpeed));

    plotCycle();
    checkButtons();

    showLEDS();
    FastLED.show();

    delayA2(darkDelay);
    //Serial.println("Delay when LED fully dark (ms): " + String(darkDelay));

}


  ////////////////////
  ////////////////////        Boolean Fadez w/ Palettes
  ////////////////////

void fadez3()
{

  //Serial.println("Made it to: fadez3");
  MaxBrightReduction = constrain(fadeAmount, 0, MaxBright);

  //A1 potentiometer controls for maximum brightness
  //maxBrightness = map(analogRead(A1), 0, 1024, 0, maxBrightnessTemp);
  maxBrightnessSet();

  if (startIndex >= 200)      
  {

      //Serial.println("Made it to: if (startIndex >= 255)   ");
      delayA1(fullDelay);
      //Serial.println("Delay when LED fully lit (ms): " + String(fullDelay));

      plotCycle();
      checkButtons();

/*      if (Mode == 3)
      {
        startIndex = 1;
        setDark();
      }
      else
      {
        fadeUp = false;
        startIndex = 255;
      }*/

      fadeUp = false;
      startIndex = 200;
      //setDark();

  }
  else if (startIndex <= 0)
  {

    //Serial.println("Made it to: if (startIndex <= 0)   ");
    setDark2();
    //delayA2(darkDelay);
    //Serial.println("Delay when LED fully dark (ms): " + String(darkDelay));

    plotCycle();
    checkButtons();

    fadeUp = true;
    startIndex = 0;

  }
  else;


  if (fadeUp == true)
  {
        //Serial.println("Made it to: fadeUp == true   ");


        paletteBanks();
        //currentPalette = cw2_033;
        STEPS = 256;
        currentBlending = LINEARBLEND;
        
        //static uint8_t startIndex = 0;
        //startIndex = startIndex + 1; /* motion speed */

        if (Bank == 1 && Mode == 3)
      {
        valueA0 = map(analogRead(A0), 0, 1024, 0.01, 30);
      }
      else
      {
        valueA0 = map(analogRead(A0), 0, 1024, 0.1, 30);
      }
        startIndex = startIndex + 0.1;
        startIndex = startIndex+valueA0;
        startIndex = constrain(startIndex, 0, 200);
        //scalePixelFade(startIndex);
        //startIndex = fadeValueScaled;
        
        //delayA0(fadeSpeed);
        

        //FastLED.setBrightness(startIndex);
        FillLEDsFromPaletteColors2(startIndex);
        //FastLED.setBrightness(startIndex);

        //averageLEDS();

        
        //Serial.println("startIndex : " + String(startIndex));
  }
  else if (fadeUp == false)
  {


        paletteBanks();
        //currentPalette = cw2_033;
        STEPS = 256;
        currentBlending = LINEARBLEND;
        
        //static uint8_t startIndex = 0;
        //startIndex = startIndex - 1; /* motion speed */

      if (Bank == 1 && Mode == 3)
      {
        valueA0 = map(analogRead(A0), 0, 1024, 0.01, 10);
      }
      else
      {
        valueA0 = map(analogRead(A0), 0, 1024, 0.1, 30);
      }

        startIndex = startIndex - 0.1;
        startIndex = startIndex-valueA0;
        startIndex = constrain(startIndex, 0, 200);
        //scalePixelFade(startIndex);
        //startIndex = fadeValueScaled;

        //delayA0(fadeSpeed);
        
        //FastLED.setBrightness(startIndex);
        FillLEDsFromPaletteColors2(startIndex);
        //FastLED.setBrightness(startIndex);

        //averageLEDS();

        //Serial.println("startIndex : " + String(startIndex));
  }
  else;


    //delayA0(fadeSpeed);
    //FastLED.delay(fadeSpeed);
    //Serial.println("Rate of Fade in/ Fade out: " + String(fadeSpeed));

    plotCycle();
    checkButtons();

    //showLEDS();
    //FastLED.show();
       
}

void setDark2()
{
    for (int i = 0; i < NUM_LEDS; i++) {     // For each pixel in strip...
    //strip.setPixelColor(p, (i/5), 0, i);
    //strip.setPixelColor(p, (redValue), 0, redValue);
    leds[i] = CRGB(0, 0, 0);
    }

    pixel.setPixelColor(0, 0, 0, 0);
    inner.setPixelColor(0, 0, 0, 0);

    FastLED.setBrightness(0);
    strip.setBrightness(0);

    //delayA0(fadeSpeed);
    //FastLED.delay(fadeSpeed);
    //Serial.println("Rate of Fade in/ Fade out: " + String(fadeSpeed));

    plotCycle();
    checkButtons();

    showLEDS();
    FastLED.show();

    delayA2(darkDelay);
    //Serial.println("Delay when LED fully dark (ms): " + String(darkDelay));

}


////////////////////
////////////////////        Boolean Fadez driven by Attractorz
////////////////////

void fadez4()
{

  //A1 potentiometer controls for maximum brightness
  //maxBrightness = map(analogRead(A1), 0, 1024, 0, maxBrightnessTemp);
  maxBrightnessAdjust();

  MaxBrightReduction = constrain(fadeAmount, 0, MaxBright);

  // attractorzCalc();
  // thomasFunction(); 
  // Serial.println("," + String(scaledVal)); 

  //count = count+1;
  thomasFunctionCalc();

  valueA2 = map(analogRead(A2), 0, 1024, 3000, 60);
  //valueA2 = 510;

  if (count >= valueA2)
  {
      
      scaledVal = mapfloat(x, -4, 4, 0, 10);
      //Serial.println("scaledX: " + String(scaledX));  
      count = 0;
  }
  else
  {
  count = count+1;
  }


  if (fadeAmount >= 255)      
  {

    //delayA1(fullDelay);
    //Serial.println("Delay when LED fully lit (ms): " + String(fullDelay));

    plotCycle();
    checkButtons();

      fadeUp = false;
      fadeAmount = 255;

  }
  else if (fadeAmount <= 0)
  {

    //delayA2(darkDelay);
    //Serial.println("Delay when LED fully dark (ms): " + String(darkDelay));

    plotCycle();
    checkButtons();

    fadeUp = true;
    fadeAmount = 0;

  }
  else;



  if (fadeUp == true)
  {
        fadeAmount = fadeAmount + 0.5;

        valueA2 = map(analogRead(A2), 0, 1024, 3000, 60);

        fadeAmount = fadeAmount+scaledVal;

  }
  else if (fadeUp == false)
  {
        fadeAmount = fadeAmount - 0.5;

        valueA2 = map(analogRead(A2), 0, 1024, 3000, 60);

        fadeAmount = fadeAmount-scaledVal;
 
  }
  else;

    fadeAmount = mapfloat(fadeAmount, 0, 255, 0, 255);

    for (int i = 0; i < NUM_LEDS; i++) {     // For each pixel in strip...
    leds[i] = CRGB(fadeAmount, 0, fadeAmount);
    }

    pixel.setPixelColor(0, fadeAmount, 0, fadeAmount);
    inner.setPixelColor(0, fadeAmount, 0, fadeAmount);

    plotCycle();
    checkButtons();

    showLEDS();
    FastLED.show();
       
}

void thomasFunctionCalc() {
  // put your main code here, to run repeatedly:
  dx = ((-b * x)+sin(y)) * timestep;
  dy = ((-b * y)+sin(z)) * timestep;
  dz = ((-b * z)+sin(x)) * timestep;

  x += dx;
  y += dy;
  z += dz;

  updateRange();

  //b = mapfloat(analogRead(A2), 0, 1024, .2, .01);

  if(map(x,minValue,maxValue,1,255) == 255){
    checkRestart();
  } else if(map(y,minValue,maxValue,1,255) == 255){
    checkRestart();
  } else if(map(z,minValue,maxValue,1,255) == 255){
    checkRestart();
  } {
    already = false;
  }

        //scaledVal = mapfloat(x, -4, 4, 1, 30);

        Serial.print(",");
        Serial.print(count);
        // Serial.print(",");
        // Serial.print(x);
        Serial.print(",");
        Serial.print(fadeAmount);
        Serial.print(",");
        Serial.println(scaledVal);  

        delayA0(fadeSpeed);
}
  


////////////////////
////////////////////        Boolean Fadez Calculate
////////////////////

void trianglezCalcA1()
{

  //  Get ready to start the fade
  //  If the fadeAmount is equal or over 255 (maximum) then fade down

  if (fadeAmountA1 >= 255)      
  {

    plotCycle();
    checkButtons();

    fadeUpA1 = false;
    fadeAmountA1 = 255;

  }

  //  If the fadeAmount is equal or less than 0 (minimum) then fade up

  else if (fadeAmountA1 <= 0)
  {

    plotCycle();
    checkButtons();

    // Set the fadeUp to true, set the fadeAmount to zero and start the cycle over

    fadeUpA1 = true;
    fadeAmountA1 = 0;

  }
  else;


  //  If fading up calculate how fast the fadeAmount counts up

  if (fadeUpA1 == true)
  {
        fadeAmountA1 = fadeAmountA1 + 0.5;
        fadeAmountA1 = fadeAmountA1+valueA1;

        //Serial.println("FADE UP || fadeAmount = " + String(fadeAmount) + " A0 = " + String(valueA0) + " fadeUp = " + String(fadeUp));

  }

  //  If fading down calculate how fast the fadeAmount counts down

  else if (fadeUpA1 == false)
  {
        fadeAmountA1 = fadeAmountA1 - 0.5;
        fadeAmountA1 = fadeAmountA1-valueA1;

        //Serial.println("FADE DOWN || fadeAmount = " + String(fadeAmount) + " A0 = " + String(valueA0) + " fadeDown = " + String(fadeUp));

  }
  else;

    //  Update the fadeAmount, rate of the cycle

    //valueA1 = map(analogRead(A1), 0, 1024, 0.5, 1);
    fadeAmountA1 = constrain(fadeAmountA1, 0.0, 255.0);
    //FastLED.setBrightness(fadeAmount);

    //  Slow down the fade by an amount from A0
    
    //delayA1(fullDelay);
    //FastLED.delay(fadeSpeed);
    //Serial.println("trianglezCalcA1: " + String(fadeAmountA1));

    plotCycle();
    checkButtons();

    //showLEDS();
    //FastLED.show();
       
}

void trianglezCalcA2()
{

  maxBrightnessSet();

  //  Get ready to start the fade
  //  If the fadeAmount is equal or over 255 (maximum) then fade down

  if (fadeAmountA2 >= 255)      
  {

    plotCycle();
    checkButtons();

    fadeUpA2 = false;
    fadeAmountA2 = 255;

  }

  //  If the fadeAmount is equal or less than 0 (minimum) then fade up

  else if (fadeAmountA2 <= 0)
  {

    plotCycle();
    checkButtons();

    // Set the fadeUp to true, set the fadeAmount to zero and start the cycle over

    fadeUpA2 = true;
    fadeAmountA2 = 0;

  }
  else;


  //  If fading up calculate how fast the fadeAmount counts up

  if (fadeUpA2 == true)
  {
        fadeAmountA2 = fadeAmountA2 + 0.5;
        fadeAmountA2 = fadeAmountA2+valueA2;

        //Serial.println("FADE UP || fadeAmount = " + String(fadeAmount) + " A0 = " + String(valueA0) + " fadeUp = " + String(fadeUp));

  }

  //  If fading down calculate how fast the fadeAmount counts down

  else if (fadeUpA2 == false)
  {
        fadeAmountA2 = fadeAmountA2 - 0.5;
        fadeAmountA2 = fadeAmountA2-valueA2;

        //Serial.println("FADE DOWN || fadeAmount = " + String(fadeAmount) + " A0 = " + String(valueA0) + " fadeDown = " + String(fadeUp));

  }
  else;

    //  Update the fadeAmount, rate of the cycle

    //valueA2 = map(analogRead(A2), 0, 1024, 0.5, 1);
    fadeAmountA2 = constrain(fadeAmountA2, 0.0, 255.0);
    //FastLED.setBrightness(fadeAmount);

    //  Slow down the fade by an amount from A0
    
    //delayA2(darkDelay);
    //FastLED.delay(fadeSpeed);
    //Serial.println("trianglezCalcA2: " + String(fadeAmountA2));

    plotCycle();
    checkButtons();

    //showLEDS();
    //FastLED.show();
       
}