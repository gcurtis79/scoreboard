#include <SD.h>
#include <SPI.h>
#include <Wire.h>
#include <ErriezTM1637.h>
#include <TMRpcm.h>
#include <EveryTimer.h>
#include <Adafruit_MCP23017.h>

#include "src/Config.h"
#include "src/GameModes.h"
#include "src/Sound.h"
#include "src/Scores.h"
#include "src/TimeClock.h"
#include "src/Timers.h"

void setup()
{
#ifdef SERIAL_DEBUG
  Serial.begin(SERIAL_DEBUG);
  delay(1000);
#endif
  soundInit();
  scoreInit();
  clockInit();
  modeInit();
  timersInit();
}

void loop()
{
  if (digitalRead(6) == LOW)
  {
    display.clear();
    while (digitalRead(6) == LOW)
      ;
    modeSelect();
  }
  if (digitalRead(7) == LOW)
  {
    while (digitalRead(7) == HIGH)
      ;
    gameReset();
  }
  updateTimers();
  //clockLoop();
}
