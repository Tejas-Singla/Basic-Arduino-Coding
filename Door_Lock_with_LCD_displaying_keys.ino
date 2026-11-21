#include<Keypad.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27 , 16,2);


char keys [4][4] ={{'1','2','3','A'},
                   {'4','5','6','B'},
                   {'7','8','9','C'},
                   {'*','0','#','D'}
                   };

byte rowPins[4]={2,3,4,5};
byte colPins[4]={6,7,8,9};

Keypad keypad = Keypad(makeKeymap(keys),rowPins,colPins,4,4);

String correctPassword="55555";
String enteredPassword="";

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

lcd.init();
lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
char key=keypad.getKey();

if(key){

  enteredPassword=enteredPassword+key;
  lcd.setCursor(0,0); 
  lcd.print(enteredPassword);
  Serial.println(enteredPassword);
}if (enteredPassword.length()==5){

  if(enteredPassword==correctPassword){
    lcd.setCursor(0,1);
    lcd.print("Door Unlocked");
    Serial.println("Door Unlocked");
  }else{
    lcd.setCursor(0,1);
    lcd.print("Door Locked");
    Serial.println("Door Locked");
  }

  delay(3000);
  lcd.clear();
  enteredPassword="";
}
}
