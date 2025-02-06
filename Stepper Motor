#include <SPI.h>
#include <SD.h>
#define cs 10
//Master In Slave Out | MOSI 11
//Master Out Slave In | MISO 12
//Clock               | 13
#include <Servo.h>
#include <AccelStepper.h>
#include <MultiStepper.h>
#define LES A0
#define RES A1
Servo s;
AccelStepper LStepper(AccelStepper::DRIVER, 2, 3); //Left Pulse: 2 Left Direction: 3
AccelStepper RStepper(AccelStepper::DRIVER, 4, 5); //Right Pulse: 4 Right Direction: 5
MultiStepper steppers;
void setup() {
  if (!SD.begin(cs)) {
    Serial.println("SD not Found!");
    while (true);
  }
  s.attach(6);
  up();
  LStepper.setMaxSpeed(500);
  LStepper.setSpeed(500);
  RStepper.setMaxSpeed(500);
  RStepper.setSpeed(500);
  RStepper.setPinsInverted(true, false, false); //reverse turning direction
  steppers.addStepper(LStepper);
  steppers.addStepper(RStepper);
  reposition();
  delay(1000);
  File file = SD.open("jafar.txt");
  while (true) {
    long p[2];
    String received = "";
    char ch;
    while (file.available()) {
      ch = file.read();
      if (ch == 'u') {
        received = "";
        up();
        continue;
      }
      if (ch == 'd') {
        received = "";
        down();
        continue;
      }
      if (ch == ',') {
        p[0] = received.toInt();
        received = "";
        continue;
      }
      if (ch == '\n') {
        p[1] = received.toInt();
        received = "";
        break;
      }
      received += ch;
    }
    if (!file.available()) {
      up();
      p[0] = 0;
      p[1] = 0;
    }
    steppers.moveTo(p);
    steppers.runSpeedToPosition();
  }
}
void loop() {}
void reposition() {
  up();
  bool LR = true; //No Collision
  bool RR = true; //No Collision
  while (LR || RR) { //Continue until both left and right are
    LR &= digitalRead(LES); //If it hits the end stop, it Returns False
    RR &= digitalRead(RES);
    if (LR) LStepper.runSpeed();
    if (RR) RStepper.runSpeed();
  }
  LStepper.setCurrentPosition(0);
  RStepper.setCurrentPosition(0);
  long pos[2] = {-3000, -3000};
  steppers.moveTo(pos);
  steppers.runSpeedToPosition();
  LStepper.setCurrentPosition(0);
  RStepper.setCurrentPosition(0);
}
void up() {
  s.write(0);
  delay(700);
}
void down() {
  s.write(90);
  delay(700);
}
