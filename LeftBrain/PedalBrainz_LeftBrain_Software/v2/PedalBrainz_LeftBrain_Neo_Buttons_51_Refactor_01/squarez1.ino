
void Squarez_01()
{
      //Serial.println("Mode 1 controlAmount: " + String(controlAmount));
      //Serial.println("Mode 1 fadeSpeeed: " + String(fadeSpeed));
      //Serial.println("AM SQUAREZ");

            MaxBrightReduction = constrain(maxBrightness, 0, MaxBright);
            pixel.setBrightness(maxBrightness);
            strip.setBrightness(MaxBrightReduction);
            inner.setBrightness(maxBrightness);
            FastLED.setBrightness(MaxBrightReduction);
            showLEDS();

            //Serial.println("maxBrightness : " + String(maxBrightness));
            //Serial.println("MaxBright : " + String(MaxBright));
            //Serial.println("MaxBrightReduction : " + String(MaxBrightReduction));
      
        // Alternate between two different blink values
        Blink1 = true;
        valueA1 = map(analogRead(A1), 0, 1024, 0, 255);
        pixel.setPixelColor(0, valueA1, (valueA1/10), 0); // Blink 1
        inner.setPixelColor(0, valueA1, (valueA1/10), 0); // Blink 1
        //for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
        //      strip.setPixelColor(p, valueA1, (valueA1/10), 0);
        //}
        strip.setPixelColor(0, valueA1, (valueA1/10), 0); // Blink 1
        strip.setPixelColor(1, valueA1, (valueA1/10), 0); // Blink 1
        //strip.setPixelColor(2, 0, 0, 0); // Blink 1
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
        //pixel.setPixelColor(0, 0x000000); // Blank

        Blink1 = false;
        valueA2 = map(analogRead(A2), 0, 1024, 0, 255);
        pixel.setPixelColor(0, (valueA2/6), valueA2, valueA2); // Blink 2
        inner.setPixelColor(0, (valueA2/6), valueA2, valueA2); // Blink 2
        //for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
        //      strip.setPixelColor(p, (valueA2/6), valueA2, valueA2);
        //}
        //strip.setPixelColor(0, (valueA2/6), valueA2, valueA2); // Blink 2
        //strip.setPixelColor(1, valueA1, (valueA1/10), 0); // Blink 1
        //strip.setPixelColor(0, 0, 0, 0); // Blink 1
        strip.setPixelColor(1, (valueA2/6), valueA2, valueA2); // Blink 2
        strip.setPixelColor(2, (valueA2/6), valueA2, valueA2); // Blink 2
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
