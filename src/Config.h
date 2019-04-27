/* Some global defines to set/enable/disable options */

//HardwareSerial Serial;

// Set serial debugging on/off with baud - Comment to disable
#define SERIAL_DEBUG 115200
#ifdef SERIAL_DEBUG
#define DEBUG_PRINT(x) Serial.println(x)
#else
#define DEBUG_PRINT(x)
#endif

// Sound settings, Speaker pin and SD Cable Select pin
#define SPK_PIN 9

// Timer (TM1637) config
#define CLOCK_CLK_PIN 4
#define CLOCK_DIO_PIN 5

// Pins for LEDs for period/overtime display
#define PERIOD_LED_PINS \
  {                     \
    A0, A1, A2, A3      \
  }

// Class declarations

// GameModes.h
uint8_t maxScore = 99;
uint8_t maxTime = 99;
uint8_t gameMode = 0;
bool menu = 1;
const byte ap[] = PERIOD_LED_PINS;

// Scores.h
Adafruit_MCP23017 mcp;
uint8_t homeScore = 00;
uint8_t awayScore = 00;
bool endGame = 0;
volatile bool homeScoring = false;
volatile bool awayScoring = false;

// Sound.h
TMRpcm snd;

// TimeClock.h
TM1637 display(CLOCK_CLK_PIN, CLOCK_DIO_PIN);
uint8_t TimeDisp[4];
bool tickTock = 0;
bool tockTick = 0;
int8_t second = 0;
int8_t minute = 0;
uint8_t spinSegment = 0;

// Timers.h
EveryTimer showScore;
EveryTimer clockTime;
