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
    
        
    def get_length(self, start_node):
        length = 0
        node = self.copy(start_node)
        while (True):
            if node == None: break
            length += 1
            node = node.next
        return length
    
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        length = self.get_length(head)
        if (head==None or head.next==None or k == length-k+1):
            return head
        
        ans = head   
        
        k_temp = k-1        
        rev_head = self.reverse_ll(head)
        while (k_temp):
            head = head.next
            k_temp -= 1   
        print(rev_head.val)
        print(head.val)
        temp = rev_head.val    
        rev_head.val = head.val     
        head.val = temp
        
        printnode(ans)    
        
        return  ans
        


if __name__ == "__main__":
    l1 = [1,2,3,4,5]
    k1= 2
    # l2 = [7,9,6,6,7,8,3,0,9,5]
    # k2 = 5
    l2 = [1,2,3,4,5,6]
    k2 = 3
    head1 = list_to_linked_list(l1)
    head2 = list_to_linked_list(l2)
    sol = Solution()
    
    printnode(sol.swapNodes(head1, k1))
    printnode(sol.swapNodes(head2, k2))