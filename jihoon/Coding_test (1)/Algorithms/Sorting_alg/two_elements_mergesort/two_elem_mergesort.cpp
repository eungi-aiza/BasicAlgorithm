#include <iostream>
#include <vector>

using namespace std;

bool compare_pairs(const pair<int, int>& p1, const pair<int, int>& p2) {
    if (p1.second < p2.second) {
        return true;
    } else if (p1.second == p2.second) {
        return p1.first < p2.first;
    } else {
        return false;
    }
}

void merge(vector<pair<int, int>>& v, int first, int mid, int last) {
    int i = first, j = mid + 1, k = 0;
    vector<pair<int, int>> temp(last - first + 1);

    while (i <= mid && j <= last) {
        if (compare_pairs(v[i], v[j])) {
            temp[k++] = v[i++];
        } else {
            temp[k++] = v[j++];
        }
    }
    
    while (i <= mid) {
        temp[k++] = v[i++];
    }
    
    while (j <= last) {
        temp[k++] = v[j++];
    }
    
    for (i = first, k = 0; i <= last; ++i, ++k) {
        v[i] = temp[k];
    }
}

void mergeSortHelper(vector<pair<int, int>>& v, int first, int last) {
    if (first < last) {
        int mid = first + (last - first) / 2;
        mergeSortHelper(v, first, mid);
        mergeSortHelper(v, mid + 1, last);
        merge(v, first, mid, last);
    }
}

void mergeSort(vector<pair<int, int>>& v) {
    mergeSortHelper(v, 0, v.size() - 1);
}

int main() {
    vector<pair<int, int>> a = {{2, 3}, {1, 3}, {1, 2}, {4, 2}, {5, 6}, {3, 6}};
    mergeSort(a);

    for (const auto& p : a) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    return 0;
}