Overview
========
The WWDT Example project is to demonstrate usage of the KSDK wdog driver.
In this example,quick test to show user how to feed watch dog.
User need to feed the watch dog in time before it warning or timeout interrupt.
The WINDOW register determines the highest TV value allowed when a watchdog feed is
performed. 

Toolchain supported
===================
- IAR embedded Workbench  9.30.1
- Keil MDK  5.37
- GCC ARM Embedded  10.3.1
- MCUXpresso  11.7.0

Hardware requirements
=====================
- Micro USB cable
- MCX-N9XX-BRK board
- Personal Computer

Board settings
==============


Prepare the Demo
================
1.  Connect a MCU-LINK or JLINK with DEBUG PORT(J4) and connect a micro USB cable with USB port(J3) on the board.
2.  Open a serial terminal with the following settings using USB2TLL connect to P1_8,P1_9 on J2 60,59 Pin
    - 115200 baud rate
    - 8 data bits
    - No parity
    - One stop bit
    - No flow control
3.  Download the program to the target board.
4.  Either press the reset button on your board or launch the debugger in your IDE to begin running the demo.

Running the demo
================
If the demo run successfully, you will see the red LED blink every two seconds.
The log below shows example output of the WWDT driver demo in the terminal window:
--- Time out reset test start ---
Watchdog reset occurred

--- Window mode refresh test start---
WDOG has be refreshed!
WDOG has be refreshed!
WDOG has be refreshed!
WDOG has be refreshed!
WDOG has be refreshed!
WDOG has be refreshed!
WDOG has be refreshed!
WDOG has be refreshed!
WDOG has be refreshed!
WDOG has be refreshed!
WDOG has be refreshed!
WDOG has be refreshed!
WDOG has be refreshed!
WDOG has be refreshed!

