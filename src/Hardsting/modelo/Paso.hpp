#ifndef BUILD_PASO_HPP
#define BUILD_PASO_HPP

#include "Hardsting/utils/string-util.hpp"
#include <string>

using namespace std;

class Paso {
    public:
        Paso();
        explicit Paso(string nombre);
        string obtenerNombre();

        void inicio(long microsegundos);
        void fin(long microsegundos);
        unsigned long tiempo() const;

        void exito(bool valor);

        string mostrar();

private:
        string nombre;
        long tiempoInicio;
        long tiempoFin;
        bool esExitoso = false;

        bool fueExitoso();
};


#endif //BUILD_PASO_HPP
