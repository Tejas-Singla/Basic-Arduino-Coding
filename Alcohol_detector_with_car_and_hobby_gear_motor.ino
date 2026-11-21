 #include <Wire.h>
 #include <LiquidCrystal_I2C.h>


 //LCD I2C address (most common: 0x27)
 LiquidCrystal_I2C lcd(0x27, 16, 2);
 //Pin definitions
 #define MQ3_PIN A0
 #define RELAY_PIN 7
 #define BUZZER_PIN 8

 int sensorValue = 0;
 int threshold = 500; //Change after testing

 
 void setup() { 
   // put your setup code here, to run once: 
   pinMode(RELAY_PIN, OUTPUT);
   pinMode(BUZZER_PIN, OUTPUT);

   digitalWrite(RELAY_PIN, LOW);
   digitalWrite(BUZZER_PIN, LOW);

   lcd.init();
   lcd.backlight();

   lcd.setCursor(0, 0);
   lcd.print("Alcohol Detector");
   lcd.setCursor(0, 1);
   lcd.print("Warning Sensor");

   delay(3000);
   lcd.clear();
     
   }

void loop() {
  // put your main code here, to run repeatedly:
sensorValue = analogRead(MQ3_PIN);

lcd.setCursor(0, 0);
lcd.print("Value: ");
lcd.print(sensorValue);
lcd.print("   ");

if (sensorValue > threshold) {
  digitalWrite(RELAY_PIN, HIGH);
  digitalWrite(BUZZER_PIN, HIGH);

  lcd.setCursor(0, 1);
  lcd.print("Alcohol Detected");
}else{
digitalWrite(RELAY_PIN, LOW);
digitalWrite(BUZZER_PIN, LOW);

lcd.setCursor(0, 1);
lcd.print("Safe Level   ");
}

delay(1000);
}
