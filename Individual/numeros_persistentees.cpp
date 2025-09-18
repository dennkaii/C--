#include <iostream>
using namespace std;

int dividir_numeros(int x) {
    int numero = x;
    int resultado = 1; // Inicializamos en 1 para multiplicar correctamente
    int contador = 0;
do { 
    resultado = 1;
    while (numero > 0) {
        int digit = numero % 10;
        resultado *= digit;
        numero /= 10;
    }
    numero = resultado;
    contador++;
}while( resultado > 9);

    return contador;
}



int main() {
    int max_persistencia = 0;
    int numero_con_mayor_persistencia = 0;

    for (int i = 10; i < 100; i++) {
        int persistencia = dividir_numeros(i);
        if (persistencia > max_persistencia) {
            max_persistencia = persistencia;
            numero_con_mayor_persistencia = i;
        }
    }

    cout << "Numero con mayor persistencia: " << numero_con_mayor_persistencia << endl;
    cout << "Persistencia: " << max_persistencia << endl;
}


