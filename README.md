## arduino-garage-door

[![PlatformIO](https://github.com/lobis/arduino-garage-door/actions/workflows/platformio.yml/badge.svg)](https://github.com/lobis/arduino-garage-door/actions/workflows/platformio.yml)

A simple program to use a microcontroller for opening and closing of a garage type of door.

I used an ESP32 microcontroller as the main component together with a 2 relay board.

The microcontroller provides a very simple web server with three buttons (open, close, stop) for user control.

The program is written in such a way that opening / closing of the door is not blocking, meaning the server can process additional commands while the door is operating.
