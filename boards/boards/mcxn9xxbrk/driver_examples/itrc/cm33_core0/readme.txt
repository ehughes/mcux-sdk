Overview
========
The ITRC Example project is a demonstration program that uses the MCUX SDK software to set up Intrusion and Tamper Response Controller.
Then tests the expected behaviour.


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

Board settings
==============

Prepare the Demo
================
1.  Connect a MCU-LINK or JLINK with DEBUG PORT(J4) and connect a micro USB cable with USB port(J3) on the board.
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
When the demo runs successfully, the terminal displays similar information like the following:
~~~~~~~~~~~~~~~~~~

ITRC Peripheral Driver Example

Pass: No Event/Action triggered after Init

Enable ITRC IRQ Action response to SW Event 0

Trigger SW Event 0

ITRC IRQ Reached!
ITRC STATUS:
SW Event0 occured!
Generated ITRC interrupt!

Clear ITRC IRQ and SW Event 0 STATUS

Disable ITRC IRQ Action response to SW Event 0

Trigger SW Event 0

Pass: No Action triggered

End of example

~~~~~~~~~~~~~~~~~~
