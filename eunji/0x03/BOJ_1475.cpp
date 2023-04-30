#include <iostream>
using namespace std;


int main(void){
    int N;
    cin >> N;
    int counter[10] = {};
    // int target;
    while (N > 0){
        int temp = N % 10;
        counter[temp] ++;
        N /= 10;
    }
    int sixnine = counter[9] + counter[6];
    int sum;
    if (sixnine % 2 > 0) sum = sixnine / 2 + 1;
    else sum = sixnine / 2;

    int answer = 0;
    for (int i=0; i<10; i++){
        if ((counter[i] > answer) && (i != 9) && (i != 6)) answer = counter[i];
        // cout << counter[i];
    }
    // cout << sum << answer;
    cout << max(sum, answer);

}