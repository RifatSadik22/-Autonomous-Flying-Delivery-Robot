/*
 * Autonomous Flying Delivery Robot
 * CSE461 - Introduction to Robotics
 *
 * Payload Lock Controller
 *
 * Reference implementation for the ESP32 + servo payload-lock subsystem.
 * This sketch demonstrates the lock/release logic and is not a replacement
 * for the MultiWii flight-control firmware used by the aircraft.
 */

#include <Servo.h>

Servo payloadServo;

const int SERVO_PIN = 18;
const int RELEASE_BUTTON = 4;

const int LOCK_POSITION = 0;
const int RELEASE_POSITION = 90;

bool payloadLocked = true;

void lockPayload() {
  payloadServo.write(LOCK_POSITION);
  payloadLocked = true;
  Serial.println("PAYLOAD: LOCKED");
}

void releasePayload() {
  payloadServo.write(RELEASE_POSITION);
  payloadLocked = false;
  Serial.println("PAYLOAD: RELEASED");
}

void setup() {
  Serial.begin(115200);

  payloadServo.attach(SERVO_PIN);
  pinMode(RELEASE_BUTTON, INPUT_PULLUP);

  // Safe startup state
  lockPayload();

  Serial.println("--------------------------------");
  Serial.println("Autonomous Delivery Robot");
  Serial.println("Payload Lock Controller");
  Serial.println("--------------------------------");
}

void loop() {
  // Button for local testing
  if (digitalRead(RELEASE_BUTTON) == LOW) {
    if (payloadLocked) {
      releasePayload();
    }
    delay(500);
  }

  // Serial commands:
  // L = lock
  // R = release
  if (Serial.available()) {
    char command = Serial.read();

    switch (command) {
      case 'L':
      case 'l':
        lockPayload();
        break;

      case 'R':
      case 'r':
        releasePayload();
        break;

      default:
        Serial.println("Unknown command. Use L = Lock, R = Release.");
        break;
    }
  }
}
