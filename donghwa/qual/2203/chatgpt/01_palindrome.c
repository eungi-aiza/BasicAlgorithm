#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_palindrome(const char *s) {
    int left = 0;
    int right = strlen(s) - 1;
    
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    
    return true;
}

bool is_substring(const char *s, const char *t) {
    int i, j;
    int slen = strlen(s);
    int tlen = strlen(t);
    
    for (i = 0; i <= slen - tlen; i++) {
        bool found = true;
        for (j = 0; j < tlen; j++) {
            if (s[i + j] != t[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            return true;
        }
    }
    return false;
}

void max_palindromes(const char *s) {
    int i, j, k;
    int len = strlen(s);
    char result[100][100]; // Assuming a maximum of 100 substrings with 100 characters each.
    int result_count = 0;
    
    for (i = 0; i < len; i++) {
        for (j = i + 1; j <= len; j++) {
            char sub[100];
            strncpy(sub, s + i, j - i);
            sub[j - i] = '\0';
            
            if (is_palindrome(sub)) {
                bool is_maximal = true;
                for (k = 0; k < result_count; k++) {
                    if (is_substring(result[k], sub)) {
                        is_maximal = false;
                        break;
                    }
                }
                if (is_maximal) {
                    strcpy(result[result_count], sub);
                    result_count++;
                }
            }
        }
    }
    
    printf("max palindromes(s): ");
    for (i = 0; i < result_count; i++) {
        printf("\"%s\" ", result[i]);
    }
    printf("\n");
}

int main() {
    const char *s1 = "kabccbadzdefgfeda";
    max_palindromes(s1);
    
    const char *s2 = "kabccba dzabccbaza";
    max_palindromes(s2);

    return 0;
}
