#include<iostream>
#include<queue>
#include<string>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    queue<int> q;
    int num;

    for (int i=0;i<N;i++){
        string command;
        cin >> command;

        if(command == "push"){
            int data;
            cin >> data;
            q.push(data);
        }
        else if (command == "pop"){
            if (q.size()!=0){
                num = q.front();
                q.pop();
            }
            else{
                num = -1;
            }
            cout << num << endl;
            }
        else if (command == "size"){
            cout << q.size() << endl;
        }
        else if (command == "empty"){
            if (q.size()==0) num = 1;
            else num = 0;
            cout << num << endl;
            }
        else if (command == "front"){
            if(q.size() == 0) num = -1;
            else num = q.front();
            cout << num << endl;
        }
        else if (command == "back"){
            if(q.size() == 0) num = -1;
            else num = q.back();
            cout << num << endl;
        }
        }

    return 0;
}