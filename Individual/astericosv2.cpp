#include <iostream>
using namespace std;

int main() {
    int altura;

    cout << "Introduce la altura de la pirámide: ";
    cin >> altura;

    for (int i = 1; i <= altura; i++) {
        // Imprimir espacios
        for (int j = 1; j <= altura - i; j++) {
            cout << " ";
        }

        // Imprimir asteriscos
        for (int k = 1; k <= 2 * i - 1; k++) {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}