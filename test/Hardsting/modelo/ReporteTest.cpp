#include "gtest/gtest.h"
#include "Hardsting/modelo/Resultado.h"

#include <Hardsting/Hardsting.hpp>

const int BOTON_ROJO = 2;

TEST(ReporteTest, alGenerarReporteNoTieneNingunResultado) {
    auto* reporte = new Reporte();
    list<Resultado> resultados = reporte->obtenerResultados();

    ASSERT_EQ(resultados.size(), 0);
}

TEST(ReporteTest, alAgregarUnResultadoSeAlmacenaEnElReporte) {
    auto* reporte = new Reporte();
    Resultado *resultado = new Resultado();

    reporte->nuevo(resultado);
    int cantidadDeResultados = reporte->obtenerResultados().size();

    ASSERT_EQ(cantidadDeResultados, 1);
}