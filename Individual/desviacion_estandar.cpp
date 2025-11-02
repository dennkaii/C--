#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

int main() {
    int n;
    std::cout << "¿Cuantos numeros aleatorios deseas generar? ";
    std::cin >> n;

    std::vector<double> datos(n);
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Generar números aleatorios entre 0 y 100
    for (int i = 0; i < n; ++i) {
        datos[i] = static_cast<double>(std::rand()) / RAND_MAX * 100;
    }

    // Calcular la media
    double suma = 0.0;
    for (double x : datos) {
        suma += x;
    }
    double media = suma / n;

    // Calcular la desviación estándar
    double suma_cuadrados = 0.0;
    for (double x : datos) {
        suma_cuadrados += (x - media) * (x - media);
    }
    double desviacion = std::sqrt(suma_cuadrados / n); // Poblacional

    // Mostrar resultados
    std::cout << "\nNumeros generados:\n";
    for (double x : datos) {
        std::cout << x << " ";
    }
    std::cout << "\n\nMedia: " << media << std::endl;
    std::cout << "Desviacion estandar: " << desviacion << std::endl;

    return 0;
}