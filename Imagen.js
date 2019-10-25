const estruc = 3;// tamaño del elemento estruturante
var sizeX_tex = 100, sizeY_tex = 100;
var canv;
var sizeX_tex, sizeY_tex, islas_tex, prob_tex, res_tex, adj_tex;
var matriz = [[0]];
var matrizAtraz = [[0]];

function setup() {
  sizeX_tex = document.getElementById("SizeX");
  sizeY_tex = document.getElementById("SizeY");
  islas_tex = document.getElementById("Islas");
  prob_tex = document.getElementById("Probavilidad");
  res_tex = document.getElementById("Result");
  adj_tex = document.getElementById("Adjacencia");
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

function apagaArea(mataux, x, y, adj){
  if(adj == 4){
    for(let i = -1 ; i<2 ; i++){
      if(x+i >= 0 && x+i < mataux[0].length && mataux[y][x+i] == 1){
        mataux[y][x+i] = 0;
        mataux = apagaArea(mataux, x+i, y, adj);
      }
      if(y+i >= 0 && y+i < mataux.length && mataux[y+i][x] == 1){
        mataux[y+i][x] = 0;
        mataux = apagaArea(mataux, x, y+i, adj);
      }
    }
  }else{
    for(let i = -1 ; i<2 ; i++){
      for(let j = -1 ; j<2 ; j++){
        if(x+i >= 0 && x+i < mataux[0].length && y+j >= 0 && y+j < mataux.length && mataux[y+j][x+i] == 1){
          mataux[y+j][x+i] = 0;
          mataux = apagaArea(mataux, x+i, y+j, adj);
        }
      }
    }
  }
  return mataux;
}
function cantidadPixelesEncendidos(){
  let cont = 0;
  for(let i = 0 ; i<matriz.length ; i++){
    for(let j = 0 ; j<matriz[0].length ; j++){
      if(matriz[i][j] != 0){
        cont++;
      }
    }
  }
  return cont;
}
function copyMatriz(mat){
  let aux = [[]];
  for(let i = 0 ; i<mat.length ; i++){
    for(let j = 0 ; j<mat[0].length ; j++){
      aux[i].push(mat[i][j]);
    }
    aux.push([]);
  }
  aux.pop();
  return aux;
}

function guardaImagen(){
  matrizAtraz = matriz;
}

function pulsaMouse(){// funcion que se ejecuta cuando se clickea la imagen
  if(matriz.length > 0){
    let sx = 500/matriz[0].length;
    let sy = 500/matriz.length
    let j = Math.floor(mouseX/sx);
    let i = Math.floor(mouseY/sy);
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

function imprimeImagen(form = true){
  if(form){
    res_tex.innerHTML = "{ ";
  }else{
    res_tex.innerHTML = "";
  }
  for(let i = 0 ; i<matriz.length ; i++){
    if(form){
      res_tex.innerHTML += "{";
    }
    for(let j = 0 ; j<matriz[i].length ; j++){
      res_tex.innerHTML += matriz[i][j] + ",";
    }
    if(form){
      res_tex.innerHTML = res_tex.innerHTML.substring(0, res_tex.innerHTML.length - 1) + "},<br/>";
    }else{
      res_tex.innerHTML = res_tex.innerHTML.substring(0, res_tex.innerHTML.length - 1) + ";<br/>";
    }
  }
  if(form){
    res_tex.innerHTML += "}";
  }else{
    res_tex.innerHTML += "**";
  }

}

function promedioAreas(){//
  let adj = parseInt(adj_tex.value);
  let mataux = copyMatriz(matriz);
  let cont = 0;
  let pix = cantidadPixelesEncendidos();
  if(pix != 0){
    for(let i = 0 ; i<mataux.length ; i++){
      for(let j = 0 ; j<mataux[0].length ; j++){
        if(mataux[i][j] == 1){
          mataux = apagaArea(mataux, j, i, adj);
          cont++;
        }
      }
    }
    pix = pix / cont;
  }
  res_tex.innerHTML = "Area = " + pix;
}

function contorno(){//
  guardaImagen();
  let aux = imagenSolida(matriz[0].length, matriz.length, 0);
  let adj = parseInt(adj_tex.value);
  for(let i = 0 ; i<matriz.length ; i++){
    for(let j = 0 ; j<matriz[0].length ; j++){
      let borde = esBorde(j, i);
      if(matriz[i][j] == 1 && (borde || existeUnApagadoAdjacente(j, i, adj, borde))){
        aux[i][j] = 1;
      }
    }
  }
  matriz = aux;
  dibujaImagen();
}
function esBorde(x, y){
  return x == 0 || y == 0 || x == matriz[0].length-1 || y == matriz.length-1;
}
function existeUnApagadoAdjacente(x, y, adj, borde){
    var res = true;
    if(borde == false){
        if(adj == 4){
          res = existeUnApagadoAdjacente4(x, y);
        }else{
          res = existeUnApagadoAdjacente8(x, y);
        }
    }
    return res;
}
function existeUnApagadoAdjacente4(x, y){
  res = false;
  for(let i = -1 ; i<2 ; i++){
     if(res == false && matriz[y+i][x] == 0){
       res = true;
     }
  }
  for(let i = -1 ; i<2 ; i++){
    if(res == false && matriz[y][x+i] == 0){
      res = true;
    }
  }
  return res;
}
function existeUnApagadoAdjacente8(x, y){
  res = false;
  for(let i = -1 ; i<2 ; i++){
    for(let j = -1 ; j<2 ; j++){
      if(res == false && matriz[y+j][x+i] == 0){
        res = true;
      }
    }
  }
  return res;
}

function cerrarForma(){//
  guardaImagen();
  matriz = dilatar();
  matriz = erocionar();
  dibujaImagen();
}
function erocionar(){
  let aux = imagenSolida(matriz[0].length, matriz.length, 0);
  for(let i = 0 ; i<matriz.length ; i++){
    for(let j = 0 ; j<matriz[0].length ; j++){
      if(matriz[i][j] == 1 && estructuranteTocaTodosPrendidos(j, i, estruc)){
        aux[i][j] = 1;
      }
    }
  }
  return aux;
}
function estructuranteTocaTodosPrendidos(x, y, est){
  var res = true;
  var punto = (est-1)/2;
  for(var i = -punto; i<=punto ; i++){
    for(var j = -punto; j<=punto ; j++){
      if(res == true && estaAdentro(x+j, y+i) && matriz[y+i][x+j] == 0){
        res = false;
      }
    }
  }
  return res;
}
function dilatar(){
  let aux = imagenSolida(matriz[0].length, matriz.length, 0);
  for(let i = 0 ; i<matriz.length ; i++){
    for(let j = 0 ; j<matriz[0].length ; j++){
      if(matriz[i][j] == 1){
        aux = prendeElementoEstructurante(j, i, estruc, aux);
      }
    }
  }
  return aux;
}
function prendeElementoEstructurante(x, y, est, mataux){
  var punto = (est-1)/2;
  for(let i = -punto; i<=punto ; i++){
    for(let j = -punto; j<=punto ; j++){
      if(estaAdentro(x+j, y+i)){
        mataux[y+i][x+j] = 1;
      }
    }
  }
  return mataux;
}
function estaAdentro(x, y){
  return x >= 0 && y >= 0 && x < matriz[0].length && y < matriz.length;
}

function atraz(){
  var mataux = matriz;
  matriz = matrizAtraz;
  dibujaImagen();
  matrizAtraz = mataux;
}

function help(){
  console.log("imprimeImegen() \nmatriz = dilatar() \nmatriz = erocionar() \ndibujaImagen()");
}
