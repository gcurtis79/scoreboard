int homeScore = 00;
int awayScore = 00;

int digitR[][7] = {
  // D     E     F     A     B     C     G           
  { HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW  },// 0
  { LOW,  LOW,  LOW,  LOW,  HIGH, HIGH, LOW  },// 1
  { HIGH, HIGH, LOW,  HIGH, HIGH, LOW,  HIGH },// 2
  { HIGH, LOW,  LOW,  HIGH, HIGH, HIGH, HIGH },// 3
  { LOW,  LOW,  HIGH, LOW,  HIGH, HIGH, HIGH },// 4
  { HIGH, LOW,  HIGH, HIGH, LOW,  HIGH, HIGH },// 5
  { HIGH, HIGH, HIGH, HIGH, LOW,  HIGH, HIGH },// 6
  { LOW,  LOW,  LOW,  HIGH, HIGH, HIGH, LOW  },// 7
  { HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH },// 8
  { HIGH, LOW,  HIGH, HIGH, HIGH, HIGH, HIGH } // 9
};

int digitL[][7] = {
  // A     F     E     D     B     C     G
  { HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW  },// 0
  { LOW,  LOW,  LOW,  LOW,  HIGH, HIGH, LOW  },// 1
  { HIGH, LOW,  HIGH, HIGH, HIGH, LOW,  HIGH },// 2
  { HIGH, LOW,  LOW,  HIGH, HIGH, HIGH, HIGH },// 3
  { LOW,  HIGH, LOW,  LOW,  HIGH, HIGH, HIGH },// 4
  { HIGH, HIGH, LOW,  HIGH, LOW,  HIGH, HIGH },// 5
  { HIGH, HIGH, HIGH, HIGH, LOW,  HIGH, HIGH },// 6
  { HIGH, LOW,  LOW,  LOW,  HIGH, HIGH, LOW  },// 7
  { HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH },// 8
  { HIGH, HIGH, LOW,  HIGH, HIGH, HIGH, HIGH } // 9
};

void doCount() {
  if (homeScore < 99) {
      homeScore++;
  } else {
    homeScore = 00;
  }
}

void showScores() {
  awayScore = abs(homeScore-100);
  int homeOne = homeScore / 10;
  int homeTwo = homeScore % 10;
  int awayOne = awayScore / 10;
  int awayTwo = awayScore % 10;
  for (int i = 0; i < 7; i++) {
    mcp.digitalWrite(abs(i-6), digitR[awayTwo][i]);
  }
  for (int i = 9; i <= 15; i++) {
    mcp.digitalWrite(i, digitL[homeTwo][i-9]);
  }
  mcp.digitalWrite(8, LOW);
  delay(5);
  mcp.digitalWrite(8, HIGH);
  for (int i = 0; i < 7; i++) {
    mcp.digitalWrite(abs(i-6), digitR[awayOne][i]);
  }
  for (int i = 9; i <= 15; i++) {
    mcp.digitalWrite(i, digitL[homeOne][i-9]);
  }
  mcp.digitalWrite(7, LOW);
  delay(5);
  mcp.digitalWrite(7, HIGH);
}
