#include "Hardsting.hpp"

Hardsting::Hardsting(Framework* framework) {
  this->framework = framework;

  this->framework->consola("Comienzan las pruebas\n");
}

void Hardsting::presiono_(int boton){
  this->framework->escribir(boton, ALTO);
  this->framework->demorar(DELAY_COMPESACION);
}

void Hardsting::suelto_(int boton){
  this->framework->escribir(boton, BAJO);
  this->framework->demorar(DELAY_COMPESACION);
}

bool Hardsting::deberia_encender_(int led, int segundos) {
  long espera = segundos * 1000L;
  long tiempo_inicial = this->framework->milisegundos();

  while(this->framework->milisegundos() - tiempo_inicial < espera){
    if (this->framework->leer(led) == ALTO) {
      this->framework->consola("[OK] Encendió LED");
      return true;
    }
  }

  this->framework->consola("[FALLÓ] Encendió LED");
  return false;
}

bool Hardsting::deberia_apagar_(int led, int segundos) {
  long espera = segundos * 1000L;
  long tiempo_inicial = this->framework->milisegundos();

  while(this->framework->milisegundos() - tiempo_inicial < espera){
    if (this->framework->leer(led) == BAJO) {
      this->framework->consola("[OK] Apagó LED");
      return true;
    }
  }

  this->framework->consola("[FALLÓ] Apagó LED");
  return false;
}

void Hardsting::pin_de_entrada(int pin) {
  this->framework->configurar_pin_entrada(pin);
}

void Hardsting::pin_de_salida(int pin) {
  this->framework->configurar_pin_salida(pin);
}

void Hardsting::empieza(string nombre) {
  this->framework->consola("Empieza TEST: " + nombre);
}

void Hardsting::termina(string nombre) {
  this->framework->consola("Termina " + nombre + "\n");
}
