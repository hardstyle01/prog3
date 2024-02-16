#include <iostream>

using namespace std;


int main(int argc, char *argv[]){
	int var=10; //Declara una variable entera llamada var e inicializa su valor en 10.
	int num=0;
	double real=10.5;
	double *ptreal;
	int * puntero=NULL; //Declara un puntero a un entero llamado puntero.
	int * ptrint=NULL;
	puntero=&var; //Asigna la dirección de memoria de la variable var al puntero puntero. Ahora puntero apunta a la dirección de memoria donde se encuentra almacenado var.
	puntero=&num;
	ptrint=puntero;
	
	cout<<"var:"<<var<<endl; // Imprime el valor de var en la consola
	cout<<"valor puntero:"<<*puntero<<endl; //Imprime el valor al que apunta puntero,
	cout<<"Direccion puntero:"<<puntero<<endl; //Imprime la dirección de memoria a la que apunta puntero. 
	return 0; //Finaliza la función main y devuelve 0 al sistema operativo, indicando que el programa se ejecutó correctamente.
}
	
