const int trig = 11;
const int echo = 12;
const int R = 2;
const int N = 4;
const int D = 7;
const int buzzer = 10;
const int Gear[] = { R, N, D };
const int Red = 8, Green = 9, Blue = 6;
const int RGB[] = { Red, Green, Blue };
int state = 4;
int blinktime = 1000;
int color = Green;
float fDistance;
void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(R, INPUT_PULLUP);
  pinMode(N, INPUT_PULLUP);
  pinMode(D, INPUT_PULLUP);
  digitalWrite(trig, LOW);
}
int lightstate = 0;
long lastblink = 0;
int buzztime = 1000;
long lastbuzz = 0;
void loop() {
  int lighton;
  //read distance
  digitalWrite(trig, HIGH);
  delayMicroseconds(15);
  digitalWrite(trig, LOW);
  fDistance = pulseIn(echo, HIGH) / 58;
  for (int i = 0; i < 3; i++) {
    if (!digitalRead(Gear[i])) {
      delay(20);
      if (!digitalRead(Gear[i]))
        state = Gear[i];
      while (!digitalRead(Gear[i]));
      for (int i = 0; i < 3; i++) {
        digitalWrite(RGB[i], LOW);
      }
    }
  }
  if (fDistance > 100) {
    for (int i = 0; i < 3; i++) {
      digitalWrite(RGB[i], LOW);
    }
    lighton = 0;
  }
  else if (fDistance < 100 && fDistance > 60) {
    lighton = 1;
    if (color != Green) {
      for (int i = 0; i < 3; i++) {
        digitalWrite(RGB[i], LOW);
      }
      color = Green;
    }
    blinktime = map(fDistance, 60, 100, 1200, 1500);
  }
  else if (fDistance < 60 && fDistance > 20) {
    lighton = 1;
    if (color != Blue) {
      for (int i = 0; i < 3; i++) {
        digitalWrite(RGB[i], LOW);
      }
      color = Blue;
    }
    blinktime = map(fDistance, 20, 60, 500, 800);
  }
  else {
    lighton = 1;
    if (color != Red) {
      for (int i = 0; i < 3; i++) {
        digitalWrite(RGB[i], LOW);
      }
      color = Red;
    }
    blinktime = map(fDistance, 1, 20, 100, 300);
  }
  if (millis() - lastblink >= blinktime && lighton) {
    lastblink = millis();
    digitalWrite(color, lightstate);
    lightstate = !lightstate;
  }

  if (state == R) {
    if (fDistance > 100) {
      if (millis() - lastbuzz >= 3000) {
        lastbuzz = millis();
        tone(buzzer, 500, 500);
      }
    }
    else {
      buzztime = map(fDistance, 1, 100, 100, 1500);
      int note = map(fDistance, 1, 100, 500, 2000);
      note = 2000 - note + 500;
      if (millis() - lastbuzz >= buzztime) {
        lastbuzz = millis();
        tone(buzzer, note, buzztime * 0.5);
      }
    }
  }
  delay(20);
}