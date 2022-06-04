/**

Routines

This is where the Mode switching and waiting happens within the loop.

*/

void Routines()
{

     
  // Check to se if both buttons are down on startup 
  //if they are both pressed, set the Bank to 1 and Mode to 0

  //checkResetDefault();

  // Pring the Mode value currently initialized
  //Serial.println("Mode : "+ String(Mode));

  checkButtons();
  plotCycle();

  //This is the initial startup mode (Mode = 0)
  //Things are about to start kicking in...

  if (Mode == 0)
  {
    // On first power cycle, do this thing so that folks know things are getting ready

    initial = true;

    // Fade in from the beginning of the Rainbow cycle (starts with the color Red) using some default values
    // This "for loop" adds to "x" which is set to zero (0) until it reaches 255 (Max Brightness)

    for (int x = 0; x < 80; x++)
    {
      for (int p = 0; p < strip.numPixels(); p++) {       // For each pixel in strip...
        strip.setBrightness(x * 3);
      }
      pixel.setBrightness(x * 3);

      mode_colorwheel_intro();
      pixel.show();
      strip.show();

      Serial.println("bright fade in = " + String(x * 3));
    }

      // Fade out from the end of the Rainbow (lol) cycle (ends with the color Red)
    for (int x = 80; x >= 0; x--)
    {
      for (int p = 0; p < strip.numPixels(); p++) {       // For each pixel in strip...
        strip.setBrightness(x * 3);
      }
      pixel.setBrightness(x * 3);

      mode_colorwheel_intro();
      pixel.show();
      strip.show();

      Serial.println("bright fade out = " + String(x * 3));
    }


    // Add a delay (ms) at the end of the rainbow cycle using potantiometer A2 while the LED is dark
    valueA1 = 5000;
    //delay(valueA1);

    /**

    Read & Set Startup Mode

    */

      //delay(1000);

      // Get the starup data from a location in memory
      EEPROM.get(storedAddress, startup);

      // If the EEPROM is empty then no STARTUP_DATA

      // Read the values of Startup Mode
      readStartupMode();
      readStartupBank();
      readStartupMultiplier();

      //Serial.println("I Read startupMode - " + String(startupMode));
      //Serial.println("I Read startupBank - " + String(startupBank));

      
      // If both buttons are being held
      // reset the Bank and Mode and 
      // set values as startup data
      // write the values
      if (buttonValUp == LOW && buttonValDown == LOW)
      {
        Bank = 1;
        Mode = 1;
        MaxBright = 255;
        timeMultiplier = 1;

        startupBank = Bank;
        startupMode = Mode;
        startupMaxBright = MaxBright;
        startupMultiplier = timeMultiplier;

        setTimeMultiplier();

        writeStartupDataz();
      }
      else;

      // Set the Bank, Mode, and MaxBright to the value of the StartupDataz
      Mode = startupMode;
      Bank = startupBank;
      MaxBright = startupMaxBright;
      timeMultiplier = startupMultiplier;

      initial = false;

      Serial.println("startupMode = " + String(startupMode));
      Serial.println("startupBank = " + String(startupBank));
      Serial.println("startupMaxBright = " + String(startupMaxBright));
      Serial.println("startupMultiplier = " + String(startupMultiplier));
      Serial.println("Mode set to startupMode = " + String(Mode));
      Serial.println("Bank set to startupBank = " + String(Bank));
      Serial.println("MaxBright set to startupMaxBright = " + String(MaxBright));
      Serial.println("timeMultiplier set to startupMultiplier = " + String(timeMultiplier));

      // If the Bank is 1 or less, set the Bank to 1
      // If there's nothing saved start Modes from the beginning
      
    if (-1 >= Bank)
    {
      Bank = 1;
      Serial.println("Bank was equal to or less than - " + String(Bank));
    }

      // If the Bank is 2 or more, set the Bank to startupBank
      // If a bank has been saved, set the saved startupBank as the Bank
    else if (2 <= Bank)
    {
      Mode = startupBank;
      Serial.println("Bank was greater than one: " + String(Bank));
    }
    else
    {
      //Bank = 1;
    }

      // If the Mode is 1 or less, set the Mode to 1
      // If there's nothing saved start Modes from the beginning
    if (-1 >= Mode)
    {
      Mode = 1;
      Serial.println("Mode was equal to or less than: " + String(Mode));
    }

      // If the Mode is 2 or more, set the Mode to startupMode
      // If a mode has been saved, set the saved startupMode as the Mode
    else if (2 <= Mode)
    {
      Mode = startupMode;
      Serial.println("Mode was greater than one: " + String(Mode));
    }
    else
    {
      Mode = startupMode;
    }

    if (-1 >= MaxBright)
    {
      MaxBright = 255;
      Serial.println("MaxBright was equal to or less than: " + String(MaxBright));
    }
    else;

      // If the timeMultiplier is 1 or less, set the Mode to 1
      // If there's nothing saved start Modes from the beginning
    if (-1 >= timeMultiplier)
    {
      timeMultiplier = 1;
      Serial.println("timeMultiplier was equal to or less than: " + String(timeMultiplier));
    }

      // If the timeMultiplier is 2 or more, set the timeMultiplier to startupMultiplier
      // If a mode has been saved, set the saved startupMode as the Mode
    else if (2 <= timeMultiplier)
    {
      timeMultiplier = startupMultiplier;
      Serial.println("timeMultiplier was greater than one: " + String(timeMultiplier));
    }
    else
    {
      timeMultiplier = startupMultiplier;
    }

    Serial.println("Routinez post-if Bank: " + String(Bank));
    Serial.println("Routinez post-if Mode: " + String(Mode));
    Serial.println("Routinez post-if MaxBright: " + String(MaxBright));
    Serial.println("Routinez post-if timeMultiplier: " + String(timeMultiplier));

    setTimeMultiplier();

    Serial.println("Read in DATAZ startupMultiplier - " + String(startupMultiplier));
    Serial.println("Set speedMinimum =  " + String(speedMinimum));
    Serial.println("Set durationMaximum =  " + String(durationMaximum));    

  }

  if (Bank == 1) {
    //Serial.println("Routines Bank 1");
    Bank1();
  }
  if (Bank == 2) {
    //Serial.println("Routines Bank 2");
    Bank2();
  }
  if (Bank == 3) {
    //Serial.println("Routines Bank 3");
    Bank3();
  }
  if (Bank == 4) {
    //Serial.println("Routines Bank 4");
    Bank4();
  }
  if (Bank == 5) {
    //Serial.println("Routines Bank 5");
    Bank5();
  }
  if (Bank == 6) {
    //Serial.println("Routines Bank 6");
    Bank6();
  }
  else {
      //Bank1();
  }

  // When it's the first runthrough of routines:
  // set the Bank & Mode as the startup and write the data to EEPROM
  if (routinesStartup == true) {


      //Serial.println("Routinez Startup Bank - " + String(Bank));
      //Serial.println("Routinez Startup Mode - " + String(Mode));
      //Serial.println("Routinez Startup MaxBright - " + String(MaxBright));

      startupBank = Bank;
      startupMode = Mode;

      //Serial.println("Routines Startup True " + String(routinesStartup));

      writeStartupDataz();
      routinesStartup = false;

      //Serial.println("Setting Routines Startup False " + String(routinesStartup));

  }
  else {
      //Serial.println("Routines Startupfalse " + String(routinesStartup));

  }



}
