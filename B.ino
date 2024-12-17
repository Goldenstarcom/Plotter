#define pul 7
#define dir 8
void setup() {
  pinMode(pul, OUTPUT);
  pinMode(dir, OUTPUT);
}

void loop() {
  digitalWrite(dir, LOW);
  for(int i = 0; i < 200; i++) {
    digitalWrite(pul, HIGH);
    digitalWrite(pul, LOW);
    delay(2);
  }
  delay(500);
  digitalWrite(dir, HIGH);
  for(int i = 0; i < 200; i++) {
    digitalWrite(pul, HIGH);
    digitalWrite(pul, LOW);
    delay(2);
  }
  delay(500);
}
