#include <stdio.h>
#include "monitor.h"

#define NUM_ZONAS 5
#define LIMITE_PM25 25.0
#define LIMITE_CO2 400.0
#define LIMITE_SO2 20.0
#define LIMITE_NO2 40.0

// Datos simulados de contaminación actual
float pm25_actual[NUM_ZONAS] = {30.5, 22.0, 18.5, 27.0, 35.0};
float co2_actual[NUM_ZONAS] = {450.0, 380.0, 400.0, 420.0, 460.0};
float so2_actual[NUM_ZONAS] = {25.0, 15.0, 10.0, 20.0, 30.0};
float no2_actual[NUM_ZONAS] = {50.0, 35.0, 25.0, 45.0, 55.0};

void calcularPromedioContaminacionActual() {
    printf("\nPromedio de contaminación actual por zona:\n");
    for (int i = 0; i < NUM_ZONAS; i++) {
        float promedio = (pm25_actual[i] + co2_actual[i] + so2_actual[i] + no2_actual[i]) / 4;
        printf("Zona %d: Promedio de contaminación: %.2f\n", i + 1, promedio);
    }
}

void calcularContaminacionActual() {
    printf("\nMonitoreo de contaminación actual:\n");
    for (int i = 0; i < NUM_ZONAS; i++) {
        if (pm25_actual[i] < 0 || co2_actual[i] < 0 || so2_actual[i] < 0 || no2_actual[i] < 0) {
            printf("Error: Datos inválidos para la zona %d.\n", i + 1);
            continue;
        }
        printf("Zona %d:\n", i + 1);
        printf("  PM2.5: %.2f %s\n", pm25_actual[i], pm25_actual[i] > LIMITE_PM25 ? "(Excede límite)" : "(Aceptable)");
        printf("  CO2: %.2f %s\n", co2_actual[i], co2_actual[i] > LIMITE_CO2 ? "(Excede límite)" : "(Aceptable)");
        printf("  SO2: %.2f %s\n", so2_actual[i], so2_actual[i] > LIMITE_SO2 ? "(Excede límite)" : "(Aceptable)");
        printf("  NO2: %.2f %s\n", no2_actual[i], no2_actual[i] > LIMITE_NO2 ? "(Excede límite)" : "(Aceptable)");
    }
    calcularPromedioContaminacionActual();
}
