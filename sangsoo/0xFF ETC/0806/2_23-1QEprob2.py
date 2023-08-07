class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def llcopy(head: ListNode) -> ListNode: #same with copy.deepcopy(head) custom deepcopy
    if not head:
        return None

    dummy = ListNode()
    current = dummy 

    while head:
        current.next = ListNode(head.val)  
        current = current.next 
        head = head.next 

    return dummy.next

def reverse(head: ListNode):
    curr = llcopy(head)
    prev = None
    while curr:
        tmp = curr.next # 임시 저장 
        curr.next = prev # 방향바꾸기
        prev = curr # 전진
        curr = tmp # 전진
    return prev

def palindrome(head:ListNode) -> bool:
    rh = reverse(head)
    curr = head
    while curr:
        if curr.val != rh.val:
            return False
        curr = curr.next
        rh = rh.next
    return True

def printlist(h: ListNode)-> None:
    while h:
        print(h.val, end = " ")
        h = h.next

def lenlist(h: ListNode)-> int:
    n = 0
    while h:
        h = h.next
        n += 1
    return n

def substring(s: ListNode, t: ListNode)->bool: # t in s?
    cnt = 0
    valid = 0
    thead = t
    while t:
        print(f"s.val: {s.val}")
        print(f"t.val: {t.val}")
        print(f"valid : {valid}")
        if s.val == t.val:
            s = s.next
            t = t.next
            valid += 1
            print(f"2valid : {valid}")
        else:
            t = thead
            cnt += 1
            valid = 0
            if cnt == 2:
                s = s.next
                cnt = 0
    print(f"valid: {valid}, lenlist(s): {lenlist(s)}")
    return valid == lenlist(t)
    
def list_to_linked_list(numlist:list)->ListNode:
    if not numlist:
        return None
    head = ListNode(numlist[0])
    curr = head

    for val in numlist[1:]:
        curr.next = ListNode(val)
        curr = curr.next
    return head

if __name__ == "__main__":
    a1 = [1, 2, 3, 2, 1]; a1head = list_to_linked_list(a1)
    a2 = [1, 2, 3, 2, 4]; a2head = list_to_linked_list(a2)
    a3 = [1, 2]; a3head = list_to_linked_list(a3)
    a4 = [2, 3]; a4head = list_to_linked_list(a4)
    a5 = [2, 4]; a5head = list_to_linked_list(a5)
    a6 = [5, 4]; a6head = list_to_linked_list(a6)
    a7 = [1, 4]; a7head = list_to_linked_list(a7)
    sublist = [a3head, a4head, a5head, a6head, a7head]
    for i in range(len(sublist)):
        print(substring(a1head, sublist[i]))
    #print(substring(a1head, a3head))
    # print(printlist(a3head))
    # print(printlist(llcopy(a1head)))
    # print(printlist(reverse(a2head)))
    # print(palindrome(a1head))
    # print(palindrome(a2head))