#ifndef BUILD_ESCENARIO_HPP
#define BUILD_ESCENARIO_HPP

#include <list>
#include "Paso.hpp"

using namespace std;

class Escenario {
    public:
    explicit Escenario(const char* string);

    list<Paso> obtenerResultados();
        void nuevo(Paso *paso);

    string imprimirFinal();

    private:
        list<Paso> resultados;
        const char *nombre;
};


#endif //BUILD_ESCENARIO_HPP
