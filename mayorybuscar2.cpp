#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// Función para imprimir los elementos de un arreglo junto con sus índices
void imprimir(int *n, int cant){
	for (int i=0; i<cant; i++)
		cout << i << " = " << n[i] << endl; // Imprime el índice y el valor del elemento en esa posición
}
	
	// Función recursiva para imprimir los elementos del arreglo en orden inverso
	void imprec(int *n, int cant){
		if (cant > 0){
			imprec(n, cant - 1); // Llamada recursiva para imprimir los elementos restantes
			cout << cant << " = " << n[cant - 1] << endl; // Imprime el índice y el valor del elemento en esa posición
		}
	}
		
		// Función recursiva para encontrar el mayor numero en el arreglo
		void mayor(int *n, int cant, int &m){
			if (cant > 0){
				if (n[cant - 1] > m)
					m = n[cant - 1]; // Actualiza el valor de m si el elemento actual es mayor que m
				mayor(n, cant - 1, m); // Llamada recursiva con el tamaño reducido del arreglo
			}
		}
			
			// Función recursiva para buscar un numero en el arreglo
			void buscar(int *n, int cant, int &buscado)
			{
				if (cant>0)
				{
					if(n[cant-1]==buscado)
						buscado=-1;
					buscar(n,cant-1, buscado);
				}
			}
			
			// Función recursiva para llenar el arreglo con numeros aleatorios
			// Función para llenar el arreglo con números aleatorios
// Función para llenar el arreglo con números aleatorios
void llenarAleatoriamente(int *n, int cant) {
    srand(time(0)); // Inicializa la semilla para generar números aleatorios, se llama solo una vez

    for (int i = 0; i < cant; i++) {
        n[i] = rand() % 100 + 1; // Genera un número aleatorio entre 1 y 100 y lo asigna a la posición actual del arreglo
    }
}


				
				int main(int argc, char *argv[]) {
					const int TAM = 7;
					int numeros[TAM];
					int opcion;
					int m = 0; // Inicializa la variable m para almacenar el mayor numero encontrado
					
					do {
						cout << "Menu:" << endl;
						cout << "1) Llenar arreglo con numeros aleatorios" << endl;
						cout << "2) Imprimir arreglo" << endl;
						cout << "3) Encontrar el mayor numero" << endl;
						cout << "4) Buscar un numero" << endl;
						cout << "0) Salir" << endl;
						cout << "Ingrese una Opcion: ";
						cin >> opcion;
						
						switch (opcion) {
						case 1:
							llenarAleatoriamente(numeros, TAM);
							cout << "Arreglo llenado aleatoriamente." << endl;
							break;
						case 2:
							cout << "IMPRESION RECURSIVA" << endl;
							imprec(numeros, TAM);
							break;
						case 3:
							mayor(numeros, TAM, m);
							cout << "El mayor es: " << m << endl;
							break;
						case 4:
							int buscado;
							cout << "Ingrese el numero a buscar: ";
							cin >> buscado;
							buscar(numeros, TAM, buscado);
							if (buscado == -1)
								cout << "El numero existe en el arreglo." << endl;
							else
								cout << "El numero no existe en el arreglo." << endl;
							break;
						case 0:
							cout << "Saliendo..." << endl;
							break;
						default:
							cout << "Opcion invalida. Intente de nuevo." << endl;
						}
					} while (opcion != 0);
					
					return 0;
				}
				