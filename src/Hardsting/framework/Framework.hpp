#ifndef FRAMEWORK_H
#define FRAMEWORK_H

#include <string>
using namespace std;

class Framework {
    public:
        virtual void escribir(int pin, int valor) = 0;
        virtual int leer(int pin) = 0;
        virtual long milisegundos() = 0;
        virtual void demorar(int milisegundos) = 0;
        virtual void consola(string mensaje) = 0;

        virtual void configurar_pin_entrada(int pin) = 0;
        virtual void configurar_pin_salida(int pin) = 0;
};

#endif