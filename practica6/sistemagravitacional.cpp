#include "SistemaGravitacional.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

// Calcular la distancia entre dos cuerpos
double SistemaGravitacional::distancia(const Cuerpo& c1, const Cuerpo& c2) {
    return sqrt(pow(c2.x - c1.x, 2) + pow(c2.y - c1.y, 2));
}

// Calcular el ángulo entre dos cuerpos
double SistemaGravitacional::angulo(const Cuerpo& c1, const Cuerpo& c2) {
    return atan2(c2.y - c1.y, c2.x - c1.x);
}

// Agregar un cuerpo al sistema
void SistemaGravitacional::agregarCuerpo(const Cuerpo& cuerpo) {
    cuerpos.push_back(cuerpo);
}

// Calcular aceleración total para un cuerpo
void SistemaGravitacional::calcularAceleracion(Cuerpo& cuerpo, int indiceCuerpo) {
    double ax = 0, ay = 0;

    // Calcular la influencia de cada otro cuerpo
    for (int j = 0; j < cuerpos.size(); ++j) {
        if (j == indiceCuerpo) continue;

        Cuerpo& otroCuerpo = cuerpos[j];
        double r = distancia(cuerpo, otroCuerpo);
        double theta = angulo(cuerpo, otroCuerpo);

        // Aceleración gravitacional
        double aceleracion = G * otroCuerpo.masa / (r * r);
        ax += aceleracion * cos(theta);
        ay += aceleracion * sin(theta);
    }

    // Actualizar velocidad
    cuerpo.vx += ax * dt;
    cuerpo.vy += ay * dt;

    // Actualizar posición
    cuerpo.x += cuerpo.vx * dt + 0.5 * ax * dt * dt;
    cuerpo.y += cuerpo.vy * dt + 0.5 * ay * dt * dt;
}

// Simular un paso del sistema
void SistemaGravitacional::simular() {
    // Crear una copia para calcular sin modificar los originales
    std::vector<Cuerpo> nuevosCuerpos = cuerpos;

    // Calcular para cada cuerpo
    for (int i = 0; i < cuerpos.size(); ++i) {
        calcularAceleracion(nuevosCuerpos[i], i);
    }

    // Actualizar el sistema
    cuerpos = nuevosCuerpos;
}

// Guardar resultados en un archivo de texto
void SistemaGravitacional::guardarEnArchivo(const std::string& nombreArchivo, int pasos) {
    std::ofstream archivoSalida(nombreArchivo);

    // Encabezados
    for (int i = 0; i < cuerpos.size(); ++i) {
        archivoSalida << "X" << i+1 << "\t" << "Y" << i+1 << "\t";
    }
    archivoSalida << std::endl;

    // Simular y guardar
    for (int paso = 0; paso < pasos; ++paso) {
        for (const auto& cuerpo : cuerpos) {
            archivoSalida << std::fixed << std::setprecision(2)
            << cuerpo.x << "\t" << cuerpo.y << "\t";
        }
        archivoSalida << std::endl;
        simular();
    }

    archivoSalida.close();
}
