#include <Arduino.h>
#include <Wire.h>
#include "BH1750.h"
#include "device.h"

BH1750 lightMeter;

void setup() {
  Serial.begin(115200);
  delay(200);
  Wire.begin(PIN_SDA, PIN_SCL);
  lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE, 0x23, &Wire);
  Serial.println("System ready...");
}

void loop() {
  float lux = lightMeter.readLightLevel();
  Serial.printf("Light: %.2f lx\n", lux);
  delay(1000);
}