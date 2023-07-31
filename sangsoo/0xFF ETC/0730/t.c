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

int substring(char* s, char* t){ //abcd, bc
    int t_length = strlen(t);
    int s_length = strlen(s);
    if (s_length == 0) return 0;
    char s_f = s[0];
    char t_f = t[0];
    if (s_f != t_f) {
        return substring(s+1, t); // bcd ,bc
    } 
    else {
        for (int i=0; i<t_length; i++){
            if (s[i] != t[i]) { // '\0'
                return substring(s+1, t);
            }
        }
        return 1;
    }
}


// Function to find the maximum palindromes
char** max_palindrome(char* s, int* returnSize) {
    // printf("%d", *returnSize);
    char** result = NULL;
    int length = strlen(s);
    *returnSize = 0;
    for (int i=0; i<length-1; i++){
        for (int j=i+1; j<length ;j++){
            char* temp = (char*)malloc((j - i + 2) * sizeof(char)); 
            strncpy(temp, s + i, j - i + 1);
            temp[j - i] = '\0';
            printf("before i : %d\t j: %d\n", i, j);
            printf("before %s\t size : %d\n", temp, strlen(temp));
            if (palindrome(temp)){
                printf("after i : %d\t j: %d\n", i, j);
                printf("after %s\t size : %d\n", temp, strlen(temp));
                (*returnSize) ++;
                result = (char**)realloc(result, (*returnSize) * sizeof(char*)); 
                result[(*returnSize) - 1] = temp;
            } 
            else{
                free(temp);
            }
        }
    }
    // for (int i=0; i<*returnSize; i++){
    //     for (int j=i; j<*returnSize; j++){
    //         if (substring(result[i], result[j])){
    //             // remove result[j]
    //         }
    //         else if (substring(result[j], result[i]))
    //             // remove result[i]
    //     }
    // }

    return result;
}

int main() {
    int size1, size2;

    char test1[] = "abcbca";
    char** result1 = max_palindrome(test1, &size1);

    return 0;

}