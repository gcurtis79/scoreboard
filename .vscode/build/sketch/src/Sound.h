#include <SD.h>
#include <SPI.h>

#include <TMRpcm.h>

TMRpcm snd;

void soundInit() {
  snd.speakerPin = SPK_PIN;
  if (!SD.begin()) {
    DEBUG_PRINT("SD Failed");
    for (int i = 0; i < 3; i++) {
      tone(9, 100, 75);
      delay(150);
    }
    return;
  }
}
