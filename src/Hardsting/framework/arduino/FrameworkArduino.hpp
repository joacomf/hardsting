#ifndef FRAMEWORKARDUINO_H
#define FRAMEWORKARDUINO_H

#include <Arduino.h>
#include "../Framework.hpp"

class FrameworkArduino: public Framework{

    private:
        int velocidadSerial = 115200;

    public:
        FrameworkArduino();
        void escribir(int pin, int valor);
        int leer(int pin);
        long milisegundos();
        long microsegundos();
        void demorar(int milisegundos);
        void consola(string mensaje);

        void configurar_pin_entrada(int pin);
        void configurar_pin_salida(int pin);
};

#endif