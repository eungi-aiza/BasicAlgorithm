#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    while(1) {
    string str;
    stack<char> stack;
    int ck = 0;

    getline(cin, str);

    if (str == ".") break; 

    for (int i=0; i < str.size() ; i++) {
        if (str[i] == '(' || str[i] == '[') { 
            stack.push(str[i]);
        }

        if (str[i] == ')'){
            if (!stack.empty() && stack.top() == '('){ //empty부터 확인하는 순서 critical!! => 반대로 쓰면 segmentation fault 발생
                stack.pop();
            }
            else {
                ck = 1;
                break;
            }
        }
        if (str[i] == ']'){
            if (!stack.empty() && stack.top() == '['){
                stack.pop();
            }
            else {
                ck = 1;
                break;
            }
        }
        }
    
    if (stack.empty() && ck == 0) cout << "yes" << endl;
    else cout << "no" << endl;
    }
    

    return 0;
}
