
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
2.  Open a serial terminal with the following settings (See Appendix A in Getting started guide for description how to determine serial port number):
    - 115200 baud rate
    - 8 data bits
    - No parity
    - One stop bit
    - No flow control
3.  Download the program to the target board.
4.  Either press the reset button on your board or launch the debugger in your IDE to begin running the demo.

Running the demo
================

When the example runs successfully, the following message is displayed in the terminal:

```
FLEXSPI NOR example started!

Successfully get FLEXSPI NOR configuration block

Successfully init FLEXSPI serial NOR flash

Serial NOR flash Information:
Serial NOR flash size: xx KB, Hex: (xx)
Serial NOR flash sector size: xx KB, Hex: (xx)
Serial NOR flash page size: xx B, Hex: (xx)

Erasing serial NOR flash over FLEXSPI

Successfully erased one sector of NOR flash device xx -> xx

Program a buffer to a page of NOR flash

Access serial NOR flash over AHB

Successfully programmed and verified location FLEXSPI AMBA memory xx -> xx

End of FLEXSPI NOR Example!
```

