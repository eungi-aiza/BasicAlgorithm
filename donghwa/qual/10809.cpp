#include <stdio.h>
#include <string.h>
#define ALPHABET_COUNT 26

void initialize(int * positions){
    for (int i=0; i<ALPHABET_COUNT; i++){
        positions[i] = -1;
    }
};
void savePosition(int* positions, char* S){
    for (int i=strlen(S)-1; i>=0; i--){
        int tmp = S[i] -'a';
        positions[tmp] = i;
    }
};

int main(){
    char S[100];
    scanf("%s", S);

    int pos[ALPHABET_COUNT];
    initialize(pos);
    savePosition(pos, S);
    
    for (int i=0; i<ALPHABET_COUNT; i++){
        printf("%d ", pos[i]);
    } printf("\n");

}
