#include <iostream>

using namespace std;

int main(){
    //  hora =
    for(int x = 1; x <= 12; x++){
        for (int i = 1; i <= 60; i++){
            int propiedad = x*x + i*i;
            if( propiedad == x*100+i){
                cout<< x <<":"<< i << endl;
            }
        }
    }
}