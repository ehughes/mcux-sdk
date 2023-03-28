Overview
========
The mailbox_mutex example shows how to use mailbox mutex.

In this example:
The core 0 sends address of shared variable to core 1 by mailbox.
Both cores trying to get mutex in while loop, after that updates shared variable
and sets mutex, to allow access other core to shared variable.

Toolchain supported
===================
- MCUXpresso  11.7.0
- GCC ARM Embedded  10.3.1
- Keil MDK  5.37
- IAR embedded Workbench  9.30.1

Hardware requirements
=====================
- Mini/micro USB cable
- MCX-N9XX-BRK board
- Personal Computer

Board settings
==============
No special settings are required.

Prepare the Demo
================
Note: MCUXpresso IDE project default debug console is semihost
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
The log below shows example output of the Mailbox mutex example in the terminal window:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Mailbox mutex example
Copy CORE1 image to address: 0x2004e000, size: 6940
Core1 has mailbox mutex, update shared variable to: 1
Core0 has mailbox mutex, update shared variable to: 2
Core1 has mailbox mutex, update shared variable to: 3
Core0 has mailbox mutex, update shared variable to: 4
Core1 has mailbox mutex, update shared variable to: 5
.
.
.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Note:
The "Copy CORE1 image to address..." log message is not displayed on the terminal window when MCUXpresso IDE is used.
In case of MCUXpresso IDE the secondary core image is copied to the target memory during startup automatically.
