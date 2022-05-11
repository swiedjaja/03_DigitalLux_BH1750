#include <Arduino.h>
#include <Wire.h>
#include "BH1750.h"
#include "device.h"

BH1750 lightMeter;

void setup() {
  Serial.begin(115200);
  delay(200);
  #if defined(NODEMCU_ESP32_C3_13)  
    pinMode(LED_BUILTIN_COOL, OUTPUT);
  #endif  
  pinMode(LED_BUILTIN, OUTPUT);
  delay(1000);

  Serial.printf("Arduino Board: %s variant: %s\n", ARDUINO_BOARD, ARDUINO_VARIANT);
  Serial.printf("Chip model: %s, Core: %d, CPU Freq: %u\n", 
    ESP.getChipModel(), ESP.getChipCores(), ESP.getCpuFreqMHz());
  Serial.printf("Flash size: %u, speed: %u, mode: %d\n", ESP.getFlashChipSize(), ESP.getFlashChipSpeed(), ESP.getFlashChipMode());
  Serial.printf("PSRAM size: %u, free: %u\n", ESP.getPsramSize(), ESP.getFreePsram());
  Serial.printf("Heap size: %u, free: %u\n", ESP.getHeapSize(), ESP.getFreeHeap());

  Wire.begin(PIN_SDA, PIN_SCL);
  lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE, 0x23, &Wire);
  Serial.println("System ready...");
}

int nCount=0;
void loop() {
  float lux = lightMeter.readLightLevel();
  Serial.printf("Light: %.2f lx\n", lux);
  // delay(1000);
  digitalWrite(LED_BUILTIN, LED_ON);
  Serial.printf("Hello World %d\n", nCount++);
  delay(100);
  digitalWrite(LED_BUILTIN, LED_OFF);
  delay(1000);

}