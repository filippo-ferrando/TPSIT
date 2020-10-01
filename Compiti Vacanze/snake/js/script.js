"use strict";
const DIM = 20; // costante dimensione campo

var campo; // Vettore campo da gioco

var direzione = "dx"; // Direzione dello snake all'avvio

/* costanti per colori */
const GRIGIO = "rgb(127, 127, 127)";
const BIANCO = "rgb(255, 255, 255)"; // #FFFFFF
const ROSSO = "rgb(255, 0, 0)";
const BLU = "rgb(0, 0, 255)";

/* POSIZIONE SNAKE */
var posSn_x = 1; // coordinata x snake
var posSn_y = 1; // coordinata y snake
var coda = new Array(); // array contenente le posizioni dello snake
var xCibo;
var yCibo;

/* PER MEMORIZZARE IL TIMEOUT */
var tOut;

function avvia() {
  initMatrice(); // inizializzare matrice di gioco
  disegnaCampo(); // disegno grafica campo

  coda.push(posSn_x + "," + posSn_y); // carico in coda posizione iniziale serpente

  // Generazione del cibo su coordinate random x, y
  generaCibo();

  // Coloriamo la testa dello snake
  document.getElementById("btn_" + posSn_x + "_" + posSn_y).style
    .backgroundColor = BLU;
  muoviSnake();
}

function initMatrice() {
  campo = new Array(DIM);
  for (let i = 0; i < DIM; i++) {
    campo[i] = new Array(DIM);
  }
  for (let i = 0; i < DIM; i++) {
    for (let j = 0; j < DIM; j++) {
      campo[i][j] = 0;
    }
  }
}

function disegnaCampo() {
  // refBody = document.getElementById('campo_gioco');
  var refBody = document.getElementsByTagName("body")[0];
  var tabella = document.createElement("table");

  var cella, riga, btn;

  refBody.appendChild(tabella); // in campo_gioco {div} => inserisco componente html table {tabella}

  tabella.style.margin = "20px auto";
  tabella.style.borderSpacing = "0";

  for (let i = 0; i < DIM; i++) {
    riga = document.createElement("tr");
    tabella.appendChild(riga);
    for (let j = 0; j < DIM; j++) {
      //matrice[i][j] = 0;
      // creazione cella
      cella = document.createElement("td");
      cella.style.width = "18px";
      riga.appendChild(cella);
      //creazione pulsante
      btn = document.createElement("input");
      btn.type = "button";
      btn.id = "btn_" + i + "_" + j; // btn_riga_colonna
      btn.style.width = "18px";
      btn.style.height = "15px";
      btn.style.backgroundColor = GRIGIO;
      btn.style.color = BIANCO;
      // setto evento
      btn.setAttribute("onClick", "get_coord(this);");

      cella.appendChild(btn);
    }
  }
}

function get_coord(btn) {
  // btn_2_4
  let vect = btn.id.split("_");
  alert(vect[1] + " " + vect[2]);
}

function generaCibo() {
  xCibo = Math.floor(DIM * Math.random());
  yCibo = Math.floor(DIM * Math.random());

  let pulsante = document.getElementById("btn_" + xCibo + "_" + yCibo);

  pulsante.style.backgroundColor = ROSSO;
  campo[xCibo][yCibo] = 2; // matrice assegno valore 2 in posizione cibo
  /*
     MATRICE CAMPO
     0 => cella vuota
     1 => snake
     2 => cibo
     */
}

function muoviSnake() {
  let dead = false;

  // 1. intercettare la direzione dx, sx, up, dw
  switch (direzione) {
    /*
         0 1 0 0 0 0 0 0 0 
         0 0 0 0 0 0 0 0 0  
         0 0 0 0 0 0 0 0 0
         0 0 0 0 0 0 0 0 0
         */
    case "dx":
      if (posSn_y + 1 > 19) {
        alert("Sei Morto");
        dead = true;
      } else {
        posSn_y++;
      }
      break;
    case "sx":
      if (posSn_y - 1 < 0) {
        alert("Sei Morto");
        dead = true;
      } else {
        posSn_y--;
      }
      break;
    case "up":
      if (posSn_x - 1 < 0) {
        alert("Sei Morto");
        dead = true;
      } else {
        posSn_x--;
      }
      break;
    case "dw":
      if (posSn_x + 1 > 19) {
        alert("Sei Morto");
        dead = true;
      } else {
        posSn_x++;
      }
      break;
  }

  // 1.5 controlla se ti mangi da solo
  if (coda.includes(posSn_x + "," + posSn_y)) {
    alert("Sei morto");
    dead = true;
  }

  // 2. resettare lo snake
  //   resettaSnake();
  let hitFood = false;
  if (posSn_y == yCibo && posSn_x == xCibo) {
    hitFood = true;
    generaCibo();
    if (direzione == "dx") {
      posSn_y--;
      posSn_y++;
    }
    if (direzione == "sx") {
      posSn_y++;
      posSn_y--;
    }
    if (direzione == "up") {
      posSn_x++;
      posSn_x--;
    }
    if (direzione == "dw") {
      posSn_x--;
      posSn_x++;
    }
  }
  // 2.5 aggiorno la coda dello snake
  coda.push(posSn_x + "," + posSn_y);

  // 3. stampo snake
  stampaSnake();

  // 3.5 rimuovo la coda dello snake
  if (!hitFood) coda.shift();

  // 4. timout
  if (!dead) tOut = setTimeout("muoviSnake();", 200);
}

function cambiaDirezione(event) {
  let codice = event.keyCode;
  if (codice == 37) {
    direzione = "sx";
  }
  if (codice == 38) {
    direzione = "up";
  }
  if (codice == 39) {
    direzione = "dx";
  }
  if (codice == 40) {
    direzione = "dw";
  }
}

function resettaSnake() {
  document.getElementById("btn_" + posSn_x + "_" + posSn_y).style
    .backgroundColor = GRIGIO;
}

function stampaSnake() {
  // migliorare la funzione
  document.getElementById("btn_" + posSn_x + "_" + posSn_y).style
    .backgroundColor = BLU;
  const [x, y] = coda[0].split(",");
  document.getElementById("btn_" + x + "_" + y).style.background = GRIGIO;
}
