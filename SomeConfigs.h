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
#define PERIOD_LED_PINS { A0, A1, A2, A3 }
