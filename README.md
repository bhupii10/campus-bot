# campus-bot
# CampusBot – Autonomous Smart Delivery Robot

## Overview

CampusBot is a line-following autonomous delivery robot designed for smart campuses.
It combines vision-based decision-making with a mechanical delivery system to transport and deliver parcels without human intervention.

---

## Problem

In campuses and institutions, small deliveries such as documents, items, and lab materials:

* Consume time
* Require manual effort
* Are repetitive and inefficient

---

## Solution

CampusBot addresses this using:

* Line-following navigation
* Vision-based decision system
* Automated delivery mechanism
* Return-to-path intelligence

---

## How It Works

### Workflow

1. Robot follows a black line
2. When all IR sensors detect black → stop
3. MU Vision detects card:

   * Right card → delivery
   * Other directions → continue path
4. Robot moves right to delivery zone
5. When all sensors detect white → stop
6. Delivery process:

   * Servo opens gate
   * Lift motor raises tray
   * Wait for 3 seconds
   * Tray lowers
   * Gate closes
7. Robot returns to line
8. Resumes line following

---

## System Architecture

### Hardware

* Arduino Uno
* L293D Motor Shield (AFMotor)
* 4 DC Motors (Omni / Mecanum wheels)
* 5-channel analog IR sensors
* MU Vision Sensor (traffic card detection)
* Servo motor (gate control)
* L298N motor driver (lift system)
* N20 gear motor (tray lift)
* Buzzer
* Battery pack

---

### Software Logic

State-based control system:

| Mode | Description        |
| ---- | ------------------ |
| 0    | Line following     |
| 1    | Stop and scan card |
| 2    | Move to delivery   |
| 3    | Delivery execution |
| 4    | Return to line     |

---

## Key Features

* Stable line-following behavior
* Vision-based routing without GPS
* Automated parcel delivery system
* Return-to-track capability
* Low-cost and scalable design

---

## Challenges and Solutions

| Challenge              | Solution                 |
| ---------------------- | ------------------------ |
| Sensor noise           | Threshold tuning (~300)  |
| Unstable movement      | Rule-based control       |
| Servo jitter           | Attach/detach control    |
| MU Vision interference | Trigger-based usage      |
| Motor inconsistency    | Speed calibration (~110) |

---

## Technical Highlights

* Analog IR-based detection system
* Real-time decision-making using vision
* Hybrid motor control (motor shield + L298N)
* State machine-based execution

---

## Feedback System

* Beep on stop detection
* Continuous beep during lift
* Delivery completion sound

---

## Future Improvements

* Multi-destination delivery
* Mobile app integration
* AI-based object detection
* Cloud monitoring
* Battery optimization

---

## Applications

* College campuses
* Office automation
* Hospitals (sample delivery)
* Warehouses

---

## Conclusion

CampusBot demonstrates how simple hardware combined with structured control logic can create an effective automation system.

It is practical, competition-ready, and scalable for real-world applications.

