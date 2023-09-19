#include <iostream>
#include <vector>
using namespace std;

class Queue {
public:
    vector<int> data;
    
    void push(int val) {
        data.push_back(val);
    }
    
    void pop() {
        if (empty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        data.erase(data.begin());
    }
    
    int front() {
        if (empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return data.front();
    }
    
    int back() {
        if (empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return data.back();
    }
    
    bool empty() {
        return data.empty();
    }
    
    int size() {
        return data.size();
    }
};

int main() {
    Queue q;
    
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    
    cout << "Front element: " << q.front() << endl;
    cout << "Rear element: " << q.back() << endl;
    cout << "Queue size: " << q.size() << endl;
    
    q.pop();
    
    cout << "Front element after pop: " << q.front() << endl;
    cout << "Rear element after pop: " << q.back() << endl;
    cout << "Queue size after pop: " << q.size() << endl;
    
    return 0;
}
