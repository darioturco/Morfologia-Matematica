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

imagen leeImagen(int num){// lee el archivo Matrices.txt, donde estan una lista de matrices binarias, separada cada una por '**'
	char lee1 = 0, lee2 = 0;
	int i = 0, j = 0;
	imagen res(1, vector<int>(0));
	ifstream archivo;
	archivo.open("ImagenesTxt.txt", ios::app);
	while(!archivo.eof()){
		archivo >> lee1 >> lee2;
		if(lee1 == '*' && lee2 == '*'){
			j++;
		}else{
			if(j == num){
				res[i].push_back(lee1 - '0');
				if(lee2 == ';'){
					res.push_back(vector<int>(0));
					i++;
				}
			}
		}
	}
	archivo.close();
	if(j >= num){
		res.pop_back();
		//res.pop_back();
	}
	return res;
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

imagen copiaImagen(const imagen& A){ //Hace una copia independiente de una imagen (NO es una copia por referencia)
	imagen img;
	img.push_back(vector<int>(0));
	for(int i = 0 ; i<A.size() ; i++){
    	for(int j = 0 ; j<A[0].size() ; j++){
      		img[i].push_back(A[i][j]);
    	}
    	img.push_back(vector<int>(0));
	}
	img.pop_back();
	return img;
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

imagen elementoEstructurante(int size){// devuelve un elemento estructurante de tamaño size
	return vector<vector<int> > (size, vector<int>(size, 1));
}

int estructuranteANumero(const imagen &B){
	return (B.size()-1)/2;
}

pixel newPixel(int x, int y){
	pixel px(2);
	px[0] = x;
	px[1] = y;
	return px;
}

void prendeElementoEstructurante(int x, int y, int elem, imagen &img){
	for(int i = -elem; i<=elem ; i++){
    	for(int j = -elem; j<=elem ; j++){
    		if(pixelValido(newPixel(y+i, x+j), img)){
        		img[y+i][x+j] = 1;
      		}
    	}
  	}
}

imagen dilatarConEstructurante(const imagen &A, int elem){
	imagen img(A.size(), vector<int>(A[0].size(), 0));
	for(int i = 0 ; i<A.size() ; i++){
	    for(int j = 0 ; j<A[0].size() ; j++){
	    	if(A[i][j] == 1){
	    		prendeElementoEstructurante(j, i, elem, img);
	    	}
	    }
	}
	return img;
}

bool estructuranteTocaTodosPrendidos(int x, int y, int elem, const imagen& A){
	int res = true;
	for(int i = -elem; i<=elem ; i++){
		for(int j = -elem; j<=elem ; j++){
			if(res == true && pixelValido(newPixel(y+i, x+j), A) && A[y+i][x+j] == 0){
				res = false;
			}
		}
	}
	return res;
}

imagen erocionaConEstructurante(const imagen &A, int elem){
	imagen img(A.size(), vector<int>(A[0].size(), 0));
	for(int i = 0 ; i<A.size() ; i++){
		for(int j = 0 ; j<A[0].size() ; j++){
			if(A[i][j] == 1 && estructuranteTocaTodosPrendidos(j, i, elem, A)){
				img[i][j] = 1;
				
			}
		}
	}
	return img;
}
