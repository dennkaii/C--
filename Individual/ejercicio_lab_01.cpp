/* 
Enunciado: Las flores de salvador
Autor: Edward Perez - 1123238
Fecha: 10/8/2025
*/

#include <iostream>
#include <list>

using namespace std;

int main()   reros
    int floreros = 100;
    // lista llamada results
    list<int> results;

    // empezando desde 0 hasta 94, para que asi quede almenos una fila de 6
    for (int i = 0; i <= floreros - 6 ; i++){
        int x = floreros - i;// floreros despues de la primera venta
        if( x % 6 == 0){ // checqueamos que sea divisible por 6 para que queden 6 filas iguales
            int z = x - 8; // restamos los 8 que se vendieron despues
            if (z > 0 && z % 11 == 0){ // chequeamos que z sea mayor que 0 sea divisible por 11 para que queden 11 filas igueales
                results.push_back(z); // agregamos z a una lista llamada resultado
            } 
        }
        
    }
    
    cout << "Posibles cantidades de floreros que tiene Salvador para vender: ";
    for (int val : results) cout << val << " "; // interamos sobre la lista para mostrar los valores asignados.
    cout << endl;
    return 0;
}
