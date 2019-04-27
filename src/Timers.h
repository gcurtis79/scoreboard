void updateTimers() {
  showScore.Update();
  clockTime.Update();
}

void timersInit() {
  DEBUG_PRINT("Timers Init");
  showScore.Every(10, showScores);
  clockTime.Every(250, Timing);
}
