Engineering Documentation Overview 
==================================
Welcome to Wired and Tired's Engineering Documentation!
 
We are a passionate team of innovators, pushing the boundaries of robotics and technology. Our projects focus on solving real-world problems with creative engineering and automation.




About WRO 2025:
The World Robot Olympiad (WRO) is an international robotics competition that fosters innovation, critical thinking, and problem-solving skills among youth. Each year, teams design and program robots to tackle real-world challenges, gaining hands-on STEM experience and preparing for future careers in technology and engineering. 

The theme for WRO 2025 is "The Future of Robots," inviting teams to explore how robotics can address global challenges and enhance our lives. Participants will delve into areas such as reshaping future cities, expanding life across the universe, and integrating AI-enabled robots into various aspects of daily life. 

The international finals for WRO 2025 are scheduled to be held in Singapore. 










Components List of our autonomous robot and Overview:


HuskyLens:

HuskyLens is an intelligent AI vision sensor designed to simplify image processing and object recognition tasks. It comes with built-in algorithms for face recognition, object tracking, line following, QR code scanning, color detection, and more. With its pre-trained AI models, users can easily implement complex vision-based functionalities without extensive programming knowledge. 

The device features a touch screen for intuitive interaction, allowing users to quickly switch between modes and train the sensor by simply clicking and learning. HuskyLens supports multiple communication protocols like UART, I2C, and USB, making it compatible with microcontrollers such as Arduino, Raspberry Pi, and more. Its versatility and ease of use make it ideal for robotics, IoT projects, and STEM education.





Rotary Encoder:

A rotary encoder is a device that converts rotational motion into digital signals, commonly used to measure position, direction, and speed. It has two main types: **incremental**, which provides pulses for relative motion, and **absolute**, which gives a unique position code. The encoder typically outputs two signals (A and B) to detect direction and speed, with some models including a Z channel for reference points.

Rotary encoders are compact, durable, and available in various resolutions, measured by pulses per revolution (PPR). They are widely used in robotics, motor control, industrial automation, and user interfaces, like dials or knobs, to ensure precise motion tracking and control.



MG995:

The MG995 is a digital servo motor  known for its high torque and precision. It provides about 9-10 kg-cm of torque at 4.8V and operates at a speed of 0.20 seconds per 60°. It’s used in robotics, RC vehicles, and automation tasks, offering metal gears for durability. The servo is controlled via PWM signals for precise movement and position control. Two MG995 servos  can be used for simultaneous control of multiple robotic joints or mechanisms.






Servo Driver:

A servo driver (I2C protocol) is a device that controls multiple servos using the I2C communication protocol, which requires only two wires (SCL and SDA) for communication. It can manage up to 16 or more servos simultaneously, reducing the number of GPIO pins required on the microcontroller. The driver sends PWM signals to the servos, providing precise control over their positions. This is ideal for projects involving multiple servos, such as robotics, automation, or animatronics, as it simplifies wiring and saves microcontroller resources. The power supply for the servos is typically separate from the microcontroller to prevent overloading.


Mini Buck Converter:

A mini buck converter is a compact DC-DC step-down voltage regulator that efficiently reduces a higher input voltage to a lower, stable output voltage. It operates using pulse-width modulation (PWM) to control the switching of transistors, ensuring minimal energy loss. The mini version is typically smaller, offering flexibility in space-constrained projects. Commonly used in battery-powered devices, IoT projects, and robotics, it is known for its high efficiency, typically around 80-90%, and its ability to handle a wide input voltage range while providing consistent output voltage.


Mini Boost Converter:

 A mini boost converter is a small DC-DC step-up voltage regulator that increases a lower input voltage to a higher, stable output voltage. It works by storing energy in an inductor and releasing it at a higher voltage using pulse-width modulation (PWM). Compact in design, it’s ideal for applications with limited space, such as portable devices, robotics, and IoT projects. Mini boost converters are efficient, typically offering 80-90% efficiency, and can handle a wide range of input voltages while providing a consistent, regulated output.



5V Converter:

A constant 5V converter is a power supply that provides a stable 5V output regardless of variations in the input voltage or load. It can either step down (buck converter) or step up (boost converter) the input voltage to maintain a consistent 5V output. These converters are commonly used in projects that require a reliable 5V power source, such as powering microcontrollers, sensors, or communication modules in electronics, robotics, and IoT applications. They are designed for high efficiency, ensuring minimal energy loss while maintaining a stable output voltage.


TB6612FNG

The TB6612FNG is a dual motor driver IC that can control two DC motors with forward, reverse, brake, and stop functions. It uses an H-bridge design and is capable of delivering up to 1.2A continuous current per channel (3.2A peak). It operates over a wide voltage range (2.5V–13.5V) and supports PWM control for precise motor speed management.

Main Features:

Dual H-bridge motor driver

1.2A continuous output current (3.2A peak)

Separate motor and logic power supply pins

Built-in thermal shutdown and overcurrent protection

Compatible with microcontrollers like Arduino and Raspberry Pi




MPU6050 + HMC5883L (Kalman Filter)

The MPU6050 is a 6-axis IMU (3-axis gyroscope + 3-axis accelerometer) and the HMC5883L is a 3-axis magnetometer. Combined, they provide a 9-axis orientation solution. When processed using a Kalman filter, sensor fusion is achieved for accurate and stable angle, tilt, and heading detection.

Main Features:

9-DOF motion tracking (acceleration, rotation, magnetic heading)

Kalman filter improves precision by reducing noise

Ideal for robotics, navigation, and gesture-based interfaces

I2C interface for easy integration

Small form factor and low power consumption



N20 Motor

The N20 motor is a small, high-precision gear motor that provides a balance between torque and speed. It is widely used in robotics and compact automation projects due to its low weight and versatile voltage compatibility (3V–12V).

Main Features:

Micro DC gear motor with high torque

Available in various gear ratios (e.g., 30:1, 50:1, 100:1)

Quiet and efficient operation

Suitable for tracked robots, actuators, and drive systems

Durable metal gearbox



TTGO

The TTGO board is a series of development boards, typically built around the ESP32 microcontroller, featuring Wi-Fi and Bluetooth connectivity. Most models include additional features such as OLED displays, LoRa modules, or battery connectors, making them suitable for IoT applications.

Main Features:

Powered by ESP32 (dual-core, 240MHz, Wi-Fi + BLE)

Built-in OLED screen (varies by model)

Low-power consumption for IoT use

Multiple GPIO pins and communication interfaces (I2C, SPI, UART)

Supports Arduino IDE and MicroPython




TTGO OLED

A TTGO OLED module refers to the integrated display in TTGO boards, typically a 0.96" 128x64 pixel OLED using the SSD1306 driver over I2C. It is used to display real-time data, debugging messages, or graphical indicators in compact embedded systems.

Main Features:

0.96" 128x64 monochrome OLED

I2C communication (SCL/SDA)

Ultra-low power consumption

Sharp, high-contrast visuals

Easy integration with ESP32 boards




MG90S

The MG90S is a micro servo motor with metal gears, offering higher durability and torque than plastic-geared counterparts. It operates on 4.8V–6V and is ideal for lightweight robotics and pan-tilt mechanisms.

Main Features:

Metal gears for durability and strength

1.8kg·cm torque at 4.8V

Fast response and precise positioning

180-degree rotation (PWM-controlled)

Compact and lightweight




URM09

The URM09 is an ultrasonic distance sensor with UART/I2C interface, offering high-accuracy range detection. It measures distances by emitting ultrasonic pulses and calculating echo times.

Main Features:

Range: 2cm to 500cm with high accuracy

I2C and UART interface options

Built-in temperature compensation

Ideal for obstacle detection and avoidance

Compact and reliable design






Now, Let's see what we made with these equipments:

Drumroll please we are thrilled to show our robot:

Formal Photo:

![WhatsApp Image 2025-07-03 at 21 41 14](https://github.com/user-attachments/assets/1febe9b8-db15-4f7f-99d9-bdaf99a60ea1)

Equipments Specification:
![Electronic Components Breakdown](https://github.com/user-attachments/assets/336301b2-dd44-4e25-a874-e8060a81f894)


