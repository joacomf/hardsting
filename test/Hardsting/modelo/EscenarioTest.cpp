#include "gtest/gtest.h"
#include "Hardsting/modelo/Paso.h"

#include <Hardsting/Hardsting.hpp>

TEST(ReporteTest, alGenerarReporteNoTieneNingunResultado) {
    auto* escenario = new Escenario();
    list<Paso> pasos = escenario->obtenerResultados();

    ASSERT_EQ(pasos.size(), 0);
}

TEST(ReporteTest, alAgregarUnResultadoSeAlmacenaEnElReporte) {
    auto* escenario = new Escenario();
    auto *paso = new Paso();

    escenario->nuevo(paso);
    int cantidadDeResultados = escenario->obtenerResultados().size();

    ASSERT_EQ(cantidadDeResultados, 1);
}

TEST(ReporteTest, alMostrarElReporteFinalSeListaEnUnaLineaCadaResultado) {
    auto* escenario = new Escenario();
    
    auto *paso1 = new Paso("Recibe comando en el pin 1");
    paso1->inicio(0);
    paso1->fin(100);
    paso1->exito(true);

    auto *paso2 = new Paso("Deja de recibir comando en el pin 1");
    paso2->inicio(150);
    paso2->fin(190);
    paso2->exito(true);

    auto *paso3 = new Paso("Recibe comando en el pin 12");
    paso3->inicio(230);
    paso3->fin(400);
    paso3->exito(false);

    escenario->nuevo(paso1);
    escenario->nuevo(paso2);
    escenario->nuevo(paso3);

    int cantidadDeResultados = escenario->obtenerResultados().size();

    string reporteFinal = escenario->imprimirFinal();

    ASSERT_EQ(cantidadDeResultados, 3);
    ASSERT_EQ("[OK] Recibe comando en el pin 1 - ejecuto en 100 useg\n[OK] Deja de recibir comando en el pin 1 - ejecuto en 40 useg\n[FALLO] Recibe comando en el pin 12 - ejecuto en 170 useg\n", reporteFinal);
}