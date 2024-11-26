#ifndef SISTEMA_GRAVITACIONAL_H
#define SISTEMA_GRAVITACIONAL_H

#include <vector>
#include <string>
#include "Cuerpo.h"

class SistemaGravitacional {
private:
    static constexpr double G = 1.0;  // Constante gravitacional simplificada
    static constexpr double dt = 1.0; // Intervalo de tiempo

    // Métodos privados de cálculo
    double distancia(const Cuerpo& c1, const Cuerpo& c2);
    double angulo(const Cuerpo& c1, const Cuerpo& c2);

public:
    // Vector de cuerpos en el sistema
    std::vector<Cuerpo> cuerpos;

    // Agregar un cuerpo al sistema
    void agregarCuerpo(const Cuerpo& cuerpo);

    // Calcular aceleración total para un cuerpo
    void calcularAceleracion(Cuerpo& cuerpo, int indiceCuerpo);

    // Simular un paso del sistema
    void simular();

    // Guardar resultados en un archivo de texto
    void guardarEnArchivo(const std::string& nombreArchivo, int pasos);
};

#endif // SISTEMA_GRAVITACIONAL_H

