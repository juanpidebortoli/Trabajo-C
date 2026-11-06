#include <stdio.h>
#include <math.h>
#include "simulador.h"
#include "validaciones.h"

/* carga los 5 datos del problema en el arreglo */
void ingresarDatos(float datos[])
{
    char *mensajes[CANT_DATOS] = {
        "Aceleracion de la primera fase a1 (m/s2): ",
        "Tiempo del desacople de los SRB t1 (s): ",
        "Aceleracion de la segunda fase a2 (m/s2): ",
        "Altura donde se apagan los motores h (m): ",
        "Valor de la gravedad g (m/s2): "
    };
    float minimos[CANT_DATOS] = {0.1, 0.1, 0.1, 1, 1};
    float maximos[CANT_DATOS] = {100, 1000, 100, 1000000, 30};
    int i;

    printf("\n--- INGRESO DE DATOS ---\n");
    printf("(use punto para los decimales, por ejemplo 9.8)\n\n");

    for (i = 0; i < CANT_DATOS; i++) {
        datos[i] = leerFlotante(mensajes[i], minimos[i], maximos[i]);
    }
}
