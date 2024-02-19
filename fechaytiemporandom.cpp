#include <iostream>
#include <vector>
#include <cstdlib> // Para la función rand() y srand()
#include <ctime> // Para la función time()

using namespace std;

struct strTiempo {
	int hora;
	int minuto;
	int segundo;
};

struct strFecha {
	int anio;
	int mes;
	int dia;
};

// Función para generar números aleatorios entre 0 y max-1
int randomica(int max) {
	return rand() % max;
}

// Función para llenar un vector de estructuras de tipo strTiempo con datos aleatorios
void llenado(vector<strTiempo>& t, int cant) {
	for (int i = 0; i < cant; ++i) {
		strTiempo tiempo;
		tiempo.hora = randomica(24); // Genera una hora aleatoria entre 0 y 23
		tiempo.minuto = randomica(60); // Genera un minuto aleatorio entre 0 y 59
		tiempo.segundo = randomica(60); // Genera un segundo aleatorio entre 0 y 59
		t.push_back(tiempo);
	}
}

// Función para llenar un vector de estructuras de tipo strFecha con datos aleatorios
void llenado(vector<strFecha>& f, int cant) {
	for (int i = 0; i < cant; ++i) {
		strFecha fecha;
		fecha.anio = randomica(24) + 2000; // Genera un año aleatorio entre 2000 y 2099
		fecha.mes = randomica(12) + 1; // Genera un mes aleatorio entre 1 y 12
		fecha.dia = randomica(31) + 1; // Genera un día aleatorio entre 1 y 31
		f.push_back(fecha);
	}
}

// Función para imprimir un vector de estructuras de tipo strTiempo
void imprimir(const vector<strTiempo>& t) {
	for (const auto& tiempo : t) {
		cout << "Hora: " << tiempo.hora << ", Minuto: " << tiempo.minuto << ", Segundo: " << tiempo.segundo << endl;
	}
}

// Función para imprimir un vector de estructuras de tipo strFecha
void imprimir(const vector<strFecha>& f) {
	for (const auto& fecha : f) {
		cout << "Año: " << fecha.anio << ", Mes: " << fecha.mes << ", Día: " << fecha.dia << endl;
	}
}

int main(int argc, char *argv[]) {
	const int TAM = 5;
	vector<strTiempo> tiempos;
	vector<strFecha> fechas;
	
	// Inicializa la semilla para la generación de números aleatorios
	srand(time(NULL));
	
	// Llena los vectores con datos aleatorios
	llenado(tiempos, TAM);
	llenado(fechas, TAM);
	
	// Imprime los vectores
	cout << "Datos de Tiempos:" << endl;
	imprimir(tiempos);
	
	cout << endl;
	
	cout << "Datos de Fechas:" << endl;
	imprimir(fechas);
	
	return 0;
}

