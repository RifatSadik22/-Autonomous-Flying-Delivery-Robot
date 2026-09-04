# Arduino Reference

`mission_profile.ino` is a documentation/integration reference sketch for the intended delivery mission.

It models:

`GROUND → TAKEOFF → CRUISE → DELIVERY → RETURN HOME`

It also provides serial commands for status, mission-state simulation, and payload lock/release testing.

**Important:** this is not the actual aircraft motor-control firmware. The completed prototype used MultiWii 2.4 for flight control and radio control/telemetry for operation. Autonomous GPS waypoint navigation was not completed because the GPS module was non-functional during development.
