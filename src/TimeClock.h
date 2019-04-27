void clockInit()
{
  DEBUG_PRINT("GameClock Init");
  display.begin();
  display.clear();
  display.setBrightness(3);
  display.displayOn();
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
}

void spinners()
{
  int8_t spinner[] = {B0000001, B00000010, B00000100, B00001000, B00010000, B00100000};
  if (spinSegment > 5)
  {
    spinSegment = 0;
  }
  for (uint8_t s = 0; s < 4; s++)
  {
    display.writeData(s, spinner[spinSegment]);
  }
  spinSegment++;
}

void dispTime()
{
  //HEX Digits     0     1     2     3     4     5     6     7     8     9
  byte nums[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
  TimeDisp[0] = nums[(minute / 10)];
  TimeDisp[1] = ((tickTock && !menu) ? nums[(minute % 10)] : (nums[(minute % 10)] + 0x80));
  TimeDisp[2] = nums[(second / 10)];
  TimeDisp[3] = nums[(second % 10)];
  display.writeData(0, TimeDisp, sizeof(TimeDisp));
}

void timesUp()
{
  if (tickTock)
  {
    dispTime();
  }
  else
  {
    display.clear();
  }
}

void Timing()
{
  tockTick = !tockTick;
  if (tockTick)
  {
    DEBUG_PRINT("tockTick");
    tickTock = !tickTock;
  }
  if (tickTock)
  {
    DEBUG_PRINT("tickTock");
    if (menu)
    {
      minute = maxTime;
      second = 0;
      endGame = 0;
      dispTime();
      return;
    }
    else if (endGame)
    {
      timesUp();
      return;
    }
    else
    {
      if (minute == maxTime)
      {
        endGame = 1;
        timesUp();
        return;
      }
      second++;
      if (second == 60)
      {
        minute++;
        second = 0;
      }
      dispTime();
    }
  }
}

void startClock()
{
    minute = 0;
    second = 0;
}