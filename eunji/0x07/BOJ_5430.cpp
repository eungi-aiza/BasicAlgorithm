#include <iostream>
#include <deque>
#include <sstream>
using namespace std;

void print_deq(deque<int> &D, int flag){
    if (flag == -1) cout << "error" << '\n';
    else if (D.size() == 0) cout << "[]" << '\n';
    else if (flag == 0){
        cout << '[';
        for (int i=0; i<D.size()-1; i++){
            cout << D[i] << ',';
        }
        cout << D[D.size()-1] << ']' << '\n';
    }
    else{
        cout << '[';
        for (int i=D.size()-1; i>0; i--){
            cout << D[i] << ',';
        }
        cout << D[0] << ']' << '\n';

    }
}
void make_deq(deque<int> &D, int size, string ns){
    size_t pos = ns.find(']');
    ns = ns.substr(1, pos-1);
    stringstream ss(ns);
    string temp;
    while (getline(ss, temp, ',')){
        D.push_back(stoi(temp));
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int testcase;
    cin >> testcase;
    for (int i=0; i<testcase; i++){
        int reverse_flag = 0;
        string func; 
        cin >> func;
        int size;   
        cin >> size;
        string ns;
        cin >> ns;
        deque<int> D;
        make_deq(D, size, ns);
        for (auto f: func){
            if (f == 'R') {
                if (reverse_flag == 0) reverse_flag = 1;
                else reverse_flag = 0;
            }
            else if (f == 'D'){
                if (D.size() == 0) {
                    reverse_flag = -1; 
                    break;
                }
                else if (reverse_flag == 0) D.pop_front();
                else if (reverse_flag == 1) D.pop_back();
            }
        }
        print_deq(D, reverse_flag);   
    }
}