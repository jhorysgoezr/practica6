#include "SistemaGravitacional.h"
#include "Cuerpo.h"

int main() {
    // Sistema 1
    SistemaGravitacional sistema1;
    sistema1.agregarCuerpo(Cuerpo(0, -7000, 70, 120, 2, 0));
    sistema1.agregarCuerpo(Cuerpo(0, 0, 70000, 300, 0, 0));
    sistema1.agregarCuerpo(Cuerpo(4000, 5000, 25, 100, -1.6, 1.2));
    sistema1.guardarEnArchivo("sistema1.txt", 10000);

    // Sistema 2
    SistemaGravitacional sistema2;
    sistema2.agregarCuerpo(Cuerpo(0, 0, 50000, 200, 0, 0));
    sistema2.agregarCuerpo(Cuerpo(-5000, 0, 70, 70, 0, -2));
    sistema2.agregarCuerpo(Cuerpo(5000, 0, 70, 70, 0, 2));
    sistema2.agregarCuerpo(Cuerpo(0, -5000, 70, 70, 2, 0));
    sistema2.agregarCuerpo(Cuerpo(0, 5000, 70, 70, -2, 0));
    sistema2.guardarEnArchivo("sistema2.txt", 10000);

    return 0;
}
