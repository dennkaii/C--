#include <iostream>
#include <limits>
using namespace std;

struct Nodo {
    int dato;
    Nodo* izq;
    Nodo* der;
    Nodo(int valor) : dato(valor), izq(nullptr), der(nullptr) {}
};

// Crear un nuevo nodo
Nodo* crearNodo(int valor) {
    return new Nodo(valor);
}

// Insertar un valor
Nodo* insertar(Nodo* raiz, int valor) {
    if (raiz == nullptr) { //el nodo se inserte en la posicion correspondiente. Si el arbol esta vacio, se coloca al inicio. 
        cout << "Insertando " << valor << " en el arbol." << endl;
        return crearNodo(valor);
    }

    if (valor < raiz->dato) { //si el valor a insertar es menor
        raiz->izq = insertar(raiz->izq, valor); //la fucnion se corre recursivamente del lado izquierdo
    }
    else if (valor > raiz->dato) { //si el valor es mayor
        raiz->der = insertar(raiz->der, valor); //la fucnion se corre recursivamente del lado derecho
    }
    else { // valor duplicado
        cout << "El valor " << valor << " ya existe en el arbol. No se insertara." << endl;
    }
    return raiz;
}

// Buscar un valor
void buscar(Nodo* raiz) {
    if (raiz == nullptr) {
        cout << "El arbol esta vacio." << endl;
        return;
    }

    int valor;
    cout << "Ingresa el valor a buscar: ";
    if (!(cin >> valor)) {
        cout << "Error: Entrada no valida." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    Nodo* aux = raiz;
    while (aux != nullptr) { //mientras el puntero auxiliar no sea null
        if (valor == aux->dato) {
            cout << "El valor " << valor << " fue encontrado en el arbol." << endl;
            return;
        }
        else if (valor < aux->dato) { //si el valor a buscar es menor al valor en el que se encuentra el puntero, seguira recorriendo el arbol hacia la izquierda
            aux = aux->izq;
        }
        else { //si el valor a buscar es mayor al valor en el que se encuentra el puntero, seguira recorriendo el arbol hacia la derecha
            aux = aux->der;
        }
    }
    // si no se encuentra el valor incresado dentro del arbol
    cout << "El valor " << valor << " no se encuentra en el arbol." << endl;
}

// Encontrar el minimo de un subarbol
Nodo* minimo(Nodo* raiz) {
    while (raiz && raiz->izq != nullptr) //mientras exista una raiz valida y su hijo izquierdo no sea null
        raiz = raiz->izq; //se recorrera el arbol hasta encontrar el nodo menor
    return raiz;
}

// Eliminar un nodo
Nodo* eliminar(Nodo* raiz, int valor) {
    if (raiz == nullptr) {
        cout << "El arbol esta vacio. No hay valores para eliminar." << endl;
        return nullptr;
    }

    if (valor < raiz->dato) { //si el valor a buscar es menor que el dato
        raiz->izq = eliminar(raiz->izq, valor); //la funcion se corre recursivamente por el lado izquierdo hasta encontrar el dato deseado
    }

    else if (valor > raiz->dato) { //la funcion se corre recursivamente por el lado derecho hasta encontrar el dato deseado
        raiz->der = eliminar(raiz->der, valor);
    }

    else { //cuando se encuentra el dato que se quiere eliminar

        if (!raiz->izq && !raiz->der) { // sin hijos
            delete raiz;
            return nullptr;
        }
        else if (!raiz->izq) { // un hijo derecho
            Nodo* aux = raiz->der;
            delete raiz;
            return aux;
        }
        else if (!raiz->der) { // un hijo izquierdo
            Nodo* aux = raiz->izq;
            delete raiz;
            return aux;
        }
        else { // dos hijos
            Nodo* aux = minimo(raiz->der); //buscamos el dato a reemplazar el valor que se va a eliminar
            raiz->dato = aux->dato; //copiamos ese dato 
            raiz->der = eliminar(raiz->der, aux->dato); //eliminamos el dato duplicado
        }
    }
    return raiz;
}

// Recorrido inorden
void inOrden(Nodo* raiz) {
    if (raiz != nullptr) {
        inOrden(raiz->izq); //recorremos el arbol por la izquierda con la funcion recursiva
        cout << raiz->dato << " "; //mostramos la raiz
        inOrden(raiz->der); //recorremos el arbol por la derecha con la funcion recursiva
    }
}

// Mostrar arbol graficamente
void mostrar(Nodo* raiz, int espacio = 0) {
    if (!raiz) return;
    else {
        mostrar(raiz->der, espacio + 1); //mostramos primero el sub-arbol derecho, ya que el arbol se va a girar 90 grados contrario al reloj
        for (int i = 0; i < espacio; i++) {//para dejar espacios entre los nodos
            cout << "   ";
        }
        cout << raiz->dato << endl; //imprime la raiz
        mostrar(raiz->izq, espacio + 1); //mostramos el sub-arbol izquierdo
    }
}

int main() {
    Nodo* raiz = nullptr;
    int opcion;

    while (true) {
        cout << "\n--- Arbol Binario ---\n";
        cout << "1. Insertar nodo\n";
        cout << "2. Buscar nodo\n";
        cout << "3. Eliminar nodo\n";
        cout << "4. Mostrar arbol\n";
        cout << "5. Recorrido InOrden\n";
        cout << "6. Salir\n";
        cout << "Opcion: ";

        if (!(cin >> opcion)) {
            cout << "Error: Entrada no valida." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (opcion) {
        case 1: {
            int valor;
            cout << "Ingresa el valor a insertar: ";
            if (cin >> valor) {
                raiz = insertar(raiz, valor);
            }
            else {
                cout << "Error: Entrada no valida." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            break;
        }
        case 2:
            buscar(raiz);
            break;
        case 3: {

            if (raiz == nullptr) { // validación antes de pedir valor
                cout << "El arbol esta vacio. No hay valores para eliminar." << endl;
                break;
            }

            int valor;
            cout << "Ingresa el valor a eliminar: ";
            if (cin >> valor) {
                raiz = eliminar(raiz, valor);
            }
            else {
                cout << "Error: Entrada no valida." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            break;
        }
        case 4:
            if (raiz == nullptr) {
                cout << "El arbol esta vacio. No hay nada que mostrar." << endl;
            }
            else {
                cout << "" << endl;
                mostrar(raiz);
            }
            break;
        case 5:
            if (raiz == nullptr) {
                cout << "El arbol esta vacio. No hay valores para recorrer." << endl;
            }
            else {
                cout << "InOrden: ";
                inOrden(raiz);
                cout << endl;
            }
            break;
        case 6:
            cout << "Saliendo del programa." << endl;
            return 0;
        default:
            cout << "Opcion no valida." << endl;
        }
    }

    return 0;
}