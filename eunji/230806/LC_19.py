# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def removeNthFromEnd(self, head, n):
        curr = 2
        prv = head
        nxt = head.next
        st = head
        k = head
        tot = 0
        
        while (True):
            if k == None: break
            k = k.next
            tot += 1
            
        n = tot-n+1
        
        while (True):
            if (n == 1):
                return nxt
            elif (n != 1 and curr == n):
                temp = nxt.next
                prv.next = temp
                return st
            else:
                curr += 1
                prv = prv.next
                nxt = nxt.next
        
        
    def print_linkedlist(self, start_node):
        while (True):
            print(start_node.val, '->', end=" ")
            if ( start_node.next == None): break
            start_node = start_node.next
        print('None')
            
            
# Example linked list: 1 -> 2 -> 3 -> 4 -> 5
node5 = ListNode(5)
node4 = ListNode(4, node5)
node3 = ListNode(3, node4)
node2 = ListNode(2, node3)
node1 = ListNode(1, node2)
n = 2
S = Solution()
S.print_linkedlist(node1)

new = S.removeNthFromEnd(node1, n=2)
# print(new.val)
S.print_linkedlist(new)
