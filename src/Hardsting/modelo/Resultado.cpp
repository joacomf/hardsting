#include <cstring>
#include "Resultado.h"

Resultado::Resultado() = default;

Resultado::Resultado(const char* nombre) {
    this->nombre = nombre;
}

const char* Resultado::obtenerNombre() {
    return this->nombre;
}

void Resultado::inicio(long microsegundos) {
    this->tiempoInicio = microsegundos;

}

void Resultado::fin(long microsegundos) {
    this->tiempoFin = microsegundos;
}

unsigned long Resultado::tiempo() const {
    return this->tiempoFin - this->tiempoInicio;
}

void Resultado::exito(bool valor) {
    this->esExitoso = valor;
}

string Resultado::mostrar() {
    string mensajeExito = this->esExitoso ? string("[OK] ") : string("[FALLO] ");
    string mensajeTiempo = to_string(this->tiempo());

    return  mensajeExito.append(this->obtenerNombre())
                        .append(" - ejecuto en ")
                        .append(mensajeTiempo).append(" useg");
}
