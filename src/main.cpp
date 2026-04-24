#include <iostream>
#include <string>
using namespace std;

// Estructura para los datos del empleado
struct Empleado {
    int codigo;
    string nombre;
    string cargo;
};

// Estructura del Nodo del Árbol
struct Nodo {
    Empleado dato;
    Nodo* izquierdo;
    Nodo* derecho;
    
    Nodo(Empleado emp) {
        dato = emp;
        izquierdo = nullptr;
        derecho = nullptr;
    }
};

class ArbolBST {
private:
    Nodo* raiz;

    // Lógica privada de inserción
    Nodo* insertar(Nodo* nodo, Empleado emp) {
        if (nodo == nullptr) {
            return new Nodo(emp);
        }
        if (emp.codigo < nodo->dato.codigo) {
            nodo->izquierdo = insertar(nodo->izquierdo, emp);
        } else if (emp.codigo > nodo->dato.codigo) {
            nodo->derecho = insertar(nodo->derecho, emp);
        } else {
            cout << "El codigo ya existe.\n";
        }
        return nodo;
    }

public:
    ArbolBST() {
        raiz = nullptr;
    }

    // Método público para insertar
    void insertarEmpleado(Empleado emp) {
        raiz = insertar(raiz, emp);
    }
};

int main() {
    ArbolBST arbol;
    int opcion;

    do {
        cout << "\n===== MENU ARBOL BST EMPRESARIAL =====\n";
        cout << "1. Insertar empleado\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            Empleado emp;
            cout << "Codigo: ";
            cin >> emp.codigo;
            cin.ignore();
            cout << "Nombre: ";
            getline(cin, emp.nombre);
            cout << "Cargo: ";
            getline(cin, emp.cargo);
            arbol.insertarEmpleado(emp);
        }
    } while (opcion != 0);

    return 0;
}