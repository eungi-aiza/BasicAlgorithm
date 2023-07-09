#include <iostream>
#include <deque>
using namespace std;


int main(void){
    string paren;
    cin >> paren;
    int ans, flag;
    ans = 0;
    flag = 0;
    deque<char> D;
    for (auto c : paren){
        if (c == '('){
            ans ++;
            D.push_back(c);
            flag = 1;
        }
        else if (c == ')' && flag == 1){
            ans --;
            if (D.size() != 1){        
                ans += D.size()-1;
            }
            flag = 0;
            D.pop_back();
        }
        else if (c == ')' and flag == 0){
            D.pop_back();
        }
    }
    cout << ans;
}
