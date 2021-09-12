/**

  Simple Potentiometer Test to change the RGB values of the onboard DotStar LED for the Adafruit Gemma M0
  This sketch is good for finding cool colors to use in other routines or to verify correct operation.

  A0 = Green LED value (Brightness)
  A1 = Red LED value (Brightness)
  A2 = Blue LED value (Brightness)
  
  -Pedal Brainz

*/

#include <Adafruit_DotStar.h>

/* Set the on-board DotStar as "pixel". */
Adafruit_DotStar pixel = Adafruit_DotStar(1, INTERNAL_DS_DATA, INTERNAL_DS_CLK, DOTSTAR_BGR);

/* Set a default variable for the red, blue, and green (RGB) value of the on-board Dot Star*/

int redValue = 0;
int blueValue = 0;
int greenValue = 0;

void setup() {
  //Start the Serial Communication
  Serial.begin(57600);
  //Start the on-board DotStar LED
  pixel.begin();
  //Start the Brightness of the on-board DotStar LED
  pixel.setBrightness(255);
}

void loop() {

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

  // Declare the LED "number" (0) and set a value for each potentiometer (pin) for colors R,G,B
  pixel.setPixelColor(0, (redValue), (greenValue), (blueValue));
  pixel.show();

  //This will print the value of all thee Potentiometers in the Serial Monitor and Serial Plotter
  Serial.println("Potentiometer A1: " + String(redValue) + " Potentiometer A0: " + String(blueValue) + " Potentiometer A2: " + String(greenValue));
}
