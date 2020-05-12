#include "Paso.hpp"

Paso::Paso() = default;

Paso::Paso(string nombre) {
    this->nombre = nombre;
}

string Paso::obtenerNombre() {
    return this->nombre;
}

void Paso::inicio(long microsegundos) {
    this->tiempoInicio = microsegundos;

}

void Paso::fin(long microsegundos) {
    this->tiempoFin = microsegundos;
}

unsigned long Paso::tiempo() const {
    return this->tiempoFin - this->tiempoInicio;
}

void Paso::exito(bool valor) {
    this->esExitoso = valor;
}

string Paso::mostrar() {
    string mensajeExito = this->esExitoso ? string("[OK] ") : string("[FALLO] ");
    string mensajeTiempo = literal(this->tiempo());

    return  mensajeExito.append(this->obtenerNombre())
                        .append(" - ejecuto en ")
                        .append(mensajeTiempo).append(" useg");
}
