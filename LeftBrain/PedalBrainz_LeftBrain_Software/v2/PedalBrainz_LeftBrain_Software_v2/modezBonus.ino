 /*
  *       BONUS MODEZ
  *
  *       Loop into some special Modez     
  *       and possibly do something cool
  *       Under certain conditionz
  *
  */

void modezBonus()
{

  if (Mode == 98)  // Light Loopz 
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
  if (Mode == 102)  //  RGB Color Mixer Test
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

      // Call the main routine and loop the thing
        testBrightPotentiometer();
      }
      // Wait for the Mode Change
      modeChangeWait();
    }
  }
  if (Mode == 103)  //  Curve Tes
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

      // Call the main routine and loop the thing
        testCurve();
      }
      // Wait for the Mode Change
      modeChangeWait();
    }
  }  
  if (Mode == 999)  //  Memory Game
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