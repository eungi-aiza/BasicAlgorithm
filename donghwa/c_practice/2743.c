#include <stdio.h>

int main(){
    int cnt = 0;
    char c;
    while((c = getchar()) != '\n'){
        cnt += 1;
    }
    printf("%d", cnt);

}