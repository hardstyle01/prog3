#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Definici�n de las estructuras
struct LIBRO {
	string title;
	string author;
	string ISBN;
	int publicationYear;
};

struct USUARIO {
	int userID;
	string name;
	string lastname;
	string email;
};

struct BIBLIOTECARIO {
	int employeeID;
	string name;
	string lastname;
	string email;
};

// Funci�n para generar una cadena aleatoria de un array dado
string generateRandomString(const string arr[], int size) {
	return arr[rand() % size]; // Selecciona una cadena aleatoria del array y la devuelve
}

// Funci�n para generar un n�mero entero aleatorio dentro de un rango dado
int generateRandomInt(int min, int max) {
	return rand() % (max - min + 1) + min; // Genera un n�mero aleatorio dentro del rango y lo devuelve
}

// Funci�n para generar datos aleatorios para las estructuras
void generateRandomData(LIBRO* libros, USUARIO* usuarios, BIBLIOTECARIO* bibliotecarios, int size) {
	// Arrays fijos de nombres y otros datos
	string listaLibros[] = {"Aprende C", "Aprende PHP", "Aprende Linux", "Aprende Pyhton", "Aprende CISCO"};
	string listaAutores[] = {"Jos� Marquez", "Dillom Forner", "Agatha Linx", "Ruben Neres", "Ever Constantino"};
	string listaISBN[] = {"1", "2", "3", "4", "5", "6", "7"};
	string listaNombres[] = {"Jorge", "Ariel", "Norberto", "Alan", "Cinthia", "Yuliana"};
	string listaApellidos[] = {"Gomez", "Ramirez", "Hernandez", "Andrade", "Foianini", "Peron�", "Santos"};
	
	// Genera datos aleatorios para cada estructura en funci�n del tama�o especificado
	for (int i = 0; i < size; ++i) {
		libros[i].title = generateRandomString(listaLibros, sizeof(listaLibros) / sizeof(listaLibros[0]));
		libros[i].author = generateRandomString(listaAutores, sizeof(listaAutores) / sizeof(listaAutores[0]));
		libros[i].ISBN = generateRandomString(listaISBN, sizeof(listaISBN) / sizeof(listaISBN[0]));
		libros[i].publicationYear = generateRandomInt(2000, 2022);
		
		usuarios[i].userID = i + 1;
		usuarios[i].name = generateRandomString(listaNombres, sizeof(listaNombres) / sizeof(listaNombres[0]));
		usuarios[i].lastname = generateRandomString(listaApellidos, sizeof(listaApellidos) / sizeof(listaApellidos[0]));
		usuarios[i].email = usuarios[i].name + usuarios[i].lastname + "@gmail.com";
		
		bibliotecarios[i].employeeID = 1000 + i;
		bibliotecarios[i].name = generateRandomString(listaNombres, sizeof(listaNombres) / sizeof(listaNombres[0]));
		bibliotecarios[i].lastname = generateRandomString(listaApellidos, sizeof(listaApellidos) / sizeof(listaApellidos[0]));
		bibliotecarios[i].email = bibliotecarios[i].name + bibliotecarios[i].lastname + "@hotmail.com";
	}
}

int main() {
	srand(time(0)); // Inicializar la semilla para generar n�meros aleatorios
	
	const int size = 3; // Tama�o de las estructuras
	
	// Declaraci�n de arrays de estructuras
	LIBRO libros[size];
	USUARIO usuarios[size];
	BIBLIOTECARIO bibliotecarios[size];
	
	// Generar datos aleatorios para las estructuras
	generateRandomData(libros, usuarios, bibliotecarios, size);
	
	// Imprimir los datos generados
	cout << "LIBROS:" << endl;
	for (int i = 0; i < size; ++i) {
		cout << "T�tulo: " << libros[i].title << ", Autor: " << libros[i].author << ", ISBN: " << libros[i].ISBN << ", A�o de publicaci�n: " << libros[i].publicationYear << endl;
	}
	
	cout << "\nUSUARIOS:" << endl;
	for (int i = 0; i < size; ++i) {
		cout << "ID: " << usuarios[i].userID << ", Nombre: " << usuarios[i].name << ", Apellido: " << usuarios[i].lastname << ", Email: " << usuarios[i].email << endl;
	}
	
	cout << "\nBIBLIOTECARIOS:" << endl;
	for (int i = 0; i < size; ++i) {
		cout << "ID de empleado: " << bibliotecarios[i].employeeID << ", Nombre: " << bibliotecarios[i].name << ", Apellido: " << bibliotecarios[i].lastname << ", Email: " << bibliotecarios[i].email << endl;
	}
	
	return 0;
}
