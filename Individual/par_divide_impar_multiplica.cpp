#include <iostream>

using namespace std;

int formula(int n){
    int dato = n,  comparador = 4, contador;
    contador = 0;
    while (dato != comparador){
    if (dato % 2 == 0) {
         dato = dato /2;
         contador++;
    }
    else{
        dato = (dato * 3) + 1;
        contador ++;
    }
     };
     return n;
}



main(){
    int posible_val = 0;
    for(int a = 1; a < 100; a++) {
        int respuesta = formula(a);
        
        if ( respuesta > posible_val ){
            posible_val = respuesta;
        }
        
    }

    cout <<"El numero es " << posible_val << endl;

}