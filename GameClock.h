#include <TM1637.h>

int8_t TimeDisp[] = {0x00, 0x00, 0x00, 0x00};
unsigned char ClockPoint = 1;
unsigned char doUpdate;
unsigned char halfsecond = 0;
unsigned char second;
unsigned char minute = 0;
unsigned char hour = 12;
uint8_t brightness = 0;


#define CLK 4
#define DIO 5

TM1637 clockDisp(CLK, DIO);

void Timing() {
  halfsecond ++;
  doUpdate = 1;
  if (halfsecond == 2) {
    second ++;
    if (second == 60) {
      minute++;
      second = 0;
    }
    if (minute == 60)minute = 0;
    halfsecond = 0;
  }
  ClockPoint = (~ClockPoint) & 0x01;
}

void TimeUpdate(void) {
  if (ClockPoint)clockDisp.point(POINT_ON);
  else clockDisp.point(POINT_OFF);
  TimeDisp[0] = minute / 10;
  TimeDisp[1] = minute % 10;
  TimeDisp[2] = second / 10;
  TimeDisp[3] = second % 10;
  doUpdate = 0;
}

void clockLoop() {
  if (doUpdate == 1) {
    TimeUpdate();
    clockDisp.display(TimeDisp);
  }
}

void clockInit(){
  clockDisp.set(2);
  clockDisp.init();
}
