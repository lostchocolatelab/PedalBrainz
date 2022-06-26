/**

  ////////////////////        Bank 3 
  ////////////////////        Rainbowz
  ////////////////////        Modez

  This is where the Mode switching and waiting happens within the loop.

  If Bank and Mode are True:
  -Initialize some things
  -Loop the Mode
  -Wait for the Mode Change

  Mode 1 | Rainbowz Shift
  A0 = Rainbow Cycle Speed
  A1 = Maximum Brightness
  A2 = Color Hue Shift

  Mode 2 | Rainbowz Stepz Set - Uses Declared Brightness values for the 4 values (randomBright01-04)
  A0 = Rainbow Cycle Speed
  A1 = Duration of Maximum Brightness
  A2 = Duration of Minimum Brightness

  Mode 3 | Rainbow Stepz Random Once - Randomize Brightness values for the 4 values once at startup
  A0 = Rainbow Cycle Speed
  A1 = Duration of 4th Color Value
  A2 = Duration of 1st Color Value

  Modez 4 | Rainbow Stepz Random Random - Randomize Brightness values for the 4 values after each cycle
  A0 = Rainbow Cycle Speed
  A1 = Duration of 4th Color Value
  A2 = Duration of 1st Color Value

  Mode 5 | Rainbow Sawz Set - Uses randomBright01-04 Declared in General Declarations
  A0 = Cycle Speed
  A1 = Maximum Brightness
  A2 = Saw Direction 

  Mode 6 | Rainbow Sawz Random Once - Randomize Brightness values for the 4 values once at startup
  A0 = Cycle Speed
  A1 = Maximum Brightness
  A2 = Saw Direction 

  Mode 7 | Rainbow Sawz Random Random - Randomize Brightness values for the 4 values after each cycle
  A0 = Cycle Speed
  A1 = Maximum Brightness
  A2 = Saw Direction 

  Mode 7 | Rainbow Squarez 
  A0 = Rainbow Cycle Speed
  A1 = Maximum Brightness
  A2 = Duration when LED is fully off (It's Dark)

  Mode 8 | Rainbow Squarez Modulate
  A0 = Rainbow Cycle Speed
  A1 = Maximum Brightness
  A2 = Duration when LED is fully off (It's Dark)  

*/

void modeStartupBank3(){

  maxBrightnessSet();
    
  //  Set Up something before jumping into the Mode Routine

    if (Mode == 1)
    {

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
    else;
                              
  showLEDS();
}

void Bank3()
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
  
  // Rainbow Shift
  if (Mode == 1)
  {
    //Serial.println("Mode 1 Started fadespeed " + String(fadeSpeed));
    
    bankFlash();
    initialBank = false;
   
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      //modeFlash();

      // Do some startup stuff for this Bank/ Mode if anything needs to be done
      modeStartupBank3();
      
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
        valueA0  = 7;
        rainbowNew();
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }

  // RainbowQuad
  if (Mode == 2)
  {
    //Serial.println("Mode 1 Started fadespeed " + String(fadeSpeed));
    
   
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      //modeFlash();

      // Do some startup stuff for this Bank/ Mode if anything needs to be done
      modeStartupBank3();
      
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
        fadeUp = true;
        RainbowQuad();
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
      modeStartupBank3();

      fadeUp = true;
      randomOnce = 0;
      
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
        RainbowQuad();
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }

  // RainbowQuad
  if (Mode == 4)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      //modeFlash();

      // Do some startup stuff for this Bank/ Mode if anything needs to be done
      modeStartupBank3();
      
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
        RainbowQuad();
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }

  // RainbowMountainRepeat
  if (Mode == 5)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      //modeFlash();

      // Do some startup stuff for this Bank/ Mode if anything needs to be done
      modeStartupBank3();

      fadeUp = true;
      
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
        RainbowQuad();
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }

  // RainbowMountainRandom
  if (Mode == 6)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      //modeFlash();

      // Do some startup stuff for this Bank/ Mode if anything needs to be done
      modeStartupBank3();

      randomOnce = 0;
      
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
        RainbowQuad();
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }

  // RainbowMountainPulse
  if (Mode == 7)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      //modeFlash();

      // Do some startup stuff for this Bank/ Mode if anything needs to be done
      modeStartupBank3();

      fadeUp = true;
      
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
        RainbowQuad();
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
      modeStartupBank3();
      
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
        RainbowSquarez();
        
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }

 // RainbowSquarez
  if (Mode == 9)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      //modeFlash();

      // Do some startup stuff for this Bank/ Mode if anything needs to be done
      modeStartupBank3();
      
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
        increaseValue = true;
        //fadeSpeed = 10;
        RainbowSquarez();
        
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }

  // RainbowSquarezRamping
  if (Mode == 10)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      //modeFlash();

      // Do some startup stuff for this Bank/ Mode if anything needs to be done
      modeStartupBank3();
      
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
        twinkelz();
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
