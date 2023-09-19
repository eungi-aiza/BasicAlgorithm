#include <iostream>

using namespace std;

// Define the structure of a node
template <typename T>
struct Node {
    T data;
    Node<T>* next;
};

// Define the Stack class
template <typename T>
class Stack {
   private:
    Node<T>* top;

   public:
    // Constructor
    Stack() {
        top = nullptr;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Function to push an element onto the stack
    void push(T data) {
        Node<T>* node = new Node<T>;
        node->data = data;
        node->next = top;
        top = node;
        cout << data << " pushed to stack." << endl;
    }

    // Function to pop an element from the stack
    T pop() {
        if (isEmpty()) {
            return -1;
        }
        Node<T>* temp = top;
        top = top->next;
        T popped = temp->data;
        delete temp;
        return popped;
    }

    // Function to get the top element of the stack
    T peek() {
        if (isEmpty()) {
            return -1;
        }
        return top->data;
    }
};

// Example usage
int main() {
    Stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.pop() << " popped from stack." << endl;

    cout << "Top element is " << s.peek() << "." << endl;

    return 0;
}
