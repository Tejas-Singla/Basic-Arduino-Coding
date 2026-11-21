
#include <Servo.h>

int buzzer=5;
int blue=6;
int red=7;
int trig=8;
int echo=9;
Servo servo;
int pos=0;
int distance;
long time;

void setup() {
  // put your setup code here, to run once:

pinMode(buzzer, OUTPUT);
pinMode(blue, OUTPUT);
pinMode(red, OUTPUT);
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
servo. attach(10);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

   Serial.println(distance);

   digitalWrite(trig, LOW);
   delayMicroseconds(2);
   digitalWrite(trig, HIGH);
   delayMicroseconds(10);
   digitalWrite(trig, LOW);

   time=pulseIn(echo, HIGH);

   distance=time*0.034/2;
   Serial.println(distance);


   
   for(pos=0; pos<=180; pos+=1){

    servo.write(pos);
    delay(15);
    Serial.println(distance);

   }

   for(pos=180; pos>=0; pos-=1){

    servo.write(pos);
    delay(15);
    Serial.println(distance);

   }

Serial.println(distance);
  

if(distance<=40){

digitalWrite(blue, LOW);
digitalWrite(red, HIGH);
tone(buzzer, 1000);
delay(1000);
noTone(buzzer);
}
else if(distance>40){

  digitalWrite(blue, HIGH);
  digitalWrite(red, LOW);
  noTone(buzzer);
  delay(1000);




}


}
