#include <bits/stdc++.h>
using namespace std;
int main(){
    deque<int> dq;
    string s = "[1,2,3]";
    for (int i = 0; i < s.length(); i++){
        if (isdigit(s[i])) {
            // cout << s[i] - '0' << endl; 
            dq.push_back(s[i]-'0'); // to convert to an integer, simply subtract the ASCII value of '0' from it
        }   
    }
    for (int i=0; i<dq.size(); i++){
        cout << dq[i] << endl;
    }
}