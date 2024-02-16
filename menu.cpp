#include <iostream>
#include <vector>
#include <cstdlib> // Para generar números aleatorios
#include <ctime>   // Para obtener una semilla aleatoria
#include <algorithm> // Para usar la función shuffle

using namespace std;

const int TAMANIO = 20;

// Prototipos de funciones
void llenarNombres(vector<string> &nombres);
void llenarApellidos(vector<string> &apellidos);
void ofuscarContrasenias(const vector<string> &nombres, const vector<string> &apellidos, vector<string> &contrasenias);
void llenarNotas(vector<float> &notas);
float calcularMedia(const vector<float> &notas);
float encontrarMayor(const vector<float> &notas);
float encontrarMenor(const vector<float> &notas);
void imprimirDatos(const vector<string> &nombres, const vector<string> &apellidos, const vector<string> &contrasenias, const vector<float> &notas);
void salir();

int main() {
	vector<string> nombres(TAMANIO);
	vector<string> apellidos(TAMANIO);
	vector<string> contrasenias(TAMANIO);
	vector<float> notas(TAMANIO);
	
	srand(time(0)); // Inicializar la semilla para obtener valores aleatorios diferentes en cada ejecución
	
	llenarNombres(nombres);
	llenarApellidos(apellidos);
	ofuscarContrasenias(nombres, apellidos, contrasenias);
	llenarNotas(notas);
	
	int opcion;
	do {
		cout << "\nMenu:" << endl;
		cout << "1. Calcular media, mayor y menor de las notas" << endl;
		cout << "2. Imprimir datos" << endl;
		cout << "3. Salir" << endl;
		cout << "Ingrese su opción: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1: {
			float media = calcularMedia(notas);
			float mayor = encontrarMayor(notas);
			float menor = encontrarMenor(notas);
			cout << "La media de las notas es: " << media << endl;
			cout << "La mayor nota es: " << mayor << endl;
			cout << "La menor nota es: " << menor << endl;
			break;
		}
		case 2:
			imprimirDatos(nombres, apellidos, contrasenias, notas);
			break;
		case 3:
			salir();
			break;
		default:
			cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
		}
	} while (opcion != 3);
	
	return 0;
}

// Funciones

void llenarNombres(vector<string> &nombres) {
	// Se puede agregar más variedad de nombres según se necesite
	vector<string> listaNombres = {"Juan", "Maria", "Carlos", "Laura", "Pedro", "Ana", "Luis", "Elena", "Diego", "Sofia"};
	random_shuffle(listaNombres.begin(), listaNombres.end());
	for (int i = 0; i < TAMANIO; ++i) {
		nombres[i] = listaNombres[i % listaNombres.size()];
	}
}

void llenarApellidos(vector<string> &apellidos) {
	// Se puede agregar más variedad de apellidos según se necesite
	vector<string> listaApellidos = {"Gonzalez", "Rodriguez", "Gomez", "Fernández", "Lopez", "Diaz", "Martinez", "Perez", "Garcia", "Sanchez"};
	random_shuffle(listaApellidos.begin(), listaApellidos.end());
	for (int i = 0; i < TAMANIO; ++i) {
		apellidos[i] = listaApellidos[i % listaApellidos.size()];
	}
}

void ofuscarContrasenias(const vector<string> &nombres, const vector<string> &apellidos, vector<string> &contrasenias) {
	for (int i = 0; i < TAMANIO; ++i) {
		string nombreOfuscado = nombres[i], apellidoOfuscado = apellidos[i];
		
		// Ofuscar solo los caracteres específicos
		for (char &c : nombreOfuscado) {
			switch(c) {
			case 'a': case 'A': c = '4'; break;
			case 'e': case 'E': c = '3'; break;
			case 'i': case 'I': c = '1'; break;
			case 'o': case 'O': c = '0'; break;
			case 's': case 'S': c = '5'; break;
			case 't': case 'T': c = '7'; break;
			default: break; // No ofuscar otros caracteres
			}
		}
		
		for (char &c : apellidoOfuscado) {
			switch(c) {
			case 'a': case 'A': c = '4'; break;
			case 'e': case 'E': c = '3'; break;
			case 'i': case 'I': c = '1'; break;
			case 'o': case 'O': c = '0'; break;
			case 's': case 'S': c = '5'; break;
			case 't': case 'T': c = '7'; break;
			default: break; // No ofuscar otros caracteres
			}
		}
		
		// Concatenar el resto de los nombres y apellidos con los dos primeros caracteres ofuscados
		nombreOfuscado += nombres[i].substr(2);
		apellidoOfuscado += apellidos[i].substr(2);
		
		// Agregar un número aleatorio al final
		contrasenias[i] = nombreOfuscado + apellidoOfuscado;
	}
}

void llenarNotas(vector<float> &notas) {
	for (int i = 0; i < TAMANIO; ++i) {
		notas[i] = rand() % 101; // Notas entre 0 y 100
	}
}

float calcularMedia(const vector<float> &notas) {
	float suma = 0;
	for (float nota : notas) {
		suma += nota;
	}
	return suma / notas.size();
}

float encontrarMayor(const vector<float> &notas) {
	float mayor = notas[0];
	for (float nota : notas) {
		if (nota > mayor) {
			mayor = nota;
		}
	}
	return mayor;
}

float encontrarMenor(const vector<float> &notas) {
	float menor = notas[0];
	for (float nota : notas) {
		if (nota < menor) {
			menor = nota;
		}
	}
	return menor;
}

void imprimirDatos(const vector<string> &nombres, const vector<string> &apellidos, const vector<string> &contrasenias, const vector<float> &notas) {
	cout << "\nDatos de los estudiantes:" << endl;
	cout << "Nombres\t\tApellidos\t\tContraseña\t\tNota" << endl;
	for (int i = 0; i < TAMANIO; ++i) {
		cout << nombres[i] << "\t\t" << apellidos[i] << "\t\t" << contrasenias[i] << "\t\t" << notas[i] << endl;
	}
}

void salir() {
	cout << "Saliendo..." << endl;
}
	
	
