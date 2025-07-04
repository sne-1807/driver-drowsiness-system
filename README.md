# Driver Drowsiness System 

## Aim
To develop a low-cost embedded system that detects driver drowsiness using eye-blink monitoring and provides immediate alerts to driver, while enabling remote tracking of activity through IoT for enhanced road and industrial safety.

## Summary of Design
- Utilizes an ESP8266 microcontroller with an infrared eye-blink sensor to detect prolonged eye closures.
- Triggers a buzzer alert when drowsiness is detected to immediately warn the driver.
- Publishes events with timestamps to ThingSpeak, enabling cloud-based monitoring and CSV data logging.
- Powered by a 9V supply regulated to 5V using an LM7805 circuit, ensuring stable operation.

## Result
The system successfully detects abnormal eye closures and activates audible alerts, and logs each drowsiness event to ThingSpeak with real-time timestamps, exportable as CSV for analysis. Thus this project provides a scalable foundation for integration into industrial fleets or commercial vehicles.
