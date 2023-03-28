Overview
========
The SCTimer 16-bit counter project is a demonstration program of the SDK SCTimer driver operation when using the SCTimer counter
as two 16-bit counters.
The example toggles an output per counter when a match occurs.

To use any 16-bit counter, this project disables the Unify 32-bit Counter by hardware limit, no matter the Low 16-bit one or the
High 16-bit one. Both the Low 16-bit counters or the High 16-bit counters  enable bidirectional mode to extend the 16-bit counting
range. When the counter is in bidirectional mode, the effect of setting and clearing the output depends on whether the counter is
counting up or down.
The 16-bit low counter is scheduled for a match event every 0.1 seconds, and the 16-bit High counter is scheduled for a match event
every 0.2 seconds. When a 16-bit counter event occurs, the output is toggled and the counter is reset.

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
- USB to serial converter

Board settings
==============
USB to serial converter connect pin:
    J2-60 - TX of USB to serial converter
    J2-59 - RX of USB to serial converter 
    J2-70 - GND of USB to serial converter

Output signal		Board location
SCT0_OUT4    		J2-44 (P1_22)
SCT0_OUT5    		J2-43 (P1_23)

Prepare the Demo
================
1.  Connect a MCU-LINK or JLINK with DEBUG PORT(J4) and connect a micro USB cable with USB port(J3) on the board.
2.  Open a serial terminal with the following settings:
    - 115200 baud rate
    - 8 data bits
    - No parity
    - One stop bit
    - No flow control
3.  Download the program to the target board.
4.  Either press the reset button on your board or launch the debugger in your IDE to begin running the demo.

Running the demo
================
The log below shows example output in the terminal window:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SCTimer example to use it in 16-bit mode
The example shows both 16-bit counters running and toggling an output periodically
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

You'll see PWM signals on J2-44 and J2-43 using an oscilloscope
