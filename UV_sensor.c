/*
    Project name : ESP8266 UV Sensor
    Modified Date: 20-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/esp8266-uv-sensor
*/

#include <Wire.h>
#include <VEML6070.h>

VEML6070 veml;

void setup() {
  Serial.begin(9600); // Initialize serial communication
  Wire.begin(D2, D1);  // Begin I2C communication (SDA pin, SCL pin)

  if (!veml.begin()) {
    Serial.println("Failed to communicate with VEML6070 sensor!");
    while (1);
  }

  Serial.println("VEML6070 UV Sensor initialized successfully!");
}

void loop() {
  float uvIndex = veml.readUVI();

  Serial.print("UV Index: ");
  Serial.println(uvIndex);

  delay(1000); // Delay before taking the next reading
}
