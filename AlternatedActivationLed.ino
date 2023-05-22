const int ledRed = 13;
const int ledYellow = 12;
const int ledGreen = 11;
const int buttonPin = 2;

int i = 0;
int buttonListener;
int elapsedTime = 0;

void setup(){
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop(){
  buttonListener = digitalRead(buttonPin);
  
  if(buttonListener==HIGH && i==0){
    activeLed(ledRed);
    i = 1;
  }else if(buttonListener == HIGH && i == 1){
  	activeLed(ledYellow);
    i = 2;
  }else if(buttonListener == HIGH && i==2){
  	activeLed(ledGreen);
    i = 0;
  }
}

void activeLed(int ledColor){
  if(ledColor == ledRed){
  	digitalWrite(ledRed, HIGH);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledGreen, LOW);
    wait();
  }else if(ledColor == ledYellow){
  	digitalWrite(ledRed, LOW);
    digitalWrite(ledYellow, HIGH);
    digitalWrite(ledGreen, LOW);
    wait();
  }else if(ledColor == ledGreen){
  	digitalWrite(ledRed, LOW);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledGreen, HIGH);
    wait();
  }
}

void wait(){
  delay(300);
}
