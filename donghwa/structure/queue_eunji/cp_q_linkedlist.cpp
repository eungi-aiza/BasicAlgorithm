#include <iostream>
using namespace std;

// Node definition
struct Node {
    Node(int data) : data(data), next(nullptr) {}
    int data;
    Node* next;
};

// Queue definition
class Queue {
public:
    Queue() : front(nullptr), rear(nullptr), size(0) {}
    Node* front;
    Node* rear;
    int size;
    void push(int data);
    void pop();
    int getFront();
    int getBack();
    bool empty();
    int getSize();
};

void Queue::push(int data) {
    Node* newNode = new Node(data);
    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    size++;
}

void Queue::pop() {
    if (empty()) {
        cout << "Queue is empty!" << endl;
        return;
    }
    Node* temp = front;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    delete temp;
    size--;
}

int Queue::getFront() {
    if (empty()) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    return front->data;
}

int Queue::getBack() {
    if (empty()) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    return rear->data;
}

bool Queue::empty() {
    return size == 0;
}

int Queue::getSize() {
    return size;
}

int main() {
    Queue q;
    
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    
    cout << "Front element: " << q.getFront() << endl;
    cout << "Rear element: " << q.getBack() << endl;
    cout << "Queue size: " << q.getSize() << endl;
    
    q.pop();
    
    cout << "Front element after pop: " << q.getFront() << endl;
    cout << "Rear element after pop: " << q.getBack() << endl;
    cout << "Queue size after pop: " << q.getSize() << endl;
    
    return 0;
}
