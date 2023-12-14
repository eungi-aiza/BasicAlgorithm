
// C++ program for the above approach
 
#include <bits/stdc++.h>
using namespace std;
 
// Structure of a Node
class Node {
public:
    int data;
    Node* next;
};
 
// Function to find the length of
// the Linked List
int sizeOfLL(Node* head)
{
    int size = 0;
 
    // While head is not null
    while (head != NULL) {
        ++size;
        head = head->next;
    }
    return size;
}
 
// Function to partition list into
// 3 parts such that maximum size
// difference between parts is minimum
vector<Node*> Partition_of_list(Node* head)
{
    int size = sizeOfLL(head);
    Node* temp = head;
    vector<Node*> ans;
 
    // If size is less than 3
    if (3 >= size) {
        // Partition linked list
        // into one node each
        while (temp != NULL) {
            Node* next = temp->next;
            temp->next = NULL;
            ans.push_back(temp);
            temp = next;
        }
 
        // The remaining parts (3-size)
        // will be filled by empty
        // the linked list
        int y = 3 - size;
        while (y != 0) {
            ans.push_back(NULL);
            y--;
        }
    }
    else {
        // Minimum size
        int minSize = size / 3;
        int rem = size % 3;
 
        // While size is positive
        // and temp is not null
        while (size > 0 && temp != NULL) {
            int m = 0;
 
            // If remainder > 0, then
            // partition list on the
            // basis of minSize + 1
            if (rem != 0) {
                m = minSize + 1;
                rem--;
            }
 
            // Otherwise, partition
            // on the basis of minSize
            else {
                m = minSize;
            }
            Node* curr = temp;
 
            // Iterate for m-1 steps
            // in the list
            for (int j = 1; j < m
                            && temp->next != NULL;
                 j++) {
                temp = temp->next;
            }
 
            // Change the next of the
            // current node to NULL
            // and add it to the ans
            if (temp->next != NULL) {
                Node* x = temp->next;
                temp->next = NULL;
                temp = x;
                ans.push_back(curr);
            }
 
            // Otherwise
            else {
                // Pushing to ans
                ans.push_back(curr);
                break;
            }
            size -= m;
        }
    }
 
    // Return the resultant lists
    return ans;
}
 
// Function to insert elements in list
void push(Node** head, int d)
{
    Node* temp = new Node();
    temp->data = d;
    temp->next = NULL;
 
    // If the head is NULL
    if ((*head) == NULL)
        (*head) = temp;
 
    // Otherwise
    else {
        Node* curr = (*head);
 
        // While curr->next is not NULL
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = temp;
    }
}
 
// Function to display the Linked list
void display(Node* head)
{
    // While head is not null
    while (head->next != NULL) {
        // Print the data
        cout << head->data << "->";
        head = head->next;
    }
    cout << head->data << "\n";
}
 
// Driver Code
int main()
{
    // Given Input
    Node* head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
 
    // Function Call
    vector<Node*> v = Partition_of_list(head);
 
    for (int i = 0; i < v.size(); i++) {
        display(v[i]);
    }
    return 0;
}