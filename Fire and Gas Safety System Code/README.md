# Fire and Gas Safety System

This project aims to build a **Fire and Gas Safety System** that continuously monitors the environment for potential hazards such as fire and gas leaks. The system uses a set of sensors to detect flames, smoke, and light intensity, and triggers alerts when dangerous conditions are detected. A buzzer sound and visual indication through a servo motor are provided as warnings to ensure the safety of the environment.

## Features:
- **Fire Detection**: Detects the presence of flames using a flame sensor (KY-026) and triggers an alarm when fire is detected.
- **Gas Leak Detection**: Measures the concentration of gases such as methane or carbon monoxide using a smoke sensor (MQ-2) and alerts the user when dangerous levels of gas are detected.
- **Light Intensity Monitoring**: The system reads light levels through an LDR (Light Dependent Resistor) sensor and can potentially adjust its behavior based on environmental lighting conditions.
- **Visual and Audio Alerts**: Provides both visual feedback (servo motor movement) and audio alerts (buzzer sound) in response to fire or gas detection.
- **Arduino Controlled**: The entire system is controlled using an Arduino, processing sensor data and controlling the outputs.
