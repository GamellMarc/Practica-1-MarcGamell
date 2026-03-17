#include <Arduino.h>
#include <Adafruit_NeoPixel.h>  // Incluimos la librería Adafruit_NeoPixel

// pin del led RGB en PCB
#define PIN       48  // ESP32S3 Generic -n8r2-

// Un solo led en PCB
#define NUMPIXELS 1

// Inicializamos el objeto "pixels"
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// REQUISITO: Duración de 1 segundo (1000 ms) 
#define DELAYVAL 1000 

void setup() {
  delay(500);
  
  // Inicializamos el objeto pixels
  pixels.begin(); 

  // REQUISITO: Intensidad lumínica mínima 
  // Configuramos el brillo global a un valor bajo (0-255). 
  // 5-10 es suficientemente bajo para no deslumbrar pero ser visible.
  pixels.setBrightness(10); 
  
  Serial.begin(115200);
  delay(500);

  // --- Información del chip (Mantenido del código original) ---
  Serial.println("\n\n================================");
  Serial.printf("Chip Modelo: %s\n", ESP.getChipModel());
  Serial.printf("Chip Revision: %d\n", ESP.getChipRevision());
  Serial.printf("E %d core\n", ESP.getChipCores());
  Serial.printf("Flash Chip capacidad: %d \n", ESP.getFlashChipSize());
  Serial.printf("Flash Chip velocidad: %d \n", ESP.getFlashChipSpeed());

  esp_chip_info_t chip_info;
  esp_chip_info(&chip_info);
  Serial.printf("\nCaracteristicas:\n %s\n %s\n %s\n %s\n %s\n",
      (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "flash en ESP32" : "Sin flash en ESP32",
      (chip_info.features & CHIP_FEATURE_WIFI_BGN) ? "2.4GHz WiFi" : "Sin Wifi",
      (chip_info.features & CHIP_FEATURE_BLE) ? "Bluetooth LE" : "Sin Bluetooth LE",
      (chip_info.features & CHIP_FEATURE_BT) ? "Bluetooth" : "Sin Bluetooth",
      (chip_info.features & CHIP_FEATURE_IEEE802154) ? "IEEE 802.15.4" : "NO IEEE 802.15.4");
  
  // MAC Address
  String MACString = "";
  uint64_t chipid = ESP.getEfuseMac(); 
  for (int i=0; i<6; i++) {
    if (i > 0) MACString.concat(":");
    uint8_t Octet = chipid >> (i * 8);
    MACString.concat(String(Octet, HEX));
  }
  Serial.println("MAC: " + MACString);
}

void loop() {
  // REQUISITO: Visualizar los 6 colores básicos (RGBCMY) y finalmente Blanco 
  
  // 1. ROJO (Red)
  pixels.setPixelColor(0, pixels.Color(255, 0, 0));
  pixels.show();
  Serial.println("Color: Rojo");
  delay(DELAYVAL);

  // 2. VERDE (Green)
  pixels.setPixelColor(0, pixels.Color(0, 255, 0));
  pixels.show();
  Serial.println("Color: Verde");
  delay(DELAYVAL);

  // 3. AZUL (Blue)
  pixels.setPixelColor(0, pixels.Color(0, 0, 255));
  pixels.show();
  Serial.println("Color: Azul");
  delay(DELAYVAL);

  // 4. CIAN (Cyan = Verde + Azul)
  pixels.setPixelColor(0, pixels.Color(0, 255, 255));
  pixels.show();
  Serial.println("Color: Cian");
  delay(DELAYVAL);

  // 5. MAGENTA (Magenta = Rojo + Azul)
  pixels.setPixelColor(0, pixels.Color(255, 0, 255));
  pixels.show();
  Serial.println("Color: Magenta");
  delay(DELAYVAL);

  // 6. AMARILLO (Yellow = Rojo + Verde)
  pixels.setPixelColor(0, pixels.Color(255, 255, 0));
  pixels.show();
  Serial.println("Color: Amarillo");
  delay(DELAYVAL);

  // 7. BLANCO (White = Rojo + Verde + Azul)
  pixels.setPixelColor(0, pixels.Color(255, 255, 255));
  pixels.show();
  Serial.println("Color: Blanco");
  delay(DELAYVAL);

  // Opcional: Apagar brevemente antes de reiniciar el ciclo
  pixels.clear();
  pixels.show();
  delay(100); 
}