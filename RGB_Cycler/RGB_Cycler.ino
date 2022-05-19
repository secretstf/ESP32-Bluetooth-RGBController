int redPin = D0;
int greenPin = D1;
int bluePin = D2;

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  resetLED();
}

void loop() {
  resetLED();
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 256; i++){
    analogWrite(redPin, i);
    delay(5);
  }
  resetLED();
  for(int i = 0; i < 256; i++){
    analogWrite(greenPin, i);
    delay(5);
  }
  resetLED();
  for(int i = 0; i < 256; i++){
    analogWrite(bluePin, i);
    delay(5);
  }
}

void resetLED(){
  analogWrite(redPin, 0);
  analogWrite(bluePin, 0);
  analogWrite(greenPin, 0);
}
