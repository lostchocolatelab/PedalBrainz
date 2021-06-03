/**

  Rainbow Mode Fades in/out a cycle of colors using the onboard DotStar LED for the Adafruit Gemma M0
  This sketch allows for variable control of the rainbow speed, brightness, and darkness delay between cycles.

  A0 = Speed of Rainbow Cycle
  A1 = Delay when LED is off (Dark)
  A2 = Maximum Brightness

  -Pedal Brainz
  
    ***ATTRIBUTION***
  
  Rainbow Mode Adapted from here:
  https://www.instructables.com/How-to-Make-Proper-Rainbow-and-Random-Colors-With-/

*/

#include <Adafruit_DotStar.h>

/* Set the on-board DotStar as "pixel". */
Adafruit_DotStar pixel = Adafruit_DotStar(1, INTERNAL_DS_DATA, INTERNAL_DS_CLK, DOTSTAR_BGR);

// Declare the potentiometer variables
int valueA0;
int valueA1;
int valueA2;


/* Set a default variable for the red, blue, and green (RGB) value of the on-board Dot Star*/
int redValue = 0;
int blueValue = 0;
int greenValue = 0;

unsigned short pixelnumber = 0;

/**

  Arrays of numbers

*/

const uint8_t lights[360] = {
  0,   0,   0,   0,   0,   1,   1,   2,
  2,   3,   4,   5,   6,   7,   8,   9,
  11,  12,  13,  15,  17,  18,  20,  22,
  24,  26,  28,  30,  32,  35,  37,  39,
  42,  44,  47,  49,  52,  55,  58,  60,
  63,  66,  69,  72,  75,  78,  81,  85,
  88,  91,  94,  97, 101, 104, 107, 111,
  114, 117, 121, 124, 127, 131, 134, 137,
  141, 144, 147, 150, 154, 157, 160, 163,
  167, 170, 173, 176, 179, 182, 185, 188,
  191, 194, 197, 200, 202, 205, 208, 210,
  213, 215, 217, 220, 222, 224, 226, 229,
  231, 232, 234, 236, 238, 239, 241, 242,
  244, 245, 246, 248, 249, 250, 251, 251,
  252, 253, 253, 254, 254, 255, 255, 255,
  255, 255, 255, 255, 254, 254, 253, 253,
  252, 251, 251, 250, 249, 248, 246, 245,
  244, 242, 241, 239, 238, 236, 234, 232,
  231, 229, 226, 224, 222, 220, 217, 215,
  213, 210, 208, 205, 202, 200, 197, 194,
  191, 188, 185, 182, 179, 176, 173, 170,
  167, 163, 160, 157, 154, 150, 147, 144,
  141, 137, 134, 131, 127, 124, 121, 117,
  114, 111, 107, 104, 101,  97,  94,  91,
  88,  85,  81,  78,  75,  72,  69,  66,
  63,  60,  58,  55,  52,  49,  47,  44,
  42,  39,  37,  35,  32,  30,  28,  26,
  24,  22,  20,  18,  17,  15,  13,  12,
  11,   9,   8,   7,   6,   5,   4,   3,
  2,   2,   1,   1,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0
};

const uint8_t HSVlights[61] =
{ 0, 4, 8, 13, 17, 21, 25, 30, 34, 38, 42, 47, 51, 55, 59, 64, 68, 72, 76,
  81, 85, 89, 93, 98, 102, 106, 110, 115, 119, 123, 127, 132, 136, 140, 144,
  149, 153, 157, 161, 166, 170, 174, 178, 183, 187, 191, 195, 200, 204, 208,
  212, 217, 221, 225, 229, 234, 238, 242, 246, 251, 255
};

const uint8_t HSVlightsFwdRev[120] =
{ 0, 4, 8, 13, 17, 21, 25, 30, 34, 38, 42, 47, 51, 55, 59, 64, 68, 72, 76,
  81, 85, 89, 93, 98, 102, 106, 110, 115, 119, 123, 127, 132, 136, 140, 144,
  149, 153, 157, 161, 166, 170, 174, 178, 183, 187, 191, 195, 200, 204, 208,
  212, 217, 221, 225, 229, 234, 238, 242, 246, 251, 255, 251, 246, 242, 238,
  234, 229, 225, 221, 217, 212, 208, 204, 200, 195, 191, 187, 183, 178, 174,
  170, 166, 161, 157, 153, 149, 144, 140, 136, 132, 127, 123, 119, 115, 110,
  106, 102, 98, 93, 89, 85, 81, 76, 72, 68, 64, 59, 55, 51, 47, 42, 38, 34,
  30, 25, 21, 17, 13, 8, 4
};

const uint8_t HSVpower[121] =
{ 0, 2, 4, 6, 8, 11, 13, 15, 17, 19, 21, 23, 25, 28, 30, 32, 34, 36, 38, 40,
  42, 45, 47, 49, 51, 53, 55, 57, 59, 62, 64, 66, 68, 70, 72, 74, 76, 79, 81,
  83, 85, 87, 89, 91, 93, 96, 98, 100, 102, 104, 106, 108, 110, 113, 115, 117,
  119, 121, 123, 125, 127, 130, 132, 134, 136, 138, 140, 142, 144, 147, 149,
  151, 153, 155, 157, 159, 161, 164, 166, 168, 170, 172, 174, 176, 178, 181,
  183, 185, 187, 189, 191, 193, 195, 198, 200, 202, 204, 206, 208, 210, 212,
  215, 217, 219, 221, 223, 225, 227, 229, 232, 234, 236, 238, 240, 242, 244,
  246, 249, 251, 253, 255
};


/**

  Set the RGB

*/

void setRGBpoint(int pixelnumber, uint8_t redValue, uint8_t greenValue, uint8_t blueValue)
{
  pixel.setPixelColor(pixelnumber, redValue, 0, 0);
  pixel.setPixelColor(pixelnumber, 0, greenValue, 0);
  pixel.setPixelColor(pixelnumber, 0, 0, blueValue);

  //Serial.println(redValue);
  //Serial.println(greenValue);
  //Serial.println(blueValue);
}

// the real HSV rainbow
void trueHSV(int pixelnumber, int angle)
{
  byte red, green, blue;

  if (angle < 60) {
    redValue = 255;
    greenValue = HSVlights[angle];
    blueValue = 0;
  } else if (angle < 120) {
    redValue = HSVlights[120 - angle];
    greenValue = 255;
    blueValue = 0;
  } else if (angle < 180) {
    redValue = 0, greenValue = 255;
    blueValue = HSVlights[angle - 120];
  } else if (angle < 240) {
    redValue = 0, greenValue = HSVlights[240 - angle];
    blueValue = 255;
  } else if (angle < 300) {
    redValue = HSVlights[angle - 240], greenValue = 0;
    blueValue = 255;
  } else
  {
    redValue = 255, greenValue = 0;
    blueValue = HSVlights[360 - angle];
  }
  setRGBpoint(pixelnumber, redValue, greenValue, blueValue);
  pixel.setPixelColor(pixelnumber, redValue, greenValue, blueValue);

}

// the 'power-conscious' HSV rainbow
void powerHSV(int pixelnumber, int angle)
{
  byte redValue, greenValue, blueValue;
  if (angle < 120) {
    redValue = HSVpower[120 - angle];
    greenValue = HSVpower[angle];
    blueValue = 0;
  } else if (angle < 240) {
    redValue = 0;
    greenValue = HSVpower[240 - angle];
    blueValue = HSVpower[angle - 120];
  } else
  {
    redValue = HSVpower[angle - 240];
    greenValue = 0;
    blueValue = HSVpower[360 - angle];
  }
  setRGBpoint(pixelnumber, redValue, greenValue, blueValue);
  pixel.setPixelColor(pixelnumber, redValue, greenValue, blueValue);
  //pixel.show();
}

// sine wave rainbow
void sineLED(int pixelnumber, int angle)
{
  setRGBpoint(pixelnumber, lights[(angle + 120) % 360], lights[angle],  lights[(angle + 240) % 360]);
  pixel.setPixelColor(pixelnumber, lights[(angle + 120) % 360], lights[angle],  lights[(angle + 240) % 360]);

}

/**

  Get Ready

*/


void setup() {
  Serial.begin(57600);
  /* Start the DotStar LED */
  pixel.begin();
  pixel.setBrightness(0);
}

/**

  Fade in the LED from Dark to the beginning of the Rainbow cycle (Red)
  Run the Rainbow Cycle (True HSV, PowerHSV, or SineLED
  Fade out the LED at the end of the Rainbow

*/

void loop() {

  //Fade in from the beginning of the Rainbow cycle (Red)
  for (int x = 0; x < 255; x++)
  {
    //Change the rate of the rainbow cycling using potantiometer A0
    valueA0 = map(analogRead(A0), 0, 1024, 50, 0);
    valueA2 = map(analogRead(A2), 0, 1024, 0, 100);

    //Increase the value of the R value causing a fade in;
    pixel.setPixelColor(pixelnumber, x, 0, 0);

    //A delay amount between each increase in value mapped to A0 and divided
    delay(valueA0 / 2);
    pixel.show();
  }

  //Run the Rainbow cycle (Red)
  for (int k = 0; k < 360; k++)
  {

    // uncomment the mode (or modes) you need below.

    //trueHSV(0, k);

    powerHSV(0, k);

    //sineLED(0, k);

    pixel.show();

    //Change the rate of the rainbow cycling using potantiometer A0
    //valueA0 = map(analogRead(A0), 0, 1024, 10, 0-1);
    valueA0 = map(analogRead(A0), 0, 1024, 50, 0);
    delay(valueA0);

    //Change the maximum brightness of the LED using potantiometer A2
    valueA2 = map(analogRead(A2), 0, 1024, 0, 100);
    pixel.setBrightness(valueA2);

  }


  //Fade out from the end of the Rainbow (lol) cycle (Red)
  for (int x = 255; x >= 0; x--)
  {
    //Change the rate of the rainbow cycling using potantiometer A0
    valueA0 = map(analogRead(A0), 0, 1024, 50, 0);
    valueA2 = map(analogRead(A2), 0, 1024, 0, 100);

    //Reduces the value of the R value causing a fade out;
    pixel.setPixelColor(pixelnumber, x, 0, 0);

    //A delay amount between each reduction in value mapped to A0 and divided
    delay(valueA0 / 2);
    pixel.show();
  }

  //Add a delay (ms) at the end of the rainbow cycle using potantiometer A2 while the LED is dark
  valueA1 = map(analogRead(A1), 0, 1024, 0, 5000);
  delay(valueA1);

  Serial.println("Rate of Rainbow cycling: " + String(valueA0)  + " ||| Delay between Rainbow cycles (ms): " + String(valueA1) + " ||| Maximum Brightness value: " + String(valueA2));


}
