const int red = 9;
const int green = 10;
const int blue = 11;

const int redButt = 2;
const int greenButt = 4;
const int blueButt = 7;

int redVal = 255;
int greenVal = 255;
int blueVal = 255;

bool sel = false;
int delayTime = 512;
void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(redButt, INPUT_PULLUP);
  pinMode(greenButt, INPUT_PULLUP);
  pinMode(blueButt, INPUT_PULLUP);
}

void loop() {
  if (!digitalRead(redButt)) {
    delay(20);
    if (!digitalRead(redButt)) {
      sel = !sel;
    }
    while (!digitalRead(redButt));
  }
  if (!digitalRead(greenButt)) {
    delay(20);
    if (!digitalRead(greenButt) && delayTime < 1024) {
      delayTime = delayTime << 1;
    }
    while (!digitalRead(greenButt));
  }
  if (!digitalRead(blueButt)) {
    delay(20);
    if (!digitalRead(blueButt) && delayTime > 4) {
      delayTime = delayTime >> 1;
    }
    while (!digitalRead(blueButt));
  }
  if (sel) {
    randomSeed(random(65535));
    analogWrite(red, random(256));
    analogWrite(green, random(256));
    analogWrite(blue, random(256));
    delay(delayTime);
  }
}