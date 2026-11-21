#define BLYNK_TEMPLATE_ID "TMPL3v20vdzRl"
#define BLYNK_TEMPLATE_NAME "RC Car"
#define BLYNK_AUTH_TOKEN "0jd3SWvpUIX8FJZeCbolXlxWGIxaqr1j"

#include<WiFi.h>
#include<BlynkSimpleEsp32.h>

char ssid[]="sudha's phone";
char password[]="Tejas@1610";


int in1=0;
int in2=4;
int xval=512;
int yval=512;

void forward(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}

void backward(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}

void stop(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}


BLYNK_WRITE(V0){
  if(param.asInt()==1){
    forward();
  }else{
stop();
  }
}

BLYNK_WRITE(V1){
if(param.asInt()==1){
  backward();
}else{
  stop();
}
}

BLYNK_WRITE(V3){
  yval=param.asInt();

  if(yval>700){
    forward();
  }else if(yval<400){
    backward();
  }else{
    stop();
  }
}


void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);

pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);

Blynk.begin(BLYNK_AUTH_TOKEN,ssid,password);
}

void loop() {
  // put your main code here, to run repeatedly:
Blynk.run();
}

