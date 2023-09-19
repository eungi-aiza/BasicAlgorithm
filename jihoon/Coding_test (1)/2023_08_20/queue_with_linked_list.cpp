# include "queue_with_linked_list.h"
#include <iostream>
using namespace std;

// Node::Node(int value) {
//     this->data = value;
//     this->next = NULL;
// }

// Linked_list::Linked_list() {}


int Queue::front() {
    return LL->head->data;
}

int Queue::back() {
    Node *curr = LL->head;
    while (curr->next) {
        curr = curr->next;
    }
    return curr->data;
}

bool Queue::empty() {
    if ((LL->length) == 0) { 
        return true;
    }
    return false;
}

int Queue::size() {
    return LL->length;
}

void Queue::push(int value) {
    cout << LL->length << endl;
    if (LL->length == 0) {
        Node *new_node = new Node;
        new_node->data = value;
        new_node->next = nullptr;
        LL->head = new_node;
        LL->length += 1;
    }
    else {
        cout << LL->head << endl;
        Node *curr = LL->head;
        while (curr->next) {
            curr = curr->next;
        }
        Node *new_node = new Node;
        new_node->data = value;
        new_node->next = nullptr;
        curr->next = new_node;
        LL->length += 1;
    }
}

int Queue::pop() {
    Node *curr = LL->head;
    while (curr->next->next) {
        curr = curr->next;
    }
    int pop_value = curr->next->data;
    curr->next = NULL;
    LL->length -= 1;
    return pop_value;
}