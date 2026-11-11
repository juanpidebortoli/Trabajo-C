#include <stdio.h>
#include "artemis.h"
#include "validaciones.h"

int main() {
    // Inicializar la estructura con los valores estándar del Problema 3 Artemis (TLI)
    EstadoTLI nave;
    nave.v_tli = 10900.0;         // Velocidad de inyección translunar predeterminada (10.9 km/s)[cite: 4]
    nave.masa_nave = M_ORION;     // Masa predeterminada de la nave Orion (26.000 kg)[cite: 4]
    nave.altitud_inicial = ALT_LEO; // Altitud inicial en órbita baja LEO (192.000 m)[cite: 3, 4]

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
    
