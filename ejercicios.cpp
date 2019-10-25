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
    imagen aux1 = imagenDual(obtenerRegionConectadaAux(p, img, k), img.size(), img[0].size());
    imagen aux2 = imagenDual(obtenerRegionConectadaAux(q, img, k), img.size(), img[0].size());
    return hayInterseccion(aux1, aux2);
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
    sqPixel edges;
    imagen img = vector<vector<int> >(A.size(), vector<int>(A[0].size(), 0));
  	for(int i = 0 ; i<img.size() ; i++){
    	for(int j = 0 ; j<img[0].size() ; j++){
      		bool borde = esBorde(A, j, i);
      		if(A[i][j] == 1 && (borde || existeUnApagadoAdjacente(A, j, i, k, borde))){
    			img[i][j] = 1;
      		}
    	}
	}
	edges = secuenciaDual(img);
    return edges;
}

// Ejercicio 5

void cerrarForma(imagen &A, const imagen &B){
	int elem = estructuranteANumero(B);
	A = dilatarConEstructurante(A, elem);
	A = erocionaConEstructurante(A, elem);
}

// Ejercicio 6

int obtenerRegionConectada(imagen &A, const pixel &semilla) {
    imagen fases(A.size(), vector<int>(A[0].size()));
    fases[semilla[0]][semilla[1]] = 1;
    vector<sqPixel> proceso = {secuenciaDual(fases)};
    while(proceso.size() == 1 || proceso[proceso.size()-1] != proceso[proceso.size()-2]){
        imagen aux = dilatar(fases, 8);
        imagen xi = interseccion(aux, A);
        proceso.push_back(secuenciaDual(xi));
        fases = xi;
    }
    proceso.pop_back();
    A = imagenDual(proceso[proceso.size()-1], A.size(), A[0].size());
    return proceso.size();
}
