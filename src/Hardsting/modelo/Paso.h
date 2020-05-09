#ifndef BUILD_PASO_H
#define BUILD_PASO_H

#include <string>

using namespace std;

class Paso {
    public:
        Paso();
        explicit Paso(const char* nombre);
        const char* obtenerNombre();

        void inicio(long microsegundos);
        void fin(long microsegundos);
        unsigned long tiempo() const;

        void exito(bool valor);

        string mostrar();

private:
        const char* nombre;
        long tiempoInicio;
        long tiempoFin;
        bool esExitoso;

    bool fueExitoso();
};


#endif //BUILD_PASO_H
