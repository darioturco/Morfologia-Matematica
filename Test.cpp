//deberia hacer incluciones ???

/***************** Test Propios *******************************/

int testEjercicio1(){
	int cont = 0;
	
	return cont;
}

int testEjercicio2(){
	int cont = 0;
	imagen img;
	pixel px1, px2;
	
	//Test 1 
	img = { {0,0,0,0,0,1,1,1,0,0},
			{0,0,0,0,1,1,1,1,0,0},
			{0,0,0,1,1,1,1,1,0,0},
			{0,0,1,1,1,1,1,0,0,0},
			{0,0,0,1,1,1,0,0,0,0},
			{0,0,0,0,1,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0}}
	
	
	
	
	return cont;
}

int testEjercicio3(){
	int cont = 0;
	float res = 0;
	imagen img;
	
	//Test 1
	//Una region adjacencia 4
	cout << "Empesando test 1 ejericio 3:" << endl;
	img = { {0,0,0,0,0,1,1,1,0,0},
			{0,0,0,0,1,1,1,1,0,0},
			{0,0,0,1,1,1,1,1,0,0},
			{0,0,1,1,1,1,1,0,0,0},
			{0,0,0,1,1,1,0,0,0,0},
			{0,0,0,0,1,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0}}
	res = devolverPromedioAreas(img, 4);
	if(res == 21){
		cont++;
	}else{
		cout << "Test 1 ejericio 3 Fallo, esperaba 21, dio: " << res << endl;
	}
	
	//Test 2
	//Una region adjacencia 8
	cout << "Empesando test 2 ejericio 3:" << endl;
	img = { {0,0,0,0,0,1,1,1,0,0},
			{0,0,0,0,1,1,1,1,0,0},
			{0,0,0,1,1,1,1,1,0,0},
			{0,0,1,1,1,1,1,0,0,0},
			{0,0,0,1,1,1,0,0,0,0},
			{0,0,0,0,1,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0}}
	res = devolverPromedioAreas(img, 8);
	if(res == 21){
		cont++;
	}else{
		cout << "Test 2 ejericio 3 Fallo, esperaba 21, dio: " << res << endl;
	}
	
	//Test 3
	//Dos region adjacencia 8
	cout << "Empesando test 3 ejericio 3:" << endl;
	img = { {0,0,0,0,0,0,0,0,0,0},
			{0,1,1,1,0,0,0,0,0,0},
			{0,1,1,1,0,0,0,0,0,0},
			{0,1,1,1,1,0,0,0,0,0},
			{0,0,0,1,0,0,0,0,0,0},
			{0,0,0,0,0,0,1,0,0,0},
			{0,0,0,0,0,1,1,1,1,0},
			{0,0,0,0,0,0,1,1,1,0},
			{0,0,0,0,0,0,1,1,1,0},
			{0,0,0,0,0,0,0,0,0,0}}
	res = devolverPromedioAreas(img, 8);
	if(res == 11){
		cont++;
	}else{
		cout << "Test 3 ejericio 3 Fallo, esperaba 11, dio: " << res << endl;
	}
	
	//Test 4
	//
	cout << "Empesando test 4 ejericio 3:" << endl;
	img = { {0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,1,0,0,0,0,0,0},
			{0,0,0,0,1,1,0,0,0,0,0,0},
			{0,0,0,1,1,1,1,0,0,0,0,0},
			{0,0,1,1,1,1,0,1,1,0,0,0},
			{0,1,1,1,1,0,1,1,0,0,0,0},
			{0,1,1,1,0,1,1,0,1,0,0,0},
			{0,0,1,0,1,1,0,1,1,0,0,0},
			{0,0,0,1,1,0,1,1,0,0,0,0},
			{0,0,1,1,0,1,1,0,0,0,0,0},
			{0,0,0,0,1,1,0,0,0,0,0,0},
			{0,0,0,1,1,0,0,0,0,0,0,0}}
	res = devolverPromedioAreas(img, 4);
	if(res == 42){
		cont++;
	}else{
		cout << "Test 4 ejericio 3 Fallo, esperaba 42, dio: " << res << endl;
	}
	
	//Test 5
	//
	cout << "Empesando test 5 ejericio 3:" << endl;
	img = { {0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,1,0,0,0,0,0,0},
			{0,0,0,0,1,1,0,0,0,0,0,0},
			{0,0,0,1,1,1,1,0,0,0,0,0},
			{0,0,1,1,1,1,0,1,1,0,0,0},
			{0,1,1,1,1,0,1,1,0,0,0,0},
			{0,1,1,1,0,1,1,0,1,0,0,0},
			{0,0,1,0,1,1,0,1,1,0,0,0},
			{0,0,0,1,1,0,1,1,0,0,0,0},
			{0,0,1,1,0,1,1,0,0,0,0,0},
			{0,0,0,0,1,1,0,0,0,0,0,0},
			{0,0,0,1,1,0,0,0,0,0,0,0}}
	res = devolverPromedioAreas(img, 8);
	if(res == 14){
		cont++;
	}else{
		cout << "Test 5 ejericio 3 Fallo, esperaba 14, dio: " << res << endl;
	}
	
	//Test 5
	// Imagen vacia adjacencia 4
	cout << "Empesando test 5 ejericio 3:" << endl;
	img = { {0,0,0,0,0},
			{0,0,0,0,0},
			{0,0,0,0,0},
			{0,0,0,0,0},
			{0,0,0,0,0}}
	res = devolverPromedioAreas(img, 4);
	if(res == 0){
		cont++;
	}else{
		cout << "Test 5 ejericio 3 Fallo, esperaba 0, dio: " << res << endl;
	}
	
	//Test 6
	// Imagen vacia adjacencia 8
	cout << "Empesando test 5 ejericio 3:" << endl;
	img = { {0,0,0,0,0},
			{0,0,0,0,0},
			{0,0,0,0,0},
			{0,0,0,0,0},
			{0,0,0,0,0}}
	res = devolverPromedioAreas(img, 8);
	if(res == 0){
		cont++;
	}else{
		cout << "Test 6 ejericio 3 Fallo, esperaba 0, dio: " << res << endl;
	}
	
	cout << "Fin de los test ejercicio 3, resultado: " << cont;
	return cont;
}

int testEjercicio4(){
	int cont = 0;
	
	return cont;
}

int testEjercicio5(){
	int cont = 0;
	
	return cont;
}

int testEjercicio6(){
	int cont = 0;
	
	return cont;
}
