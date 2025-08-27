#include <iostream>
using namespace std;

struct Nodo {
    int dato;//valor actual
    int prioridad;// prioridad
    Nodo *next;// puntero al sigueinte nodo en la lista.
};

Nodo *front = nullptr; // Apunta siempre al primer elemento de la cola 

void actualizarPrioridades() {
    Nodo *aux = front; // aux apunta a front
    int pos = 0;// posicion cero
    while (aux != nullptr) { // mientras el auxilar no sea igual a un puntero vacio(final )
        aux->prioridad = pos; // prioridad = posición en la cola
        pos++;
        aux = aux->next;// avanza al sigueinte nodo
    }
}


void push(int x, int prioridad) {
    Nodo *nuevo = new Nodo(); // reserva memoria para un nodo
    nuevo->dato = x;          // guarda el valor a encolar
    nuevo->prioridad = prioridad; // asigna la prioridad
    nuevo->next = nullptr;    // inicializa el puntero como nuevo

    // Si la cola está vacía o el nuevo va al frente
    if (front == nullptr || prioridad < front->prioridad) {
        nuevo->next = front;
        front = nuevo;
    } else {
        Nodo *aux = front;
        // Encontrar posición correcta
        while (aux->next != nullptr && aux->next->prioridad <= prioridad) {
            aux = aux->next;
        }
        nuevo->next = aux->next;
        aux->next = nuevo;
    }
     actualizarPrioridades();
}

void pop() {
    if (front == nullptr) {
        cout << "La cola está vacía\n";
        return;
    }

    Nodo *temp = front;
    front = front->next;
    delete temp;
     actualizarPrioridades();
}

void printQueue() {
    Nodo *aux = front;
    while (aux != nullptr) {
        cout << "(" << aux->dato << ", prioridad " << aux->prioridad << ") -> ";
        aux = aux->next;
    }
    cout << "NULL\n";
}

int main() {
    push(10, 2);
    push(20, 1);
    push(30, 3);
    push(40, 0);
    push(50, 1);

    cout << "Cola con prioridad:\n";
    printQueue();

    cout << "Pop:\n";
    pop();
    printQueue();

    push(50, 1);
    cout << "Después de insertar 50 con prioridad inicial 1:\n";
    printQueue();

    return 0;
}
