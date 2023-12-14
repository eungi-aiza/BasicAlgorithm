#include <iostream>
#include <vector>
using namespace std;

vector<int> slicing(vector<int>& arr, int X, int Y)
{
    auto start = arr.begin() + X;
    auto end = arr.begin() + Y;
    vector<int> result(Y - X);
    copy(start, end, result.begin());
    return result;
}

vector<int> slicing2(vector<int>& arr, int X, int Y)  // same with slicing
{
    auto start = arr.begin() + X;
    auto end = arr.begin() + Y;
    return vector<int>(start, end);
}

void merge(vector<int>& v, int first, int mid, int last){
    int k = first;
    vector<int> sub1 = slicing(v, first, mid + 1); 
    vector<int> sub2 = slicing(v, mid+1, last+1);
    int i = 0 ; int j = 0;
    while (i < sub1.size() && j < sub2.size()){
        if (sub1[i] <= sub2[j]){
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
void mergeSortHelp(vector<int>& v, int first, int last){
    if (first == last)
        return ;
    else{
        int mid = first + (last-first) / 2;
        mergeSortHelp(v, first, mid);
        mergeSortHelp(v, mid+1, last);
        merge(v, first, mid, last);
    }
}

void mergeSort(vector<int> &v){
    mergeSortHelp(v, 0, v.size()-1);
}

int main(){
    vector<int> a = {1, 3, 2, 4, 5, 6, 7, 8};
    vector<int> b = {5, 3, 2, 1, 4, 0, 6, 7};
    mergeSort(a);
    mergeSort(b);
    for(auto e : a){
        cout << e << " ";
    }
    cout << endl;
    for(auto e : b){
        cout << e << " ";
    }
    cout << endl;

}