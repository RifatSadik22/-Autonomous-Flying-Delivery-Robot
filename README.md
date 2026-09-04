# Autonomous Flying Delivery Robot 
### CSE461 — Introduction to Robotics | BRAC University

An academic aerial delivery robot prototype designed to transport lightweight emergency supplies to hard-to-reach areas.

> **Project-status note:** Despite the project title, the completed prototype did **not** achieve autonomous GPS waypoint navigation. The team demonstrated radio-controlled flight, telemetry, payload transportation, and a working ESP32 + servo payload-lock mechanism. The GPS module was non-functional during development, while ultrasonic, compass, and Bluetooth integrations were not completed within the project timeframe.

## Project Overview

Emergency situations such as floods and disasters can make conventional ground-based delivery difficult or unsafe. This project explored an aerial platform for emergency logistics, especially for flooded or remote areas where terrestrial delivery may be difficult.

The system was built around an **Arduino Mega 2560** with **MultiWii 2.4** as the flight-control architecture. A separate **ESP32 + servo** subsystem was used for the payload-lock mechanism.

## Objectives

- Build a functional aerial delivery platform.
- Integrate motors, ESCs, propellers, frame, battery and power distribution.
- Explore GPS, compass and Bluetooth integration for waypoint navigation.
- Explore ultrasonic sensing for obstacle detection and altitude-related functionality.
- Maintain stable flight using accelerometer/gyroscope sensing through the flight-control system.
- Implement a secure payload lock/release mechanism.
- Reduce human involvement and risk during emergency delivery scenarios.

## What We Actually Demonstrated

| Feature | Status |
|---|---|
| Aerial flight platform | ✅ Demonstrated |
| Motor/ESC integration | ✅ Demonstrated |
| Radio-controlled flight | ✅ Demonstrated |
| Radio telemetry | ✅ Demonstrated |
| Payload transportation | ✅ Demonstrated |
| ESP32 + servo payload lock | ✅ Working |
| GPS waypoint navigation | ❌ Not completed |
| Autonomous navigation | ❌ Not completed |
| Ultrasonic obstacle detection | ❌ Not integrated |
| Compass integration | ❌ Not integrated |
| Bluetooth integration | ❌ Not integrated |

The report records a flight demonstration at approximately **18 m**.

## System Architecture

```text
                    +----------------------+
                    |   Radio Controller    |
                    +----------+-----------+
                               |
                               v
+----------------+     +----------------------+     +----------------+
| GPS / Planned  |---->| Arduino Mega 2560   |---->| MultiWii 2.4   |
| Navigation     |     | Main Interface      |     | Flight Control |
+----------------+     +----------+-----------+     +-------+--------+
                                  |                         |
                                  |                         v
                                  |                  ESCs + Motors
                                  |
                                  v
                         +------------------+
                         | ESP32 + Servo    |
                         | Payload Lock     |
                         +--------+---------+
                                  |
                                  v
                           Delivery Box
```

## Hardware

- Arduino Mega 2560
- MultiWii 2.4 flight-control firmware
- Brushless motors
- ESCs
- Propellers
- LiPo battery
- Radio receiver
- Telemetry module
- GPS module
- Accelerometer/gyroscope sensors
- ESP32
- Servo motor
- Delivery box
- Planned: compass and ultrasonic sensor

See [`hardware/components.md`](hardware/components.md) for the component/status table.

## Code

### Arduino Mega 2560 Reference

[`code/arduino_reference/mission_profile.ino`](code/arduino_reference/mission_profile.ino) is a repository reference sketch that models the intended mission flow:

`GROUND → TAKEOFF → CRUISE → DELIVERY → RETURN HOME`

It also models payload lock/release commands.

**Important:** this is not the aircraft's actual motor-control firmware. The project used **MultiWii 2.4** for flight control. The completed prototype was controlled through radio control/telemetry, while autonomous GPS waypoint navigation was not completed.

### Payload Lock

[`code/payload_lock/payload_lock.ino`](code/payload_lock/payload_lock.ino) contains the ESP32 + servo payload-lock reference implementation. It supports lock/release testing through a push button or serial commands.

### MultiWii

The aircraft's flight-control architecture used **MultiWii 2.4** with the Arduino Mega 2560. The original MultiWii firmware is not reproduced here; the repository documents the configuration and project status instead.

## Testing & Challenges

Aerial robotics involved significant hands-on assembly and testing. **During testing, we broke one of the drone's propeller fans.** This became an important practical lesson about mechanical inspection, safe test procedures and keeping spare components available.

Other major challenges included the non-functional GPS module and limited time for integrating the planned ultrasonic, compass and Bluetooth subsystems.

## Sustainability & Impact

The project was motivated by emergency delivery scenarios such as floods, disasters and remote-area logistics. The report notes a minimal carbon footprint for the prototype, with battery waste identified as a sustainability concern.

## Future Work

- Complete reliable GPS integration.
- Implement true autonomous waypoint navigation.
- Add obstacle avoidance.
- Move toward a Pixhawk-based flight controller.
- Improve payload capacity and safety mechanisms.
- Explore smarter perception/navigation methods.

## Documentation
- 📋 [Project status and lessons learned](PROJECT_STATUS.md)

## Academic Project

This repository documents the team's academic robotics project, including the report, poster, hardware overview, project-status notes, and reference Arduino code.
