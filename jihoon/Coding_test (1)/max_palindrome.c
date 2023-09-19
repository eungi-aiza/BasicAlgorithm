#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindrome(char s[]) {
    int i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        if (s[i] != s[j]) {
            return 0;
        }
    }
    return 1;
}

int substring(char s[], char t[]) {
    // s is the small one
    // t is the big one
    int M = strlen(s);
    int N = strlen(t);
 
    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++)
            if (t[i + j] != s[j])
                break;
 
        if (j == M)
            return 1;
    }
 
    return 0;
}


int main() {
}