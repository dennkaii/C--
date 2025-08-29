#include <iostream>
#include <cmath>
using namespace std;

int es_primo(int n) {
    if (n <= 1) return 0; // Números menores o iguales a 1 no son primos
    int copia = n;
    int raiz = sqrt(n);
    for (int x = 2; x <= raiz; x++) {
        if (copia % x == 0) {
            return 0; // Si es divisible, no es primo
        }
    }
    return 1; // Si no hay divisores, es primo
}

int main(){
   int numero;
    cout << "Ingresa un numero: ";
    cin >> numero;
    if (es_primo(numero)) {
        cout << numero << " es primo" << endl;
    } else {
        cout << numero << " no es primo" << endl;
    }
    return 0;
    
}