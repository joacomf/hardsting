add_library(aceptacion "" Hardsting/modelo/Reporte.cpp Hardsting/modelo/Reporte.h)

target_sources(
    aceptacion
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/Hardsting/Hardsting.cpp
          
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/Hardsting/Hardsting.hpp
        ${CMAKE_CURRENT_LIST_DIR}/Hardsting/palabras-claves.hpp
    )

target_include_directories(
    aceptacion
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )
