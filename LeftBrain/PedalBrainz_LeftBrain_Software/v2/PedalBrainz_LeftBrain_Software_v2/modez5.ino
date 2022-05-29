/*

  ////////////////////
  ////////////////////        Bank 5 Attractorz
  ////////////////////

  
//thomas

b = 0.19;

x = 1;
y = 2;
z = 1;

timestep = .1;

//arneodo

a = -5.5;
b = 3.5;
c = -1;

x = 0.5;
y = 0.1;
z = 0.3;

//timestep = 0.01;
timestep = 0.008;

//chen

a = 5.0;
b = -10.0;
c = -0.38;

x = 5;
y = 10;
z = 10;

timestep = 0.005;

//scroll 3 

a = 40.0;
b = 0.833;
c = 20.0;
d = 0.5;
e = 0.65;

x = 2.1;
y = 0.9;
z = 1.2;

timestep = 0.01;

//lorentz83

 a = 0.95;
 b = 7.91;
 f = 4.83;
 g = 4.66;

 x = -0.2;
 y = -2.82;
 z = 2.71;

timestep = 0.005;

//dadras

a = 3;
b = 2.7;
c = 1.7;
d = 2;
e = 9;

x = 0.5;
y = 0.1;
z = 0.3;

timestep = 0.01;
*/


void modeStartupBank5(){

    maxBrightnessSet();
    
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

void Bank5()
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

    Attractorz

  */

  // Thomas
  if (Mode == 1)
  {
    //Serial.println("Mode 1 Started fadespeed " + String(fadeSpeed));
    
    // Run a color palette routine to signify the specific Bank
    bankFlash();
    initialBank = false;
   
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      //modeFlash();

      // Do some startup stuff for this Bank/ Mode if anything needs to be done
      modeStartupBank5();
      
      //          thomas attractor init maths

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
        strangeAttractor2();
      }
        // Wait for the Mode Change
        modeChangeWait();
    }
  }

  // 
  if (Mode == 2)
  {
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      //modeFlash();

      // Do some startup stuff for this Bank/ Mode if anything needs to be done
      modeStartupBank5();
      
      //          arneodo attractor init maths

      a = -5.5;
      b = 3.5;
      c = -1;

      x = 0.5;
      y = 0.1;
      z = 0.3;

      timestep = 0.008;

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
        strangeAttractor2();
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
      modeStartupBank5();

      //          chen attractor init maths

      a = 5.0;
      b = -10.0;
      c = -0.38;

      x = 5;
      y = 10;
      z = 10;

      timestep = 0.005;

  
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
        strangeAttractor2();
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

      //          scroll 3 attractor init maths

      a = 40.0;
      b = 0.833;
      c = 20.0;
      d = 0.5;
      e = 0.65;

      x = 2.1;
      y = 0.9;
      z = 1.2;

      timestep = 0.01;
      
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
        strangeAttractor2();
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

      //          lorentz83 attractor init maths

      a = 0.95;
      b = 7.91;
      f = 4.83;
      g = 4.66;

      x = -0.2;
      y = -2.82;
      z = 2.71;

      timestep = 0.005;

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
        strangeAttractor2();
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

      //          halvorsen attractor init maths

       x = -1.48;
       y = -1.51;
       z = 2.04;

       a = 1.89;

       timestep = 0.01;
      
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
        strangeAttractor2();
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

      //          Rabinovich-Fabrikant attractor init maths

       Blink1 = true;
       
       x = -1.00;
       y = 0.00;
       z = 0.50;

       a = 0.14;
       b = 0.1;

       timestep = 0.01;
    
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
        strangeAttractor2();        
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

      //          rossler attractor init maths

       x = 10.0;
       y = 0;
       z = 10.0;

       a = 0.2;
       b = 0.2;
       c = 5.7;

       timestep = 0.01;


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
        strangeAttractor2();
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

      //          Sprott attractor init maths

      x = 0.63;
      y = 0.47;
      z = -0.54;

      a = 2.07;
      b = 1.79;

      timestep = 0.01;

    
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
        strangeAttractor2();
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

      //          Four wings attractor init maths


      x = 0.63;
      y = 0.47;
      z = -0.54;

      a = 0.2;
      b = 0.01;
      c = -0.4;

      timestep = 0.05;


      
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
        strangeAttractor2();
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
}
