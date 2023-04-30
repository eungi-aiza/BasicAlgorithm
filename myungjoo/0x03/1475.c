#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    int cnt[10]={0};

    for (int i=0; N>0; i++){
            cnt[N%10]++;
            N /= 10;
            }


    int max=1;
    cnt[6] = (cnt[6] + cnt[9] +1)/2;
    cnt[9] = 0;
    
    for (int i=0;i<10;i++){
        if (cnt[i] > max)
            max = cnt[i];
    }

    printf("%d", max);

    return 0;
    
}