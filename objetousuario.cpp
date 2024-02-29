#include <iostream>
using namespace std;

class ejemplo {
	int iprivado, isegundo;
	
	int ID;
	string nombre;
	string apellido;
	string correo;
	
	
public:
	
	ejemplo(int valor, int valor2, int ID, string nombre, string apellido, string correo) {
		this->iprivado = valor;
		this->isegundo = valor2;
	}
	
	int get_ID(){
		return ID;
	}
	
	
	
	
	
	
	int get_iprivado() {
		return iprivado;
	}
	int get_isegundo() {
		return isegundo;
	}
	
	void set_iprivado(int valor) {
		if (valor > 0)
			iprivado = valor;
	}
	
	void set_isegundo(int valor) {
		if (valor > 0)
			isegundo = valor;
	}
	
	void set_ejemplo(int valor, int valor2) {
		if (valor > 0 && valor2 > 0) {
			iprivado = valor;
			isegundo = valor2;
		}
	}
	
};

int main(int argc, char *argv[]) {
	ejemplo objeto1(0, 0);
	
	cout << "objeto1 atributo iprivado: " << objeto1.get_iprivado() << endl;
	objeto1.set_iprivado(100);
	cout << "objeto1 atributo iprivado: " << objeto1.get_iprivado() << endl;
	objeto1.set_iprivado(-20);
	cout << "objeto1 atributo isegundo: " << objeto1.get_isegundo() << endl;

	return 0;
}

