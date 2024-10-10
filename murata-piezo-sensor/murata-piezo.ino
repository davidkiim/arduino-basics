float alpha = 0.1;  // Smoothing factor (0 < alpha < 1)
float filteredValue = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int rawValue = analogRead(A0);  // Read the raw signal
  float currentValue = rawValue * (5.0 / 1023.0);  // Convert to voltage (for a 5V Arduino)
  
  
  
  // Initialize the filtered value with the first reading (only at the start)
  if (filteredValue == 0) {
    filteredValue = currentValue;
  }

  // Apply exponential smoothing
  filteredValue = alpha * currentValue + (1 - alpha) * filteredValue;

  // Output the initial (raw) value and the filtered value
  // Serial.print("Raw Value: ");
  // Serial.print(currentValue);
  // Serial.print(" V, Filtered Value: ");
  // Serial.print(filteredValue);
  // Serial.println(" V");

  Serial.print(0); // To freeze the lower limit
  Serial.print(" ");
  Serial.print(1000); // To freeze the upper limit
  Serial.print(" ");
  
  Serial.println(rawValue);
  // Serial.println(filteredValue);

  delay(1);  // Add a short delay for stability
}
