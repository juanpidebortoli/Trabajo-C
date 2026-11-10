#include <stdio.h>
#include "validaciones.h"

int leer_entero(const char *mensaje, int min, int max) {
    int valor;
    char buffer[100];
    
    while (1) {
        printf("%s", mensaje);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            // Intentar leer un entero asegurando que no queden restos de buffer
            if (sscanf(buffer, "%d", &valor) == 1) {
                if (valor >= min && valor <= max) {
                    return valor;
                } else {
                    printf("  [ERROR] El valor debe estar entre %d y %d. Intente nuevamente.\n", min, max);
                }
            } else {
                printf("  [ERROR] Entrada invalida. Ingrese un numero entero.\n");
            }
        }
    }
}

double leer_flotante(const char *mensaje, double min, double max) {
    double valor;
    char buffer[100];
    
    while (1) {
        printf("%s", mensaje);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%lf", &valor) == 1) {
                if (valor >= min && valor <= max) {
                    return valor;
                } else {
                    printf("  [ERROR] El valor debe estar entre %.2f y %.2f. Intente nuevamente.\n", min, max);
                }
            } else {
                printf("  [ERROR] Entrada invalida. Ingrese un numero decimal.\n");
            }
        }
    }
}
