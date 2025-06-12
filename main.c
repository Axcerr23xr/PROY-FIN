#include <stdio.h>
#include "monitor.h"
#include "prediccion.h"
#include "alertas.h"
#include "recomendaciones.h"
#include "persistencia.h"

int main() {
    printf("Bienvenido al sistema de monitoreo de contaminación\n");

    // Recuperar datos históricos
    printf("Recuperando datos históricos...\n");
    recuperarDatos();

    // Monitoreo de contaminación actual
    printf("\nIniciando monitoreo de contaminación actual...\n");
    calcularContaminacionActual();

    // Predicción de niveles futuros
    printf("\nRealizando predicción de niveles futuros...\n");
    predecirContaminacion();

    // Emitir alertas preventivas
    printf("\nGenerando alertas preventivas...\n");
    emitirAlertas();

    // Generar recomendaciones
    printf("\nCreando recomendaciones...\n");
    generarRecomendaciones();

    // Guardar datos en archivo
    printf("\nGuardando datos en archivo...\n");
    guardarDatos();

    printf("\nOperación completada.\n");
    return 0;
}
