#include <iostream>
#include <deque>
using namespace std;

string check(string paren){
    deque<char> D;
    for (auto c : paren){
        if (D.empty()){
            D.push_back(c);
        }
        else if (c == ')'){
            if (D.back() == '('){
                D.pop_back();
            }
            else D.push_back(c);
        }
        else D.push_back(c);
    }
    if (D.size() != 0) return "NO\n";
    else return "YES\n";
}


int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int N;
    cin >> N;
    for (int i=0; i<N; i++){
        string paren;
        cin >> paren;
        cout << check(paren);
    }
}