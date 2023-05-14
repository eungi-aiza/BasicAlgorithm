#include<iostream>
#include<queue>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
	cin.tie(0);
    
    int N;
    queue<int> card;

    cin >> N;

    for (int i=1;i<=N;i++){
        card.push(i); //위 123456 밑
    }

    while (card.size()>1) {
        card.pop(); //1 2 3
        card.push(card.front()); //62345 534 4
        card.pop(); // 2345 34 
    }

    cout << card.front();

    return 0;
}
