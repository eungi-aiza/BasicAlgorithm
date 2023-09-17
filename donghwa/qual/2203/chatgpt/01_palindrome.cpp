#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool palindrome(const string& s) {
    int left = 0;
    int right = s.length() - 1;
    
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    
    return true;
}

bool substring(const string& s, const string& t) {
    // for (int i = 0; i <= s.length() - t.length(); i++) {
    //     bool found = true;
    //     for (int j = 0; j < t.length(); j++) {
    //         if (s[i + j] != t[j]) {
    //             found = false;
    //             break;
    //         }
    //     }
    //     if (found) {
    //         return true;
    //     }
    // }
    // return false;
    bool found = s.find(t) != string::npos;
    return found;
}

vector<string> max_palindromes(const string& s) {
    vector<string> result;
    
    for (int i = 0; i < s.length(); i++) {
        for (int j = i + 1; j <= s.length(); j++) {
            string sub = s.substr(i, j - i);
            if (palindrome(sub)) {
                bool isMaximal = true;
                for (int k = 0; k < result.size(); k++) {
                    if (substring(result[k], sub)) {
                        isMaximal = false;
                        break;
                    }
                }
                if (isMaximal) {
                    result.push_back(sub);
                }
            }
        }
    }
    
    return result;
}

int main() {
    string s1 = "kabccbadzdefgfeda";
    vector<string> palindromes1 = max_palindromes(s1);
    
    cout << "max palindromes(s1): ";
    for (const string& p : palindromes1) {
        cout << "\"" << p << "\" ";
    }
    cout << endl;

    string s2 = "kabccba dzabccbaza";
    vector<string> palindromes2 = max_palindromes(s2);

    cout << "max palindromes(s2): ";
    for (const string& p : palindromes2) {
        cout << "\"" << p << "\" ";
    }
    cout << endl;

    return 0;
}
