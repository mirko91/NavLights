// NavLights - Developed and hand-built in Italy by Mirko Malisan

//#define DEBUG // uncomment to activate debug

#include "config.h" // include config file
byte mode = 0;
unsigned long timer = 0;
volatile unsigned int rcPulse = 0;

void setup() {
  pinMode(strobePin, OUTPUT);
  pinMode(landPin, OUTPUT);
  pinMode(navPin, OUTPUT);
  pinMode(beaconPin, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(rcPin, INPUT);
  attachInterrupt(0, readRc, CHANGE); // interrupt

  for (byte x = 0; x < 4; x++) {
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    delay(100);
  }

#ifdef DEBUG
  Serial.begin(9600);
#endif
}

void loop() {

  heartBeat();

#ifdef DEBUG
  Serial.println(rcPulse);
#endif

  if (rcPulse < offCtrl) {
    mode = 0;
  }
  else if (rcPulse > landCtrl) {
    mode = 2;
  }
  else {
    mode = 1; //mode 2 di default #############CAMBIARE IN MODE 1#############
  }

  switch (mode) {
    case 0:
      analogWrite(strobePin, OFF);
      analogWrite(landPin, OFF);
      analogWrite(navPin, OFF);
      analogWrite(beaconPin, OFF);
      break;

    case 1:
      strobe();
      beacon();
      analogWrite(navPin, navPWM);
      analogWrite(landPin, OFF);
      break;

    case 2:
      strobe();
      beacon();
      analogWrite(navPin, navPWM);
      analogWrite(landPin, landPWM);
      break;
  }


}




