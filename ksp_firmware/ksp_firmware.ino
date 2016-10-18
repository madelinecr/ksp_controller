#include <Keyboard.h>


// Switches on controller
const int combo1Pin = 9;
const int combo2Pin = 8;
const int combo3Pin = 7;
const int combo4Pin = 6;
const int gearPin = 3;
const int sasPin = 2;
const int rcsPin = 5;
const int panicPin = 4;

// Output of switches
const String combo1Char = "1";
const String combo2Char = "2";
const String combo3Char = "3";
const String combo4Char = "4";
const String gearChar = "g";
const String sasChar = "t";
const String rcsChar = "r";
const String panicChar = "Backspace";

// State
int combo1PinState = 0;
int combo2PinState = 0;
int combo3PinState = 0;
int combo4PinState = 0;
int gearPinState = 0;
int sasPinState = 0;
int rcsPinState = 0;
int panicPinState = 0;

// Previous State
int combo1PinStatePrev = 0;
int combo2PinStatePrev = 0;
int combo3PinStatePrev = 0;
int combo4PinStatePrev = 0;
int gearPinStatePrev = 0;
int sasPinStatePrev = 0;
int rcsPinStatePrev = 0;
int panicPinStatePrev = 0;

void checkState(int State, int prevState, String character) {
  if(State != prevState) {
    Serial.print(character);
    delay(250); // Crucial to allow for switch to settle
  }
}

void setup() {
  // Init switch(es)
  pinMode(combo1Pin, INPUT);
  pinMode(combo2Pin, INPUT);
  pinMode(combo3Pin, INPUT);
  pinMode(combo4Pin, INPUT);
  pinMode(gearPin, INPUT);
  pinMode(sasPin, INPUT);
  pinMode(rcsPin, INPUT);
  pinMode(panicPin, INPUT);

  // Init keyboard
  //Keyboard.begin();
}

void loop() {
  // Read pins
  combo1PinState = digitalRead(combo1Pin);
  combo2PinState = digitalRead(combo2Pin);
  combo3PinState = digitalRead(combo3Pin);
  combo4PinState = digitalRead(combo4Pin);
  gearPinState = digitalRead(gearPin);
  sasPinState = digitalRead(sasPin);
  rcsPinState = digitalRead(rcsPin);
  panicPinState = digitalRead(panicPin);

  // Check pin states
  checkState(combo1PinState, combo1PinStatePrev, combo1Char);
  checkState(combo2PinState, combo2PinStatePrev, combo2Char);
  checkState(combo3PinState, combo3PinStatePrev, combo3Char);
  checkState(combo4PinState, combo4PinStatePrev, combo4Char);
  checkState(gearPinState, gearPinStatePrev, gearChar);
  checkState(sasPinState, sasPinStatePrev, sasChar);
  checkState(rcsPinState, rcsPinStatePrev, rcsChar);
  checkState(panicPinState, panicPinStatePrev, panicChar);
 

  // Update previous pin states
  combo1PinStatePrev = combo1PinState;
  combo2PinStatePrev = combo2PinState;
  combo3PinStatePrev = combo3PinState;
  combo4PinStatePrev = combo4PinState;
  gearPinStatePrev = gearPinState;
  sasPinStatePrev = sasPinState;
  rcsPinStatePrev = rcsPinState;
  panicPinStatePrev = panicPinState;

}
