Overview
========
The EVTG project is a simple demonstration of the SDK EVTG driver.
EVTG example will use SCTimer output 2 PWM sigal and then EVTG will genertae the intersection of PWM0 and PWM1.

Toolchain supported
===================
- IAR embedded Workbench  9.30.1
- Keil MDK  5.37
- GCC ARM Embedded  10.3.1
- MCUXpresso  11.7.0

Hardware requirements
=====================
- Mini/micro USB cable
- MCX-N9XX-BRK Board
- Personal Computer

Board settings
==============

```
Output signal		Board location
SCT0_OUT0    		J2-56 (P1_4)
SCT0_OUT1    		J2-55 (P1_5)
LED_RED                 J2-18 (P3_4)
```

Prepare the Demo
================
1.  Connect a MCU-LINK or JLINK with DEBUG PORT(J4) and connect a micro USB cable with USB port(J3) on the board.
2. Open a serial terminal with the following settings using USB2TLL connect to P1_8,P1_9 on J2 60,59 Pin
    - 115200 baud rate
    - 8 data bits
    - No parity
    - One stop bit
    - No flow control
3. Download the program to the target board.
4. Either press the reset button on your board or launch the debugger in your IDE to begin running
   the demo.

Running the demo
================
The log below shows example output in the terminal window:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
First SCTimer output success!

Second SCTimer output success!

EVTG output success.

The example output 2 PWM signals by SCTimer and their intersection by EVTG.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

You'll see PWM signals on J3-7 and J3-5 and EVTG signals on R201 using an oscilloscope.
