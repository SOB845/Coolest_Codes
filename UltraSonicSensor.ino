// Progam to control a digital pin using an HC-SR04 ultrasonic sensor via distance measurement

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

const byte BasePin = 2; // I use this pin to control the base of an NPN transistor hence the naming
const byte trig = 5;
const byte echo = 7;
float distance, duration;
bool isBaseHigh;

unsigned long prevTime = 0;
unsigned const TimeLimit = 15000; // How long should BasePin stay HIGH

void setup() {
  lcd.init();
  lcd.clear();
  lcd.backlight();
  pinMode(BasePin, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  unsigned long currentTime = millis();
  
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

  lcd.setCursor(3,0);
  lcd.print("DISTANCE:");
  lcd.setCursor(2,1);
  lcd.print(String(distance));
  lcd.setCursor(10,1);
  lcd.print("cm");
  delay(60);

  // The distance unit is in centimeters, which I set its threshold to be 270 cm
  // You may want to change it
  if(distance < 270.0){
    if (digitalRead(BasePin)== LOW){
      digitalWrite(BasePin, HIGH);
      isBaseHigh = true;      
      }
      
    if (currentTime - prevTime >= TimeLimit){
      // If time difference between currentTime and prevTime is more than 15 secs...
      digitalWrite(BasePin, LOW);
      isBaseHigh = false;
      prevTime = currentTime; // Update prevTime (originally set to 0) to be 15s in the first iteration, 30 in the second & so on
      // This allows the BasePin to stay HIGH for TimeLimit without using delay()
      }
  }    
  else{
    if (isBaseHigh == true && (currentTime - prevTime) >= TimeLimit){
      digitalWrite(BasePin, !isBaseHigh);
      }
    
   }
  
}
