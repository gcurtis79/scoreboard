#include <EveryTimer.h>
//#include <TimeLib.h>

EveryTimer showScore;
//EveryTimer scoReset;
//EveryTimer countUp;
EveryTimer clockTime;

void updateTimers() {
  showScore.Update();
  //scoReset.Update();
  //countUp.Update();
  clockTime.Update();
}

void startTimers() {
  showScore.Every(10, showScores);
  //scoReset.Every(500, _scoReset);
  //countUp.Every(250, doCount);
  clockTime.Every(500, Timing);
}
