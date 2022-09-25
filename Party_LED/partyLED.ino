const int pipeline[] = { 8, 9, 10, 11, 12, 13 };
const int leds = 6;

void setup() {
  for (int i = 0; i < leds; i++)
    pinMode(pipeline[i], OUTPUT);
}

void loop() {
  for (int i = 0; i < leds; i++) {
    digitalWrite(pipeline[i], HIGH);
    digitalWrite(pipeline[(i + 2) % 6], HIGH);
    delay(400);
    digitalWrite(pipeline[i], LOW);
    digitalWrite(pipeline[(i + 2) % 6], LOW);
    delay(400);
  }
  for (int i = 0; i < leds; i++) {
    digitalWrite(pipeline[i], HIGH);
    digitalWrite(pipeline[(i + 2) % 6], HIGH);
    digitalWrite(pipeline[(i + 3) % 6], HIGH);
    delay(100);
    digitalWrite(pipeline[i], LOW);
    digitalWrite(pipeline[(i + 2) % 6], LOW);
    digitalWrite(pipeline[(i + 3) % 6], LOW);
    delay(100);
  }
  for (int i = 0; i < 3; i++) {
    for (int i = 0; i < leds; i++) {
      digitalWrite(pipeline[i], HIGH);
      delay(100);
      digitalWrite(pipeline[i], LOW);
    }
  }
}