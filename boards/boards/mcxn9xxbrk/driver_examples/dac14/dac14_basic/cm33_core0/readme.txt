Overview
========

The DAC14 basic example shows how to use the DAC module simply as the general DAC converter. 
No support is needed to be triggered by DAC in the example using the buffer mode. The value 
written into DAC data register will be directly pushed to analog conversion.

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
Connect pin:
J2-60 - TX of USB to serial converter
J2-59 - RX of USB to serial converter 
J2-70 - GND of USB to serial converter 
DAC output pin: J19-1

Prepare the Demo
================
1.  Connect a MCU-LINK or JLINK with DEBUG PORT(J4) and connect a micro USB cable with USB port(J3) on the board.
2. Open a serial terminal on PC for the serial device with these settings:
    - 115200 baud rate
    - 8 data bits
    - No parity
    - One stop bit
    - No flow control
3. Download the program to the target board.
4. Either press the reset button on your board or launch the debugger in your IDE to begin running
   the demo.
5. A multimeter may be used to measure the DAC output voltage.

Running the demo
================
When the demo runs successfully, the log would be seen on the OpenSDA terminal like:

DAC14 Basic Example.

Please input a value (0 - 16383) to output with DAC: 1000
Input value is 1000
DAC out: 1000

The user can measure the DAC output pin to check the output voltage.

