#pragma once
using namespace std;

struct node {
	int data;
	node* next = nullptr;
};


class LinkedList{
    public : 
    /* Constructor */
    LinkedList() {
		head = nullptr;
		tail = nullptr;
	};
    int front(void);
    int back(void);
    int size(void);
    int empty(void);
    void push(int x);
    void pop(void);
    // void display(void);

    private :
        node* head;
        node* tail;
        int size_ = 0;

};

/* Accessors */
int LinkedList::front(void){
    return head->data;
};


int LinkedList::back(void) {
    if (tail) {
        return tail->data;
    } else {
        cout << "List is empty!" << endl;
        return -1;
    }
}

int LinkedList::size(void){
    return size_;
};

int LinkedList::empty(void){
    if (size_==0){ return 1; }
    else { return 0; };
};

void LinkedList::push(int x) {
	node* tmp = new node;
	tmp->data = x;
	// tmp->next = nullptr; // Set the next pointer of the new node to nullptr

	if (tail == nullptr) {
		// If the list is empty, update both head and tail
		head = tmp;
		tail = tmp;
	} else {
		tail->next = tmp;
		tail = tail->next;
	}

	size_ += 1;
}




void LinkedList::pop(void){
    if (size_ > 0){
        node *tmp = head->next;
        delete head;
        head = tmp;
        size_ -= 1;
        if (size_ == 0){
            tail = nullptr;
        }
    } 
};

