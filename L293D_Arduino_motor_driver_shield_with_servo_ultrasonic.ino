#include <AFMotor.h>
#include<Servo.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
Servo  servo;
int trig=A0;
int echo=A1;
long time;
int straightDistance;
int leftDistance;
int rightDistance;

void setup() {
  // put your setup code here, to run once:
  motor1.setSpeed(150);
  motor2.setSpeed(150);
  motor3.setSpeed(150);
  motor4.setSpeed(150);
  servo.attach(9);
  servo.write(90);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  servo.write(90);
  delay(300);
  //Distance Read
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  
  time=pulseIn(echo,HIGH);
  
  straightDistance=time*0.034/2;
  
  Serial.println("Straight Distance-");
  Serial.print(straightDistance);
//Radar Scan
if (straightDistance>40){

  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  delay(1000);
}else{
  
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  delay(300);
  
  servo.write(30);
  delay(300);
  //Distance Read
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  
  time=pulseIn(echo,HIGH);
  
  leftDistance=time*0.034/2;
  
  Serial.println("Left Distance-");
  Serial.print(leftDistance);

  servo.write(150);
  delay(300);
  //Distance Read
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  
  time=pulseIn(echo,HIGH);
  
  rightDistance=time*0.034/2;
  
  Serial.println("Right Distance-");
  Serial.print(rightDistance);

  servo.write(90);
  delay(300);

if (leftDistance> rightDistance){

  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  delay(500);
}else{

  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  delay(500);
}
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  delay(300);
}
 
}
