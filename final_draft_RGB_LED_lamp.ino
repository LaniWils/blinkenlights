/**********************************************************************
  This file contributed the button part of the code
  Filename    : TableLamp
  Description : Control led by button.
  Auther      : www.freenove.com
  Modification: 2022/10/19
**********************************************************************/
/**********************************************************************
  And this file contributed the random color part of the code
  Filename    : ColorfulLight
  Description : Use RGBLED to show random color.
  Auther      : www.freenove.com
  Modification: 2024/07/01
**********************************************************************/
#define PIN_LED    2
#define PIN_BUTTON 13
const byte ledPins[] = {38, 39, 40};    //define red, green, blue led pins
const byte chns[] = {0, 1, 2};          //define the pwm channels
int red, green, blue;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin PIN_LED as an output.
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);
  for (int i = 0; i < 3; i++) {   //setup the pwm channels,1KHz,8bit
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
    reverseGPIO(PIN_LED);
  }
}

void reverseGPIO(int pin) {
  digitalWrite(pin, !digitalRead(pin));
}

void setColor(byte r, byte g, byte b) {
  ledcWrite(ledPins[0], 255 - r); //Common anode LED, low level to turn on the led.
  ledcWrite(ledPins[1], 255 - g);
  ledcWrite(ledPins[2], 255 - b);
}
