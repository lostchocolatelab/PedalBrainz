/**

  ////////////////////        Bank 2
  ////////////////////        Shapez
  ////////////////////        Modez

This is where the Mode switching and waiting happens within the loop.

If Bank and Mode are True:
-Initialize some things
-Loop the Mode
-Wait for the Mode Change

Mode 1 | Squarez Tilt
A0 = Blink Speed
A1 = Duration of Maximum Brightness
A2 = Duration of Minimum Brightness

Mode 2 | Squarez Random
A0 = Amount of Random Time Added to A1, A2
A1 = Duration of Maximum Brightness (Random)
A2 = Duration of Minimum Brightness (Random)

Mode 3 | Trainglez Doublez
A0 = Alternate Speed
A1 = Trianglez1 Fade Speed
A2 = Trianglez2 Fade Speed

Mode 4 | Trainglez Attractorz
A0 = Fade Speed
A1 = Maximum Brightness
A2 = Update Speed (How often the speed of the Attractor is applied)

Mode 5 | Sawz Up
A0 = Fade Speed
A1 = Duration of Maximum Brightness
A2 = Duration of Minimum Brightness

Mode 6 | Sawz Up Random
A0 = Fade Speed
A1 = Duration of Maximum Brightness (Random)
A2 = Duration of Minimum Brightness (Random)

Mode 7 | Sawz Down
A0 = Fade Speed
A1 = Duration of Maximum Brightness
A2 = Duration of Minimum Brightness

Mode 8 | Sawz Down Random
A0 = Fade Speed
A1 = Duration of Maximum Brightness (Random)
A2 = Duration of Minimum Brightness (Random)

Mode 9 | Sawz Random
A0 = Fade Speed
A1 = Duration of Maximum Brightness
A2 = Duration of Minimum Brightness

Mode 10 | Twinkelz
A0 = Fade Speed
A1 = Duration of Maximum Brightness
A2 = Twinkelz Frequency

*/

void modeStartupBank2() {

  maxBrightnessSet();

  if (Mode == 1)
  {

    maxBrightness = 255;

    for (int p = 0; p < strip.numPixels(); p++) {       // For each pixel in strip...
      strip.setPixelColor(p, 255, 0, 255/10);
    }
    pixel.setPixelColor(0, 255, 0, 255/10);
    inner.setPixelColor(0, 255, 0, 255/10);

    showLEDS();

  }
  else if (Mode == 2)
  {

    maxBrightness = 255;

    for (int p = 0; p < strip.numPixels(); p++) {       // For each pixel in strip...
      strip.setPixelColor(p, 255, 0, 255/10);
    }
    pixel.setPixelColor(0, 255, 0, 255/10);
    inner.setPixelColor(0, 255, 0, 255/10);

    showLEDS();

  }
  else if (Mode == 3)
  {

    maxBrightness = 255;

    for (int p = 0; p < strip.numPixels(); p++) {       // For each pixel in strip...
      strip.setPixelColor(p, 255, 0, 255/10);
    }
    pixel.setPixelColor(0, 255, 0, 255/10);
    inner.setPixelColor(0, 255, 0, 255/10);

    showLEDS();

  }
  else if (Mode == 4)
  {

  }
  else if (Mode == 5)
  {

  }
  else if (Mode == 6)
  {

  }
  else if (Mode == 7)
  {

  }
  else if (Mode == 8)
  {

  }
  else if (Mode == 9)
  {

  }
  else if (Mode == 10)
  {

  }
  else;

  showLEDS();
}

void Bank2()
{
      //Serial.println("I am Bank Number : 1");
      //readStartupMode();
      // Pring the Mode value currently initialized
      //Serial.println("Mode : "+ String(Mode));
      //writeStartupDataz();
      //Serial.println("Waiting for mode Change " + String(WaitForModeChange));

      //Serial.println("Bank 1 Start Bank - " + String(Bank));
      //Serial.println("Bank 1 Start Mode - " + String(Mode));
      //Serial.println("Bank 1 Start MaxBright - " + String(MaxBright));

      //Things are about to start kicking in...


  plotCycle();


  /**

  Fadez

  */

  // Squarez Tilt
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

      // Do some startup stuff for this Bank/ Mode if anything needs to be done
      modeStartupBank2();

      maxBrightness = 255;

      //writeStartupDataz();

      //Do the last thing and WaitForModeChange
      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
    else
    {
      if (WaitForModeChange)
      {

      //Call the main routine and loop the thing
        Squarez_03(); // Squarez Tilt
      }
      // Wait for the Mode Change
      modeChangeWait();
    }
  }

  // Squarez Tilt Random
  if (Mode == 2)
  {

    Blink1 = true;
    
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      //modeFlash();

      // Do some startup stuff for this Bank/ Mode if anything needs to be done
      modeStartupBank2();

      maxBrightness = 255;

      //writeStartupDataz();

      //Do the last thing and WaitForModeChange
      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
    else
    {
      if (WaitForModeChange)
      {

      // Call the main routine and loop the thing
        Squarez_03(); // Squarez Tilt
      }
      // Wait for the Mode Change
      modeChangeWait();
    }
  }

  // Trianglez Doublez
  if (Mode == 3)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      //modeFlash();

      // Do some startup stuff for this Bank/ Mode if anything needs to be done
      modeStartupBank2();

      maxBrightness = 255;

      //writeStartupDataz();

      //Do the last thing and WaitForModeChange
      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
    else
    {
      if (WaitForModeChange)
      {

      // Call the main routine and loop the thing
        Squarez_02(); // Trianglez Doublez
      }
      // Wait for the Mode Change
      modeChangeWait();
    }
  }

  // RainbowMountainRepeat
  if (Mode == 4)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      //modeFlash();

      // Do some startup stuff for this Bank/ Mode if anything needs to be done
      modeStartupBank2();

      maxBrightness = 255;

      //thomas

      b = 0.19;

      x = 1;
      y = 2;
      z = 1;
      
      timestep = .1;

      //writeStartupDataz();

      //Do the last thing and WaitForModeChange
      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
    else
    {
      if (WaitForModeChange)
      {

      //Call the main routine and loop the thing
        fadez4(); //  Trainglez Attractorz
      }
      // Wait for the Mode Change
      modeChangeWait();
    }
  }

      // RainbowMountainRandom
  if (Mode == 5)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      //modeFlash();

      // Do some startup stuff for this Bank/ Mode if anything needs to be done
      modeStartupBank2();

      maxBrightness = 255;

      //writeStartupDataz();
      fadeUp = true;

      //Do the last thing and WaitForModeChange
      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
    else
    {
      if (WaitForModeChange)
      {

      //Call the main routine and loop the thing
        sawzUp1();
      }
      // Wait for the Mode Change
      modeChangeWait();
    }
  }

      // RainbowMountainPulse
  if (Mode == 6)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      //modeFlash();

      // Do some startup stuff for this Bank/ Mode if anything needs to be done
      modeStartupBank2();

      maxBrightness = 255;

      //writeStartupDataz();
      fadeUp = true;

      //Do the last thing and WaitForModeChange
      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
    else
    {
      if (WaitForModeChange)
      {

      //Call the main routine and loop the thing
        sawzUp1();
      }
      // Wait for the Mode Change
      modeChangeWait();
    }
  }
  //  Sawz Down
  if (Mode == 7)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      //modeFlash();

      // Do some startup stuff for this Bank/ Mode if anything needs to be done
      modeStartupBank2();

      maxBrightness = 255;

      //writeStartupDataz();
      fadeUp = false;

      //Do the last thing and WaitForModeChange
      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
    else
    {
      if (WaitForModeChange)
      {

      //Call the main routine and loop the thing
        sawzDown1();
      }
      // Wait for the Mode Change
      modeChangeWait();
    }
  }

      // RainbowSquarez
  if (Mode == 8)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      //modeFlash();

      // Do some startup stuff for this Bank/ Mode if anything needs to be done
      modeStartupBank2();

      maxBrightness = 255;

      //writeStartupDataz();
      fadeUp = false;

      //Do the last thing and WaitForModeChange
      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
    else
    {
      if (WaitForModeChange)
      {

      //Call the main routine and loop the thing
      sawzDown1();
      }
      // Wait for the Mode Change
      modeChangeWait();
    }
  }

      // RainbowSquarezRamping
  if (Mode == 9)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      //modeFlash();

      // Do some startup stuff for this Bank/ Mode if anything needs to be done
      modeStartupBank2();

      maxBrightness = 255;

      //writeStartupDataz();

      //Do the last thing and WaitForModeChange
      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
    else
    {
      if (WaitForModeChange)
      {

      //Call the main routine and loop the thing
      sawzRandom1();
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
      //modeFlash();

      // Do some startup stuff for this Bank/ Mode if anything needs to be done
      modeStartupBank2();

      maxBrightness = 255;

      //writeStartupDataz();

      //Do the last thing and WaitForModeChange
      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
    else
    {
      if (WaitForModeChange)
      {

      // Call the main routine and loop the thing
        //valueA0  = 7;
        //rainbowNew();
        twinkelz();
      }
      // Wait for the Mode Change
      modeChangeWait();
    }
  }

 /*
  *
  *
  *
  *        BONUS MODEZ
  *
  *
  */

  if (Mode == 98)  // Light Loopz 
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      //modeFlash();

      modeStartupBank1();

      //writeStartupDataz();

      //Do the last thing and WaitForModeChange

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
  if (Mode == 99)  //  Potentiometer RGB Color test
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      //modeFlash();

      modeStartupBank1();

      //writeStartupDataz();

      //Do the last thing and WaitForModeChange

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

  if (Mode == 100)  // Time Multiplier
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      //modeFlash();

      modeStartupBank1();

      //writeStartupDataz();

      //Do the last thing and WaitForModeChange

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
        multiplierIndicator();
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
      //modeFlash();

      modeStartupBank1();

      //writeStartupDataz();

      //Do the last thing and WaitForModeChange

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
      //modeFlash();

      modeStartupBank1();

      //writeStartupDataz();

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
