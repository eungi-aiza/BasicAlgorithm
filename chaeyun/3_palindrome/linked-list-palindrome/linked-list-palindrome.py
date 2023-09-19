# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head==None or head.next==None: 
            return head #If the list is empty or there is only one element then return it as it is
        prev=head
        curr=prev.next
        prev.next=None #After reversal first element will point to None
        temp=curr.next
        while curr.next:
            curr.next=prev
            prev=curr
            curr=temp
            temp=curr.next
        curr.next=prev #To connect last element to second last element
        return curr
    
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        slow=fast=head
        while fast.next and fast.next.next:
            slow=slow.next
            fast=fast.next.next
        temp1=self.reverseList(slow)
        temp2=head
        while temp1 and temp2:
            if temp1.val!=temp2.val:
                return False
            temp1=temp1.next
            temp2=temp2.next
        return True