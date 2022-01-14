/**

  A1 Delay - Full Delay

*/


void delayA1(int count)
{

  if (Bank == 1)
  {
   int delayCountA1 = fullDelay;
  

  plotCycle();
  checkButtons();

    if (Mode == 2)
    {
       valueA1 = map(analogRead(A1), 0, 1024, 0, durationMaximum);
       fullDelay = valueA1;      
    }
    else if (Mode == 3)
    {
      delayValueA1 = map(analogRead(A0), 0, 1024, 10000, 400);
      valueA1 = map(analogRead(A1), 0, 1024, 0, durationMaximum);
      randomAmountA1 = random(0, delayValueA1);
      fullDelay = valueA1 + randomAmountA1;      
      
    }
    else {
      
    }

  for (int count = 0; count <= delayCountA1; count++) {


    delayCountA1 = fullDelay;
    

    plotCycle();
    checkButtons();

    if (clicked == true) {

      //Serial.println("I Broke delayA1 Mode " + String(Mode) + " because button was clicked");
      clicked = false;
      breakdelayA0 = true;
      breakdelayA1 = true;
      breakdelayA2 = true;
      break;
      //count = 1;
      fadeSpeed = 0;
      fullDelay = 0;
      darkDelay = 0;
      randomAmount = 0;
      delayCountA1 = 0;
      }
      else {
      
      }

    if (breakdelayA1 == true)
    {
      //Serial.println("I Broke delayA1 Because A1 was true");
      breakdelayA1 = false;
      break;
      
    }
    else {
      
    }

    if (Mode ==  1) {

    }
    // Potentiometer Top Left | A1 - Map the value of the potentiometer to a variable and Update the Variable(s)
    else if (Mode == 2) {

      //valueA1 = map(analogRead(A1), 0, 1024, 0, durationMaximum);
      //fullDelay = valueA1;
      //Serial.println("Mode 1 fullDelay: " + String(fullDelay));
      //Serial.println("Mode 1 delayValueA1: " + String(delayValueA1));

      valueA1 = map(analogRead(A1), 0, 1024, 0, durationMaximum);
      fullDelay = valueA1;  
  
    }
    else if (Mode == 3) {

      valueA1 = map(analogRead(A1), 0, 1024, 0, durationMaximum);
      delayValueA1 = map(analogRead(A0), 0, 1024, 10000, 400);
      fullDelay = valueA1 + randomAmountA1;
      //Serial.println("Mode 3 fullDelay Random: " + String(randomAmountA1));
      //Serial.println("Mode 3 fullDelay: " + String(fullDelay));

    }
    else {
      fullDelay = 100;
      //Serial.println("Else fullDelay: " + String(fullDelay));
    }

    checkButtons();
    delay(1);
    //controlsMax();

    
    //Serial.println("Mode 1 valueA1: " + String(valueA1));
    //Serial.println("Mode 1 fullDelay: " + String(fullDelay));
    //Serial.println("Mode 1 delayCountA1: " + String(delayCountA1));

    //Serial.println("Bank - " + String(Bank) + "Mode" + String(Mode) + "fadeSpeeed: " + String(fullDelay)); 
    //Serial.println("Count if Waiting = False: " + String(count));
  }
  }
    else if (Bank == 2)
  {
     int delayCountA1 = fullDelay;
    
  
          plotCycle();
          checkButtons();
          
             for (int count = 0; count <= delayCountA1; count++) {
            
            
                delayCountA1 = fullDelay;
                
            
                plotCycle();
                checkButtons();
            
                if (clicked == true) {
            
                  //Serial.println("I Broke delayA1 Mode " + String(Mode) + " because button was clicked");
                  clicked = false;
                  breakdelayA0 = true;
                  breakdelayA1 = true;
                  breakdelayA2 = true;
                  break;
                  //count = 1;
                  fadeSpeed = 0;
                  fullDelay = 0;
                  darkDelay = 0;
                  randomAmount = 0;
                  delayCountA1 = 0;
                  }
                  else {
                  
                  }
            
                if (breakdelayA1 == true)
                {
                  //Serial.println("I Broke delayA1 Because A1 was true");
                  breakdelayA1 = false;
                  break;
                  
                }
                else {
                  
                }
            
  
                if (Mode == 1) {
                  //fullDelay = map(analogRead(A1), 0, 1024, speedMinimum, 100); // Linear Potentiometer Value
                  //Serial.println("Mode 1 fullDelay: " + String(fullDelay));
            
                  // This makes the potentiometer slower to change when reducting from full and gives better control fidelity at higher speeds
                  // This is a map of values for the potentiometer. note: the in array should have increasing values
                  int in[]  = {0, 25.5,51,76.5,102,127.5,153,178.5,204,229.5,255};
                  // This is a map of values for potentiometer curve type.
                  int out[] = { 2300,2298,2296,2295,2292,2200,2100,2000,1800,1300,0 };  // 11
                  // This maps the potentiometer scale.
                  controlAmount  = map(analogRead(A1), 0, 1024, 255, 0);
                  // This is a multimap that assigns values from the [in] array (potentiometer) to values from the [out] array (curve)
                  x = multiMap(controlAmount, in, out, 11);
                  // This maps the values for the Modez.
                  fullDelay = map(x, 0, 2300, speedMinimum, 10);
                  
            
                  //Serial.println("Mode 3 controlAmount: " + String(controlAmount));
                  //Serial.println("Mode 3 fadeSpeeed: " + String(fadeSpeed));
                  
                }
                else if (Mode == 2) {
                  fullDelay = map(analogRead(A1), 0, 1024, speedMinimum, 100); // Linear Potentiometer Value
                  //Serial.println("Mode 1 fullDelay: " + String(fullDelay));
                  
                  // This makes the potentiometer slower to change when reducting from full and gives better control fidelity at higher speeds
                  // This is a map of values for the potentiometer. note: the in array should have increasing values
                  int in[]  = {0, 25.5,51,76.5,102,127.5,153,178.5,204,229.5,255};
                  // This is a map of values for potentiometer curve type.
                  int out[] = { 2300,2298,2296,2295,2292,2200,2100,2000,1800,1300,0 };  // 11
                  // This maps the potentiometer scale.
                  controlAmount  = map(analogRead(A1), 0, 1024, 255, 0);
                  // This is a multimap that assigns values from the [in] array (potentiometer) to values from the [out] array (curve)
                  x = multiMap(controlAmount, in, out, 11);
                  // This maps the values for the Modez.
                  fullDelay = map(x, 0, 2300, speedMinimum, 10);
                  
                }
                else if (Mode == 3) {
                  //fullDelay = map(analogRead(A1), 0, 1024, speedMinimum, 100); // Linear Potentiometer Value
                  //Serial.println("Mode 1 fullDelay: " + String(fullDelay));
                  
                  // This makes the potentiometer slower to change when reducting from full and gives better control fidelity at higher speeds
                  // This is a map of values for the potentiometer. note: the in array should have increasing values
                  int in[]  = {0, 25.5,51,76.5,102,127.5,153,178.5,204,229.5,255};
                  // This is a map of values for potentiometer curve type.
                  int out[] = { 2300,2298,2296,2295,2292,2200,2100,2000,1800,1300,0 };  // 11
                  // This maps the potentiometer scale.
                  controlAmount  = map(analogRead(A1), 0, 1024, 255, 0);
                  // This is a multimap that assigns values from the [in] array (potentiometer) to values from the [out] array (curve)
                  x = multiMap(controlAmount, in, out, 11);
                  // This maps the values for the Modez.
                  fullDelay = map(x, 0, 2300, speedMinimum, 10);
                }
                else {
                  fullDelay = 100;
                  //Serial.println("Else fullDelay: " + String(fullDelay));
                }
            
                delay(1);
  
                //Serial.println("Bank - " + String(Bank) + "Mode" + String(Mode) + "fadeSpeeed: " + String(fullDelay)); 
                
                //controlsMax();
                //Serial.println("Count if Waiting = False: " + String(count));
              }
              }
                else if (Bank == 3)
              {
            
              }
          else;
    
}
