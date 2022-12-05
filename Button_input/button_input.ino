const int button = 2;
const int led = 10;

int val = 255;
const int delta = 32;

void setup() {
  pinMode(button, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  analogWrite(led, val);
  if (digitalRead(button));
  delay(20);
  if (digitalRead(button) == LOW) {
    val -= delta;
    if (val < 0)
      val = 255;
  }
  while (!digitalRead(button));
}