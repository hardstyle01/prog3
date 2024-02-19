#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Definición de las estructuras
struct LIBRO {
	string titulo;
	string autor;
	string ISBN;
	int aniopublicacion;
};

struct USUARIO {
	int userID;
	string nombre;
	string apellido;
	string email;
};

struct BIBLIOTECARIO {
	int trabajadorID;
	string nombre;
	string apellido;
	string email;
};

// Función para generar una cadena aleatoria de un array dado
string cadenarandomica(const string arr[], int TAM) {
	return arr[rand() % TAM]; // Selecciona una cadena aleatoria del array y la devuelve
}

// Función para generar un número entero aleatorio dentro de un rango dado
int numerrorandomico(int min, int max) {
	return rand() % (max - min + 1) + min; // Genera un número aleatorio dentro del rango y lo devuelve
}

// Función para generar datos aleatorios para las estructuras
void DatosRandomicos(LIBRO* libros, USUARIO* usuarios, BIBLIOTECARIO* bibliotecarios, int TAM) {
	// Arrays fijos de nombres y otros datos
	string listaLibros[] = {"Aprende C", "Aprende PHP", "Aprende Linux", "Aprende Pyhton", "Aprende CISCO"};
	string listaAutores[] = {"José Marquez", "Dillom Forner", "Agatha Linx", "Ruben Neres", "Ever Constantino"};
	string listaISBN[] = {"1", "2", "3", "4", "5", "6", "7"};
	string listaNombres[] = {"Jorge", "Ariel", "Norberto", "Alan", "Cinthia", "Yuliana"};
	string listaApellidos[] = {"Gomez", "Ramirez", "Hernandez", "Andrade", "Foianini", "Peroné", "Santos"};
	
	// Genera datos aleatorios para cada estructura en función del tamaño especificado
	for (int i = 0; i < TAM; ++i) {
		libros[i].titulo = cadenarandomica(listaLibros, sizeof(listaLibros) / sizeof(listaLibros[0]));
		libros[i].autor = cadenarandomica(listaAutores, sizeof(listaAutores) / sizeof(listaAutores[0]));
		libros[i].ISBN = cadenarandomica(listaISBN, sizeof(listaISBN) / sizeof(listaISBN[0]));
		libros[i].aniopublicacion = numerrorandomico(2000, 2022);
		
		usuarios[i].userID = i + 1;
		usuarios[i].nombre = cadenarandomica(listaNombres, sizeof(listaNombres) / sizeof(listaNombres[0]));
		usuarios[i].apellido = cadenarandomica(listaApellidos, sizeof(listaApellidos) / sizeof(listaApellidos[0]));
		usuarios[i].email = usuarios[i].nombre + usuarios[i].apellido + "@gmail.com";
		
		bibliotecarios[i].trabajadorID = 1000 + i;
		bibliotecarios[i].nombre = cadenarandomica(listaNombres, sizeof(listaNombres) / sizeof(listaNombres[0]));
		bibliotecarios[i].apellido = cadenarandomica(listaApellidos, sizeof(listaApellidos) / sizeof(listaApellidos[0]));
		bibliotecarios[i].email = bibliotecarios[i].nombre + bibliotecarios[i].apellido + "@hotmail.com";
	}
}

int main() {
	srand(time(0)); // Inicializar la semilla para generar números aleatorios
	
	const int TAM = 3; // Tamaño de las estructuras
	
	// Declaración de arrays de estructuras
	LIBRO libros[TAM];
	USUARIO usuarios[TAM];
	BIBLIOTECARIO bibliotecarios[TAM];
	
	// Generar datos aleatorios para las estructuras
	DatosRandomicos(libros, usuarios, bibliotecarios, TAM);
	
	// Imprimir los datos generados
	cout << "LIBROS:" << endl;
	for (int i = 0; i < TAM; ++i) {
		cout << "Título: " << libros[i].titulo << ", Autor: " << libros[i].autor << ", ISBN: " << libros[i].ISBN << ", Año de publicación: " << libros[i].aniopublicacion << endl;
	}
	
	cout << "\nUSUARIOS:" << endl;
	for (int i = 0; i < TAM; ++i) {
		cout << "ID: " << usuarios[i].userID << ", Nombre: " << usuarios[i].nombre << ", Apellido: " << usuarios[i].apellido << ", Email: " << usuarios[i].email << endl;
	}
	
	cout << "\nBIBLIOTECARIOS:" << endl;
	for (int i = 0; i < TAM; ++i) {
		cout << "ID de empleado: " << bibliotecarios[i].trabajadorID << ", Nombre: " << bibliotecarios[i].nombre << ", Apellido: " << bibliotecarios[i].apellido << ", Email: " << bibliotecarios[i].email << endl;
	}
	
	return 0;
}

