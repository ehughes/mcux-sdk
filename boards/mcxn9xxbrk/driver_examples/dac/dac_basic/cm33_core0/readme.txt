Overview
========

The dac_basic example shows how to use DAC module simply as the general DAC converter.

When the DAC's buffer feature is not enabled, the first item of the buffer is used as the DAC output data register.
The converter would always output the value of the first item. In this example, it gets the value from terminal,
outputs the DAC output voltage through DAC output pin.

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
DAC output pin: J2-30(P4_2)

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

DAC basic Example.
Please input a value (0 - 4095) to output with DAC: 200
Input value is 200
DAC out: 200

Then user can measure the DAC output pin to check responding voltage.

