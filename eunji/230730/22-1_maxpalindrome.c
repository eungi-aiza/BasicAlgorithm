#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// global하게 처음부터 할당해줘야하면 char* temp[20];
// function안에서 매번 다른 크기로 할당해줘야하면 char* temp =  (char*) malloc((20+1) * sizeof(char))
// 원하는 크기보다 더 크게 만들어도 되지만 temp[length-1] = '\0';가 중요

// int* temp[20];
// int* temp =  (int*) malloc((20) * sizeof(int))

int palindrome(char* s) {
    int length = strlen(s);
    char* temp = (char*) malloc((length+1) * sizeof(char)); 
    strcpy(temp, s);
    if (length == 0 || length == 1) return 1;
    char first = temp[0];
    char last = temp[length-1];
    if (first == last){
        temp[length-1] = '\0';
        return palindrome(temp+1);
    }
    else return 0;
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
    for (int i=0; i<length; i++){
        for (int j=i; j<length ;j++){
            int w = j-i+1;
            char* temp = (char*) malloc((w+1) * sizeof(char)); /// 3, 1
            strncpy(temp, s+i, w);
            temp[w] = '\0';
            int test = strlen(temp);
            if (palindrome(temp)==1){
                printf("%d, check %s\n", palindrome(temp), temp); // bc
                (*returnSize) ++;
                result = (char**) realloc(result, (*returnSize+1) * sizeof(char*)); 
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

    char test1[] = "abcb dd";
    char test2[] = "bcb";
    char test3[] = "b d";
    printf("palindrome test1 : %d\t palindrome test2 : %d\n", palindrome(test1), palindrome(test2));
    printf("test2 in test1 ? : %d\t test3 in test1 ? : %d\n", substring(test1, test2), substring(test1, test3));


    // char* s1 = "kabccbadzdefgfeda";
    // char* s2 = "kabccba dzabccbaza";
    // char* s3 = "abba";
    // char* s4 = "";
    // char s1[] = "kabccbadzdefgfeda";
    // char s2[] = "kabccba dzabccbaza";
    // char s3[] = "abba";
    // char s4[] = "";
    // int k = palindrome(s3);
    // printf("%d\n", k);

    // int t = substring(s3, s4);
    // printf("%d\n", t);

    char** result1 = max_palindrome(test1, &size1);
    // char** result2 = max_palindrome(test2, &size2);

    // printf("Result for string 1:\n");
    // for (int i = 0; i < size1; i++) {
    //     printf("%s\n", result1[i]);
    //     free(result1[i]);
    // }
    // printf("Result for string 2:\n");
    // for (int i = 0; i < size2; i++) {
    //     printf("%s\n", result2[i]);
    //     free(result2[i]);
    // }
    // free(result1);
    // free(result2);
    return 0;

}