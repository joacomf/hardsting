add_executable(
    unit_tests
    Hardsting/HardstingTest.cpp
    mocks/framework/FrameworkMock.hpp
    ../src/Hardsting/modelo/Reporte.cpp
    ../src/Hardsting/modelo/Reporte.h
    Hardsting/modelo/ReporteTest.cpp
        ../src/Hardsting/modelo/Resultado.cpp
    ../src/Hardsting/modelo/Resultado.h

        Hardsting/modelo/ResultadoTest.cpp)

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