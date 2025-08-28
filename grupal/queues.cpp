/*
Enunciado: Crear un programa que de mantenimiento a una cola con prioridad

Autores:
- Edward Perez * 1123238
- Wander Bautista * 1128559
- Henry Torres * 1095100
- Maria G. Florian * 1119634
- Juan A. Reyes *  1126017
- Suri Lara * 1128060

Fecha: 27/08/2025

*/


#include <iostream>
#include <limits>
using namespace std;

struct Nodo {
    int dato;
    int prioridad = 16;
    Nodo* next;
};

Nodo* front = nullptr;

void actualizarPrioridades() {
    Nodo* aux = front;
    int prio = 0; 
    while (aux && prio < 17) {
        aux->prioridad = prio;
        prio++;
        aux = aux->next;
    }
}


void enqueue(int dato, int prioridad) {
    if (prioridad > 16) prioridad = 16;

    Nodo* nuevo = new Nodo{dato, prioridad, nullptr}; // reserva memoria en el heap(memoria libre)

        //Revisa si front esta vacio
    if (!front) {
        front = nuevo;
        actualizarPrioridades();
        return;
    }

    Nodo* aux = front;
    Nodo* prev = nullptr;
    

    // Buscar bloque de nodos con la misma prioridad
    while (aux && aux->prioridad != prioridad) { // mientras aux distinto de null && aux-> prioridad != prioridad busca nodos que no tengan la misma prioridad
        prev = aux;
        aux = aux->next;
    }

    if (aux && aux->prioridad == prioridad) {
        // Insertar al frente del bloque de igual prioridad 
        if (prev) {
            prev->next = nuevo;
        } else {
            front = nuevo;
        }
        nuevo->next = aux;
    } else {
        // No hay bloque de igual prioridad: insertar según prioridad
        aux = front;
        prev = nullptr;
        while (aux && aux->prioridad <= prioridad) {
            prev = aux;
            aux = aux->next;
        }
        if (!prev) {
            // Insertar al frente
            nuevo->next = front;
            front = nuevo;
        } else {
            nuevo->next = prev->next;
            prev->next = nuevo;
        }
    }
    actualizarPrioridades();
}

void dequeue() {
    if (!front) {
        cout << "La cola esta vacia\n";
        return;
    }
    Nodo* temp = front;
    cout << "Elemento eliminado: (" << temp->dato << ")\n";
    front = front->next;
    delete temp;
    actualizarPrioridades();
}

void printQueue() {
    Nodo* aux = front;
    if (!aux) {
        cout << "La cola esta vacia\n";
        return;
    }
    while (aux) {
        cout << "(" << aux->dato << ") -> ";
        aux = aux->next;
    }
    cout << "NULL\n";
}

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    int op;
    do {
        cout << "\n=== COLA CON PRIORIDAD ===\n";
        cout << "1) Insertar (enqueue)\n";
        cout << "2) Eliminar (dequeue)\n";
        cout << "3) Mostrar cola\n";
        cout << "0) Salir\n> ";

        if (!(cin >> op)) { clearInput(); continue; }

        if (op == 1) {
            int x, pr;
            cout << "Valor a insertar: ";
            if (!(cin >> x)) { clearInput(); continue; }
            cout << "Prioridad inicial: ";
            if (!(cin >> pr)) { clearInput(); continue; }
            enqueue(x, pr);
        } else if (op == 2) {
            dequeue();
        } else if (op == 3) {
            printQueue();
        }
    } while (op != 0);

    cout << "Presiona Enter para cerrar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    return 0;
}
