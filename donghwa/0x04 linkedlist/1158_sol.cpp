/* 요세푸스 문제
요세푸스 문제는 다음과 같다.

1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 양의 정수 K(≤ N)가 주어진다. 
이제 순서대로 K번째 사람을 제거한다. 
한 사람이 제거되면 남은 사람들로 이루어진 원을 따라 이 과정을 계속해 나간다. 
이 과정은 N명의 사람이 모두 제거될 때까지 계속된다. 
원에서 사람들이 제거되는 순서를 (N, K)-요세푸스 순열이라고 한다. 
예를 들어 (7, 3)-요세푸스 순열은 <3, 6, 2, 7, 5, 1, 4>이다.

N과 K가 주어지면 (N, K)-요세푸스 순열을 구하는 프로그램을 작성하시오.
- 입력 : 
첫째 줄에 N과 K가 빈 칸을 사이에 두고 순서대로 주어진다. (1 ≤ K ≤ N ≤ 5,000)

- 출력 :
예제와 같이 요세푸스 순열을 출력한다.

ex1. 
- 입력 :
7 3
- 출력 :
<3, 6, 2, 7, 5, 1, 4>
*/
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n;
	int k;
	cin >> n >> k;

	vector<int> v;


	for (int i = 0; i < n; i++) {
		v.push_back(i+1); // 벡터에 N번까지 추가
	}

	int idx = k - 1; // 0번이 1번이기 때문에 k번은 k-1번

	cout << "<";
	for (int i = 0; i < n; i++) {
		if (i == n - 1) { // i가 끝이면 
			cout << v[idx] << ">"; 
			break;
		}
        
        	// i가 끝이 아닌 경우
		cout << v[idx] << ", ";
		v[idx] = 0; // 이미 담김
		int count = 0; //초기화 


		while (count != k) { // count가 k일때까지 idx를 1씩 늘림  
			idx  = idx + 1; // 해당 인덱스+1 

			if (idx > n - 1) { // n-1보다 크다면 빼주기
				idx = idx - n;
			}

			if (v[idx] != 0) { // 해당 인덱스가 0이 아니라면 1을 더해줌
				count = count + 1; 
			}
		}
	}

}