#include <cstdlib>
#include "definiciones.h"
#include "auxiliares.h"

using namespace std;

sqPixel secuenciaDual(const imagen& A){ //Pasa una imagen a secuencia de pixeles
    sqPixel sq = {};
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[0].size(); j++) {
            if(A[i][j] == 1) sq.push_back({i,j});
        }
    }
    return sq;
}

imagen imagenDual(const sqPixel& sq, int filas, int columnas){ //Pasa una secuencia de pixeles a imagen
    imagen res(filas, vector<int>(columnas));
    for (int i = 0; i < sq.size(); i++) {
        res[sq[i][0]][sq[i][1]] = 1;
    }
    return res;
}

bool pixelValido(const pixel& p, const imagen& A){
    return (0 <= p[0] && p[0] < A.size() && 0 <= p[1] && p[1] < A[0].size());
}

imagen interseccion(const imagen &A, const imagen& B){ //se presupone que las imagenes tienen igual dimension
    imagen res(A.size(), vector<int>(A[0].size()));
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[0].size(); j++) {
            if (A[i][j] == 1 && B[i][j] == 1) res[i][j] = 1;
        }
    }
    return res;
}

bool hayInterseccion(const imagen& A, const imagen& B){
    sqPixel res = secuenciaDual(interseccion(A, B));
    return (res.size() > 0);
}

imagen dilatarConAdyacenciaK(const imagen& A, int k){
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

int cantidadPixelesEncendidos(const imagen& A){ //Cuenta la cantidad de pixeles encedidos totales de una imagen valida
    int cont = 0;
    for(int i = 0 ; i<A.size() ; i++){
        for(int j = 0 ; j<A[0].size() ; j++){
            if(A[i][j] == 1){
                cont++;
            }
        }
    }
    return cont;
}

void apagaAreaAdj4(imagen &img, int x, int y){ // Apaga los pixeles que comparten area con el pixel de cordenas x, y con adjacencia 4
    for(int i = -1 ; i<2 ; i++){
        if(x+i >= 0 && x+i < img[0].size() && img[y][x+i] == 1){
            img[y][x+i] = 0;
            apagaAreaAdj4(img, x+i, y);
        }
        if(y+i >= 0 && y+i < img.size() && img[y+i][x] == 1){
            img[y+i][x] = 0;
            apagaAreaAdj4(img, x, y+i);
        }
    }
}

void apagaAreaAdj8(imagen& img, int x, int y){ // Apaga los pixeles que comparten area con el pixel de cordenas x, y con adjacencia 8
    for(int i = -1 ; i<2 ; i++){
        for(int j = -1 ; j<2 ; j++){
            if(x+i >= 0 && x+i < img[0].size() && y+j >= 0 && y+j < img.size() && img[y+j][x+i] == 1){
                img[y+j][x+i] = 0;
                apagaAreaAdj8(img, x+i, y+j);
            }
        }
    }
}

bool esBorde(const imagen &A, int x, int y){
    return (x == 0 || y == 0 || x >= A[0].size()-1 || y >= A.size()-1);
}

bool existeUnApagadoAdjacente(const imagen &A, int x, int y, int k, bool borde){
    bool res = false;
    if(k == 4){
        for(int i = -1 ; i<2 ; i++){
            res = res || A[y+i][x] == 0;
        }
        for(int i = -1 ; i<2 ; i++){
            res = res || A[y][x+i] == 0;
        }
    }else{
        for(int i = -1 ; i<2 ; i++){
            for(int j = -1 ; j<2 ; j++){
                res = res || A[y+j][x+i] == 0;
            }
        }
    }
    return res;
}

int estructuranteANumero(const imagen &B){
    return (B.size()-1)/2;
}

/*void prendeElementoEstructurante(int x, int y, imagen& img, const imagen& B){
    int elem = estructuranteANumero(B);
    for(int i = -elem; i<=elem ; i++){
        for(int j = -elem; j<=elem ; j++){
            if(pixelValido({y+i, x+j}, img) && B[i+elem][j+elem] == 1){
                img[y+i][x+j] = 1;
            }
        }
    }
}*/

bool estructuranteTocaPrendido(const imagen& A, const imagen& B, int x, int y){
    int elem = estructuranteANumero(B);
    for(int i = -elem; i<=elem ; i++){
        for(int j = -elem; j<=elem ; j++){
            if(pixelValido({y+i, x+j}, A) && A[i+y][j+x] == 1 && B[i+elem][j+elem] == 1){
                return true;
            }
        }
    }
    return false;
}

imagen dilatar(const imagen& A, const imagen& B){
  imagen img(A.size(), vector<int>(A[0].size(), 0));
  for(int i = 0 ; i<A.size() ; i++){
      for(int j = 0 ; j<A[0].size() ; j++){
          if(estructuranteTocaPrendido(A, B, j, i)){
              img[i][j] = 1;
          }
      }
  }
  return img;
}

bool estructuranteTocaTodosPrendidos(int x, int y, const imagen& A, const imagen& B){
    bool res = true;
    int elem = estructuranteANumero(B);
    for(int i = -elem; i<=elem ; i++){
        for(int j = -elem; j<=elem ; j++){
            if(res == true && pixelValido({y+i, x+j}, A) && A[y+i][x+j] == 0 && B[i+elem][j+elem] == 1){
                res = false;
            }
        }
    }
    return res;
}

imagen erosionar(const imagen& A, const imagen& B){
    imagen img(A.size(), vector<int>(A[0].size(), 0));
    for(int i = 0 ; i<A.size() ; i++){
        for(int j = 0 ; j<A[0].size() ; j++){
            if(estructuranteTocaTodosPrendidos(j, i, A, B)){
                img[i][j] = 1;
            }
        }
    }
    return img;
}

sqPixel obtenerRegionConectadaAux(const pixel& p, const imagen& A, int k){ //esta es la version de obtenerRegion conectada que devuelve una secuencia.
    imagen semilla(A.size(), vector<int>(A[0].size()));
    semilla[p[0]][p[1]] = 1;
    vector<sqPixel> proceso = {secuenciaDual(semilla)};
    while(proceso.size() == 1 || proceso[proceso.size()-1] != proceso[proceso.size()-2]){
        imagen aux = dilatarConAdyacenciaK(semilla, k);
        imagen xi = interseccion(aux, A);
        proceso.push_back(secuenciaDual(xi));
        semilla = xi;
    }
    return proceso[proceso.size()-1];
}
