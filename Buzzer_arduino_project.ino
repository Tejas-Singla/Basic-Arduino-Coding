void setup() {
  // put your setup code here, to run once:
pinMode(8, OUTPUT);
pinMode(5, OUTPUT);
}

void loop() {
 digitalWrite(8, HIGH);
 delay(1000);

 digitalWrite(5, HIGH);
 delay(5000);

 digitalWrite(5, LOW);
 delay(1000);
}
