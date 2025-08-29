#include <iostream>
#include <iomanip>

using namespace std;


long long fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1 || n == 2) return 1;
    long long f1 = 1, f2 = 1, fn;
    for (int i = 3; i <= n; i++) {
        fn = f1 + f2;
        f1 = f2;
        f2 = fn;
    }
    return fn;
}

int main() {
    const int horas = 24;
    double retrasoTotal = 0.0;

    // Calcular el retraso para cada hora
    for (int hora = 1; hora <= horas; hora++) {
        long long fn = fibonacci(hora);
        double retraso = (double)fn / (1 << hora); // empieza con 1(0000001) "<<" mueve el numero la cantidad de horas eje: 1<< 3 => 2^2 = 4
        retrasoTotal += retraso;
        // Descomenta la siguiente línea para ver el retraso de cada hora
        // cout << "Hora " << hora << ": " << fixed << setprecision(6) << retraso << " minutos\n";
    }

    cout << "Retraso total despues de 24 horas: " << fixed << setprecision(6) << retrasoTotal << " minutos\n";

    return 0;
}