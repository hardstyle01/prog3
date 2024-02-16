#include <iostream>
#include <cctype> // Incluir la biblioteca cctype para utilizar las funciones de manejo de caracteres
using namespace std;

// Declaración de la función para contar las vocales en una cadena
void vocales(const char *cadena);

int main(int argc, char *argv[]) {
	char cadena[] = "hola mundo"; // Definimos la cadena de caracteres
	char *pc=cadena;	
	vocales(cadena); // Llamamos a la función vocales pasando el puntero a la cadena
	
	return 0;
}

// Definición de la función para contar las vocales en una cadena
void vocales(const char *cadena) {
	int conteo_vocales = 0;
	
	for (; *cadena != '\0'; cadena++) { // Recorremos la cadena utilizando un bucle for
		char c = tolower(*cadena); // Convertimos el carácter a minúscula antes de compararlo con las vocales
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') { // Verificar si el carácter actual es una vocal
			conteo_vocales++; // Si el carácter es una vocal, incrementamos el contador de vocales
		}
	}
	
	cout << "El número de vocales en la cadena es: " << conteo_vocales << endl; // Imprimimos el resultado del conteo de vocales
}
