#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../mocks/framework/FrameworkMock.hpp"

#include <Hardsting/Hardsting.hpp>

using ::testing::AtLeast;
using ::testing::_;
using ::testing::Return;

const int BOTON_ROJO = 2;
const int LED_VERDE = 4;

MockFramework* framework;

TEST(HardstingTest, alEjecutarPresiono_DeberiaEscribirEnAltoYPonerDelayDeCompensacion){

    framework = new MockFramework();

    EXPECT_CALL(*framework, consola(_)).Times(AtLeast(1));
    EXPECT_CALL(*framework, escribir(2,1)).Times(AtLeast(1));
    EXPECT_CALL(*framework, demorar(2)).Times(AtLeast(1));

    EXPECT_CALL(*framework, microsegundos())
            .WillOnce(Return(0L))
            .WillOnce(Return(50L));

    auto* hardsting = new Hardsting(framework);
    hardsting->nuevo_escenario("Se puede soltar el boton rojo");
    hardsting->presiono_(BOTON_ROJO);

    delete framework;
}

TEST(HardstingTest, alEjecutarSuelto_DeberiaEscribirEnBajoYPonerDelayDeCompensacion){

    framework = new MockFramework();

    EXPECT_CALL(*framework, consola(_)).Times(AtLeast(1));
    EXPECT_CALL(*framework, escribir(2, 0)).Times(AtLeast(1));
    EXPECT_CALL(*framework, demorar(2)).Times(AtLeast(1));
    EXPECT_CALL(*framework, microsegundos())
            .WillOnce(Return(0L))
            .WillOnce(Return(50L));

    Hardsting* hardsting = new Hardsting(framework);
    hardsting->nuevo_escenario("Se puede soltar el boton rojo");
    hardsting->suelto_(BOTON_ROJO);

    delete framework;
}

TEST(HardstingTest, alTerminarLaEjecucionImprimeElReporteDeTodosLosEscenarios){

    framework = new MockFramework();

    EXPECT_CALL(*framework, consola(_)).Times(AtLeast(1));
    EXPECT_CALL(*framework, escribir(2, 1)).Times(AtLeast(1));
    EXPECT_CALL(*framework, escribir(2, 0)).Times(AtLeast(1));
    EXPECT_CALL(*framework, milisegundos())
                                .WillOnce(Return(0L))
                                .WillOnce(Return(100L))
                                .WillOnce(Return(200L))
                                .WillOnce(Return(300L))
                                .WillRepeatedly(Return(500L));
    EXPECT_CALL(*framework, microsegundos())
                                .WillOnce(Return(0L))
                                .WillOnce(Return(50L))
                                .WillOnce(Return(100L))
                                .WillOnce(Return(200L))
                                .WillOnce(Return(250L))
                                .WillOnce(Return(300L))
                                .WillOnce(Return(350L))
                                .WillOnce(Return(460L))
                                .WillRepeatedly(Return(500L));
    EXPECT_CALL(*framework, demorar(2)).Times(AtLeast(1));
    EXPECT_CALL(*framework, leer(4))
                                .WillOnce(Return(1))
                                .WillOnce(Return(0));


    auto* hardsting = new Hardsting(framework);

    hardsting->nuevo_escenario("Enciende led verde al presionar el boton rojo y apaga el mismo al soltarlo");
    hardsting->presiono_(BOTON_ROJO);
    hardsting->deberia_encender_(LED_VERDE, 1000);
    hardsting->suelto_(BOTON_ROJO);
    hardsting->deberia_apagar_(LED_VERDE, 1000);
    hardsting->termina_escenario();

    string reporte = hardsting->imprimir_reporte();

    ASSERT_EQ(reporte, "Escenario: Enciende led verde al presionar el boton rojo y apaga el mismo al soltarlo\n\n[OK] Presiono componente en el pin 2 - ejecuto en 50 useg\n[OK] Enciende LED en el pin 4 - ejecuto en 100 useg\n[OK] Suelto componente en el pin 2 - ejecuto en 50 useg\n[OK] Apaga LED en el pin 4 - ejecuto en 110 useg\n\n");

    delete framework;
}
