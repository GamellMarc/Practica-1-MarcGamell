#include <Arduino.h>

#define LED_PIN 4
#define ADC_PIN 1
#define DAC_PIN 25

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  analogReadResolution(12);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  Serial.println("ON");

  int adcValue = analogRead(ADC_PIN);
  int dacValue = map(adcValue, 0, 4095, 0, 255);
  dacWrite(DAC_PIN, dacValue);

  Serial.print("ADC:");
  Serial.print(adcValue);
  Serial.print(" DAC:");
  Serial.println(dacValue);

  float temp = temperatureRead();
  Serial.print("Temp:");
  Serial.println(temp);

  delay(500);

  digitalWrite(LED_PIN, LOW);
  Serial.println("OFF");

  delay(500);
}