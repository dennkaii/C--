/*
Enunciado: Crear el juego masterMind en beginners escrito en C++

Autores:
- Edward Perez * 1123238
- Wander Bautista * 1128559
- Henry Torres * 10951
- Maria G. Florian * 1119634


Fecha: 11/08/2025

*/

#include <algorithm> // find
#include <cstdlib>   // agrega rand() y srand() para generar los numeros
#include <ctime> // agrega time para asegurar que los numeros casi siempre sean aleatorios
#include <iostream> 
#include <vector> // trabajar con vectores
#include <windows.h> // time sleep

using namespace std;

int main() {
  srand(time(0)); // genera la semilla del rand en base a la hora en la que se corre el programa, esto asegura que los numeros se generen de manera aleatoria cada vez que se corre el codigo
  int signal = 1;
  int empieza_juego = 0;
  int respuesta_usuario;

  vector<int> lista_inicial;   // aqui se almacenan los 4 numeros iniciales
  vector<int> valores_usuario; // almacena los valores del usuario en el momento
  vector<char> lista_pistas; //  vector para las pistas

// inicio del programa, con un switch
  while (signal == 1) {
    for (int i = 0; i < 40; i++)// genera una linea de 40 caracteres con -, para que se vea mejor basicamente
      cout << "-";
    cout << endl;
    cout << "Bienvenido a Masterminds" << endl;
    cout << "Elige que nivel quieres jugar:" << endl;
    cout << "1.Beginners" << "\n"
         << "2.Intermediate" << "\n"
         << "3.Advanced" << endl;
    cout << "Ingresa el numero correspondiente al nivel: \nhint: solamente "
            "funciona el primer nivel :)"
         << endl;
    cin >> respuesta_usuario;

    switch (respuesta_usuario) {
    case 1:
      cout << "Iniciando juego..." << endl;
      Sleep(4000);
      for (int i = 0; i < 40; i++)
        cout << "-";
      empieza_juego = 1;
      signal = 0;

      break;

    case 2:
      cout << "Nivel No disponible :)" << endl;
      for (int i = 0; i < 40; i++)
        cout << "-";
      break;

    case 3:
      cout << "Nivel no disponible :)" << endl;
      for (int i = 0; i < 40; i++)
        cout << "-";
      break;

    default:
      cout << "Inavlido, terminando juego" << endl;
      for (int i = 0; i < 40; i++)
        cout << "-";
      cout << endl;
      signal = 0;
      break;
    }
  }

  while (empieza_juego == 1) {

    // generar una lista de 4 numeros aleatoria de numeros de 1 al 6
    int min = 1, max = 6;
      for (int i = 0; i < 4; i++) {
        int numero = (rand() % (max - min + 1)) + min;
        lista_inicial.push_back(numero);
      }

    int intentos = 8; // cantidad de intentos
    while (intentos !=
           0) { // mientras los intentos no lle guen a 0 se puede repetir
      valores_usuario.clear();
      lista_pistas.clear();
      cout << endl;
      cout << "Ingresa un numero del 1 al 6: (separados por espacios)" << endl;
      while (valores_usuario.size() < 4) { // almacena 4 numeros en el vector
        int num;
        while (true) {
          if (cin >> num) {
            if (num >= 1 && num <= 6) {
              valores_usuario.push_back(num);
              break;
            } else {
              cout << "Numero fuera de rango. Intenta de nuevo: ";
            }
          } else {
            cout << "Entrada invalida. Ingresa un numero entero: ";
            cin.clear(); // limpia cin
            cin.ignore(
                numeric_limits<streamsize>::max(), '\n'); // ignora el valor maxmimo que puede tener el timpo
                       // streamsize, el segundo indica el delimitador
          }
        }
      }

      // comparar valores de usuario con lista inicial
      for (size_t i = 0; i < lista_inicial.size() && i < valores_usuario.size();
           ++i) {
        if (lista_inicial[i] == valores_usuario[i]) {
          lista_pistas.push_back('C');
        } // utiliza find para buscar en lista inicial de principio a fin el
          // valor_usuario[i],lista inicial.end() devuelve el valor despues del
          // ultimo, es decir que si el find devuelve un valor diferente si
          // encontro un valor similar.
        else if (find(lista_inicial.begin(), lista_inicial.end(),
                      valores_usuario[i]) != lista_inicial.end()) {
          lista_pistas.push_back('F');
        } else {
          lista_pistas.push_back('X');
        }
      }

      // imprime los valores del usuario
      cout << "Tu respuesta: ";
      for (int i : valores_usuario) {
        cout << i << " ";
      }
      cout << endl;

      // imprime las pistas
      cout << "Pistas: ";
      for (char c : lista_pistas) {
        cout << c << " ";
      }
      cout << endl;

      // Verificar si ganó
      bool gano = true;
      for (char c : lista_pistas) {
        if (c != 'C') {
          gano = false;
          break;
        }
      }

      if (gano) {
        cout << "Felicidades! Adivinaste el codigo secreto." << endl;
        cout << "Puntuacion: " << intentos << endl;
        empieza_juego = 0;
        break; // sale del juego
      }

      intentos--;
      cout << "Intentos restantes: " << intentos << endl;

      if (intentos == 0) {
        cout << "Se acabaron los intentos. El codigo era: ";
        for (int val : lista_inicial)
          cout << val << " ";
        cout << endl;
        empieza_juego = 0;
      }
    }
  }

  return 0;
}