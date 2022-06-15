/**

  ////////////////////        Bank 6 
  ////////////////////        Fancyz
  ////////////////////        Modez

   
  This is where the Mode switching and waiting happens within the loop.

  If Bank and Mode are True:
  -Initialize some things
  -Loop the Mode
  -Wait for the Mode Change

  Mode 1 | Attractorz
  A0 = Cycle Speed
  A1 = Maximum Brightness
  A2 = Roughness  

  fire
  popFade
  meteorz1
  meteorz2

*/

void modeStartupBank6(){

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

void Bank6()
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
      modeStartupBank6();
      
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
        //palette1();
        fire1();
        //popFade();
        //breather1();
        //dripz();
        //meteorz();
        //meteorz();
        //meteorz2();
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }


  if (Mode == 2)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      //modeFlash();

      // Do some startup stuff for this Bank/ Mode if anything needs to be done
      modeStartupBank6();
      
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
        //palette1();
        //fire1();
        popFade();
        //breather1();
        //dripz();
        //meteorz();
        //meteorz();
        //meteorz2();
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }


  if (Mode == 3)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      //modeFlash();

      // Do some startup stuff for this Bank/ Mode if anything needs to be done
      modeStartupBank5();

      x = 0.5;
      y = 0.9;
      z = 0.1;
      
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
        //palette1();
        //fire1();
        //popFade();
        //breather1();
        //dripz();
        meteorz();
        //meteorz2();
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
      modeStartupBank5();
      
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
        //palette1();
        //fire1();
        //popFade();
        //breather1();
        //dripz();
        //meteorz();
        //meteorz();
        meteorz2();
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
      modeStartupBank5();
      
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
        palette1();
        //fire1();
        //popFade();
        //breather1();
        //dripz();
        //meteorz();
        //meteorz();
        //meteorz2();
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
      modeStartupBank5();
      
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
        palette1();
        //fire1();
        //popFade();
        //breather1();
        //dripz();
        //meteorz();
        //meteorz();
        //meteorz2();
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
      modeStartupBank5();
      
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
        palette1();
        //fire1();
        //popFade();
        //breather1();
        //dripz();
        //meteorz();
        //meteorz();
        //meteorz2();
        
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
      modeStartupBank5();
      
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
        palette1();
        //fire1();
        //popFade();
        //breather1();
        //dripz();
        //meteorz();
        //meteorz();
        //meteorz2();
        
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

      // Do some startup stuff for this Bank/ Mode if anything needs to be done
      modeStartupBank5();
      
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
        palette1();
        //fire1();
        //popFade();
        //breather1();
        //dripz();
        //meteorz();
        //meteorz();
        //meteorz2();
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
      modeStartupBank5();
      
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
        palette1();
        //fire1();
        //popFade();
        //breather1();
        //dripz();
        //meteorz();
        //meteorz();
        //meteorz2();
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
