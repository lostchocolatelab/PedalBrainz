/**

  ////////////////////        Bank 4 
  ////////////////////        Naturez
  ////////////////////        Modez
  
  This is where the Mode switching and waiting happens within the loop.

  If Bank and Mode are True:
  -Initialize some things
  -Loop the Mode
  -Wait for the Mode Change

  Mode 1 | Firez
  A0 = Sparking
  A1 = Maximum Brightness
  A2 = Cooling

  Mode 2 | Rolling Hillz Random Random
  A0 = Cycle Speed
  A1 = Chance of Snack
  A2 = Amount of Randomness

  Mode 3 | Sunset Hillz Random Random
  A0 = Cycle Speed
  A1 = Chance of Snack
  A2 = Amount of Randomness

  Mode 4 | Shallow Hillz
  A0 = Cycle Speed
  A1 = Dark Duration
  A2 = Amount of Randomness

  Mode 5 | Shallow Mountainz
  A0 = Cycle Speed
  A1 = Dark Duration
  A2 = Amount of Randomness

  Mode 6 | Dripz
  A0 = Fade Speed
  A1 = Maximum Brightness
  A2 = Dark Duration 

  Mode 7 | Meteorz1
  A0 = Fade Speed
  A1 = Duration of Maximum Brightness
  A2 = Duration of Minimum Brightness

  Mode 8 | Meteorz2
  A0 = Fade Speed
  A1 = Duration of Maximum Brightness
  A2 = Duration of Minimum Brightness

  Mode 9 | Oceanz
  A0 = Fade Speed
  A1 = Maximum Brightness
  A2 = Color Hue Shift

  Mode 10 | Fire Oceanz
  A0 = Fade Speed
  A1 = Maximum Brightness
  A2 = Color Hue Shift

*/

void modeStartupBank4(){

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

void Bank4()
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

  // Mountainz Snack
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
      modeStartupBank4();
      
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
        fire1();
        //dripz();
        //meteorz();
        //meteorz2();
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }

  // Mountainz
  if (Mode == 2)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      //modeFlash();

      // Do some startup stuff for this Bank/ Mode if anything needs to be done
      modeStartupBank4();
      
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
        mountainSnack ();
        reRandom = true;
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }

  // 
  if (Mode == 3)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      //modeFlash();

      // Do some startup stuff for this Bank/ Mode if anything needs to be done
      modeStartupBank4();
      
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
        mountainSnack ();
        reRandom = true;
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }

  // 
  if (Mode == 4)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      //modeFlash();

      // Do some startup stuff for this Bank/ Mode if anything needs to be done
      modeStartupBank4();
      
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
        dripz();
        mountainSnack ();
        reRandom = true;
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }

  // 
  if (Mode == 5)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      //modeFlash();

      // Do some startup stuff for this Bank/ Mode if anything needs to be done
      modeStartupBank4();
      
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
        dripz();
        mountainSnack ();
        reRandom = true;
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }

  // 
  if (Mode == 6)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      //modeFlash();

      // Do some startup stuff for this Bank/ Mode if anything needs to be done
      modeStartupBank4();
      
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
        //fire1();
        dripz();
        //meteorz();
        //meteorz2();
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }
  // 
  if (Mode == 7)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      //modeFlash();

      // Do some startup stuff for this Bank/ Mode if anything needs to be done
      modeStartupBank4();
      
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
        //fire1();
        //dripz();
        meteorz();
        //meteorz2();
        
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }

 // 
  if (Mode == 8)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      //modeFlash();

      // Do some startup stuff for this Bank/ Mode if anything needs to be done
      modeStartupBank4();
      
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
        //fire1();
        //dripz();
        //meteorz();
        meteorz2();
        
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }

  // 
  if (Mode == 9)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      //modeFlash();

      // Do some startup stuff for this Bank/ Mode if anything needs to be done
      modeStartupBank4();
      
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
        oceanz();
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }

  // 
  if (Mode == 10)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      //modeFlash();

      // Do some startup stuff for this Bank/ Mode if anything needs to be done
      modeStartupBank4();
      
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
        fire1();
        oceanz();
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
