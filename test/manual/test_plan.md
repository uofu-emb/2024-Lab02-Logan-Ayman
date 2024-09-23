How to set up the test scenario:
- Compile the program, flash it to the microcontroller

How to exercise the system:
- Plug the board in and flash it. It should run off of USB power.
- Use the serial monitor inside VS Code to connect to the board and test the character input/output. Default settings, baud rate 115200

Expected behavior:
- The controller should be blinking the LED once a second
- After opening the serial monitor, you should be able to send characters a-z, upper or lowercase, and the return should be the opposite case. If any other character is sent, the same character is returned. If multiple characters are sent as a whole message, all letters are flipped from upper to lower and vice versa and the same message is returned. This should all continue working without stopping the LED.