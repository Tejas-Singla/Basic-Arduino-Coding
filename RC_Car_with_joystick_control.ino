#include<AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

int xval;
int yval;
int button=9;
int buttonstate;


void setup() {
  // put your setup code here, to run once:
motor1.setSpeed(150);
motor2.setSpeed(150);
motor3.setSpeed(150);
motor4.setSpeed(150);

pinMode(A0, INPUT);
pinMode(A1, INPUT);
pinMode(button, INPUT_PULLUP);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
xval=analogRead(A0);
yval=analogRead(A1);
buttonstate=digitalRead(button);

Serial.print("X value=");
Serial.println(xval);
Serial.print("Y value=");
Serial.println(yval);
if(buttonstate==0){
  Serial.println("Button is ON");
  
}else{
  Serial.println("Button is OFF");
}

if(xval>700)
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

else if(xval<300){
  
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

else if(yval>700){
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
else if(yval<300){
  
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}else{

  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  }
}
