#include <iostream>
using namespace std;

int main() {
    int n = 115;
    int copia = n;  // Copia del número original
    int d = 2;      // Divisor inicial (empezamos con 2, el menor primo)
    int i = 0;      // Contador de exponentes

    while (copia > 1) {
        i = 0;                    // Reinicia el contador de exponentes para cada nuevo divisor
        while (copia % d == 0) {  // Mientras d divida a copia
            copia = copia / d;    // Actualiza copia dividiendo por d
            i++;                  // Incrementa el exponente
        }
        if (i > 0) {              // Solo imprime si d es un factor
            cout << d << "^" << i;
            if (copia > 1) cout << "x"; // Imprime "x" si hay más factores
        }
        d++;                      // Prueba el siguiente número
    }
    cout << endl;                 // Nueva línea al final para mejor formato
    return 0;
}