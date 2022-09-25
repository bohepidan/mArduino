const int sensor = 2;
const int led = 13;

void setup() {
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  while (!digitalRead(sensor));

  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(led, LOW);
  delay(100);
}
