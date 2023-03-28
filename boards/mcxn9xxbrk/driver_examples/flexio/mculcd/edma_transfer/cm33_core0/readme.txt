Overview
========
This example shows how to use flexio mculcd edma driver to drive MCU LCD panel.
Please focus on functions DEMO_LcdWriteCommand, DEMO_LcdWriteData, and DEMO_LcdWriteMemory
to learn how to use the APIs. Note that the DEMO_LcdWriteCommand and DEMO_LcdWriteData
still use blocking APIs, because the send data is very small, blocking API is faster
in this case. It is still OK to use FLEXIO_MCULCD_TransferEDMA in this case.

In this project, the panel is devided into 4 windows, the project changes the color
of each window one by one. The behavior is:
1. Project starts with black screen.
2. Fill window one by one as red, and delay 0.5s after fill each window.
3. Fill window one by one as green, and delay 0.5s after fill each window.
4. Fill window one by one as blue, and delay 0.5s after fill each window.
5. Fill window one by one as white, and delay 0.5s after fill each window.
6. Go to step 2.

+---------------------------+---------------------------+
|                           |                           |
|                           |                           |
|                           |                           |
|      window 0             |        window 1           |
|                           |                           |
|                           |                           |
+---------------------------+---------------------------+
|                           |                           |
|                           |                           |
|                           |                           |
|      window 2             |        window 3           |
|                           |                           |
|                           |                           |
+---------------------------+---------------------------+

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
- TFT Proto 5" CAPACITIVE board HW REV 1.01 by Mikroelektronika.

Board settings
==============
USB to serial converter connect pin:
    J2-60 - TX of USB to serial converter
    J2-59 - RX of USB to serial converter 
    J2-70 - GND of USB to serial converter 

Connect the panel to header J1. Panel Pin 1 match J1 Pin 43, panel Pin 27 match J1 Pin 69.

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
When the project running, the panel shows as overview described.
