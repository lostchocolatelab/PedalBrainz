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
