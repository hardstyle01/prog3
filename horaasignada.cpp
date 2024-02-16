#include <iostream>
using namespace std;

struct tiempo {
	int hora, minuto, segundo;
};

// Función para imprimir los elementos del array vt
void imprimirVectores(tiempo vt[], int numVectores) {
	for (int i = 0; i < numVectores; ++i) {
		cout << "Hora " << i << ":" << endl;
		cout << vt[i].hora << ":" << vt[i].minuto << ":" << vt[i].segundo << endl;
	}
}

int main(int argc, char *argv[]) {
	const int TMA = 2; // Corregí la declaración de la constante
	tiempo t1, vt[TMA];
	t1.hora = 12;
	t1.minuto = 0;
	t1.segundo = 0;
	
	// Registro del array vt 1
	vt[0].hora = 13;
	vt[0].minuto = 30;
	vt[0].segundo = 10;
	
	// Registro del array vt 2
	vt[1].hora = 23;
	vt[1].minuto = 0;
	vt[1].segundo = 10;
	
	// Llamar a la función para imprimir los vectores vt
	imprimirVectores(vt, TMA);
	
	return 0;
}
