#ifndef BUILD_PASO_HPP
#define BUILD_PASO_HPP

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


#endif //BUILD_PASO_HPP
