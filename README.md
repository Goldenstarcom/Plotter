

## Intro :
Introduction Robots of the future are a symbol of the combination of art and technology, tools that can accurately and beautifully map and create designs. In this project, inspired by the structure of serial robots like **Makelangelo**, a two-dimensional design robot has been developed using advanced design software such as **Rhino** and **Grasshopper**, as well as custom coding, to provide the ability to create sophisticated designs. The goal of this documentary is to provide a comprehensive and step-by-step guide to the design, construction, and operation of the robot. It not only explains the hardware and software components but also details how the robot interacts with digital designs. With the help of this guide, not only can you understand the operational mechanism of the robot, but also the possibility of redesigning or improving the design for similar projects is provided. This design robot emphasizes precision, personalization, and integration with advanced digital design tools, and can have a wide range of applications in educational, artistic, and industrial fields.


##  Components of the Design Robot  :
   The design robot of this project consists several main components, each one plays a key role in its overall performance. These components include mechanical hardware, electronic components, and software systems. Each of these components and their functions are detailed below :   

### 1 . Mechanical Components  :

* **Frame and Body** :
The robot frame is made of **lightweight** and **durable materials** to ensure balance and stability during movement . also it can easily hold motors and other components in place .



* **Arms and Motion transmission system** :
 The articulated arms move with the help of flexible belts and a pulley system. This part provides the possibility of accurately drawing lines and various shapes .

* **Pen holder** :
The pen holder is designed in a way that can hold various writing tools (such as pens, pencils, or markers) stable and be it can  easily get replaced .


***

### 2 . Electronic Components

* **Stepper Motors** :
  This project uses two stepper motors that allow precise and controlled movement of the arms. Each motor is controlled with special drivers to ensure accuracy in drawing . 

[![2eq3CZl.png](https://iili.io/2eq3CZl.png)](https://freeimage.host/)
[![2eq3Bj4.jpg](https://iili.io/2eq3Bj4.jpg)](https://freeimage.host/)
[![2eq3A8u.md.png](https://iili.io/2eq3A8u.md.png)](https://freeimage.host/i/2eq3A8u)


* **Microcontroller** :
The main control of the robot is done by a microcontroller such as Arduino. This controller is responsible for receiving commands from the design software and converting them into mechanical movement

![](https://store.arduino.cc/cdn/shop/files/A000066_03.front_643x483.jpg?v=1727098250)


* **Drivers** :
For precise and optimal control of stepper motors, drivers are used to generate signals necessary for motor movement. In this project, we used the **TB6600 driver**. 


[![2eq3uae.png](https://iili.io/2eq3uae.png)](https://freeimage.host/)
[![2eq3aZQ.md.jpg](https://iili.io/2eq3aZQ.md.jpg)](https://freeimage.host/i/2eq3aZQ)



* **Power supply** :
Power supply: All electronic components and robot motors receive power from a stable power supply that provides suitable current and voltage


 [![2eq3Ryb.png](https://iili.io/2eq3Ryb.png)](https://freeimage.host/)

* **External memory** :
In projects with a much larger number of points than the capacity of Arduino, we need to transfer data from the computer to external memory and read the coordinates of the points along with the corresponding code from it

<img src="https://ae04.alicdn.com/kf/S8218c784b2b2498d9b457b153b37cdaas.jpg_640x640q90.jpg" width="200" height="200" alt="2eq3Ywx.png" border="0" ></a>

*** 

### 3 . Software System   :
* **Programming and Control** :
The robot control software is written in **C++** language and in the **Arduino IDE** environment. This program is responsible for sending precise signals to the drivers for the movement of stepper motors. We also use the **AccelStepper library** for controlling the stepper motors.  

```c++
#include <AccelStepper.h>
#include <MultiStepper.h>
#include "instructions.h"

AccelStepper xAxis(AccelStepper::DRIVER, 7, 8);
AccelStepper yAxis(AccelStepper::DRIVER, 9, 10);
MultiStepper steppers;

void setup() {
  xAxis.setMaxSpeed(1000); // steps per second
  yAxis.setMaxSpeed(1000);
  steppers.addStepper(xAxis);
  steppers.addStepper(yAxis);
}

void loop() {
  for (int i = 0; i < 5; i++) {
    steppers.moveTo(positions[i]);
    steppers.runSpeedToPosition();
  }
}
```


* **Integration with Rhino and Grasshopper** :
The robot software section is designed in a way that it can communicate with advanced design tools such as Rhino and Grasshopper. This capability enables the conversion of digital designs into motion commands .

    G-Code Algorithm for obtaining a list of coordinate points : 

    [![2eq3xGS.md.png](https://iili.io/2eq3xGS.md.png)](https://freeimage.host/i/2eq3xGS)


    
* **Coordinate System** :
The robot uses a two-dimensional coordinate system to determine the position of its arms. This system allows for precise positioning of the pen on the paper

    [![2eq3on2.png](https://iili.io/2eq3on2.png)](https://freeimage.host/)
