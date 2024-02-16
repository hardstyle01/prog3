#include <iostream>
#include <cstdlib> // Para la funci�n rand()
#include <chrono>  // Para la funci�n std::chrono::system_clock::now()
#include <thread>  // Para la funci�n std::this_thread::sleep_for()
using namespace std;

struct tiempo {int hora, minuto, segundo;};

// Funci�n para generar un n�mero aleatorio para las horas (0-23)
int HoraRand() { return rand() % 24; } // Genera un n�mero aleatorio entre 0 y 23

// Funci�n para generar un n�mero aleatorio para los minutos y segundos (0-59)
int msRand() {return rand() % 60; } // Genera un n�mero aleatorio entre 0 y 59

// Funci�n para agregar horas aleatorias al array de tiempo
void agregar(tiempo vt[], int TMA) {
	// Obtiene un valor de tiempo actual como semilla
	auto seed = chrono::system_clock::now().time_since_epoch().count();
	srand(seed); // Inicializa la semilla del generador de n�meros aleatorios
	
	// Genera horas aleatorias para cada elemento del array de tiempo
	for (int i = 0; i < TMA; ++i) {
		vt[i].hora = HoraRand();
		vt[i].minuto = msRand();
		vt[i].segundo = msRand();
	}
}

// Funci�n para imprimir los elementos del array de tiempo
void imprimirVectores(tiempo vt[], int TMA) {
	for (int i = 0; i < TMA; ++i) {
		cout << "" << vt[i].hora << ":" << vt[i].minuto << ":" << vt[i].segundo << endl;
	}
}

// Funci�n principal
int main(int argc, char *argv[]) {
	const int TMA = 10; // Tama�o del array de tiempo
	tiempo t1, vt[TMA]; // Declaraci�n de la estructura de tiempo y el array de tiempo
	
	agregar(vt, TMA); // Llama a la funci�n para agregar horas aleatorias al array de tiempo
	
	imprimirVectores(vt, TMA); // Llama a la funci�n para imprimir los elementos del array de tiempo
	
	return 0; 
}
