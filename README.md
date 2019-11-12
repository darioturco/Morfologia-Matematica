# Morfologia-Matematica

Correcciones del TPI:

Grupo 23
========

Cobertura
---------
Se muestra una cobertura del 100% total. Tanto ejercicios.cpp como auxiliares.cpp tienen cobertura del 100%.

Correccion
----------

===========
REENTREGA
===========

Tests
-----
Resultado de los tests de correccion.

[----------] Global test environment tear-down
[==========] 190 tests from 12 test cases ran. (722 ms total)
[ PASSED ] 181 tests.
[ FAILED ] 9 tests, listed below:
[ FAILED ] cerrarFormaTest.soloUnPixelPrendidoConElemSinCentro
[ FAILED ] cerrarFormaTest.cierreConElementoEstructuranteAsimetrico
[ FAILED ] cerrarFormaTest.cierreConElementoSinCentroActivadoYConDosPixelesActivados
[ FAILED ] sonPixelesConectadosTest.NoConectadosUnPixelNoActivadoAdy8
[ FAILED ] sonPixelesConectadosTest.PixelesRomboAdy8ActivoYNoActivoNoEstanConectadosAdy8
[ FAILED ] sonPixelesConectadosTest.NoConectadosSiSegundoPixelEstaInactivo
[ FAILED ] sonPixelesConectadosTest.NoConectadosSiPrimerPixelEstaInactivo
[ FAILED ] sonPixelesConectadosTest.PixelNoActivadoEstaConectadoConsigoMismoAdy4
[ FAILED ] sonPixelesConectadosTest.PixelNoActivadoEstaConectadoConsigoMismoAdy8

Las entradas de los tests que fallan son:

Ejercicio 2
-----------

a) NoConectadosSiPrimerPixelEstaInactivo) {

imagen img = {{0}, {1}};
pixel p = {0, 0};
pixel q = {1, 0};

b) NoConectadosSiSegundoPixelEstaInactivo) {
imagen img = {{1}, {0}};
pixel p = {0, 0};
pixel q = {1, 0};


c) PixelesRomboAdy8ActivoYNoActivoNoEstanConectadosAdy8) {
imagen img = {
{0, 0, 1, 0, 0},
{0, 1, 0, 1, 0},
{1, 0, 0, 0, 1},
{0, 1, 0, 1, 0},
{0, 0, 1, 0, 0},
};
pixel p = {0, 1};
pixel q = {4, 2};


d) PixelNoActivadoEstaConectadoConsigoMismoAdy8) {
imagen img = {
{0}
};
pixel p = {0, 0};
pixel q = {0, 0};

e) PixelNoActivadoEstaConectadoConsigoMismoAdy4) {
imagen img = {
{0}
};
pixel p = {0, 0};
pixel q = {0, 0};


f) NoConectadosUnPixelNoActivadoAdy8) {
imagen img = {
{1, 0, 0, 0, 0, 0, 1, 0},
{1, 0, 0, 1, 0, 0, 1, 1},
{1, 1, 0, 1, 0, 0, 0, 1},
{0, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 0, 0, 1, 0, 0},
};
pixel p = {0, 1};
pixel q = {0, 0};


Ejercicio 5
-----------

a) soloUnPixelPrendidoConElemSinCentro) {
imagen A = {
{0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0},
{0, 0, 1, 0, 0, 0},
{0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0},
};
imagen B = {
{0, 1, 0, 1, 0},
{1, 0, 1, 0, 1},
{0, 1, 0, 1, 0},
{1, 0, 1, 0, 1},
{0, 1, 0, 1, 0},
};

b) cierreConElementoSinCentroActivadoYConDosPixelesActivados) {
imagen A = {
{0, 0, 0, 0, 0},
{0, 0, 0, 0, 0},
{0, 0, 0, 0, 0},
{0, 0, 1, 0, 0},
{0, 0, 0, 0, 0},
{0, 0, 1, 0, 0},
{0, 0, 0, 0, 0},
{0, 0, 0, 0, 0},
{0, 0, 0, 0, 0},
};
imagen B = {
{0, 1, 0},
{0, 0, 0},
{0, 1, 0},
};

c) cierreConElementoEstructuranteAsimetrico) {
imagen A = {
{0, 0, 0},
{0, 0, 0},
{0, 1, 0},
{0, 0, 0},
{0, 0, 0},
};
imagen B = {
{0, 1, 0},
{0, 1, 0},
{0, 0, 0},
};
