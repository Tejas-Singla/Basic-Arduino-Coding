int in1 = 11;
int in2 = 10;
int in3 = 9;
int in4 = 6;

void setup() {
  // put your setup code here, to run once:
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//motor clockwise
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
delay(3000);

//Motor anti clockwise
digitalWrite(in1,LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
delay(3000);

//turn
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
delay(3000);

//turn
digitalWrite(in1,LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
delay(3000);
}
