Overview
========
Hello World Virtual Com demonstrates the use of virtual com to print the "Hello World" string to the terminal.
Different with Hello World demo (a HW UART peripheral is used to transmit data), the demo transmits data based on
a serial port simulated by the USB device stack on target board side via USB peripheral.
The purpose of this demo is to demonstrate how to use virtual com and provide a simple project for debugging and further development. 

Toolchain supported
===================
- IAR embedded Workbench  9.30.1
- Keil MDK  5.37
- GCC ARM Embedded  10.3.1
- MCUXpresso  11.7.0

Hardware requirements
=====================
- Two Micro USB cables
- MCX-N9XX-BRK board
- Personal Computer

Board settings
==============

Prepare the Demo
================
1.  Connect a MCU-LINK or JLINK with DEBUG PORT(J4) and connect a micro USB cable with USB port(J3) on the board.
2.  Download the program to the target board.
3.  Either press the reset button on your board or launch the debugger in your IDE to begin running the demo.
4.  Open a serial terminal with the following settings using USB2TLL connect to P1_8,P1_9 on J2 60,59 Pin
    "boards\mcxn9xxbrk\usb_examples\usb_device_cdc_vcom\bm\readme.pdf".

Running the demo
================
The log below shows the output of the hello world demo in the terminal window:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
hello world.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
The debug console virtual com will echo back the received characters.
