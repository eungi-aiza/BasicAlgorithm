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
        vector<int> listArray;
        ListNode* current = head;
        while (current != nullptr) {
            listArray.push_back(current->val);
            current = current->next;
        }

        // length is zero
        int n = listArray.size();
        if (n == 0) {  
            return false;
        }
        // length is 1
        if (n == 1) {
            return true;
        }
        // length is odd
        if (n % 2 != 0) { 
            int mid = n / 2;
            vector<int> leftHalf(listArray.begin(), listArray.begin() + mid + 1);
            vector<int> rightHalf(listArray.rbegin(), listArray.rbegin() + mid + 1);
            return leftHalf == rightHalf;
        }
        // length is even
        else { 
            vector<int> leftHalf(listArray.begin(), listArray.begin() + n/2);
            vector<int> rightHalf(listArray.rbegin(), listArray.rbegin() + n/2);
            return leftHalf == rightHalf;
        }
    }
};