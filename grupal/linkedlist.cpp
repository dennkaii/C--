/*
Enunciado: Crear un programa que simule una lista enlazada.

Autores:
- Edward Perez * 1123238
- Wander Bautista * 1128559
- Henry Torres * 1095100
- Maria G. Florian * 1119634
- Juan A. Reyes *  1126017
- Suri Lara * 1128060

Fecha: 10/09/2025

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
    linkedList() : front(nullptr) {}//constructor
    ~linkedList() { //destructor
        while (front) {
             // liberar por si quedó algo en la lista
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
    Nodo* newNode = new Nodo(dato);
    if (is_empty(list) || dato < list.front->dato) { // revisa sila lista esta vacia y si el dato ingresado es menor que el dato al frente de la lista.
        newNode->next = list.front;
        list.front = newNode;// Inserta el dato al frrente de la lista.
        cout << "Insertando " << dato << " al inicio" << endl;
        return;
    }

    Nodo* current = list.front;// creamos un nodo auxiliar llamado current


    // revisamos si el valor existe  antes de agregarlo
    while (current != nullptr) {
    if (current->dato == dato) {
        cout << "El dato " << dato << " ya existe. No se insertara." << endl;
        delete newNode; // liberar memoria, ya que no lo vamos a usar
        return; // salir sin insertar
    }
    current = current->next;
}

    // se utliza para buscar el lugar donde vamos a insertar el nodo 
    while (current->next != nullptr && current->next->dato < dato) { // mientrasproximo de current es diferente de null y el proximo dato de current es menor que el dato
        current = current->next; // current va ir aputando al siguiente hasta que se cumplan las condiciones de arriba
    }
    newNode->next = current->next;// volvemos el proximo del nuevo nodo el  siguiente del nodo current
    current->next = newNode;// y llamamos el sigueinte del nodo current el nuevo nodo
    cout << "Insertando " << dato << " en orden ascendente" << endl;
}


// busca en la lista por valores
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
    // nodo auxiliar + un contador de posicion
    Nodo* aux = list.front;
    int posicion = 0;

    while (aux != nullptr) {// mientras el nodo no apunte a null
        if (aux->dato == valor) {// en caso de que el dato del auxiliar sea igual al valor lo devuelve
            cout << valor << " fue encontrado en la posicion " << posicion << "." << endl;
            return;
        }
        aux = aux->next; //sino sigue iterando
        posicion++;
    }
        
    cout << valor << " no fue encontrado en la lista." << endl;// en el caso de no encontrar nada
}
// busca en la lista por posicion empezando desde el 0
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
    // la posicion on puede ser negativa
    if (posicion < 0) {
        cout << "Error: La posicion " << posicion << " no es valida." << endl;
        return;
    }
    // inicializamos un nodo auxiliar y un contador para la posicion
    Nodo* aux = list.front;
    int currentPos = 0;
    // mientras la posicion actual sea 
    // diferente de la posicion que queremos el nodo ira apuntando 
    // al siguiente y aumentado el contador
    while (aux != nullptr && currentPos < posicion) {
        aux = aux->next;
        currentPos++;
    }
    
    if (aux == nullptr) {// en caso de que el nodo este  vacio
        cout << "Error: La posicion " << posicion << " esta fuera de los limites de la lista." << endl;
    } else {// sino muestra la poscion y  los datos
        cout << "El valor en la posicion " << posicion << " es " << aux->dato << "." << endl;
    }
}

// para mostrar un valor
void mostrar(const linkedList& list) {
    if (is_empty(list)) {
        cout << "La lista esta vacia." << endl;
        return;
    }
    // va iterando sobre la lista y mosntrando el valor hasta que el nodo apunte a null
    cout << "Contenido de la lista: ";
    Nodo* aux = list.front;
    while (aux != nullptr) {
        cout << aux->dato << " -> ";
        aux = aux->next;
    }
    cout << endl;
}

void eliminar(linkedList& list) {
    if (is_empty(list)) {
        cout << "La lista esta vacia. No hay valores para eliminar." << endl;
        return;
    }
    // pide la posicion al usuario
    int posicion;
    cout << "Ingresa la posicion para eliminar: ";
    if (!(cin >> posicion)) {
        cout << "Error: Entrada no valida. Por favor, ingresa un numero entero." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
        // la poscion no puede ser menor que 0
    if (posicion < 0) {
        cout << "Error: La posicion " << posicion << " no es valida." << endl;
        return;
    }
    // en caso de ser 0 la posicion seria la primera por lo que
    if (posicion == 0) {
        Nodo* temporal = list.front; // creamos un temoral
        list.front = list.front->next;// hacemos que la cabeza de nuestro nodo apunte al siguiente nodo en la cabeza del nodo.
        cout << "Eliminado el valor " << temporal->dato << " en la posición 0." << endl;
        delete temporal; // eliminamos el nodo
        return;
    }
    //creamos un nodo actual y una variable para llevar la posicion en la que nos encontramsos.
    Nodo* actual = list.front;
    int posicionActual = 0;
    // encuentra la posicion que queremos 
    while (actual != nullptr && posicionActual < posicion - 1) {
        actual = actual->next;
        posicionActual++;
    }
// si el nodo esta vacio o el proximo esta vacio 
    if (actual == nullptr || actual->next == nullptr) {
        cout << "Error: La posicion " << posicion << " esta fuera de los limites de la lista." << endl;
        return;
    }
// creamos un temporal
    Nodo* temporal = actual->next;
    actual->next = temporal->next;// hacemos que el proximo del actual apunte al proximo de temporal
    cout << "Eliminado el valor " << temporal->dato << " en la posicion " << posicion << "." << endl;
    delete temporal; // borramos el nodo auxiliar
}

} // Fin del namespace ListaEnlazada


int main() {
    ListaEnlazada::linkedList list; // utilizamos el namespace creado
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