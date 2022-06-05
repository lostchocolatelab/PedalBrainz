/**

      Squarez Mode

*/


void Squarez_01()
{
      //Serial.println("Mode 1 controlAmount: " + String(controlAmount));
      //Serial.println("Mode 1 fadeSpeeed: " + String(fadeSpeed));
      //Serial.println("AM SQUAREZ");

      maxBrightnessSet();

      //Serial.println("maxBrightness : " + String(maxBrightness));
      //Serial.println("MaxBright : " + String(MaxBright));
      //Serial.println("MaxBrightReduction : " + String(MaxBrightReduction));

  ////////////////////
  ////////////////////        Blink 1
  ////////////////////

      // Alternate between two different blink values
      Blink1 = true;
      valueA1 = map(analogRead(A1), 0, 1024, 0, 255);
      valueA2 = map(analogRead(A2), 0, 1024, 0, 255);
      pixel.setPixelColor(0, valueA1, (valueA1 / 10), 0);       // Blink 1
      inner.setPixelColor(0, valueA1, (valueA1 / 10), 0);       // Blink 1
      //for(int p=0; p<strip.numPixels(); p++) {       // For each pixel in strip...
      //      strip.setPixelColor(p, valueA1, (valueA1/10), 0);
      //}
      strip.setPixelColor(0, valueA1, (valueA1 / 10), 0);       // Blink 1
      strip.setPixelColor(1, valueA1, (valueA1 / 10), 0);       // Blink 1
      strip.setPixelColor(2, (valueA2 / 6), valueA2, valueA2);       // Blink 2
      //pixel.setBrightness(maxBrightness);
      //strip.setBrightness(MaxBright);
      //inner.setBrightness(MaxBright);
      pixel.show();
      strip.show();
      inner.show();

      delayA0(fadeSpeed);
      currentVal = valueA1;
      plotCycle();
      checkButtons();
      //pixel.setPixelColor(0, 0x000000);       // Blank

  ////////////////////
  ////////////////////        Blink 2
  ////////////////////

      Blink1 = false;
      valueA1 = map(analogRead(A1), 0, 1024, 0, 255);
      valueA2 = map(analogRead(A2), 0, 1024, 0, 255);
      pixel.setPixelColor(0, (valueA2 / 6), valueA2, valueA2);       // Blink 2
      inner.setPixelColor(0, (valueA2 / 6), valueA2, valueA2);       // Blink 2
      //for(int p=0; p<strip.numPixels(); p++) {       // For each pixel in strip...
      //      strip.setPixelColor(p, (valueA2/6), valueA2, valueA2);
      //}
      //strip.setPixelColor(0, (valueA2/6), valueA2, valueA2);       // Blink 2
      strip.setPixelColor(0, valueA1, (valueA1 / 10), 0);       // Blink 1
      //strip.setPixelColor(0, 0, 0, 0);       // Blink 1
      strip.setPixelColor(1, (valueA2 / 6), valueA2, valueA2);       // Blink 2
      strip.setPixelColor(2, (valueA2 / 6), valueA2, valueA2);       // Blink 2
      //pixel.setBrightness(maxBrightness);
      //strip.setBrightness(MaxBright);
      //inner.setBrightness(MaxBright);
      pixel.show();
      strip.show();
      inner.show();

      delayA0(fadeSpeed);
      currentVal = valueA2;
      plotCycle();
      checkButtons();
}


void Squarez_02()   //  Double Trianglez
{
      //Serial.println("Mode 1 controlAmount: " + String(controlAmount));
      //Serial.println("Mode 1 fadeSpeeed: " + String(fadeSpeed));
      //Serial.println("AM SQUAREZ");

      maxBrightnessSet();

      //Serial.println("maxBrightness : " + String(maxBrightness));
      //Serial.println("MaxBright : " + String(MaxBright));
      //Serial.println("MaxBrightReduction : " + String(MaxBrightReduction));


      //  trianglezCalcA1();
      //  trianglezCalcA2();

  ////////////////////
  ////////////////////        Blink 1
  ////////////////////

      // Alternate between two different blink values
      Blink1 = true;
      //valueA1 = map(analogRead(A1), 0, 1024, 0, 255);
      pixel.setPixelColor(0, fadeAmountA1, 0, (fadeAmountA1 / 10));       // Blink 1
      inner.setPixelColor(0, fadeAmountA1, 0, (fadeAmountA1 / 10));       // Blink 1
      //for(int p=0; p<strip.numPixels(); p++) {       // For each pixel in strip...
      //      strip.setPixelColor(p, valueA1, (valueA1/10), 0);
      //}
      strip.setPixelColor(0, fadeAmountA1, 0, (fadeAmountA1 / 10));       // Blink 1
      strip.setPixelColor(1, fadeAmountA1, 0, (fadeAmountA1 / 10));       // Blink 1
      //strip.setPixelColor(2, 0, 0, 0);       // Blink 1
      //pixel.setBrightness(maxBrightness);
      //strip.setBrightness(MaxBright);
      //inner.setBrightness(MaxBright);
      pixel.show();
      strip.show();
      inner.show();

      delayA0(fadeSpeed);
      //currentVal = fadeAmountA1;
      plotCycle();
      checkButtons();
      //pixel.setPixelColor(0, 0x000000);       // Blank

  ////////////////////
  ////////////////////        Blink 2
  ////////////////////

      Blink1 = false;
      //valueA2 = map(analogRead(A2), 0, 1024, 0, 255);
      pixel.setPixelColor(0, (fadeAmountA2 / 6), 0, fadeAmountA2);       // Blink 2
      inner.setPixelColor(0, (fadeAmountA2 / 6), 0, fadeAmountA2);       // Blink 2
      //for(int p=0; p<strip.numPixels(); p++) {       // For each pixel in strip...
      //      strip.setPixelColor(p, (valueA2/6), valueA2, valueA2);
      //}
      //strip.setPixelColor(0, (valueA2/6), valueA2, valueA2);       // Blink 2
      //strip.setPixelColor(1, valueA1, (valueA1/10), 0);       // Blink 1
      //strip.setPixelColor(0, 0, 0, 0);       // Blink 1
      strip.setPixelColor(1, (fadeAmountA2 / 6), 0, fadeAmountA2);       // Blink 2
      strip.setPixelColor(2, (fadeAmountA2 / 6), 0, fadeAmountA2);       // Blink 2
      //pixel.setBrightness(maxBrightness);
      //strip.setBrightness(MaxBright);
      //inner.setBrightness(MaxBright);
      pixel.show();
      strip.show();
      inner.show();

      delayA0(fadeSpeed);
      //currentVal = fadeAmountA2;
      plotCycle();
      checkButtons();
}

void Squarez_03()   //  Squarez Controlled
{
      //Serial.println("Mode 1 controlAmount: " + String(controlAmount));
      //Serial.println("Mode 1 fadeSpeeed: " + String(fadeSpeed));
      //Serial.println("AM SQUAREZ");

      maxBrightnessSet();
      fadeAmountA1 = 255;

      //Serial.println("maxBrightness : " + String(maxBrightness));
      //Serial.println("MaxBright : " + String(MaxBright));
      //Serial.println("MaxBrightReduction : " + String(MaxBrightReduction));


      //  trianglezCalcA1();
      //  trianglezCalcA2();

  ////////////////////
  ////////////////////        Blink 1
  ////////////////////

      // Alternate between two different blink values
      Blink1 = true;
      //valueA1 = map(analogRead(A1), 0, 1024, 0, 255);
      pixel.setPixelColor(0, fadeAmountA1, 0, (fadeAmountA1 / 10));       // Blink 1
      inner.setPixelColor(0, fadeAmountA1, 0, (fadeAmountA1 / 10));       // Blink 1
      //for(int p=0; p<strip.numPixels(); p++) {       // For each pixel in strip...
      //      strip.setPixelColor(p, valueA1, (valueA1/10), 0);
      //}
      strip.setPixelColor(0, fadeAmountA1, 0, (fadeAmountA1 / 10));       // Blink 1
      strip.setPixelColor(1, fadeAmountA1, 0, (fadeAmountA1 / 10));       // Blink 1
      //strip.setPixelColor(2, 0, 0, 0);       // Blink 1
      //pixel.setBrightness(maxBrightness);
      //strip.setBrightness(MaxBright);
      //inner.setBrightness(MaxBright);
      pixel.show();
      strip.show();
      inner.show();

      delayA1(fullDelay);
      //currentVal = fadeAmountA1;
      plotCycle();
      checkButtons();
      
      delayA0(fadeSpeed);

  ////////////////////
  ////////////////////        Blink 2
  ////////////////////

      Blink1 = false;
      //valueA2 = map(analogRead(A2), 0, 1024, 0, 255);
      pixel.setPixelColor(0, 0, 0, 0);       // Blink 2
      inner.setPixelColor(0, 0, 0, 0);       // Blink 2
      //for(int p=0; p<strip.numPixels(); p++) {       // For each pixel in strip...
      //      strip.setPixelColor(p, (valueA2/6), valueA2, valueA2);
      //}
      //strip.setPixelColor(0, (valueA2/6), valueA2, valueA2);       // Blink 2
      //strip.setPixelColor(1, valueA1, (valueA1/10), 0);       // Blink 1
      //strip.setPixelColor(0, 0, 0, 0);       // Blink 1
      strip.setPixelColor(1, 0, 0, 0);       // Blink 2
      strip.setPixelColor(2, 0, 0, 0);       // Blink 2
      //pixel.setBrightness(maxBrightness);
      //strip.setBrightness(MaxBright);
      //inner.setBrightness(MaxBright);
      pixel.show();
      strip.show();
      inner.show();

      delayA2(darkDelay);
      //currentVal = fadeAmountA2;
      plotCycle();
      checkButtons();

      delayA0(fadeSpeed);
}


