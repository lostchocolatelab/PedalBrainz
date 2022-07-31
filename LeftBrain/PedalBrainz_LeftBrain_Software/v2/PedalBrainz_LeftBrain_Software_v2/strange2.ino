/**

  STRANGE ATTRACTORS 2

  Attractorz Maths implemented in code by Timothy Franceschi

*/

void strangeAttractor2()
{

  firstAttractorzType = true;
  attractorzIndicator();

  //  This handles the maximum brightness adjustment using the A1 control
  maxBrightnessAdjust();

  //  Specifies a different attractorz type depending on Mode
  //  x,y,z and a,b,c,d,e,f,g starting values for each attractorz type in the Bank/ Modez startup
  attractorzType();
  checkButtons();
  
  //  Scale the values of the attractorz to 0-255 for the A0, A1, A2 LEDs and 0-190 for the inner LEDs
  pixelScaling();
  attractorzPixel2();
  showLEDS();
  checkButtons();

  //  Use the value of A0 to control the fadeSpeed delay
  delayA0(fadeSpeed);
  checkButtons();

  //  Slow things down when the values are low
  strangeSlow3();
  checkButtons();

  if (plotterPrint == true)
  {
    // Serial.print(",");
    // Serial.print(scaledX);
    // Serial.print(",");
    // Serial.print(scaledY);
    // Serial.print(",");
    // Serial.print(scaledZ);  
    // Serial.print(",");
    // Serial.print(scaledXInner);  
    // Serial.print(",");
    // Serial.println(scaledInnerCombined); 

    // Serial.print(",");
    // Serial.print(x);
    // Serial.print(",");
    // Serial.print(y);
    // Serial.print(",");
    // Serial.println(z);  

    // Serial.print(",");
    // Serial.print(x);
    Serial.print(",");
    Serial.print(scaledX);  
    Serial.print(",");
    Serial.print(scaledXInner);  
    Serial.print(",");
    Serial.println(scaledInnerCombined);         

    // Serial.print(",");
    // Serial.print(scaledX);
    // Serial.print(",");
    // Serial.print(scaledY);
    // Serial.print(",");
    // Serial.println(scaledZ);     

    // Serial.print(",");
    // Serial.print(dx);
    // Serial.print(",");
    // Serial.print(dy);
    // Serial.print(",");
    // Serial.println(dz);      

  }
  else;

  //Serial.print(",");
  // Serial.print(x);
  // Serial.print(",");
  // Serial.print(y);
  // Serial.print(",");
  // Serial.println(z);

  // Serial.print(",");
  // Serial.print(scaledX);
  // Serial.print(",");
  // Serial.print(scaledY);
  // Serial.print(",");
  // Serial.print(scaledZ);  
  //Serial.print(",");
  //Serial.println(b);  
  //Serial.print(",");
  //Serial.println((scaledXInner+scaledYInner+scaledZInner)/3);  

  // Serial.print(",");
  // Serial.print(scaledXInner);
  // Serial.print(",");
  // Serial.print(scaledYInner);
  // Serial.print(",");
  // Serial.println(scaledZInner);  

}

void attractorzIndicator()
{

  attractorzIndicatorValue = mapfloat(analogRead(A2), 0, 1024, 0, 300);

  if (firstAttractorzType == true)
  {

    if (attractorzIndicatorValue <= 100)
    {
      attractorzLEDType = 1;
      attractorzIndicatorRoutine();
    }
    else if ((attractorzIndicatorValue >= 101) && (attractorzIndicatorValue <= 199))
    {
      attractorzLEDType = 2;
      attractorzIndicatorRoutine();
    }
    else if (attractorzIndicatorValue >= 200)
    {
      attractorzLEDType = 3;
      attractorzIndicatorRoutine();
    }
    else;

    //firstAttractorzType = false;

  }
  else;

  //firstAttractorzType = false

}

void attractorzIndicatorRoutine()
{

  attractorzIndicatorValue = mapfloat(analogRead(A2), 0, 1024, 0, 300);
  showLEDS();

  int constrainedBright;
  int attractorzIndicatorBright;

  if (attractorzLEDType == 1)
  {
      attractorzIndicatorBright = scaledX+255;
      constrainedBright = constrain(attractorzIndicatorBright, 0, 255);
      strip.setPixelColor(0, constrainedBright, constrainedBright, constrainedBright);
      //strip.show();
      showLEDS();
      //Serial.print("Single");
  }
  else if (attractorzLEDType == 2)
  {
      attractorzIndicatorBright = scaledX+255;
      constrainedBright = constrain(scaledX, 0, 255);
      strip.setPixelColor(1, constrainedBright, constrainedBright, constrainedBright);
      //strip.show();
      showLEDS();
      //Serial.print("Double");    
  }
  else if (attractorzLEDType == 3)
  {
      attractorzIndicatorBright = scaledX+255;
      constrainedBright = constrain(scaledX, 0, 255);
      strip.setPixelColor(2, constrainedBright, constrainedBright, constrainedBright);
      //strip.show();
      showLEDS();
      //Serial.print("Triple");
  }
  else;

}



  ////////////////////
  ////////////////////        Set the LED colors by Mode
  ////////////////////

void attractorzPixel()
{
  if (Mode == 1)
  {
      for (int p = 0; p < strip.numPixels(); p++) {   // For each pixel in strip...
          strip.setPixelColor(p, colorBlueDark);

        }
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
      for (int p = 0; p < strip.numPixels(); p++) {   // For each pixel in strip...
          strip.setPixelColor(p, colorBlueDark);

        }
      pixel.setPixelColor(0, (0), (scaledYInner)/2, (scaledYInner)/2);   //Double Output Scaled XYZ
      inner.setPixelColor(0, (0), (scaledYInner)/2, (scaledYInner)/2);   //Double Output Scaled XYZ  
  }
  else;
}

void attractorzPixel2()
{

    checkButtons();
    pixelScaling();
    attractorzIndicator();

    if (attractorzLEDType == 1)
    {
        for (int p = 0; p < strip.numPixels(); p++) {   // For each pixel in strip...
          strip.setPixelColor(p, (scaledX)/8, (scaledY)/2, (scaledZ));

        }
        //Triple Output Scaled Inner XYZ
        pixel.setPixelColor(0, (scaledInnerCombined), (scaledInnerCombined), (scaledInnerCombined));   
        inner.setPixelColor(0, (scaledInnerCombined), (scaledInnerCombined), (scaledInnerCombined)); 

    }
    else if (attractorzLEDType == 2)
    {
        for (int p = 0; p < strip.numPixels(); p++) {   // For each pixel in strip...
          strip.setPixelColor(p, (scaledX)/5, (scaledY), (scaledZ/10));

        }
        //Double Output Scaled Inner XYZ
        pixel.setPixelColor(0, (scaledInnerCombined), (0), (scaledInnerCombined));   
        inner.setPixelColor(0, (scaledInnerCombined), (0), (scaledInnerCombined)); 
          
    }
    else if (attractorzLEDType == 3)
    {

        for (int p = 0; p < strip.numPixels(); p++) {   // For each pixel in strip...
          strip.setPixelColor(p, (scaledX), (scaledY), (scaledZ/5));

        }
        //Single Output Scaled Inner XYZ
        pixel.setPixelColor(0, (scaledInnerCombined), (0), (0));   
        inner.setPixelColor(0, (scaledInnerCombined), (0), (0));           
    }
    else;      

}


void attractorzPixel3()
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
  pixelScaling();
  attractorzIndicator();

  if (Mode == 1)
  {
    
    thomasFunction();
    //arneodoFunction();
    //chenFunction();
    //scroll3Function();
    //lorentz83Function();
    //dadrasFunction();
    //halvorsenFunction();
    //rabinovichFunction();
    //rosslerFunction();
    //sprottFunction();
    //fourwingsFunction();
    //aizawaFunction();

  }
  else if (Mode == 2)
  {
    
    //thomasFunction();
    arneodoFunction();
    //chenFunction();
    //scroll3Function();
    //lorentz83Function();
    //dadrasFunction();
    //halvorsenFunction();
    //rabinovichFunction();
    //rosslerFunction();
    //sprottFunction();
    //fourwingsFunction();
    //aizawaFunction();

  }
  else if (Mode == 3)
  {
    
    //thomasFunction();
    //arneodoFunction();
    chenFunction();
    //scroll3Function();
    //lorentz83Function();
    //dadrasFunction();
    //halvorsenFunction();
    //rabinovichFunction();
    //rosslerFunction();
    //sprottFunction();
    //fourwingsFunction();
    //aizawaFunction();

  }
  else if (Mode == 4)
  {
    
    //thomasFunction();
    //arneodoFunction();
    //chenFunction();
    scroll3Function();
    //lorentz83Function();
    //dadrasFunction();
    //halvorsenFunction();
    //rabinovichFunction();
    //rosslerFunction();
    //sprottFunction();
    //fourwingsFunction();
    //aizawaFunction();

  }
  else if (Mode == 5)
  {
    
    //thomasFunction();
    //arneodoFunction();
    //chenFunction();
    //scroll3Function();
    lorentz83Function();
    //dadrasFunction();
    //halvorsenFunction();
    //rabinovichFunction();
    //rosslerFunction();
    //sprottFunction();
    //fourwingsFunction();
    //aizawaFunction();

  }
  else if (Mode == 6)
  {
    
    //thomasFunction();
    //arneodoFunction();
    //chenFunction();
    //scroll3Function();
    //lorentz83Function();
    //dadrasFunction();
    halvorsenFunction();
    //rabinovichFunction();
    //rosslerFunction();
    //sprottFunction();
    //fourwingsFunction();
    //aizawaFunction();

  }
  else if (Mode == 7)
  {
    
    //thomasFunction();
    //arneodoFunction();
    //chenFunction();
    //scroll3Function();
    //lorentz83Function();
    //dadrasFunction();
    //halvorsenFunction();
    rabinovichFunction();
    //rosslerFunction();
    //sprottFunction();
    //fourwingsFunction();
    //aizawaFunction();

  }
  else if (Mode == 8)
  {
    
    //thomasFunction();
    //arneodoFunction();
    //chenFunction();
    //scroll3Function();
    //lorentz83Function();
    //dadrasFunction();
    //halvorsenFunction();
    //rabinovichFunction();
    rosslerFunction();
    //sprottFunction();
    //fourwingsFunction();
    //aizawaFunction();

  }
  else if (Mode == 9)
  {
    
    //thomasFunction();
    //arneodoFunction();
    //chenFunction();
    //scroll3Function();
    //lorentz83Function();
    //dadrasFunction();
    //halvorsenFunction();
    //rabinovichFunction();
    //rosslerFunction();
    sprottFunction();
    //fourwingsFunction();
    //aizawaFunction();

  }
  else if (Mode == 10)
  {
    
    //thomasFunction();
    //arneodoFunction();
    //chenFunction();
    //scroll3Function();
    //lorentz83Function();
    //dadrasFunction();
    //halvorsenFunction();
    //rabinovichFunction();
    //rosslerFunction();
    //sprottFunction();
    fourwingsFunction();
    //aizawaFunction();

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

  scaledX = mapfloat(x, -3.5, 4, 0, 255);
  scaledY = mapfloat(y, -3.5, 4, 0, 255);
  scaledZ = mapfloat(z, -3.5, 4, 0, 255);
  scaledX = constrain(scaledX, 0, 255);
  scaledY = constrain(scaledY, 0, 255);
  scaledZ = constrain(scaledZ, 0, 255);

  updateRange();  

  //b = mapfloat(analogRead(A2), 0, 1024, .2, .01);

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
  
}

void arneodoFunction() {
  // put your main code here, to run repeatedly:

  dx = y * timestep;
  dy = z * timestep;
  dz = (((-a)*x) - (b*y) - z + (c * pow(x,3))) * timestep;

  x += dx;
  y += dy;
  z += dz;

  scaledX = mapfloat(x, -3.5, 3.5, 0, 255);
  scaledY = mapfloat(y, -3.5, 3.5, 0, 255);
  scaledZ = mapfloat(z, -3.5, 3.5, 0, 255);
  scaledX = constrain(scaledX, 0, 255);
  scaledY = constrain(scaledY, 0, 255);
  scaledZ = constrain(scaledZ, 0, 255);
  updateRange();  

  //b = mapfloat(analogRead(A2), 0, 1024, 8, 3.5);
  
}

void chenFunction() {
  // put your main code here, to run repeatedly:

  dx = ((a*x)-(y*z))*timestep;
  dy = ((b*y)+(x*z))*timestep;
  dz = ((c*z)+((x*y)/3))*timestep;

  x += dx;
  y += dy;
  z += dz;

  scaledX = mapfloat(x, -12, 12, 0, 255);
  scaledY = mapfloat(y, -12, 12, 0, 255);
  scaledZ = mapfloat(z, -12, 12, 0, 255); 
  scaledX = constrain(scaledX, 0, 255);
  scaledY = constrain(scaledY, 0, 255);
  scaledZ = constrain(scaledZ, 0, 255); 
  updateRange();  

  //b = mapfloat(analogRead(A2), 0, 1024, -10, -14);

}

void scroll3Function() {
  // put your main code here, to run repeatedly:

  dx = (a*(y-x) + (d*x*z)) * timestep * 0.1;
  dy = ((c*y) - (x*z)) * timestep * 0.1;
  dz = ((b*z) + (x*y) - (e*x*x)) * timestep * 0.1;

  x += dx;
  y += dy;
  z += dz;

  scaledX = mapfloat(x, -70, 70, 0, 255);
  scaledY = mapfloat(y, -70, 70, 0, 255);
  scaledZ = mapfloat(z, -70, 70, 0, 255); 
  scaledX = constrain(scaledX, 0, 255);
  scaledY = constrain(scaledY, 0, 255);
  scaledZ = constrain(scaledZ, 0, 255);
  updateRange();    

  //c = mapfloat(analogRead(A2), 0, 1024, 21.3, 20.3);  

}

void lorentz83Function() {
  // put your main code here, to run repeatedly:

  dx = (((-a)*x)-(y*y)-(z*z)+(a*f)) * timestep;
  dy = ((-y) + (x * y) - (b * x * z) + g) * timestep;
  dz = ((-z) + (b * x * y) + (x * z)) * timestep;

  x += dx;
  y += dy;
  z += dz;

  //b = mapfloat(analogRead(A2), 0, 1024, 7.91, 11);

  scaledX = mapfloat(x, -1.5, 2, 0, 255);
  scaledY = mapfloat(y, -1.5, 2, 0, 255);
  scaledZ = mapfloat(z, -1.5, 2, 0, 255);  
  scaledX = constrain(scaledX, 0, 255);
  scaledY = constrain(scaledY, 0, 255);
  scaledZ = constrain(scaledZ, 0, 255);
  updateRange();  

}

void halvorsenFunction() {
  // put your main code here, to run repeatedly:

  dx = ( -(a*x) - (4 * y) - (4 * z) - (y * y)) * timestep;
  dy = ( -(a*y) - (4 * z) - (4 * x) - (z * z)) * timestep;
  dz = ( -(a*z) - (4 * x) - (4 * y) - (x * x)) * timestep;

  x += dx;
  y += dy;
  z += dz;

  //a = mapfloat(analogRead(A2), 0, 1024, 3, 1.89); // Working

  scaledX = mapfloat(x, -13, 6, 0, 255);
  scaledY = mapfloat(y, -13, 6, 0, 255);
  scaledZ = mapfloat(z, -13, 6, 0, 255); 
  scaledX = constrain(scaledX, 0, 255);
  scaledY = constrain(scaledY, 0, 255);
  scaledZ = constrain(scaledZ, 0, 255);
  updateRange();  

}

void rabinovichFunction() {
  // put your main code here, to run repeatedly:

  float val = .11;

  dx = ( y * (z - 1 + (x * x)) + (b * x)) * timestep;
  dy = (( x * ((3 * z) + 1 - (x * x))) + (b * y)) * timestep;
  dz = ((-2 * z) * (a + (x * y))) * timestep;

  x += dx;
  y += dy;
  z += dz;

  //a = mapfloat(analogRead(A2), 0, 1024, 1, 0.14);
  //b = mapfloat(analogRead(A2), 0, 1024, 0.001, val); // Stable
  //b = mapfloat(analogRead(A2), 0, 1024, 0.001, 0.11); // Cool wiggles, overruns
  //b = mapfloat(analogRead(A2), 0, 1024, 0.001, 0.1); // Cool wiggles, overruns

  count = count+1;

  if (count >= 8000)
  {
    //already = false;

    if (Blink1 == true)
    {
      x = -1.00;
      y = 0.00;
      z = 0.50;

      a = 0.14;
      b = 0.11;
      //val = 0.11;

      Blink1 = false;
      count = 0;
    }
    else if (Blink1 == false)
    {
      x = -1.00;
      y = 0.00;
      z = 0.50;

      a = 0.14;
      b = 0.106;
      //val = 0.106;

      Blink1 = true;
      count = 0;
    }
    else;

  }
  else;

  scaledX = mapfloat(x, -2.4, 0.8, 0, 255);
  scaledY = mapfloat(y, -2.4, 0.8, 0, 255);
  scaledZ = mapfloat(z, -2.4, 0.8, 0, 255);
  scaledX = constrain(scaledX, 0, 255);
  scaledY = constrain(scaledY, 0, 255);
  scaledZ = constrain(scaledZ, 0, 255);
  updateRange();   

}

void rosslerFunction() {
  // put your main code here, to run repeatedly:

  dx = (-(y+z)) * timestep;
  dy = (x + (a * y)) * timestep;
  dz = (b + z * (x - c)) * timestep;

  x += dx;
  y += dy;
  z += dz;

  //a = mapfloat(analogRead(A2), 0, 1024, 0.5, 0.2);
  //b = mapfloat(analogRead(A2), 0, 1024, 5, 0.01);  // Working
  //b = mapfloat(analogRead(A2), 0, 1024, 5, 0.001);  
  //c = mapfloat(analogRead(A2), 0, 1024, 1, 5.7);

  scaledX = mapfloat(x, -9, 10, 0, 255);
  scaledY = mapfloat(y, -9, 10, 0, 255);
  scaledZ = mapfloat(z, -9, 10, 0, 255); 
  scaledX = constrain(scaledX, 0, 255);
  scaledY = constrain(scaledY, 0, 255);
  scaledZ = constrain(scaledZ, 0, 255);
  updateRange();    

}

void sprottFunction() {
  // put your main code here, to run repeatedly:

  dx = (y + (a * x * y) + (x * z)) * timestep;
  dy = (1 - (b * pow(x,2)) + (y * z)) * timestep;
  dz = (x - pow(x,2) - pow(y,2)) * timestep;

  x += dx;
  y += dy;
  z += dz;

  //a = mapfloat(analogRead(A2), 0, 1024, 10.03, 2.07);
  //b = mapfloat(analogRead(A2), 0, 1024, 1.06, 1.28);

  scaledX = mapfloat(x, 0, 1.75, 0, 255);
  scaledY = mapfloat(y, 0, 1.75, 0, 255);
  scaledZ = mapfloat(z, 0, 1.75, 0, 255);
  scaledX = constrain(scaledX, 0, 255);
  scaledY = constrain(scaledY, 0, 255);
  scaledZ = constrain(scaledZ, 0, 255);
  updateRange();       

}

void fourwingsFunction() {
  // put your main code here, to run repeatedly:

  dx = ((a * x) + (y * z)) * timestep;
  dy = ((b * x) + (c * y) - (x * z)) * timestep;
  dz = (-z - (x * y)) * timestep;

  x += dx;
  y += dy;
  z += dz;

  //a = mapfloat(analogRead(A2), 0, 1024, 0.1, 0.25);
  //b = mapfloat(analogRead(A2), 0, 1024, 0.12, 0.01);

  scaledX = mapfloat(x, -2, 2.5, 0, 255);
  scaledY = mapfloat(y, -2, 2.5, 0, 255);
  scaledZ = mapfloat(z, -2, 2.5, 0, 255);  
  scaledX = constrain(scaledX, 0, 255);
  scaledY = constrain(scaledY, 0, 255);
  scaledZ = constrain(scaledZ, 0, 255);
  updateRange();   

}

void aizawaFunction() {
  // put your main code here, to run repeatedly:

  dx = (((z - b) * x) - (d * y)) * timestep;
  dy = ((d * x) + ((z - b) * y)) * timestep;
  dz = (c + (a * z) - (pow(z,3)/3) - ((pow(x,2) + pow(y,2)) * (1 + (e * z))) + (f * z * pow(x,3))) * timestep;

  x += dx;
  y += dy;
  z += dz;

  //b = mapfloat(analogRead(A2), 0, 1024, 2.01, 0.7); //stable
  //b = mapfloat(analogRead(A2), 0, 1024, 2.01, 0.7); 
  //a = mapfloat(analogRead(A2), 0, 1024, 0.2, 3.5); 

  updateRange();

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
  else;

  // if(mapfloat(x,minValue,maxValue,1,255) == 255){
  //   checkRestart();
  // } else if(mapfloat(y,minValue,maxValue,1,255) == 255){
  //   checkRestart();
  // } else if(mapfloat(z,minValue,maxValue,1,255) == 255){
  //   checkRestart();
  // } {
  //   already = false;
  // }  

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

void resetAttractorz()
{

    updateScaling(0, 0, 1, 0, 0);
    updateScaling(0, 0, 1, 0, 0);
    updateScaling(0, 0, 1, 0, 0);

    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    f = 0;
    g = 0;

    w = 0;
    x = 0;
    y = 0;
    z = 0;

    dx = 0;
    dy = 0;
    dz = 0;

    scaledX = 0;
    scaledY = 0;
    scaledZ = 0;
    effectiveR = 0;
    effectiveG = 0;
    effectiveB = 0;
    scaledXInner = 0;
    scaledYInner = 0;
    scaledZInner = 0;
    scaledInnerCombined = 0;

    timestep = 0.1;
}


      //          thomas attractor init maths

      // b = 0.19;

      // x = 1;
      // y = 2;
      // z = 1;

      // timestep = .1;

      //          arneodo attractor init maths

      // a = -5.5;
      // b = 3.5;
      // c = -1;

      // x = 0.5;
      // y = 0.1;
      // z = 0.3;

      // timestep = 0.008;

      //          chen attractor init maths

      // a = 5.0;
      // b = -10.0;
      // c = -0.38;

      // x = 5;
      // y = 10;
      // z = 10;

      // timestep = 0.005;

      //          scroll 3 attractor init maths

      // a = 40.0;
      // b = 0.833;
      // c = 20.0;
      // d = 0.5;
      // e = 0.65;

      // x = 2.1;
      // y = 0.9;
      // z = 1.2;

      // timestep = 0.01;

      //          lorentz83 attractor init maths

      // a = 0.95;
      // b = 7.91;
      // f = 4.83;
      // g = 4.66;

      // x = -0.2;
      // y = -2.82;
      // z = 2.71;

      // timestep = 0.005;

      //          dadras attractor init maths

      // a = 3;
      // b = 2.7;
      // c = 1.7;
      // d = 2;
      // e = 9;

      // x = 0.5;
      // y = 0.1;
      // z = 0.3;

      // timestep = 0.01;

      //          halvorsen attractor init maths

      //  x = -1.48;
      //  y = -1.51;
      //  z = 2.04;

      //  a = 1.89;

      //  timestep = 0.01;


      //          Rabinovich-Fabrikant attractor init maths

      //  Blink1 = true;
      //  x = -1.00;
      //  y = 0.00;
      //  z = 0.50;

      //  a = 0.14;
      //  b = 0.1;

      //  timestep = 0.01;

      //          rossler attractor init maths

      //  x = 10.0;
      //  y = 0;
      //  z = 10.0;

      //  a = 0.2;
      //  b = 0.2;
      //  c = 5.7;

      //  timestep = 0.01;

      //          Sprott attractor init maths

      // x = 0.63;
      // y = 0.47;
      // z = -0.54;

      // a = 2.07;
      // b = 1.79;

      // timestep = 0.01;

      //          Four wings attractor init maths


      // x = 0.63;
      // y = 0.47;
      // z = -0.54;

      // a = 0.2;
      // b = 0.01;
      // c = -0.4;

      // timestep = 0.05;


      //          Aizawa attractor init maths

      // x = 0.1;
      // y = 1;
      // z = 0.01;

      // a = 0.95;
      // b = 0.7;
      // c = 0.6;
      // d = 3.5;
      // e = 0.25;
      // f = 0.1;

      // timestep = 0.01;