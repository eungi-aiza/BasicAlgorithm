#include <iostream>

const int MAX_SIZE = 1024;

class Queue {
private:
    int data[MAX_SIZE];
    int frontIdx;
    int rearIdx;
    int count;

public:
    Queue() : frontIdx(0), rearIdx(-1), count(0) {}

    bool empty() const {
        return count == 0;
    }

    bool full() const {
        return count == MAX_SIZE;
    }

    void push(int val) {
        if (full()) {
            std::cout << "Error: Queue is full" << std::endl;
            return;
        }
        rearIdx = (rearIdx + 1) % MAX_SIZE;
        data[rearIdx] = val;
        count++;
    }

    int front() const {
        if (empty()) {
            std::cout << "Error: Queue is empty" << std::endl;
            return -1; // Returning -1 in case of error as in your C implementation
        }
        return data[frontIdx];
    }

    void pop() {
        if (empty()) {
            std::cout << "Error: Queue is empty" << std::endl;
            return;
        }
        frontIdx = (frontIdx + 1) % MAX_SIZE;
        count--;
    }

    size_t size() const {
        return count;
    }
};

int main() {
    Queue queue;

    for (int i = 1; i <= 10; i++) {
        queue.push(i);
    }

    while (!queue.empty()) {
        std::cout << queue.front() << " ";
        queue.pop();
    }
    std::cout << std::endl;

    return 0;
}
