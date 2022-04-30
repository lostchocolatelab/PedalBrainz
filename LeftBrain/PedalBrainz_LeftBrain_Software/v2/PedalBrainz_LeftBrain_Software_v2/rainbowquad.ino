
      //  Rainbow Quadz
      //  Cycles through 6 colors. The Brightness of each color is modulated 4 times. Default brightness set in declarations.
      //  Modez 1 - Uses randomBright01-04 Declared in General Declarations
      //  Modez 2 - Randomize Brightness values for the 4 values once at startup
      //  Modez 3 - Randomize Brightness values for the 4 values after each cycle
      //
      //  Set Color -> Set 4 Brightness Values w/ Delay (A1) -> Delay before setting next Color (A0)
      //
      //  A0 = Duration of 4th brightness after brightness changes for a single color
      //  A1 = Delay of each Brightness Value (4) for a Single Color
      //  A2 = Duration of Darkness after full Color Cycle (or betwixt each color if darkDelayBetwixtColors is enabled)

int randomBright0 = 50;
int randomBright1 = 90;
int randomBright2 = 155;
int randomBright3 = 255;

int MaxBrightReductionQuad;
int MaxBrightReductionQuad0;
int MaxBrightReductionQuad1;
int MaxBrightReductionQuad2;
int MaxBrightReductionQuad3;

int InnerBrightReductionQuad;
int InnerBrightReductionQuad0;
int InnerBrightReductionQuad1;
int InnerBrightReductionQuad2;
int InnerBrightReductionQuad3;



/* rainbow2 */
uint32_t colorone = 0xFF007F;
uint32_t colortwo = 0x6200FF;
uint32_t colorthree = 0xBEFF00;
uint32_t colorfour = 0x00FF34;
uint32_t colorfive = 0x0400FF;
uint32_t colorsix = 0x2600CA;

/**

Brightness Blink 6

*/

void RainbowQuad() {

    
    buttonBreak = false;

    //maxBrightness = map(analogRead(A1), 0, 1024, 0, maxBrightnessTemp);

    MaxBrightReduction = constrain(maxBrightness, 0, MaxBright);
    pixel.setBrightness(maxBrightness);
    strip.setBrightness(MaxBrightReduction);
    FastLED.setBrightness(MaxBrightReduction);
    inner.setBrightness(maxBrightness);
    showLEDS();

    //Serial.println("maxBrightness : " + String(maxBrightness));
    //Serial.println("MaxBright : " + String(MaxBright));
    //Serial.println("MaxBrightReduction : " + String(MaxBrightReduction));


    if (Mode == 2) {
        brightnessStatic();
        rainbowSaw();
    }
    else if (Mode == 3) {
        randomOnce = 0;
        setRandomBrightsOnce();
        rainbowSaw();
    }
    else if (Mode == 4) {
        setRandomBrights();
        rainbowSaw();
    }
    else if (Mode == 5) {
        brightnessStatic();
        rainbowPyramid();
    }
    else if (Mode == 6) {
        randomOnce = 0;
        setRandomBrightsOnce();
        rainbowPyramid();
    }
    else if (Mode == 7) {
        setRandomBrights();
        rainbowPyramid();
    }
    else;

    darkLEDSDelay();

}



void rainbowSaw(){

    int i;
    int x;

    for(i=0;i<6;i++) 
    {
        quadNumber(i);

        if (buttonBreak == true) 
        {

            Serial.println("I Broke because quadNumber button was clicked");
            breakdelayA0 = true;
            breakdelayA1 = true;
            breakdelayA2 = true;
            //clicked = false;
            break;

            }
            else if (buttonBreak == false)
            {
                for(x=0;x<4;x++) 
                        {

                            if (buttonBreak == true) 
                            {

                                Serial.println("I Broke because showQuad button was clicked");
                                breakdelayA0 = true;
                                breakdelayA1 = true;
                                breakdelayA2 = true;
                                //clicked = false;
                                break;

                            }
                                else if (buttonBreak == false)
                                {
                                    brightnessNumber(x);
                                    Serial.println("Setting the brightnessCount/ brightnessNumber: " + String(x));

                                    showQuad(); 
                                } 
                        }
            }
        if (buttonBreak == true) 
        {
            break;
            buttonBreak == false;
        }
        else;
    }

}

void rainbowPyramid(){

    int i;
    int x;

    for(i=0;i<6;i++) 
    {
        quadNumber(i);

        if (buttonBreak == true) 
        {

            Serial.println("I Broke because quadNumber button was clicked");
            breakdelayA0 = true;
            breakdelayA1 = true;
            breakdelayA2 = true;
            //clicked = false;
            break;

            }
            else if (buttonBreak == false)
            {
                for(x=0;x<4;x++) 
                        {

                            if (buttonBreak == true) 
                            {

                                Serial.println("I Broke because showQuad button was clicked");
                                breakdelayA0 = true;
                                breakdelayA1 = true;
                                breakdelayA2 = true;
                                //clicked = false;
                                break;

                            }
                                else if (buttonBreak == false)
                                {
                                    brightnessNumber(x);
                                    Serial.println("Setting the brightnessCount/ brightnessNumber: " + String(x));

                                    showQuad(); 
                                } 
                        }
            }
        if (buttonBreak == true) 
        {
            break;
            buttonBreak == false;
        }
        else;
    }

    for(i=6;i<0;i++) 
    {
        quadNumber(i);

        if (buttonBreak == true) 
        {

            Serial.println("I Broke because quadNumber button was clicked");
            breakdelayA0 = true;
            breakdelayA1 = true;
            breakdelayA2 = true;
            //clicked = false;
            break;

            }
            else if (buttonBreak == false)
            {
                for(x=4;x<0;x++) 
                        {

                            if (buttonBreak == true) 
                            {

                                Serial.println("I Broke because showQuad button was clicked");
                                breakdelayA0 = true;
                                breakdelayA1 = true;
                                breakdelayA2 = true;
                                //clicked = false;
                                break;

                            }
                                else if (buttonBreak == false)
                                {
                                    brightnessNumber(x);
                                    Serial.println("Setting the brightnessCount/ brightnessNumber: " + String(x));

                                    showQuad(); 
                                } 
                        }
            }
        if (buttonBreak == true) 
        {
            break;
            buttonBreak == false;
        }
        else;
    }    

}


void quadNumber(int quadStep)
{
    //Serial.println("colorone");

    if (quadStep == 0) 
    {
        pixel.setPixelColor(0, colorone);
        inner.setPixelColor(0, colorone);
        for (int p = 0; p < strip.numPixels(); p++) {       // For each pixel in strip...
            strip.setPixelColor(p, colorone);
        }
    }
    else if (quadStep == 1) 
    {
        //Serial.println("colortwo");

        pixel.setPixelColor(0, colortwo);
        inner.setPixelColor(0, colortwo);
        for (int p = 0; p < strip.numPixels(); p++) {       // For each pixel in strip...
            strip.setPixelColor(p, colortwo);
        }
    }
    else if (quadStep == 2) 
    {
        //Serial.println("colorthree");
        pixel.setPixelColor(0, colorthree);
        inner.setPixelColor(0, colorthree);
        for (int p = 0; p < strip.numPixels(); p++) {       // For each pixel in strip...
            strip.setPixelColor(p, colorthree);

        }
    }
    else if (quadStep == 3) 
    {
        //Serial.println("colorfour");
        pixel.setPixelColor(0, colorfour);
        inner.setPixelColor(0, colorfour);
        for (int p = 0; p < strip.numPixels(); p++) {       // For each pixel in strip...
            strip.setPixelColor(p, colorfour);
        }
    }
    else if (quadStep == 4) 
    {
        //Serial.println("colorfive");
        pixel.setPixelColor(0, colorfive);
        inner.setPixelColor(0, colorfive);
        for (int p = 0; p < strip.numPixels(); p++) {       // For each pixel in strip...
            strip.setPixelColor(p, colorfive);
        }
    }
    else if (quadStep == 5) 
    {
        //Serial.println("colorsix");
        pixel.setPixelColor(0, colorsix);
        inner.setPixelColor(0, colorsix);
        for (int p = 0; p < strip.numPixels(); p++) {       // For each pixel in strip...
            strip.setPixelColor(p, colorsix);
        }
    }
    else;

    // Delay the change to the next color by the amount of A0
    delayA0(fadeSpeed);

    // Add an amount of darkness by the amount of A2
    darkDelayBetwixtColors();
}

void showQuad()
{
        
        LEDBrightness = pixel.getBrightness();
        Serial.println("Setting the quadBrightnessAmount: " + String(LEDBrightness));

        // Set the brightness
        pixel.setBrightness(InnerBrightReductionQuad);
        inner.setBrightness(InnerBrightReductionQuad);
        strip.setBrightness(MaxBrightReductionQuad);
        FastLED.setBrightness(MaxBrightReductionQuad);
        showLEDS();

        // Delay the change to the next brightness by the amount of A1
        delayA1(fullDelay);

        //Serial.println("Full Delay Quad: " + String(fullDelay));
}

void quadBrightnessAmount(int quadBrightnessNumber)
{

    if (quadBrightnessNumber = 0)
    {

        // Set the brightness
        pixel.setBrightness(InnerBrightReductionQuad0);
        inner.setBrightness(InnerBrightReductionQuad0);
        strip.setBrightness(MaxBrightReductionQuad0);
        FastLED.setBrightness(MaxBrightReductionQuad0);
    }
    else if (quadBrightnessNumber = 1)
    {
        // Set the brightness
        pixel.setBrightness(InnerBrightReductionQuad1);
        inner.setBrightness(InnerBrightReductionQuad1);
        strip.setBrightness(MaxBrightReductionQuad1);
        FastLED.setBrightness(MaxBrightReductionQuad1);
    }
    else if (quadBrightnessNumber = 2)
    {
        // Set the brightness
        pixel.setBrightness(InnerBrightReductionQuad2);
        inner.setBrightness(InnerBrightReductionQuad2);
        strip.setBrightness(MaxBrightReductionQuad2);
        FastLED.setBrightness(MaxBrightReductionQuad2);
    }
    else if (quadBrightnessNumber = 3)
    {
        // Set the brightness
        pixel.setBrightness(InnerBrightReductionQuad3);
        inner.setBrightness(InnerBrightReductionQuad3);
        strip.setBrightness(MaxBrightReductionQuad3);
        FastLED.setBrightness(MaxBrightReductionQuad3);
    }
    else;

    // Show the LEDS after the Brightness values have been set
    showLEDS();

    // Delay the change to the next brightness by the amount of A1
    delayA1(fullDelay);

    //Serial.println("Full Delay 1: " + String(fullDelay));
    LEDBrightness = pixel.getBrightness();
    Serial.println("Setting the quadBrightnessAmount: " + String(LEDBrightness));

}

void brightnessNumber(int brightnessCount)
{
    if (brightnessCount == 0)
    {
        //randomBright0 = 50;

        InnerBrightReductionQuad = map(randomBright0, 0, 255, 0, 190);
        MaxBrightReductionQuad = map(randomBright0, 0, 255, 0, MaxBright);

        Serial.println("brightnessCount variable: " + String(brightnessCount));
        Serial.println("brightnessCount: 0");
    }
    else if (brightnessCount == 1)
    {
        //randomBright1 = 90;

        InnerBrightReductionQuad = map(randomBright1, 0, 255, 0, 190);
        MaxBrightReductionQuad = map(randomBright1, 0, 255, 0, MaxBright);

        Serial.println("brightnessCount variable: " + String(brightnessCount));
        Serial.println("brightnessCount: 1");
    }
    else if (brightnessCount == 2)
    {
        //randomBright2 = 155;

        InnerBrightReductionQuad = map(randomBright2, 0, 255, 0, 190);
        MaxBrightReductionQuad = map(randomBright2, 0, 255, 0, MaxBright);

        Serial.println("brightnessCount variable: " + String(brightnessCount));
        Serial.println("brightnessCount: 2");
    }
    else if (brightnessCount == 3)
    {
        //randomBright3 = 255; 

        InnerBrightReductionQuad = map(randomBright3, 0, 255, 0, 190);
        MaxBrightReductionQuad = map(randomBright3, 0, 255, 0, MaxBright);

        Serial.println("brightnessCount variable: " + String(brightnessCount));
        Serial.println("brightnessCount: 3");
    }
    else;
}

void brightnessStatic()
{
    randomBright0 = 50;
    randomBright1 = 90;
    randomBright2 = 155;
    randomBright3 = 255;
}

void setRandomBrights() {

    randomBright0  = random(10, 255);
    randomBright1  = random(10, 255);
    randomBright2  = random(10, 255);
    randomBright3  = random(10, 255);

}

void setRandomBrightsOnce() {
    if (randomOnce == 0) {

        randomBright0  = random(10, 255);
        randomBright1  = random(10, 255);
        randomBright2  = random(10, 255);
        randomBright3  = random(10, 255);

        randomOnce = 1;

    }
    else
    {
        
    }


}

void darkLEDS() {

    // Make the pixel dark

    strip.setBrightness(0);
    FastLED.setBrightness(0);
    pixel.setBrightness(0);
    inner.setBrightness(0);

    for (int p = 0; p < strip.numPixels(); p++) {       // For each pixel in strip...
        strip.setPixelColor(p, 0, 0, 0);
    }
    pixel.setPixelColor(0, 0, 0, 0);
    inner.setPixelColor(0, 0, 0, 0);
    showLEDS();

    

    //delayA2(darkDelay);
    //Serial.println("dark");

}

void darkLEDSDelay() {

    darkDelay = map(analogRead(A2), 0, 1024, 0, durationMaximum);
    //Serial.println("darkDelay " + String(darkDelay));

    if (darkDelay > 30) {

      // Make the pixel dark

        strip.setBrightness(0);
        FastLED.setBrightness(0);
        pixel.setBrightness(0);
        inner.setBrightness(0);

        for (int p = 0; p < strip.numPixels(); p++) {       // For each pixel in strip...
            strip.setPixelColor(p, 0, 0, 0);
        }
        pixel.setPixelColor(0, 0, 0, 0);
        inner.setPixelColor(0, 0, 0, 0);
        showLEDS();

    }
    

    delayA2(darkDelay);
    //Serial.println("dark");

}

void darkDelayBetwixtColors() {

    
    //darkLEDS();

    // Make the pixel dark
    /*FastLED.setBrightness(0);
    for(int p=0; p<strip.numPixels(); p++) {       // For each pixel in strip...
    strip.setPixelColor(p, 0,0,0);
    }
    strip.show();

    pixel.setPixelColor(0, 0,0,0);
    pixel.setBrightness(0);
    pixel.show();

    inner.setPixelColor(0, 0,0,0);
    inner.setBrightness(0);
    inner.show();*/

    // Delay by the amount of A2 - Remove the following comment to turn the led off between each color
    //delayA2(darkDelay);

}
