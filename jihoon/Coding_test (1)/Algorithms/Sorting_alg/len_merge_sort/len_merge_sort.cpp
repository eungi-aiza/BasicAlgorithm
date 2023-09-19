#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> slicing(const vector<string>& arr, int X, int Y)
{
    auto start = arr.begin() + X;
    auto end = arr.begin() + Y;
    return vector<string>(start, end);
}

void merge(vector<string>& v, int first, int mid, int last){
    int k = first;
    vector<string> sub1 = slicing(v, first, mid + 1); 
    vector<string> sub2 = slicing(v, mid+1, last+1);
    int i = 0 ; int j = 0;
    while (i < sub1.size() && j < sub2.size()){
        if (sub1[i].length() >= sub2[j].length()){ // 부등호 방향 < asc > desc
            v[k] = sub1[i];
            i = i + 1;
        }
        else{
            v[k] = sub2[j];
            j = j + 1;
        }
        k = k + 1;
    }
    if (i < sub1.size()){
        for (i ; i < sub1.size() ; i++){
            v[k] = sub1[i];
            k = k + 1;
        }
    }
    if (j < sub2.size()){
        for (j ; j < sub2.size() ; j++){
            v[k] = sub2[j];
            k = k + 1;
        }
    }
    return;
}

void mergeSortHelp(vector<string>& v, int first, int last){
    if (first == last)
        return ;
    else{
        int mid = first + (last-first) / 2;
        mergeSortHelp(v, first, mid);
        mergeSortHelp(v, mid+1, last);
        merge(v, first, mid, last);
    }
}

void mergeSort(vector<string> &v){
    mergeSortHelp(v, 0, v.size()-1);
}

int main(){
    vector<string> a = {"apple", "banana", "kiwi", "grapes", "orange", "strawberry"};
    vector<string> b = {"peach", "plum", "mango", "cherry", "pineapple", "blueberry"};
    mergeSort(a);
    mergeSort(b);
    for(const auto &e : a){
        cout << e << " ";
    }
    cout << endl;
    for(const auto &e : b){
        cout << e << " ";
    }
    cout << endl;

    return 0;
}