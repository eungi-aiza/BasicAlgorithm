# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertGreatestCommonDivisors(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return head
        
        first,second=head,head.next
        
        while second:
            first_val,second_val=first.val,second.val
            gcd_sav = gcd(first_val,second_val)
            node = ListNode(gcd_sav)
            first.next=node
            node.next=second
            first=second
            second=second.next
        return head