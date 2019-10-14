var sizeX_tex = 100, sizeY_tex = 100;
var canv;
var sizeX_tex, sizeY_tex, islas_tex, prob_tex, res_tex;
var matriz = [[0]];
var matrizAtraz = [[0]];

function setup() {
  sizeX_tex = document.getElementById("SizeX");
  sizeY_tex = document.getElementById("SizeY");
  islas_tex = document.getElementById("Islas");
  prob_tex = document.getElementById("Probavilidad");
  res_tex = document.getElementById("Result");
  canv = createCanvas(500,500);// crea el canvas de tamaño 500 x 500
  canv.parent(document.getElementById("Canvas"));// lo centra en la posicion correcta
  canv.mousePressed(pulsaMouse);
  background(0);
  stroke(255);
  fill(0,255,0);
  dibujaImagen();
}

function imagenRandom(){ // funcion que se ejecuta cuando se apreta el boton "Random"
  var sx = parseInt(sizeX_tex.value);// pasa como entero el valores de 'Size X: ' a sx
  var sy = parseInt(sizeY_tex.value);
  var prob = Math.abs(parseFloat(prob_tex.value));
  if(sx > 0 && sy > 0){
    guardaImagen();
    matriz = [];
    for(var i = 0 ; i<sy ; i++){
      matriz.push(new Array(sx));
      for(var j = 0 ; j<sx ; j++){
        matriz[i][j] = (Math.random() < prob) ? 1 : 0;
      }
    }
    dibujaImagen();
  }
}

function imagenIslas(){ // funcion que se ejecuta cuando se apreta el boton "Regiones"
  var sx = parseInt(sizeX_tex.value);
  var sy = parseInt(sizeY_tex.value);
  var seed = parseInt(islas_tex.value);
  var prob = Math.abs(parseFloat(prob_tex.value));
  if(sx > 0 && sy > 0 && seed >= 0){
    guardaImagen();
    matriz = imagenSolida(sx, sy, 0);
    for(var i = 0 ; i<seed ; i++){
      var x = Math.floor(Math.random() * sx);
      var y = Math.floor(Math.random() * sy);
      matriz[y][x] = 1;
      pintaAdjacencia4(prob, x, y);
    }
    dibujaImagen();
  }
}
function pintaAdjacencia4(prob, x, y){
  if(x-1 >= 0 && Math.random() < prob){
		matriz[y][x-1] = 1;
		pintaAdjacencia4(prob/1.5, x-1, y);
	}
	if(x+1 < matriz[0].length && Math.random() < prob){
		matriz[y][x+1] = 1;
		pintaAdjacencia4(prob/1.5, x+1, y);
	}
	if(y-1 >= 0 && Math.random() < prob){
		matriz[y-1][x] = 1;
		pintaAdjacencia4(prob/1.5, x, y-1);
	}
	if(y+1 < matriz.length && Math.random() < prob){
		matriz[y+1][x] = 1;
		pintaAdjacencia4(prob/1.5, x, y+1);
	}
}

function imagenSolida(sx, sy, num){
  var mat = [];
  for(var i = 0 ; i<sy ; i++){
    mat.push(new Array(sx));
    for(var j = 0 ; j<sx ; j++){
      mat[i][j] = num;
    }
  }
  return mat;
}

function dibujaImagen(){
  var deltaX = 500/matriz[0].length;
  var deltaY = 500/matriz.length;
  for(var i = 0 ; i<matriz.length ; i++){// dibuja las lineas horizontales
    line(0,i*deltaY,500,i*deltaY);
  }
  for(var i = 0 ; i<matriz[0].length ; i++){// dibuja las lineas verticales
    line(i*deltaX,0,i*deltaX,500);
  }
  for(var i = 0 ; i<matriz.length ; i++){
    for(var j = 0 ; j<matriz[0].length ; j++){
      if(matriz[i][j] > 0){
        fill(0,255,0);//pinta de verde
      }else{
        fill(0,0,0);//pinta de negro
      }
      rect(j*deltaX, i*deltaY, deltaX, deltaY);// pinta el rectangulode lado deltaX y deltaY
    }
  }
}

function guardaImagen(){
  matrizAtraz = matriz;
}

function pulsaMouse(){// funcion que se ejecuta cuando se clickea la imagen
  if(matriz.length > 0){
    var sx = 500/matriz[0].length;
    var sy = 500/matriz.length
    var j = Math.floor(mouseX/sx);
    var i = Math.floor(mouseY/sy);
    if(matriz[i][j] == 0){
      matriz[i][j] = 1;
      fill(0,255,0);//pinta de verde
    }else{
      matriz[i][j] = 0;
      fill(0,0,0);//pinta de negro
    }
    rect(j*sx, i*sy, sx, sy);
  }
}

function imprimeImagen(){
  res_tex.innerHTML = "";
  for(var i = 0 ; i<matriz.length ; i++){
    for(var j = 0 ; j<matriz[i].length ; j++){
      res_tex.innerHTML += matriz[i][j] + ",";
    }
    res_tex.innerHTML = res_tex.innerHTML.substring(0, res_tex.innerHTML.length - 1) + ";<br/>";
  }
  res_tex.innerHTML += "**";
}

function promedioAreas(){
  //Completar
  console.log("promedioAreas");
}

function contorno(){
  //Completar
  console.log("contorno");
}

function cerrarForma(){
  //Completar
  console.log("cerrarForma");
}

function atraz(){
  var mataux = matriz;
  matriz = matrizAtraz;
  dibujaImagen();
  matrizAtraz = mataux;
}
