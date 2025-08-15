/* 
Enunciado: Hacer un programa c++ que cuente desde 1 hasta 100. fizz-buzz
Autor: Edward Perez - 1123238
Fecha: /8/2025
*/

#include <iostream>

using namespace std;
main() {

    for(int x = 1; x< 101; x++){
         if(x % 5 == 0 && x % 3 == 0){
            cout << "Coca Cola" <<endl;
        }
        else if (x % 3 == 0){
            cout << "CoCa" <<endl;
        }
        else if (x % 5 == 0){
            cout << "cola" << endl;
        }
        else{
            cout << x << endl;
        }
    }
    return 0;
}

