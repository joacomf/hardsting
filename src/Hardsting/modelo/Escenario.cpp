#include "Escenario.h"

list<Paso> Escenario::obtenerResultados() {
    return this->resultados;
}

void Escenario::nuevo(Paso* resultado) {
    this->resultados.push_back(*resultado);
}

string Escenario::imprimirFinal() {
    list<Paso>::iterator resultado;
    string reporteFinal = string();

    for (resultado = this->resultados.begin(); resultado != this->resultados.end(); ++resultado) {
        reporteFinal.append(resultado->mostrar());
        reporteFinal.append("\n");
    }

    return reporteFinal;
}
