#include <iostream>
using namespace std;

// Queue definition

class Queue {
    static const int MAX_SIZE = 100;
public:
    Queue() : front(0), rear(-1), size(0) {}
    int data[MAX_SIZE];
    int front;
    int rear;
    int size;


    void push(int data);
    void pop();
    int getFront();
    int getBack();
    bool empty();
    int getSize();
};

void Queue::push(int data) {
    if (size == MAX_SIZE) {
        cout << "Queue is full!" << endl;
        return;
    }
    
    rear = (rear + 1) % MAX_SIZE;
    this->data[rear] = data;
    size++;
}

void Queue::pop() {
    if (empty()) {
        cout << "Queue is empty!" << endl;
        return;
    }
    
    front = (front + 1) % MAX_SIZE;
    size--;
}

int Queue::getFront() {
    if (empty()) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    return data[front];
}

int Queue::getBack() {
    if (empty()) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    return data[rear];
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
