#ifndef HARDSTING_H
#define HARDSTING_H

#include <string>
using namespace std;

#include "framework/Framework.hpp"
#include "palabras-claves.hpp"

#define DELAY_COMPESACION 2
#define BAJO 0x0
#define ALTO 0x1

class Hardsting {

    private:
        Framework* framework;

    public:
        Hardsting(Framework* framework);
        void presiono_(int boton);
        void suelto_(int boton);
        bool deberia_encender_(int led, int segundos);
        bool deberia_apagar_(int led, int segundos);

        void pin_de_entrada(int pin);
        void pin_de_salida(int pin);

        void empieza(string nombre);
        void termina(string nombre);

        ~Hardsting();

};

#endif