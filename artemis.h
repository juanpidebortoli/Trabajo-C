#ifndef ARTEMIS_H
#define ARTEMIS_H

#define G 6.674e-11        // Constante de gravitación universal (N*m^2/kg^2)
#define M_TIERRA 5.972e24  // Masa de la Tierra (kg)
#define R_TIERRA 6371000.0 // Radio medio de la Tierra (m)
#define M_ORION 26000.0    // Masa de la nave Orion en TLI (kg)
#define DIST_LUNA 384000000.0 // Distancia media Tierra-Luna (m)
#define ALT_LEO 192000.0   // Altitud de órbita baja LEO (m)

typedef struct {
    double v_tli;         // Velocidad de inyección translunar (m/s)
    double masa_nave;     // Masa de la nave (kg)
    double altitud_inicial; // Altitud inicial LEO (m)
    double energia_cinetica; // Energía cinética inicial (J)
    double trabajo_ext_masa; // Trabajo adicional por unidad de masa al punto de equilibrio (J/kg)
} EstadoTLI;

int leer_entero(const char *mensaje, int min, int max);
double leer_flotante(const char *mensaje, double min, double max);

void simular_inyeccion_tli(EstadoTLI *nave);
void explicar_primera_ley_newton(void);
void calcular_energia_cinetica(EstadoTLI *nave);
void calcular_trabajo_equilibrio(EstadoTLI *nave);
void analizar_balance_combustible(void);

#endif
