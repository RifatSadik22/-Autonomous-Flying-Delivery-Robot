# Project Status & Lessons Learned

## What we successfully demonstrated

- A working aerial platform based on an Arduino Mega 2560 and MultiWii 2.4.
- Radio-controlled flight and radio telemetry.
- Payload transportation.
- A working ESP32 + servo payload-lock mechanism.
- Flight at approximately 18 m during demonstration.

## What was not completed

- Autonomous GPS waypoint navigation.
- Ultrasonic obstacle detection.
- Compass integration.
- Bluetooth integration.

The GPS module was non-functional during development, which prevented the planned autonomous navigation feature.

## Hardware incident

During testing, one of the drone's propeller fans was broken. This became one of the practical lessons of the project: aerial robotics requires careful testing, inspection, and replacement planning for mechanical components.

## Future work

- More reliable GPS integration.
- Pixhawk-based flight controller.
- Autonomous waypoint navigation.
- Obstacle avoidance.
- Higher payload capacity.
- Smarter navigation and perception.
