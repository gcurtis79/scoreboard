const byte digitR[] = {
    B1111110, // 0
    B0110000, // 1
    B1101101, // 2
    B1111001, // 3
    B0110011, // 4
    B1011011, // 5
    B1011111, // 6
    B1110000, // 7
    B1111111, // 8
    B1111011  // 9
};

const byte digitL[] = {
    B0111111, // 0
    B0000110, // 1
    B1011101, // 2
    B1001111, // 3
    B1100110, // 4
    B1101011, // 5
    B1111011, // 6
    B0001110, // 7
    B1111111, // 8
    B1101111, // 9
};

void partyMode()
{
  for (uint8_t i = 0; i < 100; i++)
  {
    mcp.writeGPIOAB((random(B0000000, B1111111) << 9) + (random(B00, B10) << 7) + random(B0000000, B1111111));
    digitalWrite(ap[random(0, 4)], random(0, 2));
    delay(25);
    if (!digitalRead(2) || !digitalRead(3))
      i = 0;
  }
  for (uint8_t i = 0; i < 4; i++)
  {
    digitalWrite(ap[i], 0);
  }
  digitalWrite(ap[gameMode], HIGH);
}

void homeScored()
{
  if (millis() > 2000 && !endGame)
  {
    homeScoring = true;
  }
}

void awayScored()
{
  if (millis() > 2000 && !endGame)
  {
    awayScoring = true;
  }
}

void scoreInit()
{
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  delay(100);
  mcp.begin();
  for (uint8_t i = 0; i <= 15; i++)
  {
    mcp.pinMode(i, OUTPUT);
    mcp.digitalWrite(i, LOW);
  }
  for (uint8_t i = 0; i < 4; i++)
  {
    pinMode(ap[i], OUTPUT);
  }
  homeScoring = false;
  awayScoring = false;
  attachInterrupt(digitalPinToInterrupt(2), homeScored, LOW);
  attachInterrupt(digitalPinToInterrupt(3), awayScored, LOW);
}

void showScores()
{
  if (homeScore > 99)
  {
    homeScore = 0;
  }
  if (awayScore > 99)
  {
    awayScore = 0;
  }
  if (homeScoring || awayScoring)
  {
    if (menu)
    {
      startGame();
      return;
    }
    else
    {
      if (homeScoring)
      {
        homeScore++;
      }
      if (awayScoring)
      {
        awayScore++;
      }
      snd.play("goal.wav");
      partyMode();
      homeScoring = 0;
      awayScoring = 0;
    }
    if ((homeScore >= maxScore || awayScore >= maxScore))
    {
      endGame = 1;
      return;
    }
  }
  uint8_t homeOne = homeScore / 10;
  uint8_t homeTwo = homeScore % 10;
  uint8_t awayOne = awayScore / 10;
  uint8_t awayTwo = awayScore % 10;

  mcp.writeGPIOAB((digitL[awayTwo] << 9) + (B11 << 7) + digitR[homeTwo]);
  mcp.digitalWrite(7, LOW);
  delay(5);
  mcp.digitalWrite(7, HIGH);

  mcp.writeGPIOAB((digitL[awayOne] << 9) + (B11 << 7) + digitR[homeOne]);
  mcp.digitalWrite(8, LOW);
  delay(5);
  mcp.digitalWrite(8, HIGH);
}
