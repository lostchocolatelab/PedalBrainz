/**

A0 Delay - Fade Speed

*/

int scaledA0;

void mapScaledA0() {


        // This makes the potentiometer slower to change when reducting from full and gives better control fidelity at higher speeds
        // This is a map of values for the potentiometer. note: the in array should have increasing values
        int scaleAin[]  = {0, 25, 51, 76, 102, 127, 153, 178, 204, 229, 255};
        // This is a map of values for potentiometer curve type.
        int scaleAout[] = { 2300, 2298, 2296, 2295, 2292, 2200, 2100, 2000, 1800, 1300, 0 };         // 11
        // This maps the potentiometer scale.
        controlAmount  = map(analogRead(A0), 0, 1024, 255, 0);
        // This is a multimap that assigns values from the [in] array (potentiometer) to values from the [out] array (curve)
        scaledA0 = multiMap(controlAmount, scaleAin, scaleAout, 11);
        // This maps the values for the Modez.

        //Serial.println("Mode 1 controlAmount: " + String(controlAmount));
        //Serial.println("Mode 1 fadeSpeeed: " + String(fadeSpeed));
}

void delayA0(int count)
{

  ////////////////////
  ////////////////////        BANK 1 - Greatz
  ////////////////////
  
  if (Bank == 1)
  {

    int delayCountA0 = fadeSpeed;

    plotCycle();
    checkButtons();

    for (int count = 0; count <= delayCountA0; count++) {

      delayCountA0 = fadeSpeed;

      plotCycle();
      checkButtons();

      if (clicked == true) {

        //Serial.println("I Broke delayA0 Mode " + String(Mode) + " because button was clicked");
        breakdelayA0 = true;
        breakdelayA1 = true;
        breakdelayA2 = true;
        clicked = false;
        break;
        //count = 1;
        fadeSpeed = 0;
        fullDelay = 0;
        darkDelay = 0;
        randomAmount = 0;
        delayCountA0 = 0;
      }
      else {

      };

      if (breakdelayA0 == true)
      {
        //Serial.println("I Broke delayA0 Because A0 was true");
        breakdelayA0 = false;
        break;

      }
      else {

      }


      // Potentiometer Top Right | A0 - Map the value of the Potentiometer to a Variable
      if (Mode == 1) {

        mapScaledA0();
        fadeSpeed = mapfloat(scaledA0, 0, 2300, speedMinimum, 30);

        valueA1 = map(analogRead(A1), 0, 1024, 0, 90);
        valueA2 = map(analogRead(A2), 0, 1024, 0, 90);
      }
      // Potentiometer Top Right | A0 - Map the value of the Potentiometer to a Variable
      else if (Mode == 2) {

        //Fadez_01
        //mapScaledA0();
        //fadeSpeed = map(scaledA0, 0, 2300, speedMinimum, 0);

        //Fadez_03
        mapScaledA0();
        fadeSpeed = mapfloat(scaledA0, 0, 2300, 10, 0);

        //Serial.println("Mode 2 controlAmount: " + String(controlAmount));
        //Serial.println("Mode 2 fadeSpeeed: " + String(fadeSpeed));

      }
      else if (Mode == 3) {
        //Serial.println("Delay Value A0: " + String(delayValueA0));
        //Serial.println("Delay Random (ms) A0: " + String(randomAmountA0));
        //Serial.println("Mode 2 fadeSpeeed: " + String(fadeSpeed));

        //Fadez_01
        //mapScaledA0();
        //fadeSpeed = map(scaledA0, 0, 2300, speedMinimum, 0);

        //Fadez_03
        mapScaledA0();
        fadeSpeed = mapfloat(scaledA0, 0, 2300, 10, 0);

        //Serial.println("Mode 3 controlAmount: " + String(controlAmount));
        //Serial.println("Mode 3 fadeSpeeed: " + String(fadeSpeed));
      }
      else if (Mode == 4) {

        mapScaledA0();
        fadeSpeed = mapfloat(scaledA0, 0, 2300, speedMinimum / 10, -1);

        //Serial.println("Mode 4 controlAmount: " + String(controlAmount));
        //Serial.println("Mode 4 fadeSpeeed: " + String(fadeSpeed));


      }
      else if (Mode == 5) {

        mapScaledA0();
        fadeSpeed = mapfloat(scaledA0, 0, 2300, speedMinimum / 10, -1);

        //Serial.println("Mode 5 controlAmount: " + String(controlAmount));
        //Serial.println("Mode 5 fadeSpeeed: " + String(fadeSpeed));

      }
      else if (Mode == 8) {

        fadeSpeed = mapfloat(analogRead(A0), 0, 1024, (speedMinimum / 10), 0);

        //Serial.println("Mode 8 fadeSpeeed: " + String(fadeSpeed));

      }
      else if (Mode == 9) {

        fadeSpeed = mapfloat(analogRead(A0), 0, 1024, (speedMinimum / 10), 0);

        //Serial.println("Mode 9 fadeSpeeed: " + String(fadeSpeed));

      }
      else if (Mode == 10) {

        fadeSpeed = mapfloat(analogRead(A0), 0, 1024, (speedMinimum / 10), 0);

        //Serial.println("Mode 10 fadeSpeeed: " + String(fadeSpeed));

      }
      else {
        fadeSpeed = 7;
        //Serial.println("Else fadeSpeeed: " + String(fadeSpeed));
      }

      if (Mode == 1)
      {
        delay(0);

        // Update the brightness of each blink color depending on which Blink it is
        if (Blink1 == true)
        {

          maxBrightnessSet();
          showLEDS();

          valueA1 = map(analogRead(A1), 0, 1024, 0, 255);
          pixel.setPixelColor(0, valueA1, (valueA1 / 10), 0);         // Blink 1
          inner.setPixelColor(0, valueA1, (valueA1 / 10), 0);         // Blink 1
          //for(int p=0; p<strip.numPixels(); p++) {         // For each pixel in strip...
          //      strip.setPixelColor(p, valueA1, (valueA1/10), 0);
          //}
          strip.setPixelColor(0, valueA1, (valueA1 / 10), 0);         // Blink 1
          strip.setPixelColor(1, valueA1, (valueA1 / 10), 0);         // Blink 1

          showLEDS();


        }
        if (Blink1 == false)
        {

          maxBrightnessSet();
          showLEDS();

          valueA2 = map(analogRead(A2), 0, 1024, 0, 255);
          pixel.setPixelColor(0, (valueA2 / 6), valueA2, valueA2);         // Blink 2
          inner.setPixelColor(0, (valueA2 / 6), valueA2, valueA2);         // Blink 2
          //for(int p=0; p<strip.numPixels(); p++) {         // For each pixel in strip...
          //      strip.setPixelColor(p, (valueA2/6), valueA2, valueA2);
          //}
          strip.setPixelColor(1, valueA1, (valueA1 / 10), 0);         // Blink 2
          strip.setPixelColor(1, (valueA2 / 6), valueA2, valueA2);         // Blink 2
          strip.setPixelColor(2, (valueA2 / 6), valueA2, valueA2);         // Blink 2

          showLEDS();
        }

      }
      else
      {
        delay(.1);
      };

      checkButtons();

        //Serial.println("Bank - " + String(Bank) + " Mode - " + String(Mode) + " fadeSpeeed: " + String(fadeSpeed));
        //controlsMax();
        //Serial.println("Count if Waiting = False: " + String(count));

    }
  }

  ////////////////////
  ////////////////////        BANK 2 - Shapez
  ////////////////////

  else if (Bank == 2)
  {
    int delayCountA0 = fadeSpeed;

    plotCycle();
    checkButtons();

    for (int count = 0; count <= delayCountA0; count++) {

      delayCountA0 = fadeSpeed;

      plotCycle();
      checkButtons();

      if (clicked == true) {

        //Serial.println("I Broke delayA0 Mode " + String(Mode) + " because button was clicked");
        breakdelayA0 = true;
        breakdelayA1 = true;
        breakdelayA2 = true;
        clicked = false;
        break;
        //count = 1;
        fadeSpeed = 0;
        fullDelay = 0;
        darkDelay = 0;
        randomAmount = 0;
        delayCountA0 = 0;

      }
      else {

      }

      if (breakdelayA0 == true)
      {
        //Serial.println("I Broke delayA0 Because A0 was true");
        breakdelayA0 = false;
        break;

      }
      else {

      }

        // Potentiometer Top Right | A0 - Map the value of the Potentiometer to a Variable

      if (Mode == 1) {

        mapScaledA0();
        fadeSpeed = mapfloat(scaledA0, 0, 2300, speedMinimum, 30);

        // valueA1 = map(analogRead(A1), 0, 1024, 0, 90);
        // valueA2 = map(analogRead(A2), 0, 1024, 0, 90);

        //Serial.println("Mode 3 controlAmount: " + String(controlAmount));
        //Serial.println("Bank - " + String(Bank) + "Mode" + String(Mode) + "fadeSpeeed: " + String(fadeSpeed));
      }
      else if (Mode == 2) {

        mapScaledA0();
        fadeSpeed = mapfloat(scaledA0, 0, 2300, speedMinimum, 30);

        // valueA1 = map(analogRead(A1), 0, 1024, 0, 90);
        // valueA2 = map(analogRead(A2), 0, 1024, 0, 90);

        //Serial.println("Mode 3 controlAmount: " + String(controlAmount));
        //Serial.println("Bank - " + String(Bank) + "Mode" + String(Mode) + "fadeSpeeed: " + String(fadeSpeed));

      }
      else if (Mode == 3) {

        mapScaledA0();
        fadeSpeed = mapfloat(scaledA0, 0, 2300, speedMinimum, 0);

        //Serial.println("Mode 3 controlAmount: " + String(controlAmount));
        //Serial.println("Bank - " + String(Bank) + "Mode" + String(Mode) + "fadeSpeeed: " + String(fadeSpeed));
      }
      else if (Mode == 4) {

        mapScaledA0();
        fadeSpeed = mapfloat(scaledA0, 0, 2300, speedMinimum, 0);

        //Serial.println("Mode 3 controlAmount: " + String(controlAmount));
        //Serial.println("Bank - " + String(Bank) + "Mode" + String(Mode) + "fadeSpeeed: " + String(fadeSpeed));
      }
      else if (Mode == 5) {

        mapScaledA0();
        fadeSpeed = mapfloat(scaledA0, 0, 2300, speedMinimum, 0);

        //Serial.println("Mode 3 controlAmount: " + String(controlAmount));
        //Serial.println("Bank - " + String(Bank) + "Mode" + String(Mode) + "fadeSpeeed: " + String(fadeSpeed));
      }
      else if (Mode == 6) {

        mapScaledA0();
        fadeSpeed = mapfloat(scaledA0, 0, 2300, speedMinimum, 0);

        //Serial.println("Mode 3 controlAmount: " + String(controlAmount));
        //Serial.println("Bank - " + String(Bank) + "Mode" + String(Mode) + "fadeSpeeed: " + String(fadeSpeed));
      }
      else if (Mode == 7) {

        mapScaledA0();
        fadeSpeed = mapfloat(scaledA0, 0, 2300, speedMinimum, 0);

        //fadeSpeed = map(analogRead(A0), 0, 1024, durationMaximum, 0);
        //Serial.println("Bank - " + String(Bank) + "Mode" + String(Mode) + "fadeSpeeed: " + String(fadeSpeed));
      }
      else if (Mode == 8) {

        mapScaledA0();
        fadeSpeed = mapfloat(scaledA0, 0, 2300, speedMinimum, 0);

        //Serial.println("delayA0 fadeSpeeed: " + String(fadeSpeed));
      }
      else if (Mode == 9) {

        mapScaledA0();
        fadeSpeed = mapfloat(scaledA0, 0, 2300, speedMinimum, 0);

        //Serial.println("delayA0 fadeSpeeed: " + String(fadeSpeed));
      }
      else if (Mode == 10) {

        mapScaledA0();
        fadeSpeed = mapfloat(scaledA0, 0, 2300, speedMinimum, 0);

        //Serial.println("Mode 2 controlAmount: " + String(controlAmount));
        //Serial.println("Mode 2 fadeSpeeed: " + String(fadeSpeed));

      }
      else {
        fadeSpeed = 7;
        //Serial.println("Else fadeSpeeed: " + String(fadeSpeed));
      }

      if (Mode == 1)    //  Squarez Controlled
      {
        delay(0);

        // trianglezCalcA1();
        // trianglezCalcA2();

        maxBrightness = 255;

        // Update the brightness of each blink color depending on which Blink it is
        if (Blink1 == true)
        {

          maxBrightnessSet();
          showLEDS();

          //valueA1 = map(analogRead(A1), 0, 1024, 0, 10);
          pixel.setPixelColor(0, fadeAmountA1, 0, (fadeAmountA1 / 10));         // Blink 1
          inner.setPixelColor(0, fadeAmountA1, 0, (fadeAmountA1 / 10));         // Blink 1
          //for(int p=0; p<strip.numPixels(); p++) {         // For each pixel in strip...
          //      strip.setPixelColor(p, valueA1, (valueA1/10), 0);
          //}
          strip.setPixelColor(0, fadeAmountA1, 0, (fadeAmountA1 / 10));         // Blink 1
          strip.setPixelColor(1, fadeAmountA1, 0, (fadeAmountA1 / 10));         // Blink 1

          showLEDS();


        }
        if (Blink1 == false)
        {

          maxBrightnessSet();
          showLEDS();

          //valueA2 = map(analogRead(A2), 0, 1024, 0, 10);
          pixel.setPixelColor(0, 0, 0, 0);         // Blink 2
          inner.setPixelColor(0, 0, 0, 0);         // Blink 2
          //for(int p=0; p<strip.numPixels(); p++) {         // For each pixel in strip...
          //      strip.setPixelColor(p, (valueA2/6), valueA2, valueA2);
          //}
          strip.setPixelColor(1, fadeAmountA1, 0, (fadeAmountA1 / 10));         // Blink 2
          strip.setPixelColor(1, 0, 0, 0);         // Blink 2
          strip.setPixelColor(2, 0, 0, 0);         // Blink 2

          showLEDS();
        }

      }
      else if (Mode == 2)   //  Double Trianglez
      {
        delay(0);

        trianglezCalcA1();
        trianglezCalcA2();

        // Update the brightness of each blink color depending on which Blink it is
        if (Blink1 == true)
        {

          maxBrightnessSet();
          showLEDS();

          valueA1 = map(analogRead(A1), 0, 1024, 0, 10);
          pixel.setPixelColor(0, fadeAmountA1, 0, (fadeAmountA1 / 10));         // Blink 1
          inner.setPixelColor(0, fadeAmountA1, 0, (fadeAmountA1 / 10));         // Blink 1
          //for(int p=0; p<strip.numPixels(); p++) {         // For each pixel in strip...
          //      strip.setPixelColor(p, valueA1, (valueA1/10), 0);
          //}
          strip.setPixelColor(0, fadeAmountA1, 0, (fadeAmountA1 / 10));         // Blink 1
          strip.setPixelColor(1, fadeAmountA1, 0, (fadeAmountA1 / 10));         // Blink 1

          showLEDS();


        }
        if (Blink1 == false)
        {

          maxBrightnessSet();
          showLEDS();

          valueA2 = map(analogRead(A2), 0, 1024, 0, 10);
          pixel.setPixelColor(0, (fadeAmountA2 / 6), 0, fadeAmountA2);         // Blink 2
          inner.setPixelColor(0, (fadeAmountA2 / 6), 0, fadeAmountA2);         // Blink 2
          //for(int p=0; p<strip.numPixels(); p++) {         // For each pixel in strip...
          //      strip.setPixelColor(p, (valueA2/6), valueA2, valueA2);
          //}
          strip.setPixelColor(1, fadeAmountA1, 0, (fadeAmountA1 / 10));         // Blink 2
          strip.setPixelColor(1, (fadeAmountA2 / 6), 0, fadeAmountA2);         // Blink 2
          strip.setPixelColor(2, (fadeAmountA2 / 6), 0, fadeAmountA2);         // Blink 2

          showLEDS();
        }

      }
      else
      {
        delay(0);
      };

        //Serial.println("Bank - " + String(Bank) + " Mode - " + String(Mode) + " fadeSpeeed: " + String(fadeSpeed));
        //controlsMax();
        //Serial.println("Count if Waiting = False: " + String(count));
    }
  }

  ////////////////////
  ////////////////////        BANK 3 - Rainbowz
  ////////////////////

  else if (Bank == 3)
  {
    int delayCountA0 = fadeSpeed;

    plotCycle();
    checkButtons();

    for (int count = 0; count <= delayCountA0; count++) {

      delayCountA0 = fadeSpeed;

      plotCycle();
      checkButtons();

      if (clicked == true) {

        //Serial.println("I Broke delayA0 Mode " + String(Mode) + " because button was clicked");
        breakdelayA0 = true;
        breakdelayA1 = true;
        breakdelayA2 = true;
        clicked = false;
        break;
        //count = 1;
        fadeSpeed = 0;
        fullDelay = 0;
        darkDelay = 0;
        randomAmount = 0;
        delayCountA0 = 0;

      }
      else {

      }

      if (breakdelayA0 == true)
      {
        Serial.println("I Broke delayA0 Because A0 was true");
        breakdelayA0 = false;
        break;

      }
      else {

      }

        // Potentiometer Top Right | A0 - Map the value of the Potentiometer to a Variable

      if (Mode == 1) {

        mapScaledA0();
        fadeSpeed = mapfloat(scaledA0, 0, 2300, speedMinimum, 0);

        //Serial.println("Mode 3 controlAmount: " + String(controlAmount));
        //Serial.println("Bank - " + String(Bank) + "Mode" + String(Mode) + "fadeSpeeed: " + String(fadeSpeed));
      }
      else if (Mode == 2) {

        mapScaledA0();
        fadeSpeed = mapfloat(scaledA0, 0, 2300, speedMinimum, 10);


        //Serial.println("Mode 3 controlAmount: " + String(controlAmount));
        //Serial.println("Bank - " + String(Bank) + "Mode" + String(Mode) + "fadeSpeeed: " + String(fadeSpeed));

      }
      else if (Mode == 3) {

        mapScaledA0();
        fadeSpeed = mapfloat(scaledA0, 0, 2300, speedMinimum, 10);

        //Serial.println("Mode 3 controlAmount: " + String(controlAmount));
        //Serial.println("Bank - " + String(Bank) + "Mode" + String(Mode) + "fadeSpeeed: " + String(fadeSpeed));
      }
      else if (Mode == 4) {

        mapScaledA0();
        fadeSpeed = mapfloat(scaledA0, 0, 2300, speedMinimum, 10);

        //Serial.println("Mode 3 controlAmount: " + String(controlAmount));
        //Serial.println("Bank - " + String(Bank) + "Mode" + String(Mode) + "fadeSpeeed: " + String(fadeSpeed));
      }
      else if (Mode == 5) {

        mapScaledA0();
        fadeSpeed = mapfloat(scaledA0, 0, 2300, speedMinimum, 10);

        //Serial.println("Mode 3 controlAmount: " + String(controlAmount));
        //Serial.println("Bank - " + String(Bank) + "Mode" + String(Mode) + "fadeSpeeed: " + String(fadeSpeed));
      }
      else if (Mode == 6) {

        mapScaledA0();
        fadeSpeed = mapfloat(scaledA0, 0, 2300, speedMinimum, 10);

        //Serial.println("Mode 3 controlAmount: " + String(controlAmount));
        //Serial.println("Bank - " + String(Bank) + "Mode" + String(Mode) + "fadeSpeeed: " + String(fadeSpeed));
      }
      else if (Mode == 7) {

        mapScaledA0();
        fadeSpeed = mapfloat(scaledA0, 0, 2300, speedMinimum, 10);

        //Serial.println("Mode 3 controlAmount: " + String(controlAmount));
        //Serial.println("Bank - " + String(Bank) + "Mode" + String(Mode) + "fadeSpeeed: " + String(fadeSpeed));
      }
      else if (Mode == 8) {

        //valueA0 = map(analogRead(A0), 0, 1024, 2000, 0);
        valueA0 = log(analogRead(A0) + 1) / log(1024) * 255;
        modulateConstrain = modulateSpeed + (valueA0 - 200);
        fadeSpeed = constrain(modulateConstrain, 0, 3000);
        //fadeSpeed = map(analogRead(A0), 0, 1024, durationMaximum, 0);
        //ModulateControl();
        //fadeSpeed = fadeSpeed;

        //Serial.println("delayA0 fadeSpeeed: " + String(fadeSpeed));
      }
      else if (Mode == 9) {

        //valueA0 = map(analogRead(A0), 0, 1024, 2000, 0);
        valueA0 = log(analogRead(A0) + 1) / log(1024) * 255;
        modulateConstrain = modulateSpeed + (valueA0 - 200);
        fadeSpeed = constrain(modulateConstrain, 0, 3000);
        //fadeSpeed = map(analogRead(A0), 0, 1024, durationMaximum, 0);
        //ModulateControl();
        //fadeSpeed = fadeSpeed;

        //Serial.println("delayA0 fadeSpeeed: " + String(fadeSpeed));
      }
      else if (Mode == 10) {

        mapScaledA0();
        fadeSpeed = mapfloat(scaledA0, 0, 2300, speedMinimum, 0);

        //Serial.println("Mode 2 controlAmount: " + String(controlAmount));
        //Serial.println("Mode 2 fadeSpeeed: " + String(fadeSpeed));

      }
      else {
        fadeSpeed = 7;
        //Serial.println("Else fadeSpeeed: " + String(fadeSpeed));
      }

        //Make this number smaller to fade faster
      if (Mode == 3)
      {
        delay(1);
      }
      else
      {
        delay(.5);
      }

        //Serial.println("Bank - " + String(Bank) + " Mode - " + String(Mode) + " fadeSpeeed: " + String(fadeSpeed));
        //controlsMax();
        //Serial.println("Count if Waiting = False: " + String(count));
    }
  }

  ////////////////////
  ////////////////////        BANK 4 - Naturez
  ////////////////////

  else if (Bank == 4)
  {
    int delayCountA0 = fadeSpeed;

    plotCycle();
    checkButtons();

    for (int count = 0; count <= delayCountA0; count++) {

      delayCountA0 = fadeSpeed;

      plotCycle();
      checkButtons();

      if (clicked == true) {

        //Serial.println("I Broke delayA0 Mode " + String(Mode) + " because button was clicked");
        breakdelayA0 = true;
        breakdelayA1 = true;
        breakdelayA2 = true;
        clicked = false;
        break;
        //count = 1;
        fadeSpeed = 0;
        fullDelay = 0;
        darkDelay = 0;
        randomAmount = 0;
        delayCountA0 = 0;

      }
      else {

      }

      if (breakdelayA0 == true)
      {
        //Serial.println("I Broke delayA0 Because A0 was true");
        breakdelayA0 = false;
        break;

      }
      else {

      }

        // Potentiometer Top Right | A0 - Map the value of the Potentiometer to a Variable

      if (Mode == 1) {

        mapScaledA0();
        fadeSpeed = mapfloat(scaledA0, 0, 2300, speedMinimum, 10);

        //Serial.println("Mode 3 controlAmount: " + String(controlAmount));
        //Serial.println("Bank - " + String(Bank) + "Mode" + String(Mode) + "fadeSpeeed: " + String(fadeSpeed));
      }
      else if (Mode == 2) {

        mapScaledA0();
        fadeSpeed = mapfloat(scaledA0, 0, 2300, speedMinimum, 10);


        //Serial.println("Mode 3 controlAmount: " + String(controlAmount));
        //Serial.println("Bank - " + String(Bank) + "Mode" + String(Mode) + "fadeSpeeed: " + String(fadeSpeed));

      }
      else if (Mode == 3) {

        mapScaledA0();
        fadeSpeed = mapfloat(scaledA0, 0, 2300, speedMinimum, 10);

        //Serial.println("Mode 3 controlAmount: " + String(controlAmount));
        //Serial.println("Bank - " + String(Bank) + "Mode" + String(Mode) + "fadeSpeeed: " + String(fadeSpeed));
      }
      else if (Mode == 7) {

        valueLog = log(analogRead(A0) + 1) / log(1024) * 255;
        //Serial.println("Mode 1 valueLog: " + String(valueLog));
        fadeSpeed = mapfloat(valueLog, 0, 255, (speedMinimum / 2), 30);         // Logarithmic Potentiometer Value

        //fadeSpeed = map(analogRead(A0), 0, 1024, durationMaximum, 0);
        //Serial.println("Bank - " + String(Bank) + "Mode" + String(Mode) + "fadeSpeeed: " + String(fadeSpeed));
      }
      else if (Mode == 8) {

        //valueA0 = map(analogRead(A0), 0, 1024, 2000, 0);
        valueA0 = log(analogRead(A0) + 1) / log(1024) * 255;
        modulateConstrain = modulateSpeed + (valueA0 - 200);
        fadeSpeed = constrain(modulateConstrain, 0, 3000);
        //fadeSpeed = map(analogRead(A0), 0, 1024, durationMaximum, 0);
        //ModulateControl();
        //fadeSpeed = fadeSpeed;

        //Serial.println("delayA0 fadeSpeeed: " + String(fadeSpeed));
      }
      else if (Mode == 9) {

        //valueA0 = map(analogRead(A0), 0, 1024, 2000, 0);
        valueA0 = log(analogRead(A0) + 1) / log(1024) * 255;
        modulateConstrain = modulateSpeed + (valueA0 - 200);
        fadeSpeed = constrain(modulateConstrain, 0, 3000);
        //fadeSpeed = map(analogRead(A0), 0, 1024, durationMaximum, 0);
        //ModulateControl();
        //fadeSpeed = fadeSpeed;

        //Serial.println("delayA0 fadeSpeeed: " + String(fadeSpeed));
      }
      else if (Mode == 10) {

        mapScaledA0();
        fadeSpeed = mapfloat(scaledA0, 0, 2300, speedMinimum, 0);

        //Serial.println("Mode 2 controlAmount: " + String(controlAmount));
        //Serial.println("Mode 2 fadeSpeeed: " + String(fadeSpeed));

      }
      else {
        fadeSpeed = 7;
        //Serial.println("Else fadeSpeeed: " + String(fadeSpeed));
      }

        //Make this number smaller to fade faster
      if (Mode == 3)
      {
        delay(1);
      }
      else
      {
        delay(.5);
      }

        //Serial.println("Bank - " + String(Bank) + " Mode - " + String(Mode) + " fadeSpeeed: " + String(fadeSpeed));
        //controlsMax();
        //Serial.println("Count if Waiting = False: " + String(count));
    }
  }

  ////////////////////
  ////////////////////        BANK 5 - Attractorz
  ////////////////////

  else if (Bank == 5)
  {
    int delayCountA0 = fadeSpeed;

    plotCycle();
    checkButtons();

    for (int count = 0; count <= delayCountA0; count++) {

      delayCountA0 = fadeSpeed;

      plotCycle();
      checkButtons();

      if (clicked == true) {

        //Serial.println("I Broke delayA0 Mode " + String(Mode) + " because button was clicked");
        breakdelayA0 = true;
        breakdelayA1 = true;
        breakdelayA2 = true;
        clicked = false;
        break;
        //count = 1;
        fadeSpeed = 0;
        fullDelay = 0;
        darkDelay = 0;
        randomAmount = 0;
        delayCountA0 = 0;

      }
      else {

      }

      if (breakdelayA0 == true)
      {
        //Serial.println("I Broke delayA0 Because A0 was true");
        breakdelayA0 = false;
        break;

      }
      else {

      }

        // Potentiometer Top Right | A0 - Map the value of the Potentiometer to a Variable

        mapScaledA0();
        fadeSpeed = mapfloat(scaledA0, 0, 2300, speedMinimum/ 10, 0);
        
        delay(.5);
      

        //Serial.println("Bank - " + String(Bank) + " Mode - " + String(Mode) + " fadeSpeeed: " + String(fadeSpeed));
        //controlsMax();
        //Serial.println("Count if Waiting = False: " + String(count));
    }
  }

  ////////////////////
  ////////////////////        BANK 5
  ////////////////////

  else if (Bank == 6)
  {
    int delayCountA0 = fadeSpeed;

    plotCycle();
    checkButtons();

    for (int count = 0; count <= delayCountA0; count++) {

      delayCountA0 = fadeSpeed;

      plotCycle();
      checkButtons();

      if (clicked == true) {

        //Serial.println("I Broke delayA0 Mode " + String(Mode) + " because button was clicked");
        breakdelayA0 = true;
        breakdelayA1 = true;
        breakdelayA2 = true;
        clicked = false;
        break;
        //count = 1;
        fadeSpeed = 0;
        fullDelay = 0;
        darkDelay = 0;
        randomAmount = 0;
        delayCountA0 = 0;

      }
      else {

      }

      if (breakdelayA0 == true)
      {
        //Serial.println("I Broke delayA0 Because A0 was true");
        breakdelayA0 = false;
        break;

      }
      else {

      }

        // Potentiometer Top Right | A0 - Map the value of the Potentiometer to a Variable

      if (Mode == 1) {

        mapScaledA0();
        fadeSpeed = mapfloat(scaledA0, 0, 2300, speedMinimum, 10);

        //Serial.println("Mode 3 controlAmount: " + String(controlAmount));
        //Serial.println("Bank - " + String(Bank) + "Mode" + String(Mode) + "fadeSpeeed: " + String(fadeSpeed));
      }
      else if (Mode == 2) {

        mapScaledA0();
        fadeSpeed = mapfloat(scaledA0, 0, 2300, speedMinimum, 10);


        //Serial.println("Mode 3 controlAmount: " + String(controlAmount));
        //Serial.println("Bank - " + String(Bank) + "Mode" + String(Mode) + "fadeSpeeed: " + String(fadeSpeed));

      }
      else if (Mode == 3) {

        mapScaledA0();
        fadeSpeed = mapfloat(scaledA0, 0, 2300, speedMinimum, 10);

        //Serial.println("Mode 3 controlAmount: " + String(controlAmount));
        //Serial.println("Bank - " + String(Bank) + "Mode" + String(Mode) + "fadeSpeeed: " + String(fadeSpeed));
      }
      else if (Mode == 7) {

        valueLog = log(analogRead(A0) + 1) / log(1024) * 255;
        //Serial.println("Mode 1 valueLog: " + String(valueLog));
        fadeSpeed = mapfloat(valueLog, 0, 255, (speedMinimum / 2), 30);         // Logarithmic Potentiometer Value

        //fadeSpeed = map(analogRead(A0), 0, 1024, durationMaximum, 0);
        //Serial.println("Bank - " + String(Bank) + "Mode" + String(Mode) + "fadeSpeeed: " + String(fadeSpeed));
      }
      else if (Mode == 8) {

        //valueA0 = map(analogRead(A0), 0, 1024, 2000, 0);
        valueA0 = log(analogRead(A0) + 1) / log(1024) * 255;
        modulateConstrain = modulateSpeed + (valueA0 - 200);
        fadeSpeed = constrain(modulateConstrain, 0, 3000);
        //fadeSpeed = map(analogRead(A0), 0, 1024, durationMaximum, 0);
        //ModulateControl();
        //fadeSpeed = fadeSpeed;

        //Serial.println("delayA0 fadeSpeeed: " + String(fadeSpeed));
      }
      else if (Mode == 9) {

        //valueA0 = map(analogRead(A0), 0, 1024, 2000, 0);
        valueA0 = log(analogRead(A0) + 1) / log(1024) * 255;
        modulateConstrain = modulateSpeed + (valueA0 - 200);
        fadeSpeed = constrain(modulateConstrain, 0, 3000);
        //fadeSpeed = map(analogRead(A0), 0, 1024, durationMaximum, 0);
        //ModulateControl();
        //fadeSpeed = fadeSpeed;

        //Serial.println("delayA0 fadeSpeeed: " + String(fadeSpeed));
      }
      else if (Mode == 10) {

        mapScaledA0();
        fadeSpeed = mapfloat(scaledA0, 0, 2300, speedMinimum, 0);

        //Serial.println("Mode 2 controlAmount: " + String(controlAmount));
        //Serial.println("Mode 2 fadeSpeeed: " + String(fadeSpeed));

      }
      else {
        fadeSpeed = 7;
        //Serial.println("Else fadeSpeeed: " + String(fadeSpeed));
      }

        //Make this number smaller to fade faster
      if (Mode == 3)
      {
        delay(1);
      }
      else
      {
        delay(.5);
      }

        //Serial.println("Bank - " + String(Bank) + " Mode - " + String(Mode) + " fadeSpeeed: " + String(fadeSpeed));
        //controlsMax();
        //Serial.println("Count if Waiting = False: " + String(count));
    }
  }
  else;

}
