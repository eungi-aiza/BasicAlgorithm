#include <iostream>
using namespace std;
class Node {
public:
    int val;
    Node* next;

    Node(int value) : val(value), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;
    int count;

public:
    Queue() : front(nullptr), rear(nullptr), count(0) {}

    bool empty() const {
        return count == 0;
    }

    void push(int val) {
        Node* newNode = new Node(val);

        if (empty()) {
            front = newNode;
        } else {
            rear->next = newNode;
        }
        rear = newNode;
        count++;
    }

    int getFront() const {
        if (empty()) {
            cout << "Error: Queue is empty" << endl;
            return -1;
        }
        return front->val;
    }

    void pop() {
        if (empty()) {
            cout << "Error: Queue is empty" << endl;
            return;
        }
        front = front->next;
        count--;
    }
};

int main() {
    Queue queue;

    for (int i = 1; i <= 10; i++) {
        queue.push(i);
    }

    while (!queue.empty()) {
        cout << queue.getFront() << " ";
        queue.pop();
    }
    cout << endl;

    return 0;
}
