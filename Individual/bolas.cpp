#include <iostream>

int main() {
    int totalBolas = 10000;
    long long suma = 0; // Usamos long long para evitar overflow
    int capas = 0;

    // Calculamos la suma de cuadrados hasta que exceda 10,000
    for (int n = 1; suma <= totalBolas; n++) {
        suma += n * n;
        if (suma <= totalBolas) {
            capas = n;
        }
    }

    // bolas sobrantes
    int bolasSobrantes = totalBolas - suma + capas * capas;

    std::cout << "Numero maximo de capas: " << capas << std::endl;
    std::cout << "Bolas sobrantes: " << bolasSobrantes << std::endl;

    return 0;
}