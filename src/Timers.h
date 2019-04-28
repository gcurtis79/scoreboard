void updateTimers() {
  showScore.Update();
  clockTime.Update();
}

void timersInit() {
  showScore.Every(10, showScores);
  clockTime.Every(500, Timing);
}
