#include <Arduino.h>
#include <TM1637.h>
#include <TimeLib.h>

tm1637 display(D5, D6);
bool colon = false;

void clockInit() {
  Serial.println("GameClock Init");
  display.setBrightness(4);
}

void clockStep() {
  display.writeTime(minute(), second(), colon);
  !colon;
}
