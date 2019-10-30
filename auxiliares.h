#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"

sqPixel secuenciaDual(const imagen& A);
imagen imagenDual(const sqPixel& sq, int filas, int columnas);
bool pixelValido(const pixel& p, const imagen& A);
imagen interseccion(const imagen &A, const imagen& B);
bool hayInterseccion(const imagen& A, const imagen& B);
imagen dilatarConAdyacenciaK(const imagen& A, int k);
int cantidadPixelesEncendidos(const imagen& A);
void apagaAreaAdj4(imagen &img, int x, int y);
void apagaAreaAdj8(imagen& img, int x, int y);
bool esBorde(const imagen &A, int x, int y);
bool existeUnApagadoAdjacente(const imagen &A, int x, int y, int k, bool borde);
imagen elementoEstructurante(int size);
int estructuranteANumero(const imagen &B);
void prendeElementoEstructurante(int x, int y, imagen &img, const imagen &B);
imagen dilatar(const imagen &A, const imagen &B);
bool estructuranteTocaTodosPrendidos(int x, int y, const imagen& A, const imagen& B);
imagen erosionar(const imagen &A, const imagen &B);
sqPixel obtenerRegionConectadaAux(pixel p, imagen A, int k);

#endif //SOLUCION_AUXILIARES_H
