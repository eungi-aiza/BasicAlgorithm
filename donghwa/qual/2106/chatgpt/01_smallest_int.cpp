#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int segregate(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    return n + 1;
}

int findSmallestPositive(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
        return 1;
    }
    
    int shift = segregate(nums);
    vector<int> positive_nums(nums.begin() + shift, nums.end());

    return segregate(positive_nums);
}

int main() {
    // Example 1
    vector<int> arr1 = {4, 7, -1, 1, 2};
    cout << "Example 1: " << findSmallestPositive(arr1) << endl;

    // Example 2
    vector<int> arr2 = {100, 101, 102};
    cout << "Example 2: " << findSmallestPositive(arr2) << endl;

    // Example 3
    vector<int> arr3 = {3, 2, 1, 0, -1};
    cout << "Example 3: " << findSmallestPositive(arr3) << endl;

    return 0;
}
