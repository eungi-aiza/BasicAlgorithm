#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char* items[MAX_SIZE];
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

void push(Stack* s, char* item) {
    if (is_full(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++s->top] = strdup(item);
}

char* pop(Stack* s) {
    if (is_empty(s)) {
        printf("Stack Underflow\n");
        return NULL;
    }
    return s->items[s->top--];
}

char* peek(Stack* s) {
    if (is_empty(s)) {
        printf("Stack is empty\n");
        return NULL;
    }
    return s->items[s->top];
}

int main() {
    Stack stack;
    init(&stack);

    const char* string_item = "Hello, World!";
    push(&stack, (char*)string_item);

    printf("%s\n", pop(&stack));  // Output: Hello, World!

    return 0;
}
