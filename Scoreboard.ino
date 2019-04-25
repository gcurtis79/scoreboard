#include "src/Config.h"
#include "src/GameModes.h"
#include "src/Sound.h"
#include "src/Scores.h"
#include "src/TimeClock.h"
#include "src/Timers.h"

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
}
