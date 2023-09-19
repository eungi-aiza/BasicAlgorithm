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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        
        stack<int> st;

        while(temp) {
            st.push(temp->val);
            temp = temp->next;
        }
        bool res = false;
        temp = head;
        while(temp) {
            if(temp->val == st.top()) {
                res = true;
                st.pop();
                temp = temp->next;
            }
            else {
                return false;
            }
        }
        return res;

    }
};