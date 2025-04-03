#include <CapacitiveSensor.h>
/*
 * Coin Touch Sensor
 * Uses a coin as a capacitive touch sensor
 * Send pins: 4,8
 * Receive pins: 2,7
 * Adjust the threshold value for your specific setup
 * 
 * WARNING!!!
 * samples, DashThreshold, DotTreshold and sensor speed must be fine-tooned by hand!
 */

CapacitiveSensor dash = CapacitiveSensor(4,2); // 1M resistor between pins 4 & 2, pin 2 is sensor pin
CapacitiveSensor dot = CapacitiveSensor(8,7); // 1M resistor between pins 8 & 7, pin 7 is sensor pin

const int samples = 100; // Number of samples taken per reading (higher = slower but more stable)
unsigned long lastDashTime = 0;
unsigned long lastDotTime = 0;
unsigned long lastRelease = 0;

void setup() {
  Serial.begin(9600);
  dash.set_CS_AutocaL_Millis(0xFFFFFFFF);
  dot.set_CS_AutocaL_Millis(0xFFFFFFFF); // Turn off autocalibrate 0xFFFFFFFF
  dash.set_CS_Timeout_Millis(10); // Faster timeout
  dot.set_CS_Timeout_Millis(10);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  /* Beware, 'timer' doesn't do the counting, it just captures
    Arduino's internal clock value at the start of each loop
  */
  unsigned long timer = millis();
  
  long DashSense = dash.capacitiveSensor(samples); //Raw capacitance reading (higher = more touch)
  long DotSense = dot.capacitiveSensor(samples);
  
  // Adjust this threshold value based on your serial monitor readings
  // below these values, the capacitive sensor will read LOW
  const int DashThreshold = 120;
  const int DotThreshold = 180;

  //SensorMonitor(DashSense,DotSense); // Call for calibrating the thresholds
  
  if (DashSense > DashThreshold && timer - lastDashTime >= 150){
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.print("-");
    lastDashTime = timer;
    lastRelease = timer;
    digitalWrite(LED_BUILTIN, LOW);
  } 
  if (DotSense > DotThreshold && timer - lastDotTime >= 30){
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.print(".");
    lastDotTime = timer;
    lastRelease = timer;
    digitalWrite(LED_BUILTIN, LOW);
  }
  else if (timer - lastRelease >= 1000 && lastRelease != 0){  
    Serial.print("/");
    lastRelease = 0;
  }
 delay(100); // Sensor reading speed
}
void SensorMonitor(long readingDash, long readinDot){
  Serial.print(readingDash);
  Serial.print("|");
  Serial.print(readinDot);
  Serial.println("");
  delay(50);
  }
