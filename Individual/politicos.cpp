#include <iostream>

using namespace std;

#include <iostream>
using namespace std;
// s = senador, c = congresista, i = invitado;

// prueba todas las combinaciones posibles
int main() {
    for (int s = 0; s <= 100; s++) {
        for (int c = 0; c <= 100 - s; c++) {
            int i = 100 - s - c;
            int total = 75 * s + 99 * c + 40 * i;
            if (total == 7869) {
                cout << "Senadores: " << s << endl;
                cout << "Congresistas: " << c << endl;
                cout << "Invitados: " << i << endl;
                return 0;
            }
        }
    }
    cout << "No se encontró solución." << endl;
}

