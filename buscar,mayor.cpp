#include <iostream>
using namespace std;

// Función para imprimir los elementos de un arreglo
void imprimir(int *n, int cant){
	for (int i=0; i<cant; i++)
		cout << i << " = " << n[i] << endl;
}
	
void imprec(int *n, int cant){
	if (cant>0)
	{
		imprec(n,cant-1);
		cout<<cant<<" = "<<n[cant-1]<<endl;
	}
	
}
	
void mayor(int *n, int cant, int &m)
{
	if(cant>0)
	{
		if(n[cant-1]>m)
			m=n[cant-1];
		mayor(n,cant-1,m);
	}
}

int main(int argc, char *argv[]) {
		const int TAM = 7;
		int numeros[] = {3, 5, 2, 8, 1, 7, 4};
		int m=0;
		
		// Imprimir los elementos del arreglo utilizando un bucle
		cout << "IMPRESION BUCLE" << endl;
		imprimir(numeros, TAM);
		
		// Imprimir los elementos del arreglo en orden inverso utilizando recursión
		cout << "IMPRESION RECURSIVA" << endl;
		imprec(numeros, TAM);
		
		mayor(numeros,TAM,m);
		cout<<"mayor es: "<<m<<endl;
		
		return 0;
	}
