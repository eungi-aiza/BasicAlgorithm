#include <bits/stdc++.h>
#include <string.h>
using namespace std;

bool is_palidrome(string s){
    bool check = true;
    int n = s.size();
    for (int i=0; i<n/2; i++){
        if (s[i] != s[n-1-i]){
            check = false;
        }
    }
    return check;
}

int main(){
    string s;
    cin >> s;
    int max_length=0;
    string max_palidrome = "";
    int len = s.size();
    for (int ws=len; ws>0; ws--){
        for (int i=0; i<=len-ws; i++){
            string tmp = s.substr(i, ws);
            bool check = is_palidrome(tmp);
            if (check){
                cout << tmp << '\n';
                return 0;
            }
        }
    }

}