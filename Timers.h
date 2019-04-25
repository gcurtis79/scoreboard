#include <EveryTimer.h>
#include <OneShotTimer.h>

EveryTimer showScore;
EveryTimer clockTime;

void updateTimers() {
  showScore.Update();
  clockTime.Update();
}

void startTimers() {
  DEBUG_PRINT("Timers Init");
  showScore.Every(10, showScores);
  clockTime.Every(500, Timing);
}
