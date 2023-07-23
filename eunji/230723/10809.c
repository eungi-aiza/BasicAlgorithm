#include <stdio.h>
#include <string.h>

#define ALPHABET_COUNT 26

// Function prototypes
void initialize(int* positions);
void savePosition(int* positions, char* S);

void initialize(int* positions) {
    // 각 알파벳의 처음 등장 위치를 -1로 초기화
    for (int i = 0; i < ALPHABET_COUNT; i++) {
        positions[i] = -1;
    }
}

void savePosition(int* positions, char* S) {
    int length = strlen(S);
    // 단어에 포함된 알파벳의 처음 등장 위치를 기록
    for (int i = 0; i < length; i++) {
        int alphabetIndex = S[i] - 'a';
        if (positions[alphabetIndex] == -1) {
            positions[alphabetIndex] = i;
        }
    }
}

int main() {
    int positions[ALPHABET_COUNT];
    initialize(positions);

    char S[101];
    scanf("%s", S);

    savePosition(positions, S);

    // 결과 출력
    for (int i = 0; i < ALPHABET_COUNT; i++) {
        printf("%d ", positions[i]);
    }

    return 0;
}
