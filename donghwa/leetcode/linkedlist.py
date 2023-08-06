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
    rll = reverse_l(ll)
    curr = rll
    prev = None
    while(n-1) :
        curr = curr.next
        prev = curr
    if not prev :
        prev.next = curr.next
    else :
        curr = curr.next
    
