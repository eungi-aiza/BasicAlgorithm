#include <iostream>

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Stack class
class Stack {
public:
    // Constructor to create an empty stack
    Stack() : top(nullptr) {}

    // Destructor to free memory when the stack is destroyed
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Function to check if the stack is empty
    bool isEmpty() const {
        return top == nullptr;
    }

    // Function to push an element onto the stack
    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }

    // Function to pop an element from the stack and return it
    int pop() {
        if (isEmpty()) {
            std::cerr << "Stack is empty" << std::endl;
            exit(EXIT_FAILURE);
        }
        int data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    // Function to get the top element of the stack without removing it
    int peek() const {
        if (isEmpty()) {
            std::cerr << "Stack is empty" << std::endl;
            exit(EXIT_FAILURE);
        }
        return top->data;
    }

private:
    Node* top;
};

int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Top: " << stack.peek() << std::endl;

    stack.pop();
    std::cout << "Top after pop: " << stack.peek() << std::endl;

    return 0;
}
