#include <iostream>

using namespace std;

char mover_disco(char desde,char hacia){
cout << "Moviendo desde " << desde << " hacia " << hacia <<endl;
}
void torre_de_hanoi(int n, char ini, char aux, char dest){
    if(n >= 1){
        torre_de_hanoi(n-1, ini, dest, aux);
        mover_disco(ini, dest);
        torre_de_hanoi(n-1, aux, ini, dest);
    }
}

int main(){
    torre_de_hanoi(3, 'A', 'B', 'C');
}

