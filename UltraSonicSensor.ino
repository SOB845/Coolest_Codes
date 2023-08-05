#include <neotimer.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

const byte BasePin = 2;
const byte trig = 5;
const byte echo = 7;
float distance, duration;
Neotimer limit = Neotimer(10000);

void setup() {
  lcd.init();
  lcd.clear();
  lcd.backlight();
  pinMode(BasePin, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig , LOW);
  delayMicroseconds(2); 
  digitalWrite(trig, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trig, LOW);

  noInterrupts();
  duration = pulseIn(echo,HIGH);
  distance = (duration*0.0343)/2;
  Serial.println(distance);
  interrupts();


  if(distance < 230.0){
    limit.start();
    lcd.setCursor(1,0);
   
    while(limit.waiting()){
      digitalWrite(BasePin,HIGH);
      if (limit.done()){
        limit.stop();
        digitalWrite(BasePin, LOW);
      }
      break;
      }
    //lcd.clear();
    }
      
  else{
    digitalWrite(BasePin,LOW);
    lcd.setCursor(3,0);
    lcd.print("DISTANCE:");
    lcd.setCursor(2,1);
    lcd.print(String(distance));
    lcd.setCursor(10,1);
    lcd.print("cm");
    delay(60);
   }
  
}
