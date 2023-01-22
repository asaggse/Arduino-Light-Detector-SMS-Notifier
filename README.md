# Arduino Light Detector SMS Notifier

This project uses an Arduino board with a photoresistor sensor and a GSM shield to send an SMS message when the light level detected by the sensor falls below a certain threshold.

## Hardware
- Arduino board (e.g. Arduino Uno)
- GSM shield (e.g. SIM900)
- Photoresistor sensor module
- Breadboard and jumpers

## Software
- Arduino IDE
- GSM library (included in Arduino IDE)
- Time library (included in Arduino IDE)

## Setup
1. Connect the GSM shield to the Arduino board according to the manufacturer's instructions.
2. Connect the photoresistor sensor to the Arduino board using the following connections:
   - VCC of the sensor to 5V of the Arduino board
   - GND of the sensor to GND of the Arduino board
   - DO of the sensor to a digital pin of the Arduino board (e.g. pin 2)
3. Upload the code in the file `LightDetectorSMSNotifier.ino` to the Arduino board
4. Open the Serial Monitor in the Arduino IDE and wait for the "GSM initialized" message to appear
5. Replace the `REMOTE_NUMBER` constant with the phone number that you want to receive the SMS message.
6. Replace the `SMS_MESSAGE` constant with the message that you want to send in the SMS.
7. Replace the `LIGHT_THRESHOLD` constant with the light level threshold that you want to use (default is 300).
8. Replace the `PINNUMBER` constant with your sim card pin number.

## Usage
- When the light level detected by the sensor falls below the threshold, the Arduino board will send the SMS message to thespecified phone number. The message will include the current time and date that the threshold was triggered.

You can adjust the threshold level and message to suit your needs.
The code also includes a function called readSerial() which is not currently being used in the final version of the code so it can be removed.

## Notes
Make sure your SIM card is properly inserted in the GSM shield and has credit or an active plan for sending SMS messages.
Make sure to use the correct baud rate, serial port and other settings when uploading the code to the Arduino board and when opening the Serial Monitor.
Feel free to modify and use this code as you like.

# Arduino-Light-Detector-SMS-Notifier

## Hardware

https://docs.wokwi.com/parts/wokwi-photoresistor-sensor

https://docs.arduino.cc/retired/shields/arduino-gsm-shield

<img src="https://github.com/asaggse/Arduino-Light-Detector-SMS-Notifier/blob/main/diagram.png">
