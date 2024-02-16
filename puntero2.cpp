#include <iostream>

using namespace std;


int main(int argc, char *argv[]){
	int var=10; //Declara una variable entera llamada var e inicializa su valor en 10.
	int *puntero; //Declara un puntero a un entero llamado puntero.
	puntero=&var; //Asigna la dirección de memoria de la variable var al puntero puntero. Ahora puntero apunta a la dirección de memoria donde se encuentra almacenado var.
	*puntero=100; //Modifica el valor almacenado en la dirección de memoria apuntada por puntero. En este caso, cambia el valor de var de 10 a 100, ya que puntero apunta a var.
	cout<<"var:"<<var<<endl; // Imprime el valor de var en la consola
	cout<<"valor puntero:"<<*puntero<<endl; //Imprime el valor al que apunta puntero,
	cout<<"Direccion puntero:"<<puntero<<endl; //Imprime la dirección de memoria a la que apunta puntero. 
	return 0; //Finaliza la función main y devuelve 0 al sistema operativo, indicando que el programa se ejecutó correctamente.
}
