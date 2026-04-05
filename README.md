# SIGET - Implementación de Acceso a Medios
Implementación de acceso secuencial y aleatorio a archivos como parte del sistema SIGET (Sistema de Gestión de Tráfico), desarrollada en C++ para PC y Arduino ESP32 con SPIFFS y FreeRTOS.
## Tecnologías
- C++ con librería `fstream`
- Arduino (ESP32) con `SPIFFS` y `FreeRTOS`
- Arduino IDE 2.3.8
- Wokwi (simulador ESP32)
## Cómo ejecutar
### C++ (PC)
1. Tener instalado `g++` (MinGW en Windows)
2. Compilar:
g++ -o log_siget "log_siget.cpp"
3. Ejecutar:
   .\log_siget.exe
   ### Arduino (ESP32)
1. Abrir `log_siget.ino` en Arduino IDE 2.3.8
2. Seleccionar placa: `Tools → Board → ESP32 Dev Module`
3. Seleccionar partición: `Tools → Partition Scheme → Minimal SPIFFS`
4. Compilar con el botón ✓ Verify
### Wokwi (simulador)
1. Ir a [wokwi.com](https://wokwi.com) y crear proyecto ESP32
2. Pegar el contenido de `log_siget_wokwi.ino`
3. Dar Play ▶
