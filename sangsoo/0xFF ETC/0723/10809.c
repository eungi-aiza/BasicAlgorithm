#include <stdio.h>
#include <string.h>

/*
    Upper case : 65 ~ 90
    Lower case : 97(a) ~ 122(z)
    Numbers : 48 ~ 57 ( ??? )
*/

char input[100];
int alphabets[30]; // 97 ~ 122 ; 26개

int main(){
    scanf("%s", input);
    int n = strlen(input);
    int num = 0;
    for(int i = 0; i < 26; i++) alphabets[i] = -1; // -1로 초기화
    for(int i = 0; i < n; i++){
        num = input[i];  // ord("a") = 97
        num -= 97;
        if (alphabets[num] != -1) continue;
        alphabets[num] = i;
    }
    for(int i = 0; i < 26; i++){
        printf("%d ",alphabets[i]);
    }
}