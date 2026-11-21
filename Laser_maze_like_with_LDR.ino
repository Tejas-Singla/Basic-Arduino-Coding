void setup() {
  // put your setup code here, to run once:
pinMode(11, OUTPUT);
pinMode(8, OUTPUT);
pinMode(A0, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int ldrval;

digitalWrite(8, HIGH);
ldrval=analogRead(A0);
Serial.println(ldrval);
if(ldrval>= 150){
  digitalWrite(11, HIGH);
}else{
  digitalWrite(11, LOW);
}
delay(1000);
}
