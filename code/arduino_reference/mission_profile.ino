/*
 * Autonomous Flying Delivery Robot
 * CSE461 - Introduction to Robotics
 * BRAC University | Group 07 | Section 06
 *
 * Arduino Mega 2560 - Mission Profile / Integration Reference
 * ------------------------------------------------------------
 * This sketch is a documentation/reference implementation.
 * It does NOT directly control the aircraft motors or replace
 * MultiWii 2.4 flight-control firmware.
 *
 * The completed prototype was operated using radio control and
 * telemetry. GPS waypoint navigation was not completed because
 * the GPS module was non-functional during development.
 *
 * Serial commands:
 *   S = show system status
 *   T = simulate takeoff state
 *   F = simulate flight state
 *   D = simulate delivery state
 *   H = simulate return/home state
 *   L = request payload lock
 *   R = request payload release
 *   X = reset to ground state
 */

enum MissionState {
  GROUND,
  TAKEOFF,
  CRUISE,
  DELIVERY,
  RETURN_HOME
};

MissionState state = GROUND;
bool payloadLocked = true;
unsigned long missionStart = 0;

const char* stateName(MissionState s) {
  switch (s) {
    case GROUND:      return "GROUND";
    case TAKEOFF:     return "TAKEOFF";
    case CRUISE:      return "CRUISE / FLIGHT";
    case DELIVERY:    return "DELIVERY";
    case RETURN_HOME: return "RETURN HOME";
    default:          return "UNKNOWN";
  }
}

void printStatus() {
  Serial.println("\n========== SYSTEM STATUS ==========");
  Serial.print("Controller: Arduino Mega 2560\n");
  Serial.print("Flight firmware: MultiWii 2.4\n");
  Serial.print("Mission state: ");
  Serial.println(stateName(state));
  Serial.print("Payload: ");
  Serial.println(payloadLocked ? "LOCKED" : "RELEASED");
  Serial.print("Mission timer (ms): ");
  Serial.println(missionStart == 0 ? 0 : millis() - missionStart);
  Serial.println("===================================");
}

void setState(MissionState nextState) {
  state = nextState;
  if (nextState == TAKEOFF && missionStart == 0) {
    missionStart = millis();
  }

  Serial.print("MISSION -> ");
  Serial.println(stateName(state));
}

void lockPayload() {
  payloadLocked = true;
  Serial.println("PAYLOAD COMMAND -> LOCK");
}

void releasePayload() {
  payloadLocked = false;
  Serial.println("PAYLOAD COMMAND -> RELEASE");
}

void resetMission() {
  state = GROUND;
  payloadLocked = true;
  missionStart = 0;
  Serial.println("MISSION RESET -> GROUND / PAYLOAD LOCKED");
}

void setup() {
  Serial.begin(115200);

  Serial.println("===========================================");
  Serial.println(" AUTONOMOUS FLYING DELIVERY ROBOT");
  Serial.println(" Arduino Mega 2560 Mission Profile");
  Serial.println("===========================================");
  Serial.println("Reference/integration sketch only.");
  Serial.println("MultiWii remains the flight-control firmware.");
  Serial.println();
  Serial.println("Commands: S T F D H L R X");

  resetMission();
}

void loop() {
  if (!Serial.available()) {
    return;
  }

  char command = Serial.read();

  switch (command) {
    case 'S': case 's':
      printStatus();
      break;

    case 'T': case 't':
      setState(TAKEOFF);
      break;

    case 'F': case 'f':
      setState(CRUISE);
      break;

    case 'D': case 'd':
      setState(DELIVERY);
      break;

    case 'H': case 'h':
      setState(RETURN_HOME);
      break;

    case 'L': case 'l':
      lockPayload();
      break;

    case 'R': case 'r':
      releasePayload();
      break;

    case 'X': case 'x':
      resetMission();
      break;

    case '\n': case '\r':
      break;

    default:
      Serial.println("Unknown command. Use S,T,F,D,H,L,R,X.");
      break;
  }
}
