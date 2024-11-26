#ifndef CUERPO_H
#define CUERPO_H

class Cuerpo {
public:
    double x, y;      // Posición actual
    double vx, vy;    // Velocidad actual
    double masa;      // Masa del cuerpo
    double radio;     // Radio del cuerpo

    // Constructor
    Cuerpo(double x0, double y0, double masa0, double radio0,
           double vx0, double vy0);

    // Métodos adicionales pueden agregarse aquí si es necesario
};

#endif // CUERPO_H
