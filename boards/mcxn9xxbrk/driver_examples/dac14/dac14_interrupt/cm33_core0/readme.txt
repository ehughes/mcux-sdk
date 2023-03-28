Overview
========

The DAC14 interrupt example shows how to use the DAC FIFO interrupt. 
When the application starts to run, it will immediately enter the DAC
ISR and write data into the FIFO which is empty at first. Once the DAC 
FIFO is triggered in the while loop, the data in it shall be read out; 
then the FIFO becomes empty again, and get another round of feed in the 
DAC ISR.

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
2.  Open a serial terminal with the following settings:
    - 115200 baud rate
    - 8 data bits
    - No parity
    - One stop bit
    - No flow control
3.  Download the program to the target board.
4.  Either press the reset button on your board or launch the debugger in your IDE to begin running the demo.
5.  A multimeter may be used to measure the DAC output voltage (Connector J19-1).

Running the demo
================
When the demo runs successfully, the log would be seen on the debug console terminal like:

DAC interrupt Example.
Press any key to trigger the DAC...
DAC14 next output: 500
DAC14 next output: 1000
DAC14 next output: 2000
DAC14 next output: 3000
DAC14 next output: 4000
DAC14 next output: 5000

The user can measure the DAC output pin to check the output voltage.

