add_executable(
    unit_tests
    Hardsting/HardstingTest.cpp
    mocks/framework/FrameworkMock.hpp
        ../src/Hardsting/modelo/Escenario.cpp
        ../src/Hardsting/modelo/Escenario.hpp
        Hardsting/modelo/EscenarioTest.cpp
        ../src/Hardsting/modelo/Paso.cpp
        ../src/Hardsting/modelo/Paso.hpp

        Hardsting/modelo/PasoTest.cpp)

target_link_libraries(
    unit_tests
    gtest
    gmock
    gtest_main
    gmock_main
    aceptacion
)

add_test(
  NAME unit
  COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
)