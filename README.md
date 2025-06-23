# Autonomous-Car

This project implements a simple line-following robot using an Arduino microcontroller, three photoresistor, and two DC motors controlled via an H-bridge driver. The robot follows a black line on a white surface by reading sensor inputs and adjusting motor speeds and directions accordingly.

---

## Project Aim

To build an autonomous vehicle that can follow a line by detecting it with sensors and adjusting its motion in real time. The project demonstrates the fundamentals of robotics, embedded systems, and sensor-based control.

---

## Components

- Arduino Uno (or compatible board)  
- 3 LDR line (Left, Middle, Right)  
- 2 DC motors with motor driver (l293D)  
- Power supply (battery)  
- Vehicle  
- Wires and basic electronic components  

---

## How It Works

The robot uses three photoresistor to detect the presence of a black line. Based on the sensor states, the Arduino decides whether to move forward, turn left, turn right, or stop.

### Sensor Logic

| Sensor Readings          | Action       |
|-------------------------|--------------|
| LS=LOW, MS=LOW, RS=LOW  | Stop         |
| LS=LOW, RS=HIGH          | Turn Left    |
| LS=HIGH, RS=LOW          | Turn Right   |
| LS=HIGH, MS=LOW, RS=HIGH| Move Forward |

### Motor Control

- Motors are controlled via an H-bridge using digital pins for direction and PWM pins for speed control.
- Speed is adjusted using `analogWrite()` to the motor enable pins.
- Direction pins (`LM1`, `LM2` for left motor; `RM1`, `RM2` for right motor) are set high or low depending on desired movement.

---

### L293D Connections

| L293D Pin             | Connection                         |
|-----------------------|-------------------------------------|
| Power 1               | +9V                                |
| Input 4               | Pin 8                              |
| Output 4              | Right Motor positive terminal      |
| Ground                | Ground of 9V                       |
| Output 3              | Right Motor negative terminal      |
| Input 3               | Pin 9                              |
| Enable 3+4            | Pin 10                             |
| Power 2               | +9V                                |
| Input 2               | Pin 13                             |
| Output 2              | Left Motor negative terminal       |
| Ground                | Ground of 9V                       |
| Output 1              | Left Motor positive terminal       |
| Input 1               | Pin 12                             |
| Enable 1+2            | Pin 11                             |

### Photoresistor Connections

| Sensor          | Connection |
|-----------------|------------|
| Left sensor     | Pin 6      |
| Middle sensor   | Pin 5      |
| Right sensor    | Pin 4      |

