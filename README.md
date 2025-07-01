

## Intro :
Robots of the future are a symbol of the combination of art and technology, tools that can accurately and beautifully map and create designs. In this project, inspired by the structure of serial robots like **Makelangelo**, a two-dimensional design robot has been developed using advanced design software such as **Rhino** and **Grasshopper**, as well as custom coding, to provide the ability to create sophisticated designs. The goal of this documentary is to provide a comprehensive and step-by-step guide to the design, construction, and operation of the robot. It not only explains the hardware and software components but also details how the robot interacts with digital designs. With the help of this guide, not only can you understand the operational mechanism of the robot, but also the possibility of redesigning or improving the design for similar projects is provided. This design robot emphasizes precision, personalization, and integration with advanced digital design tools, and can have a wide range of applications in educational, artistic, and industrial fields.


##  Components of the Design Robot  :
   The design robot of this project consists several main components, each one plays a key role in its overall performance. These components include mechanical hardware, electronic components, and software systems. Each of these components and their functions are detailed below :   

### 1 . Mechanical Components  :

* **Frame and Body** :
The robot frame is made of **lightweight** and **durable materials** to ensure balance and stability during movement . also it can easily hold motors and other components in place .

![](https://github.com/Goldenstarcom/Plotter/blob/Plotter_Photos/02.png)

* **Arms and Motion transmission system** :
 The articulated arms move with the help of flexible belts and a pulley system. This part provides the possibility of accurately drawing lines and various shapes .

<img src="https://github.com/Goldenstarcom/Plotter/blob/Plotter_Photos/Diagram_01.JPG" width="400" height="400" alt="2eq3Ywx.png" border="0" ></a>
<img src="https://github.com/Goldenstarcom/Plotter/blob/Plotter_Photos/Diagram_02.JPG" width="400" height="400" alt="2eq3Ywx.png" border="0" ></a>

* **Pen holder** :
The pen holder is designed in a way that can hold various writing tools (such as pens, pencils, or markers) stable and it can easily get replaced .


<img src="https://github.com/Goldenstarcom/Plotter/blob/Plotter_Photos/Diagram_03.JPG" width="300" height="300" alt="2eq3Ywx.png" border="0" ></a>
<img src="https://github.com/Goldenstarcom/Plotter/blob/Plotter_Photos/Diagram_04.JPG" width="300" height="300" alt="2eq3Ywx.png" border="0" ></a>
<img src="https://github.com/Goldenstarcom/Plotter/blob/Plotter_Photos/Diagram_05.JPG" width="300" height="300" alt="2eq3Ywx.png" border="0" ></a>

### 2 . Electronic Components

* **Stepper Motors** :
 Two stepper motors are used to enable precise bi-directional control on the X and Y axes.

<img src="(https://github.com/Goldenstarcom/Plotter/blob/Plotter_Photos/StepperMotor_01.jpg" width="300" height="300" alt="2eq3Ywx.png" border="0" ></a>
![](https://github.com/Goldenstarcom/Plotter/blob/Plotter_Photos/Diagram_05.JPG)


* **Microcontroller** :
The main control of the robot is done by a microcontroller such as Arduino. This controller is responsible for receiving commands from the design software and converting them into mechanical movement

![](https://store.arduino.cc/cdn/shop/files/A000066_03.front_643x483.jpg?v=1727098250)


* **Drivers** :
For precise and optimal control of stepper motors, drivers are used to generate signals necessary for motor movement. In this project, we used the **TB6600 driver**. 


[![2eq3uae.png](https://iili.io/2eq3uae.png)](https://freeimage.host/)
[![2eq3aZQ.md.jpg](https://iili.io/2eq3aZQ.md.jpg)](https://freeimage.host/i/2eq3aZQ)



* **Power supply** :
 All electronic components and robot motors receive power from a stable power supply that provides suitable current and voltage


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

## 4. Step-by-Step Testing Guide :
Before deploying the complete system, we follow a structured approach to ensure that each hardware component functions correctly. This helps prevent unnecessary issues and simplifies debugging. At each step, we carefully test the performance of each component to identify and resolve potential problems early. This step-by-step approach ensures that we verify the functionality of each part, making the debugging process and hardware verification much easier.

The robot's software is developed using the Arduino IDE and C++, utilizing the AccelStepper and MultiStepper libraries for precise and synchronized stepper motor control. G-code instructions are parsed and executed in real time, and the robot interfaces with design software (Rhino and Grasshopper) via preprocessed files. Additional modules, such as an SD card reader and a servo motor for marker actuation, are integrated into the firmware. The following tests validate how each of these components work individually and as a complete system.
The process is structured as follows:

#### 4 . 1 . Endstop Testing :
- Verify the proper functioning of the endstop switches
- Use a simple test code to display sensor readings in the Serial Monitor
- Ensure that pressing each endstop switch is correctly detected and stops the system's movement
```c++
/* This code is used to verify the proper functioning of the Endstops.
When the Serial Monitor in Arduino IDE is enabled, the output will
normally be "1 - 1".
This is because the Endstops return 1 when they are not pressed.
If either Endstop button is pressed, the corresponding output will
 change to 0.*/

#define LES A0 // Left Endstop switch pin
#define RES A1 // Right Endstop switch pin

void setup() {
  pinMode(LES, INPUT);
  pinMode(RES, INPUT);

  // Initialize serial communication with a baud rate of 115200
  Serial.begin(115200);
}

void loop() {
  // Read the state of both Endstops and print the values to the Serial Monitor
  Serial.print(digitalRead(LES));
  Serial.print(" - ");
  Serial.println(digitalRead(RES));
```
<img src="https://github.com/Goldenstarcom/Plotter/blob/Plotter_Photos/1-End_Stops.jpg" width="500" height="315" alt="2eq3Ywx.png" border="0" ></a>
#### 4 . 2 . Independent Stepper Motor Testing :
- Test the functionality of each stepper motor
- Rotate the motor 400 steps in one direction and then 400 steps back in the opposite direction
- Ensure that the stepper motor and driver are working correctly by verifying the motor’s movement in both directions
##### 4 . 2 . 1 . Left Stepper Motor Testing :
```c++
/* This code tests the functionality of the left stepper motor.
   It rotates the motor 400 steps in one direction, then reverses
   the direction and rotates it another 400 steps back.
   This helps verify that the stepper motor and driver are working correctly. */

#define LeftPul 2 // Left Stepper Pulse pin
#define LeftDir 3 // Left Stepper Direction pin

void setup() {
  pinMode(LeftPul, OUTPUT);
  pinMode(LeftDir, OUTPUT);

  digitalWrite(LeftDir, HIGH); /* Set direction to HIGH (clockwise or counterclockwise depending on driver) */

  /* Rotate stepper motor 400 steps in the first direction */
  for (int i = 0; i < 400; i++) {
    digitalWrite(LeftPul, HIGH); /* Send a pulse signal */
    digitalWrite(LeftPul, LOW);  /* Turn off the pulse signal */
    delay(2); /* Short delay to control speed */
  }

  digitalWrite(LeftDir, LOW); /* Change direction (reverse) */

  /* Rotate stepper motor 400 steps in the opposite direction */
  for (int i = 0; i < 400; i++) {
    digitalWrite(LeftPul, HIGH); /* Send a pulse signal */
    digitalWrite(LeftPul, LOW);  /* Turn off the pulse signal */
    delay(2); /* Short delay to control speed */
  }
}

void loop() {
  // Empty loop
}
```
<img src="https://github.com/Goldenstarcom/Plotter/blob/Plotter_Photos/2-Left_Stepper.jpg" width="350" height="425" alt="2eq3Ywx.png" border="0" ></a>
##### 4 . 2 . 2 .Right Stepper Motor Testing :
```c++
/* This code tests the functionality of the left stepper motor.
   It rotates the motor 400 steps in one direction, then reverses
   the direction and rotates it another 400 steps back.
   This helps verify that the stepper motor and driver are working correctly. */

#define LeftPul 2 // Left Stepper Pulse pin
#define LeftDir 3 // Left Stepper Direction pin

void setup() {
  pinMode(LeftPul, OUTPUT);
  pinMode(LeftDir, OUTPUT);

  digitalWrite(LeftDir, HIGH); /* Set direction to HIGH (clockwise or counterclockwise depending on driver) */

  /* Rotate stepper motor 400 steps in the first direction
     Drivers move one step on LOW to HIGH transition */
  for (int i = 0; i < 400; i++) {
    digitalWrite(LeftPul, HIGH); /* Send a pulse signal */
    digitalWrite(LeftPul, LOW);  /* Turn off the pulse signal */
    delay(2); /* Short delay to control speed */
  }

  digitalWrite(LeftDir, LOW); /* Change direction (reverse) */

  /* Rotate stepper motor 400 steps in the opposite direction
     Drivers move one step on LOW to HIGH transition */
  for (int i = 0; i < 400; i++) {
    digitalWrite(LeftPul, HIGH); /* Send a pulse signal */
    digitalWrite(LeftPul, LOW);  /* Turn off the pulse signal */
    delay(2); /* Short delay to control speed */
  }
}

void loop() {
  // Empty loop
}
```
<img src="https://github.com/Goldenstarcom/Plotter/blob/Plotter_Photos/2-Right_Stepper.jpg" width="350" height="425" alt="2eq3Ywx.png" border="0" ></a>

#### 4 . 3 . Repositioning (Homing) and Synchronized Stepper Movement :
- Control two stepper motors using the AccelStepper and MultiStepper libraries for synchronized movement
- Use end-stop switches to ensure both motors start from a known home position
- Move stepper motors to a home position by rotating them towards the end-stop switches, then set the current position as (0,0)
- Reposition the gondola (attached to a marker) by moving both motors in sync, ensuring precise drawing on the surface

<img src="https://github.com/Goldenstarcom/Plotter/blob/Plotter_Photos/3-Repositioning.jpg"  width="500" height="500" alt="2eq3Ywx.png" border="0" ></a>

#### 4 . 4 . Precision Movement Test :
- Test the accuracy of the stepper motor movements by moving the gondola (attached to a marker) to five predefined positions
- Verify that the motors accurately reach the set positions after the system has been repositioned to its home state
- Ensure synchronized movement of both stepper motors to confirm the system's precision for drawing on the surface
```c++
/* This program controls two stepper motors using the AccelStepper and
   MultiStepper libraries.
   It synchronizes their movement and ensures both motors start from a known home
   position using end-stop switches.
   The system consists of a pulley and belt mechanism where one end of the belt
   has a hanging weight,
   and the other end is attached to a gondola that holds a marker for drawing on a
   wall.
   After repositioning, the system moves the gondola to five predefined positions
   to test movement accuracy. */

#include <AccelStepper.h> // Library for controlling stepper motors
#include <MultiStepper.h> // Library for synchronized stepper motor movement

// Define end-stop pins
#define LES A0 // Left Endstop switch pin
#define RES A1 // Right Endstop switch pin

// Define test positions for movement verification
long positions[5][2] = {
  {100, -100},
  {100, -200},
  {-400, 300},
  {500, -500},
  {0, 0}
};

/* Initialize stepper motors with driver configuration
   Parameters: DRIVER mode, Pulse pin, Direction pin */
AccelStepper LStepper(AccelStepper::DRIVER, 2, 3); // Left Stepper: Pulse on pin 2, Direction on pin 3
AccelStepper RStepper(AccelStepper::DRIVER, 4, 5); // Right Stepper: Pulse on pin 4, Direction on pin 5
MultiStepper steppers; // Multi-stepper object for synchronized movement

void setup() {
  /* Set maximum speed and initial speed for both steppers */
  LStepper.setMaxSpeed(500);
  LStepper.setSpeed(500);
  RStepper.setMaxSpeed(500);
  RStepper.setSpeed(500);

  /* Reverse the direction of the right stepper to match the system configuration */
  RStepper.setDirection(1); // Assuming 1 reverses direction, adjust as needed
}

void loop() {
  // Code to handle movement to positions would go here
}
```
<img src="https://github.com/Goldenstarcom/Plotter/blob/Plotter_Photos/3-Repositioning.jpg"  width="500" height="500" alt="2eq3Ywx.png" border="0" ></a>

#### 4 . 5 .SD Card Functionality Test :
- Ensure the SD card is properly initialized and can read a file ("test.txt") stored on it
- Verify that the SD card module is connected and functioning correctly by reading and displaying the content of the file on the Serial Monitor
- Test reading and extracting words from the file character by character to confirm SD card functionality

<img src="https://github.com/Goldenstarcom/Plotter/blob/Plotter_Photos/5-SDCard.jpg" width="500" height="300" alt="2eq3Ywx.png" border="0" ></a>
```c++
/*
  This code tests an SD card reader to ensure it is functioning correctly
  and properly wired. It reads the content of a text file ("test.txt")
  stored on the SD card, character by character, and extracts words,
  printing them to the Serial Monitor.
*/

// Include necessary libraries for SPI communication and SD card handling
#include <SPI.h> // Library for Serial Peripheral Interface (SPI) communication
#include <SD.h> // Library for interacting with SD cards

#define cs 10  // Chip Select pin for SD card module
// SPI Pins:
// Master In Slave Out (MISO) -> Pin 12
// Master Out Slave In (MOSI) -> Pin 11
// Clock (SCK) -> Pin 13

void setup() {
  
  // Initialize serial communication with a baud rate of 115200
  // This allows the Serial Monitor to display the output
  Serial.begin(115200); 
  
  // Check if SD card is properly initialized
  if (!SD.begin(cs)) {
    Serial.println("SD not Found!"); // Print error message if SD card is not detected
    while (true); // Halt the program execution
  }
  
  // Open the test file from the SD card
  File file = SD.open("test.txt");
  String word = ""; // Variable to store each word

  // Read file character by character
  while (file.available()) {
    char ch = file.read(); // Read one character from the file
    
    if (ch == ' ') { // If a space is encountered, print the current word
      Serial.println(word);
      word = ""; // Reset the word variable
    }
    else {
      word += ch; // Append character to the current word
    }
  }
}

void loop() {}
```
#### 4 . 6 . Servo Motor Test :
- Verify the functionality of the servo motor by alternating its movement between two positions:
   - "UP" (0 degrees) to lift the marker off the surface
   - "DOWN" (90 degrees) to lower the marker and press it onto the surface
-	The servo moves every 4 seconds to ensure smooth operation and test the control mechanism.

```c++
// This program controls a servo motor to lift and lower a marker for a drawing system.
// The servo has two states:
//   - "UP" (0 degrees): The servo arm extends forward, lifting the marker off the surface.
//   - "DOWN" (90 degrees): The servo arm retracts, pressing the marker onto the surface for writing.
// The loop alternates between UP and DOWN every 4 seconds for testing purposes.

#include <Servo.h> // Library for controlling the servo motor

Servo s; // Create a servo object

void setup() {
  s.attach(6); // Attach the servo to pin 6
}

void loop() {
  up();       // Lift the marker off the surface
  delay(4000); // Wait 4 seconds
  down();     // Lower the marker onto the surface
  delay(4000); // Wait 4 seconds
}

// Moves the servo to the "UP" position (0 degrees), lifting the marker
void up() {
  s.write(0);
}

// Moves the servo to the "DOWN" position (90 degrees), pressing the marker onto the surface for drawing
void down() {
  s.write(90);
}
``` 
<img src="https://github.com/Goldenstarcom/Plotter/blob/Plotter_Photos/6-Servo.jpg" width="500" height="500" alt="2eq3Ywx.png" border="0" ></a> 


















