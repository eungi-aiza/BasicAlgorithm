#include <iostream>
using namespace std;

int main(void){
    int A; int B; int C;
    cin >> A >> B >> C;
    int target = A*B*C;
    int counter[10] = {};
    while (target > 0){
        int num = target % 10;
        counter[num] ++ ;
        target = target / 10;
    }

    for (int i=0; i<10; i++){
        cout << counter[i] << '\n';
    }
}