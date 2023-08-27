# Definition for singly-linked list.
from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
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
        
        
class Solution:              
    def reverse_ll(self, start_node):
        curr = self.copy(start_node)
        prev = None
        while(curr):
            tmp = curr.next
            curr.next = prev
            prev = curr
            curr = tmp
        return prev
    
    def copy(self, start_node):
        copy_node = ListNode(start_node.val)
        ans = copy_node
        while start_node.next:
            start_node = start_node.next
            temp = ListNode(start_node.val)
            copy_node.next = temp
            copy_node = copy_node.next
        return ans
            
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        h1 = self.reverse_ll(l1)
        h2 = self.reverse_ll(l2)
        up_val = 0 
        head = ListNode()
        dummy = head
        new = None
        while (h1 or h2 or up_val):
            h1_val = h1.val if h1 else 0 
            h2_val = h2.val if h2 else 0 
            temp_val = h1_val + h2_val + 1 if up_val else h1_val + h2_val
            up_val = 0
            if temp_val >= 10:
                remain_val = temp_val - 10
                up_val = 1
            else:
                remain_val = temp_val
            new = ListNode(val=remain_val)
            head.next = new
            head = head.next            
            if h1: h1 = h1.next
            if h2: h2 = h2.next
        
        ans = self.reverse_ll(dummy.next)
        
        return ans

if __name__ == "__main__":
    # l1 = [7,2,4,3]
    # l2 = [5,6,4]
    l1 = [5,0,0]
    l2 = [5,0,0]
    # l1 = [5]
    # l2 = [5]
    # l1 = [0]
    # l2 = [0]
    head1 = list_to_linked_list(l1)
    head2 = list_to_linked_list(l2)
    sol = Solution()
    printnode(sol.addTwoNumbers(head1, head2))