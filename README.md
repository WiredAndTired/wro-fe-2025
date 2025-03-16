Engineering Documentation Overview 
==================================
Welcome to Wired and Tired's Engineering Documentation!
 
We are a passionate team of innovators, pushing the boundaries of robotics and technology. Our projects focus on solving real-world problems with creative engineering and automation.


About WRO 2025:
The World Robot Olympiad (WRO) is an international robotics competition that fosters innovation, critical thinking, and problem-solving skills among youth. Each year, teams design and program robots to tackle real-world challenges, gaining hands-on STEM experience and preparing for future careers in technology and engineering. 

The theme for WRO 2025 is "The Future of Robots," inviting teams to explore how robotics can address global challenges and enhance our lives. Participants will delve into areas such as reshaping future cities, expanding life across the universe, and integrating AI-enabled robots into various aspects of daily life. 

The international finals for WRO 2025 are scheduled to be held in Singapore. 






Components List of our autonomous robot and Overview:

The BTS 7960 :

The BTS 7960 is a powerful motor driver that makes controlling DC motors smooth and efficient. It's designed to handle large motors, providing up to 43A per channel, making it perfect for high-performance projects. With a wide input voltage range, it works well in many different systems, offering flexibility and adaptability. The built-in protections for overcurrent, overtemperature, and short-circuit ensure that your motor and driver stay safe, even under tough conditions. Its efficient control reduces energy use while keeping things running smoothly, making it a dependable choice for anyone needing reliable motor control in demanding applications. Just because we are using a 27ga motor which will provide more torque and will use more current that's why TB6612 is not suitable.


The BNO085:

The BNO085 is a small but powerful sensor that brings together a 3D accelerometer, gyroscope, and magnetometer in one device. It’s designed to measure motion, acceleration, and orientation with incredible accuracy, making it perfect for projects like navigation or stabilizing systems. The built-in sensor fusion algorithms help it deliver smooth, stable data without needing complex calculations, which makes it easier to work with. With its compact size, low power use, and easy integration, the BNO085 is a great choice for anyone needing precise motion tracking and orientation control in their designs.


HiskyLens:

HuskyLens is an intelligent AI vision sensor designed to simplify image processing and object recognition tasks. It comes with built-in algorithms for face recognition, object tracking, line following, QR code scanning, color detection, and more. With its pre-trained AI models, users can easily implement complex vision-based functionalities without extensive programming knowledge. 

The device features a touch screen for intuitive interaction, allowing users to quickly switch between modes and train the sensor by simply clicking and learning. HuskyLens supports multiple communication protocols like UART, I2C, and USB, making it compatible with microcontrollers such as Arduino, Raspberry Pi, and more. Its versatility and ease of use make it ideal for robotics, IoT projects, and STEM education.


27GA motor:

A 27GA motor is a small, high-performance DC motor commonly used in robotics, automation, and hobbyist projects. It belongs to the **27mm gear motor series**, where "GA" refers to the use of a gearbox for torque enhancement. These motors are compact, efficient, and often paired with planetary or spur gearboxes to provide precise torque and speed control.

Key Features:
1. **Compact Design**: Suitable for space-constrained applications.
2. **Gearbox Options**: Gear ratios vary to provide different combinations of speed and torque.
3. **Wide Voltage Range**: Operates typically between 3V and 12V, depending on the model.
4. **High Torque**: Ideal for driving wheels, actuators, or mechanical systems in robots.
5. **Durability**: Built with metal or reinforced plastic gearboxes for reliable operation.

Applications:
-Robotics**: For driving wheels or arms in small robots.
- RC Vehicles**: Used in cars, boats, and other remote-controlled devices.
- DIY Projects**: Perfect for small mechanical systems like conveyor belts, grippers, or rotating platforms.

The 27GA motor balances power and efficiency, making it a go-to choice for small and medium-scale motorized applications.



ESP32:

The ESP32 is a highly versatile microcontroller developed by Espressif Systems, featuring built-in Wi-Fi and Bluetooth for wireless connectivity. Powered by a dual-core Xtensa LX6 processor running at up to 240 MHz, it offers robust performance for IoT and embedded projects. It has multiple GPIO pins supporting protocols like I2C, SPI, UART, PWM, ADC, and DAC, allowing seamless integration with sensors, displays, and actuators.

The ESP32 includes up to 520 KB SRAM, external flash storage support, and advanced features like touch sensors, a Hall effect sensor, and temperature monitoring. With low-power modes (deep sleep, light sleep), it’s ideal for battery-operated devices. Its applications range from IoT systems and robotics to smart home devices and industrial automation, making it a go-to choice for developers seeking reliable performance and connectivity.

Why Choose ESP32?
The ESP32 stands out due to its excellent balance of performance, connectivity, and affordability. With extensive libraries and community support, it’s a versatile and beginner-friendly platform for anyone looking to innovate in the fields of IoT, robotics, or embedded systems.



Rotary Encoder:

A rotary encoder is a device that converts rotational motion into digital signals, commonly used to measure position, direction, and speed. It has two main types: **incremental**, which provides pulses for relative motion, and **absolute**, which gives a unique position code. The encoder typically outputs two signals (A and B) to detect direction and speed, with some models including a Z channel for reference points.

Rotary encoders are compact, durable, and available in various resolutions, measured by pulses per revolution (PPR). They are widely used in robotics, motor control, industrial automation, and user interfaces, like dials or knobs, to ensure precise motion tracking and control.



OLED:

A 0.96-inch OLED display is a small, low-power screen with a 128x64 pixel resolution, commonly used in embedded systems and IoT projects. It offers high contrast, vibrant colors, and wide viewing angles, making it ideal for compact devices. Typically interfaced via I2C or SPI with microcontrollers like Arduino or ESP32, it's used in wearables, robotics, and status indicators.


MG995:

The MG995 is a digital servo motor  known for its high torque and precision. It provides about 9-10 kg-cm of torque at 4.8V and operates at a speed of 0.20 seconds per 60°. It’s used in robotics, RC vehicles, and automation tasks, offering metal gears for durability. The servo is controlled via PWM signals for precise movement and position control. Two MG995 servos  can be used for simultaneous control of multiple robotic joints or mechanisms.



Ultrasonic:

The **DFRobot Ultrasonic Sensor** measures distances using ultrasonic waves. It has a range of 2 cm to 4 meters, with an accuracy of ±1 cm, and operates at 5V. It’s commonly used in robotics for obstacle avoidance and navigation. With **four sensors**, you can detect objects from different angles for better spatial awareness. It’s easy to integrate with microcontrollers like Arduino or ESP32.



Servo Driver:

A servo driver (I2C protocol) is a device that controls multiple servos using the I2C communication protocol, which requires only two wires (SCL and SDA) for communication. It can manage up to 16 or more servos simultaneously, reducing the number of GPIO pins required on the microcontroller. The driver sends PWM signals to the servos, providing precise control over their positions. This is ideal for projects involving multiple servos, such as robotics, automation, or animatronics, as it simplifies wiring and saves microcontroller resources. The power supply for the servos is typically separate from the microcontroller to prevent overloading.


Mini Buck Converter:

A mini buck converter is a compact DC-DC step-down voltage regulator that efficiently reduces a higher input voltage to a lower, stable output voltage. It operates using pulse-width modulation (PWM) to control the switching of transistors, ensuring minimal energy loss. The mini version is typically smaller, offering flexibility in space-constrained projects. Commonly used in battery-powered devices, IoT projects, and robotics, it is known for its high efficiency, typically around 80-90%, and its ability to handle a wide input voltage range while providing consistent output voltage.


Mini Boost Converter:

 A mini boost converter is a small DC-DC step-up voltage regulator that increases a lower input voltage to a higher, stable output voltage. It works by storing energy in an inductor and releasing it at a higher voltage using pulse-width modulation (PWM). Compact in design, it’s ideal for applications with limited space, such as portable devices, robotics, and IoT projects. Mini boost converters are efficient, typically offering 80-90% efficiency, and can handle a wide range of input voltages while providing a consistent, regulated output.



5V Converter:

A constant 5V converter is a power supply that provides a stable 5V output regardless of variations in the input voltage or load. It can either step down (buck converter) or step up (boost converter) the input voltage to maintain a consistent 5V output. These converters are commonly used in projects that require a reliable 5V power source, such as powering microcontrollers, sensors, or communication modules in electronics, robotics, and IoT applications. They are designed for high efficiency, ensuring minimal energy loss while maintaining a stable output voltage.


LIPO:

A LiPo (Lithium Polymer) 11.1V battery is a rechargeable battery commonly used in robotics, drones, and other electronic projects. It typically consists of three cells (3S configuration), each providing 3.7V, which when connected in series gives a total voltage of 11.1V. LiPo batteries are known for their lightweight design, high energy density, and ability to deliver high discharge currents, making them ideal for applications requiring powerful, compact energy sources. They also have a relatively low self-discharge rate, but require careful handling and charging to ensure safety and longevity.


Encoder Geared Motor:

An encoder geared motor is a motor with an integrated encoder and a gear system. The encoder tracks the motor's position, speed, and direction, providing feedback to control systems, which helps in precise movement control. The gear system reduces the motor's speed while increasing its torque, making it ideal for applications needing high power at low speeds, such as robotics and automation. These motors are commonly used in tasks requiring accurate positioning, like robotic arms, wheeled robots, and conveyor systems. They combine the benefits of precise feedback and high torque in a compact design.




