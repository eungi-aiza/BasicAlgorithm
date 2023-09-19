#include <iostream>
#include <cmath>
using namespace std;
// #include "main function"

bool isPrime(int n) {
    double sqrt_n = sqrt(n);
    // int rounded_sqrt_n = int(sqrt_n);
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt_n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void print_all_prime(int n1, int n2) {
    for (int i = n1; i <= n2; i++   ) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }
}

int main() {
    int n1;
    int n2;
    cout << "Find prime number within a range:" << endl;
    cout << "--------------------------------------" <<endl;
    cout << "-> The start of the range: ";
    cin >> n1;
    cout << "-> The end of the range: ";
    cin >> n2;

    cout << "The prime numbers between " << n1 << " and " << n2 << " are:" << endl;

    print_all_prime(n1, n2);
    cout << endl;
}