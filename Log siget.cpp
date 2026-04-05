/*
 * SIGET - Sistema de Gestión de Tráfico
 * Implementación de acceso a medios - C++
 * Autor: Jaime Hoyos
 * Materia: Sistemas Operativos
 *
 */

#include <iostream>   
#include <fstream>    
#include <string>   

using namespace std;

// ─────────────────────────────────────────────
// PASO 1: Crear el archivo con encabezado inicial
// ─────────────────────────────────────────────
void crear_log() {
    cout << "\n Creando log_siget.txt con el encabezado inicial..." << endl;

    ofstream archivo("log_siget.txt");

    if (!archivo.is_open()) {
        cout << "ERROR: No se pudo crear el archivo." << endl;
        return;
    }

    archivo << "Registro de eventos SIGET - Fecha: 2026-04-04, version: 1.0.0. ";
    archivo << "Este log captura datos cruciales para la optimizacion del trafico de la ciudad de Medellin. ";
    archivo << "Sensor aceleracion X:1.23 Y:2.34 Z:3.45 MPU6050." << endl;

    // Cerrar el archivo
    archivo.close();

    cout << "Archivo creado y cerrado correctamente." << endl;
}

// ─────────────────────────────────────────────
// PASO 2: Insertar ID de sensor en posición 10
// ─────────────────────────────────────────────
void actualizar_parametro() {
    cout << "Actualizando el parametro en posicion 10..." << endl;

    fstream archivo("log_siget.txt", ios::in | ios::out);

    if (!archivo.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo." << endl;
        return;
    }

    archivo.seekp(10, ios::beg);
    archivo << "ID_SENS_007";

    archivo.close();
    cout << "ID_SENS_007 insertado en posicion 10." << endl;
}

// ─────────────────────────────────────────────
// PASO 3: Reemplazar cada '3' por 'e' normalizando los datos
// ─────────────────────────────────────────────
void normalizar() {
    cout << "Normalizando datos: reemplazando '3' por 'e'..." << endl;

    // Primero leemos todo el contenido con seekg
    fstream archivo("log_siget.txt", ios::in | ios::out);

    if (!archivo.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo." << endl;
        return;
    }

    archivo.seekg(0, ios::beg);

    // Leemos todo el contenido del archivo en un string
    string contenido(
        (istreambuf_iterator<char>(archivo)),
        istreambuf_iterator<char>()
    );

    // Recorremos el string caracter por caracter
    int reemplazos = 0;
    for (char& c : contenido) {
        if (c == '3') {
            c = 'e';  
            reemplazos++;
        }
    }

    // Volvemos al inicio y sobreescribimos el archivo completo
    archivo.seekp(0, ios::beg);
    archivo << contenido;

    archivo.close();
    cout << "Normalizacion completa reemplazos realizados: " << reemplazos << endl;
}

// ─────────────────────────────────────────────
// PASO 4: Agregar alerta crítica al final del evento logístico
// ─────────────────────────────────────────────
void registrar_alerta() {
    cout << "Registrando alerta critica al final del archivo..." << endl;

    ofstream archivo("log_siget.txt", ios::app);

    if (!archivo.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo." << endl;
        return;
    }

    archivo << "Alerta: Verificar el estado del servidor ";

    archivo.close();
    cout << "Alerta critica registrada ." << endl;
}

// ─────────────────────────────────────────────
// mostrar el contenido actual del archivo
// ─────────────────────────────────────────────
void mostrar_contenido(const string& momento) {
    cout << "\n--- Contenido del archivo [" << momento << "] ---" << endl;

    ifstream archivo("log_siget.txt");
    if (!archivo.is_open()) {
        cout << "ERROR: No se pudo leer el archivo." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }

    archivo.close();
    cout << "--- Fin del contenido ---" << endl;
}

// ─────────────────────────────────────────────
// MAIN: punto de entrada del programa
// ─────────────────────────────────────────────
int main() {
    cout << "========================================" << endl;
    cout << "  SIGET - Implementacion de acceso a medios" << endl;
    cout << "  Plataforma: C++ (PC) con fstream" << endl;
    cout << "========================================" << endl;

    crear_log();
    mostrar_contenido("Primer Paso completado");

    actualizar_parametro();
    mostrar_contenido("Segundo Paso completado");

    normalizar();
    mostrar_contenido("Tercer Paso completado");

    registrar_alerta();
    mostrar_contenido("Cuarto Paso completado");

    cout << "Pasos ejecutados correctamente." << endl;
    return 0;
}