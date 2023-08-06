#include <iostream>
#include <string>
#include <deque>
using namespace std;

class Solution {
public:
    int palindrome(deque<char>& D) {
        while (!D.empty()) {
            if (D.front() == D.back()) {
                D.pop_back();
                if (!D.empty()) D.pop_front(); // Check if not empty before popping again
            } else return 0;
        }
        return 1;
    }

    string longestPalindrome(string s) {
        int length = s.size();
        int w = s.size();
        string dummy;
        while (w) {
            for (int i = 0; i < length - w + 1; i++) { // Change <= to <
                string sub = s.substr(i, w);
                deque<char> D;
                for (auto i : sub) {
                    D.push_back(i);
                }
                if (palindrome(D)) return sub;
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
    cout << sol.longestPalindrome(s1) << endl;
    cout << sol.longestPalindrome(s2) << endl;
}