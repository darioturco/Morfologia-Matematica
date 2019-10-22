#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

void imprimeMatriz(vector<vector<int> > imagen){ // muesta imagen repesentado a un pixel apagado como '0' y a un pixel prendido con '1'
	for(int i = 0 ; i<imagen.size() ; i++){
		for(int j = 0 ; j<imagen[0].size() ; j++){
			cout << imagen[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

bool expConProbaP(float p){
	bool res = (p*10000 > rand() % 10000) ? true : false;
	return res;
}

void pintaAdjacencia4(vector<vector<int> > &imagen, float p, int x, int y){
	if(x-1 >= 0 && expConProbaP(p)){
		imagen[y][x-1] = 1;
		pintaAdjacencia4(imagen, p/1.5, x-1, y);
	}
	if(x+1 < imagen[0].size() && expConProbaP(p)){
		imagen[y][x+1] = 1;
		pintaAdjacencia4(imagen, p/1.5, x+1, y);
	}
	if(y-1 >= 0 && expConProbaP(p)){
		imagen[y-1][x] = 1;
		pintaAdjacencia4(imagen, p/1.5, x, y-1);
	}
	if(y+1 < imagen.size() && expConProbaP(p)){
		imagen[y+1][x] = 1;
		pintaAdjacencia4(imagen, p/1.5, x, y+1);
	}
}

/*Generadores de imagenes*/

vector<vector<int> > todosIguales(int num, int sizeX, int sizeY){// devuelve una imagen con todos sus elementos igual a num
	return vector<vector<int> >(sizeX, vector<int>(sizeY, num));
}

vector<vector<int> > elementoEstructurante(int size){// devuelve un elemento estructurante de tamaño size
	return vector<vector<int> > (size, vector<int>(size, 1));
}

vector<vector<int> > imagenRandomSeed(int sizeX, int sizeY, int seed, float p){// devuelve una imagen aleatoria de maximo 'seed' cantidad de regiones
	int x, y;
	vector<vector<int> > res(sizeY, vector<int>(sizeX, 0));
	for(int i = 0 ; i<seed ; i++){
		x = rand() % sizeX;
		y = rand() % sizeY;
		res[y][x] = 1;
		pintaAdjacencia4(res, p, x, y);
	}
	return res;
}

vector<vector<int> > imagenRandomTotal(int sizeX, int sizeY, float p){// devuelve una imagen totalmente aleatoria donde cada pixel tiene probabilidad p de esta activo
	vector<vector<int> > res(sizeY, vector<int>(sizeX, 0));
	for(int i = 0 ; i<sizeY ; i++){
		for(int j = 0 ; j<sizeX ; j++){
			if(expConProbaP(p)){
				res[i][j] = 1;
			}
		}
	}
	return res;
}

vector<vector<int> > leeImagen(int num){// lee el archivo Matrices.txt, donde estan una lista de matrices binarias, separada cada una por '**'
	char lee1 = 0, lee2 = 0;
	int i = 0, j = 0;
	vector<vector<int> > res(1, vector<int>(0));
	ifstream archivo;
	archivo.open("Matrices.txt", ios::app);
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
		res.pop_back();
	}
	return res;
}

int main(){
	srand(time(NULL));// inicializa el generador de numero aleatorio
	int in = -1;
	int dato = 0;
	int sx, sy, ss;
	float pr;
	while(in != 0){
		cout << "Ingrese una opcion: " << endl;
		cout << "0 = Salir del programa" << endl;
		cout << "1 = Generar una imagen totalemnte aleatoria" << endl;
		cout << "2 = Genera una imagen de almenos n regiones" << endl;
		cout << "3 = Lee una imagen del archivo" << endl;
		cin >> in;
		cout << endl;
		if(in != 0){
			if(in == 1){
				cout << "Cual es el alto de la imagen? (eje Y)" << endl;
				cin >> sy;
				cout << "Cual es el largo de la imagen? (eje X)" << endl;
				cin >> sx;
				cout << "Cual es la probavilidad de que un pixel este activado? (entre 0 y 1)" << endl;
				cin >> pr;
				if(sx > 0 && sy > 0){
					imprimeMatriz(imagenRandomTotal(sx, sy, pr));
				}
			}else{ if(in == 2){
				cout << "Cual es el alto de la imagen? (eje Y)" << endl;
				cin >> sy;
				cout << "Cual es el largo de la imagen? (eje X)" << endl;
				cin >> sx;
				cout << "Cual es la probavilidad inicial de que un pixel este activado? (entre 0 y 1)" << endl;
				cin >> pr;
				cout << "Cual es el maximo de regiones posibles?" << endl;
				cin >> ss;
				if(sx > 0 && sy > 0){
					imprimeMatriz(imagenRandomSeed(sx, sy, ss, pr));
				}
			}else{ if(in == 3){
				cout << "Que numero de imagen va a imprimir? " << endl;
				cin >> dato;
				if(dato >= 0){
					imprimeMatriz(leeImagen(dato));
				}
			}else{
				cout << "Opcion incorrecta XD" << endl;
			}}}
			cout << endl << "Entre un dato para continuar...";
			cin >> in;
			cout << endl << endl << endl;
			in = -1;
		}
	}
	return 0;
}
