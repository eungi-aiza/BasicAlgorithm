# include "queue_with_linked_list.h"
#include <iostream>
using namespace std;

int main() {
    Queue q = Queue();
    cout << "what is going on" << endl;
    q.push(1);
    cout << "after push 1" << endl;
    q.push(2);
    cout << "after push" << endl;
    cout << q.front() << endl;
    cout << q.back() << endl;
    cout << q.size() << endl;
    cout << q.empty() << endl;
    q.pop();
    q.pop();
    q.pop();
    cout << q.size() << endl;
    cout << q.empty() << endl;
    q.pop();
    q.push(3);
    cout << q.empty() << endl;
    cout << q.front() << endl;
}