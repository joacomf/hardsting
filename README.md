# Test de aceptación con HIL [![Build Status](https://api.travis-ci.org/joacomf/hardsting.svg?branch=master)](https://travis-ci.com/github/joacomf/hardsting)


### Instalación entorno
El IDE utilizado para el desarollo fue [PlatformIO](https://platformio.org/). Por lo tanto al importarlo en esta plataforma, la misma se encargará de descargar las líbrerias necesarias
El proyecto fue desarrollado en un ambiente con sistema operativo Ubuntu. Para el 
mismo, se necesita tener las siguientes librerías:
- cmake
- build-essentials

Para ello:
```sh
$ sudo apt install cmake build-essentials
```

### Pruebas
Para correr las pruebas automatizadas, solo basta con ejecutar desde la raíz del proyecto:
```sh
$ ./test.sh
```
Este script se encargará de instalar las versiones necesarias de:
* [GTEST](https://github.com/google/googletest) - GoogleTest, librería de pruebas para C++ de Google
