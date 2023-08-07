#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool ispalindrome(string s) {
        for(int i = 0; i < s.length()/2; i++){
 
            if (s[i] != s[s.length()-i-1]){
                return false;
            }
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        int w = s.length();
        string dummy;
        while (w){
            for(int i = 0; i < n-w+1; i++){
                if (ispalindrome(s.substr(i, w))){ // s[i:i+w];
                    return s.substr(i, w);
                }
            }
            w--;
        }
        return dummy;
    }
};

int main(){
    Solution sol; 
    string s1 = "babab";
    string s2 = "cbbd";
    string s3 = "a";
    cout << sol.longestPalindrome(s1) << endl;
    // cout << sol.longestPalindrome(s2) << endl;
}