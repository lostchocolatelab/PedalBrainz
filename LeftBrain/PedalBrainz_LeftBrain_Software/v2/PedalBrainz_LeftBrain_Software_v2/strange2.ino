

void strangeAttractor2()
{
  //timestep = map(analogRead(A0), 0, 1024, 0.01, 0.1);

  //fadeSpeed = 0;

  maxBrightnessAdjust();

  attractorzType();
  checkButtons();
  
  pixelScaling();
  attractorzPixel();
  showLEDS();
  checkButtons();

  delayA0(fadeSpeed);
  checkButtons();

  strangeSlow3();
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

  Serial.print(",");
  Serial.print(scaledX);
  Serial.print(",");
  Serial.print(scaledY);
  Serial.print(",");
  Serial.println(scaledZ);  

  // Serial.print(",");
  // Serial.print(scaledXInner);
  // Serial.print(",");
  // Serial.print(scaledYInner);
  // Serial.print(",");
  // Serial.println(scaledZInner);  

}

void attractorzPixel()
{
  if (Mode == 1)
  {
      for (int p = 0; p < strip.numPixels(); p++) {   // For each pixel in strip...
        strip.setPixelColor(p, (scaledXInner/5), (0), (scaledZ));

      }
      pixel.setPixelColor(0, (scaledXInner/5), (0), (scaledZInner));   //Single Output Scaled XYZ
      inner.setPixelColor(0, (scaledXInner/5), (0), (scaledZInner));   //Single Output Scaled XYZ
  }
  else if (Mode == 2)
  {
      for (int p = 0; p < strip.numPixels(); p++) {   // For each pixel in strip...
        strip.setPixelColor(p, (scaledXInner/5), (scaledY/3), (scaledZ));

      }
      pixel.setPixelColor(0, (scaledXInner/5), (scaledYInner/3), (scaledZInner));   //Double Output Scaled XYZ
      inner.setPixelColor(0, (scaledXInner/5), (scaledYInner/3), (scaledZInner));   //Double Output Scaled XYZ
  }
  else if (Mode == 3)
  {
    for (int p = 0; p < strip.numPixels(); p++) {   // For each pixel in strip...
        strip.setPixelColor(p, (0), (scaledZ), (0));

      }
      pixel.setPixelColor(0, (0), (scaledZInner), (0));   //Single Output Scaled XYZ
      inner.setPixelColor(0, (0), (scaledZInner), (0));   //Single Output Scaled XYZ
  }
  else if (Mode == 4)
  {
      for (int p = 0; p < strip.numPixels(); p++) {   // For each pixel in strip...
        strip.setPixelColor(p, (0), (scaledZ), (scaledYInner/5));

      }
      pixel.setPixelColor(0, (0), (scaledZInner), (scaledYInner/5));   //Double Output Scaled XYZ
      inner.setPixelColor(0, (0), (scaledZInner), (scaledYInner/5));   //Double Output Scaled XYZ
  }
  else if (Mode == 5)
  {
      for (int p = 0; p < strip.numPixels(); p++) {   // For each pixel in strip...
        strip.setPixelColor(p, (scaledZ), (0), (0));

      }
      pixel.setPixelColor(0, (scaledZInner), (0), (0));   //Single Output Scaled XYZ
      inner.setPixelColor(0, (scaledZInner), (0), (0));   //Single Output Scaled XYZ
  }
  else if (Mode == 6)
  {
      for (int p = 0; p < strip.numPixels(); p++) {   // For each pixel in strip...
        strip.setPixelColor(p, (scaledZ), (scaledXInner/2), (0));

      }
      pixel.setPixelColor(0, (scaledZInner), (scaledXInner/2), (0));   //Single Output Scaled XYZ
      inner.setPixelColor(0, (scaledZInner), (scaledXInner/2), (0));   //Single Output Scaled XYZ
  }
  else if (Mode == 7)
  {
      for (int p = 0; p < strip.numPixels(); p++) {   // For each pixel in strip...
        strip.setPixelColor(p, (scaledZInner), (scaledXInner/4), (scaledZInner/4));

      }
      pixel.setPixelColor(0, (scaledZInner), (scaledXInner/4), (scaledZInner/4));   //Single Output Scaled XYZ
      inner.setPixelColor(0, (scaledZInner), (scaledXInner/4), (scaledZInner/4));   //Single Output Scaled XYZ
  }
  else if (Mode == 8)
  {
      for (int p = 0; p < strip.numPixels(); p++) {   // For each pixel in strip...
        strip.setPixelColor(p, (scaledZInner), (scaledZ), (scaledXInner/4));

      }
      pixel.setPixelColor(0, (scaledZInner), (scaledZInner), (scaledXInner/4));   //Single Output Scaled XYZ
      inner.setPixelColor(0, (scaledZInner), (scaledZInner), (scaledXInner/4));   //Single Output Scaled XYZ
  }
  else if (Mode == 9)
  {
      for (int p = 0; p < strip.numPixels(); p++) {   // For each pixel in strip...
        strip.setPixelColor(p, (scaledZInner), (scaledZ), (scaledXInner/4));

      }
      pixel.setPixelColor(0, (scaledZInner), (scaledZInner), (scaledXInner/4));   //Single Output Scaled XYZ
      inner.setPixelColor(0, (scaledZInner), (scaledZInner), (scaledXInner/4));   //Single Output Scaled XYZ
  }
  else if (Mode == 10)
  {
      for (int p = 0; p < strip.numPixels(); p++) {   // For each pixel in strip...
        strip.setPixelColor(p, (scaledZInner/10), (scaledZ), (scaledXInner/14));

      }
      pixel.setPixelColor(0, (scaledZInner/10), (scaledZInner), (scaledXInner/14));   //Single Output Scaled XYZ
      inner.setPixelColor(0, (scaledZInner/10), (scaledZInner), (scaledXInner/14));   //Single Output Scaled XYZ
  }
  else;
}

void attractorzSingle(){

  for (int p = 0; p < strip.numPixels(); p++) {   // For each pixel in strip...
        strip.setPixelColor(p, (0), (0), (scaledZ));

      }
      pixel.setPixelColor(0, (0), (0), (scaledZInner));   //Triple Output Scaled XYZ
      inner.setPixelColor(0, (0), (0), (scaledZInner));   //Triple Output Scaled XYZ

}

void attractorzDouble(){

  for (int p = 0; p < strip.numPixels(); p++) {   // For each pixel in strip...
        strip.setPixelColor(p, (0), (scaledY), (scaledZ));

      }
      pixel.setPixelColor(0, (0), (scaledYInner), (scaledZInner));   //Triple Output Scaled XYZ
      inner.setPixelColor(0, (0), (scaledYInner), (scaledZInner));   //Triple Output Scaled XYZ

}

void attractorzTriple(){

  for (int p = 0; p < strip.numPixels(); p++) {   // For each pixel in strip...
        strip.setPixelColor(p, (scaledX), (scaledY), (scaledZ));

      }
      pixel.setPixelColor(0, (scaledXInner), (scaledYInner), (scaledZInner));   //Triple Output Scaled XYZ
      inner.setPixelColor(0, (scaledXInner), (scaledYInner), (scaledZInner));   //Triple Output Scaled XYZ

}

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

  //updateRange();

  b = mapfloat(analogRead(A2), 0, 1024, -10, -14);
  
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

}

void lorentz83() {
  // put your main code here, to run repeatedly:

  dx = (((-a)*x)-(y*y)-(z*z)+(a*f)) * timestep;
  dy = ((-y) + (x * y) - (b * x * z) + g) * timestep;
  dz = ((-z) + (b * x * y) + (x * z)) * timestep;

  x += dx;
  y += dy;
  z += dz;

  b = mapfloat(analogRead(A2), 0, 1024, 11, 7.91);

  //updateRange();

}

void updateRange() {
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
}

void (* resetFunc)(void)=0; // declare reset function @ address 0

void checkRestart() {
  if(already == false) {
    already = true;
    return;
  }

  resetFunc();
  Serial.println("I Reset");
}


