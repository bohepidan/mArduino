const int button = 2;
const int led = 13;

int buttonState = 0;

void setup() {
  pinMode(button, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  while (digitalRead(button));
  while (!digitalRead(button));
  buttonState ^= HIGH ^ LOW;
  if (buttonState == HIGH)
    digitalWrite(led, LOW);
  else
    digitalWrite(led, HIGH);
  delay(100);
}