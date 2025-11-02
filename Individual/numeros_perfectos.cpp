#include <iostream>

using namespace std;

bool isPerfect(int num) {
    int sum = 0;
    for (int i = 1; i <= num / 2; ++i) {
        if (num % i == 0)
            sum += i;
    }
    return sum == num;
}

int main() {
    for (int n = 1; n <= 9999; ++n) {
        if (isPerfect(n))
            cout << n << endl;
    }
    return 0;
}

