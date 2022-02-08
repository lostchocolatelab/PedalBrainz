/**

  A0 Delay - Fade Speed

*/


void delayA0(int count)
{

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

      //controlAmount = map(analogRead(A0), 0, 1024, 0, 100);
      //valueLog = log(analogRead(A0)+1)/log(1024)*255;
      //Serial.println("Mode 1 valueLog: " + String(valueLog));
      //fadeSpeed = map(valueLog, 0, 255, (speedMinimum), (40/2)); // Logarithmic Potentiometer Value
      //fadeSpeed = map(valueLog, 0, 255, (speedMinimum/2), (40/2)); // Logarithmic Potentiometer Value

      // This makes the potentiometer slower to change when reducting from full and gives better control fidelity at higher speeds
      // This is a map of values for the potentiometer. note: the in array should have increasing values
      int in[]  = {0, 25.5,51,76.5,102,127.5,153,178.5,204,229.5,255};
      // This is a map of values for potentiometer curve type.
      int out[] = { 2300,2298,2296,2295,2292,2200,2100,2000,1800,1300,0 };  // 11
      // This maps the potentiometer scale.
      controlAmount  = map(analogRead(A0), 0, 1024, 255, 0);
      // This is a multimap that assigns values from the [in] array (potentiometer) to values from the [out] array (curve)
      x = multiMap(controlAmount, in, out, 11);
      // This maps the values for the Modez.
      fadeSpeed = map(x, 0, 2300, speedMinimum, 100);
      
      //Serial.println("Mode 1 controlAmount: " + String(controlAmount));
      //Serial.println("Mode 1 fadeSpeeed: " + String(fadeSpeed));


      valueA1 = map(analogRead(A1), 0, 1024, 0, 90);
      valueA2 = map(analogRead(A2), 0, 1024, 0, 90);
    }
    // Potentiometer Top Right | A0 - Map the value of the Potentiometer to a Variable
    else if (Mode == 2) {
      //valueLog = log(analogRead(A0)+1)/log(1024)*255;
      //Serial.println("Mode 1 valueLog: " + String(valueLog));
      //fadeSpeed = map(valueLog, 0, 255, (speedMinimum/2), (0/2)); // Logarithmic Potentiometer Value
      //fadeSpeed = map(analogRead(A0), 0, 1024, speedMinimum, 0); // Linear Potentiometer Value

      // This makes the potentiometer slower to change when reducting from full and gives better control fidelity at higher speeds
      // This is a map of values for the potentiometer. note: the in array should have increasing values
      int in[]  = {0, 25.5,51,76.5,102,127.5,153,178.5,204,229.5,255};
      // This is a map of values for potentiometer curve type.
      int out[] = { 2300,2298,2296,2295,2292,2200,2100,2000,1800,1300,0 };  // 11
      // This maps the potentiometer scale.
      controlAmount  = map(analogRead(A0), 0, 1024, 255, 0);
      // This is a multimap that assigns values from the [in] array (potentiometer) to values from the [out] array (curve)
      x = multiMap(controlAmount, in, out, 11);
      // This maps the values for the Modez.
      fadeSpeed = map(x, 0, 2300, speedMinimum, 0);
      
      //Serial.println("Mode 2 controlAmount: " + String(controlAmount));
      //Serial.println("Mode 2 fadeSpeeed: " + String(fadeSpeed));

    }
    
    else if (Mode == 3) {
      //Serial.println("Delay Value A0: " + String(delayValueA0));
      //Serial.println("Delay Random (ms) A0: " + String(randomAmountA0));
      //Serial.println("Mode 2 fadeSpeeed: " + String(fadeSpeed));

      // This makes the potentiometer slower to change when reducting from full and gives better control fidelity at higher speeds
      // This is a map of values for the potentiometer. note: the in array should have increasing values
      int in[]  = {0, 25.5,51,76.5,102,127.5,153,178.5,204,229.5,255};
      // This is a map of values for potentiometer curve type.
      int out[] = { 2300,2298,2296,2295,2292,2200,2100,2000,1800,1300,0 };  // 11
      // This maps the potentiometer scale.
      controlAmount  = map(analogRead(A0), 0, 1024, 255, 0);
      // This is a multimap that assigns values from the [in] array (potentiometer) to values from the [out] array (curve)
      x = multiMap(controlAmount, in, out, 11);
      // This maps the values for the Modez.
      fadeSpeed = map(x, 0, 2300, speedMinimum, 0);
      
      //Serial.println("Mode 3 controlAmount: " + String(controlAmount));
      //Serial.println("Mode 3 fadeSpeeed: " + String(fadeSpeed));
      
    }
    else if (Mode == 4) {

      //fadeSpeed = map(analogRead(A0), 0, 1024, (speedMinimum/10), -1);
      //Serial.println("Mode 4 fadeSpeeed: " + String(fadeSpeed));

      // This makes the potentiometer slower to change when reducting from full and gives better control fidelity at higher speeds
      // This is a map of values for the potentiometer. note: the in array should have increasing values
      int in[]  = {0, 25.5,51,76.5,102,127.5,153,178.5,204,229.5,255};
      // This is a map of values for potentiometer curve type.
      int out[] = { 2300,2280,2270,2260,2250,2200,2100,2000,1500,1000,0 };  // 11
      // This maps the potentiometer scale.
      controlAmount  = map(analogRead(A0), 0, 1024, 255, 0);
      // This is a multimap that assigns values from the [in] array (potentiometer) to values from the [out] array (curve)
      x = multiMap(controlAmount, in, out, 11);
      // This maps the values for the Modez.
      fadeSpeed = map(x, 0, 2300, speedMinimum/10, -1);

      //Serial.println("Mode 4 controlAmount: " + String(controlAmount));
      //Serial.println("Mode 4 fadeSpeeed: " + String(fadeSpeed));
          
      
    }
    else if (Mode == 5) {

      //fadeSpeed = map(analogRead(A0), 0, 1024, (speedMinimum/10), -1);
      //Serial.println("Mode 5 fadeSpeeed: " + String(fadeSpeed));

      
      // This makes the potentiometer slower to change when reducting from full and gives better control fidelity at higher speeds
      // This is a map of values for the potentiometer. note: the in array should have increasing values
      int in[]  = {0, 25.5,51,76.5,102,127.5,153,178.5,204,229.5,255};
      // This is a map of values for potentiometer curve type.
      int out[] = { 2300,2280,2270,2260,2250,2200,2100,2000,1500,1000,0 };  // 11
      // This maps the potentiometer scale.
      controlAmount  = map(analogRead(A0), 0, 1024, 255, 0);
      // This is a multimap that assigns values from the [in] array (potentiometer) to values from the [out] array (curve)
      x = multiMap(controlAmount, in, out, 11);
      // This maps the values for the Modez.
      fadeSpeed = map(x, 0, 2300, speedMinimum/10, -1);

      //Serial.println("Mode 5 controlAmount: " + String(controlAmount));
      //Serial.println("Mode 5 fadeSpeeed: " + String(fadeSpeed));
      
    }
    else if (Mode == 8) {

      fadeSpeed = map(analogRead(A0), 0, 1024, (speedMinimum/10), 0);

      //Serial.println("Mode 8 fadeSpeeed: " + String(fadeSpeed));
      
    }    
    else if (Mode == 9) {

      fadeSpeed = map(analogRead(A0), 0, 1024, (speedMinimum/10), 0);

      //Serial.println("Mode 9 fadeSpeeed: " + String(fadeSpeed));
      
    }
    else if (Mode == 10) {

      fadeSpeed = map(analogRead(A0), 0, 1024, (speedMinimum/10), 0);

      //Serial.println("Mode 10 fadeSpeeed: " + String(fadeSpeed));
      
    }
    else {
      fadeSpeed = 7;
      //Serial.println("Else fadeSpeeed: " + String(fadeSpeed));
    }

        //Make this number smaller to fade faster
    if (Mode == 1)
    {
      delay(0);

      // Update the brightness of each blink color depending on which Blink it is
      if (Blink1 == true) 
      {
        valueA1 = map(analogRead(A1), 0, 1024, 0, 255);
        pixel.setPixelColor(0, valueA1, (valueA1/10), 0); // Blink 1
        inner.setPixelColor(0, valueA1, (valueA1/10), 0); // Blink 1
        //for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
        //      strip.setPixelColor(p, valueA1, (valueA1/10), 0);
        //}
        strip.setPixelColor(0, valueA1, (valueA1/10), 0); // Blink 1
        strip.setPixelColor(1, valueA1, (valueA1/10), 0); // Blink 1
        pixel.setBrightness(maxBrightness);
        strip.setBrightness(MaxBright);
        inner.setBrightness(MaxBright);
        pixel.show();
        strip.show();
        inner.show();
        
        
      }
      if (Blink1 == false) 
      {
        valueA2 = map(analogRead(A2), 0, 1024, 0, 255);
        pixel.setPixelColor(0, (valueA2/6), valueA2, valueA2); // Blink 2
        inner.setPixelColor(0, (valueA2/6), valueA2, valueA2); // Blink 2
        //for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
        //      strip.setPixelColor(p, (valueA2/6), valueA2, valueA2);
        //}
        strip.setPixelColor(1, valueA1, (valueA1/10), 0); // Blink 1
        strip.setPixelColor(1, (valueA2/6), valueA2, valueA2); // Blink 2
        strip.setPixelColor(2, (valueA2/6), valueA2, valueA2); // Blink 2        
        pixel.setBrightness(maxBrightness);
        strip.setBrightness(MaxBright);
        inner.setBrightness(MaxBright);
        pixel.show();
        strip.show();
        inner.show();
      }
      //pixel.show();
      //strip.show();
      
    }
    else
    {
      delay(.5);
    }
    
    checkButtons();

    //Serial.println("Bank - " + String(Bank) + " Mode - " + String(Mode) + " fadeSpeeed: " + String(fadeSpeed)); 
    
    //controlsMax();
    //Serial.println("Count if Waiting = False: " + String(count));
  }
  }
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
              //valueLog = log(analogRead(A0)+1)/log(1024)*255;
              //Serial.println("Mode 1 valueLog: " + String(valueLog));
              //fadeSpeed = map(valueLog, 0, 255, (speedMinimum/2), (40/2)); // Logarithmic Potentiometer Value
              //fadeSpeed = map(analogRead(A0), 0, 1024, durationMaximum, 0);
        
              // This makes the potentiometer slower to change when reducting from full and gives better control fidelity at higher speeds
              // This is a map of values for the potentiometer. note: the in array should have increasing values
              int in[]  = {0, 25.5,51,76.5,102,127.5,153,178.5,204,229.5,255};
              // This is a map of values for potentiometer curve type.
              int out[] = { 2300,2298,2296,2295,2292,2200,2100,2000,1800,1300,0 };  // 11
              // This maps the potentiometer scale.
              controlAmount  = map(analogRead(A0), 0, 1024, 255, 0);
              // This is a multimap that assigns values from the [in] array (potentiometer) to values from the [out] array (curve)
              x = multiMap(controlAmount, in, out, 11);
              // This maps the values for the Modez.
              fadeSpeed = map(x, 0, 2300, speedMinimum, 10);
              
        
              //Serial.println("Mode 3 controlAmount: " + String(controlAmount));
              //Serial.println("Bank - " + String(Bank) + "Mode" + String(Mode) + "fadeSpeeed: " + String(fadeSpeed));    
            }
            else if (Mode == 2) {
              //valueLog = log(analogRead(A0)+1)/log(1024)*255;
              //Serial.println("Mode 1 valueLog: " + String(valueLog));
              //fadeSpeed = map(valueLog, 0, 255, (speedMinimum/2), (40/2)); // Logarithmic Potentiometer Value
              //fadeSpeed = map(analogRead(A0), 0, 1024, durationMaximum, 0);
        
              // This makes the potentiometer slower to change when reducting from full and gives better control fidelity at higher speeds
              // This is a map of values for the potentiometer. note: the in array should have increasing values
              int in[]  = {0, 25.5,51,76.5,102,127.5,153,178.5,204,229.5,255};
              // This is a map of values for potentiometer curve type.
              int out[] = { 2300,2298,2296,2295,2292,2200,2100,2000,1800,1300,0 };  // 11
              // This maps the potentiometer scale.
              controlAmount  = map(analogRead(A0), 0, 1024, 255, 0);
              // This is a multimap that assigns values from the [in] array (potentiometer) to values from the [out] array (curve)
              x = multiMap(controlAmount, in, out, 11);
              // This maps the values for the Modez.
              fadeSpeed = map(x, 0, 2300, speedMinimum, 10);
              
        
              //Serial.println("Mode 3 controlAmount: " + String(controlAmount));
              //Serial.println("Bank - " + String(Bank) + "Mode" + String(Mode) + "fadeSpeeed: " + String(fadeSpeed));  
        
            }
            else if (Mode == 3) {
              //valueLog = log(analogRead(A0)+1)/log(1024)*255;
              //Serial.println("Mode 1 valueLog: " + String(valueLog));
              //fadeSpeed = map(valueLog, 0, 255, (speedMinimum/2), (40/2)); // Logarithmic Potentiometer Value
              //fadeSpeed = map(analogRead(A0), 0, 1024, durationMaximum, 0);
        
              // This makes the potentiometer slower to change when reducting from full and gives better control fidelity at higher speeds
              // This is a map of values for the potentiometer. note: the in array should have increasing values
              int in[]  = {0, 25.5,51,76.5,102,127.5,153,178.5,204,229.5,255};
              // This is a map of values for potentiometer curve type.
              int out[] = { 2300,2298,2296,2295,2292,2200,2100,2000,1800,1300,0 };  // 11
              // This maps the potentiometer scale.
              controlAmount  = map(analogRead(A0), 0, 1024, 255, 0);
              // This is a multimap that assigns values from the [in] array (potentiometer) to values from the [out] array (curve)
              x = multiMap(controlAmount, in, out, 11);
              // This maps the values for the Modez.
              fadeSpeed = map(x, 0, 2300, speedMinimum, 10);
              
        
              //Serial.println("Mode 3 controlAmount: " + String(controlAmount));
              //Serial.println("Bank - " + String(Bank) + "Mode" + String(Mode) + "fadeSpeeed: " + String(fadeSpeed)); 
        
            }
            else if (Mode == 7) {
              valueLog = log(analogRead(A0)+1)/log(1024)*255;
              //Serial.println("Mode 1 valueLog: " + String(valueLog));
              fadeSpeed = map(valueLog, 0, 255, (speedMinimum/2), 30); // Logarithmic Potentiometer Value
              //fadeSpeed = map(analogRead(A0), 0, 1024, durationMaximum, 0);
        
              //Serial.println("Bank - " + String(Bank) + "Mode" + String(Mode) + "fadeSpeeed: " + String(fadeSpeed)); 
        
            }    
            else if (Mode == 8) {
              //valueA0 = map(analogRead(A0), 0, 1024, 2000, 0);
              valueA0 = log(analogRead(A0)+1)/log(1024)*255;
              modulateConstrain = modulateSpeed + (valueA0-200);
              fadeSpeed = constrain(modulateConstrain, 0, 3000);
              //fadeSpeed = map(analogRead(A0), 0, 1024, durationMaximum, 0);
              //ModulateControl();
              //fadeSpeed = fadeSpeed;
              
              //Serial.println("delayA0 fadeSpeeed: " + String(fadeSpeed));
            }  
            else if (Mode == 9) {
              //valueA0 = map(analogRead(A0), 0, 1024, 2000, 0);
              valueA0 = log(analogRead(A0)+1)/log(1024)*255;
              modulateConstrain = modulateSpeed + (valueA0-200);
              fadeSpeed = constrain(modulateConstrain, 0, 3000);
              //fadeSpeed = map(analogRead(A0), 0, 1024, durationMaximum, 0);
              //ModulateControl();
              //fadeSpeed = fadeSpeed;
              
              //Serial.println("delayA0 fadeSpeeed: " + String(fadeSpeed));
            }  
            else if (Mode == 10) {
            //valueLog = log(analogRead(A0)+1)/log(1024)*255;
            //Serial.println("Mode 1 valueLog: " + String(valueLog));
            //fadeSpeed = map(valueLog, 0, 255, (speedMinimum/2), (0/2)); // Logarithmic Potentiometer Value
            //fadeSpeed = map(analogRead(A0), 0, 1024, speedMinimum, 0); // Linear Potentiometer Value
      
            // This makes the potentiometer slower to change when reducting from full and gives better control fidelity at higher speeds
            // This is a map of values for the potentiometer. note: the in array should have increasing values
            int in[]  = {0, 25.5,51,76.5,102,127.5,153,178.5,204,229.5,255};
            // This is a map of values for potentiometer curve type.
            int out[] = { 2300,2298,2296,2295,2292,2200,2100,2000,1800,1300,0 };  // 11
            // This maps the potentiometer scale.
            controlAmount  = map(analogRead(A0), 0, 1024, 255, 0);
            // This is a multimap that assigns values from the [in] array (potentiometer) to values from the [out] array (curve)
            x = multiMap(controlAmount, in, out, 11);
            // This maps the values for the Modez.
            fadeSpeed = map(x, 0, 2300, speedMinimum, 0);
            
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
              //Serial.println("I Broke delayA0 Because A0 was true");
              breakdelayA0 = false;
              break;
              
            }
            else {
              
            }
            
            // Potentiometer Top Right | A0 - Map the value of the Potentiometer to a Variable
       
            if (Mode == 1) {
              //valueLog = log(analogRead(A0)+1)/log(1024)*255;
              //Serial.println("Mode 1 valueLog: " + String(valueLog));
              //fadeSpeed = map(valueLog, 0, 255, (speedMinimum/2), (40/2)); // Logarithmic Potentiometer Value
              //fadeSpeed = map(analogRead(A0), 0, 1024, durationMaximum, 0);
        
              // This makes the potentiometer slower to change when reducting from full and gives better control fidelity at higher speeds
              // This is a map of values for the potentiometer. note: the in array should have increasing values
              int in[]  = {0, 25.5,51,76.5,102,127.5,153,178.5,204,229.5,255};
              // This is a map of values for potentiometer curve type.
              int out[] = { 2300,2298,2296,2295,2292,2200,2100,2000,1800,1300,0 };  // 11
              // This maps the potentiometer scale.
              controlAmount  = map(analogRead(A0), 0, 1024, 255, 0);
              // This is a multimap that assigns values from the [in] array (potentiometer) to values from the [out] array (curve)
              x = multiMap(controlAmount, in, out, 11);
              // This maps the values for the Modez.
              fadeSpeed = map(x, 0, 2300, speedMinimum, 10);
              
        
              //Serial.println("Mode 3 controlAmount: " + String(controlAmount));
              //Serial.println("Bank - " + String(Bank) + "Mode" + String(Mode) + "fadeSpeeed: " + String(fadeSpeed));    
            }
            else if (Mode == 2) {
              //valueLog = log(analogRead(A0)+1)/log(1024)*255;
              //Serial.println("Mode 1 valueLog: " + String(valueLog));
              //fadeSpeed = map(valueLog, 0, 255, (speedMinimum/2), (40/2)); // Logarithmic Potentiometer Value
              //fadeSpeed = map(analogRead(A0), 0, 1024, durationMaximum, 0);
        
              // This makes the potentiometer slower to change when reducting from full and gives better control fidelity at higher speeds
              // This is a map of values for the potentiometer. note: the in array should have increasing values
              int in[]  = {0, 25.5,51,76.5,102,127.5,153,178.5,204,229.5,255};
              // This is a map of values for potentiometer curve type.
              int out[] = { 2300,2298,2296,2295,2292,2200,2100,2000,1800,1300,0 };  // 11
              // This maps the potentiometer scale.
              controlAmount  = map(analogRead(A0), 0, 1024, 255, 0);
              // This is a multimap that assigns values from the [in] array (potentiometer) to values from the [out] array (curve)
              x = multiMap(controlAmount, in, out, 11);
              // This maps the values for the Modez.
              fadeSpeed = map(x, 0, 2300, speedMinimum, 10);
              
        
              //Serial.println("Mode 3 controlAmount: " + String(controlAmount));
              //Serial.println("Bank - " + String(Bank) + "Mode" + String(Mode) + "fadeSpeeed: " + String(fadeSpeed));  
        
            }
            else if (Mode == 3) {
              //valueLog = log(analogRead(A0)+1)/log(1024)*255;
              //Serial.println("Mode 1 valueLog: " + String(valueLog));
              //fadeSpeed = map(valueLog, 0, 255, (speedMinimum/2), (40/2)); // Logarithmic Potentiometer Value
              //fadeSpeed = map(analogRead(A0), 0, 1024, durationMaximum, 0);
        
              // This makes the potentiometer slower to change when reducting from full and gives better control fidelity at higher speeds
              // This is a map of values for the potentiometer. note: the in array should have increasing values
              int in[]  = {0, 25.5,51,76.5,102,127.5,153,178.5,204,229.5,255};
              // This is a map of values for potentiometer curve type.
              int out[] = { 2300,2298,2296,2295,2292,2200,2100,2000,1800,1300,0 };  // 11
              // This maps the potentiometer scale.
              controlAmount  = map(analogRead(A0), 0, 1024, 255, 0);
              // This is a multimap that assigns values from the [in] array (potentiometer) to values from the [out] array (curve)
              x = multiMap(controlAmount, in, out, 11);
              // This maps the values for the Modez.
              fadeSpeed = map(x, 0, 2300, speedMinimum, 10);
              
        
              //Serial.println("Mode 3 controlAmount: " + String(controlAmount));
              //Serial.println("Bank - " + String(Bank) + "Mode" + String(Mode) + "fadeSpeeed: " + String(fadeSpeed)); 
        
            }
            else if (Mode == 7) {
              valueLog = log(analogRead(A0)+1)/log(1024)*255;
              //Serial.println("Mode 1 valueLog: " + String(valueLog));
              fadeSpeed = map(valueLog, 0, 255, (speedMinimum/2), 30); // Logarithmic Potentiometer Value
              //fadeSpeed = map(analogRead(A0), 0, 1024, durationMaximum, 0);
        
              //Serial.println("Bank - " + String(Bank) + "Mode" + String(Mode) + "fadeSpeeed: " + String(fadeSpeed)); 
        
            }    
            else if (Mode == 8) {
              //valueA0 = map(analogRead(A0), 0, 1024, 2000, 0);
              valueA0 = log(analogRead(A0)+1)/log(1024)*255;
              modulateConstrain = modulateSpeed + (valueA0-200);
              fadeSpeed = constrain(modulateConstrain, 0, 3000);
              //fadeSpeed = map(analogRead(A0), 0, 1024, durationMaximum, 0);
              //ModulateControl();
              //fadeSpeed = fadeSpeed;
              
              //Serial.println("delayA0 fadeSpeeed: " + String(fadeSpeed));
            }  
            else if (Mode == 9) {
              //valueA0 = map(analogRead(A0), 0, 1024, 2000, 0);
              valueA0 = log(analogRead(A0)+1)/log(1024)*255;
              modulateConstrain = modulateSpeed + (valueA0-200);
              fadeSpeed = constrain(modulateConstrain, 0, 3000);
              //fadeSpeed = map(analogRead(A0), 0, 1024, durationMaximum, 0);
              //ModulateControl();
              //fadeSpeed = fadeSpeed;
              
              //Serial.println("delayA0 fadeSpeeed: " + String(fadeSpeed));
            }  
            else if (Mode == 10) {
            //valueLog = log(analogRead(A0)+1)/log(1024)*255;
            //Serial.println("Mode 1 valueLog: " + String(valueLog));
            //fadeSpeed = map(valueLog, 0, 255, (speedMinimum/2), (0/2)); // Logarithmic Potentiometer Value
            //fadeSpeed = map(analogRead(A0), 0, 1024, speedMinimum, 0); // Linear Potentiometer Value
      
            // This makes the potentiometer slower to change when reducting from full and gives better control fidelity at higher speeds
            // This is a map of values for the potentiometer. note: the in array should have increasing values
            int in[]  = {0, 25.5,51,76.5,102,127.5,153,178.5,204,229.5,255};
            // This is a map of values for potentiometer curve type.
            int out[] = { 2300,2298,2296,2295,2292,2200,2100,2000,1800,1300,0 };  // 11
            // This maps the potentiometer scale.
            controlAmount  = map(analogRead(A0), 0, 1024, 255, 0);
            // This is a multimap that assigns values from the [in] array (potentiometer) to values from the [out] array (curve)
            x = multiMap(controlAmount, in, out, 11);
            // This maps the values for the Modez.
            fadeSpeed = map(x, 0, 2300, speedMinimum, 0);
            
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
