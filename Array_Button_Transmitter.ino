//** This will be code for the transmitter

#include <RF24.h>
#include <RF24_config.h>
#include <nRF24L01.h>
#include <printf.h>

// Initialize Radio Data

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";
const int flexPin1 = A1;
const int flexPin2 = A2;
const int ARRAY_SIZE = 2;
int flex1, flex2;

int msg[2];

// Initialize Button Data

const int buttonPin = 2;  // Pin connected to the push button
const int ledPin = 13;    // Pin connected to the LED

int buttonState;
int lastButtonState = LOW;
int modeSelect = 1;       // Current mode: 0 for mode 1, 1 for mode 2

bool debounceActive = false;  // Flag to track if button debouncing is active
bool initialButtonChange = false;  // Flag to track the initial button state change

unsigned long lastModeChange = 0;  // Timestamp of the last mode change
unsigned long debounceDelay = 100; // Debounce delay in milliseconds


void setup() {

  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  pinMode(buttonPin, INPUT); 
  pinMode(ledPin, OUTPUT);          
  Serial.println("Start Test");

}

void loop() {
  int buttonState = digitalRead(buttonPin);  // Read the current state of the button

  if (!initialButtonChange) {
    if (buttonState != lastButtonState) {
      lastButtonState = buttonState;
      if (buttonState == HIGH) {
        initialButtonChange = true;  // Button state changed for the first time, set initialButtonChange to true
      }
    }
    return; // Skip the rest of the loop until initial button change occurs
  }

  if (buttonState != lastButtonState) {
    lastButtonState = buttonState;
    if (buttonState == HIGH && debounceActive == false) {
      changeMode();                      // Button pressed, change the mode
      lastModeChange = millis();         // Record the timestamp of mode change
      debounceActive = true;             // Activate button debouncing
    }
  }

  if ((millis() - lastModeChange) > debounceDelay) {
    debounceActive = false;  // Disable button debouncing after debounceDelay
  }

  if (modeSelect == 0) {
    mode1();  // Execute mode 1 functionality
  } else {
    mode2();  // Execute mode 2 functionality
  }
}

void changeMode() {
  if (modeSelect == 0) {
    modeSelect = 1;  // Toggle mode from 0 to 1
  } else {
    modeSelect = 0;  // Toggle mode from 1 to 0
  }
}

void mode1() {  // Glove Control Mode

  digitalWrite(ledPin, HIGH);  // Turn on the LED
  //Serial.println("LED is on");

  // Transmitter Code
  flex1 = analogRead(flexPin1);
  flex1 = map(flex1, 741, 870, 0, 129); // THUMB
  flex1 = constrain(flex1, 0, 180);

  flex2 = analogRead(flexPin2);
  flex2 = map(flex2, 832, 935, 0, 103); // MIDDLE
  flex2 = constrain(flex2, 0, 180);

  msg[0] = flex1;
  msg[1] = flex2;

  radio.write(&msg, sizeof(msg));

  Serial.println("THUMB: " + String(msg[0]));
  Serial.println("MIDDLE: " + String(msg[1]));
  delay(500);    //***************************************ADJUST DELAY

}


void mode2() {  // Preset Gesture Mode

  digitalWrite(ledPin, LOW);  // Turn off the LED
  Serial.println("LED is off");

  //*** Set msg[] variable to preset motions and send them -- receiver code will run normally

}