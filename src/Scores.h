#include <EveryTimer.h>
#include <Wire.h>
#include <Adafruit_MCP23017.h>

Adafruit_MCP23017 mcp;

uint8_t homeScore = 00;
uint8_t awayScore = 00;
volatile bool homeScoring = false;
volatile bool awayScoring = false;
const byte ap[4] = PERIOD_LED_PINS;

uint16_t digitR[10] = {
  B1111110,  // 0
  B0110000,  // 1
  B1101101,  // 2
  B1111001,  // 3
  B0110011,  // 4
  B1011011,  // 5
  B1011111,  // 6
  B1110000,  // 7
  B1111111,  // 8
  B1111011   // 9
};

uint16_t digitL[10] = {
  B0111111 << 9,  // 0
  B0000110 << 9,  // 1
  B1011101 << 9,  // 2
  B1001111 << 9,  // 3
  B1100110 << 9,  // 4
  B1101011 << 9,  // 5
  B1111011 << 9,  // 6
  B0001110 << 9,  // 7
  B1111111 << 9,  // 8
  B1101111 << 9,  // 9
};

void partyMode() {
  DEBUG_PRINT("PartyMode");
  for (int i = 0; i < 100; i++) {
    mcp.writeGPIOAB((random(B0000000, B1111111) << 9) + (random(B00, B10) << 7) + random(B0000000, B1111111));
    digitalWrite(ap[random(0, 6)], random(0,1));
    delay(25);
    if (!digitalRead(2) || !digitalRead(3))i = 0;
  }
  for (int i = 0; i < 4; i++)digitalWrite(ap[i], 0);
  if (homeScoring)homeScore++;
  if (awayScoring)awayScore++;
  homeScoring = false;
  awayScoring = false;
}

void homeScored() {
  DEBUG_PRINT("Home scored");
  homeScoring = true;
}

void awayScored() {
  DEBUG_PRINT("Away scored");
  awayScoring = true;
}

void scoreInit() {
  DEBUG_PRINT("Scores Init");
  DEBUG_PRINT("PinModes");
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  delay(100);
  DEBUG_PRINT("MCP Begin");
  mcp.begin();
  DEBUG_PRINT("MCP23017 Initialized");
  for (int i = 0; i <= 15; i++) {
    mcp.pinMode(i, OUTPUT);
    mcp.digitalWrite(i, LOW);
  }
  for (int i = 0; i < 4; i++)pinMode(ap[i], OUTPUT);
  homeScoring = false;
  awayScoring = false;
  attachInterrupt(digitalPinToInterrupt(2), homeScored, FALLING);
  attachInterrupt(digitalPinToInterrupt(3), awayScored, FALLING);
  homeScore = 00;
  awayScore = 00;
}

void showScores() {
  if (homeScore > 99)homeScore = 0;
  if (awayScore > 99)awayScore = 0;
  if (homeScoring || awayScoring) {
    snd.play("goal.wav");
    partyMode();
  }
  int homeOne = homeScore / 10;
  int homeTwo = homeScore % 10;
  int awayOne = awayScore / 10;
  int awayTwo = awayScore % 10;

  mcp.writeGPIOAB(digitL[awayTwo] + (B11 << 7) + digitR[homeTwo]);
  mcp.digitalWrite(7, LOW);
  delay(5);
  mcp.digitalWrite(7, HIGH);

  mcp.writeGPIOAB(digitL[awayOne] + (B11 << 7) + digitR[homeOne]);
  mcp.digitalWrite(8, LOW);
  delay(5);
  mcp.digitalWrite(8, HIGH);
}
