

//uint8_t k_noteOn = 0x90;
//uint8_t k_noteOff = 0x80;
//uint8_t k_channelMode = 0xb0;
//uint8_t k_allNotesOff = 0x7b;
// Check signature at address 0
int UpPress = 1;
int DownPress = 1;

uint8_t k_noteOn = 1;
uint8_t k_noteOff = 0;

//SoftwareSerial midiSerial(3, 2); // RX, TX
//HardwareSerial &midiSerial = Serial;

//Bounce buttonNote(9);
//Bounce buttonRecord(6);

// Create a structure that is big enough to contain a Stuff

// Create a "savedData" variable and call it "dataz"
  savedData pressedButtons;

byte storedUpPresses[6];
byte storedDownPresses[6];

struct savedButtonPress
{
  savedButtonPress(){}
  savedButtonPress(uint8_t b0, uint8_t b1)
  {
    bytes[0] = b0;
    bytes[1] = b1;
  }
  uint8_t bytes[2]; // ButtonUp, ButtonDown
};


struct MidiMsg
{
  MidiMsg(){}
  MidiMsg(uint8_t b0, uint8_t b1, uint8_t b2)
  {
    bytes[0] = b0;
    bytes[1] = b1;
    bytes[2] = b2;
  }
  uint8_t bytes[3]; // cmd, note, velocity
};

struct SeqItem
{
  uint16_t time;
  savedButtonPress msg;
};

struct Sequence
{
  const static uint16_t max_size = 255;
  SeqItem seq[max_size];
  uint16_t size = 0;
  uint16_t pos = 0;
  uint32_t begin = 0;
  uint32_t end = 0;
} seq;

bool is_recording = false;

uint32_t now = 0;

/*struct NoteOnInfo
{
  uint8_t ref_count;
  uint8_t note;
  uint8_t channel;
  uint8_t velocity;
};*/

struct NoteOnInfo
{
  uint8_t ref_count;
  uint8_t note;
  //uint8_t channel;
  //uint8_t velocity;
};

const static uint8_t max_note_ons = 100;
NoteOnInfo note_ons[max_note_ons];
bool error = false;

bool store_note_on(uint8_t note)
{
  // Find if the note is already playing
  /*for(uint8_t i = 0; i < max_note_ons;++i)
  {
    if(note_ons[i].ref_count > 0 && note_ons[i].note == note)
    {
      //note_ons[i].velocity = max(velocity, note_ons[i].velocity);
      ++note_ons[i].ref_count;
      return true;
    }
  }*/
  // Find a slot for the note
  for(uint8_t i = 0; i < max_note_ons;++i)
  {
    if(note_ons[i].ref_count == 0)
    {
      note_ons[i].note = note;
      
      //note_ons[i].channel = channel;
      //note_ons[i].velocity = velocity;
      note_ons[i].ref_count = 1;
      return false;
    }
  }
  for (byte i = 0; i < 5; i = i + 1) {
        Serial.println(note_ons[i].note);
      }

  error = true;
  return false;
}

bool store_note_off(uint8_t note)
{
  // Find if the note is already playing
  for(uint8_t i = 0; i < max_note_ons;++i)
  {
    if(note_ons[i].ref_count > 0 && note_ons[i].note == note)
    {
      --note_ons[i].ref_count;
      return note_ons[i].ref_count > 0;
    }
  }

  error = true;
  return false;
}

void writeDataz(uint8_t note)
  {
    valueA0 = map(analogRead(A0), 0, 1024, 0, 255);
    note = valueA0;
    
    
  }

/*
void midi_out(uint8_t cmd, uint8_t note, uint8_t velocity)
{
  uint8_t type = cmd & 0xF0;
  uint8_t channel = cmd & 0x0F;
  if(type == k_noteOn)
  {
    // Don't send note off if already playing
    if(store_note_on(note, channel, velocity))
      return;
  }
  else if(type == k_noteOff)
  {
    // Don't send note off when ref count > 0
    if(store_note_off(note, channel))
      return;
  }

  midiSerial.write(cmd);
  midiSerial.write(note);
  midiSerial.write(velocity);
}

void midi_out(uint8_t cmd, uint8_t channel, uint8_t note, uint8_t velocity)
{
  midi_out(cmd+channel,note, velocity);
}
/*
void midi_out(const struct MidiMsg& msg)
{
  midi_out(msg.bytes[0], msg.bytes[1], msg.bytes[2]);
}


void midi_out(uint8_t note)
{

  buttonValDown = digitalRead(buttonPinDown);
  checkButtons();
  // Button pressed down
    if (buttonValDown == LOW && buttonLastDown == HIGH && (millis() - upTime) > debounce)
    {
      // Don't send note off if already playing
      if(store_note_on(note))
      return;
      Serial.println("Store Note On " + (note));
    }
    
    // Button released
    else if (buttonValDown == HIGH && buttonLastDown == LOW && (millis() - downTime) > debounce)
      {
      if (not ignoreUpDown)
        {
          upTime = millis();
          if (DConUpDown == false) DCwaitingDown = true;
          else
        {
          // Don't send note off when ref count > 0
      if(store_note_off(0))
      return;
      Serial.println("Store Note Off " + (note));
        }
      }
      }


  //savedButtonPress.write(note);
}

/*void midi_out(uint8_t ref_count, uint8_t note)
{
  //midi_out(ref_count, note);                  // -???????????????????
  Serial.println("MIDI out ref_count " + String(ref_count));
  Serial.println("MIDI out note " + String(note));
}

void midi_out(const struct savedButtonPress& msg)
{
  //midi_out(msg.bytes[0], msg.bytes[1]);       // -???????????????????
  //Serial.println("MIDI Out 2 ");
  //Serial.println("MIDI out Message Bytes");
  //Serial.println("MIDI out msg " + String(msg));
}
*/


void add_msg_to_seq(const struct savedButtonPress& msg)
{
  if (seq.size < seq.max_size)
  {
    SeqItem &item = seq.seq[seq.size++];
    item.time = now - seq.begin;
    item.msg = msg;
    return;
  }

  bool error = true;
}

void record_in(const struct savedButtonPress& msg)
{
  uint8_t type = msg.bytes[0];
  if(type!= k_noteOn && type!= k_noteOff)
    return;

  if (is_recording)
  {
    valueA0 = map(analogRead(A0), 0, 1024, 0, 255);
    type = valueA0;
    add_msg_to_seq(msg);
    //Serial.println("Record In Add MSG to SEQ");
    Serial.println("Record In MSG = " + String(type));
  }
}

void start_recording()
{
  // Start recording
  seq.size = 0;
  seq.begin = now;

  // Search for note-on, and set them ON in the seq
  for(uint8_t i = 0; i < max_note_ons;++i)
  {
    if(note_ons[i].ref_count > 0)
    {
      //add_msg_to_seq(MidiMsg(k_noteOn+note_ons[i].channel, note_ons[i].note, note_ons[i].velocity));
    
      //ERROR no matching function                              FIX THIS
      //add_msg_to_seq(savedButtonPress(note_ons[i].note));
      Serial.println("Start Recording Add MSG to SEQ");
    }
  } 
}

void stop_recording()
{
  // Search for note-on, and set them OFF in the seq
  for(uint8_t i = 0; i < max_note_ons;++i)
  {
    if(note_ons[i].ref_count > 0)
    {
      //ERROR no matching function
      //add_msg_to_seq(savedButtonPress(note_ons[i].note));
      Serial.println("Stop Recording Add MSG to SEQ");
    }
  }

  // Stop recording
  seq.end = now;
  seq.pos = 0;
}

void handle_seq()
{
  //buttonNote.Update();
  //buttonRecord.Update();

  // CHECK BUTTONS HERE

  checkButtons();
    
  //if (buttonRecord.IsLongPressed()) - FIX THESE IFS W/ Button Presses
  if (pressedTapzDown == true)
  {
    if(seq.size > 0 && seq.pos > 0)
      notes_off();
    stop_recording();
    is_recording = false;
    Serial.println("Stop Recording ");
  }
  //else if (buttonRecord.changed && buttonRecord.IsPressed())  - FIX THESE IFS W/ Button Presses
  else if (pressedTapzUp == true)
  {
    is_recording = is_recording;
    if(is_recording)
    {
      if(seq.size > 0 && seq.pos > 0)
        notes_off();

      start_recording();
      Serial.println("Start Recording ");
    }
    else
    { 
      is_recording = !is_recording;
      stop_recording();
      Serial.println("Stop Recording ");
      
    }
    
  }

  pressedTapzUp = false;
  pressedTapzDown = false;
  read_input();

  if (!is_recording)
  {
    if (seq.pos < seq.size && seq.pos < seq.max_size)
    {
      uint32_t time_in_seq = (now - seq.end) % (seq.end - seq.begin);
      SeqItem &next_item = seq.seq[seq.pos];
      if (abs(next_item.time - time_in_seq) < 2)
      {
        //midi_out(next_item.msg);
        ++seq.pos;
        if (seq.pos == seq.size)
          seq.pos = 0;
        
      }
    }
    //Serial.println("seq_pos " + String(seq.pos)); 
    ///for (byte i = 0; i < 5; i = i + 1) {
    //    Serial.println(note_ons[i].note);
    //  } 
    for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
              strip.setPixelColor(p, seq.pos, seq.pos, seq.pos);
            }
    pixel.setPixelColor(0, seq.pos, seq.pos, seq.pos); 
            inner.setPixelColor(0, seq.pos,seq.pos,seq.pos); 
            
            strip.show();
            pixel.show();
            inner.show();        
  }
  //delay(1);
}

uint32_t last_msg = 0;

void read_input()
{ 


  savedButtonPress msg;
  msg.bytes[0] = 1;
  msg.bytes[1] = valueA0;

  //midi_out(msg);
  
  record_in(msg);
  last_msg = now;
  
  /*while (midiSerial.available() > 2)
  {
    MidiMsg msg;
    msg.bytes[0] = midiSerial.read();
    msg.bytes[1] = midiSerial.read();
    msg.bytes[2] = midiSerial.read();

    // Midi thru
    midi_out(msg);

    record_in(msg);
    last_msg = now;
    
    // Serial.print("midi received:");
    // Serial.print(commandByte,16);
    // Serial.print(noteByte,16);
    // Serial.print(velocityByte,16);
    // Serial.print("\n");
  }*/
}

void notes_off()
{
  // init all note off
  for(uint8_t c=0; c < 16; ++c)
  {
    for(uint8_t i = 0; i < max_note_ons;++i)
    {
      note_ons[i].ref_count = 0;
    }

    //midi_out(c, 0);
  }
}

void tapzStart(){

  notes_off();

  // flash leds
      for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
              strip.setPixelColor(p, 253, 64, 108);
              inner.setPixelColor(0, 253, 64, 108);
              pixel.setPixelColor(0, 253, 64, 108);
              inner.show();
              pixel.show();
              strip.show();
      }
      for(int p=0; p<strip.numPixels(); p++) { // For each pixel in strip...
              strip.setPixelColor(p, 253, 0, 105);
              strip.show();
              inner.setPixelColor(0, 253, 0, 105);
              pixel.setPixelColor(0, 253, 0, 105);
              inner.show();
              pixel.show();
              delay(200);
              strip.setPixelColor(p, 0, 0, 0);
              strip.show();
              inner.setPixelColor(0, 0, 0, 0);
              pixel.setPixelColor(0, 0, 0, 0);
              inner.show();
              pixel.show();
              delay(200);
      }
      initial = false;
}


void tapzRecorder()
{
  //Serial.println("Tapz Looping ");
  if (initial == true) {
    tapzStart();
  }
  else;
    
  now = millis();

  handle_seq();

  //if (buttonValUp == 0){
    // 0 is not pressed 
    // 1 is pressed
    //Serial.println("Tapz Looping ");
  //}

  //digitalWrite(13, now - last_msg < 20 ? HIGH : LOW);
  //digitalWrite(10, error ? HIGH : LOW);
  //digitalWrite(11, is_recording ? HIGH : LOW);

  //Serial.println("Tapz Looping " + String(fadeSpeed));
  
}






/////////////////

// OLD VERSION BELOW

////////////////

/*
int upPressed[];
int downPressed[];
int upPressedTimeOn[];
int downPressedTomeOn[];
int upPressedTimeOff[];
int downPressedTomeOff[];





int arr[10];
boolean previous = LOW;
unsigned long time1 = 0;
//int debounce = 200;
int index_state = 0;

int button[2] = {9,10};
int leds[3] = {0,1,2};

int play_led = 2;
int play_button=10;

int record_led = 0;
int record_button=9;
int record_count = 0;
int state = HIGH;

bool full = false;


void tapzRecorder(){

checkButtons();

//Serial.println("TapzRecorder");
//blink_record(2); 
playback();
//show_array();
play_record(); 

  
}

void pressedPlay(){

  Serial.println("Fuction: Pressed Play");
  
}

void pressedRecord(){
  Serial.println("Fuction: Pressed Record");
}
/*
 * Record & Play Button Presses Template
 * "records" button presses and plays them back sequentially using LEDs.
 * Requires 6X buttons and 6X LED's 4X 
 * Full tutorial available on
 * on www.learnrobotics.org/blog
 * 
 * February 20, 2019
 * Liz Miller
 *
 */


/*
void setup()
{
   for(int i = 0;i<5 ;i++){
    pinMode(button[i],INPUT);
    pinMode(leds[i],OUTPUT);
    }
   for(int n=0;n<10;n++) arr[n] = 7;//initialization
   pinMode(record_led, OUTPUT);
   pinMode(play_led, OUTPUT);
   digitalWrite(play_led,HIGH);
   empty=true;
   Serial.begin(9600);
}

void blink_record(int repeat){
  for(int i=0; i<repeat; i++){
              strip.setPixelColor(record_led, 255, 0, 0);
              strip.show();
              inner.setPixelColor(0, 0, 0, 0);
              pixel.setPixelColor(0, 0, 0, 0);
              inner.show();
              pixel.show();
              delay(100);
              strip.setPixelColor(record_led, 0, 0, 0);
              strip.show();
              inner.setPixelColor(0, 0, 0, 0);
              pixel.setPixelColor(0, 0, 0, 0);
              inner.show();
              pixel.show();
              delay(100);
  }
}

/*
 * Shuts off 4 LED's
 * Sequence array is NOT empty

void all_off(){
  for(int i=0;i<5;i++){
    //digitalWrite(leds[i],LOW);
              strip.setPixelColor(leds[i], 0, 0, 0);
              strip.show();
              inner.setPixelColor(0, 0, 0, 0);
              pixel.setPixelColor(0, 0, 0, 0);
              inner.show();
              pixel.show();
  }
  empty=false;
}

/*
 * Prints out the sequence array to Serial

void show_array(){
   for (int i = 0; i<10; i++){
    Serial.print(arr[i]);
  }
  Serial.println();
}

/*
 * Erases the sequence array by filling with arbitrary number we'll never use
 * Sequence array is empty

void erase_stored(){
  for(int n=0;n<10;n++) arr[n] = 7; //random number we'll never use
  empty=true;
}

/*
 * Plays back the sequence routine when triggered
 * Erases the sequence array upon completion
 * 
void playback(){
  //digitalWrite(play_led,HIGH);
  strip.setPixelColor(play_led, 0, 255, 0);
  //digitalWrite(record_led,LOW);
  strip.setPixelColor(record_led, 0, 0, 0);
  strip.show();
  
    for(int i = 0; i<10; i++){
      if (arr[i]!=7){
        //digitalWrite(leds[arr[i]],HIGH);
        //delay(250);
        //digitalWrite(leds[arr[i]],LOW);
        //delay(250);
          
              strip.setPixelColor(leds[arr[i]], 255, 255, 0);
              strip.show();
              inner.setPixelColor(0, 0, 0, 0);
              pixel.setPixelColor(0, 0, 0, 0);
              inner.show();
              pixel.show();
              delay(250);
              strip.setPixelColor(leds[arr[i]], 0, 0, 0);
              strip.show();
              inner.setPixelColor(0, 0, 0, 0);
              pixel.setPixelColor(0, 0, 0, 0);
              inner.show();
              pixel.show();
              delay(250);
    }
  }
  //digitalWrite(play_led,LOW);
  strip.setPixelColor(play_led, 0, 0, 0);
  strip.show();
  
  erase_stored(); //erases array for the next time
  delay(1000);
  //digitalWrite(play_led,HIGH);
  strip.setPixelColor(play_led, 0, 255, 0);
  strip.show();
  
  show_array();
  index_state=-1;
}

/*
 * Records and plays back a sequence using button presses
 * Record button must be triggered to record a sequence
 * Play button triggers the playback
 
void play_record(){
  //boolean mode = digitalRead(button[0]) || digitalRead(button[1]) || digitalRead(button[2]) || digitalRead(button[3]) || digitalRead(record_button) || digitalRead(play_button);
  boolean mode = digitalRead(button[0]) || digitalRead(button[1]) || digitalRead(record_button) || digitalRead(play_button);

  
  //wait here till one of the pushbutton goes high;
  while(mode == LOW && record_count <= 1){
    
    mode = digitalRead(button[0]) || digitalRead(button[1]) || digitalRead(record_button) || digitalRead(play_button);
    if( mode == HIGH && previous == LOW && millis() - time1 > debounce){

  //find out which one is high and store that value in array;

  /*
   * EXAMPLE CASE for single button.
   * Add additional readings to check additional buttons
   
    if(digitalRead(button[0]) && record_count ==1) {
      arr[index_state] = 0; //set the button 0 to the current index
      //digitalWrite(leds[0],HIGH); //turn on the respective LED
              strip.setPixelColor(leds[0], 255, 255, 0);
              strip.show();
              inner.setPixelColor(0, 0, 0, 0);
              pixel.setPixelColor(0, 0, 0, 0);
              inner.show();
              pixel.show();
              
      delay(50); //briefly turn on LED to show which button was pressed
      all_off(); //make sure all LEDs are OFF
    }
    
    //**** add your button conditions here ****
    
    
    else;
    
    //print the value and the index;
    Serial.print(arr[index_state]);
    Serial.print(" Stored in index: ");
    Serial.println(index_state);

    /*
     * once we reach an index of 9 we need to reset the 
     * index so that we don't overflow the sequence array
     
    if(index_state < 9){
      index_state = (index_state + 1);
    }
    
    else{ //wait for PLAY PRESS?
      all_off();
      blink_record(5); //optionally blink the record LED
      index_state = 0; //reset
    }
      
    state = !state;
    //update value of time1 for button debouncing
    time1 =  millis();
    }
  }
}

*/
//void loop(){
//  play_record();  
//}
