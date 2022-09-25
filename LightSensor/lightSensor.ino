void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorVal = analogRead(A0);
  Serial.println("resistence at this moment: ");
  Serial.println(1000 / (double)(1000 - sensorVal) * sensorVal);
  delay(100);

}