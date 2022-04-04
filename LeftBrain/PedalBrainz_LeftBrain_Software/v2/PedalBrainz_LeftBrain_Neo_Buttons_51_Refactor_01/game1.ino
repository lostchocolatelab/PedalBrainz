/*
 * Sezme.
 * 
 * A game for the Arduino Uno that tests your memory.
 * 
 * Sezme is a memory game in which the Arduino generates a series
 * of random LED flashes. The player must then press the buttons and
 * repeat the sequence of flashes in the correct order. If the player
 * guesses incorrectly a buzzer sounds, the correct sequence is shown 
 * and the game starts again. If the player guesses correctly, the 
 * difficulty level goes up.
 * 
 * The buttons are connected to digital pins 2 through 5 via
 * a 10K Ohm pull-down resistor.
 * 
 * The LEDs (yellow, blue, green & red) positive legs are connected to
 * pins 9 through 13. The negative legs are connected to GND via a 220 Ohm resistor.
 * 
 * Button connected to pin 2 controls the yellow LED
 * Button connected to pin 3 controls the blue LED
 * Button connected to pin 4 controls the green LED
 * Button connected to pin 5 controls the red LED
 * 
 * 
 * Author: Mario Gianota December 2019
 */

const int LED_YELLOW  = 1; // Yellow LED pin
const int LED_BLUE    = 2; // Blue LED pin
const int LED_GREEN   = 1; // Green LED pin
const int LED_RED     = 2; // Red LED pin

const int BUTTON_YELLOW = A9;  // Yellow button input pin
const int BUTTON_BLUE   = A10;  // Blue button input pin
const int BUTTON_GREEN  = A9;  // Green button input pin
const int BUTTON_RED    = A10;  // Red button input pin

const int MAX_DIFFICULTY_LEVEL    = 9;  // Maximum difficulty level (LED flash sequence length)

// Array used to store the generated random sequence
int randomSequence[MAX_DIFFICULTY_LEVEL];

// Array used to store the player's guess
int playerGuess[MAX_DIFFICULTY_LEVEL];

int btnState = 0;  // button state checker
int btnStateUp = 0;  // button state checker
int btnStateDown = 0;  // button state checker

int Randomness = random(0, 1000);



void memoryGame() {
//delay(5000);
  // Run the state machine controlling the game's states
  switch( currentState ) {
    case STATE_START_GAME: 
      Serial.println("Case: START GAME"); 
      //delay(1000); // Give player time to get ready
      startFlash();
      nextState = STATE_PICK_RND_SEQUENCE; 
      break;
    case STATE_PICK_RND_SEQUENCE:
      Serial.println("Case: PICK RANDOM");
      generateRndSequence();
      nextState = STATE_SHOW_RND_SEQUENCE;
      break; 
    case STATE_SHOW_RND_SEQUENCE:
      Serial.println("Case: SHOW RANDOM");
      showRndSequence();  // Display the rnd sequence to the player
      showLEDS();
      nextState = STATE_READ_PLAYER_GUESS;
      break;
    case STATE_READ_PLAYER_GUESS:
      //Serial.println("Case: READ GUESS");
      //Serial.println("READ GUESS");
      readPlayerGuess();  // Poll buttons and record each button press
      // If all inputs have been made then verify the guess
      if( numButtonPresses >= difficultyLevel ) {
        numButtonPresses = 0;
        nextState = STATE_VERIFY_GUESS;
      }
      
      break;
    case STATE_VERIFY_GUESS:
      //Serial.println("Case: VERIFY GUESS");
      // Check player's guess against the generated random sequence
      if( verifyGuess() ) {
        nextState = STATE_GUESS_CORRECT;
      } else {
        nextState = STATE_GUESS_INCORRECT;
      }
      break;
    case STATE_GUESS_CORRECT:
      // Player was right. Increase difficulty level and goto start game
      correctFlash();
      Serial.println("Case: CORRECT");
      difficultyLevel++;
      if( difficultyLevel > MAX_DIFFICULTY_LEVEL )
        difficultyLevel = MAX_DIFFICULTY_LEVEL;
      nextState = STATE_START_GAME;
      break;
    case STATE_GUESS_INCORRECT:
      Serial.println("Case: INCORRECT");
      // Player was wrong. Sound buzzer, show correct sequence, set difficulty level to 1 and re-start game
      failFlash();
      showRndSequence();
      difficultyLevel = 1;
      nextState = STATE_START_GAME;
      break;
  }
  currentState = nextState;
}



// Generate a random sequence of LED pin numbers
void generateRndSequence() {
  for(int i=0; i<difficultyLevel; i++) {
    randomSequence[i] = rndLEDPin();
    showLEDS();
    Serial.println("gen dIFFICUKY lEVEL: " + String(difficultyLevel));
  }
    //darkLED();
}

// Show random sequence
void showRndSequence() {
  for(int i=0; i<difficultyLevel; i++) {
    flashLED(randomSequence[i]);  
    //showLEDS();
    /*
    Serial.println("show random seq 1: " + String(randomSequence[0]));
    Serial.println("show random seq 2: " + String(randomSequence[1]));
    Serial.println("show random seq 3: " + String(randomSequence[2]));
    Serial.println("show random seq 4: " + String(randomSequence[3]));
    Serial.println("show random seq 5: " + String(randomSequence[4]));
    Serial.println("show random seq 6: " + String(randomSequence[5]));
    Serial.println("show random seq 7: " + String(randomSequence[6]));
    Serial.println("show random seq 8: " + String(randomSequence[7]));
    */
  }
    showLEDS();
    //darkLED();
}

// Read a button press representing a guess from player
void readPlayerGuess() {
  
    //darkLED();
    
  if( digitalRead(BUTTON_YELLOW) == LOW ) {
    playerGuess[numButtonPresses] = LED_YELLOW;
    numButtonPresses++;
    flashLED(LED_YELLOW);
    //blockUntilRelease(BUTTON_YELLOW);
    Serial.println("BUTTON_YELLOW - 1 " + String(BUTTON_YELLOW));
    Serial.println("NUMBER OF PRESSES " + String(numButtonPresses));
  }
  else if( digitalRead(BUTTON_BLUE) == LOW ) {
    playerGuess[numButtonPresses] = LED_BLUE;
    numButtonPresses++;
    flashLED(LED_BLUE);
    //blockUntilRelease(BUTTON_BLUE);
    Serial.println("BUTTON_BLUE - 2 " + String(BUTTON_BLUE));
    Serial.println("NUMBER OF PRESSES " + String(numButtonPresses));
  }
  else if( digitalRead(BUTTON_GREEN) == LOW ) {
    playerGuess[numButtonPresses] = LED_GREEN;
    numButtonPresses++;
    flashLED(LED_GREEN);
    //blockUntilRelease(BUTTON_GREEN);
    Serial.println("BUTTON_GREEN - 3 " + String(BUTTON_GREEN));
    Serial.println("NUMBER OF PRESSES " + String(numButtonPresses));
  }
  else if( digitalRead(BUTTON_RED) == LOW ) {
    playerGuess[numButtonPresses] = LED_RED;
    numButtonPresses++;
    flashLED(LED_RED);
    //blockUntilRelease(BUTTON_RED);
    Serial.println("BUTTON_RED - 4 " + String(BUTTON_RED));
    Serial.println("NUMBER OF PRESSES " + String(numButtonPresses));
  }
   // darkLED();
}

void blockUntilRelease(int buttonNumber) {
  //while( digitalRead(buttonNumber) == HIGH )
    ;
}
// Compare the guess with the random sequence and return true if identical
bool verifyGuess() {
  bool identical = true;
  showLEDS();
  for(int i=0; i<difficultyLevel; i++) {
    if( playerGuess[i] != randomSequence[i] ) {
      identical = false;
      break;
    }
  }
  return identical;
}

void startFlash(){
  Serial.println("START"); 
   
    //darkLED();
  
      for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
              Serial.println("Start 1");
              
              strip.setBrightness(255);
              FastLED.setBrightness(255);
              strip.setPixelColor(p, 253, 64, 108);
              inner.setPixelColor(0, 253, 64, 108);
              pixel.setPixelColor(0, 253, 64, 108);
              showLEDS();
      }
      for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
              Serial.println("Start 2");
              
              strip.setBrightness(255);
              FastLED.setBrightness(255);
              strip.setPixelColor(p, 253, 0, 105);
              inner.setPixelColor(0, 253, 0, 105);
              pixel.setPixelColor(0, 253, 0, 105);
              showLEDS();
              delay(200);
              darkLED();
              showLEDS();
              delay(200);
      }
       
      delay(500);
      darkLED();
      
      delay(1000);
}

void failFlash(){
  Serial.println("FAILED");
  
  for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
              Serial.println("Fail 1");
              strip.setBrightness(255);
              FastLED.setBrightness(255);
              strip.setPixelColor(p, 255, 0, 0);
              inner.setPixelColor(0, 255, 0, 0);
              pixel.setPixelColor(0, 255, 0, 0);
              showLEDS();
              delay(100);
              darkLED();
              showLEDS();
              delay(100);
      }
   for(int p=2; p<strip.numPixels(); p--) { // For each pixel in strip...
              Serial.println("Fail 2");
              strip.setBrightness(255);
              FastLED.setBrightness(255);
              strip.setPixelColor(p, 255, 0, 0);
              inner.setPixelColor(0, 255, 0, 0);
              pixel.setPixelColor(0, 255, 0, 0);
              showLEDS();
              delay(100);
              darkLED();
              showLEDS();
              delay(100);
              Serial.println("Decrement: " + String(p));
              if (p == 0){
                break;
              }
      }
   
   delay(1000);
}

void correctFlash(){
  Serial.println("CORRECT");

      int count = 3;
      //showLEDS();
      while(count > 0 )                                   // repeat until count is no longer greater than zero
      {
        strip.setBrightness(255);
        FastLED.setBrightness(255);
        strip.setPixelColor(0, 0, 255, 0);
        strip.setPixelColor(1, 0, 255, 0);
        strip.setPixelColor(2, 0, 255, 0);
        inner.setPixelColor(0, 0, 255, 0);
        pixel.setPixelColor(0, 0, 255, 0);
        showLEDS();
        delay(200);
        
        darkLED();
        delay(100);
        count = count -1;                                  // decrement count 
       }

      delay(1000);
}

// Flash the LED on the given pin
void flashLED(int ledPinNum) {
  //digitalWrite(ledPinNum, HIGH);
  if (ledPinNum == 0){
    darkLED();
    
    digitalWrite(buttonPinUp, HIGH);
    strip.setBrightness(255);
    //FastLED.setBrightness(255);
    
    strip.setPixelColor(1, 0, 0, 0); // Blue LED pin
    strip.setPixelColor(2, 0, 0, 0); // Blue LED pin
    strip.setPixelColor(0, 0, 0, 255); // Blue LED pin
    //strip.setBrightness(255);
    inner.setPixelColor(0, 0, 0, 255);
    pixel.setPixelColor(0, 0, 0, 255);
    showLEDS();
    delay(500);
    //darkLED();
    Serial.println("FLASHING Pin 0 BLUE - " + String(ledPinNum));
  }
  else if (ledPinNum == 1){
    darkLED();
    
    digitalWrite(buttonPinUp, HIGH);
    strip.setBrightness(255);
    //FastLED.setBrightness(255);
    
    strip.setPixelColor(1, 0, 0, 0); // Blue LED pin
    strip.setPixelColor(2, 0, 0, 0); // Blue LED pin
    strip.setPixelColor(0, 0, 0, 255); // Blue LED pin
    //strip.setBrightness(255);
    inner.setPixelColor(0, 0, 0, 255);
    pixel.setPixelColor(0, 0, 0, 255);
    showLEDS();
    delay(500);
    //darkLED();
    Serial.println("FLASHING Pin 1 BLUE - " + String(ledPinNum));
  }
  else if (ledPinNum == 2){
    darkLED();
    
    digitalWrite(buttonPinDown, HIGH);
    strip.setBrightness(255);
    FastLED.setBrightness(255);
    
    strip.setPixelColor(0, 0, 0, 0); // Green LED pin
    strip.setPixelColor(1, 0, 0, 0); // Green LED pin
    strip.setPixelColor(2, 255, 44, 0); // Green LED pin
    inner.setPixelColor(0, 255, 44, 0);
    pixel.setPixelColor(0, 255, 44, 0);
    showLEDS();
    delay(500);
    //darkLED();
    Serial.println("FLASHING Pin 2 ORANGE - " + String(ledPinNum));
    
  }
  else if (ledPinNum == 3){
    darkLED();
    
    digitalWrite(buttonPinDown, HIGH);
    strip.setBrightness(255);
    FastLED.setBrightness(255);
    
    strip.setPixelColor(0, 0, 0, 0); // Green LED pin
    strip.setPixelColor(1, 0, 0, 0); // Green LED pin
    strip.setPixelColor(2, 255, 44, 0); // Green LED pin
    inner.setPixelColor(0, 255, 44, 0);
    pixel.setPixelColor(0, 255, 44, 0);
    showLEDS();
    delay(500);
    //darkLED();
    Serial.println("FLASHING Pin 3 ORANGE - " + String(ledPinNum));
  }
  else;
  //showLEDS();
  delay(500);
  darkLED();
  delay(100);
}

void darkLED(){
  //Serial.println("Setting Dark");
  
  strip.setBrightness(0);
  FastLED.setBrightness(0);
               
  pixel.setPixelColor(0, 0, 0, 0);
  inner.setPixelColor(0, 0, 0, 0);
  strip.setPixelColor(0, 0, 0, 0);
  strip.setPixelColor(1, 0, 0, 0);
  strip.setPixelColor(2, 0, 0, 0);
  //strip.setBrightness(0);*/
  showLEDS();
  
}
// Get a random LED pin number
int rndLEDPin() {
  return random(LED_YELLOW, LED_RED + 1);
  
}
