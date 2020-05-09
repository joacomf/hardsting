#ifndef BUILD_ESCENARIO_H
#define BUILD_ESCENARIO_H

#include <list>
#include "Paso.h"

using namespace std;

class Escenario {
    public:
        list<Paso> obtenerResultados();
        void nuevo(Paso *resultado);

    string imprimirFinal();

private:
        list<Paso> resultados;
};


#endif //BUILD_ESCENARIO_H
