/**

  Rainbowz Declarations

*/

unsigned short pixelnumber = 3;

/**

  Rainbow Mode - Arrays of numbers

*/

const uint8_t lights[360] = {
  0,   0,   0,   0,   0,   1,   1,   2,
  2,   3,   4,   5,   6,   7,   8,   9,
  11,  12,  13,  15,  17,  18,  20,  22,
  24,  26,  28,  30,  32,  35,  37,  39,
  42,  44,  47,  49,  52,  55,  58,  60,
  63,  66,  69,  72,  75,  78,  81,  85,
  88,  91,  94,  97, 101, 104, 107, 111,
  114, 117, 121, 124, 127, 131, 134, 137,
  141, 144, 147, 150, 154, 157, 160, 163,
  167, 170, 173, 176, 179, 182, 185, 188,
  191, 194, 197, 200, 202, 205, 208, 210,
  213, 215, 217, 220, 222, 224, 226, 229,
  231, 232, 234, 236, 238, 239, 241, 242,
  244, 245, 246, 248, 249, 250, 251, 251,
  252, 253, 253, 254, 254, 255, 255, 255,
  255, 255, 255, 255, 254, 254, 253, 253,
  252, 251, 251, 250, 249, 248, 246, 245,
  244, 242, 241, 239, 238, 236, 234, 232,
  231, 229, 226, 224, 222, 220, 217, 215,
  213, 210, 208, 205, 202, 200, 197, 194,
  191, 188, 185, 182, 179, 176, 173, 170,
  167, 163, 160, 157, 154, 150, 147, 144,
  141, 137, 134, 131, 127, 124, 121, 117,
  114, 111, 107, 104, 101,  97,  94,  91,
  88,  85,  81,  78,  75,  72,  69,  66,
  63,  60,  58,  55,  52,  49,  47,  44,
  42,  39,  37,  35,  32,  30,  28,  26,
  24,  22,  20,  18,  17,  15,  13,  12,
  11,   9,   8,   7,   6,   5,   4,   3,
  2,   2,   1,   1,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0
};

const uint8_t HSVlights[61] =
{ 0, 4, 8, 13, 17, 21, 25, 30, 34, 38, 42, 47, 51, 55, 59, 64, 68, 72, 76,
  81, 85, 89, 93, 98, 102, 106, 110, 115, 119, 123, 127, 132, 136, 140, 144,
  149, 153, 157, 161, 166, 170, 174, 178, 183, 187, 191, 195, 200, 204, 208,
  212, 217, 221, 225, 229, 234, 238, 242, 246, 251, 255
};

const uint8_t HSVpower[121] =
{ 0, 2, 4, 6, 8, 11, 13, 15, 17, 19, 21, 23, 25, 28, 30, 32, 34, 36, 38, 40,
  42, 45, 47, 49, 51, 53, 55, 57, 59, 62, 64, 66, 68, 70, 72, 74, 76, 79, 81,
  83, 85, 87, 89, 91, 93, 96, 98, 100, 102, 104, 106, 108, 110, 113, 115, 117,
  119, 121, 123, 125, 127, 130, 132, 134, 136, 138, 140, 142, 144, 147, 149,
  151, 153, 155, 157, 159, 161, 164, 166, 168, 170, 172, 174, 176, 178, 181,
  183, 185, 187, 189, 191, 193, 195, 198, 200, 202, 204, 206, 208, 210, 212,
  215, 217, 219, 221, 223, 225, 227, 229, 232, 234, 236, 238, 240, 242, 244,
  246, 249, 251, 253, 255
};


/**

  Rainbow mode Setups

*/

/**void setPixels(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
   delay(wait);                           //  Pause for a moment
  }

for(uint8_t p=0; p<10; i++) {
    uint8_t j = i + (i > 4);
    strip.setPixelColor(i,
      hsv2rgb(t + j * 1530 / 12, 255, 255, true));

  
}*/

void setRGBpoint(int pixelnumber, uint8_t redValue, uint8_t greenValue, uint8_t blueValue)
{
  
  for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
    strip.setPixelColor(p, redValue, greenValue, blueValue);
  }
  scalePixelInnerRed(redValue);
  scalePixelInnerBlue(blueValue);
  scalePixelInnerGreen(greenValue);
  pixel.setPixelColor(0, innerValueRed, innerValueGreen, innerValueBlue);
  inner.setPixelColor(0, innerValueRed, innerValueGreen, innerValueBlue);
  
  //Serial.println(redValue);
  //Serial.println(greenValue);
  //Serial.println(blueValue);
}

// the real HSV rainbow
void trueHSV(int pixelnumber, int angle)
{
  byte red, green, blue;

  if (angle < 60) {
    redValue = 255;
    greenValue = HSVlights[angle];
    blueValue = 0;
  } else if (angle < 120) {
    redValue = HSVlights[120 - angle];
    greenValue = 255;
    blueValue = 0;
  } else if (angle < 180) {
    redValue = 0, greenValue = 255;
    blueValue = HSVlights[angle - 120];
  } else if (angle < 240) {
    redValue = 0, greenValue = HSVlights[240 - angle];
    blueValue = 255;
  } else if (angle < 300) {
    redValue = HSVlights[angle - 240], greenValue = 0;
    blueValue = 255;
  } else
  {
    redValue = 255, greenValue = 0;
    blueValue = HSVlights[360 - angle];
  }
  setRGBpoint(pixelnumber, redValue, greenValue, blueValue);
  for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
    strip.setPixelColor(p, redValue, greenValue, blueValue);
  }
  scalePixelInnerRed(redValue);
  scalePixelInnerBlue(blueValue);
  scalePixelInnerGreen(greenValue);
  pixel.setPixelColor(0, innerValueRed, innerValueGreen, innerValueBlue);
  inner.setPixelColor(0, innerValueRed, innerValueGreen, innerValueBlue);
  showLEDS();

}

// the 'power-conscious' HSV rainbow
void powerHSV(int pixelnumber, int angle)
{
  byte redValue, greenValue, blueValue;
  if (angle < 120) {
    redValue = HSVpower[120 - angle];
    greenValue = HSVpower[angle];
    blueValue = 0;
  } else if (angle < 240) {
    redValue = 0;
    greenValue = HSVpower[240 - angle];
    blueValue = HSVpower[angle - 120];
  } else
  {
    redValue = HSVpower[angle - 240];
    greenValue = 0;
    blueValue = HSVpower[360 - angle];
  }
  setRGBpoint(pixelnumber, redValue, greenValue, blueValue);

  for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
    strip.setPixelColor(p, redValue, greenValue, blueValue);
  }
  scalePixelInnerRed(redValue);
  scalePixelInnerBlue(blueValue);
  scalePixelInnerGreen(greenValue);
  pixel.setPixelColor(0, innerValueRed, innerValueGreen, innerValueBlue);
  inner.setPixelColor(0, innerValueRed, innerValueGreen, innerValueBlue);
  showLEDS();
}

// sine wave rainbow
void sineLED(int pixelnumber, int angle)
{
  setRGBpoint(pixelnumber, lights[(angle + 120) % 360], lights[angle],  lights[(angle + 240) % 360]);
  for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
    strip.setPixelColor(p, lights[(angle + 120) % 360], lights[angle],  lights[(angle + 240) % 360]);
  }
  pixel.setPixelColor(0, lights[(angle + 120) % 360], lights[angle],  lights[(angle + 240) % 360]);
  inner.setPixelColor(0, lights[(angle + 120) % 360], lights[angle],  lights[(angle + 240) % 360]);

}

void RainbowMode () {

if (Bank == 1){

    if (Mode == 5) {

    //Randomize the maximum brightness of the LED using potantiometer A1
    rainbowBrightReduction = valueA1 - (randomAmount);
    rainbowBright = constrain(rainbowBrightReduction, 0, 255);
    //MaxBrightReduction = MaxBright - (randomAmount*2);
    MaxBrightRainbow = constrain(rainbowBright, 0, MaxBright);
    pixel.setBrightness(rainbowBright);
    strip.setBrightness(MaxBrightRainbow);
    FastLED.setBrightness(MaxBrightRainbow);
    inner.setBrightness(rainbowBright);
    showLEDS();
    Serial.println("Mode 5 rainbowBright: " + String(rainbowBright));
    //Serial.println("Mode 5 MaxBright " + String(MaxBright));
    //Serial.println("Mode 5 MaxBrightRainbow: " + String(MaxBrightRainbow));
    Serial.println("Mode 5 rainbowBrightReduction: " + String(rainbowBrightReduction));
    //Serial.println("---------");
    
  }
  else;
}

if (Bank == 2){
}
if (Bank == 3){

}
else;
  

  //Fade in from the beginning of the Rainbow cycle (Red)
  for (int x = 0; x < 255; x++)
  {

if (Bank == 1){
  if (Mode == 4) {

      //Change the maximum brightness of the LED using potantiometer A1
      rainbowBright = map(analogRead(A1), 0, 1024, 0, 100);
      MaxBrightReduction = map(analogRead(A1), 0, 1024, 0, MaxBright);
      pixel.setBrightness(rainbowBright);
      strip.setBrightness(MaxBrightReduction);
      FastLED.setBrightness(MaxBrightReduction);
      inner.setBrightness(rainbowBright);
      showLEDS();
      //Serial.println("Mode 4 rainbowBright: " + String(rainbowBright));
    }
    if (Mode == 5) {

      //Change the maximum brightness of the LED using potantiometer A1

      valueA1 = map(analogRead(A1), 0, 1024, 255, 0);
      randomAmount = random(0, 255);
      //Serial.println("Mode 5 randomAmount: " + String(randomAmount));
      //Serial.println("Mode 5 rainbowBright: " + String(rainbowBright));
  }
  else;
}

if (Bank == 2){
    if (Mode == 1) {

      //Change the maximum brightness of the LED using potantiometer A1
      rainbowBright = map(analogRead(A1), 0, 1024, 0, 100);
      MaxBrightReduction = map(analogRead(A1), 0, 1024, 0, MaxBright);
      pixel.setBrightness(rainbowBright);
      strip.setBrightness(MaxBrightReduction);
      FastLED.setBrightness(MaxBrightReduction);
      inner.setBrightness(rainbowBright);
      showLEDS();
      //Serial.println("Mode 4 rainbowBright: " + String(rainbowBright));
    }
    if (Mode == 2) {

       //Change the maximum brightness of the LED using potantiometer A1

      valueA1 = map(analogRead(A1), 0, 1024, 255, 0);
      randomAmount = random(0, 255);
      //Serial.println("Mode 5 randomAmount: " + String(randomAmount));
      //Serial.println("Mode 5 rainbowBright: " + String(rainbowBright));
  }
  else;
}
if (Bank == 3){

}
else;

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

    //Change the rate of the rainbow cycling using potantiometer A0
    //Increase the value of the R value causing a fade in;
    for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
              strip.setPixelColor(p, x,0,0);
    }
    pixel.setPixelColor(0, x, 0, 0);
    inner.setPixelColor(0, x, 0, 0);
    showLEDS();


    //A delay amount between each increase in value mapped to A0 and divided
    delayA0(fadeSpeed / 500);
    showLEDS();
  }

  //Run the Rainbow cycle (Red)
  for (int k = 0; k < 360; k++)
  {

    // uncomment the mode (or modes) you need below.

    //trueHSV(0, k);

    powerHSV(0, k);

    //sineLED(0, k);

    showLEDS();

    //Change the rate of the rainbow cycling using potantiometer A0
    fadeSpeed = map(analogRead(A0), 0, 1024, 80, -1);
    //Serial.println("Mode 5 fadeSpeeed: " + String(fadeSpeed));


    delayA0(fadeSpeed);


if (Bank == 1){
  if (Mode == 4) {

      //Change the maximum brightness of the LED using potantiometer A1
      rainbowBright = map(analogRead(A1), 0, 1024, 0, 100);
      MaxBrightReduction = map(analogRead(A1), 0, 1024, 0, MaxBright);
      pixel.setBrightness(rainbowBright);
      strip.setBrightness(MaxBrightReduction);
      FastLED.setBrightness(MaxBrightReduction);
      inner.setBrightness(rainbowBright);
      showLEDS();
      //Serial.println("Mode 4 rainbowBright: " + String(rainbowBright));
    }
    if (Mode == 5) {

      //Change the maximum brightness of the LED using potantiometer A1

      valueA1 = map(analogRead(A1), 0, 1024, 255, 0);
      randomAmount = random(0, 255);
      //Serial.println("Mode 5 randomAmount: " + String(randomAmount));
      //Serial.println("Mode 5 rainbowBright: " + String(rainbowBright));
  }
  else;
}

if (Bank == 2){
    if (Mode == 1) {

      //Change the maximum brightness of the LED using potantiometer A1
      rainbowBright = map(analogRead(A1), 0, 1024, 0, 100);
      MaxBrightReduction = map(analogRead(A1), 0, 1024, 0, MaxBright);
      pixel.setBrightness(rainbowBright);
      strip.setBrightness(MaxBrightReduction);
      FastLED.setBrightness(MaxBrightReduction);
      inner.setBrightness(rainbowBright);
      showLEDS();
      //Serial.println("Mode 4 rainbowBright: " + String(rainbowBright));
    }
    if (Mode == 2) {

      //Change the maximum brightness of the LED using potantiometer A1

      valueA1 = map(analogRead(A1), 0, 1024, 0, 255);
      randomAmount = random(0, 255);
      //Serial.println("Mode 5 randomAmount: " + String(randomAmount));
      //Serial.println("Mode 5 rainbowBright: " + String(rainbowBright));
  }
  else;
}
if (Bank == 3){

}
else;

    //plotCycle();
    checkButtons();
     if (clicked == true) {
            
              //Serial.println("I Broke Rainbowz Mode " + String(Mode) + " because button was clicked");
              breakdelayA0 = true;
              breakdelayA1 = true;
              breakdelayA2 = true;
              clicked = false;
              break;
              k = 1;
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

  }


  //Fade out from the end of the Rainbow (lol) cycle (Red)
  for (int x = 190; x >= 0; x--)
  {

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
            

if (Bank == 1){
  if (Mode == 4) {

      //Change the maximum brightness of the LED using potantiometer A1
      rainbowBright = map(analogRead(A1), 0, 1024, 0, 100);
      MaxBrightReduction = map(analogRead(A1), 0, 1024, 0, MaxBright);
      pixel.setBrightness(rainbowBright);
      strip.setBrightness(MaxBrightReduction);
      FastLED.setBrightness(MaxBrightReduction);
      inner.setBrightness(rainbowBright);
      showLEDS();
      //Serial.println("Mode 4 rainbowBright: " + String(rainbowBright));
    }
    if (Mode == 5) {

      //Change the maximum brightness of the LED using potantiometer A1

      valueA1 = map(analogRead(A1), 0, 1024, 0, 255);
      randomAmount = random(0, 255);
      //Serial.println("Mode 5 randomAmount: " + String(randomAmount));
      //Serial.println("Mode 5 rainbowBright: " + String(rainbowBright));
  }
  else;
}

if (Bank == 2){
    if (Mode == 1) {

      //Change the maximum brightness of the LED using potantiometer A1
      rainbowBright = map(analogRead(A1), 0, 1024, 0, 100);
      MaxBrightReduction = map(analogRead(A1), 0, 1024, 0, MaxBright);
      pixel.setBrightness(rainbowBright);
      strip.setBrightness(MaxBrightReduction);
      FastLED.setBrightness(MaxBrightReduction);
      inner.setBrightness(rainbowBright);
      showLEDS();
      //Serial.println("Mode 4 rainbowBright: " + String(rainbowBright));
    }
    if (Mode == 2) {

          //Change the maximum brightness of the LED using potantiometer A1

      valueA1 = map(analogRead(A1), 0, 1024, 0, 255);
      randomAmount = random(0, 255);
      //Serial.println("Mode 5 randomAmount: " + String(randomAmount));
      //Serial.println("Mode 5 rainbowBright: " + String(rainbowBright));
  }
  else;
}
if (Bank == 3){

}
else;

    //Change the rate of the rainbow cycling using potantiometer A0
    //Reduces the value of the R value causing a fade out;
    
    for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
              strip.setPixelColor(p, x,0,0);
    }
    pixel.setPixelColor(0, x, 0, 0);
    inner.setPixelColor(0, x, 0, 0);
    //A delay amount between each reduction in value mapped to A0 and divided
    delayA0(fadeSpeed / 500);
    //Serial.println("Rainbow 4 fadeSpeeed: " + String(fadeSpeed));
    showLEDS();
    
    plotCycle();
  }

  //Add a delay (ms) at the end of the rainbow cycle using potantiometer A2 while the LED is dark
  //valueA1 = map(analogRead(A1), 0, 1024, 0, 30);
  delayA2(darkDelay);

  plotCycle();

  //Serial.println("Rate of Rainbow cycling: " + String(valueA0)  + " ||| Delay between Rainbow cycles (ms): " + String(valueA1) + " ||| Maximum Brightness value: " + String(valueA2));

}
