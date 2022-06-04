/**

FlashAsEEPROM_SAMD Library declarations
FLASH MEMORY/ EEPROM for reading and writing the startup mode

*/



/**

Write Startup Mode to Memory

*/


void writeStartupMode()       // Currently Unused
{

}

void readStartupMode()        // Reads the Startup Bank, Mode, MaxBright when Mode is zero
{
  EEPROM.get(storedAddress + sizeof(startup), dataz);

  // Say hello to the returning user!
  Serial.print("Hi "); Serial.print(dataz.savedBank); Serial.print(" "); Serial.print(dataz.savedMode); Serial.print(" "); Serial.print(dataz.savedMaxBright);
  Serial.println(", nice to see you again :-)");


  startupBank = dataz.savedBank;
  startupMode = dataz.savedMode;
  startupMaxBright = dataz.savedMaxBright;
  startupMultiplier = dataz.savedMultiplier;

  Serial.println(startupBank);
  Serial.println(startupMode);
  Serial.println(startupMaxBright);
  Serial.println(startupMultiplier);
}

void writeStartupDataz()      // Writes the Startup Bank, Mode, MaxBright to the flash memory
{
  Serial.println("Writing STARTUP_DATAZ");

  //startupBank = Bank;
  //startupMode = Mode;
  //savedMaxBright = MaxBright;

  if ((Mode >= 1) && (Mode <= 10))
  {

    EEPROM.put(storedAddress, STARTUP_DATA);

    Serial.println("Filling in DATAZ Bank: " + String(Bank));
    Serial.println("Filling in DATAZ Mode: " + String(Mode));
    Serial.println("Filling in DATAZ MaxBright: " + String(MaxBright));
    Serial.println("Filling in DATAZ Multiplier: " + String(timeMultiplier));

    // Fill the "dataz" structure with the data entered by the user...
    dataz.savedBank = Bank;
    dataz.savedMode = Mode;
    dataz.savedMaxBright = MaxBright;
    dataz.savedMultiplier = timeMultiplier;

    // ...and finally save everything into emulated-EEPROM
    EEPROM.put(storedAddress + sizeof(startup), dataz);
  }
  else
  {
      
  }

  if (!EEPROM.getCommitASAP())
      {
        Serial.println("CommitASAP not set. Need commit()");
        EEPROM.commit();

        // Print a confirmation of the data inserted.
        Serial.print("<< Your Bank "); Serial.print(dataz.savedBank);
        Serial.print(". Your Mode: "); Serial.print(dataz.savedMode);
        Serial.print(". Your MaxBright: "); Serial.print(dataz.savedMaxBright);
        Serial.print(". Your Multiplier: "); Serial.print(dataz.savedMultiplier);
        Serial.println(" >> have been saved. Thank you!");
      }
  else
  {
    
  }
  
}

void writeMaxBrightDataz()    // Writes the MaxBright to the flash memory
{
  Serial.println("Writing MazBright STARTUP_DATAZ");

  EEPROM.put(storedAddress, STARTUP_DATA);

  Serial.println("Filling in DATAZ MaxBright - " + String(MaxBright));

  dataz.savedMaxBright = MaxBright;

  // ...and finally save everything into emulated-EEPROM
  EEPROM.put(storedAddress + sizeof(startup), dataz);

  if (!EEPROM.getCommitASAP())
  {
    Serial.println("CommitASAP not set. Need commit()");
    EEPROM.commit();
  }

  // Print a confirmation of the data inserted.
  Serial.print(". Your MaxBright: "); Serial.print(dataz.savedMaxBright);
  Serial.println(" >> have been saved. Thank you!");
}

void writeMultiplierDataz()    // Writes the MaxBright to the flash memory
{
  Serial.println("Writing Multiplier STARTUP_DATAZ");

  EEPROM.put(storedAddress, STARTUP_DATA);

  Serial.println("Filling in DATAZ timeMultiplier - " + String(timeMultiplier));

  dataz.savedMultiplier = timeMultiplier;

  // ...and finally save everything into emulated-EEPROM
  EEPROM.put(storedAddress + sizeof(startup), dataz);

  if (!EEPROM.getCommitASAP())
  {
    Serial.println("CommitASAP not set. Need commit()");
    EEPROM.commit();
  }

  setTimeMultiplier();

  // Print a confirmation of the data inserted.
  Serial.println("Set speedMinimum =  " + String(speedMinimum));
  Serial.println("Set durationMaximum =  " + String(durationMaximum));  
  Serial.print(". Your savedMultiplier: "); Serial.print(dataz.savedMultiplier);
  Serial.println(" >> have been saved. Thank you!");
}

void readStartupMultiplier()        // Reads the Startup Bank, Mode, MaxBright when Mode is zero
{
  EEPROM.get(storedAddress + sizeof(startup), dataz);

  startupMultiplier = dataz.savedMultiplier;

  setTimeMultiplier();

  Serial.println("Read in DATAZ startupMultiplier - " + String(startupMultiplier));
  Serial.println("Set speedMinimum =  " + String(speedMinimum));
  Serial.println("Set durationMaximum =  " + String(durationMaximum));
}

void readStartupBank()        // Currently Unused
{

}


/**

Memory Reporting Tools

This Section is used for memory reporting

*/

// #ifdef __arm__
//   // should use uinstd.h to define sbrk but Due causes a conflict
// extern "C" char* sbrk(int incr);
// #else    // __ARM__
// extern char *__brkval;
// #endif    // __arm__

// int freeMemory() {
//   char top;
// #ifdef __arm__
//   return &top - reinterpret_cast<char*>(sbrk(0));
// #elif defined(CORE_TEENSY) || (ARDUINO > 103 && ARDUINO != 151)
//   return &top - __brkval;
// #else    // __arm__
//   return __brkval ? &top - __brkval : &top - __malloc_heap_start;
// #endif    // __arm__
// }

// extern "C" char *sbrk(int i);

// int FreeRam () {
//   char stack_dummy = 0;
//   return &stack_dummy - sbrk(0);
// }


\

  //
  //  This Section is waiting for all potentiometers to be fully clockwise for a duration defined as "ValueHighlightTime"
  //  and then will start flashing a pattern of light in preparation for wiritng the startup mode to the Flash/ EEPROM Memory
  //  If A2 is beloww zero (turned counter-clockwise) then the current Mode will be written as the Startup Mode to Memory
  //  If A0 or A1 is rotated below fully clockwise (turned counter-clockwise) current Mode will resume with Mode Color
  //
  //  This code is historic for now and was part of the navigation for Pedal Brain Left Brain v1

void controlsMax()
{

  // If all the potentiometer are fully clockwise, set "ValueHighReached" to "True" and get ready to blink.
  //
  if ((analogRead(A0) > 1022) && (analogRead(A1) > 1022) && (analogRead(A2) > 1022) && (!ValueHighReached))
  {
    ValueHighTime = millis();
    ValueHighlightTime = millis();
    ValueHighReached = true;
    Serial.println("Getting Ready to Save the Current Mode as the Startup Mode");

  }

  //
  // When A0 or A1 becomes less than fully Clockwise, resume the current Mode without writing the Startup Mode
  // then set the pixel color to the right color depending on the current Mode
  //
  if (((analogRead(A0) < 1023) or (analogRead(A1) < 1023)) && (ValueHighReached))
  {
    ValueHighTime = 0;
    ValueHighReached = false;

    if (Mode == 1)
    {
      if (Blink1 = true)
      {
        valueA1 = map(analogRead(A1), 0, 1024, 0, 20);
        pixel.setPixelColor(0, valueA1, (valueA1 / 5), 0);   // Blink 1
        pixel.setBrightness(valueA1);
        pixel.show();
      }
      if (Blink1 = false)
      {
        valueA2 = map(analogRead(A2), 0, 1024, 0, 255);
        pixel.setPixelColor(0, (valueA2 / 6), valueA2, valueA2);   // Blink 2
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
    Serial.println("Peaced-Out on Saving the Startup Mode");
  }



  //
  // When A2 potentiometer becomes less than fully Clockwise, write the startup mode to the Flash/ EEPROM Memory
  // then set the pixel color to the right color depending on the Mode
  //
  if ((analogRead(A2) < 1023) && (ValueHighReached))
  {
    ValueHighTime = 0;
    ValueHighReached = false;

      // Write the startupMode to EEPROM Flash Memory
     //writeStartupDataz();

    modeFlash();
    pixel.setPixelColor(0, Sketch2Red);
    pixel.show();
    delay(1000);
    modeFlash();

    if (Mode == 1)
    {

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
    Serial.println("Startup Mode written to Flash Memory");
  }

  //If "ValueHighReached" = True and the duration in milleseconds defined for "WaitTime" has been reached, start blinking a pattern and get ready to save the startup mode.
  if (((ValueHighTime + WaitTime) < millis()) && (ValueHighReached))
  {

  //If all the potentiometer are fully clockwise and a variable duration of time has elapsed, start blinking.
    if ((ValueHighlightTime + 300) < millis())
    {

      if (ValueHighlight == 0)
      {
        ValueHighlightTime = millis();
        ValueHighlight = 1;
        pixel.setBrightness(155);
  //pixel.setPixelColor(0, 255,64,98);
        pixel.setPixelColor(0, Sketch2Yellow);
        pixel.show();
        delay(100);
        pixel.setPixelColor(0, 0x000000);   // Blank
        pixel.show();
        delay(300);
        Serial.println("Blinking and getting ready to Save Startup Mode");
      }
      else
      {
        ValueHighlightTime = millis();
        ValueHighlight = 0;
        Serial.println("I'm ready to write the startup mode");
      }

    }
  }
}
