#include <iostream>

using namespace std;

int main() {
    for (int n = 100; n < 1000; n++) {
        int numero_comp = n; 
        int num = 0; 
        int temp = n;

        while (temp > 0) {
            int dig = temp % 10; 
            num += dig * dig * dig; 
            temp /= 10; 
        }

        
        if (numero_comp == num) {
            cout << numero_comp << " es un cubo narcisista" << endl;
        }
    }

    return 0; 
}