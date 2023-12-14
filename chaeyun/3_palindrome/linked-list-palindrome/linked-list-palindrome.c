/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
typedef int bool;
#define True  1
#define False 0

struct ListNode {
    int val;
    struct ListNode *next;
};

bool isPalindrome(struct ListNode* head){
        if(!head)   return False;
        if(!head->next) return True;

        struct ListNode *rev_head = NULL , *ptr = head;
        while(ptr != NULL)
        {
            struct ListNode *temp = (struct ListNode*)malloc(sizeof(struct ListNode));
            temp->val = ptr->val;
            temp->next = rev_head;
            rev_head = temp;
            ptr = ptr->next;
        }

        while(head && rev_head)
        {
            if(head->val != rev_head->val)  return False;
            else
            {
                head = head->next;
                rev_head = rev_head->next;
            }
        }
        return True;

}