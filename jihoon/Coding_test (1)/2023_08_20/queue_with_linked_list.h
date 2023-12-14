#pragma once
#include <stdio.h>

struct Node {
    public:
    int data;
    Node *next;
};

struct Linked_list {
    public:
    Node *head;
    int length;
};

class Queue {
    Linked_list *LL;
    public:
    int front();
    int back();
    bool empty();
    int size();
    void push(int value);
    int pop();
};


