#include "Escenario.h"

list<Resultado> Escenario::obtenerResultados() {
    return this->resultados;
}

void Escenario::nuevo(Resultado* resultado) {
    this->resultados.push_back(*resultado);
}

string Escenario::imprimirFinal() {
    list<Resultado>::iterator resultado;
    string reporteFinal = string();

    for (resultado = this->resultados.begin(); resultado != this->resultados.end(); ++resultado) {
        reporteFinal.append(resultado->mostrar());
        reporteFinal.append("\n");
    }

    return reporteFinal;
}
