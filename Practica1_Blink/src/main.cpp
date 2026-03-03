#include <Arduino.h>

#define LED_PIN 35
#define ADC_PIN 1
#define PWM_PIN 36 // En l'S3, qualsevol pin pot fer de PWM

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  
  // Configurem la resolució de l'ADC (0-4095)
  analogReadResolution(12);
  
  // Opcional: pots definir la resolució del PWM si vols (per defecte és 8 bits: 0-255)
  // analogWriteResolution(8); 
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  Serial.println("--- INICI CICLE ---");

  // 1. Llegim el valor analògic (Potenciòmetre o sensor)
  int adcValue = analogRead(ADC_PIN);

  // 2. Mapegem el valor de l'ADC (12 bits) al PWM (8 bits)
  // De 0-4095 a 0-255
  int pwmValue = map(adcValue, 0, 4095, 0, 255);

  // 3. Enviem el senyal (Substitueix dacWrite que no existeix a l'S3)
  analogWrite(PWM_PIN, pwmValue);

  // Mostrem dades per consola
  Serial.print("Entrada ADC: ");
  Serial.print(adcValue);
  Serial.print(" | Sortida PWM: ");
  Serial.println(pwmValue);

  // 4. Lectura de temperatura interna del xip
  // Nota: És la temperatura del silici, no de l'ambient.
  float temp = temperatureRead();
  Serial.print("Temp. Interna ESP32-S3: ");
  Serial.print(temp);
  Serial.println(" °C");

  delay(500);

  digitalWrite(LED_PIN, LOW);
  Serial.println("LED OFF");

  delay(500);
}