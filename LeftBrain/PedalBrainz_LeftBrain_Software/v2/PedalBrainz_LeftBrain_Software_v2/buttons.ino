/**

BUTTON declarations

*/

// variables will change:
//int buttonStateUp = 0;               // variable for reading the pushbutton status
//int buttonStateDown = 0;               // variable for reading the pushbutton status
//int lastButtonStateUp = 1;           // previous state of the buttons
//int lastButtonStateDown = 1;           // previous state of the buttons



// MULTI-CLICK: One Button, Multiple Events

// Button timing variables

int debounce = 50;       // ms debounce period to prevent flickering when pressing or releasing the button
int DCgap = 300;       // max ms between clicks for a double click event
int holdTime = 1000;       // ms hold period: how long to wait for press+hold event
int longHoldTime = 3000;       // ms long hold period: how long to wait for press+hold event

      // Button variables
boolean buttonValUp = HIGH;       // value read from button
boolean buttonValDown = HIGH;       // value read from button
boolean buttonLastUp = HIGH;       // buffered value of the button’s previous state
boolean buttonLastDown = HIGH;       // buffered value of the button’s previous state

boolean buttonBreak = false;       // buffered value of the button’s previous state

boolean DCwaitingUp = false;       // whether we’re waiting for a double click (down)
boolean DCwaitingDown = false;       // whether we’re waiting for a double click (down)

boolean DConUpUp = false;       // whether to register a double click on next release, or whether to wait and click
boolean DConUpDown = false;       // whether to register a double click on next release, or whether to wait and click

boolean singleOKUp = true;       // whether it’s OK to do a single click
boolean singleOKDown = true;       // whether it’s OK to do a single click

long downTime = -1;       // time the button was pressed down
long upTime = -1;       // time the button was released

boolean ignoreUpUp = false;       // whether to ignore the button release because the click+hold was triggered
boolean ignoreUpDown = false;       // whether to ignore the button release because the click+hold was triggered

boolean waitForUpUp = false;       // when held, whether to wait for the up event
boolean waitForUpDown = false;       // when held, whether to wait for the up event

boolean holdEventPastUp = false;       // whether or not the hold event happened already
boolean holdEventPastDown = false;       // whether or not the hold event happened already

boolean longHoldEventPastUp = false;      // whether or not the long hold event happened already
boolean longHoldEventPastDown = false;      // whether or not the long hold event happened already

int checkButtonUp() 
{

  int eventUp = 0;
  buttonValUp = digitalRead(buttonPinUp);

      // Button pressed
  if (buttonValUp == LOW && buttonLastUp == HIGH && (millis() - upTime) > debounce)
  {
    Serial.println("checkButtonUp: button pressed");
    downTime = millis();
    ignoreUpUp = false;
    waitForUpUp = false;
    singleOKUp = true;
    holdEventPastUp = false;
    longHoldEventPastUp = false;
    if ((millis() - upTime) < DCgap && DConUpUp == false && DCwaitingUp == true)
    {
      Serial.println("doubleclick Up true"); //leave in as kludge fix
      DConUpUp = true;
    }
    else
    {
      Serial.println("doubleclick Up false"); //leave in as kludge fix
       DConUpUp = false;
    }
    DCwaitingUp = false;
  }

      // Button released
  if (buttonValUp == HIGH && buttonLastUp == LOW && (millis() - downTime) > debounce)
  {
    Serial.println("checkButtonUp: button released");
    if (ignoreUpUp)
    {
      Serial.println("checkButtonUp: ignoreUpUp");
    }
    else
    {
      upTime = millis();
      if (DConUpUp)
      {
        Serial.println("doubleclick Up true"); //leave in as kludge fix
        eventUp = 2;
        DConUpUp = false;
        DCwaitingUp = false;
        singleOKUp = false;
      }
      else
      {
        Serial.println("doubleclick Up false"); //leave in as kludge fix
        DCwaitingUp = true;
      }
    }
  }

      // Test for normal click event: DCgap expired
  if ( buttonValUp == HIGH && (millis() - upTime) >= DCgap && DCwaitingUp == true && DConUpUp == false && singleOKUp == true && eventUp != 2)
  {
    eventUp = 1;
    DCwaitingUp = false;
  }
      // Test for hold
  if (buttonValUp == LOW && (millis() - downTime) >= holdTime) {

      // Trigger “normal” hold
    if (not holdEventPastUp)
    {
      eventUp = 3;
      waitForUpUp = true;
      ignoreUpUp = true;
      DConUpUp = false;
      DCwaitingUp = false;
      //downTime = millis();
      holdEventPastUp = true;
    }

      // Trigger “long” hold
    if ((millis() - downTime) >= longHoldTime)
    {
      if (not longHoldEventPastUp)
      {
        eventUp = 4;
        longHoldEventPastUp = true;
      }
    }
  }
  buttonLastUp = buttonValUp;
  return eventUp;
}

int checkButtonDown() 
{

  int eventDown = 0;
  buttonValDown = digitalRead(buttonPinDown);

      // Button pressed
  if (buttonValDown == LOW && buttonLastDown == HIGH && (millis() - upTime) > debounce)
  {
    Serial.println("checkButtonDown: button pressed");
    downTime = millis();
    ignoreUpDown = false;
    waitForUpDown = false;
    singleOKDown = true;
    holdEventPastDown = false;
    longHoldEventPastDown = false;
    if ((millis() - upTime) < DCgap && DConUpDown == false && DCwaitingDown == true)
    {
       Serial.println("doubleclick Down true"); //leave in as kludge fix
       DConUpDown = true;
    }
    else
    {
       Serial.println("doubleclick Down false"); //leave in as kludge fix
       DConUpDown = false;
    }
    DCwaitingDown = false;
  }

      // Button released
  if (buttonValDown == HIGH && buttonLastDown == LOW && (millis() - downTime) > debounce)
  {
    Serial.println("checkButtonDown: button released"); //leave in as kludge fix
    if (ignoreUpDown)
    {
      Serial.println("checkButtonDown: ignoreUpDown"); //leave in as kludge fix
    }
    else
    {
      upTime = millis();
      if (DConUpDown) 
      {
        Serial.println("doubleclick Down true");
        eventDown = 2;
        DConUpDown = false;
        DCwaitingDown = false;
        singleOKDown = false;
      }
      else
      {
         Serial.println("doubleclick Down false");
         DCwaitingDown = true;
      }
    }
  }

      // Test for normal click event: DCgap expired
  if ( buttonValDown == HIGH && (millis() - upTime) >= DCgap && DCwaitingDown == true && DConUpDown == false && singleOKDown == true && eventDown != 2)
  {
    eventDown = 1;
    DCwaitingDown = false;
  }
      // Test for hold
  if (buttonValDown == LOW && (millis() - downTime) >= holdTime) {

      // Trigger “normal” hold
    if (not holdEventPastDown)
    {
      eventDown = 3;
      waitForUpDown = true;
      ignoreUpDown = true;
      DConUpDown = false;
      DCwaitingDown = false;
      //downTime = millis();
      holdEventPastDown = true;
    }

      // Trigger “long” hold
    if ((millis() - downTime) >= longHoldTime)
    {
      if (not longHoldEventPastDown)
      {
        eventDown = 4;
        longHoldEventPastDown = true;
      }
    }
  }
  buttonLastDown = buttonValDown;
  return eventDown;
}

void checkButtons() 
{

      // Get button event and act accordingly
  int buttonup = checkButtonUp();
  if (buttonup == 1) clickEventUp();
  if (buttonup == 2) doubleClickEventUp();
  if (buttonup == 3) holdEventUp();
  if (buttonup == 4) longHoldEventUp();

      // Get button event and act accordingly
  int buttondown = checkButtonDown();
  if (buttondown == 1) clickEventDown();
  if (buttondown == 2) doubleClickEventDown();
  if (buttondown == 3) holdEventDown();
  if (buttondown == 4) longHoldEventDown();
}

void clickEventUp()
{

  Serial.println("click up");

  buttonBreak = true;
  already = false;

  setRandoms();

  if (Mode == 98) {

    pressedTapzUp = true;

  }
  else;

  if (6 >= Bank) {
    clicked = true;
    WaitForModeChange = false;

    if (9 >= Mode)
    {
      Mode = Mode + 1;
      //Serial.println("Mode Change = " + String(Mode));
      //Serial.println("Totally advancing Modez Now");
      writeStartupDataz();
    }
    else if (Mode == 10)
    {
      Mode = 1;
      //Serial.println("Mode Change = " + String(Mode));
      //Serial.println("Totally advancing Modez Now");
      writeStartupDataz();
    }
    else if (Mode == 99)
    {
      readStartupMode();
      Serial.println("StartupMode = " + String(startupMode));
      Mode = startupMode;
      Serial.println("Returning to Modez Now");
      Serial.println("Mode Change = " + String(Mode));
    }
    else if (Mode == 100)
    {
      readStartupMultiplier();
      Serial.println("I read startupMultiplier before = " + String(startupMultiplier));
      startupMultiplier = timeMultiplier;
      Serial.println("I set startupMultiplier as timeMultiplier and now startupMultiplier = " + String(startupMultiplier));
      Serial.println("Returning to Modez Now");
      writeMultiplierDataz();
    }    
    else if (Mode == 102)
    {
      readStartupMode();
      Serial.println("StartupMaxBright = " + String(startupMaxBright));
      MaxBright = MaxBrightTemp;
      Mode = startupMode;
      Serial.println("Max Bright = " + String(startupMaxBright));
      Serial.println("Returning to Modez Now");
      writeMaxBrightDataz();
    }
    else if (Mode == 999)
    {

    }

      waitingFlag = false;
      WaitForModeChange = false;
      //Serial.println(" WaitForModeChange = False & WaitingFlag = False");
      //Serial.println("Totally advancing Modez Now");
      //delay(200);

    //Serial.println("Current speedMinimum =  " + String(speedMinimum));
    //Serial.println("Current durationMaximum =  " + String(durationMaximum));        
  }
}

void doubleClickEventUp()
{

  buttonBreak = true;
  clicked = true;
  WaitForModeChange = false;
  already = false;

  Serial.println("doubleclick up");




  if ((Bank >= 1) && (Bank <= 4))
  {
    if (Mode == 999)
    {

    }
    else if (Mode == 98) {

      // Disable double click to allow for button entry
      Serial.println("Mode is 98 and Don't ChangebBank");

    }
    else {
      Bank = Bank+1;
      Mode = 1;
      Serial.println("Bank Change = " + String(Bank));
      writeStartupDataz();
      initialBank = true;
    }


  }
  else if (Bank == 5)
  {
    if (Mode == 999)
    {

    }
    else if (Mode == 98) {

      // Disable double click to allow for button entry
      Serial.println("Mode is 98 and Don't ChangebBank");

    }
    else {
      Bank = 1;
      Mode = 1;
      Serial.println("Bank Change = " + String(Bank));
      writeStartupDataz();
      initialBank = true;
    }

  }



  waitingFlag = false;
  WaitForModeChange = false;
      //Serial.println(" WaitForModeChange = False & WaitingFlag = False");
  Serial.println("Totally advancing Bank Now");
      //delay(200);
}

void holdEventUp()
{

  Serial.println("hold up");
}

void longHoldEventUp()
{
  Serial.println("longhold up");

  buttonLongHoldUp = true;

  already = false;

  if (Mode == 98) {
    clicked = true;
    readStartupMode();
    Mode = startupMode;       //
    Serial.println("Changing from Light Loopz to Startup Mode");
  }
  else if (Mode == 100) {
    clicked = true;
    readStartupMode();
    Mode = startupMode;       //
    Serial.println("Changing from Time Multiplier to Startup Mode");
  }
  else
  {
    writeStartupDataz();
    clicked = true;
    initial = false;
    Mode = 98;       // Light Loopz
    Serial.println("Changing from Modez to LightLoopz");
  }

  waitingFlag = false;
  WaitForModeChange = false;
}

void clickEventDown()
{

  Serial.println("click down");

  buttonBreak = true;
  already = false;

  setRandoms();

  if (Mode == 98) {

    pressedTapzDown = true;

  }
  else;

  if (6 >= Bank) {


    clicked = true;
    WaitForModeChange = false;

    if ((Mode >= 2) && (Mode <= 10))
    {
      Mode = Mode - 1;
      //Serial.println("Mode Change between 2 and 9 = " + String(Mode));
      //Serial.println("Totally REVERSING Modez Now");
      writeStartupDataz();
    }

    else if (Mode == 1)
    {
      Mode = 10;
      //Serial.println("Mode Change = " + String(Mode));
      //Serial.println("Totally REVERSING Modez Now");
      writeStartupDataz();
    }
    else if (Mode == 99)
    {
      readStartupMode();
      Serial.println("StartupMode = " + String(startupMode));
      Mode = startupMode;
      Serial.println("Mode Change = " + String(Mode));
      Serial.println("Returning to Modez Now");
    }
    else if (Mode == 100)
    {
      readStartupMultiplier();
      Serial.println("I read startupMultiplier before = " + String(startupMultiplier));
      startupMultiplier = timeMultiplier;
      Serial.println("I set startupMultiplier as timeMultiplier and now startupMultiplier = " + String(startupMultiplier));
      writeMultiplierDataz();
      readStartupMode();
      Serial.println("StartupMode = " + String(startupMode));
      Mode = startupMode;
      Serial.println("Mode Change = " + String(Mode));
      Serial.println("Returning to Modez Now");
    }    
    else if (Mode == 102)
    {
      readStartupMode();
      Serial.println("StartupMaxBright = " + String(startupMaxBright));
      MaxBright = MaxBrightTemp;
      Mode = startupMode;
      Serial.println("I set MaxBrightTemp to Max Bright = " + String(MaxBright));
      Serial.println("Returning to Modez Now");
      writeMaxBrightDataz();
    }
    else if (Mode == 999)
    {

    }

    waitingFlag = false;
    WaitForModeChange = false;
      //Serial.println(" WaitForModeChange = False & WaitingFlag = False");
      //Serial.println("ButtonStateDown= " + String(buttonStateDown));
      //Serial.println("Totally REVERSING Modez Now = " + String(Mode));
      //delay(200);

    //Serial.println("Current speedMinimum =  " + String(speedMinimum));
    //Serial.println("Current durationMaximum =  " + String(durationMaximum));       

  }
}

void doubleClickEventDown()
{


  buttonBreak = true;
  clicked = true;
  WaitForModeChange = false;
  already = false;


  Serial.println("doubleclick down");

  if ((Bank >= 2) && (Bank <= 5))
  {
    Serial.println("Inner");

    if (Mode == 999)
    {

    }
    else if (Mode == 98) {

      // Disable double click to allow for button entry
      Serial.println("Mode is 98 and Don't Change Bank");

    }
    else 
    {
    Bank = Bank-1;
    Mode = 1;
    Serial.println("Bank Change = " + String(Bank));
    writeStartupDataz();
    initialBank = true;
    }

  }
  else if (Bank == 1)
  {
    if (Mode == 999)
    {

    }
    else if (Mode == 98) {

      // Disable double click to allow for button entry
      Serial.println("Mode is 98 and Don't Change Bank");

    }
    else
    {
      Bank = 5;
      Mode = 1;
      Serial.println("Bank Change = " + String(Bank));
      writeStartupDataz();
      initialBank = true;
    }

  }

  waitingFlag = false;
  WaitForModeChange = false;
      //Serial.println(" WaitForModeChange = False & WaitingFlag = False");
      //Serial.println("ButtonStateDown= " + String(buttonStateDown));
  Serial.println("Totally REVERSING Bank Now = " + String(Mode));
      //delay(200);
}

void holdEventDown()
{

  Serial.println("hold down");
}

void longHoldEventDown()
{
  Serial.println("longhold down");

  already = false;
  buttonLongHoldDown = true;

  if (Mode == 98) // If it's Mode 98 = Light Loopz then go to Mode 102 = Max Bright Settings
  {
    Mode = 102;       // Mode 102 = Max Bright Settings
    Serial.println("Changing from Light Loopz to Max Bright");
  }
  else if (Mode == 100) // If it's Mode 100 Time Multiplier then go to Mode 99 = Color Mix
  {
    //readStartupMultiplier();
    Serial.println("I read startupMultiplier before = " + String(startupMultiplier));
    startupMultiplier = timeMultiplier;
    Serial.println("I set startupMultiplier as timeMultiplier and now startupMultiplier = " + String(startupMultiplier));
    Serial.println("Returning to Modez Now");
    writeMultiplierDataz();
    
    Mode = 99;       // Mode 99 = Color Mix
    Serial.println("Changing from Time Multiplier to Color Mix");
  }
  else if (Mode == 102) // If it's Mode 102 = Max Bright Settings then go to Mode 99 = Color Mix
  {
    //readStartupMode();
    Serial.println("StartupMaxBright = " + String(startupMaxBright));
    MaxBright = MaxBrightTemp;
    writeMaxBrightDataz();

    Mode = 100;        // Mode 100 = Time Multiplier
    Serial.println("Max Bright = " + String(startupMaxBright));
    Serial.println("Changing from Max Bright to Time Multiplier");
  }
  else if (Mode == 99) // If it's Mode 99 = Color Mix then go to Mode 999 = Memory Game
  {
    Mode = 999;       // Mode 999 = Memory Game
    Serial.println("Changing from Color Mix to Memory Game");
  }
  else if (Mode == 999) 
  {
    Mode = 1;
    Serial.println("Changing from Memory Game to Startup Mode");
  }
  else
  {
    if (10 >= Mode) {
      writeStartupDataz();
      clicked = true;
      Mode = 102;       // Mode 102 = Max Bright Settings
      Serial.println("Writing Startup Dataz and Changing from Modez to MaxBright");
    }
    clicked = true;
    Mode = 102; // Mode 102 = Max Bright Settings
    Serial.println("Changing from Modez to MaxBright");
  }

  waitingFlag = false;
  WaitForModeChange = false;
}


void checkResetDefault()
{

    // If it's during the initial startup and both buttons are held down reset the Bank/ Mode/ and MaxBright to default
    if (initial == true)
    {
      if (buttonValUp == LOW && buttonValDown == LOW)
      {
        Bank = 1;
        Mode = 0;
        MaxBright = 255;

        //Serial.println("Startup Check Reset = Initial True");
        //Serial.println("Initial " + String(initial));

        startupBank = Bank;
        startupMode = Mode;
        startupMaxBright = MaxBright;

        writeStartupDataz();

        resetAttractorz();
        already = false;


        //Serial.println("Setting Routines Startup False " + String(routinesStartup));
      }
    }
    // If both buttons are long held during routines reset the Bank/ MaxBright to default and set the Mode to 1
    else if (buttonLongHoldUp == true && buttonLongHoldDown == true)
    {
      Bank = 1;
      Mode = 1;
      MaxBright = 255;

      //Serial.println("Startup Check Reset = Initial False");
      //Serial.println("Initial " + String(initial));

      startupBank = Bank;
      startupMode = Mode;
      startupMaxBright = MaxBright;

      writeStartupDataz();

      resetAttractorz();
      already = false;

      buttonLongHoldUp = false;
      buttonLongHoldDown = false;

      //Serial.println("Setting Routines Startup False " + String(routinesStartup));
    }
    else
    {

      // Otherwise, set these to false
      initial = false;
      buttonLongHoldUp = false;
      buttonLongHoldDown = false;

      //Serial.println("Startup Check Reset Else = Initial False");
      //Serial.println("Initial " + String(initial));

    }


}