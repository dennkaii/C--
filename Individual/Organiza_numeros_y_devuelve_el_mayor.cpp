/* 
Enunciado: Las flores de salvador
Autor: Edward Perez - 1123238
Fecha: 8/8/2025
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
   int arr[5] =  {5 , 10 ,15 ,20, 6};

   // devuelte el tamaño del array
    int n = sizeof(arr) / sizeof(arr[0]);
    // organiza utilizando la funcion sort
    sort(arr, arr + n);
    cout <<"El numero mas alto es: "<< arr[n-1]<<endl;

    return 0;
}
