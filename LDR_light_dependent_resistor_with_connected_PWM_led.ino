int ldr=A2;
int ldrvalue;
int led=3;

void setup() {
  // put your setup code here, to run once:
pinMode(ldr, INPUT);
pinMode(led, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
ldrvalue=analogRead(ldr);
ldrvalue=ldrvalue/4.01568627451;
Serial.println(ldrvalue);
delay(100);

analogWrite(led, ldrvalue);
}
