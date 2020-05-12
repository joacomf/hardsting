#include "Hardsting.hpp"

Hardsting::Hardsting(Framework* framework) {
  this->framework = framework;

  this->framework->consola("Comienzan las pruebas\n");
}

void Hardsting::presiono_(int boton){
  string nombre = string("Presiono componente en el pin " + literal(boton));
  Paso* paso = new Paso(nombre);
  paso->inicio(this->framework->microsegundos());

  this->framework->escribir(boton, ALTO);
  this->framework->demorar(DELAY_COMPESACION);

  paso->fin(this->framework->microsegundos());
  paso->exito(true);
  escenario->nuevo(paso);
}

void Hardsting::suelto_(int boton){
  string nombre = string("Suelto componente en el pin " + literal(boton));
  Paso* paso = new Paso(nombre);
  paso->inicio(this->framework->microsegundos());

  this->framework->escribir(boton, BAJO);
  this->framework->demorar(DELAY_COMPESACION);

  paso->fin(this->framework->microsegundos());
  paso->exito(true);
  escenario->nuevo(paso);
}

bool Hardsting::deberia_encender_(int led, int segundos) {
  string nombre = string("Enciende LED en el pin " + literal(led));
  Paso* paso = new Paso(nombre);
  paso->inicio(this->framework->microsegundos());

  long espera = segundos * 1000L;
  long tiempo_inicial = this->framework->milisegundos();

  while(this->framework->milisegundos() - tiempo_inicial < espera){
    if (this->framework->leer(led) == ALTO) {
      paso->fin(this->framework->microsegundos());
      paso->exito(true);
      this->escenario->nuevo(paso);
      return true;
    }
  }

  this->escenario->nuevo(paso);
  return false;
}

bool Hardsting::deberia_apagar_(int led, int segundos) {
  string nombre = string("Apaga LED en el pin " + literal(led));
  Paso* paso = new Paso(nombre);
  paso->inicio(this->framework->microsegundos());

  long espera = segundos * 1000L;
  long tiempo_inicial = this->framework->milisegundos();

  while(this->framework->milisegundos() - tiempo_inicial < espera){
    if (this->framework->leer(led) == BAJO) {
      paso->fin(this->framework->microsegundos());
      paso->exito(true);
      this->escenario->nuevo(paso);
      return true;
    }
  }

  this->escenario->nuevo(paso);
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

string Hardsting::imprimir_reporte() {
    string reporteFinal = string();

    list<Escenario>::iterator escenario;

    for (escenario = this->escenarios.begin(); escenario != this->escenarios.end(); ++escenario) {
        reporteFinal.append(escenario->imprimirFinal());
        reporteFinal.append("\n");
    }

    this->framework->consola(reporteFinal);

    return reporteFinal;
}

void Hardsting::nuevo_escenario(const char *nombreDeEscenario) {
    this->escenario = new Escenario(nombreDeEscenario);
}

void Hardsting::termina_escenario() {
    this->escenarios.push_back(*this->escenario);
}
