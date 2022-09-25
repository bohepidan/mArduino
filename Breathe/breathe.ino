const int led = 9;

void setup() {}
int pot = A0;

void loop() {
  for (int fadeVal = 0; fadeVal <= 255; fadeVal += 5) {
    analogWrite(led, fadeVal);
    delay(analogRead(pot) / 5);
  }
  for (int fadeVal = 255; fadeVal >= 0; fadeVal -= 5) {
    analogWrite(led, fadeVal);
    delay(analogRead(pot) / 5);
  }

}