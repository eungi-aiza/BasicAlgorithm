#include <stdio.h>
#include <string.h>

int main(){
    char a[1005];
    int i=0;
    scanf("%s", a);
    scanf("%d", &i);
    printf("%c", a[i-1]);
}