// C++ code
//
int button=9;
int red=13;
int yellow = 12;
int green=11;
int blue=10;
int buttonState;

void setup()
{
  pinMode( red, OUTPUT);
  pinMode (yellow, OUTPUT);
  pinMode (green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop()
{
  buttonState=digitalRead(button);
  
  if(buttonState==0){
  digitalWrite(red,HIGH);
  digitalWrite(yellow,LOW);
  digitalWrite(green,LOW);
  digitalWrite(blue,HIGH);
    
  delay(1000);
    
  digitalWrite(red,LOW);
  digitalWrite(yellow,LOW);
  digitalWrite(green,LOW);
  digitalWrite(blue,LOW);
   
  }
  else{
    digitalWrite(red, HIGH);
    delay(1000);
    digitalWrite(red, LOW);
    
    digitalWrite(yellow, HIGH);
    delay(1000);
    digitalWrite(yellow, LOW);
    
    digitalWrite(green, HIGH);
    delay(1000);
    digitalWrite(green, LOW);
  }
    
} 