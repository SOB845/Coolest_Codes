#include <Timer.h>
#include <HCSR04.h>

Timer timer;
HCSR04 hc(12,13); // HCSR04 (trig pin , echo pin)
const byte BasePin = 2; // The pin that controls the base of a transistor
unsigned const TimeLimit = 15000;

void setup() {
  pinMode(BasePin, OUTPUT);
}

void loop() {
  delay(60);
  digitalWrite(BasePin, LOW);
  if (hc.dist() < 270.0){
      timer.start();

      while (timer.read() < TimeLimit) {
        digitalWrite(BasePin, HIGH);
        }
  }   
}
