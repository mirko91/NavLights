// Beacon function can be either a fade or ON/OFF
#define FADE // define to make the beacon fade, undefine (//) to make it blink
//#define DEBUG1 // uncomment to activate debug

unsigned long oldTime1 = 0;
byte value = 0;
#ifndef FADE
boolean temp = 0;
#endif

#ifndef FADE
void beacon() {
  if (millis() - oldTime1 >= beaconPause) {
    oldTime1 = millis();
    if (temp == 0) {
      analogWrite(beaconPin, OFF);
    }
    else {
      analogWrite(beaconPin, beaconPWM);
    }
    temp = !temp;
  }
}
#endif


#ifdef FADE
void beacon() {
  value = beaconPWM + beaconPWM * cos(2 * PI / beaconPause * millis());
  analogWrite(beaconPin, value);

#ifdef DEBUG1
  Serial.println(value);
#endif
}
#endif















