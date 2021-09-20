//TRABAJO_3_EN_RAYA_(1ERA_PARTE)

//INTEGRANTES:
//	Diego Zeballos Cartagena 
//  Mariana Caceres Urquizo
//	Amara Barrera Gutierrez
//	Gabriel Nuñez Arenas

//NOMBRE DEL PROFESOR:
//	DSc. Manuel Eduardo Loaiza Fernández

//DDEOARTAMENTO DE CIENCIAS DE LA COMPUTACION 
// Universidad Católica San Pablo                       Semestre 2021 - I
//                                                        Arequipa - Perú 

#include <iostream>
#include <string>
using namespace std;

int main() {
	int positions[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	int games[3] = {0, 0, 0}; // numero de juegos ya jugados (empates, gana 1, gana 2)
	int player;
	int change; // guardar el num de la casilla que juega el jugador
	int game_state = 0;  
	string name1;
	string name2;
	string replay;
	char char1;
	char char2;
	bool focus = true;
	cout << "Tres en Raya\n\n";
	cout << "Nombre del jugador 1: ";
	cin >> name1;
	while (focus) {
		cout << "Que simbolo quieres? (X/O): ";
		cin >> char1;
		if (char1 == 'X') {
			char2 = 'O';
			focus = false;
		}
		else if (char1 == 'O') {
			char2 = 'X';
			focus = false;
		}
		else {
			cout << "Ese simbolo no es valido\n";
		}
	}	
	focus = true;
	cout << "\nNombre del jugador 2: ";
	cin >> name2;
	string names[2] = {name1, name2};
	char chars[3] = {' ', char1, char2};
	cout << "\n";
    for (int c = 0; c <= 8; c++) { // imprime el tablero tutorial
		cout << "  " << c + 1 << "  ";
		if (c == 8) {
			cout << " ";
		}
		else if ((c + 1) % 3 == 0) {
			cout << "\n-----------------\n";
		}
		else {
			cout << "!";
		}
	}
	cout << "\n\nPara jugar ingresa el numero de una casilla\n\n";
	while (focus) {
		for (int a = 1; a <= 9 && game_state == 0; a++) {  //cada vez que este bucle se repite es un turno
			//muestra el tablero
			for (int c = 0; c <= 8; c++) {
				cout << "  " << chars[positions[c]] << "  ";
				if (c == 8) {
					cout << " ";
				}
				else if ((c + 1) % 3 == 0) {
					cout << "\n-----------------\n";
				}
				else {
					cout << "!";
				}
			}
			player = ((a - 1) % 2) + 1; //alterna entre 1 y 2 cada turno
			cout << "\n\nTurno de " << names[player - 1] << "\n";
			cin >> change;
			//checkea si un espacio está ocupado
			if ((1 <= change) && (positions[change - 1] == 0) && (change <= 9)) {
				positions[change - 1] = player;
			}
			else {
				a -= 1;
				cout << "\nNo es valido\n\n";
			}
			// checkea si alguien ganó
			for (int b = 0; b <= 2; b++) { //columnas
				if (positions[b] == player && positions[b + 3] == player && positions[b + 6] == player) {
					game_state = player;
				}
			}
			for (int b = 0; b <= 6; b += 3) {  //filas
				if (positions[b] == player && positions[b + 1] == player && positions[b + 2] == player) {
					game_state = player;
				}
			}
			if ((positions[0] == player && positions[4] == player && positions[8] == player) || (positions[2] == player && positions[4] == player && positions[6] == player)) {
				game_state = player;    //diagonales
			}
		}
		for (int c = 0; c <= 8; c++) {
			cout << "  " << chars[positions[c]] << "  ";
			if (c == 8) {
				cout << " ";
			}
			else if ((c + 1) % 3 == 0) {
				cout << "\n-----------------\n";
			}
			else {
				cout << "!";
			}
		}
		focus = false;
		if (game_state == 0) {   //verificar el estado del juego
			cout << "\n\nEs un empate";
			games[0] += 1;
		}
		else {
			cout << "\n\nGana " << names[game_state - 1];
			games[game_state] += 1;
		}
		cout << "\a\n\nQuieren jugar de nuevo? (si/no): ";
		cin >> replay;
		if (replay == "si") 
		{
			focus = true;
			for (int d = 0; d <= 8; d++) {
				positions[d] = 0;
			}
			game_state = 0;
			cout << "\nEstan jugando de nuevo\n\n";
			replay = names[0];
			names[0] = names[1];
			names[1] = replay;
			char1 = chars[1];
			chars[1] = chars[2];
			chars[2] = char1;
			change = games[1];
			games[1] = games[2];
			games[2] = change;
		}
	}
	cout << "\nFin del juego\n\nEmpates: " << games[0] << "\n" << names[0] << " gano: " << games[1] << "\n" << names[1] << " gano: " << games[2] << "\n\nTotal: " << games[0] + games[1] + games[2];
	return 0;
}
