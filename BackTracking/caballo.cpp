#include <iostream>
#include <iomanip>
using namespace std;

#define N 6

int caballo(int x, int y, int mover, int tablero[N][N], int x_coord[], int y_coord[]);

int dentro_tablero(int x, int y, int tablero[N][N]) {
	return (x >= 0 && x < N && y >= 0 && y < N && tablero[x][y] == 0);
}

void imprimir(int tablero[N][N]){
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++){
			cout << " " << setw(2) << tablero[x][y] << " ";			
		}
		cout << endl;
	}
}



int caballo(int x, int y, int mover, int tablero[N][N], int x_coord[], int y_coord[]) {
	int x_sig, y_sig;
	if (mover == N * N){
		return 1;		
	}

	//intenta todos los movimientos para la coordenada x ^ y 
	for (int k = 0; k < 8; k++) {
		x_sig = x + x_coord[k];
		y_sig = y + y_coord[k];
		if (dentro_tablero(x_sig, y_sig, tablero)) {
			tablero[x_sig][y_sig] = mover;
			if (caballo(x_sig, y_sig, mover + 1, tablero, x_coord, y_coord)== 1)
				return 1;
			else
			// backtracking
				tablero[x_sig][y_sig] = 0;
		}
	}
	return 0;
}


int main() {
	int tablero[N][N];

	for (int x = 0; x < N; x++){
		for (int y = 0; y < N; y++){
			tablero[x][y] = 0;			
		}
	}
	
	int x_coord[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int y_coord[] = { 1, 2, 2, 1, -1, -2, -2, -1 };



	if (caballo(0, 0, 1, tablero, x_coord, y_coord) == 0) {
		cout << "no hay solucion";
		return 0;
	}
	else
		imprimir(tablero);

	return 0;
}
