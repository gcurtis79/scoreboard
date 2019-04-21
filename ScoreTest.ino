//#include "MyFunk.h"
#include "Scores.h"
#include "GameClock.h"
#include "Timers.h"

void setup()
{
  //Serial.begin(115200);
  //setTime(0);
  mcpInit();
  //scanConnect();

  //ArduinoOTA.setHostname("ScoreBoard");
  //ArduinoOTA.begin();
  clockInit();
  startTimers();
}

void loop() {
  //ArduinoOTA.handle();
  updateTimers();
  //showScores();
  clockLoop();
  if (digitalRead(2) == LOW && !homeScoring)homeScored();
  if (digitalRead(3) == LOW && !awayScoring)awayScored();
}
