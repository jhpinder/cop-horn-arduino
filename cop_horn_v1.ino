int buttonPin = 7;
int speakerPin = 8;
boolean isButtonPressed = false;
float currentTime = 0;
long nextDelay = 0;
unsigned int delayTable[] = {
  769,
  769,
  769,
  769,
  769,
  769,
  769,
  384,
  537,
  537,
  537,
  312,
};
void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(speakerPin, OUTPUT);
  currentTime = micros();
}

void loop() {
  if(!digitalRead(buttonPin)) {
    makeTone();
  }

}

void makeTone() {
  for(int i = 0; i < 12; i++) {
    digitalWrite(speakerPin, i%2);
    delayMicroseconds(delayTable[i] - 4);
  }
}
