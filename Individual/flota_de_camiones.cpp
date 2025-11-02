#include <iostream>

using namespace std;

int main(){
 int max_camiones = 500;
 int contador = 0;
 for (int i=1; i < max_camiones;i++ ){
     int numero  = i * i;
    if(numero > 99 && numero % 100 == i){
       cout<< (i)<< "="<< numero << endl; 
       contador++;
    }
    else if(numero < 100 && numero % 10 == i) {
        cout << i << "=" << numero << endl;
        contador ++;
    }

 }

}