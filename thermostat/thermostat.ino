// TMP36 (Thermometer) pin
int tmp36Pin = A0;

void setup() {
  // Start serial port at 9600 baud
  Serial.begin(9600);

}

void loop() {
  // Get the temp from the TMP36 sensor
  int temp = getTemp(tmp36Pin);

  Serial.print("Current Temperature: ");
  Serial.print(temp);
  Serial.print("");

  delay(30000);

}

// Get the temperature from the sensor
int getTemp(int sensor) {
  // Get the sensor data
  int sensorValue = getAnalogValue(sensor);
  // Convert the sensor data to metric temperature
  double metricTemp = getMetric(sensorValue);
  // Convert meteric temperature to imperial.
  int imperialTemp = getImperial(metricTemp);
  // Return the imperial temperature.
  return imperialTemp;
}

// read anlog value of sensor.
int getAnalogValue(int sensor) {
  return analogRead(sensor);
}

// Convert the analog sensor value to a usable temp.
double getMetric(int sensorData) {
  // Find percentage of analog value.
  double temp = (double)sensorData / 1024;
  // Multiply by 5V to get voltage.
  temp = temp * 5;
  // Subtract offset.
  temp = temp - 0.5;
  // Multiply by 100 to get temperature.
  temp = temp * 100;

  return temp;
}

// Convert metric to imperial
int getImperial(double temp) {
  return (temp * 9 / 5) + 32; 
}