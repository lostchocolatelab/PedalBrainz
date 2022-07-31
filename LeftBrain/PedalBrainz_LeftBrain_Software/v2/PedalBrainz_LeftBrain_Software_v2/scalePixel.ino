void scalePixelRed (int val){

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
      //redValue = map(x, 0, 255, 0, 255);
      redValue = constrain(x, 0.0, 255.0);

      //int redValue = 236;
      //int blueValue = 73;
      //int greenValue = 107;
      
}

void scalePixelGreen (int val){

      //controlAmount = map(analogRead(A0), 0, 1024, 0, 100);
      //valueLog = log(analogRead(A0)+1)/log(1024)*255;
      //Serial.println("Mode 1 valueLog: " + String(valueLog));
      //fadeSpeed = map(valueLog, 0, 255, (speedMinimum), (40/2)); // Logarithmic Potentiometer Value
      //fadeSpeed = map(valueLog, 0, 255, (speedMinimum/2), (40/2)); // Logarithmic Potentiometer Value

      // This makes the potentiometer slower to change when reducting from full and gives better control fidelity at higher speeds
      // This is a map of values for the potentiometer. note: the in array should have increasing values
      int in[]  = {0, 25,51,76,102,127,153,178,204,229,255};
      // This is a map of values for potentiometer curve type.
      int out[] = { 2300,2298,2296,2295,2292,2200,2100,2000,1800,1300,0 };  // 11
      // This maps the potentiometer scale.
      controlAmount  = val;
      // This is a multimap that assigns values from the [in] array (potentiometer) to values from the [out] array (curve)
      y = multiMap(controlAmount, in, out, 11);
      // This maps the values for the Modez.
      greenValue = map(y, 0, 2300, speedMinimum, 100);

      //int redValue = 236;
      //int blueValue = 73;
      //int greenValue = 107;
      
}

void scalePixelBlue (int val){

      //controlAmount = map(analogRead(A0), 0, 1024, 0, 100);
      //valueLog = log(analogRead(A0)+1)/log(1024)*255;
      //Serial.println("Mode 1 valueLog: " + String(valueLog));
      //fadeSpeed = map(valueLog, 0, 255, (speedMinimum), (40/2)); // Logarithmic Potentiometer Value
      //fadeSpeed = map(valueLog, 0, 255, (speedMinimum/2), (40/2)); // Logarithmic Potentiometer Value

      // This makes the potentiometer slower to change when reducting from full and gives better control fidelity at higher speeds
      // This is a map of values for the potentiometer. note: the in array should have increasing values
      int in[]  = {0, 25,51,76,102,127,153,178,204,229,255};
      // This is a map of values for potentiometer curve type.
      int out[] = { 2300,2298,2296,2295,2292,2200,2100,2000,1800,1300,0 };  // 11
      // This maps the potentiometer scale.
      controlAmount  = val;
      // This is a multimap that assigns values from the [in] array (potentiometer) to values from the [out] array (curve)
      z = multiMap(controlAmount, in, out, 11);
      // This maps the values for the Modez.
      blueValue = map(z, 0, 2300, speedMinimum, 100);

      //int redValue = 236;
      //int blueValue = 73;
      //int greenValue = 107;
      
}

void scalePixelInner (int val){

      // This makes the potentiometer slower to change when reducting from full and gives better control fidelity at higher speeds
      // This is a map of values for the potentiometer. note: the in array should have increasing values
      //int in[]  = {0, 25,51,76,102,127,153,178,204,229,255}; 
      int in[]  = {15,32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52, 54, 56, 58, 60, 62, 64, 66, 68, 70, 72, 74, 76, 78, 80, 82, 84, 86, 88, 90, 92, 94, 96, 98, 100,102,104,106,108,110,112,114,116,118,120,122,124,126,128,130,132,134,136,138,140,142,144,146,148,150,152,154,156,158,160,162,164,166,168,170,172,174,176,178,180,182,184,186,190}; 
      // This is a map of values for potentiometer curve type.
      //int out[] = {0   , 1   ,  2 ,    3    , 5    , 7    , 10 ,   15  ,  20 ,   40  ,  140 };  // 11 Good Slightly Curved at top
      int out[] = {0, 0,  0,  0,  0,  0,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 57, 60, 63, 66, 69, 72, 78, 83, 88, 95, 111,118,128,138,150,160,180,190};  // 40 Smoover
      // LINEAR int out[]  = {0, 5,  7,  9,  11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49, 51, 53, 55, 57, 59, 61, 63, 65, 67, 69, 71, 73, 75, 77, 79, 81, 83, 85, 87, 89, 91, 93, 95, 97, 99, 101,103,105,107,109,111,113,115,117,119,121,123,125,127,129,131,133,135,137,139,141,143,145,147,149,151,153,155,157,159,190}; 
     
      // This maps the potentiometer scale.
      controlAmount  = val;
      // This is a multimap that assigns values from the [in] array (potentiometer) to values from the [out] array (curve)
      x = multiMap(controlAmount, in, out, 80);
      // This maps the values for the Modez.
      innerValue = mapfloat(x, 0, 190, 0, 190);
      //innerValue = constrain(x, 0.0, 140.0);

      //int redValue = 236;
      //int blueValue = 73;
      //int greenValue = 107;
      
}

void scalePixelInner11 (int val){

      // This makes the potentiometer slower to change when reducting from full and gives better control fidelity at higher speeds
      // This is a map of values for the potentiometer. note: the in array should have increasing values
      //int in[]  = {0, 25,51,76,102,127,153,178,204,229,255}; 
      int in[]  = {0  ,  15   , 30  ,  45  ,  60  ,  75 ,   90  ,  105  , 120 ,  135  , 140}; 
      // This is a map of values for potentiometer curve type.
      //int out[] = {0   , 1   ,  2 ,    3    , 5    , 7    , 10 ,   15  ,  20 ,   40  ,  140 };  // 11 Good Slightly Curved at top
      int out[] = {0  ,  1  ,   2   ,  3  ,   4   ,  5   ,  6  ,   7  ,   8 ,    10  ,  140};  // 11 A little steppy

      // This maps the potentiometer scale.
      controlAmount  = val;
      // This is a multimap that assigns values from the [in] array (potentiometer) to values from the [out] array (curve)
      x = multiMap(controlAmount, in, out, 11);
      // This maps the values for the Modez.
      innerValue = mapfloat(x, 0, 140, 0, 140);
      //innerValue = constrain(x, 0.0, 140.0);

      //int redValue = 236;
      //int blueValue = 73;
      //int greenValue = 107;
      
}