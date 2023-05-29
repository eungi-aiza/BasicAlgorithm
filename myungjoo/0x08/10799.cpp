#include<iostream>
#include<stack>
#include<string.h>
using namespace std;


string s;
int ans = 0;
int main() {
    cin >> s;
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(') st.push(s[i]);
        else{ //')'
            if(s[i-1]=='('){ //레이저인 경우
                st.pop();
                ans += st.size();
            }
            else{ //막대의 끝인 경우
                st.pop();
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}