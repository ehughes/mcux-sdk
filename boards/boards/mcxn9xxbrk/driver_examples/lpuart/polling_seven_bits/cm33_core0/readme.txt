Overview
========
The lpuart_polling_seven_bits Example project is to demonstrate usage of the KSDK lpuart driver with seven data bits feature enabled.
In the example, you can send characters to the console back and they will be printed out onto console
 instantly.
NOTE: Please set com port format to "7 data bits without parity bit" in PC's com port tool

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
    J1-51 - TX of USB to serial converter
    J1-54 - RX of USB to serial converter 
    J1-42 - GND of USB to serial converter 

Prepare the Demo
================
Note: MCUXpresso IDE project default debug console is semihost
1.  Connect a MCU-LINK or JLINK with DEBUG PORT(J4) and connect a micro USB cable with USB port(J3) on the board.
2.  Open a serial terminal with the following settings:
    - 115200 baud rate
    - 7 data bits
    - No parity
    - One stop bit
    - No flow control
3. Download the program to the target board.
4. Either press the reset button on your board or launch the debugger in your IDE to begin running the demo.

Running the demo
================
When the demo runs successfully, the log would be seen on the OpenSDA terminal like:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Lpuart polling example with seven data bits
Board will send back received characters
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
