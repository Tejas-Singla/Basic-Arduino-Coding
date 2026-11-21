int sound=8;

void setup() {
  // put your setup code here, to run once:
pinMode(sound, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int soundval=digitalRead(sound);
Serial.println(soundval);
delay(100);
}
