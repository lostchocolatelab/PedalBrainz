/**
Simple Potentiometer Test to change the RGB values of the onboard DotStar LED
*/

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
    pixel.setBrightness(155);
}

void loop() {

/* Read the value for each potentiometer (pin) and get ready to set in. */

    //Potentiometer Top Right Rate Random
    valuePotentiometerA0 = potentiometerA0.read();
    Serial.println("potentiometerA0: ");
    Serial.println(valuePotentiometerA0);

    //Potentiometer Top Left Depth Random
    valuePotentiometerA1 = potentiometerA1.read();
    Serial.println("potentiometerA1: ");
    Serial.println(valuePotentiometerA1);

    //Potentiometer Bottom Right Rate 
    valuePotentiometerA2 = potentiometerA2.read();
    Serial.println("potentiometerA2: ");
    Serial.println(valuePotentiometerA2);

    
    /* Set a value for each potentiometer (pin) for colors R,G,B. */
    pixel.setPixelColor(0, valuePotentiometerA0, valuePotentiometerA1, valuePotentiometerA2); 
    pixel.show();  
}
