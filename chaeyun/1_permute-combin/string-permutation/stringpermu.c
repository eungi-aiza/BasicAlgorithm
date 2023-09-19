#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char* x, char* y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void permuteRecur(char* str, int start, int length) {
    if (start == length - 1) {
        printf("%s\n", str);
        return;
    }

    for (int i = start; i < length; i++) {
        swap(&str[start], &str[i]);
        permuteRecur(str, start + 1, length);
        swap(&str[start], &str[i]);
    }
}

void permute(char* str) {
    permuteRecur(str, 0, strlen(str));
}

int main() {
    char str[] = "AABC";
    permute(str);
    return 0;
}


/*
AABC
AACB
ABAC
ABCA
ACBA
ACAB
AABC
AACB
ABAC
ABCA
ACBA
ACAB
BAAC
BACA
BAAC
BACA
BCAA
BCAA
CABA
CAAB
CBAA
CBAA
CABA
CAAB
*/