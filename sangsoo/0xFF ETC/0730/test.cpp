#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
string foo(const string& s) {
	return;
}
string bar(const string& s) {
	return;
}
int main(){
	string str1 = "abcde";
	string str2 = "";
	string str3 = "abccdef";
    cout << foo(str1) << endl; // abdec
    cout << foo(str2) << endl; // ""
    cout << foo(str3) << endl; // cacebd
    cout << bar(str1) << endl; // abdec
    cout << bar(str2) << endl; // acebd
    cout << bar(str3) << endl; // acfbed
}