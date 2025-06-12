#include <stdio.h>
#include "persistencia.h"

#define NUM_ZONAS 5

// Datos simulados
float pm25_actual[NUM_ZONAS] = {30.5, 22.0, 18.5, 27.0, 35.0};
float pm25_predicho[NUM_ZONAS] = {30.0, 22.0, 18.0, 27.0, 35.0};

void guardarDatos() {
    FILE *archivo = fopen("reporte_contaminacion.txt", "w");
    if (archivo == NULL) {
        perror("Error al abrir el archivo para guardar datos");
        return;
    }

    fprintf(archivo, "Reporte de Contaminación\n\n");
    for (int i = 0; i < NUM_ZONAS; i++) {
        if (pm25_actual[i] < 0 || pm25_predicho[i] < 0) {
            fprintf(stderr, "Error: Datos inválidos para la zona %d\n", i + 1);
            continue;
        }
        fprintf(archivo, "Zona %d:\n", i + 1);
        fprintf(archivo, "  PM2.5 actual: %.2f\n", pm25_actual[i]);
        fprintf(archivo, "  PM2.5 predicho: %.2f\n\n", pm25_predicho[i]);
    }

    fclose(archivo);
    printf("Datos guardados exitosamente en reporte_contaminacion.txt\n");
}

void recuperarDatos() {
    FILE *archivo = fopen("reporte_contaminacion.txt", "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo para recuperar datos");
        return;
    }

    char linea[256];
    int lineCount = 0;
    printf("\nRecuperando datos del archivo:\n\n");
    while (fgets(linea, sizeof(linea), archivo)) {
        lineCount++;
        printf("%s", linea);
    }

    if (lineCount == 0) {
        printf("El archivo está vacío.\n");
    }

    fclose(archivo);
}
