#include <iostream>

using namespace std;


int n, t1 = 0, t2 = 1, nextTerm=0;


int main(){

    cout << "ingresa un numero positivo: "; cin>>n;
    cout << "Series" << t1 << " " << t2 << " ";
    nextTerm = t1 + t2;
    while(nextTerm <= n){
        cout << nextTerm << " ";
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t1 + t2;

    }
    return 0;
}
