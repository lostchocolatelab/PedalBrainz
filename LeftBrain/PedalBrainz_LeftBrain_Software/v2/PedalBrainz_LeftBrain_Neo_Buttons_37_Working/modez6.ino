/**

  Bank 6 - Modez
  
  This is where the Mode switching and waiting happens within the loop.

  If Bank and Mode are True:
  -Initialize some things
  -Loop the Mode
  -Wait for the Mode Change

  Mode 1 | 

*/

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

  /**

    Tapz

  */

  // Tapz
   if (Mode == 1)
  {
    //Serial.println("Mode 1 Started fadespeed " + String(fadeSpeed));
    
   
    if (!waitingFlag)
    {
      // Flash the pixel at the start of a mode chnage
      modeFlash();

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
        //knobzRecorder();
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
