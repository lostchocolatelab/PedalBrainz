/**

  STRANGE ATTRACTORS 2

  Attractorz Maths implemented in code by Timothy Franceschi

*/

void strangeAttractor2()
{
  //timestep = map(analogRead(A0), 0, 1024, 0.01, 0.1);

  //fadeSpeed = 0;

  //  This handles the maximum brightness adjustment using the A1 control
  maxBrightnessAdjust();

  //  Specifies a different attractorz type depending on Mode
  //  x,y,z and a,b,c,d,e,f,g starting values for each attractorz type in the Bank/ Modez startup
  attractorzType();
  checkButtons();
  
  //  Scale the values of the attractorz to 0-255 for the A0, A1, A2 LEDs and 0-190 for the inner LEDs
  pixelScaling();
  attractorzPixel();
  showLEDS();
  checkButtons();

  //  Use the value of A0 to control the fadeSpeed delay
  delayA0(fadeSpeed);
  checkButtons();

  //  Slow things down when the values are low
  //strangeSlow3();
  checkButtons();

  // Serial.print(", X:");
  // Serial.print(x);
  // Serial.print(",Y:");
  // Serial.print(y);
  // Serial.print(",Z:");
  // Serial.println(z);


  //Serial.print(",");
  // Serial.print(x);
  // Serial.print(",");
  // Serial.print(y);
  // Serial.print(",");
  // Serial.println(z);

  //Serial.print(",");
  Serial.print(scaledX);
  Serial.print(",");
  Serial.print(scaledY);
  Serial.print(",");
  Serial.println(scaledZ);  
  //Serial.print(",");
  //Serial.println((scaledXInner+scaledYInner+scaledZInner)/3);  

  // Serial.print(",");
  // Serial.print(scaledXInner);
  // Serial.print(",");
  // Serial.print(scaledYInner);
  // Serial.print(",");
  // Serial.println(scaledZInner);  

}

  ////////////////////
  ////////////////////        Set the LED colors by Mode
  ////////////////////

void attractorzPixel()
{
  if (Mode == 1)
  {
      // for (int p = 0; p < strip.numPixels(); p++) {   // For each pixel in strip...
      //   strip.setPixelColor(p, (scaledXInner/5), (0), (scaledZ));

      // }
      // pixel.setPixelColor(0, (scaledXInner/5), (0), (scaledZInner));   //Single Output Scaled XYZ
      // inner.setPixelColor(0, (scaledXInner/5), (0), (scaledZInner));   //Single Output Scaled XYZ

      strip.setPixelColor(0, (scaledX), (0), (scaledX/5));
      strip.setPixelColor(1, (scaledY), (0), (scaledY/3));
      strip.setPixelColor(2, (scaledZ), (0), (scaledZ/1));
      pixel.setPixelColor(0, (scaledXInner), (0), (0));   //Single Output Scaled XYZ
      inner.setPixelColor(0, (scaledXInner), (0), (0));   //Single Output Scaled XYZ

  }
  else if (Mode == 2)
  {
      // for (int p = 0; p < strip.numPixels(); p++) {   // For each pixel in strip...
      //   strip.setPixelColor(p, (scaledXInner/5), (scaledY/3), (scaledZ));

      // }

      strip.setPixelColor(0, (scaledX)/5, (0), (scaledX));
      strip.setPixelColor(1, (scaledY)/3, (0), (scaledY));
      strip.setPixelColor(2, (scaledZ)/1, (0), (scaledZ));      
      pixel.setPixelColor(0, (scaledXInner)/2, (0), (scaledYInner)/2);   //Single Output Scaled XYZ
      inner.setPixelColor(0, (scaledXInner)/2, (0), (scaledYInner)/2);   //Single Output Scaled XYZ
  }
  else if (Mode == 3)
  {
    // for (int p = 0; p < strip.numPixels(); p++) {   // For each pixel in strip...
    //     strip.setPixelColor(p, (0), (scaledZ), (0));

    //   }

      strip.setPixelColor(0, (0), (scaledX), (scaledX)/5);
      strip.setPixelColor(1, (0), (scaledY), (scaledY)/3);
      strip.setPixelColor(2, (0), (scaledZ), (scaledZ)/1);
      pixel.setPixelColor(0, (0), (scaledZInner), (0));   //Single Output Scaled XYZ
      inner.setPixelColor(0, (0), (scaledZInner), (0));   //Single Output Scaled XYZ    
  }
  else if (Mode == 4)
  {
      // for (int p = 0; p < strip.numPixels(); p++) {   // For each pixel in strip...
      //   strip.setPixelColor(p, (0), (scaledZ), (scaledYInner/5));

      // }

      strip.setPixelColor(0, (0), (scaledX)/5, (scaledX));
      strip.setPixelColor(1, (0), (scaledY)/3, (scaledY));
      strip.setPixelColor(2, (0), (scaledZ)/1, (scaledZ));
      pixel.setPixelColor(0, (0), (scaledZInner)/2, (scaledYInner/2));   //Double Output Scaled XYZ
      inner.setPixelColor(0, (0), (scaledZInner)/2, (scaledYInner/2));   //Double Output Scaled XYZ
  }
  else if (Mode == 5)
  {
      // for (int p = 0; p < strip.numPixels(); p++) {   // For each pixel in strip...
      //   strip.setPixelColor(p, (scaledZ), (0), (0));

      // }

      strip.setPixelColor(0, (scaledX), (scaledX)/5, (0));
      strip.setPixelColor(1, (scaledY), (scaledY)/3, (0));
      strip.setPixelColor(2, (scaledZ), (scaledZ)/1, (0));
      pixel.setPixelColor(0, (scaledXInner), (0), (0));   //Single Output Scaled XYZ
      inner.setPixelColor(0, (scaledXInner), (0), (0));   //Single Output Scaled XYZ    
  }
  else if (Mode == 6)
  {
      // for (int p = 0; p < strip.numPixels(); p++) {   // For each pixel in strip...
      //   strip.setPixelColor(p, (scaledZ), (scaledXInner/2), (0));

      // }

      strip.setPixelColor(0, (scaledX)/5, (scaledX), (0));
      strip.setPixelColor(1, (scaledY)/3, (scaledY), (0));
      strip.setPixelColor(2, (scaledZ)/1, (scaledZ), (0));
      pixel.setPixelColor(0, (scaledZInner)/2, (scaledXInner)/2, (0));   //Double Output Scaled XYZ
      inner.setPixelColor(0, (scaledZInner)/2, (scaledXInner)/2, (0));   //Double Output Scaled XYZ
  }
  else if (Mode == 7)
  {
      // for (int p = 0; p < strip.numPixels(); p++) {   // For each pixel in strip...
      //   strip.setPixelColor(p, (scaledZInner), (scaledXInner/4), (scaledZInner/4));

      // }

      strip.setPixelColor(0, (scaledX), (scaledX), (scaledX)/10);
      strip.setPixelColor(1, (scaledY)/5, (scaledY), (scaledY)/10);
      strip.setPixelColor(2, (scaledZ), (scaledZ), (scaledZ)/10);
      pixel.setPixelColor(0, (0), (0), (scaledXInner));   //Single Output Scaled XYZ
      inner.setPixelColor(0, (0), (0), (scaledXInner));   //Single Output Scaled XYZ       
}
  else if (Mode == 8)
  {
      // for (int p = 0; p < strip.numPixels(); p++) {   // For each pixel in strip...
      //   strip.setPixelColor(p, (scaledZInner), (scaledZ), (scaledXInner/4));

      // }

      strip.setPixelColor(0, (scaledX), (scaledX)/2, (scaledX)/10);
      strip.setPixelColor(1, (scaledY), (scaledY)/2, (scaledY)/10);
      strip.setPixelColor(2, (scaledZ)/2, (scaledZ)/2, (scaledZ)/10);
      pixel.setPixelColor(0, (0), (scaledYInner)/2, (scaledXInner)/2);   //Double Output Scaled XYZ
      inner.setPixelColor(0, (0), (scaledYInner)/2, (scaledXInner)/2);   //Double Output Scaled XYZ       
 }
  else if (Mode == 9)
  {
      // for (int p = 0; p < strip.numPixels(); p++) {   // For each pixel in strip...
      //   strip.setPixelColor(p, (scaledZInner), (scaledZ), (scaledXInner/4));

      // }

      strip.setPixelColor(0, (scaledX)/10, (scaledX), (scaledX)/5);
      strip.setPixelColor(1, (scaledY)/10, (scaledY), (scaledY)/4);
      strip.setPixelColor(2, (scaledZ)/10, (scaledZ), (scaledZ)/3);
      pixel.setPixelColor(0, (0), (scaledYInner)/2, (scaledYInner)/2);   //Single Output Scaled XYZ
      inner.setPixelColor(0, (0), (scaledYInner)/2, (scaledYInner)/2);   //Single Output Scaled XYZ   
  }
  else if (Mode == 10)
  {
      // for (int p = 0; p < strip.numPixels(); p++) {   // For each pixel in strip...
      //   strip.setPixelColor(p, (scaledZInner/10), (scaledZ), (scaledXInner/14));

      // }
 
      strip.setPixelColor(0, (scaledX)/6, (scaledX), (scaledX));
      strip.setPixelColor(1, (scaledY)/6, (scaledY), (scaledY));
      strip.setPixelColor(2, (scaledZ)/6, (scaledZ), (scaledZ));
      pixel.setPixelColor(0, (0), (scaledYInner)/2, (scaledYInner)/2);   //Double Output Scaled XYZ
      inner.setPixelColor(0, (0), (scaledYInner)/2, (scaledYInner)/2);   //Double Output Scaled XYZ  
  }
  else;
}

  ////////////////////
  ////////////////////        Set the attractorz type by Mode
  ////////////////////        x,y,z and a,b,c,d,e,f,g starting values in the Bank/ Modez startup
  ////////////////////

void attractorzType()
{
  if (Mode == 1)
  {
    
    thomasFunction();
    //arneodoFunction();
    //chenFunction();
    //scroll3Function();
    //lorentz83();
    //dadrasFunction();

  }
  else if (Mode == 2)
  {
    
    thomasFunction();
    //arneodoFunction();
    //chenFunction();
    //scroll3Function();
    //lorentz83();
    //dadrasFunction();

  }
  else if (Mode == 3)
  {
    
    //thomasFunction();
    arneodoFunction();
    //chenFunction();
    //scroll3Function();
    //lorentz83();
    //dadrasFunction();

  }
  else if (Mode == 4)
  {
    
    //thomasFunction();
    arneodoFunction();
    //chenFunction();
    //scroll3Function();
    //lorentz83();
    //dadrasFunction();

  }
  else if (Mode == 5)
  {
    
    //thomasFunction();
    //arneodoFunction();
    chenFunction();
    //scroll3Function();
    //lorentz83();
    //dadrasFunction();

  }
  else if (Mode == 6)
  {
    
    //thomasFunction();
    //arneodoFunction();
    chenFunction();
    //scroll3Function();
    //lorentz83();
    //dadrasFunction();

  }
  else if (Mode == 7)
  {
    
    //thomasFunction();
    //arneodoFunction();
    //chenFunction();
    scroll3Function();
    //lorentz83();
    //dadrasFunction();

  }
  else if (Mode == 8)
  {
    
    //thomasFunction();
    //arneodoFunction();
    //chenFunction();
    scroll3Function();
    //lorentz83();
    //dadrasFunction();

  }
  else if (Mode == 9)
  {
    
    //thomasFunction();
    //arneodoFunction();
    //chenFunction();
    //scroll3Function();
    lorentz83();
    //dadrasFunction();

  }
  else if (Mode == 10)
  {
    
    //thomasFunction();
    //arneodoFunction();
    //chenFunction();
    //scroll3Function();
    lorentz83();
    //dadrasFunction();

  }
  else;
}

void thomasFunction() {
  // put your main code here, to run repeatedly:
  dx = ((-b * x)+sin(y)) * timestep;
  dy = ((-b * y)+sin(z)) * timestep;
  dz = ((-b * z)+sin(x)) * timestep;

  x += dx;
  y += dy;
  z += dz;

  updateRange();

  b = mapfloat(analogRead(A2), 0, 1024, .2, .01);

  if(map(x,minValue,maxValue,1,255) == 255){
    checkRestart();
  } else if(map(y,minValue,maxValue,1,255) == 255){
    checkRestart();
  } else if(map(z,minValue,maxValue,1,255) == 255){
    checkRestart();
  } {
    already = false;
  }
}

void dadrasFunction() {
 
  dx = (y - (a*x) + (b*y*z)) * timestep;
  dy = ((c*y) - (x*z) + z) * timestep;
  dz = ((d*x*y) - (e*z)) * timestep;

  x = x + dx;
  //Serial.print(".");
  y = y + dy;
  //Serial.print(".");
  z = z + dz;
  //Serial.println(".");
  
  updateRange();

  //c = mapfloat(analogRead(A0), 0, 1024, 10, 3.1);

  if(mapfloat(x,minValue,maxValue,1,255) == 255){
    checkRestart();
  } else if(mapfloat(y,minValue,maxValue,1,255) == 255){
    checkRestart();
  } else if(mapfloat(z,minValue,maxValue,1,255) == 255){
    checkRestart();
  } {
    already = false;
  }
  
}

void arneodoFunction() {
  // put your main code here, to run repeatedly:

  dx = y * timestep;
  dy = z * timestep;
  dz = (((-a)*x) - (b*y) - z + (c * pow(x,3))) * timestep;

  x += dx;
  y += dy;
  z += dz;
  
  updateRange();

  b = mapfloat(analogRead(A2), 0, 1024, 8, 3.5);

  if(map(x,minValue,maxValue,1,255) == 255){
    checkRestart();
  } else if(map(y,minValue,maxValue,1,255) == 255){
    checkRestart();
  } else if(map(z,minValue,maxValue,1,255) == 255){
    checkRestart();
  } {
    already = false;
  }
  
}

void chenFunction() {
  // put your main code here, to run repeatedly:

  dx = ((a*x)-(y*z))*timestep;
  dy = ((b*y)+(x*z))*timestep;
  dz = ((c*z)+((x*y)/3))*timestep;

  x += dx;
  y += dy;
  z += dz;

  updateRange();

  b = mapfloat(analogRead(A2), 0, 1024, -10, -14);
  
  if(map(x,minValue,maxValue,1,255) == 255){
    checkRestart();
  } else if(map(y,minValue,maxValue,1,255) == 255){
    checkRestart();
  } else if(map(z,minValue,maxValue,1,255) == 255){
    checkRestart();
  } {
    already = false;
  }  
}

void scroll3Function() {
  // put your main code here, to run repeatedly:

  dx = (a*(y-x) + (d*x*z)) * timestep * 0.1;
  dy = ((c*y) - (x*z)) * timestep * 0.1;
  dz = ((b*z) + (x*y) - (e*x*x)) * timestep * 0.1;

  x += dx;
  y += dy;
  z += dz;

  updateRange();

  c = mapfloat(analogRead(A2), 0, 1024, 21.3, 20.3);  

  if(map(x,minValue,maxValue,1,255) == 255){
    checkRestart();
  } else if(map(y,minValue,maxValue,1,255) == 255){
    checkRestart();
  } else if(map(z,minValue,maxValue,1,255) == 255){
    checkRestart();
  } {
    already = false;
  }
}

void lorentz83() {
  // put your main code here, to run repeatedly:

  dx = (((-a)*x)-(y*y)-(z*z)+(a*f)) * timestep;
  dy = ((-y) + (x * y) - (b * x * z) + g) * timestep;
  dz = ((-z) + (b * x * y) + (x * z)) * timestep;

  x += dx;
  y += dy;
  z += dz;

  b = mapfloat(analogRead(A2), 0, 1024, 7.91, 11);

  updateRange();

  if(map(x,minValue,maxValue,1,255) == 255){
    checkRestart();
  } else if(map(y,minValue,maxValue,1,255) == 255){
    checkRestart();
  } else if(map(z,minValue,maxValue,1,255) == 255){
    checkRestart();
  } {
    already = false;
  }
}

void updateRange() 
{

  if(x > maxValue){
    maxValue = x;
  }
  if(x < minValue){
    minValue = x;
  }
  if(y > maxValue){
    maxValue = y;
  }
  if(y < minValue){
    minValue = y;
  }
  if(z > maxValue){
    maxValue = z;
  }
  if(z < minValue){
    minValue = z;
  }

  checkButtons();

}



void checkRestart() {
  if(already == false) {
    already = true;
    return;
  }

  resetFunc();
  Serial.println("I Reset");
}


