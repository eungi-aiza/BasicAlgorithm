#include <iostream>
#include <string>

using namespace std;

bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    if (num <= 3) {
        return true;
    }
    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }
    int i = 5;
    while (i * i <= num) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
        i += 6;
    }
    return true;
}

bool is_palindrome(int num) {
    string str = to_string(num);
    int len = str.length();
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

int primePalindrome(int n) {
    while (true) {
        if (n == 1) {
            n = 2;
        }
        if (is_palindrome(n) && is_prime(n)) {
            return n;
        }
        n++;
    }
}

int main() {
    int n1 = 6;
    cout << "Example 1 Output: " << primePalindrome(n1) << endl; // Output: 7

    int n2 = 8;
    cout << "Example 2 Output: " << primePalindrome(n2) << endl; // Output: 11

    int n3 = 13;
    cout << "Example 3 Output: " << primePalindrome(n3) << endl; // Output: 101

    return 0;
}
