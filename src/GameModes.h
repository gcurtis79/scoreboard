int maxScore, maxTime, gameMode;

void modeSelect() {
  gameMode ++;
  if (gameMode > 3)gameMode = 0;
  switch (gameMode) {
    case 0: {
      digitalWrite(A0, HIGH);
      maxScore = 10;
      maxTime = 10;
      break;
    }
    case 1: {
      digitalWrite(A1, HIGH);
      maxScore = 10;
      maxTime = 10;
      break;
    }
    case 2: {
      digitalWrite(A1, HIGH);
      maxScore = 20;
      maxTime = 20;
      break;
    }
    default: {
      digitalWrite(A3, HIGH);
      maxScore = 99;
      maxTime = 99;
      break;
    }
  }

}
