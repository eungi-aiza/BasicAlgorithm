"""
Given the head of a singly linked list, reverse the list, 
and return the reversed list.

ex1.
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

ex2.
Input: head = [1,2]
Output: [2,1]
"""

import copy

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def reverse_ll(ll):
    prev = None
    ll_tmp = copy.deepcopy(ll)
    curr = ll_tmp
    while(curr):
        tmp = curr.next
        curr.next = prev
        prev = curr
        curr = tmp
    return prev

def remove(ll, n):
    rll = reverse_ll(ll)
    curr = rll
    prev = None
    while(n-1) :
        curr = curr.next
        prev = curr
    if not prev :
        prev.next = curr.next
    else :
        curr = curr.next
    
