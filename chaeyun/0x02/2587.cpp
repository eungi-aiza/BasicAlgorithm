#include <iostream>
#include <algorithm>
#include <vector> 
#include <string>
using namespace std;

int main()
{
    int sum = 0;
    vector<int> v(5);
    
    for(int i =0; i < v.size(); i++) cin>>v[i];
    sort(v.begin(), v.end());
    
    for (int i = 0; i < v.size(); i++) {
        sum += (int) v.at(i);
    }
    
    cout << sum/ v.size() << endl; 
    cout << v[2];
    return 0;
}
