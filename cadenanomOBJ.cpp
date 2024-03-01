#include <iostream>
#include <cstdlib> // Para la función rand()
#include <ctime>   // Para inicializar la semilla de generación de números aleatorios
#include <string>
using namespace std;

// Definición de la clase Persona
class Persona {
private:
	string nombre;
	string apellido;
	string correo;
	
	// Función privada para generar el correo electrónico
	string generarCorreo() {
		// Convertimos el nombre y apellido a minúsculas
		string correo = nombre + apellido + "@gmail.com";
		return correo;
	}
	
public:
		// Constructor de la clase Persona
		Persona() {
			// Arrays de nombres y apellidos
			string nombres[15] = {"Jorge", "Pedro", "Anabel", "Mario", "Carla", "Elizabeth", "Juan", "Marcos", "Manuel", "Cristina", "Lucia", "Luis", "Maria", "Fernando", "Gabriela"};
			string apellidos[15] = {"Ramirez", "Yabeta", "Diaz", "Hernandez", "Tito", "Sanchez", "Gomez", "Paniagua", "Robles", "Huari", "Torres", "Lopez", "Martinez", "Garcia", "Rodriguez"};
			
			// Asignación aleatoria de nombre, apellido y correo
			nombre = nombres[rand() % 15];
			apellido = apellidos[rand() % 15];
			correo = generarCorreo();
		}
		
		// Métodos para obtener los datos de la persona
		string getNombre() {
			return nombre;
		}
		
		string getApellido() {
			return apellido;
		}
		
		string getCorreo() {
			return correo;
		}
};

// Definición de la clase ejemplo
class ejemplo {
private:
	int ID;
	Persona persona;
	
public:
	// Constructor de la clase ejemplo
	ejemplo(int valor, int valor2) {
		ID = valor;
		// Crear una nueva instancia de Persona
		persona = Persona();
	}
	
	// Métodos para obtener los datos de la persona asociada
	int getID() {
		return ID;
	}
	
	string getNombre() {
		return persona.getNombre();
	}
	
	string getApellido() {
		return persona.getApellido();
	}
	
	string getCorreo() {
		return persona.getCorreo();
	}
	
	// Método para establecer el ID
	void setID(int valor) {
		if (valor > 0)
			ID = valor;
	}
};

int main() {
	// Inicializamos la semilla para la generación de números aleatorios
	srand(time(0));
	
	int num;
	// Solicitar al usuario la cantidad de veces que desea imprimir datos
	cout << "Ingrese la cantidad de veces que desea imprimir datos: ";
	cin >> num;
	
	// Bucle para crear objetos y mostrar datos
	for (int i = 0; i < num; ++i) {
		// Crear una nueva instancia de ejemplo
		ejemplo objeto1(0, 0);
		// Mostrar los datos del objeto
		cout << "objeto1 atributo ID: " << objeto1.getID() << endl;
		cout << "objeto1 atributo nombre: " << objeto1.getNombre() << endl;
		cout << "objeto1 atributo apellido: " << objeto1.getApellido() << endl;
		cout << "objeto1 atributo correo: " << objeto1.getCorreo() << endl;
		cout << "---------------------------" << endl;
	}
	
	return 0;
}
