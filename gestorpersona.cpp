#include <iostream>
#include <string>
#include <cstdlib> // para la función rand()
using namespace std;

class Persona {
	int userID;
	string nombre;
	string apellido;
	string correo;
public:
	
	Persona() : nombre(""), apellido(""), correo("") {}
	Persona(string n, string a) : nombre(n), apellido(a), correo(n + "." + a + "@example.com") {}
	string get_nombre(){ return nombre;}
	string get_apellido(){ return apellido;}
	string get_correo(){ return correo;}
	void set_nombre(string n){ nombre=n;}
	void set_apellido(string a){ apellido=a;}
};

string nombres[] = {"Jorge", "Pedro", "Anabel", "Mario", "Carla", "Elizabeth", "Juan", "Marcos", "Manuel", "Cristina", "Lucia", "Luis", "Maria", "Fernando", "Gabriela"};
string apellidos[] = {"Ramirez", "Yabeta", "Diaz", "Hernandez", "Tito", "Sanchez", "Gomez", "Paniagua", "Robles", "Huari", "Torres", "Lopez", "Martinez", "Garcia", "Rodriguez"};

int randomico(int max) {
	return rand() % max;
}

const int TAM=10;
class GestorPersonas {
private:
	
	Persona personas[TAM]; // Tamaño fijo para simplificar el ejemplo
	int tamanoActual;
	
public:
	GestorPersonas() : tamanoActual(0) {}
	
	void agregarPersona(const Persona& p) {
		if(tamanoActual < 10) {
			personas[tamanoActual++] = p;
		} else {
			cout << "Arreglo lleno." << endl;
		}
	}
	
	void imprimirPersonas() {
		for(int i = 0; i < tamanoActual; ++i) {
			cout << personas[i].get_nombre() << " " << personas[i].get_apellido() << " - " << personas[i].get_correo() << endl;
		}
	}
	
	int buscarPersona(const string& nombre) {
		for(int i = 0; i < tamanoActual; ++i) {
			if(personas[i].get_nombre() == nombre) {
				return i;
			}
		}
		return -1;
	}
	
	void llenadoAleatorio() {
		for (int i = 0; i < TAM; ++i) {
			string nombre = nombres[randomico(15)];
			string apellido = apellidos[randomico(15)];
			agregarPersona(Persona(nombre, apellido));
		}
		cout << "Usuarios generados aleatoriamente." << endl;
	}
};

void menu(GestorPersonas& gestor) {
	int opcion;
	string nombre;
	do {
		cout << "\n----- Menú -----\n";
		cout << "1. Agregar Persona\n";
		cout << "2. Mostrar Personas\n";
		cout << "3. Buscar Persona\n";
		cout << "4. Llenar Aleatoriamente\n";
		cout << "5. Salir\n";
		cout << "Ingrese su opción: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			cout << "Ingrese el nombre de la persona: ";
			cin >> nombre;
			gestor.agregarPersona(Persona(nombre, ""));
			break;
		case 2:
			cout << "Lista de Personas:\n";
			gestor.imprimirPersonas();
			break;
		case 3:
			cout << "Ingrese el nombre de la persona a buscar: ";
			cin >> nombre;
			if (gestor.buscarPersona(nombre) != -1)
				cout << "La persona está en la lista.\n";
			else
				cout << "La persona no está en la lista.\n";
			break;
		case 4:
			gestor.llenadoAleatorio();
			break;
		case 5:
			cout << "Saliendo del programa...\n";
			break;
		default:
			cout << "Opción no válida. Intente de nuevo.\n";
			break;
		}
	} while (opcion != 5);
}

int main() {
	GestorPersonas gestor;
	menu(gestor);
	return 0;
}
