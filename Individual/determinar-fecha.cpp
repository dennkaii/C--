#include <iostream>
using namespace std;
#include <map>

void determinar_mes_dia(int dia, int month ,int year){
    
    if ((year%4 ==0  && year % 100 != 0) || year % 400 ==0 ){
        dia = dia+1;
    };
    month = month-1;
    cout<< "han pasado " << month << " meses y " << dia <<" dias desde 1/1/"<<year<<endl;
}

int main(){

//pruba bisiesto
   determinar_mes_dia(10 ,10 ,2000);
// prueba no bisiesto
    determinar_mes_dia(10,10,2001);
    return 0;
}