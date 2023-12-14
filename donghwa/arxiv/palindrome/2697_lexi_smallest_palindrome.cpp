#include <iostream>
#include <string>

using namespace std;

string makePalindrome(string s) {
    int len = s.length();
    string result = s;
    int operations = 0;
    int left = 0, right = len - 1;

    while (left <= right) {
        if (result[left] != result[right]) {
            result[left] = result[right] = min(result[left], result[right]);
            operations++;
        }
        left++;
        right--;
    }

    // If there are still more than one operations needed, repeat the process
    if (operations > 1) {
        return makePalindrome(result);
    }

    return result;
}

int main() {
    string s1 = "egcfe";
    string result1 = makePalindrome(s1);
    cout << "Example 1 Output: " << result1 << endl;  // Output: "efcfe"

    string s2 = "abcd";
    string result2 = makePalindrome(s2);
    cout << "Example 2 Output: " << result2 << endl;  // Output: "abba"

    string s3 = "seven";
    string result3 = makePalindrome(s3);
    cout << "Example 3 Output: " << result3 << endl;  // Output: "neven"

    return 0;
}
