#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

double leerNumero(const string& mensaje) {
    double num;
    while (true) {
        cout << mensaje;
        cin >> num;

        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada no valida. Intenta de nuevo." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return num;
        }
    }
}

int main() {
    bool repetir = true;

    // Lambda para calcular discriminante
    auto discriminante = [](double h, double k, double l) {
        return (k * k) - (4 * h * l);
    };

    while(repetir){
        // Leer coeficientes dentro del bucle
        double a = leerNumero("Ingresa a: ");
        double b = leerNumero("Ingresa b: ");
        double c = leerNumero("Ingresa c: ");

        if(a == 0){
            cout << "No se puede resolver, a no puede ser 0." << endl;
        } else {
            double D = discriminante(a, b, c);

            if(D > 0){
                double sol1 = (-b + sqrt(D)) / (2 * a);
                double sol2 = (-b - sqrt(D)) / (2 * a);
                cout << "Raices reales distintas:" << endl;
                cout << "x1 = " << sol1 << "\nx2 = " << sol2 << endl;
            }
            else if(D == 0){
                cout << "Raiz unica: x = " << (-b / (2 * a)) << endl;
            }
            else { // D < 0
                double parte_real = -b / (2*a);
                double parte_imaginaria = sqrt(-D) / (2*a);
                cout << "Raices imaginarias:" << endl;
                cout <<  parte_real << " +/- " << parte_imaginaria << "i" << endl;
                
        }

        // Preguntar al usuario si quiere repetir
        char opcion;
        cout << "Deseas resolver otra ecuacion? (s/n): ";
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if(opcion != 's' && opcion != 'S'){
            repetir = false;
        }

        cout << "--------------------------" << endl;
    }

    }
    return 0;
}

