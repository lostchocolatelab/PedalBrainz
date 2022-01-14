void testColorPotentiometer() {

  //Start the Brightness of the on-board DotStar LED
  pixel.setBrightness(255);
  inner.setBrightness(255);
  strip.setBrightness(255);
  
  /* Read the value for each potentiometer (pin) and set as R, G, B continuously while looping*/

  //Potentiometer Top Left | A1 - Map the value of the potentiometer from 0-1024 to 0-256 to the variable redValue
  redValue = map(analogRead(A1), 0, 1024, 0, 256);
  //Serial.println("potentiometerA1: " + String(redValue)); //This will print the value of the A1 Potentiometer

  //Potentiometer Top Right | A0 - Map the value of the potentiometer from 0-1024 to 0-256 to the variable greenValue
  greenValue = map(analogRead(A0), 0, 1024, 0, 256);
  //Serial.println("potentiometerA0: " + String(greenValue)); //This will print the value of the A0 Potentiometer

  //Potentiometer Bottom Right | A2 - Map the value of the potentiometer from 0-1024 to 0-256 to the variable blueValue
  blueValue = map(analogRead(A2), 0, 1024, 0, 256);
  //Serial.println("potentiometerA2: " + String(blueValue)); //This will print the value of the A2 Potentiometer

  if (2 >= redValue)
  {
    redValue =0;
  }
    if (1 >= greenValue)
  {
    greenValue =0;
  }
    if (1 >= blueValue)
  {
    blueValue =0;
  }
  
  // Declare the LED "number" (0) and set a value for each potentiometer (pin) for colors R,G,B
  //pixel.setPixelColor(0, (redValue), (greenValue), (blueValue));
  //strip.setPixelColor(0,0,0,0);

  strip.setPixelColor(0, redValue, blueValue, greenValue);
  strip.setPixelColor(1, redValue, blueValue, greenValue);
  strip.setPixelColor(2, redValue, blueValue, greenValue);
  //strip.setPixelColor(3, redValue, blueValue, greenValue);
  
  pixel.setPixelColor(0, redValue, blueValue, greenValue);
  inner.setPixelColor(0, redValue, blueValue, greenValue);
  
  inner.show();
  strip.show();
  pixel.show();

  checkButtons();

  //This will print the value of all thee Potentiometers in the Serial Monitor and Serial Plotter
  //Serial.println("Potentiometer A1: RED " + String(redValue)  + " Potentiometer A2: BLUE " + String(blueValue)+ " Potentiometer A0: GREEN " + String(greenValue));
}

void testBrightPotentiometer() {

  

  //Potentiometer Top Left | A1 - Map the value of the potentiometer from 0-1024 to 0-256 to the variable redValue
  //MaxBrightTemp = map(analogRead(A1), 0, 1024, 0, 256);
  //Serial.println("potentiometerA1: " + String(redValue)); //This will print the value of the A1 Potentiometer

  //Potentiometer Top Right | A0 - Map the value of the potentiometer from 0-1024 to 0-256 to the variable greenValue
  //MaxBrightTemp = map(analogRead(A0), 0, 1024, 0, 256);
  //Serial.println("potentiometerA0: " + String(greenValue)); //This will print the value of the A0 Potentiometer

  //Potentiometer Bottom Right | A2 - Map the value of the potentiometer from 0-1024 to 0-256 to the variable blueValue
  MaxBrightTemp = map(analogRead(A0), 0, 1024, 0, 256);
  //Serial.println("MaxBrightTemp: " + String(MaxBrightTemp)); //This will print the value of MaxBrightTemp
  
  //Start the Brightness of the on-board DotStar LED
  pixel.setBrightness(0);
  inner.setBrightness(0);
  strip.setBrightness(MaxBrightTemp);
  
  //Potentiometer Top Left | A1 - Map the value of the potentiometer from 0-1024 to 0-256 to the variable redValue
  redValue = map(analogRead(A0), 0, 1024, 0, 256);
  //Serial.println("potentiometerA1: " + String(redValue)); //This will print the value of the A1 Potentiometer
  greenValue = redValue;
  blueValue = redValue;
  
  // Declare the LED "number" (0) and set a value for each potentiometer (pin) for colors R,G,B
  //pixel.setPixelColor(0, (redValue), (greenValue), (blueValue));
  //strip.setPixelColor(0,0,0,0);

  strip.setPixelColor(0, 0, 0, 0);
  strip.setPixelColor(1, redValue, blueValue, greenValue);
  strip.setPixelColor(2, 0, 0, 0);
  //strip.setPixelColor(3, redValue, blueValue, greenValue);
  
  pixel.setPixelColor(0, 0, 0, 0);
  inner.setPixelColor(0, 0, 0, 0);
  
  inner.show();
  strip.show();
  pixel.show();

  checkButtons();

  //This will print the value of all thee Potentiometers in the Serial Monitor and Serial Plotter
  //Serial.println("Potentiometer A1: RED " + String(redValue)  + " Potentiometer A2: BLUE " + String(blueValue)+ " Potentiometer A0: GREEN " + String(greenValue));
}
