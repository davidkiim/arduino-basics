// Define pin numbers
const int irSensorPin = 2;   // IR Sensor connected to digital pin 2
 
void setup() {
  Serial.begin (9600);
  pinMode(irSensorPin, INPUT);  // Set the IR sensor pin as input
}
 
void loop() {
  int sensorState = digitalRead(irSensorPin); // Read the state from the IR sensor
 
  // The sensor outputs LOW when it detects an obstacle
  if (sensorState == LOW) {  
    Serial.println("DETECTED");
  } else {
    Serial.println("NOT DETECTED");   // Turn the LED off
  }
 
  delay(100);  // Wait for 100 milliseconds
}
