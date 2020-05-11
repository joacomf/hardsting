#include <Hardsting/framework/Framework.hpp>
#include "gmock/gmock.h"

class MockFramework : public Framework {
    public:
        MOCK_METHOD2(escribir, void(int, int));
        MOCK_METHOD1(leer, int(int));
        MOCK_METHOD0(milisegundos, long());
        MOCK_METHOD0(microsegundos, long());
        MOCK_METHOD1(demorar, void(int));
        MOCK_METHOD1(consola, void(string));

        MOCK_METHOD1(configurar_pin_entrada, void(int));
        MOCK_METHOD1(configurar_pin_salida, void(int));
};