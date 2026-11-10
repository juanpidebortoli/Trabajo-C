#include <stdio.h>
#include <math.h>
#include "artemis.h"

// Función principal que coordina la simulación del escenario TLI
void simular_inyeccion_tli(EstadoTLI *nave) {
    printf("\n==================================================\n");
    printf("   INICIANDO SIMULACION TLI - PROBLEMA 3 ARTEMIS   \n");
    printf("==================================================\n");
    printf("  - Velocidad de Inyeccion (v_TLI): %.2f m/s\n", nave->v_tli);
    printf("  - Masa de la nave Orion: %.2f kg\n", nave->masa_nave);
    printf("  - Altitud inicial LEO: %.2f m\n", nave->altitud_inicial);
   
    calcular_energia_cinetica(nave);
    calcular_trabajo_equilibrio(nave);
}

// a) Explicación basada en la 1.ª Ley de Newton (Inercia)
void explicar_primera_ley_newton(void) {
    printf("\n--- a) Analisis: 1.a Ley de Newton (Inercia) ---\n");
    printf(" Una vez que la etapa superior ICPS ejecuta la TLI (10.900 m/s) y se desacopla,\n");
    printf(" los propulsores se apagan por completo. De acuerdo con la 1.a Ley de Newton (Inercia),\n");
    printf(" la nave Orion mantiene su estado de movimiento rectilineo uniforme a menos que una\n");
    printf(" fuerza externa neta actue sobre ella.\n");
    printf(" A medida que la nave se aleja de la Tierra, la fuerza de atraccion gravitatoria terrestre\n");
    printf(" actua en direccion contraria a su movimiento, desacelerando progresivamente a la nave\n");
    printf(" de manera constante durante toda la trayectoria de retorno libre.\n");
}

// b) Cálculo de la energía cinética inicial K1
void calcular_energia_cinetica(EstadoTLI *nave) {
    // Fórmula: K = 1/2 * m * v^2
    nave->energia_cinetica = 0.5 * nave->masa_nave * pow(nave->v_tli, 2);
    printf("\n--- b) Calculo de Energia Cinetica Inicial (K1) ---\n");
    printf(" Formula aplicada: K = 0.5 * m * (v_TLI)^2\n");
    printf(" Resultado obtenido: %.2f Joules (J)\n", nave->energia_cinetica);
}
