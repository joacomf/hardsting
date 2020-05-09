#ifndef BUILD_ESCENARIO_H
#define BUILD_ESCENARIO_H

#include <list>
#include "Resultado.h"

using namespace std;

class Escenario {
    public:
        list<Resultado> obtenerResultados();
        void nuevo(Resultado *resultado);

    string imprimirFinal();

private:
        list<Resultado> resultados;
};


#endif //BUILD_ESCENARIO_H
