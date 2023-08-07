# Definition for singly-linked list.
from typing import Optional
import copy
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def lenlist(self, head) -> int:
        curr = head
        n = 0
        while curr:
            curr = curr.next
            n += 1
        return n
    def llcopy(self, head: ListNode) -> ListNode: #same with copy.deepcopy(head) custom deepcopy
        if not head:
            return None

        dummy = ListNode()
        current = dummy 

        while head:
            current.next = ListNode(head.val)  
            current = current.next 
            head = head.next 

        return dummy.next

    def reverse(self, head: ListNode)-> ListNode:
        prev = None
        curr = self.llcopy(head)
        while(curr):
            next = curr.next # 임시저장
            curr.next = prev # 방향 바꾸기
            prev = curr # 전진
            curr = next # 전진

        return prev

    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        rhead = self.reverse(head)
        rcurr = rhead
        length = self.lenlist(head)
        if length == 1 and n == 1:
            return None
        if n == length:
            return head.next
        if n == 1:
            return self.reverse(rhead.next)
        for _ in range(n -2):
            rcurr = rcurr.next
        rcurr.next = rcurr.next.next
        newhead = self.reverse(rhead)
        return newhead
    
def list_to_linked_list(numlist:list)->ListNode:
    if not numlist:
        return None
    head = ListNode(numlist[0])
    curr = head

    for val in numlist[1:]:
        curr.next = ListNode(val)
        curr = curr.next
    return head

def printlist(head: ListNode)->None:
    curr =head
    while curr:
        print(curr.val, end = '-')
        curr = curr.next

if __name__ == '__main__':
    a1 = [1, 2, 3, 4, 5]; a1head = list_to_linked_list(a1)
    a2 = [1, 2]; a2head = list_to_linked_list(a2)
    sol = Solution()
    # printlist(sol.removeNthFromEnd(a1head, 2))
    printlist(sol.removeNthFromEnd(a2head, 1))