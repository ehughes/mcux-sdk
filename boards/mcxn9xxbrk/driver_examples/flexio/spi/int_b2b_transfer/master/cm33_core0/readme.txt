Overview
========
The flexio_spi_master_interrupt example shows how to use flexio spi master  driver in interrupt way:

In this example, a flexio simulated master connect to a flexio simulated spi slave .

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
To make the example work, connections needed to be as follows:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
MASTER(FlexIO SPI)          connect to      SLAVE(FlexIO SPI)
Pin Name   Board Location                   Pin Name    Board Location
SOUT       J1 pin 68                        SIN         J1 pin 68
SIN        J1 pin 67                        SOUT        J1 pin 67
SCK        J1 pin 69                        SCK         J1 pin 69
PCS0       J1 pin 70                        PCS0        J1 pin 70
GND        J1 pin 42                        GND         J1 pin 42
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Prepare the Demo
================
1.  Connect a USB cable between the host PC and the EVK board J5.
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
The log below shows the output of the hello world demo in the terminal window:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
FlexIO SPI interrupt example
Master Start...

Master runs successfully!
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
