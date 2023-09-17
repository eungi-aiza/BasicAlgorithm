# Definition for singly-linked list.
from typing import Optional
import copy
"""

You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
가장 큰 수부터 linked list 

ex1.
Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]

ex2.
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]

ex3. 
Input: l1 = [0], l2 = [0]
Output: [0]
"""

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverse_ll(self, ll):
        prev = None
        ll_tmp = copy.deepcopy(ll)
        curr = ll_tmp
        while(curr):
            tmp = curr.next
            curr.next = prev
            prev = curr
            curr = tmp
        return prev
    
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        rll1 = self.reverse_ll(l1)
        rll2 = self.reverse_ll(l2)
        num = 0
        over_num = 0
        step = 0
        while(rll1 or rll2):
            if not rll1 :
                val = rll2.val
            elif not rll2 :
                val = rll1.val
            else :
                val = rll1.val + rll2.val
            num = (over_num + val)%10
            over_num = (over_num + val)//10
            newNode = ListNode(val=num)
            if step == 0:
                head = newNode
                curr = head
            else :
                curr.next = newNode
                curr = curr.next
            step+=1
            if rll1 :
                rll1 = rll1.next
            if rll2 :
                rll2 = rll2.next
        if over_num :
            newNode = ListNode(over_num)
            curr.next = newNode
            
        
        head = self.reverse_ll(head)
        ans = []
        while(head):
            ans.append(head.val)
            head = head.next
        print(ans)


    
    def list_to_linked_list(self, numlist:list)->Optional[ListNode]:
        if not numlist:
            return None
        head = ListNode(numlist[0])
        curr = head

        for val in numlist[1:]:
            curr.next = ListNode(val)
            curr = curr.next
        return head

    def printnode(self, head: ListNode)->None:
        while(head):
            print(head.val, end = "->")
            head = head.next
        print("None")
        return

if __name__ == "__main__":
    # numlist1 = [7,2,4,3]
    # numlist2 = [5,6,4]
    # numlist1 = [2,4,3]
    # numlist2 = [5,6,4]
    numlist1 = [5]
    numlist2 = [5]
    # numlist1 = [0]
    # numlist2 = [0]
    sol = Solution()
    head1 = sol.list_to_linked_list(numlist1)
    head2 = sol.list_to_linked_list(numlist2)
    sol.addTwoNumbers(head1, head2)
    # printnode(sol.deleteDuplicates(head1))
    # printnode(sol.deleteDuplicates(head2))