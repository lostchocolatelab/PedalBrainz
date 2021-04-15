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


void setup() {
    Serial.begin(57600);
    /* Start the DotStar LED */
    pixel.begin();
    //pixel.setBrightness(155);
    pixel.setPixelColor(0, 50, 255, 100); 
    pixel.show(); 
    
}

void loop() {
  int x = 1;
  for (int i = 0; i > -1; i = i + x) {
    pixel.setBrightness(i);
    pixel.show(); 
    valuePotentiometerA2 = potentiometerA2.read();
    Serial.println(valuePotentiometerA2);
    if (i == 50) {
      x = -1;  // switch direction at peak
    }
    valuePotentiometerA0 = potentiometerA0.read();
    delay(valuePotentiometerA0/1.9);
    
  }
  valuePotentiometerA1 = potentiometerA1.read();
  delay(valuePotentiometerA1*20);
}
