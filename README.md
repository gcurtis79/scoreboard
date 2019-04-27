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

Almost fully non-blocking. When a score is made, there is blocking for about 2 seconds while the scoreboard randomly does flashy lights, but the audio playing is not blocked.

Working:
* Score display
    * Score tracking via interrupt pins
* "Party mode" when score happens
    * "Party mode" holds untill pin release in case puck gets stuck
* Game Mode selection (Score limit based)
* Reset button code
* Dual speaker (2" 4Ohm 3W) and amplifier
    * Also added volume knob (Mini air-hockey paddle)

![alt text](https://raw.githubusercontent.com/gcurtis79/scoreboard/master/images/Paddle-Knob.jpg "Air Hockey Puck Knob")

Sorta working:
* A clock that counts up (game based on score, not time)

ToDo:
* Make clock run correctly
* Connect a beam-break style goal detection (Currently just a button)
