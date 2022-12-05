const int red = 9;
const int green = 10;
const int blue = 11;

const int redButt = 2;
const int greenButt = 4;
const int blueButt = 7;

int redVal = 255;
int greenVal = 255;
int blueVal = 255;
const int delta = 32;

void changeColor(int led, int& val, int button) {
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

void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(redButt, INPUT_PULLUP);
  pinMode(greenButt, INPUT_PULLUP);
  pinMode(blueButt, INPUT_PULLUP);
}

void loop() {
  changeColor(red, redVal, redButt);
  changeColor(green, greenVal, greenButt);
  changeColor(blue, blueVal, blueButt);
}
