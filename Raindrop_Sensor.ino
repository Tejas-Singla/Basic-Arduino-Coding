void setup() {
  // put your setup code here, to run once:
pinMode(A0, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int sensorval;
sensorval=analogRead(A0);
Serial.println(sensorval);
if(sensorval>= 800){
  Serial.println("NO RAIN");
}else if(sensorval>=400 && sensorval<=600 ){
  Serial.println("LITTLE RAIN");
}else if(sensorval>=350 && sensorval<=400){
  Serial.println("MEDIUM RAIN");
}else if(sensorval<=350){
  Serial.println("LOT OF RAIN");
}
delay(1000);
}
