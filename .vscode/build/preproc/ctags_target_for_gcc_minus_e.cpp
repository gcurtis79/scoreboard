# 1 "d:\\Arduino\\scoreboard\\Scoreboard.ino"
# 1 "d:\\Arduino\\scoreboard\\Scoreboard.ino"
//#include <Arduino.h>
# 3 "d:\\Arduino\\scoreboard\\Scoreboard.ino" 2
# 4 "d:\\Arduino\\scoreboard\\Scoreboard.ino" 2
# 5 "d:\\Arduino\\scoreboard\\Scoreboard.ino" 2
# 6 "d:\\Arduino\\scoreboard\\Scoreboard.ino" 2
# 7 "d:\\Arduino\\scoreboard\\Scoreboard.ino" 2
# 8 "d:\\Arduino\\scoreboard\\Scoreboard.ino" 2

void setup() {

  Serial.begin(115200);
  delay(1000);
  Serial.println("Startup");

  soundInit();
  scoreInit();
  clockInit();
  startTimers();
  Serial.println("Init Done");
}

void loop() {
  updateTimers();
  clockLoop();
}
