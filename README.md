Physical/Virtual Hardware Needed:

8051 Board.
16*2 LCD display.
4*4 keypad.

Software/Compiler Dependencies:

Kiel 4.0/5.0 to compile and generate the 8051 hex code.

Step 1:

Load the folder into the kiel IDE and compile the code. Refer https://www.keil.com/c51/ to download and setup up the environment.

Step 2:

Once the hex code is generated, load the 8051 board/simulator and make all the connections with respect to pin number assigned in the header file.

That's it, Now restart the board if it's physical one. The code will start executing.

Direction of Use:

1. Enter the number with the operator eg: 10 * 30 + 78 / 90 output would be 300.

Note: operator precedence is taken care and the flaot point values are neglected.
