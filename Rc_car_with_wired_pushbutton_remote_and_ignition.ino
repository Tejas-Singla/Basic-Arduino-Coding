int in1=8;
int in2=9;
int in3=7;
int in4=6;
int ena=10;
int enb=11;
int button1=5;
int button2=4;
int chabiButton=3;
int buttonState1;
int buttonState2;
bool lastChabiState=HIGH;
bool codeState=LOW;
int chabiState;

void setup() {
  // put your setup code here, to run once:

pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
pinMode(ena, OUTPUT);
pinMode(enb, OUTPUT);
pinMode(button1, INPUT_PULLUP);
pinMode(button2, INPUT_PULLUP);
pinMode(chabiButton, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:

chabiState=digitalRead(chabiButton);

if(chabiState==0 && lastChabiState==1){

  codeState=!codeState;
}

if(codeState==true){

buttonState1=digitalRead(button1);
buttonState2=digitalRead(button2);


if(buttonState1==0){

analogWrite(ena, 200);
analogWrite(enb, 200);
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
}

else if(buttonState2== 0){
analogWrite(ena, 200);
analogWrite(enb, 200);
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);

}
else{


digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);

}

}
lastChabiState=chabiState;
}