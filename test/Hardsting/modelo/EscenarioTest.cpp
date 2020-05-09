#include "gtest/gtest.h"
#include "Hardsting/modelo/Resultado.h"

#include <Hardsting/Hardsting.hpp>

TEST(ReporteTest, alGenerarReporteNoTieneNingunResultado) {
    auto* reporte = new Escenario();
    list<Resultado> resultados = reporte->obtenerResultados();

    ASSERT_EQ(resultados.size(), 0);
}

TEST(ReporteTest, alAgregarUnResultadoSeAlmacenaEnElReporte) {
    auto* reporte = new Escenario();
    auto *resultado = new Resultado();

    reporte->nuevo(resultado);
    int cantidadDeResultados = reporte->obtenerResultados().size();

    ASSERT_EQ(cantidadDeResultados, 1);
}

TEST(ReporteTest, alMostrarElReporteFinalSeListaEnUnaLineaCadaResultado) {
    auto* reporte = new Escenario();
    
    auto *resultadoPaso1 = new Resultado("Recibe comando en el pin 1");
    resultadoPaso1->inicio(0);
    resultadoPaso1->fin(100);
    resultadoPaso1->exito(true);

    auto *resultadoPaso2 = new Resultado("Deja de recibir comando en el pin 1");
    resultadoPaso2->inicio(150);
    resultadoPaso2->fin(190);
    resultadoPaso2->exito(true);

    auto *resultadoPaso3 = new Resultado("Recibe comando en el pin 12");
    resultadoPaso3->inicio(230);
    resultadoPaso3->fin(400);
    resultadoPaso3->exito(false);

    reporte->nuevo(resultadoPaso1);
    reporte->nuevo(resultadoPaso2);
    reporte->nuevo(resultadoPaso3);

    int cantidadDeResultados = reporte->obtenerResultados().size();

    string reporteFinal = reporte->imprimirFinal();

    ASSERT_EQ(cantidadDeResultados, 3);
    ASSERT_EQ("[OK] Recibe comando en el pin 1 - ejecuto en 100 useg\n[OK] Deja de recibir comando en el pin 1 - ejecuto en 40 useg\n[FALLO] Recibe comando en el pin 12 - ejecuto en 170 useg\n", reporteFinal);
}