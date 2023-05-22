#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(void) {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
    
    queue<int> q;

    int N, data;
    string command;
    cin >> N;

    for (int i=0;i<N;i++){
        cin >> command;

        if(command == "push"){
            cin >> data;
            q.push(data);
        }
        else if (command == "pop"){
            if (q.size()!=0){
                cout << q.front() << "\n";
                q.pop();
            }
            else{
                cout << -1 << "\n";
            }
            }
        else if (command == "size"){
            cout << q.size() << "\n";
        }
        else if (command == "empty"){
            cout << q.empty() << "\n";
            }
        else if (command == "front"){
            if (q.size() == 0) cout << -1 << "\n";
            else cout << q.front() << "\n";
            
        }
        else if (command == "back"){
            if (q.size() == 0) cout << -1 << "\n";
            else cout << q.back() << "\n";
        }
        }

    return 0;
}

//endl -> \n으로 바꾸니까 time out 발생 안함