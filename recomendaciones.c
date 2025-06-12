#include <stdio.h>
#include "recomendaciones.h"

#define NUM_ZONAS 5
#define LIMITE_PM25 25.0

// Datos simulados de contaminación actual y predicha
float pm25_actual[NUM_ZONAS] = {30.5, 22.0, 18.5, 27.0, 35.0};
float pm25_predicho[NUM_ZONAS] = {30.0, 22.0, 18.0, 27.0, 35.0};

void generarRecomendaciones() {
    printf("\nGeneración de recomendaciones:\n");
    for (int i = 0; i < NUM_ZONAS; i++) {
        printf("Zona %d:\n", i + 1);
        if (pm25_actual[i] > LIMITE_PM25 || pm25_predicho[i] > LIMITE_PM25) {
            printf("  Recomendación: Reducir tráfico vehicular, cerrar industrias temporalmente, evitar actividades al aire libre.\n");
            printf("  Nota: Se recomienda monitorear continuamente los niveles de contaminación.\n");
        } else {
            printf("  Recomendación: Continuar con actividades normales.\n");
            printf("  Nota: Mantener medidas preventivas para evitar aumentos en los niveles de contaminación.\n");
        }
    }
}
