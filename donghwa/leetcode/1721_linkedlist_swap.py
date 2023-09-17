# Definition for singly-linked list.

"""

You are given the head of a linked list, and an integer k.
Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).
linkedlist의 앞에서부터 k번째 node와 뒤에서부터 k번째 node를 swap해라 

ex1. 
Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]

ex2.
Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]

"""
from typing import Optional
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def getLength(self, head: Optional[ListNode])-> int :
        cnt = 0
        curr = head
        while(curr):
            curr = curr.next
            cnt += 1
        return cnt

    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        prev = None
        curr = head
        n = self.getLength(head)
        if (n//2 <= k):
             cnt = k
             cnt2 = n-k
        else :
            cnt = n-k
            cnt2 = k
            
        while(cnt>1):
            prev = curr
            curr = curr.next
            cnt -= 1

        prev2 = None
        curr2 = head
        while(cnt2):
            prev2 = curr2
            curr2 = curr2.next
            cnt2 -= 1
        # swap
        print(f"curr : {curr.val}, prev2 : {prev2.val}, curr2 :{curr2.val} ") # prev : {prev.val}, 
        if (curr == curr2):
            return head
        elif (not prev):
            tmp = curr.val
            curr.val = curr2.val
            curr2.val = tmp
        elif (curr == prev2):
            tmp = curr2.next
            prev.next = curr2
            curr2.next = curr
            curr.next = tmp 
        else :
            tmp = curr2.next
            prev.next = curr2
            curr2.next = curr.next
            curr.next = None
            prev2.next = curr
            curr.next = tmp
        self.printnode(head)
        # return head
    
        
    
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
    # numlist = [1, 2,3,4,5]
    # k = 2
    # numlist = [7,9,6,6,7,8,3,0,9,5]
    # k = 5
    numlist = [100, 9]
    k = 2
    # numlist = [1,2]
    # k = 1
    sol = Solution()
    head = sol.list_to_linked_list(numlist)
    sol.swapNodes(head, k)