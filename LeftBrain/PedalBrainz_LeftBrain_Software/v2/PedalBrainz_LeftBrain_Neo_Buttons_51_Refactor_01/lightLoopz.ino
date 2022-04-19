


int seqCount[255];
//int seqValue[255];
int seqValue[] = {
                  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255,
                  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255,
                  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255,
                  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255,
                  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255,
                  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255,
                  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255,
                 };     
int lastCount = 255;
int seqSpeed;
int maxCount = 255;

byte i = 0;

bool recording = false;
bool playback = true;
bool playbackInitial = true;

unsigned long currentMillis;
int checkMillis = 50;  //the value is a number of milliseconds

bool printLoopz = false;

void lightLoopz() {

  //  If it's the first startup, set the light colors differently 
  //  Serial.println("Tapz Looping ");
  if (initial == true) 
  {
    startLights();
  }
  else;

  //lastMillis;
  //  This is where the main loopz sequence is started from
  sequencez();  

}

  
void sequencez() {    //  This is the main loopz sequence

  checkButtons();

  if (pressedTapzUp == true)
  {

    //Serial.println(i);

    //recording = recording;
    if (!recording)
    {
      playbackInitial = false;
      recording = true;

      playback = false;


      i = 0;

      Serial.println("Start Recording ");

    }
    else
    {
      //recording = recording;
      recording = false;
      record_stop();
      playback = true;

      i = 0;

      //maxCount = lastCount;

      Serial.println(i);
      Serial.println("Last Count " + String(lastCount));
      Serial.println("Stop Recording ");
    }

    if (pressedTapzDown == true)
    {
    //maxCount = 30;
    //Serial.println("Max Count 30 ");
    }


  }

  if (playback == true) {
    play_sequence();
  }
  else if (playback == false) {
    record_sequence();
  }
  else;

  pressedTapzUp = false;
  pressedTapzDown = false;

  //Serial.println("Time " + (now));
}

void play_sequence() {    //  This is the loop when the sequence is playing back

  //Serial.println("Recording Sequence ");

  //  A1 sets the maximum brightness of the potentiometer LEDs
  maxBrightness = map(analogRead(A1), 0, 1024, 10, maxBrightnessTemp);
  MaxBrightReduction = constrain(maxBrightness, 0, MaxBright);
  pixel.setBrightness(maxBrightness);
  strip.setBrightness(MaxBrightReduction);
  inner.setBrightness(maxBrightness);


  currentMillis = millis();  //get the current "time" (actually the number of milliseconds since the program started)
  if (currentMillis - startMillis >= checkMillis)  //test whether the period has elapsed
  {
    startMillis = currentMillis;  //IMPORTANT to save the start time of the current LED state.

    checkMillis = map(analogRead(A0), 0, 1024, 200, 10);

    if (i <= lastCount) {
      if (printLoopz == true)
      {
        Serial.println("Play Seq Count " + String(seqCount[i]));
      }
      else;

      i = i + 1;
      lastCount = i;
      seqCount[i] = i;
      //maxCount = lastCount+1;

      if (printLoopz == true)
      {
        Serial.println("Play Last Count " + String(lastCount));
        Serial.println("Play Max Count " + String(maxCount));
      }
      else;


      if (playbackInitial) {

        for (int p = 0; p < strip.numPixels(); p++) { // For each pixel in strip...
          strip.setPixelColor(0, 66, 0, 255);
          strip.setPixelColor(1, seqValue[i], 0, seqValue[i] / 2);
          strip.setPixelColor(2, seqValue[i], seqValue[i] / 2, 0);
          inner.setPixelColor(0, seqValue[i], seqValue[i] / 2, 0);
          pixel.setPixelColor(0, seqValue[i], seqValue[i] / 2, 0);
          inner.show();
          pixel.show();
          strip.show();
        }

        if (printLoopz == true)
        {
          Serial.println("Play Seq Value " + String(seqValue[i]));
        }
        else;


      }
      else if (!playbackInitial) {
        for (int p = 0; p < strip.numPixels(); p++) { // For each pixel in strip...
          strip.setPixelColor(0, 66, 0, 255);
          strip.setPixelColor(1, 0, 255, 0);
          strip.setPixelColor(2, 0, seqValue[i], 0);
          inner.setPixelColor(0, 0, seqValue[i], seqValue[i] / 8);
          pixel.setPixelColor(0, 0, seqValue[i], seqValue[i] / 8);
          inner.show();
          pixel.show();
          strip.show();
        }

        if (printLoopz == true)
        {
          Serial.println("Play Seq Value " + String(seqValue[i]));
        }
        else;

      }
      else;
    }


    if (i == maxCount) {
      i = 0;
      Serial.println("i was == to maxCount");
    }
    else;

    //for (byte i = 0; i < lastCount; i = i + 1) {
    //    Serial.println(seqValue[i]);
    //}

    //Serial.println("A thing "+ String(currentMillis));
  }
  else;


}

void record_sequence() {    //  This is the loop when the sequence is recording

  //Serial.println("Recording Sequence ");
  maxBrightness = map(analogRead(A1), 0, 1024, 10, maxBrightnessTemp);
  MaxBrightReduction = constrain(maxBrightness, 0, MaxBright);
  pixel.setBrightness(maxBrightness);
  strip.setBrightness(MaxBrightReduction);
  inner.setBrightness(maxBrightness);

  checkMillis = 50;

  currentMillis = millis();  //get the current "time" (actually the number of milliseconds since the program started)
  if (currentMillis - startMillis >= checkMillis)  //test whether the period has elapsed
  {
    startMillis = currentMillis;  //IMPORTANT to save the start time of the current LED state.

    if (i <= lastCount) {
      if (printLoopz == true)
      {
        Serial.println("Record Seq Count " + String(seqCount[i]));
      }
      else;

      i = i + 1;
      lastCount = i;
      seqCount[i] = i;
      maxCount = lastCount + 1;

      checkButtons();
      if (buttonValDown == LOW)
      {
        seqValue[i] = 255;

        if (printLoopz == true)
        {
          Serial.println("Down Button is Down " + String(seqValue[i]));
        }
        else;

      }
      else {
        valueA0 = map(analogRead(A2), 0, 1024, 0, 255);
        seqValue[i] = valueA0;
      }

      if (printLoopz == true)
      {
        Serial.println("Record Last Count " + String(lastCount));
        Serial.println("Record Max Count " + String(maxCount));
        Serial.println("Record Seq Value " + String(seqValue[i]));
      }
      else;


      for (int p = 0; p < strip.numPixels(); p++) { // For each pixel in strip...
        strip.setPixelColor(0, 66, 0, 255);
        strip.setPixelColor(1, 255, 0, 0);
        strip.setPixelColor(2, seqValue[i], 0, 0);
        inner.setPixelColor(0, seqValue[i], 0, 0);
        pixel.setPixelColor(0, seqValue[i], 0, 0);
        inner.show();
        pixel.show();
        strip.show();
      }

    }
    else;

    if (i == maxCount) {
      i = 0;
      Serial.println("i was == to maxCount");
    }
    else;

  }
}

void record_stop() {
  Serial.println("Stopping Sequence Recording");

}

void sequence_speed() {

}

void sequence_store() {

}

void sequence_value() {

}

void array_read() {
  Serial.println("Reading Sequence to Array");
}

void array_write() {
  Serial.println("Writing Sequence to Array");
}

void startLights() {

  // flash leds in a unique color scheme at startup
  for (int p = 0; p < strip.numPixels(); p++) { // For each pixel in strip...
    strip.setPixelColor(p, 253, 64, 108);
    inner.setPixelColor(0, 253, 64, 108);
    pixel.setPixelColor(0, 253, 64, 108);
    inner.show();
    pixel.show();
    strip.show();
  }
  for (int p = 0; p < strip.numPixels(); p++) { // For each pixel in strip...
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



