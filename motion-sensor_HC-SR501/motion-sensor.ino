/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-motion-sensor-led
 */

const int MOTION_SENSOR_PIN = 5;   // Arduino pin connected to the OUTPUT pin of motion sensor
int motionStateCurrent      = LOW; // current  state of motion sensor's pin
int motionStatePrevious     = LOW; // previous state of motion sensor's pin

void setup() {
  Serial.begin(9600);                // initialize serial
  pinMode(MOTION_SENSOR_PIN, INPUT); // set arduino pin to input mode
}

void loop() {
  motionStatePrevious = motionStateCurrent;             // store old state
  motionStateCurrent  = digitalRead(MOTION_SENSOR_PIN); // read new state
  Serial.println(digitalRead(MOTION_SENSOR_PIN));
  
  if (motionStatePrevious == LOW && motionStateCurrent == HIGH) { // pin state change: LOW -> HIGH
    Serial.println("Motion detected!");
  }
  else if (motionStatePrevious == HIGH && motionStateCurrent == LOW) { // pin state change: HIGH -> LOW
    Serial.println("Motion stopped!");
  }

}
