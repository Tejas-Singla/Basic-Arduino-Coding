int sensorPin = A0;
int buzzerPin = 2;
int alcoholValue;
int limit=600;

void setup() {
  // put your setup code here, to run once:
pinMode(buzzerPin, OUTPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
alcoholValue = analogRead(sensorPin);
Serial.print("Alcohol Value:");
Serial.println(alcoholValue);

if(alcoholValue > limit){
  digitalWrite(buzzerPin, HIGH);
}else{
  digitalWrite(buzzerPin, LOW);
}


delay(500);

}