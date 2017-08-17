# FortNuino - Research Tracker
An Arduino project that allows tracking of research points generation for the game Fortnite without having the game open in the background !

!["How it looks IRL !"](http://image.noelshack.com/fichiers/2017/33/5/1503008743-fortnuino-pic-irl.jpg)

## Why?

Because I wanted my first self-written Arduino project to be related to the game I've been ~~slaving over~~ playing for almost a month now. 

Not only was it a learning experience, but also a useful gadget, so I hope releasing this publicly can benefit someone else too!

## Instructions

> TL;DR: Assemble the schema in the picture, add `Time.h` and `TimeAlarms.h` to your libs, download, open, upload, ???, **PROFIT !**

First, you need to assemble the circuitry schema that follows using :

- Your Arduino
- A breadboard
- A compatible LCD screen
- A 10K potentiometer
- A 220k resistor.
- A bunch of wires.

It's the common circuitry used for [all basic LCD display examples available on Arduino.cc](https://www.arduino.cc/en/Reference/LiquidCrystal).

![](https://www.arduino.cc/en/uploads/Tutorial/LCD_Base_bb_Fritz.png)

Next, get these two required libraries :

- [`Time.h`](https://github.com/PaulStoffregen/Time)
- [`TimeAlarms.h`](https://github.com/PaulStoffregen/TimeAlarms)

Download them as a `.zip` file and extract them where you keep your external libraries.

Once this is done, download this repository and open the `.ino` file using your Arduino IDE.

**Important:** Make sure you change the first two constants, `RESEARCH_GEN_LIMIT` and `RESEARCH_PER_HOUR`, to the appropriate values you have in-game.

Finally, connect your assembled Arduino to your computer, upload the program to it, and you're good to go!

## Usage

### Basic

Press the Reset button on your Arduino to reinitialize your research points tracker to 0.

**Remember:** change the first two constants within the code, `RESEARCH_GEN_LIMIT` and `RESEARCH_PER_HOUR`, to the appropriate values you have in-game.

### Advanced 

_Note: The following instructions are the steps I personally take in order to achieve a 1-to-1 sync with the game. Your mileage may vary._

1) In-game, go to your research menu and put your cursor on the "Collect" button.
2) Turn on the Arduino.
3) Put one hand on the Reset button of your Arduino, and another on your mouse's left click.
4) Wait for your counter in-game to go up 1
5) As soon as it increases by 1, press "Collect" and reset your Arduino, all at the same time.
6) Enjoy tracking your Research Points out of the Research menu !

## What's next

If this gets enough people interested, I'd like to develop the whole concept of research points tracking further.

I'm thinking of implement commands for serial input allowing to sync it without needing to restart, develop a v2 that'll implement a DS3231/DS3232 interface allowing it to continue tracking research without it being on 24/7...

Additionally, I plan in the coming weeks to make a web version for those who don't have an arduino (aka most players), with cloud tracking and a more user-friendly interface.
