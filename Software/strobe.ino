unsigned long oldTime = 0;
unsigned long timeNow = 0;
byte state = 0;

// OLD LEGACY DOUBLE BLINK
/*
void strobe() {

 if(millis() - oldTime >= strobeOff) {
 oldTime = millis();
 analogWrite(strobePin, strobePWM);
 delay(strobeOn);
 analogWrite(strobePin, OFF);
 delay(dblinkPause);
 analogWrite(strobePin, strobePWM);
 delay(strobeOn);
 analogWrite(strobePin, OFF);
 }
 }
 */
void strobe() {
  timeNow = millis();

  if ((timeNow - oldTime >= strobeOff) && (state == 0)) {
    oldTime = timeNow;
    analogWrite(strobePin, strobePWM);
    state = 1;
  }

  if ((timeNow - oldTime >= strobeOn) && (state == 1)) {
    oldTime = timeNow;
    analogWrite(strobePin, OFF);
    state = 2;
  }
  if ((timeNow - oldTime >= dblinkPause) && (state == 2)) {
    oldTime = timeNow;
    analogWrite(strobePin, strobePWM);
    state = 3;
  }
  if ((timeNow - oldTime >= strobeOn) && (state == 3)) {
    oldTime = timeNow;
    analogWrite(strobePin, OFF);
    state = 0;
  }
}


