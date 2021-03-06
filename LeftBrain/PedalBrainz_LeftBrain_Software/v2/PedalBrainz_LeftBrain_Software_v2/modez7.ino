/**

  Bank 1 - Modez
  
  This is where the Mode switching and waiting happens within the loop.

  If Bank and Mode are True:
  -Initialize some things
  -Loop the Mode
  -Wait for the Mode Change

  Mode 1 | Squarez 
  A0 = Speed between 2 Blinks
  A1 = Blink 1 Color Value (Brightness)
  A2 = Blink 2 Color Value (Brightness)

  Mode 2 | Trainglez 
  A0 = Fade speed of LED
  A1 = Duration when LED is fully on (It's Lit)
  A2 = Duration when LED is fully off (It's Dark)

  Mode 3 | Trainglez Random
  A0 = Amount of Random Time Added to A1, A2
  A1 = Duration when LED is fully on (It's Lit)
  A2 = Duration when LED is fully off (It's Dark)

  Mode 4 | Rainbowz
  A0 = Rainbow Cycle Speed
  A1 = Maximum Brightness
  A2 = Duration when LED is fully off (It's Dark)

  Mode 5 | Rainbowz Random
  A0 = Rainbow Cycle Speed
  A1 = Randomized Maximum Brightness
  A2 = Duration when LED is fully off (It's Dark)

  Mode 6 | Mountainz Random Repeat
  A0 = Cycle Speed
  A1 = Amount of Randomness
  A2 = Chance of Snack

  Mode 7 | Mountainz Random Random
  A0 = Cycle Speed
  A1 = Amount of Randomness
  A2 = Chance of Snack

  Mode 8 | Strange Attractorz Single
  A0 = Cycle Speed
  A1 = Maximum Brightness
  A2 = Amount of Randomness

  Mode 9 | Strange Attractorz Double
  A0 = Cycle Speed
  A1 = Maximum Brightness
  A2 = Amount of Randomness

  Mode 10 | Strange Attractorz Triple
  A0 = Cycle Speed
  A1 = Maximum Brightness
  A2 = Amount of Randomness

*/

void Bank7()
{
 plotCycle();

  /**

    Fadez

  */

  // Squarez
  if (Mode == 1)
  {
    //Serial.println("Mode 1 Started fadespeed " + String(fadeSpeed));
    
    bankFlash();
    initialBank = false;
    Blink1 = true;
    
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      //modeFlash();

      //Do the last thing and WaitForModeChange

      if (Blink1 = true)
          {
            valueA1 = map(analogRead(A1), 0, 1024, 0, 20);
            for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
              strip.setPixelColor(p, valueA1, (valueA1/5), 0);
            }
            pixel.setPixelColor(0, valueA1, (valueA1/5), 0); // Blink 1
            pixel.setBrightness(valueA1);
            pixel.show();
            strip.setBrightness(valueA1);
            strip.show();
          }
      if (Blink1 = false)
          {
            valueA2 = map(analogRead(A2), 0, 1024, 0, 255);
            for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
              strip.setPixelColor(p,  (valueA2/6), valueA2, valueA2);
            }
            pixel.setPixelColor(0, (valueA2/6), valueA2, valueA2); // Blink 2
            pixel.setBrightness(valueA2);
            pixel.show();
            strip.setBrightness(valueA2);
            strip.show();
          }  
      pixel.show();
      strip.show();

      //writeStartupDataz();
      

      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
    else
    {
      if (WaitForModeChange)
      {

        //Call the main routine and loop the thing
        fadeSpeed = 10;
        Squarez_01 ();
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }

  // Trianglez
  if (Mode == 2)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      modeFlash();

      //Do the last thing and WaitForModeChange

      pixel.setBrightness(255);
      pixel.setPixelColor(0, 36, 0, 255);
      //0,0,255
      pixel.show();

      strip.setBrightness(MaxBright);
      for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
         strip.setPixelColor(p, 36, 0, 255);
      }
      strip.show();

      //writeStartupDataz();
     

      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
    else
    {
      if (WaitForModeChange)
      {

        // Call the main routine and loop the thing
        fadeSpeed = 10;
        fadez1 ();
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }

  // Trianglez Repeat
  if (Mode == 3)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      modeFlash();

      //Do the last thing and WaitForModeChange

      pixel.setBrightness(255);
      pixel.setPixelColor(0, 0, 255, 60);
      //31,255,60
      pixel.show();

      //writeStartupDataz();
      strip.setBrightness(MaxBright);
      for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
         strip.setPixelColor(p, 36, 0, 255);
      }
      strip.show();     

      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
    else
    {
      if (WaitForModeChange)
      {

        // Call the main routine and loop the thing
        fadeSpeed = 10;
        fadez1 ();
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }

  //Rainbow 01
  if (Mode == 4)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      modeFlash();

      //Do the last thing and WaitForModeChange

      pixel.setBrightness(100);
      pixel.setPixelColor(0, 36, 200, 10);
      pixel.show();

      strip.setBrightness(MaxBright);
      for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
         strip.setPixelColor(p, 36, 200, 10);
      }
      strip.show();      

      //writeStartupDataz();

      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
    else
    {
      if (WaitForModeChange)
      {

        //Call the main routine and loop the thing
        fadeSpeed = -1;
        RainbowMode ();
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }

  //Rainbow 02
  if (Mode == 5)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      modeFlash();

      //Do the last thing and WaitForModeChange

      pixel.setBrightness(100);
      pixel.setPixelColor(0, 36, 200, 10);
      pixel.show();

      strip.setBrightness(MaxBright);
      for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
         strip.setPixelColor(p, 36, 200, 10);
      }
      strip.show();      

      //writeStartupDataz();

      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
    else
    {
      if (WaitForModeChange)
      {

        //Call the main routine and loop the thing
        fadeSpeed = -1;
        RainbowMode ();
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }

  // Mountain Snack Mode
  if (Mode == 6)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      modeFlash();

      // Do the last thing and WaitForModeChange

      pixel.setBrightness(100);
      pixel.setPixelColor(0, 36, 200, 10);
      pixel.show();

      strip.setBrightness(MaxBright);
      for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
         strip.setPixelColor(p, 36, 200, 10);
      }
      strip.show(); 
      
      //writeStartupDataz();

      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
     else
    {
      if (WaitForModeChange)
      {

        //Call the main routine and loop the thing
        mountainSnack ();
        reRandom = false;
        
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }

 // Mountain Snack Mode
  if (Mode == 7)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      modeFlash();

      //Do the last thing and WaitForModeChange

      pixel.setBrightness(100);
      pixel.setPixelColor(0, 36, 200, 10);
      pixel.show();

      strip.setBrightness(MaxBright);
      for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
         strip.setPixelColor(p, 36, 200, 10);
      }
      strip.show(); 
      
      //writeStartupDataz();  

      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
     else
    {
      if (WaitForModeChange)
      {

        //Call the main routine and loop the thing
        mountainSnack ();
        reRandom = true;
        
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }

  // Strange Attractor 1
  if (Mode == 8)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      modeFlash();

      //Do the last thing and WaitForModeChange

      pixel.setBrightness(100);
      pixel.setPixelColor(0, 36, 200, 10);
      pixel.show();

      strip.setBrightness(MaxBright);
      for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
         strip.setPixelColor(p, 36, 200, 10);
      }
      strip.show(); 
      
      //writeStartupDataz();

      x = 0.01;
      y = 0.3;
      z = 0.7;

      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
    else
    {
      if (WaitForModeChange)
      {

        //Call the main routine and loop the thing
        strangeAttractor ();
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }

  // Strange Attractor 2
  if (Mode == 9)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      modeFlash();

      //Do the last thing and WaitForModeChange

      pixel.setBrightness(100);
      pixel.setPixelColor(0, 36, 200, 10);
      pixel.show();

      strip.setBrightness(MaxBright);
      for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
         strip.setPixelColor(p, 36, 200, 10);
      }
      strip.show(); 
      
      //writeStartupDataz();

      x = 0.1;
      y = 2;
      z = 1;

      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
     else
    {
      if (WaitForModeChange)
      {

        //Call the main routine and loop the thing
        strangeAttractor ();
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }

  // Strange Attractor 3
  if (Mode == 10)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      modeFlash();

      //Do the last thing and WaitForModeChange

      pixel.setBrightness(100);
      pixel.setPixelColor(0, 36, 200, 10);
      pixel.show();

      strip.setBrightness(MaxBright);
      for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
         strip.setPixelColor(p, 36, 200, 10);
      }
      strip.show(); 
      
      //writeStartupDataz();
      
      x = 0.5;
      y = 0.9;
      z = 0.1;

      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
     else
    {
      if (WaitForModeChange)
      {

        // Call the main routine and loop the thing
        //strangeAttractor ();
        oceanz();
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }
  if (Mode == 98)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      modeFlash();

      //Do the last thing and WaitForModeChange
      
      //writeStartupDataz();
      
      x = 0.5;
      y = 0.9;
      z = 0.1;

      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
     else
    {
      if (WaitForModeChange)
      {

        // Call the main routine and loop the thing
        lightLoopz();
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }
  
  if (Mode == 99)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      modeFlash();

      //Do the last thing and WaitForModeChange

      pixel.setBrightness(100);
      pixel.setPixelColor(0, 36, 200, 10);
      pixel.show();

      strip.setBrightness(MaxBright);
      for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
         strip.setPixelColor(p, 36, 200, 10);
      }
      strip.show(); 
      
      //writeStartupDataz();
      
      x = 0.5;
      y = 0.9;
      z = 0.1;

      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
     else
    {
      if (WaitForModeChange)
      {

        // Call the main routine and loop the thing
        testColorPotentiometer();
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }
  if (Mode == 102)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      modeFlash();

      //Do the last thing and WaitForModeChange

      pixel.setBrightness(100);
      pixel.setPixelColor(0, 36, 200, 10);
      pixel.show();

      strip.setBrightness(MaxBright);
      for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
         strip.setPixelColor(p, 36, 200, 10);
      }
      strip.show(); 
      
      //writeStartupDataz();
      
      x = 0.5;
      y = 0.9;
      z = 0.1;

      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
     else
    {
      if (WaitForModeChange)
      {

        // Call the main routine and loop the thing
        testBrightPotentiometer();
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }
  if (Mode == 999)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      modeFlash();

      //Do the last thing and WaitForModeChange
      darkLED();
      //writeStartupDataz();
      
      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
     else
    {
      if (WaitForModeChange)
      {

        // Call the main routine and loop the thing
        memoryGame();
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }  

}
