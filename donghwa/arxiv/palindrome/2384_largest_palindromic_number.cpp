#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> cnt(10);
        for (char c: num) {
            cnt[c - '0']++;
        }
        
        string lp, rp; // left and right partition
        for (int i: num) {
            for (int j = 9; j >= 0; j--)  {
                if (cnt[j] > 1 && (j > 0 || lp.size())) {
                    lp += '0' + j;
                    rp += '0' + j;
                    cnt[j] -= 2;
                    break;
                }
            }
        }
        for (int i = 9; i >= 0; i--) {
            if (cnt[i]) {
                lp += '0' + i; break;
            }
        }
        reverse(begin(rp), end(rp));
        return lp + rp;
    }
};
int main() {
    string num1 = "444947137";
    Solution solution;

    string result1 = solution.largestPalindromic(num1);
    cout << "Example 1 Output: " << result1 << endl;  // Output: "7449447"

    string num2 = "00009";
    string result2 = solution.largestPalindromic(num2);
    cout << "Example 2 Output: " << result2 << endl;  // Output: "9"

    return 0;
}
