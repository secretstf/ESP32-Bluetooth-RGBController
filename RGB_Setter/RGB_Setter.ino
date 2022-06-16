int redPin = D0;
int greenPin = D1;
int bluePin = D2;

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  resetLED();

  Serial.begin(9600);
  Serial.println("RGB Ccolour Selector v1.0");
  Serial.println("Default Colour is Green ");
  rgbSetter(0,255,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  lineDivider();
  Serial.println("Do you want to enter hex code (1) or RGB code (2) [default is 1]? ");
  while(Serial.available() == 0){}

  if(Serial.parseInt() == 2){
    rgbCodeInput();
  } else {
    hexCodeInput();
  }

}

void hexCodeInput(){
  Serial.println("What hex code would you like to choose? ");
  while(Serial.available() == 0){}

  String hexString = Serial.readString();
  if(checkHexValue(hexString)){
    int number = (int) strtol( &hexString[1], NULL, 16);
  
    // Split them up into r, g, b values
    int r = number >> 16;
    int g = number >> 8 & 0xFF;
    int b = number & 0xFF;

    Serial.println();
    Serial.println("Setting colour ... ");
    rgbSetter(r, g, b);

    delay(200);
  } else {
    Serial.println();
    Serial.println("Input invalid!!!");
  }
  
}

void rgbCodeInput(){
  Serial.println();
  Serial.println("What red value would you like to have (0-255)?");
  while(Serial.available() == 0){}

  int r = rangeValue(Serial.parseInt(), 0 , 255);
  
  Serial.println("What green value would you like to have (0-255)?");
  while(Serial.available() == 0){}

  int g = rangeValue(Serial.parseInt(), 0 , 255);
  
  Serial.println("What blue value would you like to have (0-255)?");
  while(Serial.available() == 0){}

  int b = rangeValue(Serial.parseInt(), 0 , 255);

  Serial.println();
  Serial.println("Setting colour ...");

  rgbSetter(r, g, b);
  delay(200);
}

int rangeValue(int in, int minimum, int maximum){
  if(in > maximum)
    return maximum;
  if(in < minimum)
    return minimum;
  return in;
}

void resetLED(){
  analogWrite(redPin, 0);
  analogWrite(bluePin, 0);
  analogWrite(greenPin, 0);
}

void rgbSetter(int r, int g, int b){
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
}

void lineDivider(){
  Serial.println();
  Serial.println("--------------------------------------");
  Serial.println();
}

boolean checkHexValue(String hexValue){
  if(hexValue[0] != '#')
    return false;

  String lowerString = hexValue.substring(1);
  lowerString.toLowerCase();

  for(int i = 0; i < lowerString.length(); i++){
    if(!(lowerString[i] - '0' >= 0 && lowerString[i] - '9' <= 0) && !(lowerString[i] - 'a' >= 0 && lowerString[i] - 'f' <= 0))
      return false;
  }

  return true;
}
