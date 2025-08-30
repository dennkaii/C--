#include <iostream>
#include <cmath>
using namespace std;

struct Nodo {
    int dato;
    Nodo* next;
    Nodo* prev;
};

Nodo* front = nullptr;
Nodo* back = nullptr;

// Insertar al final
void at_back(int dato) {
    Nodo* nuevo = new Nodo{dato, nullptr, back};
    if (back != nullptr) back->next = nuevo;
    else front = nuevo;
    back = nuevo;
}

// Verificar si un número es primo
bool es_primo(int n) {
    if (n <= 1) return false;
    int raiz = sqrt(n);
    for (int i = 2; i <= raiz; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Imprimir lista
void imprimir() {
    Nodo* actual = front;
    while (actual != nullptr) {
        cout << actual->dato << " ";
        actual = actual->next;
    }
    cout << endl;
}

int main() {
    cout << "Ingresa la cantidad de primos que quieres generar: ";
    int X;
    cin >> X;

    int num = 2;
    int contador = 0;

    while (contador < X) {
        if (es_primo(num)) {
            at_back(num);
            contador++;
        }
        num++;
    }

    cout << "Los primeros " << X << " primos son: ";
    imprimir();

    return 0;
}
