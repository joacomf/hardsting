#include "gtest/gtest.h"
#include "Hardsting/modelo/Paso.h"

TEST(ResultadoTest, seGeneraUnResultadoConNombrePaso) {
    auto* resultado = new Paso("Envia comando a pin 13");

    string nombreDelPaso = resultado->obtenerNombre();

    ASSERT_EQ(nombreDelPaso, "Envia comando a pin 13");
}

TEST(ResultadoTest, seObtieneElTiempoLuegoDeRegistrarInicioYFin) {
    auto* resultado = new Paso("Envia comando a pin 13");
    resultado->inicio(102450L);
    resultado->fin(103000L);
    unsigned long tiempo = resultado->tiempo();

    ASSERT_EQ(tiempo, 550L);
}

TEST(ResultadoTest, alTenerMostrarUnResultadoOKSeExpresaElExitoNombreYTiempoTranscurrido) {
    auto* resultado = new Paso("Envia comando a pin 13");

    resultado->inicio(103540L);
    resultado->fin(103580L);
    resultado->exito(false);

    string resultadoExpresado = resultado->mostrar();

    ASSERT_EQ(resultadoExpresado, "[FALLO] Envia comando a pin 13 - ejecuto en 40 useg");
}