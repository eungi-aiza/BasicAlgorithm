#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int N = atoi(argv[1]);
    // YOUR CODE HERE
    for(int j=0; j<N; j++){
        for(int i=N-j-1; i>0; i--){
            printf(" ");
        }
        if(j==(N-1)|j==0){
            for(int i=1; i<=2*j+1; i++){
                printf("*");
            }
        }
        else {
            printf("*");
            for(int i=1; i<=2*j-1; i++){
                printf(" ");
            }
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
