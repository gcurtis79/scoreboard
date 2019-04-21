# scoreboard
Rebuild of an air hockey scoreboard a friend of mine blew up with 120v AC...

Very much a work in progress.

Working:
* Score tracking via interrupt pins
* "Party mode" when score happens
    * "Party mode" holds untill pin release in case puck gets stuck

Sorta working:
* A clock that counts up (will count down later)

ToDo:
* Make clock count periods and end game
* Add sound output for startup, scoring, and end period/game
* Connect a beam-break style goal detection
