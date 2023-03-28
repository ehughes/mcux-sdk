Overview
========

The SYSPM project is a simple demonstration program of the SDK SYSPM driver. 

The System Performance Monitor (SYSPM) is a memory mapped peripheral that enables the user to monitor system and/or CPU events. 
This demo project obtains the event count value through the system performance monitor, and prints three values.

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

Running the demo
================
The following lines are printed to the serial terminal when the demo program is executed.
The three values printed each time may be different.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
START DEMO SYSPM
eventcounter = 7
eventcounter = 122034
eventcounter = 279104
END DEMO SYSPM
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


