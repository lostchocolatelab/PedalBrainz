/**

  Mode Change

*/
//
//


void modeChangeWait() {
  
   
    checkButtons();
    
      
}


void modeFlash() {

        /*pixel.setBrightness(70);
        pixel.setPixelColor(0, Sketch2Pink); // Pink
        pixel.show();
       delay(ModeFlashDelay);
        pixel.setPixelColor(0, 0x000000); // Blank
        pixel.show();
       delay(ModeFlashDelay);
        */

        //Serial.println("ModeFlash Bank - " + String(Bank));
        //Serial.println("ModeFlash Start Mode - " + String(Mode));
        //Serial.println("ModeFlash MaxBright - " + String(MaxBright));        
        
         /*// Flash Pink 3 Times bacause Pink is pretty cool
         for (int i = 0; i < 3; i++)
            {
              pixel.setBrightness(70);
              pixel.setPixelColor(0, Sketch2Pink); // Pink
              pixel.show();
             delay(ModeFlashDelay);
              pixel.setPixelColor(0, 0x000000); // Blank
              pixel.show();
             delay(ModeFlashDelay);
            }*/
      
 }

 void bankFlash()
 {

    if (initialBank == true)
    {
      
      //Serial.println(" BankFlash True ");
      paletteStart();

    }
    else
    {

    }
  
  
 }


void modeButtons (){
  
writeStartupDataz();

}

//  This Section is waiting for all potentiometers to be fully counter-clockwise for a duration 
//  and then will start flashing a pattern of light in preparation for advancing Modez
//  If A2 is above zero (turned clockwise) mode will advance in Routines 
//  If A0 or A1 is above zero (turned clockwise) current Mode will resume with Mode Color


void modeChangeWaitPotentiometers() {
  
 
     // If all pins are fully counter-clockwise (zero) get ready to routine (Mode) change and set WaitForModeChange to False
     if ((analogRead(A0) <= ValueZeroAdjustment) && (analogRead(A1) <= ValueZeroAdjustment) && (analogRead(A2) <= ValueZeroAdjustment) && (WaitForModeChange))
        {
          WaitForModeChange = false;
          //Serial.println(" WaitForModeChange = False");
         delay(200);
        }

    //If WaitForModeChange is False because all of the potentiometers are fully counter-clockwise and a variable duration of time has elapsed, start blinking.
    if (!WaitForModeChange)
    {
        pixel.setBrightness(70);
        pixel.setPixelColor(0, Sketch2Green);
        pixel.show();
       delay(100);
        pixel.setPixelColor(0, 0x000000); // Blank
        pixel.show();
       delay(300);
        Serial.println("Blinking and getting ready to Advance Modez");

      // If pin A0 or A1 moves from fully counter-clockwise (zero) go back to waiting for the routine (Mode) change
      if ((analogRead(A0) > ValueZeroAdjustment) or (analogRead(A1) > ValueZeroAdjustment) && (!WaitForModeChange))
      {
        
        if (Mode == 1)
        {
          if (Blink1 = true)
          {
            valueA1 = map(analogRead(A1), 0, 1024, 0, 20);
            pixel.setPixelColor(0, valueA1, (valueA1/5), 0); // Blink 1
            pixel.setBrightness(valueA1);
            pixel.show();
          }
          if (Blink1 = false)
          {
            valueA2 = map(analogRead(A2), 0, 1024, 0, 255);
            pixel.setPixelColor(0, (valueA2/6), valueA2, valueA2); // Blink 2
            pixel.setBrightness(valueA2);
            pixel.show();
          }       
        }
        if (Mode == 2)
        {
          pixel.setPixelColor(0, 36, 0, 255); 
        }
        if (Mode == 3)
        {
          pixel.setPixelColor(0, 0, 200, 30);    
        }
        if (Mode == 4)
        {
          pixel.setPixelColor(0, Sketch2Red);
        }
        if (Mode == 5)
        {
          pixel.setPixelColor(0, Sketch2Red);
        }
        else;
            
        pixel.show();
        waitingFlag = true;
        WaitForModeChange = true;
        //Serial.println(" WaitForModeChange = False & WaitingFlag = True");
        Serial.println("Peaced-Out on Advancing the Mode");
      }
      
      // If pin A2 moves from fully counter-clockwise (zero) then advance the Mode
      if ((analogRead(A2) > ValueZeroAdjustment) && (!WaitForModeChange))
      {
        if (9 >= Mode)
        {
          Mode = Mode+1;
          //Serial.println("Mode Change = " + String(Mode));
        }
        else if (Mode == 10)
        {
          Mode = 1;
          //Serial.println("Mode Change = " + String(Mode));
        }
                
        waitingFlag = false;
        WaitForModeChange = false;
        //Serial.println(" WaitForModeChange = False & WaitingFlag = False");
        Serial.println("Totally advancing Modez Now");
      }
      
    }   
  
}

void modeChangeButtons() {
 // Deprecated
}
