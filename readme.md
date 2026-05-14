# Random Color Light with Arduino IDE

This project uses the ESP32 and Arduino IDE to set up an RGB LED light that changes colors randomly at the press of a button. There aren't a lot of practical applications (aside from interesting mood lighting and possibly fidget toys), but it's fun and demonstrates some examples of code in C. 


## Materials List
1 Breadboard with ESP32 and extension board attached

1 RGB LED

6 M/M jumpers

5 220Ω resistors 


## Wiring the Breadboard

### The Light
Plug each of the RGB LED's four pins into a different row on the board.
Use a resistor to connect each of the red, green, and blue LED elements to the corresponding row on the opposite side. 
Connect each of these rows to a different pin on the breadboard with a M/M jumper (it may be helpful to color-code which of the LED's colors corresponds to which jumper).
Connect the long pin on the LED across the trench to the red (powered) rail on the opposite side. 

### The Button
Note: Avoid connecting any of these parts to rows that already have parts from the LED setup in them. 
Plug in a button across the trench. 
Use a resistor to connect one side of the button to the red (powered rail). 
On the other side of the trench, connect one side of the button to another row using a resistor, then connect that row to one of the pins of the extension board. Connect the other side of the button to the blue (ground) rail on that side of the trench.
