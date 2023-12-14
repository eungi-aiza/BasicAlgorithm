#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

void init(Stack* s) {
    s->top = -1;
}

int is_empty(Stack* s) {
    return s->top == -1;
}

int is_full(Stack* s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack* s, int item) {
    if (is_full(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++s->top] = item;
}

int pop(Stack* s) {
    if (is_empty(s)) {
        printf("Stack Underflow\n");
        return 0;  // Return a default value or handle the underflow condition appropriately
    }
    return s->items[s->top--];
}

int peek(Stack* s) {
    if (is_empty(s)) {
        printf("Stack is empty\n");
        return 0;  // Return a default value or handle the empty stack condition appropriately
    }
    return s->items[s->top];
}

int main() {
    Stack stack;
    init(&stack);
    
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    
    printf("%d\n", pop(&stack));  // Output: 3
    printf("%d\n", peek(&stack));  // Output: 2
    
    return 0;
}
