const int PhonePin = 2;
const int BasePin = 4;
int threshold = 300;
int clapCounter = 0;
unsigned long currentMillis,sec;


void setup() {
  pinMode(BasePin, OUTPUT);
  digitalWrite(BasePin, LOW);
}

void loop() {
  int Sound = digitalRead(PhonePin);
  if (Sound == HIGH){
    delay(10);
    clapCounter++;
    currentMillis= millis();
      
    while (clapCounter >= 2){
      if (Sound == HIGH){
        sec = millis();
        //clapCounter++;
      
      if ((sec - currentMillis) < 2000){         
        digitalWrite(BasePin,HIGH);
        delay(5000);
        digitalWrite(BasePin, LOW);
        clapCounter = 0;
        }
      }  
       break;
      //sec = millis();
  }
 }
}  
