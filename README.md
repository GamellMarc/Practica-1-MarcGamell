# Pràctica 1 - Processadors Digitals

Aquest repositori conté els projectes i la memòria corresponents a la **Pràctica 1** de l'assignatura de Processadors Digitals. L'objectiu principal d'aquesta pràctica és la familiarització amb l'entorn de desenvolupament PlatformIO, la programació en C++ (framework Arduino) i el control del maquinari del microcontrolador **ESP32-S3**.

## 📂 Estructura del Repositori

El repositori està dividit en les següents carpetes i fitxers:

* **`Practica1_Blink/`**: Conté el projecte principal de PlatformIO. Hi ha implementat el codi per:
    * Controlar el parpelleig periòdic d'un LED (Blink).
    * Llegir un valor d'un convertidor A/D (12 bits) i mapejar-lo a una sortida PWM (8 bits).
    * Llegir i mostrar la temperatura interna del silici del xip.
* **`Practica1Complementari/`**: Conté el projecte corresponent a l'activitat complementària. Inclou:
    * L'ús de la llibreria externa `Adafruit_NeoPixel`.
    * El control del LED RGB integrat a la placa (visualització d'una seqüència de 7 colors).
    * L'extracció i visualització de les característiques del maquinari (model, MAC, memòria, etc.) pel terminal sèrie.
* **`InformePràctica1PD.pdf`**: Memòria completa de la pràctica que inclou l'explicació detallada del codi, els diagrames de flux, els diagrames de temps i l'anàlisi de l'ocupació (temps lliure) del processador.

## 🛠️ Tecnologies i Maquinari Utilitzat

* **Placa:** YD-ESP32-S3 (Compatible amb ESP32-S3-DevKitC-1)
* **Entorn de desenvolupament:** Visual Studio Code + extensió PlatformIO
* **Llenguatge:** C++ (Framework d'Arduino)
* **Comunicació:** Monitor sèrie a 115200 bauds.

## 👤 Autor
**Marc Gamell**
