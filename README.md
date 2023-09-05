# MCC_Robotic_Hand

## Transmitter
The Transmitter code is responsible for the debounced button logic that waits for the user to start the sequence after powering on. It allows the user to toggle between what mode they want to have active from the glove. (Either user control ON or OFF)
The analog flex sensor values are read in and then mapped to servo values that have been calibrated to each finger on the glove. 
These Values are then sent via the RF24 radio module in an array with an extra element to indicate which mode is active.

## Receiver
The receiver code is responsible for the receiving values sent from the glove transmitter via the RF24 radio. These values drive the servos and depending on which mode is active, and will run through a pre-programmed sequence.

## LCD Display
The LCD Display code shows the startup sequence and will provide live feedback of all Servo rotation values with its own RF24 receiver. The LCD will provide feedback based on which mode is active or if there is some kind of wireless connection error.
