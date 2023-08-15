
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def copy(start_node):
    copy_node = ListNode(start_node.val)
    ans = copy_node
    while start_node.next:
        start_node = start_node.next
        temp = ListNode(start_node.val)
        copy_node.next = temp
        copy_node = copy_node.next
    return ans


def palindrome(start_node):
    if start_node == None or start_node.next == None:
        return True
    
    prev = copy(start_node)
    nxt = prev.next
    
    # fast nxt & slow nxt
    while nxt:
        prev = prev.next
        nxt = nxt.next
        if nxt:
            nxt = nxt.next

    # reverse 
    mid = prev
    prev_rev = None
    while mid: # middle node
        temp = mid.next
        mid.next = prev_rev
        prev_rev = mid
        mid = temp

    node = copy(start_node)
    while prev_rev:
        if node.val != prev_rev.val:
            return False
        node = node.next
        prev_rev = prev_rev.next

    return True


def print_linkedlist(start_node):
    while (True):
        print(start_node.val, '->', end=' ')
        start_node = start_node.next
        if ( start_node == None): 
            print('none')
            break

def get_length(s):
    length = 0
    while (True):
        if s == None: break
        length += 1
        s = s.next
    return length


def issub(s, t):
    # t in s?
    st = t    
    while (s and t):
        if s.val != t.val:
            s = s.next
            t = st
        else:
            s = s.next
            t = t.next

    if t == None:
        return True
    else:
        return False

    
def slicing(start_node, start, length):
    while start :
        if not start_node:
            return None  
        start_node = start_node.next
        start -= 1

    if not start_node:
        return None

    st = ListNode(start_node.val)
    current = st
    length -= 1
    while length > 0 and start_node.next:  
        start_node = start_node.next
        nxt = ListNode(start_node.val)
        current.next = nxt
        current = nxt  
        length -= 1
        
    return st


def maxpalindrome(s):
    length = get_length(s)
    window = length
    while window:
        for i in range(length - window + 1):
            sub = slicing(s, i, window)
            if palindrome(sub): 
                return sub
        window -= 1

    return None


node5 = ListNode(1)
node4 = ListNode(5, node5)
node3 = ListNode(2, node4)
node2 = ListNode(1, node3)
node1 = ListNode(3, node2)


result = maxpalindrome(node1)
print_linkedlist(result)