// FAIL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

char s[MAX_LENGTH];
char v[MAX_LENGTH];
int isused[MAX_LENGTH];
char permutations[MAX_LENGTH][MAX_LENGTH];

void str_perm(int cur, char* ss, int length) {
    if (cur == length) {
        strcpy(permutations[cur - 1], ss);
        return;
    }
    for (int i = 0; i < length; i++) {
        if (!isused[i]) {
            ss[cur] = s[i];
            isused[i] = 1;
            str_perm(cur + 1, ss, length);
            isused[i] = 0;
        }
    }
}

int main() {
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0'; // Remove the newline character

    int length = strlen(s);
    str_perm(0, v, length);

    // Use a set-like mechanism to ensure unique permutations
    char unique_permutations[MAX_LENGTH][MAX_LENGTH];
    int unique_count = 0;

    for (int i = 0; i < length; i++) {
        int is_unique = 1;
        for (int j = 0; j < unique_count; j++) {
            if (strcmp(unique_permutations[j], permutations[i]) == 0) {
                is_unique = 0;
                break;
            }
        }
        if (is_unique) {
            strcpy(unique_permutations[unique_count], permutations[i]);
            unique_count++;
        }
    }

    for (int i = 0; i < unique_count; i++) {
        printf("%s\n", unique_permutations[i]);
    }

    return 0;
}
