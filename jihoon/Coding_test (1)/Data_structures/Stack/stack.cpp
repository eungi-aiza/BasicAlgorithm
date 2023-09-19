#include <iostream>
using namespace std;

template <class T>
class Stack {
private:
    int top;
    int capacity;
    T* stack;

public:
    Stack(int size) {
        top = -1;
        capacity = size;
        stack = new T[size];
    }

    ~Stack() {
        delete[] stack;
    }

    bool is_empty() {
        return top == -1;
    }

    bool is_full() {
        return top == capacity - 1;
    }

    void push(T item) {
        if (is_full()) {
            cout << "Stack Overflow" << endl;
            return;
        }
        stack[++top] = item;
    }

    T pop() {
        if (is_empty()) {
            cout << "Stack Underflow" << endl;
            return T();
        }
        return stack[top--];
    }

    T peek() {
        if (is_empty()) {
            cout << "Stack is empty" << endl;
            return T();
        }
        return stack[top];
    }
};

int main() {
    Stack<int> int_stack(5);
    int_stack.push(1);
    int_stack.push(2);
    int_stack.push(3);
    cout << int_stack.pop() << endl;  // Output: 3
    cout << int_stack.peek() << endl;  // Output: 2

    Stack<string> string_stack(5);
    string_stack.push("Hello");
    string_stack.push("World");
    cout << string_stack.pop() << endl;  // Output: World
    cout << string_stack.peek() << endl;  // Output: Hello

    Stack<char> char_stack(5);
    char_stack.push('a');
    char_stack.push('b');
    cout << char_stack.pop() << endl;  // Output: b
    cout << char_stack.peek() << endl;  // Output: a

    return 0;
}
