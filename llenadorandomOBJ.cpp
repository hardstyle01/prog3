#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class ejemplo {
	int iprivado, isegundo;
	
public:
	// Constructor por defecto
	ejemplo() {
		this->iprivado = 0;
		this->isegundo = 0;
	}
	
	// Obtener el valor de iprivado
	int get_iprivado() {
		return iprivado;
	}
	
	// Obtener el valor de isegundo
	int get_isegundo() {
		return isegundo;
	}
	
	// Establecer el valor de iprivado
	void set_iprivado(int valor) {
		if (valor > 0)
			iprivado = valor;
	}
	
	// Establecer el valor de isegundo
	void set_isegundo(int valor) {
		if (valor > 0)
			isegundo = valor;
	}
	
	// Establecer valores para ambos atributos
	void set_ejemplo(int valor, int valor2) {
		if (valor > 0 && valor2 > 0) {
			iprivado = valor;
			isegundo = valor2;
		}
	}
	
	// Destructor
	~ejemplo() {
		iprivado = -1;
		isegundo = -1;
	}
};

// Llenar los objetos con valores aleatorios
void llenar_objetos(ejemplo arrObjeto[], int TAM) {
	srand(time(0));
	for (int i = 0; i < TAM; ++i) {
		int valorAleatorio1 = rand() % 100 + 1;
		int valorAleatorio2 = rand() % 100 + 1;
		arrObjeto[i].set_iprivado(valorAleatorio1);
		arrObjeto[i].set_isegundo(valorAleatorio2);
	}
}

// Imprimir los valores de los objetos
void imprimir_objetos(ejemplo arrObjeto[], int TAM) {
	for (int i = 0; i < TAM; ++i) {
		cout << "Objeto " << i << ": iprivado= " << arrObjeto[i].get_iprivado() << ", isegundo= " << arrObjeto[i].get_isegundo() << endl;
	}
}

// Encontrar el mayor valor de iprivado entre los objetos
int mayor_iprivado(ejemplo arrObjeto[], int TAM) {
	int mayor = arrObjeto[0].get_iprivado();
	for (int i = 1; i < TAM; ++i) {
		if (arrObjeto[i].get_iprivado() > mayor) {
			mayor = arrObjeto[i].get_iprivado();
		}
	}
	return mayor;
}

// Encontrar el mayor valor de isegundo entre los objetos
int mayor_isegundo(ejemplo arrObjeto[], int TAM) {
	int mayor = arrObjeto[0].get_isegundo();
	for (int i = 1; i < TAM; ++i) {
		if (arrObjeto[i].get_isegundo() > mayor) {
			mayor = arrObjeto[i].get_isegundo();
		}
	}
	return mayor;
}

int main(int argc, char *argv[]) {
	const int TAM = 20;
	ejemplo arrObjeto[TAM];
	
	// Llenar los objetos con valores aleatorios
	llenar_objetos(arrObjeto, TAM);
	
	// Imprimir los valores de los objetos
	imprimir_objetos(arrObjeto, TAM);
	
	// Encontrar y mostrar el mayor valor de iprivado
	int mayorIprivado = mayor_iprivado(arrObjeto, TAM);
	cout << "El mayor valor de iprivado es: " << mayorIprivado << endl;
	
	// Encontrar y mostrar el mayor valor de isegundo
	int mayorIsegundo = mayor_isegundo(arrObjeto, TAM);
	cout << "El mayor valor de isegundo es: " << mayorIsegundo << endl;
	
	return 0;
}
