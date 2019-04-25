#include <Arduino.h>
#line 1 "d:\\Arduino\\scoreboard\\Scoreboard.ino"
#line 1 "d:\\Arduino\\scoreboard\\Scoreboard.ino"
//#include <Arduino.h>
#include "src/Config.h"
#include "src/GameModes.h"
#include "src/Sound.h"
#include "src/Scores.h"
#include "src/TimeClock.h"
#include "src/Timers.h"

#line 9 "d:\\Arduino\\scoreboard\\Scoreboard.ino"
void setup();
#line 22 "d:\\Arduino\\scoreboard\\Scoreboard.ino"
void loop();
#line 9 "d:\\Arduino\\scoreboard\\Scoreboard.ino"
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

