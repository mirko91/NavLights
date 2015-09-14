// RC signal computing function, interrupt driven to be fast and efficient without
// wasting CPU cycles or create excessive jitter

void readRc() {
  if (digitalRead(rcPin) == HIGH) {
    timer = micros();
  }
  else
  {
    rcPulse = micros() - timer;
  }
}
