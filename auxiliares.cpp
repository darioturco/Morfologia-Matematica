//
//
#include <cstdlib>
#include "definiciones.h"
#include "auxiliares.h"

using namespace std;

sqPixel secuenciaDual(imagen A){
    sqPixel sq = {};
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[0].size(); j++) {
            if(A[i][j] == 1) sq.push_back({i,j});
        }
    }
    return sq;
}

imagen imagenDual(sqPixel sq, int filas, int columnas){
    imagen res(filas, vector<int>(columnas));
    for (int i = 0; i < sq.size(); i++) {
        res[sq[i][0]][sq[i][1]] = 1;
    }
    return res;
}

bool pixelValido(pixel p, imagen A){
    return (0 <= p[0] && p[0] < A.size() && 0 <= p[1] && p[1] < A[0].size());
}

bool sonAdyacentesDeAdyacenciak(pixel p, pixel q, int k){
    bool res = false;
    if(k == 4){
        res = (abs(p[0] - q[0]) +  abs(p[1] - q[1])) <= 1;
    } else if(k == 8){
        res = max(abs(p[0] - q[0]), abs(p[1] - q[1])) <= 1;
    }
    return res;
}

bool pertenece(pixel p, sqPixel sq){
    for (int i = 0; i < sq.size(); i++) {
        if((p[0] == sq[i][0]) && (p[1] == sq[i][1])) return true;
    }
    return false;
}

sqPixel eliminarRepetidos(sqPixel sq){
    sqPixel sinRepetidos = {};
    sqPixel copiaDeSq = sq;
    for (int i = 0; i < sq.size(); i++) {
        pixel aux = copiaDeSq[copiaDeSq.size()-1];
        copiaDeSq.pop_back();
        if(!pertenece(aux, copiaDeSq)) sinRepetidos.push_back(aux);
    }
    return sinRepetidos;
}

imagen elementoEstructuranteDesplazado(int k, pixel p, imagen A) {
    imagen res(A.size(), vector<int>(A[0].size()));
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j <= A[0].size(); j++) {
            if (sonAdyacentesDeAdyacenciak(p, {i,j}, k)) res[i][j] = 1;
        }
    }
    return res;
}

sqPixel interseccion(imagen A, imagen B){   //se presupone que las imagenes tienen igual dimension
    sqPixel res;
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[0].size(); j++) {
            if (A[i][j] == 1 && B[i][j] == 1) res.push_back({i,j});
        }
    }
    return res;
}

bool hayInterseccion(imagen A, imagen B){
    return interseccion(A,B).size() > 0;
}

imagen dilatar(imagen A, int k) {
    sqPixel aux = secuenciaDual(A);
    sqPixel res;
    if (k == 8) {
        for (int i = 0; i < aux.size(); i++) {
            for (int j = -1; j <= 1; j++) {
                for (int l = -1; l <= 1; l++) {
                    if (pixelValido({aux[i][0] + j,aux[i][1] + l}, A)) res.push_back({aux[i][0] + j,aux[i][1] + l});
                }
            }
        }
    } else if (k == 4){
        for (int i = 0; i < aux.size(); i++) {
            if(pixelValido({aux[i][0] - 1, aux[i][1]}, A)) res.push_back({aux[i][0] - 1, aux[i][1]});
            if(pixelValido({aux[i][0], aux[i][1] - 1}, A)) res.push_back({aux[i][0], aux[i][1] - 1});
            if(pixelValido({aux[i][0], aux[i][1]}, A)) res.push_back({aux[i][0], aux[i][1]});
            if(pixelValido({aux[i][0] + 1, aux[i][1]}, A)) res.push_back({aux[i][0] + 1, aux[i][1]});
            if(pixelValido({aux[i][0], aux[i][1] + 1}, A)) res.push_back({aux[i][0], aux[i][1] + 1});
        }
    }
    return imagenDual(res, A.size(), A[0].size());
}

sqPixel obtenerRegionConectada(pixel p, imagen A, int k){
    imagen semilla(A.size(), vector<int>(A[0].size()));
    semilla[p[0]][p[1]] = 1;
    vector<sqPixel> proceso;
    while(proceso[proceso.size()-1] != proceso[proceso.size()-2]){
        sqPixel aux = secuenciaDual(dilatar(semilla, k));
        sqPixel xi = interseccion(aux, A);
        proceso.push_back(xi);
        semilla = imagenDual(xi, A.size(), A[0].size());
    }
    return proceso[proceso.size()-1];
}



