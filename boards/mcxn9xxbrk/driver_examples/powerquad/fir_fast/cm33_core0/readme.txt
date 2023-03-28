Overview
========
The PowerQuad fetches data from system RAM and private RAM through different
path, for the calculations which need data from two parts of memory, such as
FIR, convolve, correlate, and some matrix operations, place the input data B
in private RAM improves the performance.
PowerQuad private RAM starts from address 0xe0000000, the first 4KByte is used
by PowerQuad driver, the RAM starts from 0xe0001000 could be used by user
for optimization. In this example, the FIR taps, convolve input data B, and correlate
input data B are not changed, so they are converted to float format and saved
to private RAM at the beginning.
If the example runs successfully, the performance using optimized method is better
than the normal method.

Toolchain supported
===================
- MCUXpresso  11.7.0
- Keil MDK  5.37
- IAR embedded Workbench  9.30.1
- GCC ARM Embedded  10.3.1

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
1.  Connect a MCU-LINK or JLINK with DEBUG PORT(J4) and connect a micro USB cable with USB port(J3) on the board.
2.  Open a serial terminal with the following settings (See Appendix A in Getting started guide for description how to determine serial port number):
    - 115200 baud rate
    - 8 data bits
    - No parity
    - One stop bit
    - No flow control
3.  Download the program to the target board.
4.  Either press the reset button on your board or launch the debugger in your IDE to begin running the demo.

Running the demo
================
The message about error or success will be output to the termial.
