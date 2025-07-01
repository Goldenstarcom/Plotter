
# Design and Implementation of a 2D Drawing Robot with G-Code Integration and Digital Design Tool 
___
## Abstract 
In this research, a 2D drawing robot has been developed that is capable of rendering digital designs on a surface with high precision. Inspired by open-source projects such as Makelangelo, the robot utilizes lightweight mechanical components, precise stepper motors, and a control system based on Arduino. The software is designed to interface with Rhino and Grasshopper, receiving complex design inputs, converting them into motion codes (G-Code), and sending them to the robot. The goal of this project is to investigate the feasibility of building a simple yet precise robotic system for educational, artistic, and research purposes. Experimental evaluations were conducted to measure the robot’s drawing accuracy in both linear and curved paths. Results showed satisfactory performance in rendering both simple and complex shapes, though improvements in motion algorithms were identified, especially for curves.


## Keywords 
   The design robot of this project consists several main components, each one plays a key role in its overall performance. These components include mechanical hardware, electronic components, and software systems. Each of these components and their functions are detailed below :   

## 1. introduction :
The convergence of art and technology has given rise to intelligent tools such as drawing robots—systems capable of transferring digital designs onto any surface with precision. In recent years, open-source projects like Makelangelo have provided foundational concepts for building such systems. This project builds on these concepts using powerful design tools such as Rhino and Grasshopper to develop a 2D drawing robot. The robot receives design data as G-Code and controls the pen’s motion path to execute the design with high accuracy. The main objective of the project is to build a functional model for teaching electronics, motion control, and digital-to-physical design interaction.
## 2. System Architecture :


#### 2 . 1 . Mechanical Components
The robot frame is made of **lightweight** and **durable materials** to ensure balance and stability during movement . also it can easily hold motors and other components in place .



* **Chasis and Body** : Constructed from lightweight and durable materials to ensure structural stability and support.

* **Arms and Motion Transmission** :
Utilizes flexible belts and pulleys to transfer motion from motors to the pen holder.

* **Pen Holder** : Designed for both stability and ease of tool replacement (pen, marker, pencil).

#### 2 . 2 . Electronic Components


* **Stepper Motors** :
  This project uses two stepper motors that allow precise and controlled movement of the arms. Each motor is controlled with special drivers to ensure accuracy in drawing . 
![](https://github.com/Goldenstarcom/Plotter/blob/Plotter_Photos/02.png)
* **Microcontroller** :
The main control of the robot is done by a microcontroller such as Arduino. This controller is responsible for receiving commands from the design software and converting them into mechanical movement.

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
