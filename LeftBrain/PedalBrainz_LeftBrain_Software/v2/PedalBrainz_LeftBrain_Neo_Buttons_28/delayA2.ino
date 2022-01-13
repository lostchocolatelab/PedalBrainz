
/**

  A2 Delay - Dark Delay

*/


void delayA2(int count)
{

  if (Bank == 1)
  {

  
        int delayCountA2 = darkDelay;
      
        plotCycle();
        checkButtons();

  if (Mode == 2)
    {
      valueA2 = map(analogRead(A2), 0, 1024, 0, durationMaximum);
      darkDelay = valueA2;
    } 
  else if (Mode == 3)
    {
      delayValueA2 = map(analogRead(A0), 0, 1024, 10000, 400);
      valueA2 = map(analogRead(A2), 0, 1024, 0, durationMaximum);
      randomAmountA2 = random(0, delayValueA2);
      darkDelay = valueA2 + randomAmountA2;
    }
    else {
      
    }        
        
        for (int count = 0; count <= delayCountA2; count++) {
      
          delayCountA2 = darkDelay;
          //Serial.println("delayA2 delayCountA2: " + String(delayCountA2));
          
          plotCycle();
          checkButtons();
      
          if (clicked == true) {
         
            //Serial.println("I Broke delayA2 Mode" + String(Mode) + " because button was clicked");
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
            delayCountA2 = 0;    
          }
          else {
            
          }
      
          if (breakdelayA2 == true)
          {
            //Serial.println("I Broke delayA2 Because A2 was true");
            breakdelayA2 = false;
            break;
            
          }
          else {
            
          }
          
          if (Mode ==  1) {

          }
          //Potentiometer Bottom Right | A2 - Map the value of the potentiometer to a variable and Update the Variable(s)
          else if (Mode == 2) {
      
            valueA2 = map(analogRead(A2), 0, 1024, 0, durationMaximum);
            darkDelay = valueA2;
            //Serial.println("Mode 1 darkDelay: " + String(darkDelay));
            //Serial.println("Mode 1 delayValueA2: " + String(delayValueA2));
      
            
          }
          else if (Mode == 3) {
      
            valueA2 = map(analogRead(A2), 0, 1024, 0, durationMaximum);
            delayValueA2 = map(analogRead(A0), 0, 1024, 10000, 400);
            darkDelay = valueA2 + randomAmountA2;
            //Serial.println("Mode 3 delayValueA2: " + String(delayValueA2));
            //Serial.println("Mode 3 darkDelay Random: " + String(randomAmountA2));
            //Serial.println("Mode 3 darkDelay: " + String(darkDelay));
          }
          else if (Mode == 4) {
      
            valueA2 = map(analogRead(A2), 0, 1024, 0, durationMaximum);
            darkDelay =  valueA2;
            //Serial.println("Mode 4 darkDelay: " + String(fullDelay));
          }
          else if (Mode == 5) {
      
            valueA2 = map(analogRead(A2), 0, 1024, 0, durationMaximum);
            darkDelay =  valueA2;
            //Serial.println("Mode 4 darkDelay: " + String(fullDelay));
          }
          else {
            darkDelay = 100;
            //Serial.println("Else darkDelay: " + String(darkDelay));
          }
      
          checkButtons();
          delay(1);
          //controlsMax();
      
          //Serial.println("Mode 1 valueA1: " + String(valueA1));
          //Serial.println("Mode 1 fullDelay: " + String(fullDelay));
          
          //Serial.println("Mode 1 delayCountA1: " + String(delayCountA1));

          //Serial.println("Bank - " + String(Bank) + "Mode" + String(Mode) + "fadeSpeeed: " + String(darkDelay)); 
          //Serial.println("Count if Waiting = False: " + String(count));
        }
  }
    else if (Bank == 2)
  {
 int delayCountA2 = darkDelay;

  plotCycle();
  checkButtons();

  for (int count = 0; count <= delayCountA2; count++) {

    delayCountA2 = darkDelay;
    //Serial.println("delayA2 delayCountA2: " + String(delayCountA2));
    
    plotCycle();
  delayCountA2 = darkDelay;
    //Serial.println("delayA2 delayCountA2: " + String(delayCountA2));
    
    plotCycle();
    checkButtons();

    if (clicked == true) {
   
      //Serial.println("I Broke delayA2 Mode" + String(Mode) + " because button was clicked");
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
      delayCountA2 = 0;    
    }
    else {
      
    }

    if (breakdelayA2 == true)
    {
      //Serial.println("I Broke delayA2 Because A2 was true");
      breakdelayA2 = false;
      break;
      
    }
    else {
      
    }
    
   if (Mode == 1) {

      darkDelay = map(analogRead(A2), 0, 1024, 0, durationMaximum);
      //Serial.println("Bank - " + String(Bank) + " Mode " + String(Mode) + " fadeSpeeed: " + String(darkDelay)); 
    }
    else if (Mode == 2) {

      darkDelay = map(analogRead(A2), 0, 1024, 0, durationMaximum);
      //Serial.println("Bank - " + String(Bank) + " Mode " + String(Mode) + " fadeSpeeed: " + String(darkDelay)); 
    }    
    else if (Mode == 3) {

      darkDelay = map(analogRead(A2), 0, 1024, 0, durationMaximum);
      //Serial.println("Bank - " + String(Bank) + " Mode " + String(Mode) + " fadeSpeeed: " + String(darkDelay)); 
    }  
    else if (Mode == 6) {

      valueA2 = map(analogRead(A2), 0, 1024, 0, durationMaximum);
      darkDelay =  valueA2/5;
      //Serial.println("Bank - " + String(Bank) + " Mode " + String(Mode) + " fadeSpeeed: " + String(darkDelay)); 
    } 
    else if (Mode == 7) {

      darkDelay = map(analogRead(A2), 0, 1024, 0, durationMaximum);
     //Serial.println("Bank - " + String(Bank) + " Mode " + String(Mode) + " fadeSpeeed: " + String(darkDelay)); 
    } 
    else if (Mode == 8) {

      darkDelay = map(analogRead(A2), 0, 1024, 0, durationMaximum);
      //Serial.println("Bank - " + String(Bank) + " Mode " + String(Mode) + " fadeSpeeed: " + String(darkDelay)); 
    } 
    else if (Mode == 9) {

      darkDelay = map(analogRead(A2), 0, 1024, 0, durationMaximum);
      //Serial.println("Bank - " + String(Bank) + " Mode " + String(Mode) + " fadeSpeeed: " + String(darkDelay)); 
    }             
    else if (Mode == 10) {

      darkDelay = map(analogRead(A2), 0, 1024, 0, durationMaximum);
      //Serial.println("Bank - " + String(Bank) + " Mode " + String(Mode) + " fadeSpeeed: " + String(darkDelay)); 
    }      
    else {
      darkDelay = 100;
      //Serial.println("Else darkDelay: " + String(darkDelay));
    }

    checkButtons();
    delay(1);
    //controlsMax();
    //Serial.println("Count if Waiting = False: " + String(count));
    //Serial.println("Bank - " + String(Bank) + " Mode " + String(Mode) + " fadeSpeeed: " + String(darkDelay)); 
          
  }
  }
    else if (Bank == 3)
  {

  }
  else;
}