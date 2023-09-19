#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Counting Sort function
void countingSort(vector<int> &arr) {
    int n = arr.size();
    if (n <= 1) return;  // If the array has one or zero elements, it's already sorted.

    // Find maximum value in the input array
    int maxVal = *max_element(arr.begin(), arr.end());

    // Create a count array of size (maxVal+1) and initialize with 0
    vector<int> count(maxVal + 1, 0);

    // Store count of each number
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Update the input array with sorted values
    int index = 0;
    for (int i = 0; i <= maxVal; i++) {
        while (count[i] > 0) {
            arr[index] = i;
            index++;
            count[i]--;
        }
    }
}

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    countingSort(arr);
    
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}