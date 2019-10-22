#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

// Ejercicio 1

bool esImagenValida(const imagen& img) {
	bool resp = true;
	resp = (img.size() > 0) && (img[0].size() > 0);
    for (int i = 0; i < img.size(); i++) {
        resp = resp && img[i].size() == img[0].size();
        for (int j = 0; j < img[i].size(); j++) {
            resp = resp && (img[i][j] == 0 || img[i][j] == 1);
        }

    }
    return resp;
}

// Ejercicio 2

bool sonPixelesConectados(const imagen& img, const pixel& p, const pixel& q, int k) {
	bool resp = false;

    return resp;
}

// Ejercicio 3

float devolverPromedioAreas(const imagen &A, int k){
	float prom = 0.0;
	float pixelesEncendidos = cantidadPixelesEncendidos(A);
	float cantidadRegiones = 0.0; 
	if(pixelesEncendidos > 0){
		imagen img = copiaImagen(A);
		for (int i = 0; i < img.size(); i++) {
        	for (int j = 0; j < img[i].size(); j++) {
				if(img[i][j] == 1){
					if(k == 4){
						apagaAreaAdj4(img, j, i);
					}else{
						apagaAreaAdj8(img, j, i);
					}
					cantidadRegiones++;
				}
			}
		}
		prom = pixelesEncendidos / cantidadRegiones;
	}
    return prom;
}

// Ejercicio 4

sqPixel calcularContorno(const imagen &A, int k){
    sqPixel edges = {{}};
	// TODO --> cuerpo de funcion
    return edges;
}

// Ejercicio 5

void cerrarForma(imagen &A, const imagen &B){
	// TODO --> cuerpo de funcion
	return;
}

// Ejercicio 6

int obtenerRegionConectada(imagen &A, const pixel &semilla) {
	int ite = 0;
	// TODO --> cuerpo de funcion
	return ite;
}
