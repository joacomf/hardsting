#include "Escenario.h"

list<Paso> Escenario::obtenerResultados() {
    return this->resultados;
}

void Escenario::nuevo(Paso* paso) {
    this->resultados.push_back(*paso);
}

string Escenario::imprimirFinal() {
    list<Paso>::iterator paso;
    string reporteDeEscenario = string();

    for (paso = this->resultados.begin(); paso != this->resultados.end(); ++paso) {
        reporteDeEscenario.append(paso->mostrar());
        reporteDeEscenario.append("\n");
    }

    return reporteDeEscenario;
}
