#include<stdio.h>

int main() {
    int N, K, check[5002] = {0, }, cur;
    scanf("%d %d", &N, &K);
    cur = K;
    printf("<%d", cur);
    check[cur] = 1;

    for (int i=0;i<N-1;i++){
        for (int j=0;j<K;j++){
            while(1) {
                cur++;
                if(cur > N) cur = 1;
                if(check[cur] == 0) break; //방문 안했으면 break
            }
        }
        printf(", %d", cur);
        check[cur] = 1;
    }
    printf(">");


    return 0;
}
