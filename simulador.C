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



// c) Cálculo del trabajo adicional por unidad de masa hasta el punto de equilibrio
void calcular_trabajo_equilibrio(EstadoTLI *nave) {
    double r_leo = R_TIERRA + nave->altitud_inicial;
   
    printf("\n--- c) Trabajo Adicional para el Punto de Equilibrio ---\n");
    printf(" Aplicando el principio de conservacion de la energia mecanica (Em = K + U),\n");
    printf(" se evalua el potencial gravitatorio desde la orbita baja (r = %.2f m)\n", r_leo);
    printf(" hasta el punto de equilibrio gravitatorio Tierra-Luna.\n");
   
    // Potencial gravitatorio específico en LEO (U / m = - G * M_Tierra / r)
    double u_leo = - (G * M_TIERRA) / r_leo;
    // Ubicación estimada del punto de influencia neutra / equilibrio
    double r_eq = DIST_LUNA * 0.9;
    double u_eq = - (G * M_TIERRA) / r_eq;
   
    nave->trabajo_ext_masa = u_eq - u_leo;
    printf(" Trabajo adicional minimo requerido por unidad de masa (W_ext/m): %.2f J/kg\n", nave->trabajo_ext_masa);
}

// d) Justificación energética del balance de combustible Tierra-Luna vs Luna-Tierra
void analizar_balance_combustible(void) {
    printf("\n--- d) Analisis Energetico: Balance de Combustible Tierra-Luna vs Luna-Tierra ---\n");
    printf(" Viajar de la Tierra a la Luna requiere una masa de combustible significativamente mayor\n");
    printf(" debido a que la nave debe escapar del profundo pozo gravitatorio generado por la gran masa\n");
    printf(" de la Tierra (M_T = 5.972 x 10^24 kg)[cite: 3] desde una orbita baja (LEO), venciendo una enorme\n");
    printf(" energia potencial gravitatoria inicial.\n");
    printf(" En contraste, el viaje de regreso (Luna-Tierra) parte de un cuerpo con un campo gravitatorio\n");
    printf(" mucho mas debil, por lo que requiere impulsos de propulsion sustancialmente menores.\n");
}
//simulacion terminada 
