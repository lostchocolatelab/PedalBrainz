/**

  Simple Fade In/Out with Delays of the onboard DotStar LED for the Adafruit Gemma M0
  This sketch is good for controlling the speed of fade in/ out and delay times while fully bright and dark.

  -Pedal Brainz

*/

#include <Adafruit_DotStar.h>

/* Set the on-board DotStar as "pixel". */
Adafruit_DotStar pixel = Adafruit_DotStar(1, INTERNAL_DS_DATA, INTERNAL_DS_CLK, DOTSTAR_BGR);

// Declare the potentiometer variables
int valueA0;
int valueA1;
int valueA2;

// Set a default variable for the red, blue, and green (RGB) value of the on-board Dot Star
// Pink! Potentiometer A0: 236 Potentiometer A1: 73 Potentiometer A2: 107

int redValue = 236;
int blueValue = 73;
int greenValue = 107;


void setup() {
  Serial.begin(57600);
  /* Start the DotStar LED */
  pixel.begin();
  pixel.setBrightness(255);
  pixel.setPixelColor(0, redValue, blueValue, greenValue);
  pixel.show();

}

void loop() {
  int x = 1;

  //This fades the brightness in and out using maths
  for (int i = 0; i > -1; i = i + x) {
    pixel.setBrightness(i);
    pixel.show();


    //If the fade has reached it's peak keep the LED lit and then fade out

    if (i == 50) {

      //Potentiometer Top Right | A1 - Map the value of the potentiometer from 0-1024 to 0-5000 to the variable valueA1
      valueA1 = map(analogRead(A1), 0, 1024, 0, 5000);

      //Use the value of A1 to keep the LED fully lit by the amount of A1 (delay) and then start fading out
      delay(valueA1);
      Serial.println("Delay when LED fully lit (ms): " + String(valueA1));

      x = -1;  // switch direction at peak
    }

    //Potentiometer Top Right | A0 - Map the value of the potentiometer from 0-1024 to 0-135 to the variable valueA0
    valueA0 = map(analogRead(A0), 0, 1024, 2, 135);

    //Use the value of A0 to control the rate of fade in/out using a delay
    delay(valueA0);
  }
  Serial.println("Rate of Fade in/ Fade out: " + String(valueA0));

  //Potentiometer Bottom Right | A2 - Map the value of the potentiometer from 0-1024 to 0-5000 to the variable valueA2
  valueA2 = map(analogRead(A2), 0, 1024, 0, 5000);

  //Use the value of A2 to keep the LED fully dark (delay) between fade in/fade out
  delay(valueA2);
  Serial.println("Delay when LED fully dark (ms): " + String(valueA2));

  //Serial.println("Rate of Fade in/ Fade out: " + String(valueA0) + " ||| Delay when LED fully lit (ms): " + String(valueA1) + " ||| Delay when LED fully dark (ms): " + String(valueA2));
}
