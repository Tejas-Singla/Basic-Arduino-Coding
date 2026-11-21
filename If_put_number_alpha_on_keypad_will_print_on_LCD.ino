# include<Keypad.h>
# include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16,2);

char keys[4][4]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[4]={2,3,4,5};
byte colPins[4]={6,7,8,9};

Keypad keypad = Keypad(makeKeymap(keys),rowPins, colPins, 4,4);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

lcd.init();
lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
char Key = keypad.getKey();

String Input="";
if(Key){
  Serial.print(Key);
  Input=Input+Key;
  lcd.setCursor(0,0);
  lcd.print(Input);
  delay(1000);
  lcd.clear();
}
}
