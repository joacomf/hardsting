#ifndef BUILD_REPORTE_H
#define BUILD_REPORTE_H

#include <list>
#include "Resultado.h"

using namespace std;

class Reporte {
    public:
        list<Resultado> obtenerResultados();
        void nuevo(Resultado *resultado);

private:
        list<Resultado> resultados;
};


#endif //BUILD_REPORTE_H
