#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
    int K, num;
    int pos = 0; //이거 안하면 outofbound error 발생
    int stack[100000];

    scanf("%d", &K);
    for (int k=0; k<K; k++){
        scanf("%d", &num);
        
        if (num==0) {
            stack[pos] = 0;
            pos--;
        }
        else {
            stack[pos] = num;
            pos++;
        }
    }

    int sum=0;
    for (int k=0; k<pos; k++){
        sum += stack[k];
    }

    printf("%d", sum);

    return 0; 
}