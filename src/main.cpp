#include "Hardsting/Hardsting.hpp"
#include "Hardsting/framework/arduino/FrameworkArduino.hpp"

#define LED_ROJO 4
#define BOTON_ROJO 5

Hardsting* hardsting;

void setup() {
    hardsting = new Hardsting(new FrameworkArduino());

    hardsting->pin_de_entrada(LED_ROJO);
    hardsting->pin_de_salida(BOTON_ROJO);
}

prueba presionar_boton_enciende_led(){
  
  hardsting->nuevo_escenario("presionar boton enciende led");

  cuando->presiono_(BOTON_ROJO);
  entonces->deberia_encender_(LED_ROJO, 50);

  hardsting->termina_escenario();
}

prueba presionar_boton_enciende_led_al_presionarlo_nuevamente_lo_apaga(){
  hardsting->nuevo_escenario("presionar boton enciende led al presionarlo nuevamente lo apaga");

  cuando->presiono_(BOTON_ROJO);
  entonces->deberia_encender_(LED_ROJO, 50);
  y_->suelto_(BOTON_ROJO);
  entonces->deberia_apagar_(LED_ROJO, 50);

  hardsting->termina_escenario();
}

void loop() {

  PRUEBA presionar_boton_enciende_led();
  PRUEBA presionar_boton_enciende_led_al_presionarlo_nuevamente_lo_apaga();

  hardsting->imprimir_reporte();
  TERMINA_PRUEBAS
}