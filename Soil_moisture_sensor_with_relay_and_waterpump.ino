int in=8;
int soil=A0;

void setup() {
  // put your setup code here, to run once:
pinMode(in, OUTPUT);
pinMode(A0, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int soilval=analogRead(soil);
Serial.println(soilval);
delay(100);
if (soilval>=800){
  digitalWrite(in,LOW);
}else{
  digitalWrite(in, HIGH);
}
}
