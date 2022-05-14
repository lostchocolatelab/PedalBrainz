/**

  Mountain Snack Mode Arrays of Numbers

*/


PROGMEM const int sine2048[] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9,
  9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15, 15, 16,
  16, 16, 16, 16, 17, 17, 17, 17, 17, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 20, 20, 20, 20, 20, 21, 21, 21, 21, 21, 22, 22, 22, 22, 23, 23, 23, 23, 23, 24, 24,
  24, 24, 25, 25, 25, 25, 26, 26, 26, 26, 27, 27, 27, 27, 27, 28, 28, 28, 28, 29, 29, 29, 29, 30, 30, 30, 30, 31, 31, 31, 31, 32, 32, 32, 33, 33, 33, 33, 34, 34,
  34, 34, 35, 35, 35, 35, 36, 36, 36, 37, 37, 37, 37, 38, 38, 38, 38, 39, 39, 39, 40, 40, 40, 40, 41, 41, 41, 42, 42, 42, 42, 43, 43, 43, 44, 44, 44, 45, 45, 45,
  45, 46, 46, 46, 47, 47, 47, 48, 48, 48, 48, 49, 49, 49, 50, 50, 50, 51, 51, 51, 52, 52, 52, 52, 53, 53, 53, 54, 54, 54, 55, 55, 55, 56, 56, 56, 57, 57, 57, 58,
  58, 58, 59, 59, 59, 60, 60, 60, 61, 61, 61, 62, 62, 62, 63, 63, 63, 64, 64, 64, 65, 65, 65, 66, 66, 66, 67, 67, 67, 68, 68, 68, 69, 69, 69, 70, 70, 71, 71, 71,
  72, 72, 72, 73, 73, 73, 74, 74, 74, 75, 75, 75, 76, 76, 77, 77, 77, 78, 78, 78, 79, 79, 79, 80, 80, 81, 81, 81, 82, 82, 82, 83, 83, 83, 84, 84, 85, 85, 85, 86,
  86, 86, 87, 87, 88, 88, 88, 89, 89, 89, 90, 90, 90, 91, 91, 92, 92, 92, 93, 93, 93, 94, 94, 95, 95, 95, 96, 96, 97, 97, 97, 98, 98, 98, 99, 99, 100, 100, 100, 101,
  101, 101, 102, 102, 103, 103, 103, 104, 104, 105, 105, 105, 106, 106, 106, 107, 107, 108, 108, 108, 109, 109, 110, 110, 110, 111, 111, 112, 112, 112, 113, 113, 113, 114, 114, 115, 115, 115, 116, 116,
  117, 117, 117, 118, 118, 119, 119, 119, 120, 120, 120, 121, 121, 122, 122, 122, 123, 123, 124, 124, 124, 125, 125, 126, 126, 126, 127, 127, 128, 128, 128, 128, 129, 129, 129, 130, 130, 131, 131, 131, 132, 132, 133, 133, 133, 134, 134, 135, 135,
  135, 136, 136, 136, 137, 137, 138, 138, 138, 139, 139, 140, 140, 140, 141, 141, 142, 142, 142, 143, 143, 143, 144, 144, 145, 145, 145, 146, 146, 147, 147, 147, 148, 148, 149, 149, 149, 150, 150, 150,
  151, 151, 152, 152, 152, 153, 153, 154, 154, 154, 155, 155, 155, 156, 156, 157, 157, 157, 158, 158, 158, 159, 159, 160, 160, 160, 161, 161, 162, 162, 162, 163, 163, 163, 164, 164, 165, 165, 165, 166,
  166, 166, 167, 167, 167, 168, 168, 169, 169, 169, 170, 170, 170, 171, 171, 172, 172, 172, 173, 173, 173, 174, 174, 174, 175, 175, 176, 176, 176, 177, 177, 177, 178, 178, 178, 179, 179, 180, 180, 180,
  181, 181, 181, 182, 182, 182, 183, 183, 183, 184, 184, 184, 185, 185, 186, 186, 186, 187, 187, 187, 188, 188, 188, 189, 189, 189, 190, 190, 190, 191, 191, 191, 192, 192, 192, 193, 193, 193, 194, 194,
  194, 195, 195, 195, 196, 196, 196, 197, 197, 197, 198, 198, 198, 199, 199, 199, 200, 200, 200, 201, 201, 201, 202, 202, 202, 203, 203, 203, 203, 204, 204, 204, 205, 205, 205, 206, 206, 206, 207, 207,
  207, 207, 208, 208, 208, 209, 209, 209, 210, 210, 210, 210, 211, 211, 211, 212, 212, 212, 213, 213, 213, 213, 214, 214, 214, 215, 215, 215, 215, 216, 216, 216, 217, 217, 217, 217, 218, 218, 218, 218,
  219, 219, 219, 220, 220, 220, 220, 221, 221, 221, 221, 222, 222, 222, 222, 223, 223, 223, 224, 224, 224, 224, 225, 225, 225, 225, 226, 226, 226, 226, 227, 227, 227, 227, 228, 228, 228, 228, 228, 229,
  229, 229, 229, 230, 230, 230, 230, 231, 231, 231, 231, 232, 232, 232, 232, 232, 233, 233, 233, 233, 234, 234, 234, 234, 234, 235, 235, 235, 235, 235, 236, 236, 236, 236, 236, 237, 237, 237, 237, 237,
  238, 238, 238, 238, 238, 239, 239, 239, 239, 239, 240, 240, 240, 240, 240, 240, 241, 241, 241, 241, 241, 242, 242, 242, 242, 242, 242, 243, 243, 243, 243, 243, 243, 244, 244, 244, 244, 244, 244, 245,
  245, 245, 245, 245, 245, 245, 246, 246, 246, 246, 246, 246, 246, 247, 247, 247, 247, 247, 247, 247, 248, 248, 248, 248, 248, 248, 248, 248, 249, 249, 249, 249, 249, 249, 249, 249, 250, 250, 250, 250,
  250, 250, 250, 250, 250, 250, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253,
  253, 253, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
  255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
  255, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 252, 252, 252,
  252, 252, 252, 252, 252, 252, 252, 252, 252, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 249, 249, 249, 249, 249, 249, 249, 249, 248, 248, 248,
  248, 248, 248, 248, 248, 247, 247, 247, 247, 247, 247, 247, 246, 246, 246, 246, 246, 246, 246, 245, 245, 245, 245, 245, 245, 245, 244, 244, 244, 244, 244, 244, 243, 243, 243, 243, 243, 243, 242, 242,
  242, 242, 242, 242, 241, 241, 241, 241, 241, 240, 240, 240, 240, 240, 240, 239, 239, 239, 239, 239, 238, 238, 238, 238, 238, 237, 237, 237, 237, 237, 236, 236, 236, 236, 236, 235, 235, 235, 235, 235,
  234, 234, 234, 234, 234, 233, 233, 233, 233, 232, 232, 232, 232, 232, 231, 231, 231, 231, 230, 230, 230, 230, 229, 229, 229, 229, 228, 228, 228, 228, 228, 227, 227, 227, 227, 226, 226, 226, 226, 225,
  225, 225, 225, 224, 224, 224, 224, 223, 223, 223, 222, 222, 222, 222, 221, 221, 221, 221, 220, 220, 220, 220, 219, 219, 219, 218, 218, 218, 218, 217, 217, 217, 217, 216, 216, 216, 215, 215, 215, 215,
  214, 214, 214, 213, 213, 213, 213, 212, 212, 212, 211, 211, 211, 210, 210, 210, 210, 209, 209, 209, 208, 208, 208, 207, 207, 207, 207, 206, 206, 206, 205, 205, 205, 204, 204, 204, 203, 203, 203, 203,
  202, 202, 202, 201, 201, 201, 200, 200, 200, 199, 199, 199, 198, 198, 198, 197, 197, 197, 196, 196, 196, 195, 195, 195, 194, 194, 194, 193, 193, 193, 192, 192, 192, 191, 191, 191, 190, 190, 190, 189,
  189, 189, 188, 188, 188, 187, 187, 187, 186, 186, 186, 185, 185, 184, 184, 184, 183, 183, 183, 182, 182, 182, 181, 181, 181, 180, 180, 180, 179, 179, 178, 178, 178, 177, 177, 177, 176, 176, 176, 175,
  175, 174, 174, 174, 173, 173, 173, 172, 172, 172, 171, 171, 170, 170, 170, 169, 169, 169, 168, 168, 167, 167, 167, 166, 166, 166, 165, 165, 165, 164, 164, 163, 163, 163, 162, 162, 162, 161, 161, 160,
  160, 160, 159, 159, 158, 158, 158, 157, 157, 157, 156, 156, 155, 155, 155, 154, 154, 154, 153, 153, 152, 152, 152, 151, 151, 150, 150, 150, 149, 149, 149, 148, 148, 147, 147, 147, 146, 146, 145, 145,
  145, 144, 144, 143, 143, 143, 142, 142, 142, 141, 141, 140, 140, 140, 139, 139, 138, 138, 138, 137, 137, 136, 136, 136, 135, 135, 135, 134, 134, 133, 133, 133, 132, 132, 131, 131, 131, 130, 130, 129,
  129, 129, 128, 128, 128, 127, 127, 126, 126, 126, 125, 125, 124, 124, 124, 123, 123, 122, 122, 122, 121, 121, 120, 120, 120, 119, 119, 119, 118, 118, 117, 117, 117, 116, 116, 115, 115, 115, 114, 114,
  113, 113, 113, 112, 112, 112, 111, 111, 110, 110, 110, 109, 109, 108, 108, 108, 107, 107, 106, 106, 106, 105, 105, 105, 104, 104, 103, 103, 103, 102, 102, 101, 101, 101, 100, 100, 100, 99, 99, 98,
  98, 98, 97, 97, 97, 96, 96, 95, 95, 95, 94, 94, 93, 93, 93, 92, 92, 92, 91, 91, 90, 90, 90, 89, 89, 89, 88, 88, 88, 87, 87, 86, 86, 86, 85, 85, 85, 84, 84, 83,
  83, 83, 82, 82, 82, 81, 81, 81, 80, 80, 79, 79, 79, 78, 78, 78, 77, 77, 77, 76, 76, 75, 75, 75, 74, 74, 74, 73, 73, 73, 72, 72, 72, 71, 71, 71, 70, 70, 69, 69,
  69, 68, 68, 68, 67, 67, 67, 66, 66, 66, 65, 65, 65, 64, 64, 64, 63, 63, 63, 62, 62, 62, 61, 61, 61, 60, 60, 60, 59, 59, 59, 58, 58, 58, 57, 57, 57, 56, 56, 56,
  55, 55, 55, 54, 54, 54, 53, 53, 53, 52, 52, 52, 52, 51, 51, 51, 50, 50, 50, 49, 49, 49, 48, 48, 48, 48, 47, 47, 47, 46, 46, 46, 45, 45, 45, 45, 44, 44, 44, 43,
  43, 43, 42, 42, 42, 42, 41, 41, 41, 40, 40, 40, 40, 39, 39, 39, 38, 38, 38, 38, 37, 37, 37, 37, 36, 36, 36, 35, 35, 35, 35, 34, 34, 34, 34, 33, 33, 33, 33, 32,
  32, 32, 31, 31, 31, 31, 30, 30, 30, 30, 29, 29, 29, 29, 28, 28, 28, 28, 27, 27, 27, 27, 27, 26, 26, 26, 26, 25, 25, 25, 25, 24, 24, 24, 24, 23, 23, 23, 23, 23,
  22, 22, 22, 22, 21, 21, 21, 21, 21, 20, 20, 20, 20, 20, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 17, 17, 17, 17, 17, 16, 16, 16, 16, 16, 15, 15, 15, 15, 15, 15,
  14, 14, 14, 14, 14, 13, 13, 13, 13, 13, 13, 12, 12, 12, 12, 12, 12, 11, 11, 11, 11, 11, 11, 10, 10, 10, 10, 10, 10, 10, 9, 9, 9, 9, 9, 9, 9, 8, 8, 8,
  8, 8, 8, 8, 7, 7, 7, 7, 7, 7, 7, 7, 6, 6, 6, 6, 6, 6, 6, 6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};


/**

  Mountain Snack Mode Functions

  This Section is the Mountain Snack Mode and stuff called by the mountainSnack() function
  
*/

void setRandoms() {

  for (int j = 0; j < randomDensity; j++) {
    randomCore[j] = (random(512) - 256); // fill a random array of size=randomDensity
    //   Serial.println(randomCore[j]);
    for (int i = 0; i < (loopLength / randomDensity); i++) {
      randomNumbers[i + ((loopLength / randomDensity)*j)] = randomCore[j]; // apply those randomDensity values evenly and sequentially into an array of 2048 values
    }
  }

}

void mountainSnack() {


      // This makes the potentiometer slower to change when reducting from full and gives better control fidelity at higher speeds
      // This is a map of values for the potentiometer. note: the in array should have increasing values
      int in[]  = {0, 25,51,76,102,127,153,178,204,229,255};
      // This is a map of values for potentiometer curve type.
      int out[] = { 2300,2280,2270,2260,2250,2200,2100,2000,1500,1000,0 };  // 11
      // This maps the potentiometer scale.
      controlAmount  = map(analogRead(A0), 0, 1024, 255, 0);
      // This is a multimap that assigns values from the [in] array (potentiometer) to values from the [out] array (curve)
      x = multiMap(controlAmount, in, out, 11);
      // This maps the values for the Modez.
      newValue1 = mapfloat(x, 0, 2300, 255, 0);
  
  //newValue1 = map(analogRead(A0), 0, 1024, 255, 0); // Control the Speed
  
  
  if (abs(newValue1 - newCalibrate1) > 1) { // this further smooths the knob, at the expense of some accuracy. probably worth it.
    valueA0 = newValue1;
    newCalibrate1 = newValue1;
    //Serial.println("newValue1 :" + String(newValue1));
    //Serial.println("newCalibrate :" + String(newCalibrate1));
  }

  valueA2 = analogRead(A2); // Increases Chance for Snack
  valueA1 = analogRead(A1); // Amount of Randomness to the Cycle
  
  speedControl = float(valueA0) / 256; // speed control bit shifted and then goes from 0-1
  randomAmount = float(valueA1) / 2048; // random depth from 0-0.5
  if (Bank == 2 && Mode == 4){
    
  }
  else{
    snackChance = valueA2; // chance of snack from 0-1024
  }
  

  // calculate the random array that will be sent to LED by multiplying the random number array by a factor from 0 to 1 (for now, maybe these values should be adjusted)
  for (int i = 0; i < loopLength; i++) {
    int randomDepth = int(randomNumbers[i] * randomAmount);

    // sum1024[i] = int(sine1024[i]+((random1024[i]-128)*randomMultiplier));
    sumArray[i] = constrain(sine2048[i] + randomDepth, 0, 255);

         if (clicked == true) {
            
              //Serial.println("I Broke Rainbowz Mode " + String(Mode) + " because button was clicked");
              breakdelayA0 = true;
              breakdelayA1 = true;
              breakdelayA2 = true;
              clicked = false;
              break;
              x = 1;
              fadeSpeed = 0;
              fullDelay = 0;
              darkDelay = 0;
              randomAmount = 0;  
            }
          else {
            
          }
        
            if (breakdelayA0 == true)
            {
              //Serial.println("Rainbowz - I Broke delayA0 Because A0 was true");
               breakdelayA0 = false;
               break;
             
            }
            if (breakdelayA1 == true)
            {
              //Serial.println("Rainbowz - I Broke delayA1 Because A0 was true");
              breakdelayA1 = false;
              break;
              
            }
            if (breakdelayA2 == true)
            {
              //Serial.println("Rainbowz - I Broke delayA2 Because A0 was true");
              breakdelayA2 = false;
             break;
              
            }
            else {
              
            }
            
  };




  // Set pulse rate
  valueA0 = newValue1;
  targetSpeed = (maxLength * speedControl) + minLength; // set number of milliseconds the loop will last by multiplying the longest possible length by a fraction calculated by the knob
  //Serial.println("targetspeed :" + String(targetSpeed));
  milli = millis() - lastMillis;
  if (milli > targetSpeed) {
    milli = 0;
    lastMillis = millis();
    if (reRandom) {
      setRandoms(); // the resets the random numbers on each loop.
    };
  }

  // use targetSpeed and lengths to read the array of values and determine LED brightness
 // currentLoc = (milli * ((maxLength + minLength) / targetSpeed)) / 2; // fix this so that lengths other than 1000-4096 can be selected
   currentLoc = (milli * ((maxLength + minLength) / targetSpeed)) / ((maxLength + minLength)/loopLength);
  currentVal = sumArray[int(currentLoc)];




  // every so often decide whether to stop for a snack, current 3 times per cycle

  snackInterval = int(targetSpeed / 3.2);
  if ((millis() - snackMilli) > snackInterval) {
    snackMilli = millis();
    snackRandom = random(1024); // this is where randomness range could be set, currently it is 0-100%, should maybe max out at 50%?

    //   Serial.println(snackRandom);
  }


  snackDecision();
  Serial.println(scaledVal);
  mountainzColorMap();
  
  showLEDS();


              //Serial.println(scaledVal);

       if (Bank == 2 && Mode == 4){
    
          }
       else if ((scaledVal >= 0) && (scaledVal <= 10)) {
              
                // Slow down the simulation when the value is low
                
                strangeRandom = random(20, 200);
                strangeSlowAmount = (strangeRandom+(delayAmount*3));
                delay(strangeSlowAmount);
                Serial.println("StrangeSlow: " + String(strangeSlowAmount));
                Serial.println("currentVal: " + String(currentVal));
                 Serial.println("scaledVal: " + String(scaledVal));
                //Serial.println("ScaledVal: " + String(scaledVal));
                //Serial.println("CurrentVal: " + String(currentVal));
    
                showLEDS();
           }  
           else;
        

  plotCycle();
  checkButtons();
  
  

  // pixel.setPixelColor(pixel number, R, G, B);
  // pixel.setPixelColor(0, 64, 0, 0); pixel.show();delay(1000); //red brightness value 0-255
}

void snackDecision(){
    // if you've decided to have your snack

  if (Bank == 2 && Mode == 4){


    if ((scaledVal >= 0) && (scaledVal <= .1)) {
               
        snackChance = 1024;
                   
        snackLength = map(analogRead(A2), 0, 1024, 0, 10000); // Control the amount of Random Snack
        //snackLength = int(targetSpeed/3);
        lastMillis += snackLength;
        snackRandom = 1024;
        snackLengthRandom = random(1000)-50;
        //snackLengthRandom = random(snackLength+1000)-(snackLength+50);
        delaySnackLength = snackLength+snackLengthRandom;
        //delaySnackLength = snackLength;
        Serial.println("SNACK TIME");
        //Serial.println(snackLength+snackLengthRandom);
        //delay(snackLength+snackLengthRandom);
        Serial.println("delaySnackLength :" + String(delaySnackLength));
        
        delaySnack(delaySnackLength);
        
        Serial.println("WaitDelay is True");
          
        //delayA2(darkDelay);
        Serial.println(scaledVal);
        //Serial.println(currentVal);
    
    }

  } 
  else {
    if (snackRandom < snackChance) {
    
        snackLength = map(analogRead(A0), 0, 1024, 0, 1000); // Control the amount of Random Snack
        //snackLength = int(targetSpeed/3);
        lastMillis += snackLength;
        snackRandom = 1024;
        //snackLengthRandom = random(100)-50;
        snackLengthRandom = random(snackLength+1000)-(snackLength+50);
        delaySnackLength = snackLength+snackLengthRandom;
        //Serial.println("SNACK TIME");
        //Serial.println(snackLength+snackLengthRandom);
        //delay(snackLength+snackLengthRandom);
        //Serial.println("snackLength :" + String(delaySnackLength));
        
        delaySnack(delaySnackLength);
    }
  }
  
  

    plotCycle();
    checkButtons();

  
}

void scaledLowDelay(){
        if ((scaledVal >= 0) && (scaledVal <= .1)) {
               
               Serial.println("WaitDelay is True");
               // Delay between cycles
               for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                    strip.setPixelColor(p, 0, 0, 0);
                }
                pixel.setPixelColor(0, 0, 0, 0);
                inner.setPixelColor(0, 0, 0, 0);
                showLEDS();

                strip.setBrightness(0);
                FastLED.setBrightness(0);
                pixel.setBrightness(0);
                inner.setBrightness(0);
                showLEDS();
                
                delayA2(darkDelay);
                Serial.println(scaledVal);
                currentVal = 2;
             
           
          }
}
void mountainzColorMap(){

   if (Bank == 1)
    {
  
      if (Mode == 6){
        
          color = 1;
      }
      if (Mode == 7){
        
          color = 3;
      }
    }  
else  if (Bank == 2)
  {
    
      if (Mode == 4){
        
          color = 6;
      }
      if (Mode == 5){
        
          color = 5;
      }
      if (Mode == 6){
        
          color = 5;
      }
  }
else  if (Bank == 3)
  {
      
      if (Mode == 4){
        
          color = 4;
      }
      if (Mode == 5){
        
          color = 4;
      }
  }
else  if (Bank == 4)
  {
    
      if (Mode == 2){
        
          color = 6;
      }
      if (Mode == 3){
        
          color = 5;
      }
      if (Mode == 4){
        
          color = 5;
      }
  }
else;

    // yann's simple system for setitng single pixel color with variable brightness
    
    scaledVal = mapfloat(currentVal, 0, 255, 0, maximumScale);
    MaxBrightReduction = constrain(currentVal, 0, MaxBright);
    
      //Serial.println(scaledVal);
      if (color == 0) {
              strip.setBrightness(MaxBrightReduction);
              FastLED.setBrightness(MaxBrightReduction);
              pixel.setBrightness(scaledVal);
              inner.setBrightness(scaledVal);
              showLEDS();
        
        for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                strip.setPixelColor(p, 255, 0, 255);
         }
        pixel.setPixelColor(0, 255, 0, 255);
        inner.setPixelColor(0, 255, 0, 255);
        showLEDS();
      }
    
      if (color == 1) {
              strip.setBrightness(MaxBrightReduction);
              FastLED.setBrightness(MaxBrightReduction);
              pixel.setBrightness(scaledVal);
              inner.setBrightness(scaledVal);
              showLEDS();
         
        for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                strip.setPixelColor(p, 0, 255, 255);
        }
        pixel.setPixelColor(0, 0, 255, 255);
        inner.setPixelColor(0, 0, 255, 255);
        showLEDS();
      }
    
      if (color == 2) {
              strip.setBrightness(MaxBrightReduction);
              FastLED.setBrightness(MaxBrightReduction);
              pixel.setBrightness(scaledVal);
              inner.setBrightness(scaledVal);
              showLEDS();
         
        for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                strip.setPixelColor(p, 0, 0, 255);
        }
        pixel.setPixelColor(0, 0, 0, 255);
        inner.setPixelColor(0, 0, 0, 255);
        showLEDS();
      }
    
      // damian's wacky system for setitng triple pixel color with variable brightness
    
      
      if (color == 3) {
        if ((currentVal >= 0) && (currentVal <= 2)) {
              strip.setBrightness(MaxBrightReduction);
              FastLED.setBrightness(0);
              pixel.setBrightness(0);
              inner.setBrightness(0);
              showLEDS();
              
              for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                      strip.setPixelColor(p, 0,0,0);

              }
              pixel.setPixelColor(0, 0,0,0);
              inner.setPixelColor(0, 0,0,0);
              showLEDS();
            }
        if ((currentVal >= 3) && (currentVal <= 60)) {
              strip.setBrightness(MaxBrightReduction);
              FastLED.setBrightness(MaxBrightReduction);
              pixel.setBrightness(scaledVal);
              inner.setBrightness(scaledVal);
              showLEDS();
          
          for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                strip.setPixelColor(p, (currentVal/2), 0, currentVal);
        }
        pixel.setPixelColor(0, (currentVal/2), 0, currentVal);
        inner.setPixelColor(0, (currentVal/2), 0, currentVal);
        showLEDS();
        }
      
        if ((currentVal >= 60) && (currentVal <= 200)) {
              strip.setBrightness(MaxBrightReduction);
              FastLED.setBrightness(MaxBrightReduction);
              pixel.setBrightness(scaledVal);
              inner.setBrightness(scaledVal);
              showLEDS();
          
          
          for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                strip.setPixelColor(p, 10, (currentVal/2), currentVal);

          }
          pixel.setPixelColor(0, 10, (currentVal/2), currentVal);
          inner.setPixelColor(0, 10, (currentVal/2), currentVal);
          showLEDS();
        }
      
        if ((currentVal >= 190) && (currentVal <= 255)) {
              strip.setBrightness(MaxBrightReduction);
              FastLED.setBrightness(MaxBrightReduction);
              pixel.setBrightness(scaledVal);
              inner.setBrightness(scaledVal);
              showLEDS();
          
          for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                strip.setPixelColor(p, currentVal, currentVal, 0);
                FastLED.show();
          }
        pixel.setPixelColor(0, currentVal, currentVal, 0);
        inner.setPixelColor(0, currentVal, currentVal, 0);
        showLEDS();
        }
      }
      if (color == 4) {
            if ((currentVal >= 0) && (currentVal <= 2)) {
              strip.setBrightness(MaxBrightReduction);
              FastLED.setBrightness(0);
              pixel.setBrightness(0);
              inner.setBrightness(0);
              showLEDS();
              
              for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                      strip.setPixelColor(p, 0,0,0);

              }
              pixel.setPixelColor(0, 0,0,0);
              inner.setPixelColor(0, 0,0,0);
              showLEDS();
            }
            if ((currentVal >= 3) && (currentVal <= 40)) {
              strip.setBrightness(MaxBrightReduction);
              FastLED.setBrightness(MaxBrightReduction);
              pixel.setBrightness(scaledVal);
              inner.setBrightness(scaledVal);
              showLEDS();
              
              for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                      strip.setPixelColor(p, colorRed);
              }
              
              pixel.setPixelColor(0, colorRed); 
              inner.setPixelColor(0, colorRed); 
              showLEDS();
            }
            if ((currentVal >= 41) && (currentVal <= 80)) {
              strip.setBrightness(MaxBrightReduction);
              FastLED.setBrightness(MaxBrightReduction);
              pixel.setBrightness(scaledVal);
              inner.setBrightness(scaledVal);
              showLEDS();
              
              for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                      strip.setPixelColor(p, colorOrange);
              }
              
              pixel.setPixelColor(0, colorOrange); 
              inner.setPixelColor(0, colorOrange);
              showLEDS();
            }
            if ((currentVal >= 81) && (currentVal <= 120)) {
              strip.setBrightness(MaxBrightReduction);
              FastLED.setBrightness(MaxBrightReduction);
              pixel.setBrightness(scaledVal);
              inner.setBrightness(scaledVal);
              showLEDS();
              
              for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                      strip.setPixelColor(p, colorYellow);
              }
              
              pixel.setPixelColor(0, colorYellow);
              inner.setPixelColor(0, colorYellow);
              showLEDS();
            }
            if ((currentVal >= 121) && (currentVal <= 160)) {
              FastLED.setBrightness(MaxBrightReduction);
              pixel.setBrightness(scaledVal);
              inner.setBrightness(scaledVal);
              showLEDS();
              
              for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                      strip.setPixelColor(p, colorGreen);
              }
              
              pixel.setPixelColor(0, colorGreen); 
              inner.setPixelColor(0, colorGreen); 
              showLEDS();
            }
            if ((currentVal >= 161) && (currentVal <= 200)) {
              strip.setBrightness(MaxBrightReduction);
              FastLED.setBrightness(MaxBrightReduction);
              pixel.setBrightness(scaledVal);
              inner.setBrightness(scaledVal);
              showLEDS();
              
              for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                      strip.setPixelColor(p, colorBlue);
              }
              
              pixel.setPixelColor(0, colorBlue); 
              inner.setPixelColor(0, colorBlue); 
              showLEDS();
            }
            if ((currentVal >= 201) && (currentVal <= 240)) {
              FastLED.setBrightness(MaxBrightReduction);
              pixel.setBrightness(scaledVal);
              inner.setBrightness(scaledVal);
              showLEDS();
              
              for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                      strip.setPixelColor(p, colorPurple);
              }
              
              pixel.setPixelColor(0, colorPurple); 
              inner.setPixelColor(0, colorPurple); 
              showLEDS();
            }
            if ((currentVal >= 241) && (currentVal <= 260)) {
              strip.setBrightness(MaxBrightReduction);
              FastLED.setBrightness(MaxBrightReduction);
              pixel.setBrightness(scaledVal);
              inner.setBrightness(scaledVal);
              showLEDS();
              
              for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                      strip.setPixelColor(p, colorPink);

              }
              
              pixel.setPixelColor(0, colorPink); 
              inner.setPixelColor(0, colorPink); 
              showLEDS();
            }
          }
          if (color == 5) {
            if ((currentVal >= 0) && (currentVal <= 2)) {
              strip.setBrightness(MaxBrightReduction);
              FastLED.setBrightness(0);
              pixel.setBrightness(0);
              inner.setBrightness(0);
              showLEDS();
              
              for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                      strip.setPixelColor(p, 0,0,0);

              }
              pixel.setPixelColor(0, 0,0,0);
              inner.setPixelColor(0, 0,0,0);
              showLEDS();
            }
            if ((currentVal >= 3) && (currentVal <= 40)) {
              strip.setBrightness(MaxBrightReduction);FastLED.setBrightness(MaxBrightReduction);
              pixel.setBrightness(scaledVal);
              inner.setBrightness(scaledVal);
              showLEDS();
              
              for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                      strip.setPixelColor(p, 3,2,93);

              }
              pixel.setPixelColor(0, 3,2,93);
              inner.setPixelColor(0, 3,2,93);
              showLEDS();
            }
            if ((currentVal >= 41) && (currentVal <= 80)) {
              strip.setBrightness(MaxBrightReduction);FastLED.setBrightness(MaxBrightReduction);
              pixel.setBrightness(scaledVal);
              inner.setBrightness(scaledVal);
              showLEDS();
              
              for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                      strip.setPixelColor(p, 3,29,255);
              }
              
              pixel.setPixelColor(0, 3,29,255); 
              inner.setPixelColor(0, 3,29,255); 
              showLEDS();
            }
            if ((currentVal >= 81) && (currentVal <= 120)) {
              strip.setBrightness(MaxBrightReduction);
              FastLED.setBrightness(MaxBrightReduction);
              pixel.setBrightness(scaledVal);
              inner.setBrightness(scaledVal);
              showLEDS();
              
              for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                      strip.setPixelColor(p, 0,255,81);
              }
              
              pixel.setPixelColor(0, 0,255,81); 
              inner.setPixelColor(0, 0,255,81); 
              showLEDS();
            }
            if ((currentVal >= 121) && (currentVal <= 160)) {
              strip.setBrightness(MaxBrightReduction);
              FastLED.setBrightness(MaxBrightReduction);
              pixel.setBrightness(scaledVal);
              inner.setBrightness(scaledVal);
              showLEDS();
              
              for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                      strip.setPixelColor(p, 37,255,0);
              }
              
              pixel.setPixelColor(0, 37,255,0); 
              inner.setPixelColor(0, 37,255,0); 
              showLEDS();
            }
            if ((currentVal >= 161) && (currentVal <= 200)) {
              strip.setBrightness(MaxBrightReduction);
              FastLED.setBrightness(MaxBrightReduction);
              pixel.setBrightness(scaledVal);
              inner.setBrightness(scaledVal);
              showLEDS();
              
              for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                      strip.setPixelColor(p, 255,0,255);
                      FastLED.show();
              }
              
              pixel.setPixelColor(0, 255,0,255); 
              inner.setPixelColor(0, 255,0,255); 
              showLEDS();
            }
            if ((currentVal >= 201) && (currentVal <= 240)) {
              strip.setBrightness(MaxBrightReduction);
              FastLED.setBrightness(MaxBrightReduction);
              pixel.setBrightness(scaledVal);
              inner.setBrightness(scaledVal);
              showLEDS();
              
              for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                      strip.setPixelColor(p, 255,0,157);
              }
              
              pixel.setPixelColor(0, 255,0,157); 
              inner.setPixelColor(0, 255,0,157); 
              showLEDS();
            }
            if ((currentVal >= 241) && (currentVal <= 260)) {
              strip.setBrightness(MaxBrightReduction);
              FastLED.setBrightness(MaxBrightReduction);
              pixel.setBrightness(scaledVal);
              inner.setBrightness(scaledVal);
              showLEDS();
              
              for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                      strip.setPixelColor(p, 35,0,255);
              }
              
              pixel.setPixelColor(0, 35,0,255);
              inner.setPixelColor(0, 35,0,255); 
              showLEDS();
            }
          }
          if (color == 6) {
            if ((currentVal >= 0) && (currentVal <= 2)) {
              strip.setBrightness(MaxBrightReduction);
              FastLED.setBrightness(0);
              pixel.setBrightness(0);
              inner.setBrightness(0);
              showLEDS();
              
              for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                      strip.setPixelColor(p, 0,0,0);

              }
              pixel.setPixelColor(0, 0,0,0);
              inner.setPixelColor(0, 0,0,0);
              showLEDS();
            }
            if ((currentVal >= 3) && (currentVal <= 40)) {
              FastLED.setBrightness(MaxBrightReduction);
              pixel.setBrightness(scaledVal);
              inner.setBrightness(scaledVal);
              showLEDS();
              
              for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                      strip.setPixelColor(p, 20,0,255);
                      FastLED.show();
              }
              
              pixel.setPixelColor(0, 20,0,255); 
              inner.setPixelColor(0, 20,0,255); 
              showLEDS();
            }
            if ((currentVal >= 41) && (currentVal <= 80)) {
              strip.setBrightness(MaxBrightReduction);
              FastLED.setBrightness(MaxBrightReduction);
              pixel.setBrightness(scaledVal);
              inner.setBrightness(scaledVal);
              showLEDS();
              
              for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                      strip.setPixelColor(p, 255,0,255);
              }

              pixel.setPixelColor(0, colorOrange); 
              pixel.setPixelColor(0, colorOrange); 
              showLEDS();
            }
            if ((currentVal >= 81) && (currentVal <= 120)) {
              strip.setBrightness(MaxBrightReduction);
              FastLED.setBrightness(MaxBrightReduction);
              pixel.setBrightness(scaledVal);
              inner.setBrightness(scaledVal);
              showLEDS();
              
              for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                      strip.setPixelColor(p, 255,0,104);
              }
              
              pixel.setPixelColor(0, 255,0,104); 
              inner.setPixelColor(0, 255,0,104); 
              showLEDS();
            }
            if ((currentVal >= 121) && (currentVal <= 160)) {
              FastLED.setBrightness(MaxBrightReduction);
              pixel.setBrightness(scaledVal);
              inner.setBrightness(scaledVal);
              showLEDS();
              
              for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                      strip.setPixelColor(p, 255,0,0);
              }
              
              pixel.setPixelColor(0, 255,0,0); 
              inner.setPixelColor(0, 255,0,0); 
              showLEDS();
            }
            if ((currentVal >= 161) && (currentVal <= 200)) {
              strip.setBrightness(MaxBrightReduction);
              FastLED.setBrightness(MaxBrightReduction);
              pixel.setBrightness(scaledVal);
              inner.setBrightness(scaledVal);
              showLEDS();
              
              for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                      strip.setPixelColor(p, 255,41,0);
                      
              }
               
              pixel.setPixelColor(0, 255,41,0); 
              inner.setPixelColor(0, 255,41,0); 
              showLEDS();
            }
            if ((currentVal >= 201) && (currentVal <= 240)) {
              strip.setBrightness(MaxBrightReduction);
              FastLED.setBrightness(MaxBrightReduction);
              pixel.setBrightness(scaledVal);
              inner.setBrightness(scaledVal);
              showLEDS();
              
              for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                      strip.setPixelColor(p, 255,255,0);
              }
              
              pixel.setPixelColor(0, 255,255,0); 
              inner.setPixelColor(0, 255,255,0); 
              showLEDS();
            }
            if ((currentVal >= 241) && (currentVal <= 260)) {
              
              strip.setBrightness(MaxBrightReduction);
              FastLED.setBrightness(MaxBrightReduction);
              pixel.setBrightness(scaledVal);
              inner.setBrightness(scaledVal);
              showLEDS();
              
              for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
                      strip.setPixelColor(p, 255,255,255);
                      
              }
                           
              pixel.setPixelColor(0, 255,255,255);
              inner.setPixelColor(0, 255,255,255); 
              showLEDS();
            }
          }

}

void delaySnack(int count)
{
  
  int delaySnackLength = snackLength+snackLengthRandom;
  int delaySnacking = delaySnackLength;

  for (int count = 0; count <= delaySnacking; count++) {

    delaySnacking = delaySnackLength;
    //Serial.println("delaySnacking delaySnackLength: " + String(delaySnacking));
    
    plotCycle();
    checkButtons();

          if (clicked == true) {
            
              //Serial.println("I Broke Rainbowz Mode " + String(Mode) + " because button was clicked");
              breakdelayA0 = true;
              breakdelayA1 = true;
              breakdelayA2 = true;
              clicked = false;
              break;
              x = 1;
              fadeSpeed = 0;
              fullDelay = 0;
              darkDelay = 0;
              randomAmount = 0;  
            }
          else {
            
          }
        
            if (breakdelayA0 == true)
            {
              //Serial.println("Rainbowz - I Broke delayA0 Because A0 was true");
               breakdelayA0 = false;
               break;
             
            }
            if (breakdelayA1 == true)
            {
              //Serial.println("Rainbowz - I Broke delayA1 Because A0 was true");
              breakdelayA1 = false;
              break;
              
            }
            if (breakdelayA2 == true)
            {
              //Serial.println("Rainbowz - I Broke delayA2 Because A0 was true");
              breakdelayA2 = false;
             break;
              
            }
            else {
              
            }
   
     for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
          strip.setPixelColor(p, 0, 0, 0);
      }
      pixel.setPixelColor(0, 0, 0, 0);
      inner.setPixelColor(0, 0, 0, 0);
      showLEDS();
      
      strip.setBrightness(MaxBrightReduction);
      FastLED.setBrightness(0);
      pixel.setBrightness(0);
      inner.setBrightness(0);
      showLEDS();
      
      delay(1);
      //controlsMax();
      //Serial.println("Count if Waiting = False: " + String(count));
  }
}
