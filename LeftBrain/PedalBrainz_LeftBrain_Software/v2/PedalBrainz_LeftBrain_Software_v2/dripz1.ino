// This is an example how to create a dripping effect using the FastLED library
// https://codebender.cc/sketch:213839#Dripping%20Icicle.ino

#define TRAIL_LENGTH       30
#define TRAIL_DIM_BY       60
#define DRIP_HUE           130
#define DRIP_HUE_SKEW      10
#define DRIP_SAT           190
#define MIRROR             false
#define MIRROR_INV_COLOR   true
#define STOP_SEGMENT       30

byte led_pos = 0;
byte inv_led_pos = NUM_LEDS-1;

byte trail_pos = 0;
byte lead_pos = 0;
CHSV colorDrip;
CHSV alt_colorDrip;

void dripz() 
{

  //A1 potentiometer controls for maximum brightness
  maxBrightnessAdjust();
  checkButtons();

  fadeSpeed = map(analogRead(A0), 0, 1024, 2, 60);
  //darkDelay = map(analogRead(A2), 0, 1024, speedMinimum/2, 100); 

  // send the 'leds' array out to the actual LED strip
  averageLEDS(); 
  FastLED.show();  

  // insert a delay to keep the framerate modest
  //FastLED.delay(1000/fadeSpeed);
  FastLED.delay((speedMinimum/10)/fadeSpeed);
  //delayA2(1000/fadeSpeed);
  
  fadeToBlackBy(leds, NUM_LEDS, TRAIL_DIM_BY);
  
  if (trail_pos == 0) 
  {
  	lead_pos++;
	if (lead_pos >= NUM_LEDS) 
	{
		colorDrip = CHSV(DRIP_HUE+(DRIP_HUE_SKEW*led_pos),DRIP_SAT,255);
		alt_colorDrip = CHSV(DRIP_HUE+(DRIP_HUE_SKEW*led_pos)+127,DRIP_SAT,255);
	  	leds[led_pos] = colorDrip;
		if (MIRROR) {
			if (MIRROR_INV_COLOR) leds[inv_led_pos] = alt_colorDrip;
		    else leds[inv_led_pos] = colorDrip;
		}
		inv_led_pos--;
		led_pos++;
	} else 
	{
		CHSV color_1 = CHSV(DRIP_HUE+NUM_LEDS-lead_pos,DRIP_SAT,map(lead_pos, 1, NUM_LEDS, 1, 255));
		CHSV color_2 = CHSV(DRIP_HUE+NUM_LEDS-lead_pos,DRIP_SAT,map(lead_pos, 1, NUM_LEDS, 1, 64));
		CHSV alt_color_1 = CHSV(DRIP_HUE+NUM_LEDS-lead_pos+127,DRIP_SAT,map(lead_pos, 1, NUM_LEDS, 1, 255));
		CHSV alt_color_2 = CHSV(DRIP_HUE+NUM_LEDS-lead_pos+127,DRIP_SAT,map(lead_pos, 1, NUM_LEDS, 1, 64));
		
		if (MIRROR) 
		{
			leds[inv_led_pos-1] = color_2;
			leds[inv_led_pos] = color_1;
			if (MIRROR_INV_COLOR) 
			{
				leds[inv_led_pos-1] = alt_color_2;
				leds[inv_led_pos] = alt_color_1;
			}
		}
		leds[led_pos] = color_1;
		leds[led_pos+1] = color_2;
	}
  }
  
  if (led_pos >= STOP_SEGMENT-1) 
  {
  	trail_pos++;
  	if (trail_pos <= TRAIL_LENGTH*0.50) 
  	{
  		leds[led_pos] = colorDrip;
  		if (MIRROR) {
  			leds[inv_led_pos] = colorDrip;
  			if (MIRROR_INV_COLOR) {
  				leds[inv_led_pos] = alt_colorDrip;
  			}
  		}
  	}
  	if (trail_pos >= TRAIL_LENGTH) 
  	{
  		leds[led_pos] = CHSV(0,0,0);

		if (Bank == 4 && Mode == 4)
		{
			darkDelay = map(analogRead(A2), 0, 1024, speedMinimum/2, 100); 
			randomAmountA2 = random(-1000, darkDelay+5000);
			darkDelay = darkDelay+randomAmountA2;
  		delayA2(darkDelay);
		}
		else if (Bank == 4 && Mode == 4)
		{
			darkDelay = map(analogRead(A2), 0, 1024, speedMinimum/2, 100); 
			randomAmountA2 = random(-1000, darkDelay+5000);
			darkDelay = darkDelay+randomAmountA2;
  		delayA2(darkDelay);			
		}
		else
		{
			darkDelay = map(analogRead(A2), 0, 1024, speedMinimum/2, 100); 
			randomAmountA2 = random(-500, darkDelay+1000);
			darkDelay = darkDelay+randomAmountA2;
  		delayA2(darkDelay);
		}


		if (MIRROR) leds[inv_led_pos] = CHSV(0,0,0);

  		trail_pos = 0;
  		led_pos = 0;
  		lead_pos = 0;
  		inv_led_pos = NUM_LEDS-1;
  	}
  }
}