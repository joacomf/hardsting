#ifndef BUILD_RESULTADO_H
#define BUILD_RESULTADO_H

#include <string>

using namespace std;

class Resultado {
    public:
        Resultado();
        explicit Resultado(const char* nombre);
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
};


#endif //BUILD_RESULTADO_H
