#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <Hardsting/Hardsting.hpp>
#include "../mocks/framework/FrameworkMock.hpp"

using ::testing::AtLeast;
using ::testing::_;

const int BOTON_ROJO = 2;

MockFramework* framework;

TEST(HardstingTest, alEjecutarPresiono_DeberiaEscribirEnAltoYPonerDelayDeCompensacion){

    framework = new MockFramework();

    EXPECT_CALL(*framework, consola(_)).Times(AtLeast(1));
    EXPECT_CALL(*framework, escribir(2,1)).Times(AtLeast(1));
    EXPECT_CALL(*framework, demorar(2)).Times(AtLeast(1));

    Hardsting* hardsting = new Hardsting(framework);
    hardsting->presiono_(BOTON_ROJO);

    delete framework;
}

TEST(HardstingTest, alEjecutarSuelto_DeberiaEscribirEnBajoYPonerDelayDeCompensacion){

    framework = new MockFramework();

    EXPECT_CALL(*framework, consola(_)).Times(AtLeast(1));
    EXPECT_CALL(*framework, escribir(2, 0)).Times(AtLeast(1));
    EXPECT_CALL(*framework, demorar(2)).Times(AtLeast(1));

    Hardsting* hardsting = new Hardsting(framework);
    hardsting->suelto_(BOTON_ROJO);

    delete framework;
}