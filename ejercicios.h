#ifndef _EJERCICIOS_H
#define _EJERCICIOS_H

#include <iostream>
#include <vector>

#include "definiciones.h"

using namespace std;

bool esImagenValida(const imagen &A);
bool sonPixelesConectados(const imagen& img, const pixel& p, const pixel& q, int k);
float devolverPromedioAreas(const imagen &A, int k);
sqPixel calcularContorno(const imagen &A, int k);
void cerrarForma(imagen &A, const imagen &B);
int obtenerRegionConectada(imagen &A, const pixel &semilla);


#endif //ETPH_EJERCICIOS_H
