#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *finding_alphabet(int *alph_list, char s[]) {
    for (int i=0; i < strlen(s); i++) {
        int alph_idx = s[i] - 'a';
        if (alph_list[alph_idx] == -1) {
            alph_list[alph_idx] = i;
        }
    }
    return alph_list;
}

int main() {
    // create alphabet list that contains all -1
    int alph_list[26];
    for (int j=0; j < 26; j++) {
        alph_list[j] = -1;
    }

    char *s = "baekjoon";
    int *ans = finding_alphabet(alph_list, s);
    for (int i = 0; i < 26; i++) {
        printf("%d ", ans[i]);
    }
}