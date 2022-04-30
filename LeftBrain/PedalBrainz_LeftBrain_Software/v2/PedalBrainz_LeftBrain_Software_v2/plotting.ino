/**

  Serial Printing and Plotting

  This Section includes different ways to print and plot the variable to the Arduino Serial Monitor and Serial Plotter

*/

void plotCycle()
{

//Serial.println(" A0 = " + String(analogRead(A0)) + " A1 = " + String(analogRead(A1)) + " A2 = " + String(analogRead(A2)));

if (plotterPrint == true){
          
  ///*
  if (Mode == 1)
{
  Serial.println("Min:0,Max:100"); //Un-comment this for a smooth line
  //Serial.println(","); //Un-comment this for a smooth line
  Serial.println(currentVal);
  //Serial.println(valueA1);
  //Serial.println(valueA2);
  
}

  // If the Mode is 2-5, run print for fades
   if ((Mode >= 2) && (Mode <= 5))
  {
    //Serial.println("Min:0,Max:255");
    Serial.println("Min:0,Max:255"); //Un-comment this for a smooth line
    //Serial.print(","); //Un-comment this for a smooth line

    LEDBrightness = pixel.getBrightness();
    //Serial.println(LEDBrightness);
    Serial.println(redValue);
    //LEDBrightness = redValue + blueValue + greenValue;
  }

  if ((Mode >= 6) && (Mode <= 7))
    //if (6 <= Mode)
  {
    //Serial.print("Min:0,Max:300"); //Un-comment this for a smooth line
    //Serial.print(","); //Un-comment this for a smooth line
    Serial.println(currentVal);
    //Serial.print(","); //Un-comment this for a smooth line
  }
  if ((Mode >= 8) && (Mode <= 10))
    //if (6 <= Mode)
  {
    //Print some things
    Serial.print("Min:0,Max:200"); //Un-comment this for a smooth line
    Serial.print(","); //Un-comment this for a smooth line

    //printStrangeScaled(); // This one is nice
    //printStrangeScaled2();
    //printStrangeScaled3(); // This one is nice
    //printStrangeScaledSingle();

    //printStrangeEffective();

    //Serial.print("Min:0,Max:100");
    printStrangeXYZ(); // This one is the coolest
  }
  else;
} 
  //*/
}

void printStrangeXYZ()
{
  Serial.println("x:  " + String(x + 100) + " y:  " + String(y + 100) + " z:  " + String(z + 100));
  Serial.print("\n"); //Comment this line to not have a space between cicles
  //Serial.println("A0:  " + String(analogRead(A0)) + " A1:  " + String(analogRead(A1)) + " A2:  " + String(analogRead(A2)));
}


void printStrangeScaled()
{
  Serial.println(String(scaledX));
  Serial.println(String(scaledY));
  Serial.println(String(scaledZ));
}

void printStrangeScaled2()
{
  Serial.println("x:  " + String(scaledX) + " y:  " + String(scaledY) + " z:  " + String(scaledZ));
  Serial.print("\n"); //Comment this line to not have a space between cicles
}

void printStrangeScaled3()
{
  Serial.println(String(scaledX));
  Serial.print("\n"); //Comment this line to not have a space between cicles
  Serial.println(String(scaledY));
  Serial.print("\n"); //Comment this line to not have a space between cicles
  Serial.println(String(scaledZ));
  Serial.print("\n"); //Comment this line to not have a space between cicles
}

void printStrangeScaledSingle()
{
  //Serial.print(F("x:  "));
  //Serial.println(String(scaledX));
  //Serial.print(F("y:  "));
  //Serial.println(String(scaledY));
  Serial.print(F("z:  "));
  Serial.println(String(scaledZ));
  //Serial.print("\n"); //Comment this line to not have a space between cicles
}

void printStrangeEffective()
{
  Serial.print(F("  |  "));
  Serial.println(effectiveR);
  Serial.print(F("  |  "));
  Serial.println(effectiveG);
  Serial.print(F("  |  "));
  Serial.println(effectiveB);
  Serial.print("\n"); //Comment this line to not have a space between cicles
}
