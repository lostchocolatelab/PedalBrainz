#include <Adafruit_NeoPixel.h>
#include <AnalogIO.h>
#include <Adafruit_DotStar.h>

/* Set the DtoStar as "pixel". */
Adafruit_DotStar pixel = Adafruit_DotStar(1, INTERNAL_DS_DATA, INTERNAL_DS_CLK, DOTSTAR_BGR);

/* Creating the object for reading the value from a potentiometer. */
AnalogIn potentiometerA0(A0, BIT8);
AnalogIn potentiometerA1(A1, BIT8);
AnalogIn potentiometerA2(A2, BIT8);

/* Set a value for each potentiometer (pin). */
unsigned short valuePotentiometerA0 = 0;
unsigned short valuePotentiometerA1 = 0;
unsigned short valuePotentiometerA2 = 0;

unsigned short pixelnumber = 0;

// uint8_t is the same as byte
// uint16_t is unsigned int
// I just noticed that I mixed these in this sketch, sorry

const uint8_t lights[360]={
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
  0,   0,   0,   0,   0,   0,   0,   0};

const uint8_t HSVlights[61] = 
{0, 4, 8, 13, 17, 21, 25, 30, 34, 38, 42, 47, 51, 55, 59, 64, 68, 72, 76,
81, 85, 89, 93, 98, 102, 106, 110, 115, 119, 123, 127, 132, 136, 140, 144,
149, 153, 157, 161, 166, 170, 174, 178, 183, 187, 191, 195, 200, 204, 208,
212, 217, 221, 225, 229, 234, 238, 242, 246, 251, 255};

const uint8_t HSVpower[121] = 
{0, 2, 4, 6, 8, 11, 13, 15, 17, 19, 21, 23, 25, 28, 30, 32, 34, 36, 38, 40,
42, 45, 47, 49, 51, 53, 55, 57, 59, 62, 64, 66, 68, 70, 72, 74, 76, 79, 81, 
83, 85, 87, 89, 91, 93, 96, 98, 100, 102, 104, 106, 108, 110, 113, 115, 117, 
119, 121, 123, 125, 127, 130, 132, 134, 136, 138, 140, 142, 144, 147, 149, 
151, 153, 155, 157, 159, 161, 164, 166, 168, 170, 172, 174, 176, 178, 181, 
183, 185, 187, 189, 191, 193, 195, 198, 200, 202, 204, 206, 208, 210, 212, 
215, 217, 219, 221, 223, 225, 227, 229, 232, 234, 236, 238, 240, 242, 244, 
246, 249, 251, 253, 255};

//uint8_t outputPins[6] = {3, 5, 6, 9, 10, 11}; // PWM pins

// setRGBpoint (0, ...) for pins 3, 5, 6; setRGBpoint (1, ...) for pins 9, 10, 11.
// See array above
void setRGBpoint(int pixelnumber, uint8_t red, uint8_t green, uint8_t blue)
{
  // this code is for common anode LEDs. If you use common cathode ones,
  // remove the '255-' bits.
  pixel.setPixelColor(pixelnumber,red,0,0);
  pixel.setPixelColor(pixelnumber,0,green,0);
  pixel.setPixelColor(pixelnumber,0,0,blue);
  
//Serial.println(red);
//Serial.println(green);
//Serial.println(blue);
}

// the real HSV rainbow
void trueHSV(int pixelnumber, int angle)
{
  byte red, green, blue;

  if (angle<60) {red = 255; green = HSVlights[angle]; blue = 0;} else
  if (angle<120) {red = HSVlights[120-angle]; green = 255; blue = 0;} else 
  if (angle<180) {red = 0, green = 255; blue = HSVlights[angle-120];} else 
  if (angle<240) {red = 0, green = HSVlights[240-angle]; blue = 255;} else 
  if (angle<300) {red = HSVlights[angle-240], green = 0; blue = 255;} else 
                 {red = 255, green = 0; blue = HSVlights[360-angle];} 
  valuePotentiometerA0 = potentiometerA0.read();
  setRGBpoint(pixelnumber, red, green, blue);
  pixel.setPixelColor(pixelnumber,red,green,blue);
  pixel.show(); 
}

// the 'power-conscious' HSV rainbow
void powerHSV(int pixelnumber, int angle)
{
  byte red, green, blue;
  if (angle<120) {red = HSVpower[120-angle]; green = HSVpower[angle]; blue = 0;} else
  if (angle<240) {red = 0;  green = HSVpower[240-angle]; blue = HSVpower[angle-120];} else
                 {red = HSVpower[angle-240]; green = 0; blue = HSVpower[360-angle];}
    valuePotentiometerA0 = potentiometerA0.read();
    setRGBpoint(pixelnumber, red, green, blue);
    pixel.setPixelColor(pixelnumber,red,green,blue);
    pixel.show(); 
}

// sine wave rainbow
void sineLED(int pixelnumber, int angle)
{
  setRGBpoint(pixelnumber, lights[(angle+120)%360], lights[angle],  lights[(angle+240)%360]);
  //pixel.setPixelColor(pixelnumber, lights[(angle+120)%360], lights[angle],  lights[(angle+240)%360]);
}

void setup() {
}

void loop() {
  
for (int k=0; k<360; k++)
{

// uncomment the mode (or modes) you need below.
// with all six PWM outputs connected you may use 2 modes, change one 0 to 1.

//trueHSV(0, k);

powerHSV(0, k);

//sineLED(0, k);

delay(valuePotentiometerA0);
Serial.println(valuePotentiometerA0);
}
}
