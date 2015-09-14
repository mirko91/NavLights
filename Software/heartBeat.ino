#define pause 200
#define ledOn 20

unsigned long timeNow2 = 0;
unsigned long oldTime2 = 0;
byte stateHB = 0;

void heartBeat() {
  timeNow2 = millis();

  if ((timeNow2 - oldTime2 >= pause) && (stateHB == 0)) {
    oldTime2 = timeNow2;
    digitalWrite(led, HIGH);
    stateHB = 1;
  }

  if ((timeNow2 - oldTime2 >= ledOn) && (stateHB == 1)) {
    oldTime2 = timeNow2;
    digitalWrite(led, LOW);
    stateHB = 0;
  }
}
