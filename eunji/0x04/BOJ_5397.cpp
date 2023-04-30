#include <iostream>
#include <list>
using namespace std;


int main(void){
  int N;
  cin >> N;
  for (int i=0; i<N; i++){
    string pw;
    cin >> pw;
    list<char> pwl;   
    auto curr = pwl.begin();  
    for (auto c : pw){
      if ((c == '-') && (curr != pwl.begin())){
        curr --;
        curr = pwl.erase(curr);
      }   
      else if ((c == '<') && (curr != pwl.begin())){
        curr --;
      }   
      else if ((c == '>') && (curr != pwl.end())){
        curr ++;
      }    
      else if ((c != '>') && (c != '-') && (c != '<')){
        pwl.insert(curr, c);
      }   
    }
    for (auto c : pwl) cout << c;
    cout << '\n';
  } 
}