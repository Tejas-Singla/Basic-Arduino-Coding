void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()){

  String data=Serial.readStringUntil("\n"); // the \n matlab new line tak hi read kare 
  data.trim();

  Serial.print(data);

if (data=="LED ON"){
  digitalWrite(13, HIGH);
}

if(data=="LED OFF"){
  digitalWrite(13, LOW);
}
}

}
