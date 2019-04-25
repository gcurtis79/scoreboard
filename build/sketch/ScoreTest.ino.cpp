#include <Arduino.h>
#line 1 "/home/gcurtis79/Arduino/ScoreTest/ScoreTest.ino"
#line 1 "/home/gcurtis79/Arduino/ScoreTest/ScoreTest.ino"
#include "MyFunk.h"
#include "Scores.h"
//#include "GameClock.h"
#include "Timers.h"

#line 6 "/home/gcurtis79/Arduino/ScoreTest/ScoreTest.ino"
void setup();
#line 18 "/home/gcurtis79/Arduino/ScoreTest/ScoreTest.ino"
void loop();
#line 6 "/home/gcurtis79/Arduino/ScoreTest/ScoreTest.ino"
void setup()
{
  Serial.begin(9600);
  setTime(0);
  mcpInit();
  scanConnect();

  ArduinoOTA.setHostname("ScoreBoard");
  ArduinoOTA.begin();
  startTimers();
}

void loop() {
  ArduinoOTA.handle();
  updateTimers();
}

