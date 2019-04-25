#include "Config.h"
#include "Sound.h"
#include "Scores.h"
#include "GameClock.h"
#include "Timers.h"

void setup() {
  #ifdef SERIAL_DEBUG
  Serial.begin(SERIAL_DEBUG);
  delay(1000);
  DEBUG_PRINT("Startup");
  #endif
  soundInit();
  scoreInit();
  clockInit();
  startTimers();
  DEBUG_PRINT("Init Done");
}

void loop() {
  updateTimers();
  clockLoop();
  if (digitalRead(2) == LOW && !homeScoring)homeScored();
  if (digitalRead(3) == LOW && !awayScoring)awayScored();
}
