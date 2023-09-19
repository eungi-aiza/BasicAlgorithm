#include <iostream>
using namespace std;

class LinkedNode{
public:
    int val;
    LinkedNode* next;
    LinkedNode(int value) : val(value), next(NULL) {}
};

class LinkedList{
public:
    LinkedNode* merge_sort(LinkedNode* head){
        if(!head || !head->next)
            return head;
        
        LinkedNode *prev = NULL, *slow = head, *fast = head;
        while(fast && fast ->next){
            prev = slow;
            slow = slow->next;
            fast = fast ->next->next;
        }
        prev->next = NULL;

        LinkedNode* left = merge_sort(head);
        LinkedNode* right = merge_sort(slow);
        return merge(left, right);
    }
    LinkedNode* merge(LinkedNode* left, LinkedNode* right){
        if(!left) return right;
        if(!right) return left;

        if(left->val < right->val){ // 부등호 방향 < : asc , > : desc
            left->next = merge(left->next, right);
            return left;
        }
        else{
            right->next = merge(left, right->next);
            return right;
        }
    }
    LinkedNode* list_to_linked_list(const int arr[], int n){
        if(n <= 0) return NULL;
        LinkedNode* head = new LinkedNode(arr[0]);
        LinkedNode* curr = head;

        for(int i = 0; i < n; i++){
            curr->next = new LinkedNode(arr[i]);
            curr = curr->next;
        }
        return head;
    }
    void print(LinkedNode* head) {
        while (head) {
            cout << head->val << " -> ";
            head = head->next;
        }
        cout << "NULL" << endl;
    }
    
};

int main() {
    int a[] = {1, 3, 2, 4, 5, 6, 7, 8};
    int b[] = {5, 3, 2, 1, 4, 0, 6, 7};

    LinkedList linkedList;

    LinkedNode* ahead = linkedList.list_to_linked_list(a, sizeof(a)/sizeof(a[0]));
    LinkedNode* bhead = linkedList.list_to_linked_list(b, sizeof(b)/sizeof(b[0]));

    linkedList.print(linkedList.merge_sort(ahead));
    linkedList.print(linkedList.merge_sort(bhead));
    
    // Remember to delete nodes to avoid memory leaks
    // (not done in this code for simplicity)
    return 0;
}