void modeShow()
{
  homeScore = maxScore;
  awayScore = maxScore;
}

void modeSet()
{
  for (uint8_t i = 0; i < 4; i++)
  {
    digitalWrite(ap[i], LOW);
  }
  switch (gameMode)
  {
  case 0:
  {
    maxScore = 10;
    maxTime = 10;
    digitalWrite(ap[0], HIGH);
    break;
  }
  case 1:
  {
    maxScore = 20;
    maxTime = 20;
    digitalWrite(ap[1], HIGH);
    break;
  }
  case 2:
  {
    maxScore = 30;
    maxTime = 30;
    digitalWrite(ap[2], HIGH);
    break;
  }
  default:
  {
    maxScore = 99;
    maxTime = 99;
    digitalWrite(ap[3], HIGH);
    break;
  }
  }
  modeShow();
}

void modeInit()
{
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  modeSet();
}

void startClock(void); // Prototype for TimeClock.h (not loaded yet)
void startGame()
{
  snd.play("charge.wav");
  menu = 0;
  homeScore = 0;
  homeScoring = 0;
  awayScore = 0;
  awayScoring = 0;
  startClock();
}

void modeSelect()
{
  gameMode++;
  if (gameMode > 3)
    gameMode = 0;
  modeSet();
}

void gameReset()
{
  gameMode = 0;
  homeScore = 0;
  homeScoring = 0;
  awayScore = 0;
  awayScoring = 0;
  menu = 1;
  modeSet();
  modeShow();
}
