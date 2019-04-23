# Arduino Air Hockey Scoreboard

![alt text](https://raw.githubusercontent.com/gcurtis79/scoreboard/master/images/scoreup.jpg "Air Hockey Scoreoard")

Rebuild of an air hockey scoreboard a friend of mine blew up with 120v AC...

The original ran on an unknown MCU, and was totally fried. Some of the 7-Segment displays literally exploded, some even cracking the plastic holders.

![alt text](https://raw.githubusercontent.com/gcurtis79/scoreboard/master/images/burnt.jpg "burnt board")

Original features:
* Dual sided scoreboard that hung center-table (shown in photo)
* Buttons to set game time/score limits, and to start the game
* Infra-red emitter/detector in the goals to sense puck
* Speaker for startup, goal, and period/game start/end sounds

I plan on making it run on an ESP8266/ESP32, but the 4-digit display/clock library seems to be crashing it at the moment, so I currently have it running on an Arduino Nano (Atmega328p)

Very much a work in progress.

Working:
* Score display with almost no flicker
    * There is a flick every half second then the clock updates
* Score tracking via interrupt pins
* "Party mode" when score happens
    * "Party mode" holds untill pin release in case puck gets stuck

Sorta working:
* A clock that counts up (will count down later)

ToDo:
* Make clock count periods and end game
* Mode and start button functions (period time, goal limit)
* Add sound output for startup, scoring, and end period/game
* Connect a beam-break style goal detection
