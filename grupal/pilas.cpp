/*
Enunciado: Crear un programa que mantenga un stack(push y pop)

Autores:
- Edward Perez * 1123238
- Wander Bautista * 1128559
- Henry Torres * 1095100
- Maria G. Florian * 1119634
- Juan A. Reyes *  1126017
- Suri Lara * 1128060

Fecha: 26/08/2025

*/

#include <iostream>
#include <limits>
using namespace std;

// ---------- NODO Y ESTRUCTURA DE PILA ----------
struct Nodo {
    int dato;
    Nodo* next;
    Nodo(int d, Nodo* n = nullptr) : dato(d), next(n) {}// metodo constructor
};

struct Pila {
    Nodo* top;
    Pila() : top(nullptr) {}
    ~Pila() { // destructor
        // liberar por si quedó algo en la pila
        while (top) {
            Nodo* aux = top;
            top = top->next;
            delete aux;
        }
    }
};

// ---------- OPERACIONES ----------
void Push(Pila& pila, int dato) {
    pila.top = new Nodo(dato, pila.top);
    cout << "Push OK: " << dato << " agregado.\n";
}

bool Pop(Pila& pila, int& out) {
    if (!pila.top) {
        cout << "Pila vacia.\n";
        return false;
    }
    Nodo* aux = pila.top;
    out = aux->dato;
    pila.top = aux->next;
    delete aux;
    cout << "Pop OK: " << out << " eliminado.\n";
    return true;
}

bool Peek(const Pila& pila, int& out) {
    if (!pila.top) return false;
    out = pila.top->dato;
    return true;
}

void Mostrar(Pila pilaCopia) {
    cout << "[top] ";
    while (pilaCopia.top) {
        cout << pilaCopia.top->dato << (pilaCopia.top->next ? " -> " : " ");//muestra el dato y pregunta si existe un dato siguiente
        pilaCopia.top = pilaCopia.top->next;
    }
    cout << "[bottom]\n";
}

// ---------- UTIL ----------
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// ---------- MENU ----------
int main() { 

    Pila pila;
    int op;

    do {
        cout << "\n=== PILA (STACK) ===\n";
        cout << "1) Push\n";
        cout << "2) Pop\n";
        cout << "3) Peek (Top)\n";
        cout << "4) Mostrar pila\n";
        cout << "0) Salir\n> ";

        if (!(cin >> op)) { clearInput(); continue; }

        if (op == 1) {
            int x; 
            cout << "Valor: ";
            if (!(cin >> x)) { clearInput(); continue; }
            Push(pila, x);
        } else if (op == 2) {
            int out;
            Pop(pila, out);
        } else if (op == 3) {
            int topVal;
            if (Peek(pila, topVal)) cout << "Top = " << topVal << "\n";
            else cout << "Pila vacia.\n";
        } else if (op == 4) {
            Mostrar(pila);
        }
    } while (op != 0);

    cout << "Presiona Enter para cerrar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpiar lo que quede
    cin.get(); // ahora sí espera al Enter
    return 0;
}