#include <stdio.h>
#include "artemis.h"
#include "validaciones.h"

int main() {
    // Inicializar la estructura con los valores estándar del Problema 3 Artemis (TLI)
    EstadoTLI nave;
    nave.v_tli = 10900.0;         // Velocidad de inyección translunar predeterminada (10.9 km/s)
    nave.masa_nave = M_ORION;     // Masa predeterminada de la nave Orion (26.000 kg)
    nave.altitud_inicial = ALT_LEO; // Altitud inicial en órbita baja LEO (192.000 m)

    int opcion;

    do {
        printf("\n==================================================\n");
        printf("   SIMULADOR ARTEMIS - PROBLEMA 3: TLI E INERCIA  \n");
        printf("==================================================\n");
        printf(" 1. Ejecutar simulacion completa TLI\n");
        printf(" 2. Analizar inciso a) 1.a Ley de Newton y Estado de Inercia\n");
        printf(" 3. Calcular inciso b) Energia Cinetica Inicial (K1)\n");
        printf(" 4. Calcular inciso c) Trabajo y Punto de Equilibrio\n");
        printf(" 5. Analizar inciso d) Balance de Combustible Tierra-Luna\n");
        printf(" 6. Modificar parametros de la nave (Velocidad / Masa)\n");
        printf(" 7. Salir del simulador\n");
 
        // Uso de la función de validación de enteros para evitar fallos por entradas erróneas
        opcion = leer_entero("Seleccione una opcion (1-7): ", 1, 7);

        switch(opcion) {
            case 1:
                simular_inyeccion_tli(&nave);
                break;
            case 2:
                explicar_primera_ley_newton();
                break;
            case 3:
                calcular_energia_cinetica(&nave);
                break;
            case 4:
                calcular_trabajo_equilibrio(&nave);
                break;
            case 5:
                analizar_balance_combustible();
                break;
            case 6:
                printf("\n--- Configuracion de Parametros de la Nave ---\n");
                nave.v_tli = leer_flotante("Ingrese la velocidad TLI (m/s) [Recomendado: 10900.0]: ", 5000.0, 25000.0);
                nave.masa_nave = leer_flotante("Ingrese la masa de la nave (kg) [Recomendado: 26000.0]: ", 1000.0, 100000.0);
                printf("  [EXITO] Parametros actualizados exitosamente en memoria.\n");
                break;
            case 7:
                printf("\nSaliendo del Simulador Artemis. ¡Misión finalizada con éxito!\n");
                break;
        }

        if (opcion != 7) {
            printf("\nPresione Enter para volver al menu principal...");
            getchar(); // Pausa limpia de consola
        }

    } while (opcion != 7);

    return 0;
}
    
