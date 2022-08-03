/**

  ////////////////////        Bank 1 
  ////////////////////        Greatezt Hitz
  ////////////////////        Modez

  This is where the Mode switching and waiting happens within the loop.

  If Bank and Mode are True:
  -Initialize some things
  -Loop the Mode
  -Wait for the Mode Change

  Mode 1 | Squarez
  A0 = Blink Speed
  A1 = Blink 1 Brightness
  A2 = Blink 2 Brightness

  Mode 2 | Trainglez
  A0 = Fade Speed
  A1 = Duration of Maximum Brightness
  A2 = Duration of Minimum Brightness

  Mode 3 | Trainglez Random
  A0 = Amount of Random Time Added to A1, A2
  A1 = Duration of Maximum Brightness
  A2 = Duration of Minimum Brightness

  Mode 4 | Rainbowz
  A0 = Rainbow Cycle Speed
  A1 = Maximum Brightness
  A2 = Duration of Minimum Brightness

  Mode 5 | Rainbowz Random
  A0 = Rainbow Cycle Speed
  A1 = Randomized Maximum Brightness
  A2 = Duration of Minimum Brightness

  Mode 6 | Mountainz Random Repeat
  A0 = Cycle Speed
  A1 = Amount of Randomness
  A2 = Chance of Snack

  Mode 7 | Mountainz Random Random
  A0 = Cycle Speed
  A1 = Amount of Randomness
  A2 = Chance of Snack

  Mode 8 | Strange Attractorz Singlez
  A0 = Cycle Speed
  A1 = Maximum Brightness
  A2 = Amount of Randomness

  Mode 9 | Strange Attractorz Doublez
  A0 = Cycle Speed
  A1 = Maximum Brightness
  A2 = Amount of Randomness

  Mode 10 | Strange Attractorz Triplez
  A0 = Cycle Speed
  A1 = Maximum Brightness
  A2 = Amount of Randomness

*/
void modeStartupBank1() {

  maxBrightnessSet();
  //zeroVariables();

  //  Set Up something before jumping into the Mode Routine
  
    if (Mode == 1)
    {

      //valueA1 = map(analogRead(A1), 0, 1024, 0, 20);
      for (int p = 0; p < strip.numPixels(); p++) {       // For each pixel in strip...
        strip.setPixelColor(p, 0, 0, 0);
      }
      pixel.setPixelColor(0, 0, 0, 0);       //
      inner.setPixelColor(0, 0, 0, 0);       //

      showLEDS();

    }
    else if (Mode == 2)
    {

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

  showLEDS();
}

void Bank1()
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

      // Do some startup stuff for this Bank/ Mode if anything needs to be done
      modeStartupBank1();

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
        fadeSpeed = 50;
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
      //modeFlash();

      modeStartupBank1();

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
        //fadeSpeed = 0;
        fadez3();
        
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
      //modeFlash();

      modeStartupBank1();

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
        fadeSpeed = 0;
        fadez3 ();
      
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
      //modeFlash();

      modeStartupBank1();

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
      //modeFlash();

      modeStartupBank1();

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
      //modeFlash();

      modeStartupBank1();

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
      //modeFlash();

      modeStartupBank1();

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
      //modeFlash();

      modeStartupBank1();

      //writeStartupDataz();

      //Do the last thing and WaitForModeChange

      strangeDelayReset();

      lx = 0.01;
      ly = 0.3;
      lz = 0.7;

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
      //modeFlash();

      modeStartupBank1();

      //writeStartupDataz();

      //Do the last thing and WaitForModeChange

      strangeDelayReset();

      lx = 0.1;
      ly = 2;
      lz = 1;

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
      //modeFlash();

      modeStartupBank1();

      //writeStartupDataz();

      //Do the last thing and WaitForModeChange

      strangeDelayReset();

      lx = 0.5;
      ly = 0.9;
      lz = 0.1;

      waitingFlag = true;
      WaitForModeChange = true;
      Serial.println(" WaitForModeChange = True");
    }
    else
    {
      if (WaitForModeChange)
      {

        // Call the main routine and loop the thing
        strangeAttractor ();
        //oceanz();
      }
      // Wait for the Mode Change
      modeChangeWait();
    }
  }

 /*
  *       BONUS MODEZ
  *
  *       Loop into some special Modez     
  *       and possibly do something cool
  *       Under certain conditionz
  *
  */

  modezBonus();

}
