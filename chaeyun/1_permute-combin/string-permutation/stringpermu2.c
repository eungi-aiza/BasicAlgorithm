#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char* x, char* y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

int compare(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

void permuteRecur(char* str, int start, int length) {
    if (start == length - 1) {
        printf("%s\n", str);
        return;
    }

    for (int i = start; i < length; i++) {
        // Ensure we don't swap the same characters
        if (i != start && str[i] == str[start]) {
            continue;
        }

        swap(&str[start], &str[i]);
        permuteRecur(str, start + 1, length);
        swap(&str[start], &str[i]);

        // Skip characters that are the same to avoid duplicates
        while (i + 1 < length && str[i] == str[i + 1]) {
            i++;
        }
    }
}

void permute(char* str) {
    qsort(str, strlen(str), sizeof(char), compare);  // Sort the string first
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
BAAC
BACA
BCAA
CABA
CAAB
CBAA
*/