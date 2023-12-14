
/*
Version 01 : One input, opposite ends
*/
int fn(vector<int>& arr) {
    int left = 0;
    int right = int(arr.size()) - 1;
    int ans = 0;

    while (left < right) {
        // do some logic here with left and right
        if (CONDITION) {
            left++;
        } else {
            right--;
        }
    }

    return ans;
}

/*
two inputs, exhaust both
*/
int fn(vector<int>& arr1, vector<int>& arr2) {
    int i = 0, j = 0, ans = 0;

    while (i < arr1.size() && j < arr2.size()) {
        // do some logic here
        if (CONDITION) {
            i++;
        } else {
            j++;
        }
    }

    while (i < arr1.size()) {
        // do logic
        i++;
    }

    while (j < arr2.size()) {
        // do logic
        j++;
    }

    return ans;
}