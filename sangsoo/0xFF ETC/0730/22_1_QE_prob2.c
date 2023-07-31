#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int palindrome(char* s) {
    int n = strlen(s);
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1])
            return 0;
    }
    return 1;
}
int substring(char* s, char* t){ // t in s?
    return strstr(s, t) != NULL; // t가 s에 포함되는지 ? t in s? 포함이 되면 NULL 이 아니고 포함이 안되면 NULL;
}


// Function to find the maximum palindromes
char** max_palindrome(char* s, int* returnSize) {
    int n = strlen(s);
    char** result = (char**) malloc(1 * sizeof(char*)); // 뭔가 최댓값 을 표시해야하지 않을까. 문제에서 이건 조건으로 줘야겠다.
    *returnSize = 0;
    for (int w = n; w > 0; w--) { // window 사이즈 줄여가면서...
        for (int i = 0; i <= n - w; i++) { // n-w 까지 가야함...!
            char* substr = (char*) malloc((w+1) * sizeof(char)); // 윈도우 사이즈 만큼 동적할당
            strncpy(substr, s+i, w); // in python substr = s[i:i+w] // same with strncpy(substr, &s[i], w);
            substr[w] = '\0'; // 마지막글자를 '\0'으로 바꿔줘야함..!
            if (palindrome(substr)) {
                int found = 0;
                for (int j = 0; j < *returnSize; j++) {
                    if (substring(result[j], substr)) {
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    result[*returnSize] = substr;
                    (*returnSize)++;
                    result = (char **)realloc(result, (*returnSize+1)*sizeof(char*));
                }
                else free(substr);
            } 
            else free(substr);
        }
    }
    // Reordering step
    char** orderedResult = (char**) malloc(n * sizeof(char*));
    int orderedReturnSize = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            char* substr = (char*) malloc((j - i + 1) * sizeof(char));
            strncpy(substr, &s[i], j - i);
            substr[j - i] = '\0';
            if (palindrome(substr)) {
                int found = 0;
                for (int k = 0; k < *returnSize; k++) {
                    if (strcmp(substr, result[k]) == 0) {
                        found = 1;
                        break;
                    }
                }
                if (found) {
                    orderedResult[orderedReturnSize] = substr;
                    orderedReturnSize++;
                } else {
                    free(substr);
                }
            } else {
                free(substr);
            }
        }
    }

    // Free the original results
    for (int i = 0; i < *returnSize; i++) {
        free(result[i]);
    }
    free(result);

    // Update the result with ordered results
    *returnSize = orderedReturnSize;
    return orderedResult;
}

int main() {
    // char* test1 = "abcba";
    // char* test2 = "bc";
    // char* test3 = "bd";
    char test1[] = "abcba";
    char test2[] = "bc";
    char test3[] = "bd";
    printf("palindrome test1 : %d\t palindrome test2 : %d\n", palindrome(test1), palindrome(test2));
    printf("test2 in test1 ? : %d\t test3 in test1 ? : %d\n", substring(test1, test2), substring(test3, test1));

    int size1, size2;
    char s1[] = "kabccbadzdefgfeda";
    char s2[] = "kabccba dzabccbaza";
    char** result1 = max_palindrome(s1, &size1);
    char** result2 = max_palindrome(s2, &size2);
    printf("Result for string 1:\n");
    for (int i = 0; i < size1; i++) {
        printf("%s\n", result1[i]);
        free(result1[i]);
    }
    printf("Result for string 2:\n");
    for (int i = 0; i < size2; i++) {
        printf("%s\n", result2[i]);
        free(result2[i]);
    }
    free(result1);
    free(result2);
    return 0;
}