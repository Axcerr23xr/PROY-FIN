#include <stdio.h>
#include "alertas.h"

#define NUM_ZONAS 5
#define LIMITE_PM25 25.0

// Datos simulados de predicción (debería enlazarse con prediccion.c)
float pm25_predicho[NUM_ZONAS] = {30.0, 22.0, 18.0, 27.0, 35.0};

void emitirAlertas() {
    printf("\nEmisión de alertas preventivas:\n");
    for (int i = 0; i < NUM_ZONAS; i++) {
        if (pm25_predicho[i] > LIMITE_PM25) {
            printf("Alerta: Zona %d excederá el límite de PM2.5 (%.2f > %.2f). Se recomienda tomar medidas inmediatas.\n", i + 1, pm25_predicho[i], LIMITE_PM25);
        } else {
            printf("Zona %d: Niveles dentro de límites aceptables.\n", i + 1);
        }
    }
}
