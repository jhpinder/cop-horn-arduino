int buttonPin = 7;
int speakerPin = 8;
boolean isButtonPressed = false;
float modulator = 335;
float highFreq = 1535;
float lowFreq = 630;
float currentTime = 0;
long nextDelay = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(speakerPin, OUTPUT);
  currentTime = micros();
}

void loop() {
  if(!digitalRead(buttonPin)) {
    oneCycle();
  }

}

void oneCycle() {
  long currentTime = micros();
  //while (micros() - currentTime < 3750) {
  while (micros() - currentTime < (1 / modulator * 750000)) {
    makeTone(lowFreq);
  }
  currentTime = micros();
  //while (micros() - currentTime < 1250) {
  while (micros() - currentTime < (1 / modulator * 250000)) {
    makeTone(highFreq);
  }
}

void makeTone(float frequency) {
  float period = 1000000 / frequency;  
  digitalWrite(speakerPin, HIGH);
  delayMicroseconds(period / 2);
  digitalWrite(speakerPin, LOW);
  delayMicroseconds(period / 2);
}

void getSignal() {
  
}
