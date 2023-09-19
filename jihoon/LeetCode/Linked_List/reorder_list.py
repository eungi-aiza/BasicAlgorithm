# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        slow = head
        fast = head.next
        
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            
        
        #reverse second list
        second = slow.next  #head of second list
        slow.next = None #pointing tail of first list to null
        prev = None
        
        while second:
            temp = second.next
            second.next = prev
            prev = second
            second = temp
            
            
        #merge two halves
        first, second = head, prev
        
        while second:
            temp1 = first.next
            temp2 = second.next
            
            first.next = second
            second.next = temp1
            first = temp1
            second = temp2