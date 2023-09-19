# Definition for singly-linked list.
from typing import Optional
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        curr = head
        prev = None
        while(curr):
            if (prev and prev.val == curr.val):
                prev.next = curr.next
            else:
                prev = curr
            curr = curr.next
        return head
    
def list_to_linked_list(numlist:list)->Optional[ListNode]:
    if not numlist:
        return None
    head = ListNode(numlist[0])
    curr = head

    for val in numlist[1:]:
        curr.next = ListNode(val)
        curr = curr.next
    return head

def printnode(head: ListNode)->None:
    while(head):
        print(head.val, end = "->")
        head = head.next
    print("None")
    return

if __name__ == "__main__":
    numlist1 = [1, 1, 2]
    numlist2 = [1, 1, 2, 3, 3]
    head1 = list_to_linked_list(numlist1)
    head2 = list_to_linked_list(numlist2)
    sol = Solution()
    printnode(sol.deleteDuplicates(head1))
    printnode(sol.deleteDuplicates(head2))