#include <stdio.h>
#include "prediccion.h"

#define NUM_ZONAS 5
#define DIAS_HISTORICOS 7

// Datos simulados de contaminación histórica (últimos 7 días)
float pm25_historico[NUM_ZONAS][DIAS_HISTORICOS] = {
    {28.0, 30.0, 32.0, 29.0, 31.0, 30.5, 30.0},
    {20.0, 22.0, 23.0, 21.0, 22.5, 22.0, 22.0},
    {18.0, 19.0, 20.0, 18.5, 19.5, 18.5, 18.0},
    {25.0, 26.0, 27.0, 26.5, 27.5, 27.0, 27.0},
    {33.0, 34.0, 35.0, 34.5, 35.5, 35.0, 35.0}
};

// Factores climáticos actuales
float temperatura[NUM_ZONAS] = {25.0, 22.0, 20.0, 24.0, 26.0};
float velocidad_viento[NUM_ZONAS] = {5.0, 3.0, 4.0, 6.0, 5.0};
float humedad[NUM_ZONAS] = {60.0, 55.0, 50.0, 65.0, 70.0};

float calcularPromedioPonderado(float datos[DIAS_HISTORICOS]) {
    float peso_total = 0.0;
    float suma_ponderada = 0.0;
    for (int i = 0; i < DIAS_HISTORICOS; i++) {
        float peso = DIAS_HISTORICOS - i; // Más peso para días recientes
        suma_ponderada += datos[i] * peso;
        peso_total += peso;
    }
    return suma_ponderada / peso_total;
}

float ajustarPorClima(float prediccion, float temperatura, float viento, float humedad) {
    // Ajuste simple basado en factores climáticos
    float ajuste = (temperatura * 0.1) - (viento * 0.2) + (humedad * 0.05);
    return prediccion + ajuste;
}

void predecirContaminacion() {
    printf("\nPredicción de niveles futuros de contaminación:\n");
    for (int i = 0; i < NUM_ZONAS; i++) {
        if (pm25_historico[i][0] < 0) {
            printf("Error: Datos históricos inválidos para la zona %d.\n", i + 1);
            continue;
        }
        float pm25_predicho = calcularPromedioPonderado(pm25_historico[i]);
        pm25_predicho = ajustarPorClima(pm25_predicho, temperatura[i], velocidad_viento[i], humedad[i]);
        printf("Zona %d: PM2.5 predicho ajustado por clima: %.2f\n", i + 1, pm25_predicho);
    }
}
