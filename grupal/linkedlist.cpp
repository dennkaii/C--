/*
Enunciado: Crear un programa que simule una lista enlazada.

Autores:
- Edward Perez * 1123238
- Wander Bautista * 1128559
- Henry Torres * 1095100
- Maria G. Florian * 1119634
- Juan A. Reyes *  1126017
- Suri Lara * 1128060

Fecha: 05/09/2025

*/

#include <iostream>
#include <limits>

using namespace std;

namespace ListaEnlazada { 
    // definimos todo dentro de un namespace para resolver un 
    // conflicto que se presento con la funcion is_empty()

struct Nodo {
    int dato;
    Nodo* next;
    Nodo(int d, Nodo* n = nullptr) : dato(d), next(n) {}//constructor
};

struct linkedList {
    Nodo* front;
    linkedList() : front(nullptr) {}
    ~linkedList() { //destructor
        while (front) {
            Nodo* aux = front;
            front = front->next;
            delete aux;
        }
    }
};

bool is_empty(const linkedList& list) {//revisa si la lista esta vacia
    return list.front == nullptr;
}

void insert(linkedList& list, int dato) {
    if (is_empty(list)){
        list.front = new Nodo(dato,nullptr);
        cout << "La lista estaba vacia. Insertando " << dato << " al inicio" << endl;
        return;
    }

    int posicion;
    cout << "Ingregar la posicion  para insertar " << dato << ": ";
    if (!(cin >> posicion)) {
        cout << "Error: Entrada no valida. Por favor, ingresa un numero entero." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    if (posicion <= 0){
        list.front = new Nodo(dato, list.front);
        cout << "insertando " << dato << " en la posicion 0" << endl;
        return;
    }

    Nodo* aux = list.front; 
    int Posicion_actual = 0;

    while(aux != nullptr && Posicion_actual < posicion - 1){
        aux = aux->next;
        Posicion_actual++;
    }

    if (aux == nullptr){
        cout << "No es posible insertar " << dato << " en la posicion " << posicion << endl;
        cout << "insertando " << dato << " al final de la lista" << endl;
        aux = list.front;
        while(aux->next != nullptr){
            aux = aux->next;
        }
        aux->next = new Nodo(dato,nullptr);
    }
    else {
        aux->next = new Nodo(dato,aux->next);
        cout << "Insertando " << dato << " en la posicion" << posicion << "."<< endl;
    }
}

void buscar_valor(const linkedList& list) {
    if (is_empty(list)) {
        cout << "La lista esta vacia. No hay valores para buscar." << endl;
        return;
    }

    int valor;
    cout << "Ingresa el valor a buscar: ";
    if (!(cin >> valor)) {
        cout << "Error: Entrada no valida. Por favor, ingresa un numero entero." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    Nodo* aux = list.front;
    int posicion = 0;

    while (aux != nullptr) {
        if (aux->dato == valor) {
            cout << valor << " fue encontrado en la posicion " << posicion << "." << endl;
            return;
        }
        aux = aux->next;
        posicion++;
    }

    cout << valor << " no fue encontrado en la lista." << endl;
}

void buscar_posicion(const linkedList& list) {
    if (is_empty(list)) {
        cout << "La lista esta vacia. No hay valores para buscar." << endl;
        return;
    }

    int posicion;
    cout << "Ingresa la posicion (indice basado en 0) a buscar: ";
    if (!(cin >> posicion)) {
        cout << "Error: Entrada no valida. Por favor, ingresa un numero entero." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    if (posicion < 0) {
        cout << "Error: La posicion " << posicion << " no es valida." << endl;
        return;
    }

    Nodo* aux = list.front;
    int currentPos = 0;

    while (aux != nullptr && currentPos < posicion) {
        aux = aux->next;
        currentPos++;
    }

    if (aux == nullptr) {
        cout << "Error: La posicion " << posicion << " esta fuera de los limites de la lista." << endl;
    } else {
        cout << "El valor en la posicion " << posicion << " es " << aux->dato << "." << endl;
    }
}

void mostrar(const linkedList& list) {
    if (is_empty(list)) {
        cout << "La lista esta vacia." << endl;
        return;
    }

    cout << "Contenido de la lista: ";
    Nodo* aux = list.front;
    while (aux != nullptr) {
        cout << aux->dato << "->";
        aux = aux->next;
    }
    cout << endl;
}

void eliminar(linkedList& list) {
    if (is_empty(list)) {
        cout << "La lista está vacia. No hay valores para eliminar." << endl;
        return;
    }

    int posicion;
    cout << "Ingresa la posicion para eliminar: ";
    if (!(cin >> posicion)) {
        cout << "Error: Entrada no valida. Por favor, ingresa un número entero." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    if (posicion < 0) {
        cout << "Error: La posicion " << posicion << " no es valida." << endl;
        return;
    }

    if (posicion == 0) {
        Nodo* temporal = list.front;
        list.front = list.front->next;
        cout << "Eliminado el valor " << temporal->dato << " en la posición 0." << endl;
        delete temporal;
        return;
    }

    Nodo* actual = list.front;
    int posicionActual = 0;

    while (actual != nullptr && posicionActual < posicion - 1) {
        actual = actual->next;
        posicionActual++;
    }

    if (actual == nullptr || actual->next == nullptr) {
        cout << "Error: La posición " << posicion << " está fuera de los límites de la lista." << endl;
        return;
    }

    Nodo* temporal = actual->next;
    actual->next = temporal->next;
    cout << "Eliminado el valor " << temporal->dato << " en la posición " << posicion << "." << endl;
    delete temporal;
}

} // Fin del namespace ListaEnlazada

int main() {
    ListaEnlazada::linkedList list;
    int opcion, dato;

    while (true) {
        cout << "\n Listas enlazadas :)\n";
        cout << "1. Insertar un valor\n";
        cout << "2. Buscar\n";
        cout << "3. Mostrar lista\n";
        cout << "4. Eliminar un valor\n";
        cout << "5. Salir\n";
        cout << "Ingresa una opcion: ";
        
        if (!(cin >> opcion)) {
            cout << "Error: Entrada no valida. Por favor, ingresa un numero entero." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (opcion) {
            case 1:
                cout << "Ingresa el valor a insertar: ";
                if (!(cin >> dato)) {
                    cout << "Error: Entrada no valida. Por favor, ingresa un numero entero." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    ListaEnlazada::insert(list, dato);
                }
                break;
            case 2:
                cout << "\nSubmenu de busqueda:\n";
                cout << "1. Buscar por valor\n";
                cout << "2. Buscar por posicion\n";
                cout << "Ingresa una opcion: ";
                int subopcion;
                if (!(cin >> subopcion)) {
                    cout << "Error: Entrada no valida. Por favor, ingresa un numero entero." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    switch (subopcion) {
                        case 1:
                            ListaEnlazada::buscar_valor(list);
                            break;
                        case 2:
                            ListaEnlazada::buscar_posicion(list);
                            break;
                        default:
                            cout << "Opcion no valida. Por favor, ingresa 1 o 2." << endl;
                    }
                }
                break;
            case 3:
                ListaEnlazada::mostrar(list);
                break;
            case 4:
                ListaEnlazada::eliminar(list);
                break;
            case 5:
                cout << "Saliendo del programa." << endl;
                return 0;
            default:
                cout << "Opcion no valida. Por favor, ingresa una opcion entre 1 y 5." << endl;
        }
    }

    return 0;
}