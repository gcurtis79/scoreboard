#include <EveryTimer.h>
#include <TimeLib.h>

EveryTimer showScore;
EveryTimer countUp;
EveryTimer clockTime;

void updateTimers() {
  showScore.Update();
  countUp.Update();
  clockTime.Update();
}

void startTimers() {
  showScore.Every(10, showScores);
  countUp.Every(250, doCount);
  //clockTime.Every(1000, clockStep);
}
