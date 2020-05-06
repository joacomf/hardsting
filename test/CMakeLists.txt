add_executable(
    unit_tests
    Hardsting/Hardsting_test.cpp
    mocks/framework/FrameworkMock.hpp
)

target_link_libraries(
    unit_tests
    gtest_main
    gmock_main
    aceptacion
)

add_test(
  NAME unit
  COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
)