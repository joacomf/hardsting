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
  
  hardsting->empieza("presionar boton enciende led");

  cuando->presiono_(BOTON_ROJO);
  entonces->deberia_encender_(LED_ROJO, 5);

  hardsting->termina("presionar boton enciende led");
}

prueba presionar_boton_enciende_led_al_presionarlo_nuevamente_lo_apaga(){
  hardsting->empieza("presionar boton enciende led al presionarlo nuevamente lo apaga");

  cuando->presiono_(BOTON_ROJO);
  entonces->deberia_encender_(LED_ROJO, 5);
  y_->suelto_(BOTON_ROJO);
  entonces->deberia_apagar_(LED_ROJO, 5);

  hardsting->termina("presionar boton enciende led al presionarlo nuevamente lo apaga");
}

void loop() {

  PRUEBA presionar_boton_enciende_led();
  PRUEBA presionar_boton_enciende_led_al_presionarlo_nuevamente_lo_apaga();

  TERMINA_PRUEBAS
}