# Line-Following Robot

This project implements a simple line-following robot using an Arduino microcontroller, three infrared (IR) sensors, and two DC motors controlled via an H-bridge driver. The robot follows a black line on a white surface by reading sensor inputs and adjusting motor speeds and directions accordingly.

---

## Project Aim

To build an autonomous vehicle that can follow a line by detecting it with sensors and adjusting its motion in real time. The project demonstrates the fundamentals of robotics, embedded systems, and sensor-based control.

---

## Components

- Arduino Uno (or compatible board)  
- 3 IR line sensors (Left, Middle, Right)  
- 2 DC motors with motor driver (e.g., L298N)  
- Power supply (battery)  
- Chassis and wheels  
- Connecting wires and basic electronic components  

---

## How It Works

The robot uses three IR sensors to detect the presence of a black line. Based on the sensor states, the Arduino decides whether to move forward, turn left, turn right, or stop.

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

## Pin Configuration

| Component          | Arduino Pin |
|--------------------|-------------|
| Left Sensor (LS)   | 6           |
| Middle Sensor (MS) | 5           |
| Right Sensor (RS)  | 4           |
| Left Motor (LM1)   | 12          |
| Left Motor (LM2)   | 13          |
| Left Motor Enable (enL) | 11      |
| Right Motor (RM1)  | 9           |
| Right Motor (RM2)  | 8           |
| Right Motor Enable (enR) | 10      |
