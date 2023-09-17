# Welcome to my Summer 23' Engineering Project!
Over the past 3 months, 2 other Computer Engineering students and I started designing, prototyping, and building a wireless gesture-controlled robotic hand with multiple functions and a screen with a live feedback display. It fully consists of 3D-printed parts that we designed in Solidworks that house the hardware and microcontrollers responsible for controlling the servos in the hand as well the LCD screen. It also includes a custom wearable glove with flex sensors on each finger integrated into a circuit controlled by an Arduino Nano with a radio transmitter. The user has the ability to control the robotic hand with the glove so their motions are mirrored by the robot. The user will also have the ability to toggle between modes wirelessly and have the robot run through some pre-programmed gestures. This will occur while the LCD provides live feedback of which mode is active, all of the servo rotation values, and error handling if there is an issue with the wireless connection.
This project is split into 3 main components described below.

## Transmitter
The Transmitter code is responsible for the debounced button logic that waits for the user to start the sequence after powering on. It allows the user to toggle between what mode they want to have active from the glove. (Either user control ON or OFF)
The analog flex sensor values are read in and then mapped to servo values that have been calibrated to each finger on the glove. 
These Values are then sent via the RF24 radio module in an array with an extra element to indicate which mode is active.

## Receiver
The receiver code is responsible for the receiving values sent from the glove transmitter via the RF24 radio. These values drive the servos and depending on which mode is active, and will run through a pre-programmed sequence.

## LCD Display
The LCD Display code shows the startup sequence and will provide live feedback of all Servo rotation values with its own RF24 receiver. The LCD will provide feedback based on which mode is active or if there is some kind of wireless connection error.

<p align="center">
  <a href="https://youtube.com/shorts/nZMyS09LJu8?feature=share">
    <img src="download.png" alt="Watch the video" />
  </a>
</p>

<p align="center">Here is a video to watch a live demo </p>
