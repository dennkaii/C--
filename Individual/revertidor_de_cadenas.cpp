#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void revertidor(std::string string){
    std::string  texto = string;
    int longitud = texto.length();
    for(int i = 0; i < longitud/2;i++){
        std::swap(texto[i],texto[longitud-1-i]);
    }
    cout <<"texto invertido: " <<texto<<endl;
};


int main(){

    std::string text ="arroba";
    cout<< "texto normal: " << text <<endl;
    revertidor(text);

    return 0;
}