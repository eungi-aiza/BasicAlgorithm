/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
#include <vector>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr){
            if((prev) && (prev->val == curr->val)){
                prev->next = curr->next;
            }
            else{
                prev = curr;
            }
            curr = curr->next;
        }
        return head;
    }
};

ListNode* list_to_linked_list(const std::vector<int>& numlist) {
    if (numlist.empty()) {
        return nullptr;
    }

    ListNode* head = new ListNode(numlist[0]);
    ListNode* curr = head;

    for (int i = 1; i < numlist.size(); ++i) {
        curr->next = new ListNode(numlist[i]);
        curr = curr->next;
    }
    return head;
}

void printnode(ListNode* head) {
    while (head) {
        std::cout << head->val << "->";
        head = head->next;
    }
    std::cout << "None" << std::endl;
}

int main(){
    vector<int> v1 = {1, 1, 2};
    vector<int> v2 = {1,1,2,3,3};
    ListNode* head1 = list_to_linked_list(v1);
    ListNode* head2 = list_to_linked_list(v2);
    Solution sol;
    printnode(sol.deleteDuplicates(head1));
    printnode(sol.deleteDuplicates(head2));
}