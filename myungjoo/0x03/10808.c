#include <stdio.h>
#include <string.h>

int main() {
    char arr[101];
    int i;
    int cnt[26] = {0};

    scanf("%s", arr); //받아서 arr에 넣음

    for (int i=0; i < strlen(arr); i++) {
        //printf("%d", strlen(arr));
        cnt[arr[i] - 'a']++;
    }

    for (int i=0;i<26;i++)
    printf("%d ", cnt[i]);








}