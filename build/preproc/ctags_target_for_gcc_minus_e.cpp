# 1 "/home/gcurtis79/Arduino/ScoreTest/ScoreTest.ino"
# 1 "/home/gcurtis79/Arduino/ScoreTest/ScoreTest.ino"
# 2 "/home/gcurtis79/Arduino/ScoreTest/ScoreTest.ino" 2
# 3 "/home/gcurtis79/Arduino/ScoreTest/ScoreTest.ino" 2
//#include "GameClock.h"
# 5 "/home/gcurtis79/Arduino/ScoreTest/ScoreTest.ino" 2

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
