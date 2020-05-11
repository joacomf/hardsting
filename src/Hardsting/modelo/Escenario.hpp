#ifndef BUILD_ESCENARIO_HPP
#define BUILD_ESCENARIO_HPP

#include <list>
#include "Paso.hpp"

using namespace std;

class Escenario {
    public:
        list<Paso> obtenerResultados();
        void nuevo(Paso *paso);

    string imprimirFinal();

private:
        list<Paso> resultados;
};


#endif //BUILD_ESCENARIO_HPP
