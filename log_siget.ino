/*
 * SIGET - Sistema de Gestión de Tráfico
 * Implementación de acceso a medios - Arduino (ESP32)
 * Autor: Jaime Hoyos
 * Materia: Sistemas Operativos
 */

#include <Arduino.h>

// ─────────────────────────────────────────────
// Simulación del archivo en memoria RAM
// ─────────────────────────────────────────────
String archivoRAM = "";  
// ─────────────────────────────────────────────
void crear_log() {
  Serial.println("\n Creando log_siget.txt con encabezado inicial...");
  archivoRAM = "";
  archivoRAM += "Registro de eventos SIGET - Fecha: 2026-04-04, version: 1.0.0. ";
  archivoRAM += "Este log captura datos cruciales para la optimizacion del trafico. ";
  archivoRAM += "Sensor aceleracion X:1.23 Y:2.34 Z:3.45 MPU6050.\n";

  Serial.println("Archivo creado correctamente.");
}

void actualizar_parametro() {
  Serial.println("\nActualizando parametro en posicion 10");
  String idSensor = "ID_SENS_007";
  archivoRAM = archivoRAM.substring(0, 10) + idSensor + archivoRAM.substring(10 + idSensor.length());

  Serial.println("ID_SENS_007 insertado en posicion 10.");
}

void normalizar() {
  Serial.println("\nNormalizando datos: reemplazando '3' por 'e'...");

  int reemplazos = 0;
  for (int i = 0; i < archivoRAM.length(); i++) {
    if (archivoRAM[i] == '3') {
      archivoRAM[i] = 'e';
      reemplazos++;
    }
  }

  Serial.print("Normalizacion completa. Reemplazos: ");
  Serial.println(reemplazos);
}
void registrar_alerta() {
  Serial.println("\nRegistrando alerta critica...");

  archivoRAM += "\nAlerta: Verifique el estado del servidor de optimizacion de rutas. ";

  Serial.println("Alerta critica registrada.");
}

// ─────────────────────────────────────────────
// Mostrar contenido del archivo
// ─────────────────────────────────────────────
void mostrar_contenido(const char* momento) {
  Serial.print("\n--- Contenido [");
  Serial.print(momento);
  Serial.println("] ---");
  Serial.println(archivoRAM);
  Serial.println("--- Fin ---");
}

// ─────────────────────────────────────────────
// TAREA FREERTOS
// ─────────────────────────────────────────────
void taskSIGET(void* parameter) {
  Serial.println("========================================");
  Serial.println("  SIGET - Implementacion de acceso a medios");
  Serial.println("========================================");

  crear_log();
  mostrar_contenido("PASO 1");
  vTaskDelay(500 / portTICK_PERIOD_MS);

  actualizar_parametro();
  mostrar_contenido("PASO 2");
  vTaskDelay(500 / portTICK_PERIOD_MS);

  normalizar();
  mostrar_contenido("PASO 3");
  vTaskDelay(500 / portTICK_PERIOD_MS);

  registrar_alerta();
  mostrar_contenido("FINAL");

  Serial.println("\nTodos los pasos ejecutados correctamente.");

  vTaskDelete(NULL);
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("Sistema iniciado correctamente.");

  xTaskCreate(
    taskSIGET,
    "TaskSIGET",
    8192,
    NULL,
    1,
    NULL
  );
}

void loop() {
}
