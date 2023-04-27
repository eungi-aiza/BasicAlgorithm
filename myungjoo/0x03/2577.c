#include <stdio.h>

int main(){
    int input;
    int mult = 1;
    for (int i=0; i<3; i++){
        scanf("%d", &input);
        mult *= input;
    }

    int N = sizeof(mult);
 
    int cnt[10] = {};
    int value;
    for (int i=0;mult>0;i++){
        value = mult % 10; //몫
        cnt[value] += 1;
        mult /= 10; //나머지
    }
    
    for(int i=0;i<10;i++)
     printf("%d\n", cnt[i]);


    return 0;
}