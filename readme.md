# Random Color Light with Arduino IDE

This project uses the ESP32 and Arduino IDE to set up an RGB LED light that changes colors randomly at the press of a button. There aren't a lot of practical applications (aside from interesting mood lighting and possibly fidget toys), but it's fun and demonstrates some examples of code in C. 


## Materials List
1 Breadboard with ESP32 and extension board attached

1 button

1 RGB LED

6 M/M jumpers

5 220Ω resistors 


<img width="624" height="202" alt="Screenshot 2026-05-14 at 17 01 06" src="https://github.com/user-attachments/assets/b124ac68-49c8-47b4-af19-24789e8b1c77" />


## Wiring the Breadboard

### The Light
Plug each of the RGB LED's four pins into a different row on the board.
Use a resistor to connect each of the red, green, and blue LED elements to the corresponding row on the opposite side. 
Connect each of these rows to a different pin on the breadboard with a M/M jumper (it may be helpful to color-code which jumper corresponds to which of the LED's colors).
Connect the long pin on the LED across the trench to the red (powered) rail on the opposite side. 

### The Button
Note: Avoid connecting any of these parts to rows that the LED setup is already using. 
Plug in the button across the trench. 
Use a resistor to connect one side of the button to the red (powered rail). 
On the other side of the trench, connect one side of the button to another row using a resistor, then connect that row to one of the pins of the extension board. Connect the other side of the button to the blue (ground) rail on that side of the trench.


## Raw Code 

    #define PIN_BUTTON 13

    const byte ledPins[] = {38, 39, 40};    //define red, green, blue led pins
    
    const byte chns[] = {0, 1, 2};          //define the pwm channels
    
    int red, green, blue;
    
    // the setup function runs once when you press reset or power the board
    
    void setup() {
    
      // initialize digital pin PIN_BUTTON as input.
      
      pinMode(PIN_BUTTON, INPUT);
      
      //setup the pwm channels,1KHz,8bit
      
      for (int i = 0; i < 3; i++) {   
      
        ledcAttachChannel(ledPins[i], 1000, 8, chns[i]);
      
      }
    
    }
    
    // the loop function runs over and over again forever
    
    void loop() {
    
      if (digitalRead(PIN_BUTTON) == LOW) {
      
        delay(20);
        
        if (digitalRead(PIN_BUTTON) == LOW) {
        
          red = random(0, 256);
          
          green = random(0, 256);
          
          blue = random(0, 256);
          
          setColor(red, green, blue);
        
        }
        
        while (digitalRead(PIN_BUTTON) == LOW);
        
        delay(20);
        
        while (digitalRead(PIN_BUTTON) == LOW);
      
      }
    
    }
    
    void setColor(byte r, byte g, byte b) {
    
      ledcWrite(ledPins[0], 255 - r); //Common anode LED, low level to turn on the led.
      
      ledcWrite(ledPins[1], 255 - g);
      
      ledcWrite(ledPins[2], 255 - b);
    
    }


## Descriptions of Source Code Parts

### This part establishes which pins will be used for the LEDs and button:

    #define PIN_BUTTON 13

    const byte ledPins[] = {38, 39, 40};    //define red, green, blue led pins
    
    const byte chns[] = {0, 1, 2};          //define the pwm channels
    
    int red, green, blue;
    

### This part establishes that the pins for the LEDs will send signals while the one for the button will receive them:

     // the setup function runs once when you press reset or power the board
    
    void setup() {
    
      // initialize digital pin PIN_BUTTON as input.
      
      pinMode(PIN_BUTTON, INPUT);
      
      //setup the pwm channels,1KHz,8bit
      
      for (int i = 0; i < 3; i++) {   
      
        ledcAttachChannel(ledPins[i], 1000, 8, chns[i]);
      
      }
    
    }


### This part is the main code, which determines whether a button is pushed and generates new random colors if it is: 

    // the loop function runs over and over again forever
    
    void loop() {
    
      if (digitalRead(PIN_BUTTON) == LOW) {
      
        delay(20);
        
        if (digitalRead(PIN_BUTTON) == LOW) {
        
          red = random(0, 256);
          
          green = random(0, 256);
          
          blue = random(0, 256);
          
          setColor(red, green, blue);
        
        }
        
        while (digitalRead(PIN_BUTTON) == LOW);
        
        delay(20);
        
        while (digitalRead(PIN_BUTTON) == LOW);
      
      }
    
    }


### This part sets the LEDs to their new colors (when called by the main code as part of the loop): 

    void setColor(byte r, byte g, byte b) {
    
      ledcWrite(ledPins[0], 255 - r); //Common anode LED, low level to turn on the led.
      
      ledcWrite(ledPins[1], 255 - g);
      
      ledcWrite(ledPins[2], 255 - b);
    
    }



## Link to code
The code can be found and downloaded here: 

https://github.com/LaniWils/blinkenlights/blob/main/final_draft_RGB_LED_lamp.ino


## References and Credits
Much of the source code for this project came from tutorials on freenove.com, specifically: 

"2. Chapter Button and LED" 
https://docs.freenove.com/projects/fnk0083/en/latest/fnk0083/codes/C/2_Button_%26_LED.html 

and "5. Chapter RGB LED" 
https://docs.freenove.com/projects/fnk0083/en/latest/fnk0083/codes/C/5_RGB_LED.html

