/*
Enunciado: Crear el juego masterMind en beginners escrito en C++

Autores:
- Edward Perez * 1123238
- Wander Bautista * 1128559
- Henry Torres * 10951
- Maria G. Florian * 1119634
- Juan A. Reyes *  1126017

Fecha: 11/08/2025

*/
using namespace std;

#include <algorithm> // find
#include <cstdlib>   // rand, srand
#include <ctime>     // time
#include <iostream>
#include <limits>    // numeric_limits
#include <windows.h> // Sleep

using namespace std;

int main() {
    srand(time(0));// Genera una semilla que sera utlizada por rand() utilizando la hora actual asegurando asi que casi siempre los numeros sean diferentes.
    int signal = 1; 
    int empieza_juego = 0;
    int respuesta_usuario; 

    int lista_inicial[4];
    int valores_usuario[4];
    char lista_pistas[4]; 

    while (signal == 1) {
        for (int i = 0; i < 40; i++) cout << "-"; // genera una fila de 40 "-".
        cout << endl;
        cout << "Bienvenido a Masterminds" << endl;
        cout << "Niveles de dificultad disponibles:" << endl;
        cout << "1.Beginners\n2.Intermediate\n3.Advanced\n4.Salir" << endl;
        cout << "Ingresa el nivel de dificultad: \n";
        cin >> respuesta_usuario;

        switch (respuesta_usuario) {
            case 1:
                cout << "Iniciando juego..." << endl;
                Sleep(2000);
                for (int i = 0; i < 40; i++) cout << "-";
                empieza_juego = 1;
                signal = 0;
                break;
            case 2:
             cout << "To be done" << endl;
                for (int i = 0; i < 40; i++) cout << "-";
                break;

            case 3:
                cout << "To be done" << endl;
                for (int i = 0; i < 40; i++) cout << "-";
                break;
            case 4:
                cout << "Finalizando juego..." << endl;
                for (int i = 0; i < 40; i++) cout << "-";
                signal = 0;
                break;

            default:
                cout << "Ingresa un valor valido" << endl;
                for (int i = 0; i < 40; i++) cout << "-";
                cout << endl;
        }
    }

    while (empieza_juego == 1) {
        int min = 1, max = 6;
        for (int i = 0; i < 4; i++) {
            lista_inicial[i] = (rand() % (max - min + 1)) + min;// 
        }

        int intentos = 8;
        while (intentos != 0) {
         fill(begin(valores_usuario), end(valores_usuario), 0); // agrega unos valores por defecto de 0 0 0 0 al array
         fill(begin(lista_pistas), end(lista_pistas), ' ');  // agrega ' ' al array 
            cout << "\nIngresa 4 numeros del 1 al 6 (separados por espacios): ";
            for (int i = 0; i < 4; i++) {
                while (true) {
                    if (cin >> valores_usuario[i]) {
                        if (valores_usuario[i] >= 1 && valores_usuario[i] <= 6) {
                            break;
                        } else {
                            cout << "Numero fuera de rango. Intenta de nuevo: ";
                        }
                    } else {
                        cout << "Entrada invalida. Ingresa un numero entero: ";
                        cin.clear(); // limpia el cin
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');//limpia lo que queda en el buffer hasta llegar a un salto de linea
                    }
                }
            }

            // Generar pistas
            for (int i = 0; i < 4; i++) {
                if (lista_inicial[i] == valores_usuario[i]) {
                    lista_pistas[i] = 'C';
                    // utiliza find para buscar en lista inicial de principio a fin el
                    // valor_usuario[i], end(lista_inicial) devuelve el valor despues del
                    // ultimo, es decir que si el find devuelve un valor diferente si
                    // encontro un valor similar.
                } else if (find(begin(lista_inicial), end(lista_inicial), valores_usuario[i]) != end(lista_inicial)) {
                    lista_pistas[i] = 'F';
                } else {
                    lista_pistas[i] = 'X';
                }
            }

            // Mostrar respuesta del usuario
            cout << "Tu respuesta: ";
            for (int i = 0; i < 4; i++) cout << valores_usuario[i] << " ";
            cout << endl;

            // Mostrar pistas
            cout << "Pistas: ";
            for (int i = 0; i < 4; i++) cout << lista_pistas[i] << " ";
            cout << endl;

            // Comprobar si ganó
            bool gano = true;
            for (int i = 0; i < 4; i++) {
                if (lista_pistas[i] != 'C') {
                    gano = false;
                    break;
                }
            }

            if (gano) {
                cout << "Felicidades! Adivinaste el codigo secreto." << endl;
                cout << "Puntuacion: " << intentos << endl;
                empieza_juego = 0;
                break;
            }

            intentos--;
            cout << "Intentos restantes: " << intentos << endl;

            if (intentos == 0) {
                cout << "Se acabaron los intentos. El codigo era: ";
                for (int i = 0; i < 4; i++) cout << lista_inicial[i] << " ";
                cout << endl;
                empieza_juego = 0;
            }
        }
    }

    return 0;
}
