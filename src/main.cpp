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
   void mostrarEmpleado(Nodo* nodo) {
        cout << "Codigo: " << nodo->dato.codigo
             << " | Nombre: " << nodo->dato.nombre
             << " | Cargo: " << nodo->dato.cargo << endl;
    }

    Nodo* buscar(Nodo* nodo, int codigo) {
        if (nodo == nullptr || nodo->dato.codigo == codigo) {
            return nodo;
        }
        if (codigo < nodo->dato.codigo) {
            return buscar(nodo->izquierdo, codigo);
        } else {
            return buscar(nodo->derecho, codigo);
        }
    }

    void inorden(Nodo* nodo) {
        if (nodo != nullptr) {
            inorden(nodo->izquierdo);
            mostrarEmpleado(nodo);
            inorden(nodo->derecho);
        }
    }

    void preorden(Nodo* nodo) {
        if (nodo != nullptr) {
            mostrarEmpleado(nodo);
            preorden(nodo->izquierdo);
            preorden(nodo->derecho);
        }
    }

    void postorden(Nodo* nodo) {
        if (nodo != nullptr) {
            postorden(nodo->izquierdo);
            postorden(nodo->derecho);
            mostrarEmpleado(nodo);
        }
    }
public:
    void buscarEmpleado(int codigo) {
        Nodo* resultado = buscar(raiz, codigo);
        if (resultado != nullptr) {
            cout << "\nEmpleado encontrado:\n";
            mostrarEmpleado(resultado);
        } else {
            cout << "\nEmpleado no encontrado.\n";
        }
    }

    void mostrarInorden() {
        cout << "\nRecorrido Inorden:\n";
        inorden(raiz);
    }

    void mostrarPreorden() {
        cout << "\nRecorrido Preorden:\n";
        preorden(raiz);
    }

    void mostrarPostorden() {
        cout << "\nRecorrido Postorden:\n";
        postorden(raiz);
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
        else if (opcion == 2) {
            int codigo;
            cout << "Ingrese codigo a buscar: ";
            cin >> codigo;
            arbol.buscarEmpleado(codigo);
        }
        else if (opcion == 4) {
            arbol.mostrarInorden();
        }
        else if (opcion == 5) {
            arbol.mostrarPreorden();
        }
        else if (opcion == 6) {
            arbol.mostrarPostorden();
        }
    } while (opcion != 0);

    return 0;
}