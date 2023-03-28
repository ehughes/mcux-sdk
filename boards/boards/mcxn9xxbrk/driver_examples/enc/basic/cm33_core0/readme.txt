Overview
========

The enc_basic example shows how to quickly start using ENC driver.

In this example, user needs to connect a real encoder to the board. Actually, only PHASE A and PHASE B are enough for the basic application. When running the project, user can turn the encoder so that ENC module can monitor the position change. Then, the internal counter would also count for the position. User can also type keys into terminal, and the current position values recorded by ENC would display. 

The ENC hardware is created with a special synchronize mechanism. There are actually 4 counters (the 32-bit position counter is combined with the two 16-bit counter registers) for position with responding hold registers. When any of the counter registers is read, the contents of each counter register is written to the corresponding hold register. Taking a snapshot of the counters' values provides a consistent view of a system position and a velocity to be attained.


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
- An encoder with PHASE A/B signals.

Board settings
==============
1. For pin connection between board and USB to serial converter:
       J2-60 - TX of USB to serial converter
       J2-59 - RX of USB to serial converter 
       J2-70 - GND of USB to serial converter 
2. For pin connection between board and encoder,
      J2.4  (P1_0)  -> kINPUTMUX_TrigIn1ToEnc0Phasea -> ENC_PHA
      J2.44 (P1_22) -> kINPUTMUX_TrigIn3ToEnc0Phaseb -> ENC_PHB
      J2.8  (P1_1)  -> kINPUTMUX_TrigIn0ToEnc0Index  -> ENC_INDEX

Prepare the Demo
================
1.  Connect a MCU-LINK or JLINK with DEBUG PORT(J4) and connect a micro USB cable with USB port(J3) on the board.
2.  Connect the wires between encoder and the MCU board. See to the code for pin mux setting in function "BOARD_InitPins()".
3.  Open a serial terminal with the following settings:
    - 115200 baud rate
    - 8 data bits
    - No parity
    - One stop bit
    - No flow control
4.  Download the program to the target board.
5.  Either press the reset button on your board or launch the debugger in your IDE to begin running the demo.

Running the demo
================
Turn the encoder and type in any key into terminal.
When the demo runs successfully, the log would be seen on the OpenSDA terminal like:

ENC Basic Example.
Press any key to get the encoder values ...

Current position value: 0
Position differential value: 0
Position revolution value: 0

Current position value: 10
Position differential value: 10
Position revolution value: 0

...


