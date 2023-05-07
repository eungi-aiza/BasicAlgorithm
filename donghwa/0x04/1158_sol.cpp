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