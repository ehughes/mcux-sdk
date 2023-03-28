Overview
========

The INTM project is a simple demonstration of the SDK INTM driver.
The role of INTM is to monitor the interrupt response. The main monitoring is whether the interrupt has timed out from 
the request to the response. Up to 4 interrupts can be monitored simultaneously.
This example is to detect the key interrupt, verify the function of INTM by delaying the time from the trigger to 
the response of the key interrupt, and confirm the interrupt timeout by the flag bit one.

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
2. Open a serial terminal on PC for the serial device with these settings:
    - 115200 baud rat
    - 8 data bits
    - No parity
    - One stop bit
    - No flow control
3. Download the program to the target board.
4. Either press the reset button on your board or launch the debugger in your IDE to begin running
   the demo.

Running the demo
================
The following lines are printed to the serial terminal when the demo program is executed.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
INTM Example Start:

Press SW3 to trigger interrupt. 
INTM timeout. 

INTM Example End.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

