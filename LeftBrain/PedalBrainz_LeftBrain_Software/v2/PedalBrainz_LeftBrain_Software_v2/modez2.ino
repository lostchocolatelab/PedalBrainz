/**

Bank 2 - Modez

This is where the Mode switching and waiting happens within the loop.

If Bank and Mode are True:
-Initialize some things
-Loop the Mode
-Wait for the Mode Change

Mode 1 | Quad Rainbowz Fixed - Uses randomBright01-04 Declared in General Declarations
A0 = Rainbow Cycle Speed
A1 = Maximum Brightness
A2 = Duration when LED is fully off (It's Dark)

Mode 2 | Quad Rainbowz Random Once - Randomize Brightness values for the 4 values once at startup
A0 = Rainbow Cycle Speed
A1 = Randomized Maximum Brightness
A2 = Duration when LED is fully off (It's Dark)

Modez 3 | Quad Rainbowz Random Random - Randomize Brightness values for the 4 values after each cycle
A0 = Duration of 4th brightness after brightness changes for a single color
A1 = Delay of each Brightness Value (4) for a Single Color
A2 = Duration of Darkness after full Color Cycle (or betwixt each color if darkDelayBetwixtColors is enabled)

Mode 4 | Mountainz Rainbow Random Repeat
A0 = Cycle Speed
A1 = Amount of Randomness
A2 = Chance of Snack

Mode 5 | Mountainz Rainbow Random Random
A0 = Cycle Speed
A1 = Amount of Randomness
A2 = Chance of Snack

Mode 6 | Mountainz Rainbow Random Random Slow
A0 = Cycle Speed
A1 = Amount of Randomness
A2 = Chance of Snack

Mode 7 | Rainbow Squarez
A0 = Rainbow Cycle Speed
A1 = Maximum Brightness
A2 = Duration when LED is fully off (It's Dark)

Mode 8 | Rainbow Squarez Modulate
A0 = Rainbow Cycle Speed
A1 = Maximum Brightness
A2 = Duration when LED is fully off (It's Dark)

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

      // RainbowQuad
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
        Squarez_03();
      }
      // Wait for the Mode Change
      modeChangeWait();
    }
  }

      // RainbowQuad
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
        Squarez_02();
      }
      // Wait for the Mode Change
      modeChangeWait();
    }
  }

      // RainbowQuad
  if (Mode == 3)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      //modeFlash();

      // Do some startup stuff for this Bank/ Mode if anything needs to be done
      modeStartupBank2();

      //writeStartupDataz();
      startIndex = 0;

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
        trianglez1();
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

      //writeStartupDataz();
      startIndex = 0;

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
        trianglez1();
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

      //writeStartupDataz();
      startIndex = 0;

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
        trianglez1();
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

      //writeStartupDataz();
      startIndex = 0;

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
      // RainbowSquarez
  if (Mode == 7)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      //modeFlash();

      // Do some startup stuff for this Bank/ Mode if anything needs to be done
      modeStartupBank2();

      //writeStartupDataz();
      startIndex = 0;

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

      // RainbowSquarez
  if (Mode == 8)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      //modeFlash();

      // Do some startup stuff for this Bank/ Mode if anything needs to be done
      modeStartupBank2();

      //writeStartupDataz();
      startIndex = 0;

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

      // RainbowSquarezRamping
  if (Mode == 9)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      //modeFlash();

      // Do some startup stuff for this Bank/ Mode if anything needs to be done
      modeStartupBank2();

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
      fadez3();
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
      for (int p = 0; p < strip.numPixels(); p++) {       // For each pixel in strip...
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
      for (int p = 0; p < strip.numPixels(); p++) {       // For each pixel in strip...
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
}
