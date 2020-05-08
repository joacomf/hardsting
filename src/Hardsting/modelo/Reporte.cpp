#include "Reporte.h"

list<Resultado> Reporte::obtenerResultados() {
    return this->resultados;
}

void Reporte::nuevo(Resultado* resultado) {
    this->resultados.push_front(*resultado);
}
