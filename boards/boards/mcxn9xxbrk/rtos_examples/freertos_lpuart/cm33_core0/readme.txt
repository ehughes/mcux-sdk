Overview
========
This example is showing data send and receive via FreeRTOS adapted LPUART driver. Program initially send
string into serial terminal via virtual COM. After that, user may send some custom input and
application will return every 4 characters back to console. If delay from last user input exceed
10s (receive timeout) notification about exceeded timeout appear and application will finish.
Example need only single LPUART instance.

Toolchain supported
===================
- IAR embedded Workbench  9.30.1
- Keil MDK  5.37
- GCC ARM Embedded  10.3.1
- MCUXpresso  11.7.0

Hardware requirements
=====================
- Mini/micro USB cable
- MCX-N9XX-BRK board
- Personal Computer
- USB to serial converter

Board settings
==============
USB to serial converter connect pin:
    J2-60 - TX of USB to serial converter
    J2-59 - RX of USB to serial converter 
    J2-70 - GND of USB to serial converter 

Prepare the Demo
================
Note: MCUXpresso IDE project default debug console is semihost
1.  Connect a MCU-LINK or JLINK with DEBUG PORT(J4) and connect a micro USB cable with USB port(J3) on the board.
2.  Open a serial terminal with the following settings:
    - 115200 baud rate
    - 8 data bits
    - No parity
    - One stop bit
    - No flow control
3.  Download the program to the target board.
4.  Either press the reset button on your board or launch the debugger in your IDE to begin running the demo.

